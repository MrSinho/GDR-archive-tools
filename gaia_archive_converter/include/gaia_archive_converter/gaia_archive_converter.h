#ifndef GAIA_ARCHIVE_CONVERTER_H
#define GAIA_ARCHIVE_CONVERTER_H

#include <stdint.h>

typedef enum GaiaModelFlags {
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
    GAIA_MODEL_EXPORT_ALL       = UINT32_MAX
}GaiaModelFlags;

typedef struct GaiaCelestialBody {
    char        source_extended_id[20];
    uint64_t    source_id;
    uint64_t    solution_id;
    double      ra;
    double      dec;
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

extern void gaiaConvertCSV(const char* src_path, const char* dst_path, const uint32_t body_count);

#endif//GAIA_ARCHIVE_CONVERTER