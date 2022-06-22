#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include "gaia-archive-tools/gaiaArchiveTools.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {//example call: ./gaia-split ../gaia-bin/  0
    //gaiaSplit("../gaia-bin/", 0);
    if (argc == 3) {
        gaiaSplit(argv[1], (uint32_t)atoi(argv[2]));
    }
    else {
        printf("gaia-split error: wrong arguments\n");
    }
    return 0;
}

#ifdef  __cplusplus
}
#endif//__cplusplus