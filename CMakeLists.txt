cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)



project(gaia-archive-tools C)



function(build_archive_tools)
add_library(gaia-archive-tools STATIC 
    gaia-archive-tools/src/gaia-archive-tools.c
    external/csv-fast-reader/csv.c
)
target_include_directories(gaia-archive-tools PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/gaia-archive-tools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)

add_executable(gaia-exp   gaia-exp/src/gaia-exp.c)
add_executable(gaia-split gaia-split/src/gaia-split.c)

target_link_libraries(gaia-exp   PUBLIC gaia-archive-tools)
target_link_libraries(gaia-split PUBLIC gaia-archive-tools)

set_target_properties(gaia-archive-tools gaia-exp gaia-split PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
endfunction()



function(build_examples)
add_executable(gaia-read-sample    samples/src/gaia-read.c)
add_executable(gaia-convert-sample samples/src/gaia-convert.c)

target_link_libraries(gaia-read-sample    PUBLIC gaia-archive-tools)
target_link_libraries(gaia-convert-sample PUBLIC gaia-archive-tools)

set_target_properties(gaia-read-sample gaia-convert-sample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
endfunction()



option(GAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES CACHE OFF)



function(main)
build_archive_tools()
if (GAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES)
build_examples()
endif(GAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES)
endfunction()



main()