add_library(day05lib day05.hpp day05.cpp)
target_link_libraries(day05lib aocUtils)
set_target_properties(day05lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(AOCDay05 main.cpp)
target_link_libraries(AOCDay05 day05lib)

add_executable(AOCDay05_Test test_day05.cpp)
target_link_libraries(AOCDay05_Test GTest::gtest_main day05lib)
add_test(Day05Tests AOCDay05_Test)