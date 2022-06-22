#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include <gaia-archive-tools/gaiaArchiveTools.h>

int main(void) {
	
    gaiaConvertCSV(
        "../gaia-csv/gaiaUniverseModel_0000.csv",
        "../gaia-bin/gaiaUniverseModel_0000.bin",
        UINT32_MAX
    );

	return 0;
}

#ifdef  __cplusplus
}
#endif//__cplusplus