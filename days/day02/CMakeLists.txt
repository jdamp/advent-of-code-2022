add_library(day02lib day02.hpp)
target_link_libraries(day02lib aocUtils)
set_target_properties(day02lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(AOCDay02 main.cpp)
target_link_libraries(AOCDay02 day02lib)

add_executable(AOCDay02_Test test_day02.cpp)
target_link_libraries(AOCDay02_Test GTest::gtest_main day02lib)
add_test(Day02Tests AOCDay02_Test)