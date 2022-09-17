
# gaia-archive-tools

![windows-badge](windows-status.svg)

## [windows build logs:](https://github.com/mrsinho/shci)

        
```bash
choco install -y curl mingw cmake
mingw-get install gcc mingw32-make gdb
```

```bash
Chocolatey v0.11.2
Installing the following packages:
curl;mingw;cmake
By installing, you accept licenses for the packages.
curl v7.80.0 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.
mingw v11.2.0.07112021 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.
cmake v3.22.0 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.

Chocolatey installed 0/3 packages. 
 See the log for details (C:\ProgramData\chocolatey\logs\chocolatey.log).

Warnings:
 - cmake - cmake v3.22.0 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.
 - curl - curl v7.80.0 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.
 - mingw - mingw v11.2.0.07112021 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.

```

---

    
```bash
cd gaia-archive-tools && mkdir build && cd build && cmake .. -DGAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES=ON && cmake --build .
```

```bash
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.21996.
-- The C compiler identification is MSVC 19.32.31332.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.32.31326/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/build
Microsoft (R) Build Engine version 17.2.1+52cd2da31 for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

  Checking Build System
  Building Custom Rule C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/CMakeLists.txt
  gaia-archive-tools.c
  csv.c
  Generating Code...
  gaia-archive-tools.vcxproj -> C:\Users\sino3\Desktop\shci-test\gaia-archive-tools\gaia-archive-tools\bin\Debug\gaia-archive-tools.lib
  Building Custom Rule C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/CMakeLists.txt
  gaia-convert.c
  gaia-convert-sample.vcxproj -> C:\Users\sino3\Desktop\shci-test\gaia-archive-tools\gaia-archive-tools\bin\Debug\gaia-convert-sample.exe
  Building Custom Rule C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/CMakeLists.txt
  gaia-exp.c
  gaia-archive-tools.c
  csv.c
  Generating Code...
  gaia-exp.vcxproj -> C:\Users\sino3\Desktop\shci-test\gaia-archive-tools\gaia-archive-tools\bin\Debug\gaia-exp.exe
  Building Custom Rule C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/CMakeLists.txt
  gaia-read.c
  gaia-read-sample.vcxproj -> C:\Users\sino3\Desktop\shci-test\gaia-archive-tools\gaia-archive-tools\bin\Debug\gaia-read-sample.exe
  Building Custom Rule C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/CMakeLists.txt
  gaia-split.c
  gaia-archive-tools.c
  csv.c
  Generating Code...
  gaia-split.vcxproj -> C:\Users\sino3\Desktop\shci-test\gaia-archive-tools\gaia-archive-tools\bin\Debug\gaia-split.exe
  Building Custom Rule C:/Users/sino3/Desktop/shci-test/gaia-archive-tools/gaia-archive-tools/CMakeLists.txt

```

---

    