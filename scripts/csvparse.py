import csv, os
def parse_robolog(filename):
    global linenum
    reader = csv.DictReader(open(filename))
    names = reader.fieldnames
    linelist = []
    listsize = 0
    linenum = 0
    for ln in reader:
        linelist.append(ln)
        listsize += 1
    for ln in linelist:
        linenum += 1
        for name in names:
            ln[name] = float(ln[name])
    for ln in linelist:
        pass
    return linelist

max_foldername = "00000000.00.00.00"
for filename in os.listdir("C:\\FTP"):
#    parse_robolog("W:\\workspace\\test.csv")
    if filename > max_foldername:
        max_foldername = filename
max_foldername = "C:\\FTP\\" + max_foldername
for filename in os.listdir(max_foldername):
    print("Checking " + max_foldername + '\\' + filename)
    parse_robolog(max_foldername+"\\"+filename)
