#ifndef GAIA_ARCHIVE_TOOLS_H
#define GAIA_ARCHIVE_TOOLS_H

#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

#include <stdint.h>

typedef enum GaiaCelestialBodyPropertyIdx {
    SOURCE_EXTENDED_ID_IDX          = 0,
    SOURCE_ID_IDX                   = 1,
    SOLUTION_ID_IDX                 = 2,
    RA_IDX                          = 3,
    DEC_IDX                         = 4,
    BARYCENTRIC_DISTANCE_IDX        = 5,
    PMRA_IDX                        = 6,
    PMDEC_IDX                       = 7,
    RADIAL_VELOCITY_IDX             = 8,
    MAG_G_IDX                       = 9,
    MAG_BP_IDX                      = 10,
    MAG_RP_IDX                      = 11,
    MAG_RVS_IDX                     = 12,
    V_I_IDX                         = 13,
    MEAN_ABSOLUTE_V_IDX             = 14,
    AG_IDX                          = 15,
    AV_IDX                          = 16,
    TEFF_IDX                        = 17,
    SPECTRAL_TYPE_IDX               = 18,
    LOGG_IDX                        = 19,
    FEH_IDX                         = 20,
    ALPHAFE_IDX                     = 21,
    MBOL_IDX                        = 22,
    AGE_IDX                         = 23,
    MASS_IDX                        = 24,
    RADIUS_IDX                      = 25,
    VSINI_IDX                       = 26,
    POPULATION_IDX                  = 27,
    HAS_PHOTOCENTER_MOTION_IDX      = 28,
    NC_IDX                          = 29,
    NT_IDX                          = 30,
    SEMIMAJOR_AXIS_IDX              = 31,
    ECCENTRICITY_IDX                = 32,
    INCLINATION_IDX                 = 33,
    LONGITUDE_ASCENDING_NODE_IDX    = 34,
    ORBIT_PERIOD_IDX                = 35,
    PERIASTRON_DATE_IDX             = 36,
    PERIASTRON_ARGUMENT_IDX         = 37,
    VARIABILITY_AMPLITUDE_IDX       = 38,
    VARIABILITY_TYPE_IDX			= 39,
    VARIABILITY_PERIOD_IDX          = 40,
    VARIABILITY_PHASE_IDX           = 41
} GaiaCelestialBodyPropertyIdx;

#define GAIA_BODY_VARIABLES 42

#ifdef _MSC_VER
#pragma warning (disable: 4293)
#endif//_MSC_VER

typedef enum GaiaCelestialBodyFlags {
    GAIA_SOURCE_EXTENDED_ID = 1 << 0,
    GAIA_SOURCE_ID = 1 << 1,
    GAIA_SOLUTION_ID = 1 << 2,
    GAIA_RA = 1 << 3,
    GAIA_DEC = 1 << 4,
    GAIA_BARYCENTRIC_DISTANCE = 1 << 5,
    GAIA_PMRA = 1 << 6,
    GAIA_PMDEC = 1 << 7,
    GAIA_RADIAL_VELOCITY = 1 << 8,
    GAIA_MAG_G = 1 << 9,
    GAIA_MAG_BP = 1 << 10,
    GAIA_MAG_RP = 1 << 11,
    GAIA_MAG_RVS = 1 << 12,
    GAIA_V_I = 1 << 13,
    GAIA_MEAN_ABSOLUTE_V = 1 << 14,
    GAIA_AG = 1 << 15,
    GAIA_AV = 1 << 16,
    GAIA_TEFF = 1 << 17,
    GAIA_SPECTRAL_TYPE = 1 << 18,
    GAIA_LOGG = 1 << 19,
    GAIA_FEH = 1 << 20,
    GAIA_ALPHAFE = 1 << 21,
    GAIA_MBOL = 1 << 22,
    GAIA_AGE = 1 << 23,
    GAIA_MASS = 1 << 24,
    GAIA_RADIUS = 1 << 25,
    GAIA_VSINI = 1 << 26,
    GAIA_POPULATION = 1 << 27,
    GAIA_HAS_PHOTOCENTER_MOTION = 1 << 28,
    GAIA_NC = 1 << 29,
    GAIA_NT = 1 << 30,
    GAIA_SEMIMAJOR_AXIS = 1 << 31,
    GAIA_ECCENTRICITY = 1 << 32,
    GAIA_INCLINATION = 1 << 33,
    GAIA_LONGITUDE_ASCENDING_NODE = 1 << 34,
    GAIA_ORBIT_PERIOD = 1 << 35,
    GAIA_PERIASTRON_DATE = 1 << 36,
    GAIA_PERIASTRON_ARGUMENT = 1 << 37,
    GAIA_VARIABILITY_AMPLITUDE = 1 << 38,
    GAIA_VARIABILITY_PERIOD = 1 << 39,
    GAIA_VARIABILITY_PHASE = 1 << 40,
    GAIA_FULL_BODY = UINT64_MAX
} GaiaCelestialBodyFlags;

