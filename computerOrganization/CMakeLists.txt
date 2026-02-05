project(computerOrganization)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

file(GLOB TEST_SOURCES "test/*.cc" "test/*.cpp")
file(GLOB TEST_HEADERS "test/*.h" "test/*.hpp")

add_executable(
  ${PROJECT_NAME}_test
  ${TEST_SOURCES}
)

target_include_directories(
  ${PROJECT_NAME}_test
  PRIVATE test
)

target_include_directories(
  ${PROJECT_NAME}_test
  PRIVATE src
)

target_link_libraries(
  ${PROJECT_NAME}_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)