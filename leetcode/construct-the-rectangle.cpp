//https://leetcode.com/problems/construct-the-rectangle/
class Solution {
  public:
    vector<int> constructRectangle(int area) {
      int mindiff = area - 1;
      int leng = 1;
      int width = area;
      for (int i = 1; i*i <= area; i++) {
        if (area % i == 0) {
          int w = area / i;
          if (abs(i - w) < mindiff)
          {
            leng = i;
            width = w;
          }
        }
      }
      vector<int> v;
      v.push_back(width);v.push_back(leng);
      return v;
    }
};
