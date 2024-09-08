add_test([=[DistributedTrackingTest.BuildsCorrectly]=]  C:/Users/seanl/Dynamic-RTS/src/build/distributed_tracking_test.exe [==[--gtest_filter=DistributedTrackingTest.BuildsCorrectly]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DistributedTrackingTest.BuildsCorrectly]=]  PROPERTIES WORKING_DIRECTORY C:/Users/seanl/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DistributedTrackingTest.CreatesCorrectSlackWhenSmall]=]  C:/Users/seanl/Dynamic-RTS/src/build/distributed_tracking_test.exe [==[--gtest_filter=DistributedTrackingTest.CreatesCorrectSlackWhenSmall]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DistributedTrackingTest.CreatesCorrectSlackWhenSmall]=]  PROPERTIES WORKING_DIRECTORY C:/Users/seanl/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DistributedTrackingTest.CreatesCorrectSlackWhenBig]=]  C:/Users/seanl/Dynamic-RTS/src/build/distributed_tracking_test.exe [==[--gtest_filter=DistributedTrackingTest.CreatesCorrectSlackWhenBig]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DistributedTrackingTest.CreatesCorrectSlackWhenBig]=]  PROPERTIES WORKING_DIRECTORY C:/Users/seanl/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DistributedTrackingTest.ProcessSignalWithoutMaturity]=]  C:/Users/seanl/Dynamic-RTS/src/build/distributed_tracking_test.exe [==[--gtest_filter=DistributedTrackingTest.ProcessSignalWithoutMaturity]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DistributedTrackingTest.ProcessSignalWithoutMaturity]=]  PROPERTIES WORKING_DIRECTORY C:/Users/seanl/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DistributedTrackingTest.HandlesMaturityWhenSmall]=]  C:/Users/seanl/Dynamic-RTS/src/build/distributed_tracking_test.exe [==[--gtest_filter=DistributedTrackingTest.HandlesMaturityWhenSmall]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DistributedTrackingTest.HandlesMaturityWhenSmall]=]  PROPERTIES WORKING_DIRECTORY C:/Users/seanl/Dynamic-RTS/src/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  distributed_tracking_test_TESTS DistributedTrackingTest.BuildsCorrectly DistributedTrackingTest.CreatesCorrectSlackWhenSmall DistributedTrackingTest.CreatesCorrectSlackWhenBig DistributedTrackingTest.ProcessSignalWithoutMaturity DistributedTrackingTest.HandlesMaturityWhenSmall)
