#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include <gaia-archive-tools/gaiaArchiveTools.h>

#include <stdlib.h>
#include <stdio.h>



//example call: ./gaia-exp gaiaUniverseModel_0001.csv gaiaUniverseModel_0001.bin
//example call: ./gaia-exp gaiaUniverseModel_0001.csv gaiaUniverseModel_0001.bin 2500
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
        printf("gaia-exp error: wrong arguments\n");
    }
    return 0;
}



#ifdef  __cplusplus
}
#endif//__cplusplus