add_test( EndpointTreeTest.StabsCorrectNumberOfNodes /Users/sean/Dynamic-RTS/src/build/element_processing_test [==[--gtest_filter=EndpointTreeTest.StabsCorrectNumberOfNodes]==] --gtest_also_run_disabled_tests)
set_tests_properties( EndpointTreeTest.StabsCorrectNumberOfNodes PROPERTIES WORKING_DIRECTORY /Users/sean/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( element_processing_test_TESTS EndpointTreeTest.StabsCorrectNumberOfNodes)
