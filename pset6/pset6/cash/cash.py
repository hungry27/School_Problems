from cs50 import get_float

change = get_float('How much will you be paying\n');
coin = 0
while(change<0):
    change = get_float('How much will you be paing\n')
if(change == 0):
    print('0\n')
cent = round(change*100)
while(cent>= 25):
    cent = cent - 25
    coin += 1
while(cent>= 10):
    cent = cent -10
    coin += 1
while(cent>=5):
    cent = cent - 5
    coin += 1
while(cent >= 1):
    cent = cent - 1 
    coin += 1
print(coin)