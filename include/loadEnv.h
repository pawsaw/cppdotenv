#ifndef LOADENV_H
#define LOADENV_H

#include <concepts>
#include <array>
#include <unordered_map>
#include <string>
#include <vector>

std::unordered_map<std::string, std::string> loadEnv(const std::string& filename);

template<std::ranges::range Range>
    requires std::same_as<std::ranges::range_value_t<Range>, std::string>
std::unordered_map<std::string, std::string> loadEnv(const Range& filenames);

#endif // LOADENV_H
