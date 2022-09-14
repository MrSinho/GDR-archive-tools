#ifdef __cplusplus
extern "C" {
#endif//__cplusplus



#include <gaia-archive-tools/gaiaArchiveTools.h>

#include <stdlib.h>
#include <stdio.h>

void printWithSourceExtendedId(const uint32_t read_data, GaiaCelestialBodyFlags flags, void* p_bodies) {
	printf("\n\tREAD %i BYTES:\n\n", read_data);

	for (uint32_t i = 0; i < 2; i++) {
		char* p_body = &((char*)p_bodies)[i * gaiaGetBodySize(flags)];
		char* source_extended_id = p_body;
		
		float* p_values = (float*)(&p_body[GAIA_SOURCE_EXTENDED_ID_SIZE]);

		printf("source extended id: %s\n", source_extended_id);
		printf("right ascension: %f deg\n", p_values[0]);
		printf("declination: %f deg\n\n", p_values[1]);

	}
	
}

void printData(const uint32_t read_data, float* p_bodies) {
	printf("\n\tREAD %i BYTES:\n\n", read_data);

	for (uint32_t i = 0; i < 2; i++) {
		
		printf("right ascension: %f deg\n", p_bodies[5 * i + 0]);
		printf("declination: %f deg\n", p_bodies[5 * i + 1]);
		printf("pmra: %f mas\n", p_bodies[5 * i + 2]);
		printf("pmdec: %f mas\n", p_bodies[5 * i + 3]);
		printf("radial velocity: %f km/s\n\n", p_bodies[5 * i + 4]);
	}

}



int main(void) {
	
	char src_id[5];
	void* p_bodies = NULL;
	uint32_t read_data = 0;


	{//WITH SOURCE EXTENDED ID
		gaiaUniverseModelGetId(0, src_id); //"0001"
		printf("Reading ../gaia-bin/gaiaUniverseModel_%s.bin\n", src_id);

		GaiaCelestialBodyFlags read_flags = GAIA_SOURCE_EXTENDED_ID | GAIA_RA | GAIA_DEC;

		gaiaReadBinaryFileFromID(
			"../gaia-bin",
			0,//0000
			read_flags,
			0,
			gaiaGetBodySize(read_flags) * 2, //if size is set to 0, the entire file will be read.
			//0,
			&read_data,
			&p_bodies
		); //Reads ../gaia_resources/GaiaUniverseModel_0000.bin

		if (p_bodies == NULL || read_data == 0) {
			return 0;
		}

		printWithSourceExtendedId(read_data, read_flags, p_bodies);
		gaiaFree(p_bodies);
	}
	puts("\n\n\n");
	{//WITHOUT SOURCE EXTENDED ID
		gaiaUniverseModelGetId(1, src_id); //"0001"
		printf("Reading ../gaia-bin/gaiaUniverseModel_%s.bin\n", src_id);
	
		p_bodies = NULL;
		read_data = 0;

		GaiaCelestialBodyFlags read_flags = GAIA_RA | GAIA_DEC | GAIA_PMRA | GAIA_PMDEC | GAIA_RADIAL_VELOCITY;

		gaiaReadBodies(
			"../gaia-bin",
			1,//0001
			read_flags,
			1000,
			2,
			&read_data,
			&p_bodies
		); //Reads ../gaia_resources/GaiaUniverseModel_0001.bin

		if (p_bodies == NULL || read_data == 0) {
			return 0;
		}
		
		printData(read_data, p_bodies);
		gaiaFree(p_bodies);
	}//WITHOUT SOURCE EXTENDED ID

	return 0;
}

#ifdef __cplusplus
}
#endif//__cplusplus