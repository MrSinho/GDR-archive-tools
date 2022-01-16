#include "gaia_archive_tools/gaiaArchiveTools.h"
#include "csv-fast-reader/csv.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#ifdef _MSC_VER
#pragma warning (disable: 4996)
#endif//_MSC_VER

#define SOURCE_EXTENDED_ID_IDX          0
#define SOURCE_ID_IDX                   1
#define SOLUTION_ID_IDX                 2
#define RA_IDX                          3
#define DEC_IDX                         4
#define BARYCENTRIC_DISTANCE_IDX        5
#define PMRA_IDX                        6
#define PMDEC_IDX                       7
#define RADIAL_VELOCITY_IDX             8
#define MAG_G_IDX                       9
#define MAG_BP_IDX                      10
#define MAG_RP_IDX                      11
#define MAG_RVS_IDX                     12
#define V_I_IDX                         13
#define MEAN_ABSOLUTE_V_IDX             14
#define AG_IDX                          15
#define AV_IDX                          16
#define TEFF_IDX                        17
#define SPECTRAL_TYPE_IDX               18
#define LOGG_IDX                        19
#define FEH_IDX                         20
#define ALPHAFE_IDX                     21
#define MBOL_IDX                        22
#define AGE_IDX                         23
#define MASS_IDX                        24
#define RADIUS_IDX                      25
#define VSINI_IDX                       26
#define POPULATION_IDX                  27
#define HAS_PHOTOCENTER_MOTION_IDX      28
#define NC_IDX                          29
#define NT_IDX                          30
#define SEMIMAJOR_AXIS_IDX              31
#define ECCENTRICITY_IDX                32
#define INCLINATION_IDX                 33
#define LONGITUDE_ASCENDING_NODE_IDX    34
#define ORBIT_PERIOD_IDX                35
#define PERIASTRON_DATE_IDX             36
#define PERIASTRON_ARGUMENT_IDX         37
#define VARIABILITY_AMPLITUDE_IDX       38
#define VARIABILITY_TYPE_IDX			39
#define VARIABILITY_PERIOD_IDX          40
#define VARIABILITY_PHASE_IDX           41

#define GAIA_BODY_VARIABLES 42

#define GAIA_BODY_SIZE 186

void gaiaWriteByte(uint8_t val, uint32_t* p_offset, FILE* dst_stream) {
	uint8_t _val = val;
	fwrite(&_val, 1, 1, dst_stream);
	fseek(dst_stream, 0, SEEK_SET);
	(*p_offset)++;
	fseek(dst_stream, *p_offset, SEEK_SET);
}

void gaiaWriteBuffer(void* src, const uint32_t size, uint32_t* p_offset, FILE* dst_stream) {
	fwrite(src, 1, size, dst_stream);
	fseek(dst_stream, 0, SEEK_SET);
	(*p_offset) += size;
	fseek(dst_stream, *p_offset, SEEK_CUR);
}

void gaiaWriteLong(const uint64_t val, uint32_t* p_offset, FILE* dst_stream) {
	const uint64_t _val = val;
	gaiaWriteBuffer((void*)&_val, 8, p_offset, dst_stream);
}

void gaiaWriteDouble(const double val, uint32_t* p_offset, FILE* dst_stream) {
	const double _val = val;
	gaiaWriteBuffer((void*)&_val, 8, p_offset, dst_stream);
}

void gaiaWriteFloat(const float val, uint32_t* p_offset, FILE* dst_stream) {
	const float _val = val;
	gaiaWriteBuffer((void*)&_val, 4, p_offset, dst_stream);
}

void gaiaWriteBoolean(const char* src, uint32_t* p_offset, FILE* dst_stream) {
	if (strcmp(src, "True") == 0) {
		gaiaWriteByte(1, p_offset, dst_stream);
	}
	else {
		gaiaWriteByte(0, p_offset, dst_stream);
	}
}

void gaiaWriteInt(const uint32_t val, uint32_t* p_offset, FILE* dst_stream) {
	const uint32_t _val = val;
	gaiaWriteBuffer((void*)&_val, 4, p_offset, dst_stream);
}

void gaiaConvertCSV(const char* src_path, const char* dst_path, const uint32_t body_count) {
	assert(src_path != NULL && dst_path != NULL);

	FILE* dst_stream = fopen(dst_path, "wb");
	assert(dst_stream != NULL);

	uint32_t offset = 0;
	CsvHandle csv = CsvOpen(src_path);
	char* row = CsvReadNextRow(csv);
	for (uint32_t i = 0; row != NULL && i < body_count; i++) {
		row = CsvReadNextRow(csv);
		if (row != NULL) {
			for (uint32_t j = 0; j < GAIA_BODY_VARIABLES; j++) {
				const char* column = CsvReadNextCol(row, csv);
				if (column != NULL) {
					switch (j) {
					case SOURCE_EXTENDED_ID_IDX: 
						gaiaWriteBuffer((void*)column, 20, &offset, dst_stream); break;
					case SOURCE_ID_IDX:
						gaiaWriteLong((uint64_t)atol(column), &offset, dst_stream); break;
					case SOLUTION_ID_IDX:
						gaiaWriteLong((uint64_t)atol(column), &offset, dst_stream); break;
					case RA_IDX:
						gaiaWriteDouble((double)atof(column), &offset, dst_stream); break;
					case DEC_IDX:
						gaiaWriteDouble((double)atof(column), &offset, dst_stream); break;
					case BARYCENTRIC_DISTANCE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case PMRA_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case PMDEC_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case RADIAL_VELOCITY_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MAG_G_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MAG_BP_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MAG_RP_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MAG_RVS_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case V_I_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MEAN_ABSOLUTE_V_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case AG_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case AV_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case TEFF_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case LOGG_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case FEH_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case ALPHAFE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MBOL_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case AGE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case MASS_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case RADIUS_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case VSINI_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case POPULATION_IDX:
						gaiaWriteByte((uint8_t)atoi(column), &offset, dst_stream); break;
					case HAS_PHOTOCENTER_MOTION_IDX:
						gaiaWriteBoolean(column, &offset, dst_stream); break;
					case NC_IDX:
						gaiaWriteInt((uint32_t)atoi(column), &offset, dst_stream); break;
					case NT_IDX:
						gaiaWriteInt((uint32_t)atoi(column), &offset, dst_stream); break;
					case SEMIMAJOR_AXIS_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case ECCENTRICITY_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case INCLINATION_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case LONGITUDE_ASCENDING_NODE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case ORBIT_PERIOD_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case PERIASTRON_DATE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case PERIASTRON_ARGUMENT_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case VARIABILITY_AMPLITUDE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case VARIABILITY_PERIOD_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					case VARIABILITY_PHASE_IDX:
						gaiaWriteFloat((float)atof(column), &offset, dst_stream); break;
					}
				}
			}
		}
		fflush(dst_stream);
	}
	fclose(dst_stream);
}