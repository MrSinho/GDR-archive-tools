#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include "gaia_archive_tools/gaiaArchiveTools.h"
#include "csv-fast-reader/csv.h"

#ifdef _MSC_VER
#pragma warning (disable: 26451 4996 6386)
#endif//_MSC_VER
#if 0
#include <curl/curl.h>
#endif//0

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <assert.h>

uint32_t gaiaGetBodySize(GaiaCelestialBodyFlags flags) {
	uint32_t src_size = 0;
	if (flags & GAIA_SOURCE_EXTENDED_ID) { src_size += 20; }
	if (flags & GAIA_SOURCE_ID) { src_size += 8; }
	if (flags & GAIA_SOLUTION_ID) { src_size += 8; }
	if (flags & GAIA_RA) { src_size += 8; }
	if (flags & GAIA_DEC) { src_size += 8; }
	if (flags & GAIA_BARYCENTRIC_DISTANCE) { src_size += 4; }
	if (flags & GAIA_PMRA) { src_size += 4; }
	if (flags & GAIA_PMDEC) { src_size += 4; }
	if (flags & GAIA_RADIAL_VELOCITY) { src_size += 4; }
	if (flags & GAIA_MAG_G) { src_size += 4; }
	if (flags & GAIA_MAG_BP) { src_size += 4; }
	if (flags & GAIA_MAG_RP) { src_size += 4; }
	if (flags & GAIA_MAG_RVS) { src_size += 4; }
	if (flags & GAIA_V_I) { src_size += 4; }
	if (flags & GAIA_MEAN_ABSOLUTE_V) { src_size += 4; }
	if (flags & GAIA_AG) { src_size += 4; }
	if (flags & GAIA_AV) { src_size += 4; }
	if (flags & GAIA_TEFF) { src_size += 4; }
	if (flags & GAIA_LOGG) { src_size += 4; }
	if (flags & GAIA_FEH) { src_size += 4; }
	if (flags & GAIA_ALPHAFE) { src_size += 4; }
	if (flags & GAIA_MBOL) { src_size += 4; }
	if (flags & GAIA_AGE) { src_size += 4; }
	if (flags & GAIA_MASS) { src_size += 4; }
	if (flags & GAIA_RADIUS) { src_size += 4; }
	if (flags & GAIA_VSINI) { src_size += 4; }
	if (flags & GAIA_POPULATION) { src_size += 1; }
	if (flags & GAIA_HAS_PHOTOCENTER_MOTION) { src_size += 1; }
	if (flags & GAIA_NC) { src_size += 4; }
	if (flags & GAIA_NT) { src_size += 4; }
	if (flags & GAIA_SEMIMAJOR_AXIS) { src_size += 4; }
	if (flags & GAIA_ECCENTRICITY) { src_size += 4; }
	if (flags & GAIA_INCLINATION) { src_size += 4; }
	if (flags & GAIA_LONGITUDE_ASCENDING_NODE) { src_size += 4; }
	if (flags & GAIA_ORBIT_PERIOD) { src_size += 4; }
	if (flags & GAIA_PERIASTRON_DATE) { src_size += 4; }
	if (flags & GAIA_PERIASTRON_ARGUMENT) { src_size += 4; }
	if (flags & GAIA_VARIABILITY_AMPLITUDE) { src_size += 4; }
	if (flags & GAIA_VARIABILITY_PERIOD) { src_size += 4; }
	if (flags & GAIA_VARIABILITY_PHASE) { src_size += 4; }
	return src_size;
}

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


void gaiaStreamReadBuffer(void* p_dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
	fseek(src_stream, 0, SEEK_SET);
	fseek(src_stream, src_offset, SEEK_SET);
	fread(p_dst, 1, size, src_stream);
	(*p_dst_offset) += size;
}

