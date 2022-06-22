import sys
import subprocess
import os



def main():
    if (len(sys.argv) == 2):
        subprocess.run(["./../bin/gaia-split", "../gaia-bin/", str(sys.argv[1])])
    elif (len(sys.argv) == 3):
        subprocess.run(["./../bin/gaia-split", "../gaia-bin/", str(sys.argv[1]), str(sys.argv[2])])


if __name__ == '__main__':
    main()