#ifndef LOADENV_H
#define LOADENV_H

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> loadEnv(const std::string& filename);

#endif // LOADENV_H
