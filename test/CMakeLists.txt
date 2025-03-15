cmake_minimum_required(VERSION 3.10)

set(This ExampleTests)

set(Sourses
    ExampleTests.cpp
)

set(Headers
    ../lib.h
    ../build/version.h
)

add_executable(${This} ${Sourses} ${Headers})


target_link_libraries(${This} PUBLIC
    gtest_main
    helloworld
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

