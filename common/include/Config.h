#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct Config {
    int N = 4;
    double S = 20.0;
    int K = 2;
    
    static Config fromJson(const std::string& json);
    std::string toJson() const;
    bool validate() const;
};

#endif
