# ESA Gaia archive
<p float="left">
  <img src="https://www.cosmos.esa.int/documents/29201/0/Gaia_logo.png/62960d22-cdd9-02a2-c9d0-1bda19ab67cf?t=1607347628590" alt="drawing" width="170"/>
  <img src="https://www.gaudenzi.it/wp-content/uploads/2017/12/42_digital_logo_dark_blue_sign_A.png" alt="drawing" width="270"/> 
</p>

This unofficial repository collects the universe model csv files in a binary format. There is also a python scripts to download and unzip the resources. The original data can be found [here](http://cdn.gea.esac.esa.int/).

## Download CSV files
To download the [csv files](http://cdn.gea.esac.esa.int/Gaia/gedr3/simulation/gaia_universe_model/) run the `download_catalogues.py` script:
```bash
cd scripts
python -m pip install requests
python download_catalogues.py #downloads and extracts all files
python download_catalogues.py 0 #downloads and extracts GaiaUniverseModel_0000.csv.gz
python download_catalogues.py 10 12 #downloads and extracts GaiaUniverseModel_0010.csv.gz, GaiaUniverseModel_0011.csv.gz, GaiaUniverseModel_0012.csv.gz
```
The `csv` files will be found in `gaia_csv`.

## Usage of the archive converter:
To export an entire csv file in a binary format (first argument is the source path, second argument is the destination path):
```bash
cd bin
./gaia_exp ../gaia_csv/GaiaUniverseModel_0000.csv ../gaia_bin/GaiaUniverseModel_0000.csv.bin
```
To export a certain number of celestial objects:
```bash
./gaia_exp ../gaia_csv/GaiaUniverseModel_0000.csv ../gaia_bin/GaiaUniverseModel_0000.csv.bin 10 #export celestial objects from row 1 to 10
```
