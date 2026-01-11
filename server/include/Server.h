#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    Server(int port = 8080);
    bool start();
    void stop();
    
    static void printHelp();
    static std::string getVersion();
    
private:
    int port;
    bool running;
};

#endif
