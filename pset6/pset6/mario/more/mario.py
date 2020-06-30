from cs50 import get_int 

height = get_int("How high would you like it to be?\n" )
while (height > 8 or height < 1):
    
    height = get_int ("please choose a number from 1 to 8?\n" )

for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * i, end="  ")
    print("#" * i)