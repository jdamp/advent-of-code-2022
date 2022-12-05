add_library(day01lib include/day01.h src/day01.cpp)
target_include_directories(day01lib PRIVATE include)

add_executable(AOCDay01 main.cpp)
target_include_directories(AOCDay01 PRIVATE ../../include)
target_link_libraries(AOCDay01 day01lib aocUtils)

add_executable(AOCDay01_Test tests/test_day01.cpp)
target_include_directories(AOCDay01_Test PRIVATE include)
target_link_libraries(AOCDay01_Test GTest::GTest day01lib)
add_test(Day01Tests AOCDay01_Test)