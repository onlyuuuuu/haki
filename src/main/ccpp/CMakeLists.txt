cmake_minimum_required(VERSION 3.28)
project(ccpp C CXX)

set(CMAKE_C_STANDARD            23)
set(CMAKE_CXX_STANDARD          23)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    include_directories(AFTER SYSTEM
        /Library/Developer/CommandLineTools/usr/include/c++/v1
        /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1
        /Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include
        /Library/Developer/CommandLineTools/usr/include
        /Library/Developer/CommandLineTools/usr/include
        /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
        /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
        /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
        /usr/local/include
        /usr/include
        /usr/lib
    )
endif()

# Only grab .cpp/.c from src/
file(GLOB_RECURSE
    SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(ccpp main/05/m1_s5_4.cpp)

if(MINGW)
    target_compile_definitions(ccpp PRIVATE
        NDEBUG
        _GLIBCXX_ASSERTIONS
    )
    target_compile_options(ccpp PRIVATE
        -std=gnu++23
        -O2 -pipe
        -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal
        -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond
        -Wcast-qual -Wcast-align -Wnull-dereference -Wuseless-cast -Wdouble-promotion
        -Wpedantic -Wsign-conversion -Wimplicit-fallthrough=3 -Wnon-virtual-dtor
        -Woverloaded-virtual -Wold-style-cast -Wzero-as-null-pointer-constant
        -fanalyzer
    )
    target_link_options(ccpp PRIVATE
        -static
        -static-libgcc
        -static-libstdc++
        -s
    )
endif()
