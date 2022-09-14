#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include <gaia-archive-tools/gaiaArchiveTools.h>
#include <stdio.h>

int main(void) {
	
    const char* src_path = "../gaia-csv/gaiaUniverseModel_0000.csv";
    const char* dst_path = "../gaia-csv/gaiaUniverseModel_0000.csv";

    printf("Converting\n\t%s\n\tto\n\t%s", 
        src_path, 
        dst_path
    );

    gaiaConvertCSV(
        src_path,
        dst_path,
        UINT32_MAX
    );

	return 0;
}

#ifdef  __cplusplus
}
#endif//__cplusplus