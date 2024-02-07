#include "loadEnv.h"
#include <fstream>
#include <sstream>

extern char** environ;

void load_from_sys_env(std::unordered_map<std::string, std::string>& env) {
    for (char** envp = environ; *envp != nullptr; ++envp) {
        std::string env_str(*envp);
        const auto delimiter_position = env_str.find('=');
        std::string key = env_str.substr(0, delimiter_position);
        std::string value = env_str.substr(delimiter_position + 1);
        env[key] = value;
    }
}

void load_from_file(const std::string& filename, std::unordered_map<std::string, std::string>& env) {
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
}

// Function to load environment variables from .env file
std::unordered_map<std::string, std::string> loadEnv(const std::string& filename) {

    std::unordered_map<std::string, std::string> env;
    load_from_file(filename, env);
    load_from_sys_env(env);
    
    return env;
}

template<std::ranges::range Range>
    requires std::same_as<std::ranges::range_value_t<Range>, std::string>
std::unordered_map<std::string, std::string> loadEnv(const Range& filenames) {
    std::unordered_map<std::string, std::string> env;
    for (const auto& filename : filenames) {
        load_from_file(filename, env);
    }
    load_from_sys_env(env);
    return env;
}
