
def find_cuts(board, H, V):
  rows = []
  columns = []
  for i in range(len(board)):
    count = 0
    for j in range(len(board[0])):
      if (board[i][j] == '@'):
        count = count + 1
    rows.append(count)
  for i in range(len(board[0])):
    count = 0
    for j in range(len(board)):
      if (board[j][i] == '@'):
        count = count + 1
    columns.append(count)
  if sum(rows[0: len(rows)]) % (H + 1) != 0 or sum(columns[0: len(columns)]) % (V + 1) != 0:
    return "IMPOSSIBLE"
  row_set_value = sum(rows[0: len(rows)]) / (H + 1)
  col_set_value = sum(columns[0: len(columns)]) / (V + 1)
  sum_rows = 0
  h_cut_count = 0
  row_cuts = []
  for i in range(len(rows)):
    sum_rows += rows[i]
    if sum_rows == row_set_value and h_cut_count < H:
      h_cut_count = h_cut_count + 1
      row_cuts.append(i)
      sum_rows = 0
  v_cut_count = 0
  sum_columns=0
  col_cuts = []
  for i in range(len(columns)):
    sum_columns += columns[i]
    if sum_columns == col_set_value and v_cut_count < V:
      v_cut_count = v_cut_count + 1
      sum_columns = 0
      col_cuts.append(i)
  print(col_cuts)
  print(row_cuts)
  
  if h_cut_count == H+1 and v_cut_count == V+1:
    return "POSSIBLE"
  return "IMPOSSIBLE"

count = int(raw_input())
for i in range(count):  
  line = raw_input()
  R = int(line.split(" ")[0])
  C = int(line.split(" ")[1])
  H = int(line.split(" ")[2])
  V = int(line.split(" ")[3])
  board = []
  for j in range(R):
    line = raw_input()
    board.append(list(line))
  print("CASE #{}: {}".format(i + 1, find_cuts(board, H, V)))



