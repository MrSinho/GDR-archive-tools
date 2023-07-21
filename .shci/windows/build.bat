> .shci/windows/build-output.txt (
    mkdir windows-build
    cd windows-build
    cmake .. -DGAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES=ON
    cmake --build .
)
