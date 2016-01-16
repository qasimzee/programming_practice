//https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> v;
      v.push_back(1);
      for (int i = 1; i <= rowIndex; i++) {
        vector<int> newRow;
        newRow.push_back(1);
        for (int j = 0; j < v.size() - 1; j++) {
          newRow.push_back(v[j] + v[j + 1]);
        }
        newRow.push_back(1);
        v = newRow;
      }
      return v;
    }
};
