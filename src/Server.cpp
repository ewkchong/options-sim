#include <cstdlib>
#include <cstring>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>

#include "Server.h"
#include "Message.h"
#include "MatchingEngine.h"

static std::vector<int> clients; // Store client sockets
static std::mutex mtx;           // Mutex for protecting shared data
                       //
void Server::handleClient(int clientSocket) {
    char buffer[1024];
    std::cout << "Client connected. Socket: " << clientSocket << std::endl;

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead <= 0) {
            break;
        }

		//  TODO: Process message, check if order

        std::cout << "Received from client (Socket " << clientSocket
                  << "): " << buffer << std::endl;

        send(clientSocket, buffer, bytesRead, 0);
    }

    close(clientSocket);

    {
        std::lock_guard<std::mutex> lock(mtx);
        (void)std::remove(clients.begin(), clients.end(), clientSocket);
    }

    std::cout << "Client disconnected. Socket: " << clientSocket << std::endl;
}

int Server::start() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    // Set up server address
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9999);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP and port
    if (bind(serverSocket, (struct sockaddr *)&serverAddress,
             sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to bind to port 9999." << std::endl;
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cerr << "Failed to listen for connections." << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Server started. Listening on port 9999." << std::endl;

    while (true) {
        // Accept a new client connection
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Failed to accept client connection." << std::endl;
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(mtx);
            clients.push_back(clientSocket);
        }

        // Start a new thread to handle the client
        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    // Close the server socket
    close(serverSocket);

    return 0;
}
