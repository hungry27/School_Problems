from cs50 import get_string

text = get_string('Text: ')
out = len(text)
wc = 0
lc = 0
sc = 0
for i in range (out):
    #count the letters
    if (ord(text[i]) >= 65 and ord(text[i]) <= 122):
        lc += 1
        
    #count the spaces and increment the words
    elif (ord(text[i]) == 32 and (ord(text[i - 1]) != 33 and ord(text[i - 1]) != 46 and ord(text[i - 1]) != 63)):
        wc += 1
        
    # counts the sentences by finding dots, exclamation marks and interrogatives
    elif (ord(text[i]) == 33 or ord(text[i]) == 46 or ord(text[i]) == 63):
        sc += 1
        wc += 1
    
L = lc*100/wc
S = sc*100/wc
# Coleman -Liau index is computed using the formula
index = round(0.0588*L -0.296*S - 15.8)
    
if(index<1):
    print('Before Grade 1')
elif(index >= 16):
    print('Grade 16+')
else:
    print('Grade' ,index)