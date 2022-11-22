# CMake generated Testfile for 
# Source directory: /Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp
# Build directory: /Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(dynamictsp_test "/Users/maurizioberta/Documents/Max 8/Packages/tsp/tests/dynamictsp_test")
  set_tests_properties(dynamictsp_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;66;add_test;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;0;;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;39;include;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(dynamictsp_test "/Users/maurizioberta/Documents/Max 8/Packages/tsp/tests/dynamictsp_test")
  set_tests_properties(dynamictsp_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;66;add_test;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;0;;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;39;include;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(dynamictsp_test "/Users/maurizioberta/Documents/Max 8/Packages/tsp/tests/MinSizeRel/dynamictsp_test")
  set_tests_properties(dynamictsp_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;66;add_test;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;0;;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;39;include;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(dynamictsp_test "/Users/maurizioberta/Documents/Max 8/Packages/tsp/tests/RelWithDebInfo/dynamictsp_test")
  set_tests_properties(dynamictsp_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;66;add_test;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/min-api/test/min-object-unittest.cmake;0;;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;39;include;/Users/maurizioberta/Documents/Max 8/Packages/tsp/source/projects/dynamictsp/CMakeLists.txt;0;")
else()
  add_test(dynamictsp_test NOT_AVAILABLE)
endif()
subdirs("mock")
