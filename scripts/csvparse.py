import csv, os
def parse_robolog(filename):
    reader = csv.DictReader(open(filename))
    names = reader.fieldnames
    linelist = []
    for ln in reader:
        linelist.append(ln)
    for ln in linelist:
        for name in names:
            ln[name] = float(ln[name])
    for ln in linelist:
        pass

max_filename = "00000000.00.00.00"
for filename in os.listdir("C:\\FTP"):
#    parse_robolog("W:\\workspace\\test.csv")
    if filename > max_filename:
        max_filename = filename
print max_filename
