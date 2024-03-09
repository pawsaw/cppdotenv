#include "load_env.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("loadEnv loads environment variables from a single .env file",
          "[loadEnv]") {
  const std::filesystem::path filepath = "./test_files/.env";

  env_map env = load_env(filepath);

  REQUIRE(env["FOO"] == "foo");
  REQUIRE(env["BAR"] == "bar");
}

TEST_CASE("loadEnv loads environment variables from multiple .env files",
          "[loadEnv]") {
  std::vector<std::filesystem::path> filepaths = {"test_files/.env",
                                                  "test_files/.env.local"};

  env_map env = load_env(filepaths);

  REQUIRE(env["FOO"] == "foo");
  REQUIRE(env["BAR"] == "bar.local");
}
