# ESA Gaia Archive Tools
<p float="left">
  <img src="https://www.cosmos.esa.int/documents/29201/0/Gaia_logo.png/62960d22-cdd9-02a2-c9d0-1bda19ab67cf?t=1607347628590" alt="drawing" width="170"/>
  <img src="https://www.gaudenzi.it/wp-content/uploads/2017/12/42_digital_logo_dark_blue_sign_A.png" alt="drawing" width="270"/> 
</p>

## [About the mission](https://www.esa.int/Science-exploration/Space_Science/Gaia)

*Gaia will create an extraordinarily precise three-dimensional map of more than a thousand million stars throughout our Milky Way galaxy and beyond, mapping their motions, luminosity, temperature and composition. This huge stellar census will provide the data needed to tackle an enormous range of important questions related to the origin, structure and evolutionary history of our galaxy.*

Thanks to a billion pixel camera and after more than 7 years in space, the Gaia project has given us many details about the Universe, thanks to **`Gaia Data Release 1`**, **`Gaia Data Release 2`** and **`Gaia Early Data Release 3`**. 

In 2022 the **`Gaia Data Release 3`** is going to be be available to the public.

## [Gaia License](https://www.cosmos.esa.int/web/gaia-users/license)

*Use of the Gaia data comes with the following license:*

*"The Gaia data are open and free to use, provided credit is given to 'ESA/Gaia/DPAC'. In general, access to, and use of, ESA's Gaia Archive (hereafter called 'the website') constitutes acceptance of the following general terms and conditions. Neither ESA nor any other party involved in creating, producing, or delivering the website shall be liable for any direct, incidental, consequential, indirect, or punitive damages arising out of user access to, or use of, the website. The website does not guarantee the accuracy of information provided by external sources and accepts no responsibility or liability for any consequences arising from the use of such data."*

## About this repository

This unofficial repository collects the tools to pack the universe model csv files in a binary format. There is also a python scripts to download and unzip the resources. The original data can be found [here](http://cdn.gea.esac.esa.int/).

## [Implementation of the Gaia Archive Tools](https://github.com/MrSinho/Gaia_Universe_Model)
Coming soon...

## Download CSV files
To download the **`Gaia EDR 3`** [csv files](http://cdn.gea.esac.esa.int/Gaia/gedr3/simulation/gaia_universe_model/) run the `download_catalogues.py` script:
```bash
cd scripts
python -m pip install requests
python download_catalogues.py #download and extract all files
python download_catalogues.py 0 #download and extracts GaiaUniverseModel_0000.csv.gz
python download_catalogues.py 10 12 #download and extract GaiaUniverseModel_0010.csv.gz, GaiaUniverseModel_0011.csv.gz, GaiaUniverseModel_0012.csv.gz
```
The `csv` files will be found in `gaia_csv`.

## Usage of the archive converter:
To export an entire csv file in a binary format (first argument is the source path, second argument is the destination path):
```bash
cd bin
./gaia-exp ../gaia_csv/GaiaUniverseModel_0000.csv ../gaia_bin/GaiaUniverseModel_0000.bin
```
To export a certain number of celestial objects:
```bash
./gaia-exp ../gaia_csv/GaiaUniverseModel_0000.csv ../gaia_bin/GaiaUniverseModel_0000.bin 10 #export celestial objects from row 1 to 10
```
Using python:
```bash
cd scripts
python convert_catalogues.py 10 12 #convert GaiaUniverseModel_0010.csv.gz, GaiaUniverseModel_0011.csv.gz, GaiaUniverseModel_0012.csv.gz
```

## [Data types and celestial objects size](https://gaia.aip.de/metadata/gaiaedr3/gaia_universe_model/)
The structure that handles the data of a celestial object has a total size of `186` bytes. The meaning of each variable and the full [documentation](https://www.cosmos.esa.int/web/gaia-users/archive/gedr3-documentation) of the Gaia Archive can be found by checking the [official web page](https://www.cosmos.esa.int/web/gaia/home).
```c
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
```