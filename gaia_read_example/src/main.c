#include <gaia_archive_tools/gaiaArchiveTools.h>

#include <stdio.h>

int main(void) {

	float values[4];
	gaiaReadWeb("4001", GAIA_RA | GAIA_DEC, 0, 16, values, 1);
	
	printf("\n\tREAD VALUES:\n\n");

	printf("right ascension %f\n", values[0]);
	printf("declination %f\n\n", values[1]);
	
	printf("right ascension %f\n", values[2]);
	printf("declination %f\n\n", values[3]);

	return 0;
}