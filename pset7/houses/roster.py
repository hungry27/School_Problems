# TODO
from cs50 import SQL
from sys import argv, exit

if len(argv) != 2:
    print("incorrect conditions")
    exit (1)

db = SQL("sqlite:///students.db")

house = argv[1]
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
for row in rows:
    first, middle, last, house, birth = row["first"], row["middle"], row["last"], row["house"], row["birth"]
    print(f"{first}{middle if middle else ''} {last} born {birth}")