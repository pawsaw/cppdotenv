# cppdotenv

A C++20 library for loading configurations from a `.env` file.

## How to use

### Prerequisites

Make sure you're using C++20 in your app.

`CMakeLists.txt`
```cmake
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

### Setup

Make sure you've added the *cppdotenv* library to your `CMakeLists.txt` file:

```cmake
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

### Basic Usage

Add a `.env` file to the root of your project.

*Example*:
```ini
DB_HOST=localhost
DB_USER=root
DB_PASS=s3cret
```
Use it in your code:
```cpp
#include <iostream>
#include <load_env.h>

int main() {
    auto env = load_env(".env"); // Use the library's functionality

    std::cout << "DB_HOST: " << env["DB_HOST"] << std::endl;
    std::cout << "DB_USER: " << env["DB_USER"] << std::endl;
    std::cout << "DB_PASS: " << env["DB_PASS"] << std::endl;

    return 0;
}
```

### Multiple *.env* files (overrides)

It's also possible to use multiple `.env` files. The **order is important**. The naming does **not** matter. 

*Example*:

```ini
# filename: .env

FOO=foo
BAR=bar
```

and...

```ini
# filename: .env.local

BAR=bar.local
```

```cpp
#include <iostream>
#include <vector>
#include <load_env.h>

int main() {
    auto env = load_env(std::vector<std::string>{".env", ".env.local"});

    std::cout << "FOO: " << env["FOO"] << std::endl; // output: FOO: foo
    std::cout << "BAR: " << env["BAR"] << std::endl; // output: BAR: bar.local

    return 0;
}
```

### Use environment variables

Environment variables override the definitions from the `.env` files.

Assuming you build the example above as `myapp`, considering `.env` and `.env.local` in the same directory and execute it like this:

```sh
FOO=myfoo ./myapp
```

The output is:

```sh
FOO: myfoo
BAR: bar.local
```


## License

```txt
Copyright 2024 Pawel Sawicki

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```