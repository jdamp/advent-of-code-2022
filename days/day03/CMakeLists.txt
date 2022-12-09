add_library(day03lib day03.hpp)
target_link_libraries(day03lib aocUtils)
set_target_properties(day03lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(AOCDay03 main.cpp)
target_link_libraries(AOCDay03 day03lib)

add_executable(AOCDay03_Test test_day03.cpp)
target_link_libraries(AOCDay03_Test GTest::gtest_main day03lib)
add_test(Day03Tests AOCDay03_Test)