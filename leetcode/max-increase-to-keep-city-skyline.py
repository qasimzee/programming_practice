#!/bin/python3
# https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row_max = []
        col_max = []
        for row in grid:
            row_max.append(max(row))
        old_sum = 0 
        for col in range(len(grid)):
            col_maximum = -math.inf
            for row in range(len(grid[0])):
                if grid[row][col] > col_maximum:
                    col_maximum = grid[row][col]
                old_sum += grid[row][col]
            col_max.append(col_maximum)
        new_sum = 0
        
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                new_sum += min([row_max[row], col_max[col]])
        return new_sum - old_sum
