#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include "gaia_archive_tools/gaiaArchiveTools.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	
    if (argc == 3) {
        gaiaSplit(
            argv[1],
            argv[2]
        );
    }
    else {
        printf("gaia-split error: wrong arguments\n");
    }

    return 0;
}

#ifdef  __cplusplus
}
#endif//__cplusplus