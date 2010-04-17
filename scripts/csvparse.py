__all__ = ['parse_robolog', 'parse_latest']

import csv, os

def parse_robolog(filename):
    global linenum, ln, keyname
    print("Checking " + filename)
    reader = csv.DictReader(open(filename))
    names = reader.fieldnames
    linelist = []
    listsize = 0
    linenum = 0
    keyname = ""
    ln = []
    for ln in reader:
        linelist.append(ln)
        listsize += 1
    for ln in linelist:
        linenum += 1
        for keyname in names:
            ln[keyname] = float(ln[keyname])
        del ln['Seconds']
        del ln['Nanoseconds']
    return linelist

def lod2dol(lod):
    '''
    Convert a list of dicts into a dict of lists
    '''
    dol = {}
    for key in lod[0]:
        dol[key] = list()
    for dictset in lod:
        for key in dictset:
            dol[key].append(dictset[key])
    timer = dol['Elapsed Time']
    del dol['Elapsed Time']
    return (timer, dol)

def randrgb():
    return "b-"

def graph_robolog(times, dol, filename):
    import matplotlib.pyplot as plt
    i=0
    keyrange = 0
    xlen = 2
    ylen = len(dol)
    if ylen % 2 == 1:
        ylen += 1
    ylen /= 2
    for key in dol.keys():
        keyrange += 1
    for key in dol.keys():
        i += 1
        plt.subplot(xlen,ylen,i)
        #plt.title(key)
        plt.xlabel('Elapsed Time')
        plt.ylabel(key)
        plt.plot(times, dol[key], randrgb())
    plt.savefig(filename)

def parse_latest():
    # The initial timestamp of all 0s
    # All timestamps are guaranteed to be greater than this!
    global linenum, ln, name
    max_foldername = "00000000.00.00.00"
    for filename in os.listdir("C:\\FTP\\Logs"):
        # Find the latest files
        if filename > max_foldername:
            max_foldername = filename
    address = "C:\\FTP\\Logs\\" + max_foldername
    pngaddress = "C:\\FTP\\PNG\\" + max_foldername
    os.mkdir(pngaddress)
    for filename in os.listdir(address):
        # Check each file in the latest folder
        try:
            lod = parse_robolog(address + "\\" + filename)
            (times, data) = lod2dol(lod)
            graph_robolog(times,data, pngaddress + "\\" + filename + ".png")
        except:
            print("\tError: invalid data on line " + str(linenum))
            print("\tIn file: " + str(max_foldername + '\\' + filename))
            print("\tWith key: " + keyname)
            print("\tLine contents:")
            print(ln)

if __name__ == "__main__":
    parse_latest()
