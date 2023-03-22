from cs50 import get_int




while True:
#### prompt and store height as integer 
 height = get_int("Enter height here: ")

 if 1 <= height <= 8:
   break
###### for loop to iterate height
for row in range(1, height + 1):
  print(' ' * (height - row) + '#' * row)


