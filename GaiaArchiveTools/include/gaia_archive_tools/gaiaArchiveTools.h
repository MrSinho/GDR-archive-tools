#ifndef GAIA_ARCHIVE_TOOLS_H
#define GAIA_ARCHIVE_TOOLS_H

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
#pragma warning (disable: 4309)
#endif//_MSC_VER

typedef enum GaiaCelestialBodyFlags {
    GAIA_SOURCE_EXTENDED_ID = 0x00000000001,
    GAIA_SOURCE_ID = 0x00000000002,
    GAIA_SOLUTION_ID = 0x00000000004,
    GAIA_RA = 0x00000000008,
    GAIA_DEC = 0x00000000010,
    GAIA_BARYCENTRIC_DISTANCE = 0x00000000020,
    GAIA_PMRA = 0x00000000040,
    GAIA_PMDEC = 0x00000000080,
    GAIA_RADIAL_VELOCITY = 0x00000000100,
    GAIA_MAG_G = 0x00000000200,
    GAIA_MAG_BP = 0x00000000400,
    GAIA_MAG_RP = 0x00000000800,
    GAIA_MAG_RVS = 0x00000001000,
    GAIA_V_I = 0x00000002000,
    GAIA_MEAN_ABSOLUTE_V = 0x00000004000,
    GAIA_AG = 0x00000008000,
    GAIA_AV = 0x00000010000,
    GAIA_TEFF = 0x00000020000,
    GAIA_SPECTRAL_TYPE = 0x00000040000,
    GAIA_LOGG = 0x00000080000,
    GAIA_FEH = 0x00000100000,
    GAIA_ALPHAFE = 0x00000200000,
    GAIA_MBOL = 0x00000400000,
    GAIA_AGE = 0x00000800000,
    GAIA_MASS = 0x00001000000,
    GAIA_RADIUS = 0x00002000000,
    GAIA_VSINI = 0x00004000000,
    GAIA_POPULATION = 0x00008000000,
    GAIA_HAS_PHOTOCENTER_MOTION = 0x00010000000,
    GAIA_NC = 0x00020000000,
    GAIA_NT = 0x00040000000,
    GAIA_SEMIMAJOR_AXIS = 0x00080000000,
    GAIA_ECCENTRICITY = 0x00100000000,
    GAIA_INCLINATION = 0x00200000000,
    GAIA_LONGITUDE_ASCENDING_NODE = 0x00400000000,
    GAIA_ORBIT_PERIOD = 0x00800000000,
    GAIA_PERIASTRON_DATE = 0x01000000000,
    GAIA_PERIASTRON_ARGUMENT = 0x02000000000,
    GAIA_VARIABILITY_AMPLITUDE = 0x04000000000,
    GAIA_VARIABILITY_PERIOD = 0x08000000000,
    GAIA_VARIABILITY_PHASE = 0x10000000000,
    GAIA_FULL_BODY = UINT32_MAX
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

typedef struct _iobuf FILE;

extern void gaiaWriteByte(uint8_t val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteBuffer(void* src, const uint32_t size, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteLong(const uint64_t val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteDouble(const double val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteFloat(const float val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteBoolean(const char* src, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaWriteInt(const uint32_t val, uint32_t* p_offset, FILE* dst_stream);

extern void gaiaConvertCSV(const char* src_path, const char* dst_path, const uint32_t body_count);

extern void gaiaReadBinary(const char* src_path, const GaiaCelestialBodyFlags flags, const uint32_t offset, const uint32_t size, void* dst);

#endif//GAIA_ARCHIVE_TOOLS