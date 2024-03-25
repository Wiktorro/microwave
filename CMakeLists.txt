project(microwave)


# rsi_reference_layout_library()
#  if("RECURSE" IN_LIST ARGV)
#    set(RECURSIVELY TRUE)
#    list(REMOVE_ITEM ARGV RECURSE)
#  else()
#    set(RECURSIVELY FALSE)
#  endif()
file(GLOB_RECURSE SRC "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include/)

# target_link_libraries(${PROJECT_NAME} cuuds uds_items_catalog diagnostic_validator_interface)

if(ENABLE_GTEST_UNIT_TESTS)
  file(GLOB_RECURSE SRC CONFIGURE_DEPENDS test/*.cpp)

  add_executable(${PROJECT_NAME}_ut ${SRC})

  target_link_libraries(${PROJECT_NAME}_ut ${PROJECT_NAME})

#  rsi_register_ut_executable(${PROJECT_NAME}_ut)
  target_link_libraries(${name_ut} "${GMOCK_LIB}")
  rsi_add_shorter_file_paths(${name_ut})

  set(XML_TEST_RESULT_PATH "${CMAKE_CURRENT_BINARY_DIR}/${name_ut}_gtest-test-results.xml")

  # Ensure it can be built without running
  add_dependencies(ut_build ${name_ut})

  # Reproducible and incremental friendly
  add_custom_command(
    OUTPUT "${XML_TEST_RESULT_PATH}"
    COMMAND ${SANITIZER_FLAGS} ${CMAKE_CURRENT_BINARY_DIR}/${name_ut} --gtest_output=xml:${XML_TEST_RESULT_PATH}
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Target ${name_ut} finished"
    COMMENT "Running unit tests ${name_ut}"
    DEPENDS ${name_ut}
    VERBATIM
  )

  add_custom_target(${name_ut}_run DEPENDS "${XML_TEST_RESULT_PATH}")
  add_dependencies(ut ${name_ut}_run)
  # End reproducible and incremental friendly

  # Add ctest option
  add_test(NAME ${name_ut} COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${name_ut} --gtest_output=xml:${XML_TEST_RESULT_PATH})
  set_tests_properties(${name_ut} PROPERTIES LABELS "${name_ut};ut")
  set_tests_properties(${name_ut} PROPERTIES ENVIRONMENT "${SANITIZER_FLAGS}")
endif()

# target_link_libraries(  ${PROJECT_NAME} )
