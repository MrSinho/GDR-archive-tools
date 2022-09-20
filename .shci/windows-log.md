
# gaia-archive-tools

![windows-badge](windows-exit_code.svg)

## [windows build logs:](https://github.com/mrsinho/shci)

        

Build ran for `1.33s`

---

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
cd gaia-archive-tools 
mkdir build
cd build
cmake .. -DGAIA_ARCHIVE_TOOLS_BUILD_EXAMPLES=ON 
cmake --build .
```

```bash

```

---

    

---

Build terminated with exit code 1

---

