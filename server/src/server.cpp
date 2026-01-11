#include <iostream>
#include <cstdlib>

void printHelp() {
    std::cout << "Сервер Kenguru Task\n";
    std::cout << "Использование: server [порт]\n";
    std::cout << "Пример: server 8080\n";
}

std::string getVersion() {
    const char* major = std::getenv("APP_VERSION_MAJOR");
    const char* minor = std::getenv("APP_VERSION_MINOR");
    const char* patch = std::getenv("APP_VERSION_PATCH");
    
    if (!major) major = "1";
    if (!minor) minor = "0";
    if (!patch) patch = "0";
    
    return std::string(major) + "." + minor + "." + patch;
}

int main(int argc, char* argv[]) {
    if (argc > 1 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        printHelp();
        return 0;
    }
    
    std::cout << "Сервер Kenguru Task v" << getVersion() << std::endl;
    std::cout << "Сервер готов к работе (TCP не реализован в демо-версии)" << std::endl;
    
    return 0;
}
