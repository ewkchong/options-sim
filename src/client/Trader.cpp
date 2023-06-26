#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "usage: client <port-number>" << std::endl;
		return 1;
	}

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9999);  // Port number of the server
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");  // IP address of the server (localhost)

    if (connect(sockfd, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to connect to the server." << std::endl;
        close(sockfd);
        return 1;
    }

	// TODO: create order to send to server

	// send message to server
    std::string message = "Hello, server!";
    if (send(sockfd, message.c_str(), message.size(), 0) == -1) {
        std::cerr << "Failed to send data to the server." << std::endl;
        close(sockfd);
        return 1;
    }

	// receive response
    char buffer[1024];
    int bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Failed to receive data from the server." << std::endl;
        close(sockfd);
        return 1;
    }

    buffer[bytesRead] = '\0';
    std::cout << "Received from server: " << buffer << std::endl;

    // Close the socket
    close(sockfd);

    return 0;
}

