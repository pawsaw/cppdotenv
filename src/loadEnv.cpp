#include "loadEnv.h"
#include <fstream>
#include <sstream>

// Function to load environment variables from .env file
std::unordered_map<std::string, std::string> loadEnv(const std::string& filename) {
    

    std::unordered_map<std::string, std::string> env;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string value;
            if (key[0] == '#' || key.empty()) continue; // Skip comments or empty lines
            if (std::getline(is_line, value)) {
                env[key] = value;
            }
        }
    }
    return env;
}