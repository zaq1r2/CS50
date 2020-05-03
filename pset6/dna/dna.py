from sys import argv, exit
import csv
from collections import defaultdict

def main():
    if len(argv) < 3 or len(argv) > 3:
        print("Wrong!!!!!")
        exit(1)
    

    with open(argv[1] , "r") as csv_file, open(argv[2], "r") as dna_file:
        csv_contents = csv.DictReader(csv_file)
        dna_contents = dna_file.read()
        short_tandem_repeats = csv_contents.fieldnames[1:]
        str_dict = {repeat : 0 for repeat in short_tandem_repeats}
        dna_length = len(dna_contents)
        for repeat in str_dict.keys():
            length = len(repeat)
            count = 0
            for i in range(dna_length - length):
                j = i + length 
                while dna_contents[i:j] == repeat:
                    count += 1
                    i += length
                    j += length
                    str_dict[repeat] = max(count, str_dict[repeat])
                else:
                    count = 0
        for row in csv_contents:
            match = True
            for repeat in str_dict.keys():
                if row[repeat] != str(str_dict[repeat]):
                    match = False
                    break
            if match == True:    
                print(row['name'])
                return
        
        print("No match")

main()





