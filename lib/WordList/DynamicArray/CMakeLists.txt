set(CMAKE_CXX_STANDARD 11)
add_library(DynamicArray
            INTERFACE 
            )
target_include_directories(
  DynamicArray
  INTERFACE CMAKE_CURRENT_LIST_DIR
  )

#add_subdirectory(../WordOccurrence WordOccurrence)
#target_link_libraries(DynamicArray INTERFACE WordOccurrence)
macro(genTest TEST_NAME)

  set(TST "DynamicArray_${TEST_NAME}")
  add_executable(${TST} "test/test${TEST_NAME}.cpp")
  add_test(NAME ${TST} COMMAND ${TST})

  target_link_libraries(${TST} DynamicArray)

endmacro()

genTest(AddElement)
genTest(InsertElement)
genTest(RemoveElement)

enable_testing()
