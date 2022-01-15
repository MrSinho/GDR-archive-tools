cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

project(GaiaArchive C)


set(CSV_PARSER_DIR external/csv-fast-reader)

#Archive converter library
set(GAIA_ARCHIVE_CONVERTER_SRC gaia_archive_converter/src)
add_library(gaia_archive_converter STATIC 
    ${GAIA_ARCHIVE_CONVERTER_SRC}/gaia_archive_converter.c
    ${CSV_PARSER_DIR}/csv.c
)
target_include_directories(gaia_archive_converter PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/gaia_archive_converter/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)

#archive converter executable
add_executable(gaia_exp gaia_archive_converter/src/main.c)
target_link_libraries(gaia_exp PUBLIC gaia_archive_converter)

set_target_properties(gaia_archive_converter gaia_exp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)