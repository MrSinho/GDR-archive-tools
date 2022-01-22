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

typedef enum GaiaCelestialBodyFlags {
    SOURCE_EXTENDED_ID          = 0x00000001,
    SOURCE_ID                   = 0x00000002,
    SOLUTION_ID                 = 0x00000004,
    RA                          = 0x00000008,
    DEC                         = 0x00000010,
    BARYCENTRIC_DISTANCE        = 0x00000020,
    PMRA                        = 0x00000040,
    PMDEC                       = 0x00000080,
    RADIAL_VELOCITY             = 0x00000100,
    MAG_G                       = 0x00000200,
    MAG_BP                      = 0x00000400,
    MAG_RP                      = 0x00000800,
    MAG_RVS                     = 0x00001000,
    V_I                         = 0x00002000,
    MEAN_ABSOLUTE_V             = 0x00004000,
    AG                          = 0x00008000,
    AV                          = 0x00010000,
    TEFF                        = 0x02000000,
    SPECTRAL_TYPE               = 0x04000000,
    LOGG                        = 0x08000000,
    FEH                         = 0x00100000,
    ALPHAFE                     = 0x00080000,
    MBOL                        = 0x00200000,
    AGE                         = 0x00400000,
    MASS                        = 0x01000000,
    RADIUS                      = 0x00800000,
    VSINI                       = 0x00020000,
    POPULATION                  = 0x00040000,
    HAS_PHOTOCENTER_MOTION      = 0x00080000,
    NC                          = 0x00100000,
    NT                          = 0x00200000,
    SEMIMAJOR_AXIS              = 0x00400000,
    ECCENTRICITY                = 0x00800000,
    INCLINATION                 = 0x01000000,
    LONGITUDE_ASCENDING_NODE    = 0x02000000,
    ORBIT_PERIOD                = 0x04000000,
    PERIASTRON_DATE             = 0x08000000,
    PERIASTRON_ARGUMENT         = 0x10000000,
    VARIABILITY_AMPLITUDE       = 0x20000000,
    VARIABILITY_PERIOD          = 0x40000000,
    VARIABILITY_PHASE           = 0x80000000,
    GAIA_FULL_BODY              = UINT32_MAX
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