# TODO
from cs50 import SQL
from sys import argv, exit
import csv

def parse (Fname):
    names = Fname.split()
    return names if len(names) >= 3 else [names [0], None, names[1]]
    
db = SQL("sqlite:///students.db")
#def main():
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)
    
    
csv_path  = argv[1]
with open(csv_path) as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
      names =  parse(row["name"])
      db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", names[0], names[1], names[2], row["house"],  row["birth"])
     

#if __name__ == "__main__":
 #   main()