#ifndef GAIA_DOUBLE_PRECISION
    typedef float gaia_real;
#else
    typedef double gaia_real;
#endif//GAIA_DOUBLE_PRECISION

#define GAIA_SOURCE_EXTENDED_ID_SIZE 24
typedef struct GaiaCelestialBody {
    char        source_extended_id[GAIA_SOURCE_EXTENDED_ID_SIZE];
    uint64_t    source_id;
    uint64_t    solution_id;
    gaia_real   ra;
    gaia_real   dec;//56 bytes total
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
    float       vsini;//56 + 84 = 140 bytes total
    uint8_t     population;
    uint8_t     has_photocenter_motion;//142
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
    float       variability_phase;//142 + 48 = 190 bytes total
} GaiaCelestialBody;

#define GAIA_CELESTIAL_BODY_MAX_SIZE 190

#define GAIA_SRC_OFFSET(body_count) (GAIA_CELESTIAL_BODY_MAX_SIZE * (body_count))

#define gaiaError(condition, error_msg, failure_expression)\
    if ((int)(condition)) {\
        printf("gaia-archive-tools error: %s\n", (const char*)error_msg);\
        failure_expression;\
    }\


extern uint8_t gaiaUniverseModelGetId(const uint32_t id, char* s_dst);

extern uint32_t gaiaGetBodySize(GaiaCelestialBodyFlags flags);

extern uint8_t gaiaWriteByte(uint8_t val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteBuffer(void* src, const uint32_t size, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteLong(const uint64_t val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteDouble(const double val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteFloat(const float val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteBoolean(const char* src, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaWriteInt(const uint32_t val, uint32_t* p_dst_offset, void* p_dst);

extern uint8_t gaiaReadBuffer(void* p_dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src);

extern uint8_t gaiaExtractBuffer(void* p_src, const uint32_t src_buffer_size, const uint32_t offset, const GaiaCelestialBodyFlags flags, const uint32_t dst_size, void* p_dst);

#define gaiaCheckDestinationOffset(dst_offset, to_read, dst_size)\
    if (((dst_offset) + (to_read)) > (dst_size)) { dst_offset -= to_read; break; } 

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

extern void* gaiaProcessSourceExtendedId(char* p_bodies, const uint32_t body_idx, const GaiaCelestialBodyFlags flags, char* p_source_extended_id);

extern uint8_t gaiaConvertCSV(const char* src_path, const char* dst_path, const uint32_t body_count);

extern uint8_t gaiaReadBinaryFile(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t dst_size, uint32_t* p_dst_size, void** pp_dst);

extern uint8_t gaiaReadBinaryFileFromID(const char* src_dir, const uint32_t src_id, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, uint32_t* p_dst_size, void** pp_dst);

static uint8_t gaiaReadBodies(const char* src_dir, const uint32_t src_id, const GaiaCelestialBodyFlags flags, const uint32_t first_body, const uint32_t body_count, uint32_t* p_dst_size, void** pp_dst) {
    gaiaReadBinaryFileFromID(src_dir, src_id, flags, GAIA_SRC_OFFSET(first_body), gaiaGetBodySize(flags) * body_count, p_dst_size, pp_dst);
    return 1;
}

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