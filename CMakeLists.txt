cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

project(Gaia_Archive_Tools C)


set(CSV_PARSER_DIR external/csv-fast-reader)

#Archive converter library
add_library(GaiaArchiveTools STATIC 
    GaiaArchiveTools/src/gaiaArchiveTools.c
    ${CSV_PARSER_DIR}/csv.c
)
target_include_directories(GaiaArchiveTools PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/GaiaArchiveTools/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)

#archive converter executable
add_executable(gaia-exp GaiaArchiveTools/src/main.c)
target_link_libraries(gaia-exp PUBLIC GaiaArchiveTools)

set_target_properties(GaiaArchiveTools gaia-exp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)