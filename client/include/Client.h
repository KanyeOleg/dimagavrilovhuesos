#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(const std::string& configFile);
    bool run();
    
    static void printHelp();
    static std::string getVersion();
    
private:
    std::string configFile;
};

#endif
