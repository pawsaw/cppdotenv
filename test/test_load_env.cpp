#include <catch2/catch_test_macros.hpp>
#include "load_env.h"
#include <vector>
#include <string>

TEST_CASE("loadEnv loads environment variables from a single .env file", "[loadEnv]") {
    const std::string filename = "./test_files/.env";

    env_map env = load_env(filename);


    REQUIRE(env["FOO"] == "foo");
    REQUIRE(env["BAR"] == "bar");
}

TEST_CASE("loadEnv loads environment variables from multiple .env files", "[loadEnv]") {
    std::vector<std::string> filenames = {"test_files/.env", "test_files/.env.local"};

    env_map env = load_env(filenames);

    REQUIRE(env["FOO"] == "foo");
    REQUIRE(env["BAR"] == "bar.local");
}
