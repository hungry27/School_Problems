from sys import argv, exit
import csv

def main():
    if len(argv) != 3:
        print ("usage: python dna.py data.csv sequence.txt")
        exit(1)
        
    csv_path = argv[1]
    with open(csv_path) as csv_file:
        reader = csv.reader(csv_file)
        all_sequences = next(reader)[1:]
        
        dnapath = argv[2]
        with open(dnapath) as txt_file:
            f = txt_file.read()
            actual = [max_iterations(f,seq) for seq in all_sequences]
        prinM (reader, actual)

def max_iterations(f, sub):
    ans = [0]*len(f)
    for i in range(len(f) - len(sub), -1, -1):
        if f[i: i + len(sub)] == sub:
            if i + len(sub) > len(f) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i +len(sub)]
    return max(ans)

def prinM(reader, actual):
    for line in reader:
        name = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(name)
            return
    print("No match")

        
if __name__ == "__main__":
    main()