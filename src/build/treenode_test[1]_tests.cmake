add_test([=[TreeNodeTest.StabsCorrectValueFiniteBounds]=]  /Users/sean/Dynamic-RTS/src/build/treenode_test [==[--gtest_filter=TreeNodeTest.StabsCorrectValueFiniteBounds]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TreeNodeTest.StabsCorrectValueFiniteBounds]=]  PROPERTIES WORKING_DIRECTORY /Users/sean/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TreeNodeTest.DoesntStabIncorrectValueFiniteBounds]=]  /Users/sean/Dynamic-RTS/src/build/treenode_test [==[--gtest_filter=TreeNodeTest.DoesntStabIncorrectValueFiniteBounds]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TreeNodeTest.DoesntStabIncorrectValueFiniteBounds]=]  PROPERTIES WORKING_DIRECTORY /Users/sean/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TreeNodeTest.StabsCorrectValueInfiniteBounds]=]  /Users/sean/Dynamic-RTS/src/build/treenode_test [==[--gtest_filter=TreeNodeTest.StabsCorrectValueInfiniteBounds]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TreeNodeTest.StabsCorrectValueInfiniteBounds]=]  PROPERTIES WORKING_DIRECTORY /Users/sean/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  treenode_test_TESTS TreeNodeTest.StabsCorrectValueFiniteBounds TreeNodeTest.DoesntStabIncorrectValueFiniteBounds TreeNodeTest.StabsCorrectValueInfiniteBounds)