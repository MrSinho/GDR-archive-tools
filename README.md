# ESA Gaia Archive Tools

[![linux-status](.shci/linux/exit_code.svg)](.shci/linux/log.md)
[![windows-status](.shci/windows/exit_code.svg)](.shci/windows/log.md)

---

## License

Use of the Gaia data comes with the following license:
 
```
"The Gaia data are open and free to use, provided credit is given to 'ESA/Gaia/DPAC'. In general, access to, and use of, ESA's Gaia Archive (hereafter called 'the website') constitutes acceptance of the following general terms and conditions. Neither ESA nor any other party involved in creating, producing, or delivering the website shall be liable for any direct, incidental, consequential, indirect, or punitive damages arising out of user access to, or use of, the website. The website does not guarantee the accuracy of information provided by external sources and accepts no responsibility or liability for any consequences arising from the use of such data."
```

This repository is licensed under the GPL-3.0 license.

---

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


| CMake target                                           | type       |
|--------------------------------------------------------|------------|
| [gaia-archive-tools](./gaia-archive-tools/)            | library    |
| [gaia-exp](./gaia-archive-tools/src/gaia-exp.c)        | executable |
| [gaia-convert-sample](./samples/src/gaia-convert.c)    | executable |
| [gaia-read-sample](./samples/gaia-read.c)              | executable |

For any issues, see the [windows](.shci/windows/log.md) and [linux](.shci/linux/log.md) build logs.

---

## Before running: manually unzip example source data

Go to [gaia-bin](./gaia-bin) and unzip the files before running the offline sample [gaia-read.c](./samples/src/gaia-read.c) 

---

## Example

The [gaia-universe-model](https://github.com/mrsinho/gaia-universe-model) repository uses this library and the [shengine](https://github.com/mrsinho/shengine) API to render in a 3d environment hundreds of millions of celestial bodies in real time, with gradually more features being implemented.

## Useful Python Scripts

If you navigate in the scripts folder you'll find some python scripts:
```batch
cd scripts
dir
```

```batch
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
