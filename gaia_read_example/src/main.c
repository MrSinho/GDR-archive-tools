#include <gaia_archive_tools/gaiaArchiveTools.h>

#include <stdio.h>

int main(void) {

	gaiaWebHandle gaia = gaiaWebSetup(1);

	float values[4];
	gaiaReadWeb(gaia, "4001", GAIA_RA | GAIA_DEC, 0, 16, values);
	
	printf("\n\tREAD VALUES:\n\n");

	printf("right ascension %f\n", values[0]);
	printf("declination %f\n\n", values[1]);
	
	printf("right ascension %f\n", values[2]);
	printf("declination %f\n\n", values[3]);

	gaiaWebShutdown(gaia);

	return 0;
}