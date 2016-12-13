//https://leetcode.com/problems/island-perimeter/
class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int area = 0;
      if (grid.size() == 0) return area;
      for (int i = 0; i < grid.size(); i++)
      {
        grid[i].push_back(0);
        grid[i].insert(grid[i].begin(), 0);
      }
      vector<int> v;
      for (int i = 0; i < grid[0].size(); i++)
      {
        v.push_back(0);
      }
      grid.push_back(v);
      grid.insert(grid.begin(), v);
      int x[] = {-1, 1, 0, 0};
      int y[] = {0, 0, 1, -1};
      for (int i = 1; i < grid.size() - 1; i++)
      {
        for (int j = 1; j < grid[0].size() - 1; j++)
        {
          if (grid[i][j] == 1) {
            for (int k = 0; k < 4; k++)
            {
              if (grid[i + x[k]][j + y[k]] == 0)
                area++;
            }
          }
        }
      }
      return area;
    }
};
