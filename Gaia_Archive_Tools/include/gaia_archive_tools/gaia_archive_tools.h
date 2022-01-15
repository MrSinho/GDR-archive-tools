#ifndef GAIA_ARCHIVE_TOOLS_H
#define GAIA_ARCHIVE_TOOLS_H

#include <stdint.h>

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

#endif//GAIA_ARCHIVE_TOOLS