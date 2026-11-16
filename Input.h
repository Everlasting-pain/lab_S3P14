#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <stdexcept>
#include <string>

inline std::string readText(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line))
            throw std::runtime_error("Ввод завершён.");
        if (line.find_first_not_of(" \t\r") != std::string::npos) return line;
        std::cout << "Строка не должна быть пустой." << std::endl;
    }
}

inline int readInt(const std::string& prompt, int minValue, int maxValue) {
    while (true) {
        std::string line = readText(prompt);
        try {
            size_t pos;
            int value = std::stoi(line, &pos);
            if (pos == line.size() && value >= minValue && value <= maxValue)
                return value;
        } catch (...) {}
        std::cout << "Введите целое число от " << minValue
                  << " до " << maxValue << "." << std::endl;
    }
}

#endif
