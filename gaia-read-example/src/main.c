#ifdef __cplusplus
extern "C" {
#endif//__cplusplus



#include <gaia-archive-tools/gaiaArchiveTools.h>

#include <stdio.h>
#include <stdlib.h>



void printData(const uint32_t read_data, float* p_values) {
	printf("\n\tREAD %i BYTES:\n\n", read_data);

	printf("right ascension %f\n", p_values[0]);
	printf("declination %f\n\n", p_values[1]);

	printf("right ascension %f\n", p_values[2]);
	printf("declination %f\n\n\n", p_values[3]);
}



int main(void) {

	uint32_t read_data = 0;
	
	char src_id[5];
	gaiaUniverseModelGetId(0, src_id); //"0025"
	printf("Reading ../gaia-bin/gaiaUniverseModel_%s.bin\n", src_id);

	float* values;

	{//READS FULL FILE
		gaiaReadBinaryFileFromID(
			"../gaia-bin",
			0,
			UINT8_MAX,
			GAIA_RA | GAIA_DEC,
			0,
			16, //if size is set to 0, the entire file will be read.
			&read_data,
			(void**)&values
		); //Reads ../gaia_resources/GaiaUniverseModel_0000.0.bin
	}
	printData(read_data, values);
    

	printf("Reading ../gaia-bin/gaiaUniverseModel_%s.0.bin\n", src_id);
	{//READS SPLITTED PART OF THE FILE
		gaiaReadBinaryFileFromID(
			"../gaia-bin",
			0,
			1,
			GAIA_RA | GAIA_DEC,
			0,
			16, //if size is set to 0, the entire file will be read.
			&read_data,
			(void**)&values
		); //Reads ../gaia_resources/GaiaUniverseModel_0000.1.bin
	}
	printData(read_data, values);
	

	gaiaFree(values);

	return 0;
}

#ifdef __cplusplus
}
#endif//__cplusplus