cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

project(GaiaArchiveTools C)


set(CSV_PARSER_DIR externals/csv-fast-reader)

#archive tools library
add_library(gaia-archive-tools STATIC 
    GaiaArchiveTools/src/gaiaArchiveTools.c
    ${CSV_PARSER_DIR}/csv.c
)
target_include_directories(gaia-archive-tools PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/GaiaArchiveTools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/externals
)

#archive converter executable
add_executable(gaia-exp GaiaArchiveTools/src/gaia-exp.c)
target_link_libraries(gaia-exp PUBLIC gaia-archive-tools)


#archive reader example
add_executable(gaia_read_example gaia_read_example/src/main.c)
target_link_libraries(gaia_read_example PUBLIC gaia-archive-tools)
set_target_properties(gaia_read_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

set_target_properties(gaia-archive-tools gaia-exp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)