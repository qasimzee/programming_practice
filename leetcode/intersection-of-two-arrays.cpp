//https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
  public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      set<int> retset;
      vector<int> retv;
      sort(nums2.begin(), nums2.end());
      for (int i = 0; i < nums1.size(); i++) {
        if (binary_search(nums2.begin(), nums2.end(), nums1[i]))
          retset.insert(nums1[i]);
      }
      for (auto it = retset.begin(); it != retset.end(); it++) {
        retv.push_back(*it);
      }
      return retv;
    }
};
