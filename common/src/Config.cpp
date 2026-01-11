#include "Config.h"
#include <sstream>

Config Config::fromJson(const std::string& json) {
    Config config;
    // Простой парсинг JSON (для демонстрации)
    std::istringstream iss(json);
    std::string token;
    while (iss >> token) {
        if (token.find("\"N\":") != std::string::npos) {
            iss >> config.N;
        } else if (token.find("\"S\":") != std::string::npos) {
            iss >> config.S;
        } else if (token.find("\"K\":") != std::string::npos) {
            iss >> config.K;
        }
    }
    return config;
}

std::string Config::toJson() const {
    std::ostringstream oss;
    oss << "{\"N\":" << N << ",\"S\":" << S << ",\"K\":" << K << "}";
    return oss.str();
}

bool Config::validate() const {
    return N > 0 && S > 0 && K > 0 && K <= N;
}
