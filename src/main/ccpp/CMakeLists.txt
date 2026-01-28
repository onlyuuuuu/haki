cmake_minimum_required(VERSION 3.28)
project(ccpp C CXX)

set(CMAKE_C_STANDARD              23)
set(CMAKE_CXX_STANDARD            23)
set(CMAKE_C_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_STANDARD_REQUIRED   ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Only grab .cpp/.c from src/
file(GLOB_RECURSE
    SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "main/test/*.cpp"
    "main/06/*.cpp"
)

add_executable(ccpp ${SOURCES})

if(MINGW)
    # Match VSCode tasks.json: g++.exe build (O2)
    target_compile_definitions(ccpp PRIVATE
        NDEBUG
        _GLIBCXX_ASSERTIONS
        _GLIBCXX_DEBUG
    )
    target_compile_options(ccpp PRIVATE
        -fdiagnostics-color=always
        -std=gnu++23
        -g
        -O2
        -fsanitize-address-use-after-scope
        -fno-omit-frame-pointer
        -pipe
    )
    target_link_options(ccpp PRIVATE
        -static
        -static-libgcc
        -static-libstdc++
    )
elseif(UNIX AND NOT APPLE)
    # Match VSCode tasks.json: g++ build (O2) for Linux
    target_compile_definitions(ccpp PRIVATE
        NDEBUG
        _GLIBCXX_ASSERTIONS
        _GLIBCXX_DEBUG
    )
    target_compile_options(ccpp PRIVATE
        -fdiagnostics-color=always
        -std=gnu++23
        -g
        -O2
        -fsanitize=address,undefined
        -fsanitize-address-use-after-scope
        -fno-omit-frame-pointer
        -pipe
    )
    target_link_options(ccpp PRIVATE
        -fsanitize=address,undefined
        -fsanitize-address-use-after-scope
    )
elseif(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Match VSCode tasks.json: clang++ build (O2) for macOS
    target_compile_definitions(ccpp PRIVATE
        NDEBUG
        _LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_DEBUG
    )
    target_compile_options(ccpp PRIVATE
        -std=gnu++23
        -stdlib=libc++
        -fcolor-diagnostics
        -fansi-escape-codes
        -g
        -O2
        -fsanitize=address,undefined
        -fsanitize-address-use-after-scope
        -fno-omit-frame-pointer
        -pipe
    )
    target_link_options(ccpp PRIVATE
        -fsanitize=address,undefined
        -fsanitize-address-use-after-scope
    )
endif()
