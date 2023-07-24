
# gaia-universe-model

![linux-badge](exit_code.svg)

## [linux build logs:](https://github.com/mrsinho/shci)

```
system        : Linux
version       : #1 SMP Fri Jan 27 02:56:13 UTC 2023
platform      : Linux-5.15.90.1-microsoft-standard-WSL2-x86_64-with-glibc2.31
processor     : 
min frequency : 0.0 MHz
max frequency : 0.0 MHz
cores         : 4
```

build ran for `20.18 s` and terminated with exit code `0`

---

```bash
function PREREQUISITES {
    sudo apt -y update
    sudo apt install -y libvulkan-dev libvulkan1
    sudo apt install -y libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev
    sudo apt install -y libwayland-dev
    sudo apt install -y python3.9 python3-pip
    sudo apt install -y gcc cmake make libc6-dev
}

PREREQUISITES > .shci/linux/prerequisites-output.txt

```

```bash
Hit:1 http://deb.debian.org/debian bullseye InRelease
Get:2 http://deb.debian.org/debian bullseye-updates InRelease [44.1 kB]
Get:3 http://security.debian.org/debian-security bullseye-security InRelease [48.4 kB]
Get:4 http://ftp.debian.org/debian bullseye-backports InRelease [49.0 kB]
Get:5 http://security.debian.org/debian-security bullseye-security/main amd64 Packages [252 kB]
Get:6 http://security.debian.org/debian-security bullseye-security/main Translation-en [164 kB]
Get:7 http://ftp.debian.org/debian bullseye-backports/main amd64 Packages.diff/Index [63.3 kB]
Get:8 http://ftp.debian.org/debian bullseye-backports/main Translation-en.diff/Index [63.3 kB]
Get:9 http://ftp.debian.org/debian bullseye-backports/main amd64 Packages T-2023-07-18-1410.09-F-2023-07-18-0209.04.pdiff [20.1 kB]
Get:9 http://ftp.debian.org/debian bullseye-backports/main amd64 Packages T-2023-07-18-1410.09-F-2023-07-18-0209.04.pdiff [20.1 kB]
Get:10 http://ftp.debian.org/debian bullseye-backports/main Translation-en T-2023-07-18-2011.14-F-2023-07-18-0209.04.pdiff [5,503 B]
Get:10 http://ftp.debian.org/debian bullseye-backports/main Translation-en T-2023-07-18-2011.14-F-2023-07-18-0209.04.pdiff [5,503 B]
Fetched 710 kB in 1s (636 kB/s)
Reading package lists...
Building dependency tree...
Reading state information...
1 package can be upgraded. Run 'apt list --upgradable' to see it.
Reading package lists...
Building dependency tree...
Reading state information...
libvulkan-dev is already the newest version (1.2.162.0-1).
libvulkan1 is already the newest version (1.2.162.0-1).
0 upgraded, 0 newly installed, 0 to remove and 1 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
libxcursor-dev is already the newest version (1:1.2.0-2).
libxinerama-dev is already the newest version (2:1.1.4-2).
libxrandr-dev is already the newest version (2:1.5.1-1).
libx11-dev is already the newest version (2:1.7.2-1+deb11u1).
0 upgraded, 0 newly installed, 0 to remove and 1 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
libwayland-dev is already the newest version (1.18.0-2~exp1.1).
0 upgraded, 0 newly installed, 0 to remove and 1 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
python3-pip is already the newest version (20.3.4-4+deb11u1).
python3.9 is already the newest version (3.9.2-1).
0 upgraded, 0 newly installed, 0 to remove and 1 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
cmake is already the newest version (3.18.4-2+deb11u1).
gcc is already the newest version (4:10.2.1-1).
libc6-dev is already the newest version (2.31-13+deb11u6).
make is already the newest version (4.3-4.1).
0 upgraded, 0 newly installed, 0 to remove and 1 not upgraded.

```

---
    
```bash
function BUILD {
	mkdir linux-build
	cd linux-build
	cmake ..
	cmake --build .
}

BUILD > .shci/linux/build-output.txt

```

```bash
-- The C compiler identification is GNU 10.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/d/home/Desktop/Github/gaia-archive-tools/linux-build
Scanning dependencies of target gaia-archive-tools
[ 14%] Building C object CMakeFiles/gaia-archive-tools.dir/gaia-archive-tools/src/gaia-archive-tools.c.o
[ 28%] Building C object CMakeFiles/gaia-archive-tools.dir/external/csv-fast-reader/csv.c.o
[ 42%] Linking C static library ../bin/libgaia-archive-tools.a
[ 42%] Built target gaia-archive-tools
Scanning dependencies of target gaia-split
[ 57%] Building C object CMakeFiles/gaia-split.dir/gaia-split/src/gaia-split.c.o
[ 71%] Linking C executable ../bin/gaia-split
[ 71%] Built target gaia-split
Scanning dependencies of target gaia-exp
[ 85%] Building C object CMakeFiles/gaia-exp.dir/gaia-exp/src/gaia-exp.c.o
[100%] Linking C executable ../bin/gaia-exp
[100%] Built target gaia-exp

```

---
    
build ran for `20.18 s` and terminated with exit code `0`

---

