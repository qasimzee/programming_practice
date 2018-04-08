def troubleSort(integers_list):
  l1 = integers_list[0::2]
  l2 = integers_list[1::2]
  l1.sort()
  l2.sort()
  new_list = []
  for i in range(min(len(l1), len(l2))):
    new_list.append(l1[i])
    new_list.append(l2[i])
  if (len(l1) > len(l2)):
    new_list.append(l1[len(l1) - 1])
  for i in range(len(new_list) - 1):
   if new_list[i] > new_list[i + 1]:
     return i
  return "OK"


count = int(raw_input())
for i in range(count):  
  line1 = raw_input()
  integers_list = [int(x) for x in raw_input().split(" ")]
  print ("Case #{}: {}".format(i + 1, troubleSort(integers_list)))