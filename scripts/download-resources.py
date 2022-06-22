import sys
import requests
import shutil

def id_to_filename(i):
    filename_list = list(str(i))
    while (len(filename_list) < 4):
        filename_list.insert(0, 0)
    return "".join(str(v) for v in filename_list)

def download_universe_model_file(filename):
    for i in range (0, 2, 1):
        extension = "." + str(i) + ".bin"
        link = "https://github.com/mrsinho/gaia-resources/raw/main/" + "gaiaUniverseModel_" + filename + extension
        print(f"downloading {link}\n")
        buffer = requests.get(link)
        directory = "../gaia-resources/"
        open(directory+"gaiaUniverseModel_"+filename+extension, "wb").write(buffer.content)    

def main():
    range_start = 0
    range_end = 5000
    if (len(sys.argv) > 1):
        if (sys.argv[1].isnumeric()): 
            range_start = int(sys.argv[1])
            range_end   = int(sys.argv[1])+1
    if (len(sys.argv) > 2):
        if (sys.argv[2].isnumeric()): range_end = int(sys.argv[2])+1
    for i in range (range_start, range_end, 1):
        download_universe_model_file(id_to_filename(i));

if __name__ == '__main__':
    main()