void gaiaStreamReadReal(gaia_real* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream) {
#ifndef GAIA_DOUBLE_PRECISION
	fseek(src_stream, 0, SEEK_SET);
	fseek(src_stream, src_offset, SEEK_SET);
	double _val;
	fread((void*)&_val, 1, 8, src_stream);
	*p_val = (gaia_real)_val;
	(*p_dst_offset) += sizeof(gaia_real);
#else
	gaiaStreamReadBuffer((void*)p_val, sizeof(gaia_real), src_offset, p_dst_offset, src_stream);
#endif//GAIA_DOUBLE_PRECISION
}

void gaiaReadBuffer(void* p_dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src) {
	memcpy(p_dst, (void*)(&((char*)p_src)[src_offset]), size);
	(*p_dst_offset) += size;
}

void gaiaReadReal(gaia_real* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src) {
#ifndef GAIA_DOUBLE_PRECISION
	double _val;
	memcpy(&_val, (void*)(&((char*)p_src)[src_offset]), 8);
	*p_val = (gaia_real)_val;
	(*p_dst_offset) += sizeof(gaia_real);
#else
	gaiaStreamReadBuffer((void*)p_val, sizeof(gaia_real), src_offset, p_dst_offset, p_src);
#endif//GAIA_DOUBLE_PRECISION
}

