import time
MAX_TIME=200
class SameColorPairs:
    
    def __init__(self):
        self.map_colors = {}
        self.H = 0
        self.W = 0
        self.time = 0
    def removeByRectangle(self, board, ret):
        if (time.time() - self.time > MAX_TIME):
            return
        local_time = time.time()
        self.map_colors = {}
        for i in range(self.H):
            for j in range(self.W):
                if board[i][j] != '.':
                    if not self.map_colors.get(board[i][j]):
                        self.map_colors[board[i][j]] = []
                    self.map_colors[board[i][j]].append((i, j))
        for key, val in self.map_colors.items():
            self.map_colors[key] = list(set(val))
        for color, single_colors_list in self.map_colors.items():
            for i in range(len(single_colors_list)):
                if board[single_colors_list[i][0]][single_colors_list[i][1]] != '.':
                    for j in range(i + 1, len(single_colors_list)):
                        if time.time() - self.time > MAX_TIME:
                            return

                        count = 0
                        if (single_colors_list[i][0] > -1 and 
                            single_colors_list[i][1] > -1 and 
                            single_colors_list[j][0] > -1 and 
                            single_colors_list[j][1] > -1
                        ):
                            for x in range(min(single_colors_list[i][0], single_colors_list[j][0]), max(single_colors_list[i][0], single_colors_list[j][0]) + 1):
                                for y in range(min(single_colors_list[i][1], single_colors_list[j][1]), max(single_colors_list[i][1], single_colors_list[j][1]) + 1):
                                    if board[x][y] != '.':
                                        count = count + 1
                        if (count == 2):
                            move = str(single_colors_list[i][0]) + " " + str(single_colors_list[i][1]) + " " + str(single_colors_list[j][0]) + " " + str(single_colors_list[j][1])
                            ret.append(move)                            
                            #print >> sys.stderr, move
                            board[single_colors_list[i][0]][single_colors_list[i][1]] = '.'
                            board[single_colors_list[j][0]][single_colors_list[j][1]] = '.'
                            self.map_colors[color][i] = single_colors_list[i] = (-1, -1)
                            self.map_colors[color][j] = single_colors_list[j] = (-1, -1)
                            #print >> sys.stderr, "{} {}".format(i, j)
                            break
                
    def removeBySkippingRows(self, board, ret):
        moves_found = False
        for i in range(self.H-1):
            for j in range(self.W):
                if board[i][j] != '.':
                    x = i + 1
                    while x < self.H and board[x][j] == '.':
                        x = x + 1
                    if x < self.H and board[x][j] == board[i][j]:
                        moves_found = True
                        ret.append(str(i) + " " + str(j) + " " + str(x) + " " + str(j))
                        board[x][j] = '.'
                        board[i][j] = '.'
    def removeBySkippingColumns(self, board, ret):
        moves_found = False
        for i in range(self.H):
            for j in range(self.W-1):
                if board[i][j] != '.':
                    x = j + 1
                    while x < self.W and board[i][x] == '.':
                        x = x + 1
                    if x < self.W and board[i][x] == board[i][j]:
                        moves_found = True
                        ret.append(str(i) + " " + str(x) + " " + str(i) + " " + str(j))
                        board[i][x] = '.'
                        board[i][j] = '.'
    def removePairs(self, board):
        self.time = time.time()
        self.H = len(board)
        self.W = len(board[0])
        ret = []
        for i in range(self.H):
          board[i] = list(board[i])
        
        max_moves = (len(board) * len(board[0]))/2
        moves_found = True

        for i in range(1):
            self.removeBySkippingRows(board, ret)
            self.removeBySkippingColumns(board, ret)
        for i in range(3):
            self.removeByRectangle(board, ret)
        for i in range(5):
            moves_found = self.removeBySkippingRows(board, ret)
            moves_found = moves_found or self.removeBySkippingColumns(board, ret)
        for i in range(5):
            self.removeByRectangle(board, ret)
        return ret

# -------8<------- end of solution submitted to the website -------8<-------

import sys
H = int(raw_input())
board = []
for i in range(H):
    board.append(raw_input())

scp = SameColorPairs()
ret = scp.removePairs(board)
print len(ret)
for st in ret:
    print st
sys.stdout.flush()
