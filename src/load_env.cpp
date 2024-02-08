#include "load_env.h"
#include <fstream>
#include <sstream>

extern char** environ;

std::ostream& operator<<(std::ostream& os, const env_map& env) {
    for (const auto& [key, value] : env) {
        os << key << "=" << value << std::endl;
    }
    return os;
}

void load_from_sys_env(env_map& env) {
    for (char** envp = environ; *envp != nullptr; ++envp) {
        std::string env_str(*envp);
        const auto delimiter_position = env_str.find('=');
        std::string key = env_str.substr(0, delimiter_position);
        std::string value = env_str.substr(delimiter_position + 1);
        env[key] = value;
    }
}

void load_from_file(const std::string& filename, env_map& env) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string value;
            if (key[0] == '#' || key.empty()) {
                continue; // Skip comments or empty lines
            }
            if (std::getline(is_line, value)) {
                env[key] = value;
            }
        }
    }
}

env_map load_env(const std::string& filename) {
    env_map env;
    load_from_file(filename, env);
    load_from_sys_env(env);
    return env;
}


