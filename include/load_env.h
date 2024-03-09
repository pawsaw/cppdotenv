#ifndef LOADENV_H
#define LOADENV_H

#include <filesystem>
#include <ostream>
#include <string>
#include <unordered_map>

using env_map = std::unordered_map<std::string, std::string>;

std::ostream &operator<<(std::ostream &os, const env_map &env);

env_map load_env(const std::filesystem::path &filepath);

void load_from_file(const std::filesystem::path &filepath, env_map &env);
void load_from_sys_env(env_map &env);

template <std::ranges::range TContainer>
  requires std::is_same_v<std::ranges::range_value_t<TContainer>,
                          std::filesystem::path>
env_map load_env(const TContainer &filepaths) {
  env_map env;
  for (const auto &filepath : filepaths) {
    load_from_file(filepath, env);
  }
  load_from_sys_env(env);
  return env;
}

#endif // LOADENV_H
