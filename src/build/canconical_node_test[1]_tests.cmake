add_test( EndpointTreeTest.HasCorrectCanonicalNodeSet /Users/sean/Dynamic-RTS/src/build/canconical_node_test [==[--gtest_filter=EndpointTreeTest.HasCorrectCanonicalNodeSet]==] --gtest_also_run_disabled_tests)
set_tests_properties( EndpointTreeTest.HasCorrectCanonicalNodeSet PROPERTIES WORKING_DIRECTORY /Users/sean/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( canconical_node_test_TESTS EndpointTreeTest.HasCorrectCanonicalNodeSet)
