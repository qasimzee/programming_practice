def find_max_percentage(N, L, C):
  remaining_people = N - sum(C[0: len(C)])
  ans = 0
  if remaining_people == 0:
    for choice in C:
      percentage = 100 * (float(choice) / N)
      ans += (int(percentage) + 1) if (percentage - int(percentage)) >= 0.5 else 0
    return ans
  single_percent = (1.0 / N) * 100.0
  percentages = []
  for choice in C:
    cp = 100 * float(float(choice) / N)
    if cp - int(cp) >= 0.5:
      percentages.append(int(cp) + 1)
    else:
      percentages.append(int(cp))
  
  for i in range(remaining_people):
    C.append(0)
    percentages.append(0)

  for i in range(remaining_people + 1):
    index = 0
    for choice in C:
      p = 100.0 * (float(choice) / N)
      if (p - int(p) ) < 0.5:
        p = 100.0 * (float(choice + i) / N)
        if p - int(p) >= 0.5 and i <= remaining_people:
          C[index] += i
          remaining_people -= i
          new_p = 100 * (float(C[index]) / N)
          percentages[index] = int(new_p) + 1 if new_p - int(new_p) >= 0.5 else int(new_p)
        if (remaining_people == 0):
          return sum(percentages)
      index = index + 1
  
  return sum(percentages) + (int(single_percent)) * remaining_people
    

count = int(raw_input())
for i in range(count):  
  line = raw_input()
  N = int(line.split(" ")[0])
  L = line.split(" ")[1]
  C = raw_input().split(" ")
  for j in range(len(C)):  
    C[j] = int(C[j])
  print ("CASE #{}: {}".format(i + 1, find_max_percentage(N, L, C)) )
