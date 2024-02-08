#include <catch2/catch_test_macros.hpp>
#include "loadEnv.h"
#include <vector>
#include <string>
#include <iostream>

TEST_CASE("loadEnv loads environment variables from a single .env file", "[loadEnv]") {
    const std::string filename = "./test_files/.env";

    env_map env = loadEnv(filename);

    std::cout << env << std::endl;

    REQUIRE(env["FOO"] == "foo");
    REQUIRE(env["BAR"] == "bar");
}

TEST_CASE("loadEnv loads environment variables from multiple .env files", "[loadEnv]") {
    std::vector<std::string> filenames = {"test_files/.env", "test_files/.env.local"};

    env_map env = loadEnv(filenames);

    std::cout << env << std::endl;

    REQUIRE(env["FOO"] == "foo");
    REQUIRE(env["BAR"] == "bar.local");
}
