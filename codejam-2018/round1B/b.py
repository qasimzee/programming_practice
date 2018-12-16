def find_max_signs(signs):
  for x in range(0, 10000):
    for y in range(0, 10000):
      
    

count = int(raw_input())
for i in range(count):  
  S = int(raw_input())
  signs = []
  for i in range(S):
    line = raw_input()
    signs.append(line.split(" "))
  ans = find_max_signs(signs)
  print ("CASE #{}: {} {}".format(i + 1, ans[0], ans[1]) )
