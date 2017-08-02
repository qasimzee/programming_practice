#https://leetcode.com/problems/battleships-in-a-board/description/
class Solution(object):
    def countBattleships(self, board):
        battle = 0
        i = 0
        foundX = 0
        battleCount = 0
        while (i < len(board)):
            j = 0
            while (j < len(board[i])):
                if (board[i][j] == 'X'):
                    if (i == 0 and j == 0 or i > 0 and j == 0 and board[i-1][j] == '.' or j > 0 and i == 0 and board[i][j-1] == '.' or i > 0 and j > 0 and board[i-1][j] == '.' and board[i][j-1] == '.'):
                        board[i][j] = str(battle);
                        battleCount = battle + 1
                        battle = battle + 1
                    if (i > 0 and board[i-1][j] != '.'):
                        board[i][j] = board[i-1][j]
                    if (j > 0 and board[i][j - 1] != '.'):
                        board[i][j] = board[i][j - 1]
                j = j + 1
            i = i + 1
        return battleCount
