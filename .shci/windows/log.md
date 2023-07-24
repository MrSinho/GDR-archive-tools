
# gaia-universe-model

![windows-badge](exit_code.svg)

## [windows build logs:](https://github.com/mrsinho/shci)

```
system        : Windows
version       : 10.0.22621
platform      : Windows-10-10.0.22621-SP0
processor     : AMD64 Family 23 Model 17 Stepping 0, AuthenticAMD
min frequency : 0.0 MHz
max frequency : 3500.0 MHz
cores         : 4
```

build ran for `34.31 s` and terminated with exit code `0`

---

```bash
> .shci/windows/prerequisites-output.txt (
    choco install -y mingw cmake
    mingw-get install gcc mingw32-make gdb
)
```

```bash
Chocolatey v2.0.0
Chocolatey detected you are not running from an elevated command shell
 (cmd/powershell).

 You may experience errors - many functions/packages
 require admin rights. Only advanced users should run choco w/out an
 elevated shell. When you open the command shell, you should ensure
 that you do so with "Run as Administrator" selected. If you are
 attempting to use Chocolatey in a non-administrator setting, you
 must select a different location other than the default install
 location. See
 https://docs.chocolatey.org/en-us/choco/setup#non-administrative-install
 for details.

For the question below, you have 20 seconds to make a selection.

 Do you want to continue?([Y]es/[N]o): 
Timeout or your choice of '' is not a valid selection.
Installing the following packages:
mingw;cmake
By installing, you accept licenses for the packages.
mingw v12.2.0.03042023 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.
cmake v3.26.4 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.

Chocolatey installed 0/2 packages. 
 See the log for details (C:\ProgramData\chocolatey\logs\chocolatey.log).

Warnings:
 - cmake - cmake v3.26.4 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.
 - mingw - mingw v12.2.0.03042023 already installed.
 Use --force to reinstall, specify a version to install, or try upgrade.

Did you know the proceeds of Pro (and some proceeds from other
 licensed editions) go into bettering the community infrastructure?
 Your support ensures an active community, keeps Chocolatey tip-top,
 plus it nets you some awesome features!
 https://chocolatey.org/compare

```

---
    
```bash
> .shci/windows/build-output.txt (
    mkdir windows-build
    cd windows-build
    cmake .. -DGAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES=ON
    cmake --build .
)

```

```bash
-- Selecting Windows SDK version 10.0.22000.0 to target Windows 10.0.22621.
-- Configuring done (0.5s)
-- Generating done (0.5s)
-- Build files have been written to: D:/home/desktop/GitHub/gaia-archive-tools/windows-build
MSBuild version 17.6.3+07e294721 for .NET Framework

  gaia-archive-tools.c
  gaia-archive-tools.vcxproj -> D:\home\desktop\GitHub\gaia-archive-tools\bin\Debug\gaia-archive-tools.lib
  gaia-convert.c
  gaia-convert-sample.vcxproj -> D:\home\desktop\GitHub\gaia-archive-tools\bin\Debug\gaia-convert-sample.exe
  gaia-exp.c
  gaia-exp.vcxproj -> D:\home\desktop\GitHub\gaia-archive-tools\bin\Debug\gaia-exp.exe
  gaia-read.c
  gaia-read-sample.vcxproj -> D:\home\desktop\GitHub\gaia-archive-tools\bin\Debug\gaia-read-sample.exe
  gaia-split.c
  gaia-split.vcxproj -> D:\home\desktop\GitHub\gaia-archive-tools\bin\Debug\gaia-split.exe

```

---
    
build ran for `34.31 s` and terminated with exit code `0`

---

