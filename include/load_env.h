#ifndef LOADENV_H
#define LOADENV_H

#include <string>
#include <unordered_map>
#include <vector>
#include <ostream>

using env_map = std::unordered_map<std::string, std::string>;

std::ostream& operator<<(std::ostream& os, const env_map& env);

env_map load_env(const std::string& filename);

void load_from_file(const std::string& filename, env_map& env);
void load_from_sys_env(env_map& env);

template <std::ranges::range TContainer>
    requires std::is_same_v<std::ranges::range_value_t<TContainer>, std::string>
env_map load_env(const TContainer& filenames) {
    env_map env;
    for (const auto& filename : filenames) {
        load_from_file(filename, env);
    }
    load_from_sys_env(env);
    return env;
}

#endif // LOADENV_H