void gaiaReadBinaryFile(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, void* p_dst) {
	FILE* src_stream = fopen(src_path, "rb");
	assert(src_path != NULL && p_dst != NULL && src_stream != NULL);

	uint32_t src_offset = offset;
	for (uint32_t dst_offset = 0; dst_offset < size;) {
		if (flags & GAIA_SOURCE_EXTENDED_ID)			{ gaiaStreamReadBuffer((void*)(&((char*)p_dst)[dst_offset]), 20, src_offset, &dst_offset, src_stream);  }
		src_offset += 20;
		if (flags & GAIA_SOURCE_ID)						{ gaiaStreamReadLong((uint64_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_SOLUTION_ID)					{ gaiaStreamReadLong((uint64_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_RA)							{ gaiaStreamReadReal((gaia_real*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_DEC)							{ gaiaStreamReadReal((gaia_real*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 8;
		if (flags & GAIA_BARYCENTRIC_DISTANCE)			{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PMRA)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PMDEC)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_RADIAL_VELOCITY)				{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_G)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_BP)						{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_RP)						{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MAG_RVS)						{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_V_I)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MEAN_ABSOLUTE_V)				{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_AG)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_AV)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_TEFF)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_LOGG)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_FEH)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_ALPHAFE)						{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MBOL)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_AGE)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_MASS)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_RADIUS)						{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VSINI)							{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_POPULATION)					{ gaiaStreamReadByte((uint8_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 1;
		if (flags & GAIA_HAS_PHOTOCENTER_MOTION)		{ gaiaStreamReadByte((uint8_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 1;
		if (flags & GAIA_NC)							{ gaiaStreamReadInt((uint32_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 4;
		if (flags & GAIA_NT)							{ gaiaStreamReadInt((uint32_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);	 }
		src_offset += 4;
		if (flags & GAIA_SEMIMAJOR_AXIS)				{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_ECCENTRICITY)					{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_INCLINATION)					{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_LONGITUDE_ASCENDING_NODE)		{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_ORBIT_PERIOD)					{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PERIASTRON_DATE)				{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_PERIASTRON_ARGUMENT)			{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VARIABILITY_AMPLITUDE)			{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VARIABILITY_PERIOD)			{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
		if (flags & GAIA_VARIABILITY_PHASE)				{ gaiaStreamReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, src_stream);		 }
		src_offset += 4;
	}

	fclose(src_stream);
}
#if 0
void gaiaCheckCurlResult(const CURLcode r, const char* msg) {
#ifndef NDEBUG
	(r != CURLE_OK) && printf("gaia archive tools error: curl failure, %s, %s\n", msg, curl_easy_strerror(r));
#endif//NDEBUG
	assert(r == CURLE_OK);
}
#endif//0
typedef struct curl_buffer_t {
    char* p_src;
    size_t size;
} curl_buffer_t;

size_t gaiaWebWriteCallback(char* p_src, size_t n_items, size_t item_size, void* p_dst_curl_buffer) {
	curl_buffer_t* p_curl_buffer = (curl_buffer_t*)p_dst_curl_buffer;
	size_t buffer_size = n_items * item_size;
	memcpy(&(((char*)p_curl_buffer->p_src)[p_curl_buffer->size]), p_src, buffer_size);
	p_curl_buffer->size += buffer_size;
	return buffer_size;
}
#if 0
gaiaWebHandle gaiaWebSetup(const uint8_t debug) {
	CURL* p_curl = curl_easy_init();
	gaiaCheckCurlResult(
		curl_easy_setopt(p_curl, CURLOPT_WRITEFUNCTION, gaiaWebWriteCallback),
		"cannot set download callback function"
	);
	(debug) && (curl_easy_setopt(p_curl, CURLOPT_VERBOSE, 1L));
	return (gaiaWebHandle)p_curl;
}
#endif 0
void gaiaReadWeb(const char* src_id, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, uint32_t* p_bytes_read, void* p_dst) {
	assert(p_bytes_read != NULL && p_dst != NULL);
	
	char cmd[256];
	system("rm GaiaUniverseModel_tmp.bin");
	strcpy(cmd, "wget https://github.com/MrSinho/GEDR3-binaries/blob/main/gedr3/GaiaUniverseModel_");
	strcat(cmd, src_id);
	strcat(cmd, ".0.bin");
	strcat(cmd, "?raw=true -O GaiaUniverseModel_tmp.bin");

	struct buffer_t {
		void* p_src;
	};

	struct buffer_t buffer = {
		calloc(1, 175000000)
	};
	assert(buffer.p_src != NULL);

	uint32_t dst_offset = 0;

	for (uint8_t i = 0; i < 2; i++) {
		
#if 0
		gaiaCheckCurlResult(
			curl_easy_setopt(p_curl, CURLOPT_URL, src_address),
			"cannot set url option"
		);

		curl_buffer_t buffer = { 0 };

		const uint32_t BUFFER_MAX_SIZE = 175000000;
		buffer.p_src = calloc(1, BUFFER_MAX_SIZE);
		assert(buffer.p_src != NULL);

		gaiaCheckCurlResult(
			curl_easy_setopt(p_curl, CURLOPT_WRITEDATA, (void*)&buffer),
			"cannot link to memory"
		);

		gaiaCheckCurlResult(
			curl_easy_perform(p_curl),
			"cannot perform curl handle"
		);
#endif//0
		assert(system(cmd) == 0);
	
		FILE* src_stream = fopen("GaiaUniverseModel_tmp.bin", "rb");
		fseek(src_stream, 0, SEEK_END);
		uint32_t stream_size = ftell(src_stream);
		fseek(src_stream, 0, SEEK_SET);

		fread(buffer.p_src, 1, stream_size, src_stream);

		*p_bytes_read = stream_size / (uint32_t)GAIA_CELESTIAL_BODY_MAX_SIZE * gaiaGetBodySize(flags);
		(size != 0) && (*p_bytes_read = size);

		uint32_t src_offset = offset;
		while (dst_offset < *p_bytes_read) {
			if (flags & GAIA_SOURCE_EXTENDED_ID) { gaiaReadBuffer((void*)(&((char*)p_dst)[dst_offset]), 20, src_offset, &dst_offset, buffer.p_src); }
			src_offset += 20;
			if (flags & GAIA_SOURCE_ID) { gaiaReadLong((uint64_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 8;
			if (flags & GAIA_SOLUTION_ID) { gaiaReadLong((uint64_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 8;
			if (flags & GAIA_RA) { gaiaReadReal((gaia_real*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 8;
			if (flags & GAIA_DEC) { gaiaReadReal((gaia_real*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 8;
			if (flags & GAIA_BARYCENTRIC_DISTANCE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_PMRA) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_PMDEC) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_RADIAL_VELOCITY) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MAG_G) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MAG_BP) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MAG_RP) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MAG_RVS) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_V_I) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MEAN_ABSOLUTE_V) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_AG) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_AV) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_TEFF) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_LOGG) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_FEH) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_ALPHAFE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MBOL) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_AGE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_MASS) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_RADIUS) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_VSINI) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_POPULATION) { gaiaReadByte((uint8_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 1;
			if (flags & GAIA_HAS_PHOTOCENTER_MOTION) { gaiaReadByte((uint8_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 1;
			if (flags & GAIA_NC) { gaiaReadInt((uint32_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_NT) { gaiaReadInt((uint32_t*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_SEMIMAJOR_AXIS) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_ECCENTRICITY) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_INCLINATION) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_LONGITUDE_ASCENDING_NODE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_ORBIT_PERIOD) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_PERIASTRON_DATE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_PERIASTRON_ARGUMENT) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_VARIABILITY_AMPLITUDE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_VARIABILITY_PERIOD) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;
			if (flags & GAIA_VARIABILITY_PHASE) { gaiaReadFloat((float*)(&((char*)p_dst)[dst_offset]), src_offset, &dst_offset, buffer.p_src); }
			src_offset += 4;

		}
		if (*p_bytes_read != 0 && *p_bytes_read >= size) {
			break;
		}

		fclose(src_stream);
		cmd[strlen(cmd) - 43] = '1';
	}
	free(buffer.p_src);
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

void gaiaSplit(const char* src_dir, const char* src_id) {
	assert(src_dir != NULL && src_id != NULL);

	char dst_0_path[256]; char dst_1_path[256];
	
	char src_path[256];
	strcpy(src_path, src_dir);
	strcat(src_path, "/GaiaUniverseModel_");
	strcat(src_path, src_id);

	strcpy(dst_0_path, src_path);
	strcpy(dst_1_path, src_path);

	strcat(src_path, ".bin");

	strcat(dst_0_path, ".0.bin");
	strcat(dst_1_path, ".1.bin");

	FILE* src_stream = fopen(src_path, "rb");
	
	fseek(src_stream, 0, SEEK_END);
	uint32_t dst_size_0, dst_size_1 = 0;
	{
		uint32_t dst_size = ((uint32_t)ftell(src_stream) / (uint32_t)GAIA_CELESTIAL_BODY_MAX_SIZE);
		if (dst_size % 2 == 1) {
			dst_size_0 = (dst_size - 1) / 2 * (uint32_t)GAIA_CELESTIAL_BODY_MAX_SIZE;
			dst_size_1 = (dst_size + 1) / 2 * (uint32_t)GAIA_CELESTIAL_BODY_MAX_SIZE;
		}
		else {
			dst_size_0 = dst_size / 2 * (uint32_t)GAIA_CELESTIAL_BODY_MAX_SIZE;
			dst_size_1 = dst_size / 2 * (uint32_t)GAIA_CELESTIAL_BODY_MAX_SIZE;
		}
	}
	
	fseek(src_stream, 0, SEEK_SET);

	FILE* dst_0_stream = fopen(dst_0_path, "wb");
	FILE* dst_1_stream = fopen(dst_1_path, "wb");
	void* dst_0_buffer = calloc(1, dst_size_0);
	void* dst_1_buffer = calloc(1, dst_size_1);
	assert(dst_0_buffer != NULL && dst_1_buffer != NULL);

	fread(dst_0_buffer, 1, dst_size_0, src_stream);
	fseek(src_stream, dst_size_0, SEEK_SET);
	fread(dst_1_buffer, 1, dst_size_1, src_stream);

	fwrite(dst_0_buffer, 1, dst_size_0, dst_0_stream);
	fwrite(dst_1_buffer, 1, dst_size_1, dst_1_stream);
	
	free(dst_0_buffer);
	free(dst_1_buffer);
	fclose(src_stream);
	fclose(dst_0_stream);
	fclose(dst_1_stream);
}

#ifdef  __cplusplus
}
#endif//__cplusplus