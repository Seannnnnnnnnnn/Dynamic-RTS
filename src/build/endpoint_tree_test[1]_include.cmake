if(EXISTS "/Users/sean/Dynamic-RTS/src/build/endpoint_tree_test[1]_tests.cmake")
  include("/Users/sean/Dynamic-RTS/src/build/endpoint_tree_test[1]_tests.cmake")
else()
  add_test(endpoint_tree_test_NOT_BUILT endpoint_tree_test_NOT_BUILT)
endif()
