cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)



project(gaia-archive-tools C)



function(build_archive_tools)
add_library(gaia-archive-tools STATIC 
    gaia-archive-tools/src/gaia-archive-tools.c
    external/csv-fast-reader/csv.c
)
add_executable(gaia-exp 
    gaia-archive-tools/src/gaia-exp.c
    gaia-archive-tools/src/gaia-archive-tools.c
    external/csv-fast-reader/csv.c
)
add_executable(gaia-split 
    gaia-archive-tools/src/gaia-split.c
    gaia-archive-tools/src/gaia-archive-tools.c
    external/csv-fast-reader/csv.c
)
target_include_directories(gaia-archive-tools PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/gaia-archive-tools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)
target_include_directories(gaia-exp PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/gaia-archive-tools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)
target_include_directories(gaia-split PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/gaia-archive-tools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)
set_target_properties(gaia-archive-tools gaia-exp gaia-split PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
endfunction()



function(build_examples)
add_executable(gaia-read-example gaia-read-example/src/main.c)
add_executable(gaia-convert-example gaia-convert-example/src/main.c)
target_link_libraries(gaia-read-example PUBLIC gaia-archive-tools)
target_link_libraries(gaia-convert-example PUBLIC gaia-archive-tools)
set_target_properties(gaia-read-example gaia-convert-example PROPERTIES
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