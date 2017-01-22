//https://leetcode.com/problems/number-of-boomerangs/
class Solution {
  public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
      int count = 0;
      for (int i = 0; i < points.size(); i++) {
        unordered_map<double, int> ctr(points.size());
        for (int j = 0; j < points.size(); j++) {
          count += 2 * ctr[hypot(points[i].first - points[j].first, points[i].second - points[j].second)]++;
        }
      }
      return count;
    }
};
