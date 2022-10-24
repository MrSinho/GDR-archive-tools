
# gaia-archive-tools

![linux-badge](linux-exit_code.svg)

## [linux build logs:](https://github.com/mrsinho/shci)

        

Build ran for `9.18s`

---

```bash
sudo apt install -y gcc cmake make gdb libc6-dev
```

```bash
Reading package lists...
Building dependency tree...
Reading state information...
cmake is already the newest version (3.18.4-2+deb11u1).
gcc is already the newest version (4:10.2.1-1).
gdb is already the newest version (10.1-1.7).
make is already the newest version (4.3-4.1).
libc6-dev is already the newest version (2.31-13+deb11u5).
0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.

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
-- The C compiler identification is GNU 10.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/c/Users/sino3/Desktop/shci-unix-test/gaia-archive-tools/gaia-archive-tools/build
Scanning dependencies of target gaia-split
[  6%] Building C object CMakeFiles/gaia-split.dir/gaia-archive-tools/src/gaia-split.c.o
[ 13%] Building C object CMakeFiles/gaia-split.dir/gaia-archive-tools/src/gaia-archive-tools.c.o
[ 20%] Building C object CMakeFiles/gaia-split.dir/external/csv-fast-reader/csv.c.o
[ 26%] Linking C executable ../bin/gaia-split
[ 26%] Built target gaia-split
Scanning dependencies of target gaia-archive-tools
[ 33%] Building C object CMakeFiles/gaia-archive-tools.dir/gaia-archive-tools/src/gaia-archive-tools.c.o
[ 40%] Building C object CMakeFiles/gaia-archive-tools.dir/external/csv-fast-reader/csv.c.o
[ 46%] Linking C static library ../bin/libgaia-archive-tools.a
[ 46%] Built target gaia-archive-tools
Scanning dependencies of target gaia-convert-sample
[ 53%] Building C object CMakeFiles/gaia-convert-sample.dir/samples/src/gaia-convert.c.o
[ 60%] Linking C executable ../bin/gaia-convert-sample
[ 60%] Built target gaia-convert-sample
Scanning dependencies of target gaia-read-sample
[ 66%] Building C object CMakeFiles/gaia-read-sample.dir/samples/src/gaia-read.c.o
[ 73%] Linking C executable ../bin/gaia-read-sample
[ 73%] Built target gaia-read-sample
Scanning dependencies of target gaia-exp
[ 80%] Building C object CMakeFiles/gaia-exp.dir/gaia-archive-tools/src/gaia-exp.c.o
[ 86%] Building C object CMakeFiles/gaia-exp.dir/gaia-archive-tools/src/gaia-archive-tools.c.o
[ 93%] Building C object CMakeFiles/gaia-exp.dir/external/csv-fast-reader/csv.c.o
[100%] Linking C executable ../bin/gaia-exp
[100%] Built target gaia-exp

```

---

    

Build terminated with exit code 0

---

