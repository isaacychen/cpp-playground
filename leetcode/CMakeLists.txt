add_executable(leetcode
        P0026RemoveDuplicatesFromSortedArray.cpp
        P0027RemoveElement.cpp
        P0088MergeSortedArray.cpp
        P0080RemoveDuplicatesFromSortedArray2.cpp
        P0169MajorityElement.cpp
        P0189RotateArray.cpp
        P0121BestTimetoBuyandSellStock.cpp
)
target_link_libraries(
        leetcode
        GTest::gtest_main
)
gtest_discover_tests(leetcode)

add_executable(cpp-playground
        main.cpp
)
