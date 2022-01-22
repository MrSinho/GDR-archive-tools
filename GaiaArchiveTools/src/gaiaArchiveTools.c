#include "gaia_archive_tools/gaiaArchiveTools.h"
#include "csv-fast-reader/csv.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#ifdef _MSC_VER
#pragma warning (disable: 4996)
#endif//_MSC_VER

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




void gaiaReadBuffer(void* dst, const uint32_t size, uint32_t* p_dst_offset, FILE* src_stream) {
	fread(dst, 1, size, src_stream);
	fseek(src_stream, 0, SEEK_SET);
	(*p_dst_offset) += size;
	fseek(src_stream, *p_dst_offset, SEEK_CUR);
}

void gaiaReadByte(uint8_t* p_val, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 1, p_dst_offset, src_stream);
}

void gaiaReadLong(uint64_t* p_val, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 8, p_dst_offset, src_stream);
}

void gaiaReadDouble(double* p_val, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 8, p_dst_offset, src_stream);
}

void gaiaReadFloat(float* p_val, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 4, p_dst_offset, src_stream);
}

void gaiaReadReal(gaia_real* p_val, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, sizeof(gaia_real), p_dst_offset, src_stream);
}

void gaiaReadInt(uint32_t* p_val, uint32_t* p_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 4, p_offset, src_stream);
}

void gaiaReadBinary(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, void* dst) {
	FILE* src_stream = fopen(src_path, "rb");
	assert(src_stream != NULL);

	uint32_t src_offset = offset;
	for (uint32_t dst_offset = 0; dst_offset < size;) {
		if (flags & SOURCE_EXTENDED_ID)			{ gaiaReadBuffer((void*)((char*)dst)[dst_offset], 20, &dst_offset, src_stream);  }
		src_offset += 20;
		if (flags & SOURCE_ID)					{ gaiaReadLong((uint64_t*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & SOLUTION_ID)				{ gaiaReadLong((uint64_t*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & RA)							{ gaiaReadReal((gaia_real*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & DEC)						{ gaiaReadReal((gaia_real*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & BARYCENTRIC_DISTANCE)		{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & PMRA)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & PMDEC)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & RADIAL_VELOCITY)			{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MAG_G)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MAG_BP)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MAG_RP)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MAG_RVS)					{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & V_I)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MEAN_ABSOLUTE_V)			{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & AG)							{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & AV)							{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & TEFF)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & LOGG)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & FEH)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & ALPHAFE)					{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MBOL)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & AGE)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & MASS)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & RADIUS)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & VSINI)						{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & POPULATION)					{ gaiaReadByte((uint8_t*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 1;
		if (flags & HAS_PHOTOCENTER_MOTION)		{ gaiaReadByte((uint8_t*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 1;
		if (flags & NC)							{ gaiaReadInt((uint32_t*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 4;
		if (flags & NT)							{ gaiaReadInt((uint32_t*)((char*)dst)[dst_offset], &dst_offset, src_stream);	 }
		src_offset += 4;
		if (flags & SEMIMAJOR_AXIS)				{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & ECCENTRICITY)				{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & INCLINATION)				{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & LONGITUDE_ASCENDING_NODE)	{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & ORBIT_PERIOD)				{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & PERIASTRON_DATE)			{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & PERIASTRON_ARGUMENT)		{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & VARIABILITY_AMPLITUDE)		{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & VARIABILITY_PERIOD)			{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & VARIABILITY_PHASE)			{ gaiaReadFloat((float*)((char*)dst)[dst_offset], &dst_offset, src_stream);		 }
	}

	fclose(src_stream);
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