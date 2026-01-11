#include "Client.h"
#include "Config.h"
#include "MathLib.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

Client::Client(const std::string& configFile) : configFile(configFile) {}

bool Client::run()
{
    // Чтение конфигурации
    std::ifstream file(configFile);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла: " << configFile << std::endl;
        return false;
    }

    std::string json((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());

    Config config = Config::fromJson(json);
    if (!config.validate())
    {
        std::cerr << "Неверная конфигурация" << std::endl;
        return false;
    }

    // Генерация чисел
    auto numbers = MathLib::generateNumbers(config.N, config.S);
    double product = MathLib::productOfKLargest(numbers, config.K);
    char answer = MathLib::checkCondition(product);

    // Вывод результатов
    std::cout << "Числа: ";
    for (double num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\nПроизведение " << config.K << " наибольших: " << product;
    std::cout << "\nПравильный ответ: " << answer << std::endl;

    return true;
}

void Client::printHelp()
{
    std::cout << "Клиент Kenguru Task\n";
    std::cout << "Использование: client <файл_конфигурации>\n";
    std::cout << "Пример: client config/params.json\n";
    std::cout << "Формат JSON: {\"N\":4, \"S\":20.0, \"K\":2}\n";
}

std::string Client::getVersion()
{
    const char* major = std::getenv("APP_VERSION_MAJOR");
    const char* minor = std::getenv("APP_VERSION_MINOR");
    const char* patch = std::getenv("APP_VERSION_PATCH");

    if (!major) major = "1";
    if (!minor) minor = "0";
    if (!patch) patch = "0";

    return std::string(major) + "." + minor + "." + patch;
}

int main(int argc, char* argv[])
{
    // Проверка флага помощи
    if (argc > 1 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help"))
    {
        Client::printHelp();
        return 0;
    }

    // Проверка аргументов
    if (argc < 2)
    {
        std::cerr << "Требуется файл конфигурации\n";
        Client::printHelp();
        return 1;
    }

    // Запуск клиента
    Client client(argv[1]);
    if (!client.run())
    {
        std::cerr << "Ошибка выполнения клиента" << std::endl;
        return 1;
    }

    return 0;
}
