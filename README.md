# cppdotenv

A C++20 library for loading configurations from a `.env` file.

## How to use

### Prerequisites

Make sure you're using C++20 in your app.

`CMakeLists.txt`
```
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

### Setup

Make sure you've added the *cppdotenv* library to your `CMakeLists.txt` file:

```
include(FetchContent)
FetchContent_Declare(
    cppdotenv
    GIT_REPOSITORY https://github.com/pawsaw/cppdotenv.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(cppdotenv)

# Include directories for cppdotenv
target_include_directories(YourApp PRIVATE ${cppdotenv_SOURCE_DIR}/include)

# Link cppdotenv to your target
target_link_libraries(YourApp PRIVATE cppdotenv)
```

### Usage

Add a `.env` file to the root of your project.

*Example*:
```
DB_HOST=localhost
DB_USER=root
DB_PASS=s3cret
```
Use it in your code:
```
#include <iostream>
#include "cppdotenv/loadEnv.h"

int main() {
    auto env = loadEnv(".env"); // Use the library's functionality

    std::cout << "DB_HOST: " << env["DB_HOST"] << std::endl;
    std::cout << "DB_USER: " << env["DB_USER"] << std::endl;
    std::cout << "DB_PASS: " << env["DB_PASS"] << std::endl;

    return 0;
}
```