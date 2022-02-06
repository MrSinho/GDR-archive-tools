cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

project(Gaia_Archive_Tools C)


set(CSV_PARSER_DIR externals/csv-fast-reader)

add_subdirectory(externals/curl)

#archive tools library
add_library(GaiaArchiveTools STATIC 
    GaiaArchiveTools/src/gaiaArchiveTools.c
    ${CSV_PARSER_DIR}/csv.c
)
target_include_directories(GaiaArchiveTools PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/GaiaArchiveTools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/externals
    ${CMAKE_CURRENT_SOURCE_DIR}/externals/curl/include
)
target_link_libraries(GaiaArchiveTools PUBLIC libcurl)

#archive converter executable
add_executable(gaia-exp GaiaArchiveTools/src/main.c)
target_link_libraries(gaia-exp PUBLIC GaiaArchiveTools)

#archive reader example
add_executable(gaia_read_example gaia_read_example/src/main.c)
target_link_libraries(gaia_read_example PUBLIC GaiaArchiveTools)
set_target_properties(gaia_read_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

set_target_properties(GaiaArchiveTools gaia-exp libcurl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)