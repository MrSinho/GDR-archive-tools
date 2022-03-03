# ESA Gaia Archive Tools
<p float="left">
  <img src="https://www.cosmos.esa.int/documents/29201/0/Gaia_logo.png/62960d22-cdd9-02a2-c9d0-1bda19ab67cf?t=1607347628590" alt="drawing" width="170"/>
  <img src="https://www.gaudenzi.it/wp-content/uploads/2017/12/42_digital_logo_dark_blue_sign_A.png" alt="drawing" width="270"/> 
</p>

Documentation at https://mrsinho.github.io/docs/Gaia_Archive_Tools/index.html

Setup
* [Clone and build](#clone-and-build)
* [Download Universe Model Data](#download-universe-model-data)

Tutorial
* [Use CMake](#use-cmake)
* [Example](#example)
* [Gaia Universe Model Repository as Reference](#gaia-universe-model-repository-as-reference)
* [Useful Python Scripts](#useful-python-scripts)

---

# Setup

## Clone and Build

Open the terminal and run the following commands:
```bash
git clone --recursive https://github.com/MrSinho/Gaia_Archive_Tools.git
cd Gaia_Archive_Tools
mkdir build
cd build
cmake ..
cmake --build .
```

## Download Universe Model Data

Inside the cloned repository directory download the GEDR3 binaries by executing one of the scripts shown below: 
```bash
#For Linux devices
./download_resources.sh
#For Windows devices
./download_resources.bat
```

# Tutorial

## Use CMake

| CMake target                                           | type       |
|--------------------------------------------------------|------------|
| [gaia-archive-tools](../Gaia_Archive_Tools/index.md)   | library    |

## Example
```c
//Located at "repo-dir/gaia_read_example/src/main.c"
#include <gaia-archive-tools/gaiaArchiveTools.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float* values;
	uint32_t read_data = 0;

    //Downloads the file and reads the data
    //if size is set to 0, the entire file will be read.
    //char src_id[5];
    //gaiaUniverseModelGetId(25, src_id); //"0025"
    //gaiaReadWeb(src_id, GAIA_RA | GAIA_DEC, 0, 16, &read_data, &values); 

    //If you have already downloaded the binaries:
    //Reads ../gaia_resources/GaiaUniverseModel_0003.bin
    gaiaReadBinaryFileFromID("../gaia_resources", 3, GAIA_RA | GAIA_DEC, 0, 16, &read_data, &values); 

	printf("\n\tREAD %i BYTES:\n\n", read_data);

	printf("right ascension %f\n", values[0]);
	printf("declination %f\n\n", values[1]);
	
	printf("right ascension %f\n", values[2]);
	printf("declination %f\n\n", values[3]);

	gaiaFree(values);
	return 0;
}
```

## Gaia Universe Model repository as reference

The [Gaia_Universe_Model](../Gaia_Universe_Model/index.md) repository uses this library and the [SH-Engine](../SH-Engine/index.md) to render in a 3d environment millions of celestial bodies in real time. The program uses all the functionalities of this library.

## Useful Python Scripts

If you navigate in the scripts folder you'll find some python scripts:
```batch
 Directory: C:\GitHub\Gaia_Archive_Tools\scripts


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----        26/01/2022     20:26           1116 compress_catalogues.py
-a----        22/01/2022     21:53           1127 convert_catalogues.py
-a----        13/01/2022     17:37           1485 download_catalogues.py
-a----        15/01/2022     22:49              8 requirements.txt
```
To download the original CSV files directly from the Gaia Servers:
```bash 
python download_catalogues.py 0 #Download only file 0
python download_catalogues.py 0 4999 #Download all the files in the given range
```

If you want to convert the CSV files in a binary format, do:
```bash
python convert_catalogues.py 0 #Convert only file 0 
python convert_catalogues.py 0 4999 #Convert all the files in the given range 
```

In case you need to compress the binaries in a RAR file:
```bash
python compress_catalogues.py 0 #Compress only file 0 
python compress_catalogues.py 0 4999 #Compress all the files in the given range 
```
