# export CXX=/usr/bin/clang++
#cmake最低版本要求
cmake_minimum_required(VERSION 2.6)

#项目名称
project(Base)

option(test "Build all tests." ON) # Makes boolean 'test' available.

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

#set (cxx-sources Socket.cpp)
#foreach (source ${cxx-sources})
#  list (APPEND sources ${CMAKE_CURRENT_SOURCE_DIR}/src/${source})
#endforeach ()

#add_library(Base ${sources})
#install(TARGETS HelloSocket DESTINATION ${PROJECT_SOURCE_DIR}/lib)

if (test)
  add_subdirectory(3rd_lib/googletest)
  include_directories(${PROJECT_SOURCE_DIR}/src)
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  enable_testing()

  #set (cxx-sources-src TcpChannel.cpp)
  #foreach (source ${cxx-sources-src})
  #  list (APPEND sources-src ${CMAKE_CURRENT_SOURCE_DIR}/src/${source})
  #endforeach ()

  set (cxx-sources-src_unittest Slice_unittest.cpp)
  foreach (source ${cxx-sources-src_unittest})
    list (APPEND sources-src_unittest
      ${CMAKE_CURRENT_SOURCE_DIR}/src_unittest/${source})
  endforeach ()

  add_executable(runUnitTests ${sources-src} ${sources-src_unittest})
  target_link_libraries(runUnitTests gtest gtest_main)

  add_test(NAME that-test-I-made COMMAND runUnitTests)
  add_test(that-other-test-I-made runUnitTests)
endif()
