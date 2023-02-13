add_subdirectory(DynamicArray)
add_subdirectory(WordOccurrence)

add_library(WordList
            WordList.hpp
            WordList.cpp
            DynamicArray)

target_link_libraries(WordList WordOccurrence)

set(TESTS
  AddWord
  Assign
  Equal
  WordList)

macro(linkTest TEST_NAME)
  set(TST "test${TEST_NAME}")
  add_executable(${TST} "test/${TST}.cpp")
  target_link_libraries(${TST} WordList)
  add_test(NAME ${TST} COMMAND ${TST})

endmacro()

foreach(TEST IN LISTS TESTS)

  linkTest(${TEST})

endforeach()


enable_testing()
