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
}GaiaCelestialBodyFlags;

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

typedef struct _iobuf FILE;

extern void gaiaWriteByte(uint8_t val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteBuffer(void* src, const uint32_t size, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteLong(const uint64_t val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteDouble(const double val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteFloat(const float val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteBoolean(const char* src, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteInt(const uint32_t val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaStreamReadBuffer(void* p_dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream);

#define gaiaStreamReadByte(p_val, src_offset, p_dst_offset, src_stream)\
	gaiaStreamReadBuffer((void*)(p_val), 1, src_offset, p_dst_offset, src_stream)

#define gaiaStreamReadLong(p_val, src_offset, p_dst_offset, src_stream)\
	gaiaStreamReadBuffer((void*)(p_val), 8, src_offset, p_dst_offset, src_stream)

#define gaiaStreamReadDouble(p_val, src_offset, p_dst_offset, src_stream)\
	gaiaStreamReadBuffer((void*)(p_val), 8, src_offset, p_dst_offset, src_stream)

#define gaiaStreamReadFloat(p_val, src_offset, p_dst_offset, src_stream)\
	gaiaStreamReadBuffer((void*)(p_val), 4, src_offset, p_dst_offset, src_stream)

#define gaiaStreamReadInt(p_val, src_offset, p_dst_offset, src_stream)\
    gaiaStreamReadBuffer((void*)(p_val), 4, src_offset, p_dst_offset, src_stream)

extern void gaiaStreamReadReal(gaia_real* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, FILE* src_stream);

extern void gaiaReadBuffer(void* p_dst, const uint32_t size, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src);

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

extern void gaiaReadReal(gaia_real* p_val, const uint32_t src_offset, uint32_t* p_dst_offset, void* p_src);

extern void gaiaConvertCSV(const char* src_path, const char* dst_path, const uint32_t body_count);

extern void gaiaReadBinaryFile(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, void* p_dst);

extern void gaiaReadWeb(const char* src_id, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, void* p_dst, const uint8_t log_debug);

#ifdef  __cplusplus
}
#endif//__cplusplus

#endif//GAIA_ARCHIVE_TOOLS