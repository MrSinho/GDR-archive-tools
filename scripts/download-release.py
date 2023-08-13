import sys
import requests
import os


def id_to_filename(i):
    filename_list = list(str(i))
    while (len(filename_list) < 4):
        filename_list.insert(0, 0)
    return "".join(str(v) for v in filename_list)

def download_gaia_catalogue(filename):
    extension = ".bin"
    filename = filename
    link = "https://github.com/MrSinho/gaia-resources/releases/download/v1.0.0-alpha/" + "gaiaUniverseModel_" + filename + extension
    print(f"downloading {link}\n")
    buffer = requests.get(link)
    directory = "../gaia-release/"
    path = directory+"gaiaUniverseModel_"+filename+extension
    print(f"path: {path}")
    file = open(path, "wb")
    file.write(buffer.content)
    file.close()

def download_catalogues(range_start, range_end):
    for i in range (range_start, range_end, 1):
        filename = id_to_filename(i)
        download_gaia_catalogue(filename)

#example call: python download-release.py 0
#example call: python download-release.py 0 5
def main():
    range_start = 0
    range_end = 5000
    if (len(sys.argv) > 1):
        if (sys.argv[1].isnumeric()): 
            range_start = int(sys.argv[1])
            range_end   = int(sys.argv[1])+1
    if (len(sys.argv) > 2):
        if (sys.argv[2].isnumeric()): range_end = int(sys.argv[2])+1
    download_catalogues(range_start, range_end)

if __name__ == '__main__':
    main()