#ifndef GAIA_ARCHIVE_TOOLS_H
#define GAIA_ARCHIVE_TOOLS_H

#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include <stdint.h>

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

#ifdef _MSC_VER
#pragma warning (disable: 4293)
#endif//_MSC_VER

typedef uint64_t GaiaCelestialBodyFlags;
#define GAIA_SOURCE_EXTENDED_ID (uint64_t)1 << 0
#define GAIA_SOURCE_ID (uint64_t)1 << 1
#define GAIA_SOLUTION_ID (uint64_t)1 << 2
#define GAIA_RA (uint64_t)1 << 3
#define GAIA_DEC (uint64_t)1 << 4
#define GAIA_BARYCENTRIC_DISTANCE (uint64_t)1 << 5
#define GAIA_PMRA (uint64_t)1 << 6
#define GAIA_PMDEC (uint64_t)1 << 7
#define GAIA_RADIAL_VELOCITY (uint64_t)1 << 8
#define GAIA_MAG_G (uint64_t)1 << 9
#define GAIA_MAG_BP (uint64_t)1 << 10
#define GAIA_MAG_RP (uint64_t)1 << 11
#define GAIA_MAG_RVS (uint64_t)1 << 12
#define GAIA_V_I (uint64_t)1 << 13
#define GAIA_MEAN_ABSOLUTE_V (uint64_t)1 << 14
#define GAIA_AG (uint64_t)1 << 15
#define GAIA_AV (uint64_t)1 << 16
#define GAIA_TEFF (uint64_t)1 << 17
#define GAIA_SPECTRAL_TYPE (uint64_t)1 << 18
#define GAIA_LOGG (uint64_t)1 << 19
#define GAIA_FEH (uint64_t)1 << 20
#define GAIA_ALPHAFE (uint64_t)1 << 21
#define GAIA_MBOL (uint64_t)1 << 22
#define GAIA_AGE (uint64_t)1 << 23
#define GAIA_MASS (uint64_t)1 << 24
#define GAIA_RADIUS (uint64_t)1 << 25
#define GAIA_VSINI (uint64_t)1 << 26
#define GAIA_POPULATION (uint64_t)1 << 27
#define GAIA_HAS_PHOTOCENTER_MOTION (uint64_t)1 << 28
#define GAIA_NC (uint64_t)1 << 29
#define GAIA_NT (uint64_t)1 << 30
#define GAIA_SEMIMAJOR_AXIS (uint64_t)1 << 31
#define GAIA_ECCENTRICITY (uint64_t)1 << 32
#define GAIA_INCLINATION (uint64_t)1 << 33
#define GAIA_LONGITUDE_ASCENDING_NODE (uint64_t)1 << 34
#define GAIA_ORBIT_PERIOD (uint64_t)1 << 35
#define GAIA_PERIASTRON_DATE (uint64_t)1 << 36
#define GAIA_PERIASTRON_ARGUMENT (uint64_t)1 << 37
#define GAIA_VARIABILITY_AMPLITUDE (uint64_t)1 << 38
#define GAIA_VARIABILITY_PERIOD (uint64_t)1 << 39
#define GAIA_VARIABILITY_PHASE (uint64_t)1 << 40
#define GAIA_FULL_BODY (uint64_t)UINT64_MAX

#ifndef GAIA_DOUBLE_PRECISION
    typedef float gaia_real;
#else
    typedef double gaia_real;
#endif//GAIA_DOUBLE_PRECISION

typedef struct GaiaCelestialBody {
    char        source_extended_id[20];
    uint64_t    source_id;
    uint64_t    solution_id;
    gaia_real   ra;
    gaia_real   dec;
    float       barycentric_distance;
    float       pmra;
    float       pmdec;
    float       radial_velocity;
    float       mag_g;
    float       mag_bp;
    float       mag_rp;
    float       mag_rvs;
    float       v_i;
    float       mean_absolute_v;
    float       ag;
    float       av;
    float       teff;
    float       logg;
    float       feh;
    float       alphafe;
    float       mbol;
    float       age;
    float       mass;
    float       radius;
    float       vsini;
    uint8_t     population;
    uint8_t     has_photocenter_motion;
    uint32_t    nc;
    uint32_t    nt;
    float       semimajor_axis;
    float       eccentricity;
    float       inclination;
    float       longitude_ascending_node;
    float       orbit_period;
    float       periastron_date;
    float       periastron_argument;
    float       variability_amplitude;
    float       variability_period;
    float       variability_phase;
} GaiaCelestialBody;

#define GAIA_CELESTIAL_BODY_MAX_SIZE 186


#define gaiaError(condition, error_msg, failure_expression)\
    if ((int)(condition)) {\
        printf("gaia-archive-tools error: %s\n", (const char*)error_msg);\
        failure_expression;\
    }\


extern uint8_t gaiaUniverseModelGetId(const uint32_t id, char* s_dst);

extern uint32_t gaiaGetBodySize(GaiaCelestialBodyFlags flags);

#include <stdio.h>

extern uint8_t gaiaWriteByte(uint8_t val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteBuffer(void* src, const uint32_t size, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteLong(const uint64_t val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteDouble(const double val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteFloat(const float val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteBoolean(const char* src, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteInt(const uint32_t val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaReadBuffer(void* p_dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src);

extern uint8_t gaiaExtractBuffer(void* p_src, const uint32_t src_buffer_size, const uint32_t offset, const GaiaCelestialBodyFlags flags, const uint32_t dst_size, void* p_dst);

#define gaiaReadByte(p_val, src_offset, p_dst_offset, p_src)\
	gaiaReadBuffer((void*)(p_val), 1, src_offset, p_dst_offset, p_src)

#define gaiaReadLong(p_val, src_offset, p_dst_offset, p_src)\
	gaiaReadBuffer((void*)(p_val), 8, src_offset, p_dst_offset, p_src)

#define gaiaReadDouble(p_val, src_offset, p_dst_offset, p_src)\
	gaiaReadBuffer((void*)(p_val), 8, src_offset, p_dst_offset, p_src)

#define gaiaReadFloat(p_val, src_offset, p_dst_offset, p_src)\
	gaiaReadBuffer((void*)(p_val), 4, src_offset, p_dst_offset, p_src)

#define gaiaReadInt(p_val, src_offset, p_dst_offset, p_src)\
    gaiaReadBuffer((void*)(p_val), 4, src_offset, p_dst_offset, p_src)

extern uint8_t gaiaReadReal(gaia_real* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src);

extern uint8_t gaiaConvertCSV(const char* src_path, const char* dst_path, const uint32_t body_count);

extern uint8_t gaiaReadBinaryFile(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, uint32_t* p_dst_size, void** pp_dst);

extern uint8_t gaiaReadBinaryFileFromID(const char* src_dir, const uint32_t src_id, const uint8_t half, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, uint32_t* p_dst_size, void** pp_dst);

#if 0
#include <curl/curl.h>
typedef struct CURL* gaiaWebHandle;

extern gaiaWebHandle gaiaWebSetup(const uint8_t debug);

#define gaiaWebShutdown(gaia_web_handle)\
    curl_easy_cleanup((CURL*)gaia_web_handle)
#endif//0
extern uint8_t gaiaReadWeb(const char* src_id, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, uint32_t* p_dst_size, void** pp_dst);

extern uint8_t gaiaSplit(const char* src_dir, const uint32_t src_id);

#define gaiaFree(p_buffer)\
    free(p_buffer)

#ifdef  __cplusplus
}
#endif//__cplusplus

#endif//GAIA_ARCHIVE_TOOLS