#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <gaia-archive-tools/gaiaArchiveTools.h>

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	uint32_t read_data = 0;
	
	char src_id[5];
	gaiaUniverseModelGetId(25, src_id); //"0025"

	float* values;

    //Downloads the file and reads the data
	//if size is set to 0, the entire file will be read.
    //gaiaReadWeb(src_id, GAIA_RA | GAIA_DEC, 0, 16, &read_data, &values); 
	

    //If you have already downloaded the binaries:
	gaiaReadBinaryFileFromID("../gaia_resources", 0, GAIA_RA | GAIA_DEC, 0, 16, &read_data, &values); //Reads ../gaia_resources/GaiaUniverseModel_0000.bin

	printf("\n\tREAD %i BYTES:\n\n", read_data);

	printf("right ascension %f\n", values[0]);
	printf("declination %f\n\n", values[1]);
	
	printf("right ascension %f\n", values[2]);
	printf("declination %f\n\n", values[3]);

	gaiaFree(values);

	return 0;
}

#ifdef __cplusplus
}
#endif//__cplusplus