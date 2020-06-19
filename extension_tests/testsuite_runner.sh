#!/bin/bash
make > ext_test_execute_make_log.txt
./ext_test_execute
echo "Now testing sample.TXT"
cd ..
make > CLogic_make_log.txt
./CLogic ./extension_tests/sample.TXT > ./extension_tests/sample_output.out
cmp --silent ./extension_tests/sample_expected_output.out ./extension_tests/sample_output.out && echo '### SUCCESS: sample.TXT is as expected! ###' || echo '### WARNING: Output is different to what was expected! Check logs! ###'