# ESA Gaia Archive Tools

[![linux-status](.shci/linux-exit_code.svg)](.shci/linux-log.md)
[![windows-status](.shci/windows-exit_code.svg)](.shci/window-log.md)

![](https://www.gaudenzi.it/wp-content/uploads/2017/12/42_digital_logo_dark_blue_sign_A.png)

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
git clone --recursive https://github.com/MrSinho/gaia-archive-tools.git
cd gaia-archive-tools
mkdir build
cd build
cmake .. #-DGAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES=ON
cmake --build .
```

## Manually unzip example source files

Go to [gaia-bin](gaia-bin) and unzip the files before running the offline sample [gaia-read.c](samples/src/gaia-read.c) 

## Download Universe Model Data (not required)

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
#include <gaia-archive-tools/gaiaArchiveTools.h>

#include <stdlib.h>
#include <stdio.h>

int main(void) {

  char src_id[5];
	void* p_bodies = NULL;
	uint32_t read_data = 0;

  gaiaUniverseModelGetId(1, src_id); //"0001"
	printf("Reading ../gaia-bin/gaiaUniverseModel_%s.bin\n", src_id);
		p_bodies = NULL;
	read_data = 0;

	GaiaCelestialBodyFlags read_flags = GAIA_RA | GAIA_DEC | AIA_PMRA | GAIA_PMDEC | GAIA_RADIAL_VELOCITY;

	gaiaReadBinaryFileFromID(
		"../gaia-bin",
		1,//0001
		read_flags,
		0,
		gaiaGetMaxBodySize(read_flags) * 2, //if size is set to 0, the entire file will be read.
		&read_data,
		&p_bodies
	); //Reads ../gaia_resources/GaiaUniverseModel_0001.bin

	if (p_bodies == NULL || read_data == 0) {
		return 0;
	}
	
	printData(read_data, p_bodies);
	gaiaFree(p_bodies);

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
