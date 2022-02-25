#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <gaia_archive_tools/gaiaArchiveTools.h>

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	uint32_t read_data = 0;
	
	char src_id[7];
	gaiaUniverseModelGetId(25, 0, src_id); //"0025.0"

	float* values;
	gaiaReadWeb(src_id, GAIA_RA | GAIA_DEC, 0, 16, &read_data, &values); //if size is set to 0, the entire file will be read. 
	
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