#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include "gaia-archive-tools/gaiaArchiveTools.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {//example call: ./gaia-split ../gaia-bin/  0000
    if (argc == 3) {
        gaiaSplit(argv[1], (uint32_t)atoi(argv[2]));
    }
    else if (argc == 4) {
        for (uint32_t i = (uint32_t)atoi(argv[2]); i < ((uint32_t)atoi(argv[3]) + 1); i++) {
            gaiaConvertCSV(
                argv[1],
                argv[2],
                i
            );
        }
    }
    else {
        printf("gaia-split error: wrong arguments\n");
    }
    return 0;
}

#ifdef  __cplusplus
}
#endif//__cplusplus