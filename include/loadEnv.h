#ifndef LOADENV_H
#define LOADENV_H

#include <string>
#include <unordered_map>
#include <vector>
#include <ostream>

using env_map = std::unordered_map<std::string, std::string>;

std::ostream& operator<<(std::ostream& os, const env_map& env);

env_map loadEnv(const std::string& filename);
env_map loadEnv(const std::vector<std::string>& filenames);

#endif // LOADENV_H
