#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <gaia_archive_tools/gaiaArchiveTools.h>

#include <stdio.h>

int main(void) {

	uint32_t read_data = 0;

	float values[4];
	gaiaReadWeb("0000", GAIA_RA | GAIA_DEC, 1, 0, 16, &read_data, values); //if offset is set to 0, the entire file will be read. 
	
	printf("\n\tREAD VALUES:\n\n");

	printf("right ascension %f\n", values[0]);
	printf("declination %f\n\n", values[1]);
	
	printf("right ascension %f\n", values[2]);
	printf("declination %f\n\n", values[3]);

	return 0;
}

#ifdef __cplusplus
}
#endif//__cplusplus