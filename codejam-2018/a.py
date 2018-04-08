def calcScore(moves):
  strength = 1
  score = 0
  for move in moves:
    if (move == 'C'):
      strength = strength * 2
    else:
      score = score + strength
  return score

def find_moves(D, moves):
  hacks = 0
  score = calcScore(moves)

  while score > D:
    index = -1
    foundS = False
    count = len(moves) - 1
    for item in moves[::-1]:
      if item == 'S':
        foundS = True
      if foundS and item == 'C':
        index = count
        break
      count = count - 1
    if (index == -1):
      return "IMPOSSIBLE"
    temp = moves[index]
    moves[index] = moves[index + 1]
    moves[index + 1] = temp
    score = calcScore(moves)
    hacks = hacks + 1

  return hacks

count = int(raw_input())
for i in range(count):  
  line = raw_input()
  D = int(line.split(" ")[0])
  moves = line.split(" ")[1]
  print ("CASE #{}: {}".format(i + 1, find_moves(D, list(moves))))