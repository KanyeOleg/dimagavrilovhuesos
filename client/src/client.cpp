#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

// Простая реализация математических функций прямо в клиенте
std::vector<double> generateNumbers(int N, double S) {
    std::vector<double> numbers(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    
    double sum = 0.0;
    for (int i = 0; i < N - 1; ++i) {
        double max_val = S - sum - (N - i - 1) * 0.001;
        std::uniform_real_distribution<> dist(0.001, max_val);
        numbers[i] = dist(gen);
        sum += numbers[i];
    }
    numbers[N - 1] = S - sum;
    
    return numbers;
}

double productOfKLargest(const std::vector<double>& numbers, int K) {
    std::vector<double> sorted = numbers;
    std::sort(sorted.begin(), sorted.end(), std::greater<double>());
    
    double product = 1.0;
    for (int i = 0; i < K && i < (int)sorted.size(); ++i) {
        product *= sorted[i];
    }
    return product;
}

char checkCondition(double product) {
    bool A = product < 99.0;
    bool B = product > 0.001;
    bool C = fabs(product - 25.0) > 0.0001;
    bool D = fabs(product - 75.0) > 0.0001;
    
    if (A && B && C && D) return 'E';
    if (!A) return 'A';
    if (!B) return 'B';
    if (!C) return 'C';
    if (!D) return 'D';
    return '?';
}

void printHelp() {
    std::cout << "Клиент Kenguru Task v";
    
    const char* major = std::getenv("APP_VERSION_MAJOR");
    const char* minor = std::getenv("APP_VERSION_MINOR");
    const char* patch = std::getenv("APP_VERSION_PATCH");
    
    if (!major) major = "1";
    if (!minor) minor = "0";
    if (!patch) patch = "0";
    
    std::cout << major << "." << minor << "." << patch << "\n";
    std::cout << "Использование: client <файл_конфигурации>\n";
    std::cout << "Пример: client config/params.json\n";
    std::cout << "Формат JSON: {\"N\":4, \"S\":20.0, \"K\":2}\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        printHelp();
        return 0;
    }
    
    if (argc < 2) {
        std::cerr << "Требуется файл конфигурации\n";
        printHelp();
        return 1;
    }
    
    // Простой парсинг JSON
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << argv[1] << std::endl;
        return 1;
    }
    
    int N = 4;
    double S = 20.0;
    int K = 2;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("\"N\":") != std::string::npos) {
            sscanf(line.c_str(), "\"N\":%d", &N);
        } else if (line.find("\"S\":") != std::string::npos) {
            sscanf(line.c_str(), "\"S\":%lf", &S);
        } else if (line.find("\"K\":") != std::string::npos) {
            sscanf(line.c_str(), "\"K\":%d", &K);
        }
    }
    
    // Проверка параметров
    if (N <= 0 || S <= 0 || K <= 0 || K > N) {
        std::cerr << "Неверные параметры конфигурации\n";
        return 1;
    }
    
    // Выполнение задачи
    auto numbers = generateNumbers(N, S);
    double product = productOfKLargest(numbers, K);
    char answer = checkCondition(product);
    
    // Вывод результатов
    std::cout << "Числа: ";
    for (double num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nПроизведение " << K << " наибольших: " << product;
    std::cout << "\nПравильный ответ: " << answer << std::endl;
    
    return 0;
}
