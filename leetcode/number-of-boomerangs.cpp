//NOT ACCEPTED: https://leetcode.com/problems/number-of-boomerangs/
class Solution {
  public:
    double pointDistance(pair<int, int> p1, pair<int, int> p2) {
      return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
      int count = 0;
      for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
          for (int k = 0; k < points.size(); k++) {
            if (i != j && i != k && j != k) {
              double dis1 = pointDistance(points[i], points[j]);
              double dis2 = pointDistance(points[j], points[k]);
              count += (dis1 == dis2);
            }
          }
        }
      }
      return count;
    }
};
