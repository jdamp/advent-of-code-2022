add_executable(AOCTools_Test test_tools.cpp)
target_link_libraries(AOCTools_Test GTest::GTest aocUtils)
add_test(AOCTest AOCTools_Test)