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




void gaiaReadBuffer(void* dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	fseek(src_stream, 0, SEEK_SET);
	fseek(src_stream, src_offset, SEEK_SET);
	fread(dst, 1, size, src_stream);
	(*p_dst_offset) += size;
}

void gaiaReadByte(uint8_t* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 1, src_offset, p_dst_offset, src_stream);
}

void gaiaReadLong(uint64_t* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 8, src_offset, p_dst_offset, src_stream);
}

void gaiaReadDouble(double* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 8, src_offset, p_dst_offset, src_stream);
}

void gaiaReadFloat(float* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 4, src_offset, p_dst_offset, src_stream);
}

void gaiaReadReal(gaia_real* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
#ifndef GAIA_DOUBLE_PRECISION
	fseek(src_stream, 0, SEEK_SET);
	fseek(src_stream, src_offset, SEEK_SET);
	double _val;
	fread((void*)&_val, 1, 8, src_stream);
	*p_val = (gaia_real)_val;
	(*p_dst_offset) += sizeof(gaia_real);
#else
	gaiaReadBuffer((void*)p_val, sizeof(gaia_real), src_offset, p_dst_offset, src_stream);
#endif//GAIA_DOUBLE_PRECISION
}

void gaiaReadInt(uint32_t* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	gaiaReadBuffer((void*)p_val, 4, src_offset, p_dst_offset, src_stream);
}

void gaiaReadBinary(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, void* dst) {
	FILE* src_stream = fopen(src_path, "rb");
	assert(src_stream != NULL);

	uint32_t src_offset = offset;
	for (uint32_t dst_offset = 0; dst_offset < size;) {
		if (flags & GAIA_SOURCE_EXTENDED_ID)			{ gaiaReadBuffer((void*)(&((char*)dst)[dst_offset]), 20, src_offset, &dst_offset, src_stream);  }
		src_offset += 20;
		if (flags & GAIA_SOURCE_ID)						{ gaiaReadLong((uint64_t*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_SOLUTION_ID)					{ gaiaReadLong((uint64_t*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_RA)							{ gaiaReadReal((gaia_real*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_DEC)							{ gaiaReadReal((gaia_real*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_BARYCENTRIC_DISTANCE)			{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PMRA)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PMDEC)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_RADIAL_VELOCITY)				{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_G)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_BP)						{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_RP)						{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_RVS)						{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_V_I)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MEAN_ABSOLUTE_V)				{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_AG)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_AV)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_TEFF)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_LOGG)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_FEH)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_ALPHAFE)						{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MBOL)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_AGE)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MASS)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_RADIUS)						{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VSINI)							{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_POPULATION)					{ gaiaReadByte((uint8_t*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 1;
		if (flags & GAIA_HAS_PHOTOCENTER_MOTION)		{ gaiaReadByte((uint8_t*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 1;
		if (flags & GAIA_NC)							{ gaiaReadInt((uint32_t*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 4;
		if (flags & GAIA_NT)							{ gaiaReadInt((uint32_t*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 4;
		if (flags & GAIA_SEMIMAJOR_AXIS)				{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_ECCENTRICITY)					{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_INCLINATION)					{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_LONGITUDE_ASCENDING_NODE)		{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_ORBIT_PERIOD)					{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PERIASTRON_DATE)				{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PERIASTRON_ARGUMENT)			{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VARIABILITY_AMPLITUDE)			{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VARIABILITY_PERIOD)			{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VARIABILITY_PHASE)				{ gaiaReadFloat((float*)(&((char*)dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
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