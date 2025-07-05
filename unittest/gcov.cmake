option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

if(ENABLE_COVERAGE)
    # Check compiler
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # Add coverage flags
        add_compile_options(-fprofile-arcs -ftest-coverage)
        add_link_options(--coverage)
        
        # Find required programs
        find_program(GCOV_PATH gcov REQUIRED)
        find_program(LCOV_PATH lcov)
        find_program(GENHTML_PATH genhtml)

        # Set paths using CMake variables
        set(GCNO_DIR "${CMAKE_BINARY_DIR}/CMakeFiles/cmlite_test.dir")
        set(COVERAGE_DIR "${CMAKE_BINARY_DIR}/coverage")
        
        # Custom target for coverage
        add_custom_target(gcov
            # Clean previous coverage data
            COMMAND ${CMAKE_COMMAND} -E remove_directory ${COVERAGE_DIR}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${COVERAGE_DIR}
            COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/*.info
            
            # Run tests
            COMMAND ${CMAKE_BINARY_DIR}/cmlite_test
            
            # LCOV operations
            
            COMMAND ${LCOV_PATH} --directory . --capture --initial --output-file baseline.info
            COMMAND ${LCOV_PATH} --directory . --capture --output-file tests.info
            COMMAND ${LCOV_PATH} --add-tracefile baseline.info --add-tracefile tests.info --output-file total.info
            COMMAND ${LCOV_PATH} --remove total.info '/usr/*' '*/tests/*' '*/moc_*.cpp' '*/qrc_*.cpp' '*/ui_*.h' --output-file filtered.info
            
            # Generate HTML report
            COMMAND ${GENHTML_PATH} filtered.info --output-directory ${COVERAGE_DIR}
            
            # GCOV text report
            COMMAND ${GCOV_PATH} -o ${GCNO_DIR} ${GCNO_DIR}/*.gcno
            
            # Cleanup and final message
            COMMAND ${CMAKE_COMMAND} -E remove baseline.info tests.info total.info
            COMMAND ${CMAKE_COMMAND} -E echo "HTML report: file://${COVERAGE_DIR}/index.html"
            
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            DEPENDS cmlite_test
            COMMENT "Generating code coverage reports"
        )

        # Add status messages
        if(LCOV_PATH AND GENHTML_PATH)
            message(STATUS "LCOV configured: HTML reports enabled")
        else()
            message(WARNING "LCOV/genhtml not found - HTML reports disabled")
        endif()
    else()
        message(WARNING "Code coverage requires GCC or Clang compiler")
    endif()
endif()