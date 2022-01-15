#include "gaia_archive_converter/gaia_archive_converter.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc == 3) {
        gaiaConvertCSV(
            argv[1],
            argv[2],
            UINT32_MAX
        );
    }
    else if (argc == 4) {
        gaiaConvertCSV(
            argv[1],
            argv[2],
            (uint32_t)atoi(argv[3])
        );
    }
    else {
        printf("Gaia Archive Converter error: wrong arguments\n");
    }
    return 0;
}