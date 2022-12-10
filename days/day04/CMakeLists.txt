add_library(day04lib day04.hpp)
target_link_libraries(day04lib aocUtils)
set_target_properties(day04lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(AOCDay04 main.cpp)
target_link_libraries(AOCDay04 day04lib)

add_executable(AOCDay04_Test test_day04.cpp)
target_link_libraries(AOCDay04_Test GTest::gtest_main day04lib)
add_test(Day04Tests AOCDay04_Test)