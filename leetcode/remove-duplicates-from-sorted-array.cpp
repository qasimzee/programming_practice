//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (nums.size() == 0) 
            return 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])  {
                nums.erase(nums.begin() + i);
                i--;
                len--;
            }
        }
        
        return len;
    }
};
