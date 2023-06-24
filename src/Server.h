#ifndef SERVER_H
#define	SERVER_H

class Server {
public:
	static void handleClient(int);
	int start();
};

#endif // !SERVER_H
