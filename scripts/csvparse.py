__all__ = ['parse_robolog', 'parse_latest']

import csv, os

def parse_robolog(filename):
    # Seperate the robot log into a list of dicts
    global linenum, ln, keyname
    print("Checking " + filename)
    reader = csv.DictReader(open(filename))
    names = reader.fieldnames
    # Initialize all the variables we're going to use
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
        #Remove extraneous values that we're not using
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
    return dol

def graph_robolog(dol, filename):
    import matplotlib.pyplot as plt
    times = dol['Elapsed Time']
    del dol['Elapsed Time']
    i=0
    keyrange = 0
    xlen = 1
    ylen = len(dol)
    for key in dol.keys():
        keyrange += 1
    for key in dol.keys():
        i += 1
        plt.subplot(ylen,xlen,i)
        plt.xlabel('Elapsed Time')
        plt.ylabel(key)
        plt.plot(times, dol[key])
    plt.savefig(filename)
    plt.clf()
    
def parse_latest():
    # The initial timestamp of all 0s
    # All timestamps are guaranteed to be greater than this!
    global max_foldername
    max_foldername = "00000000.00.00.00"
    for filename in os.listdir("C:\\FTP\\Logs"):
        # Find the latest files
        if filename > max_foldername:
            max_foldername = filename
    address = "C:\\FTP\\Logs\\" + max_foldername
    pngaddress = "C:\\FTP\\PNG\\" + max_foldername
    try:
        os.mkdir(pngaddress)
    except:
        print("Directory `" + pngaddress + "` already exists.")
        go = raw_input("Redraw graphs? (Y/N)\n==>")
        if go != "Y":
            return
    for filename in os.listdir(address):
        # Check each file in the latest folder
        # Attempt to graph each file
        try:
            lod = parse_robolog(address + "\\" + filename)
        except:
            diagnostics()
        data = lod2dol(lod)
        graph_robolog(data, pngaddress + "\\" + filename + ".png")
        lod = ()
        data = {}
        
def diagnostics():
    global linenum, ln, name
    # Error in the CSV
    print("\tError: invalid data on line " + str(linenum))
    print("\tIn file: " + str(max_foldername + '\\' + filename))
    print("\tWith key: " + keyname)
    print("\tLine contents:")
    print(ln)

if __name__ == "__main__":
    parse_latest()
