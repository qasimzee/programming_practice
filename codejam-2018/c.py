# Incorrect
def make_rectangle(A):
  
  board = [
    ['.' for i in range(1001)] 
    for j in range(1001)
  ]
  print("{} {}".format(2, 2))
  count = 3
  i = 1
  j = 1
  while i > 0 and j > 0:
    line = raw_input()
    i = int(line.split(' ')[0])
    j = int(line.split(' ')[1])
    
    print("2 {}".format(count % A))
    count = count + 1

count = int(raw_input())
for i in range(count):  
  A = int(raw_input())
  make_rectangle(A)


