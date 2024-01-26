set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cpp-playground
        main.cpp
)

add_executable(leetcode
        00026RemoveDuplicatesFromSortedArray.cpp
        00027RemoveElement.cpp
        00088MergeSortedArray.cpp
)
target_link_libraries(
        leetcode
        GTest::gtest_main
)
gtest_discover_tests(leetcode)
