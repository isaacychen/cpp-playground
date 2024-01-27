add_executable(leetcode
        00026RemoveDuplicatesFromSortedArray.cpp
        00027RemoveElement.cpp
        00088MergeSortedArray.cpp
        00080RemoveDuplicatesFromSortedArray2.cpp
)
target_link_libraries(
        leetcode
        GTest::gtest_main
)
gtest_discover_tests(leetcode)

add_executable(cpp-playground
        main.cpp
)
