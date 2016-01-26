//https://leetcode.com/problems/rectangle-area/
class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      int x1 = min(max(A, E), max(C, G));
      int x2 = max(min(A, E), min(C, G));

      int y1 = min(max(D, H), max(B, F));
      int y2 = max(min(D, H), min(B, F));
      int overlapped_area = 0;
      if (x2 > x1 && y2 > y1)
        overlapped_area = (x2 - x1) * (y2 - y1);

      return abs(D - B) * abs(C - A) + abs(H - F) * abs(G - E) - overlapped_area;
    }

};
