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

def graph_robolog(times, dol):
    import random
    import matplotlib.pyplot as plt
    for ls in dol:
        plt.plot(times, ls)

def parse_latest():
    # The initial timestamp of all 0s
    # All timestamps are guaranteed to be greater than this!
    global linenum, ln, name
    max_foldername = "00000000.00.00.00"
    for filename in os.listdir("C:\\FTP"):
        # Find the latest files
        if filename > max_foldername:
            max_foldername = filename
    max_foldername = "C:\\FTP\\" + max_foldername
    for filename in os.listdir(max_foldername):
        # Check each file in the latest folder
        try:
            l = parse_robolog(max_foldername + "\\" + filename)
            
        except:
            print("\tError: invalid data on line " + str(linenum))
            print("\tIn file: " + str(max_foldername + '\\' + filename))
            print("\tWith key: " + keyname)
            print("\tLine contents:")
            print(ln)

if __name__ == "__main__":
    parse_latest()
