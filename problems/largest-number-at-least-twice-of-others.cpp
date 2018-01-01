/******************************************************************
* problem id : 748
* problem title : Largest Number At Least Twice of Others
* proble link : https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
******************************************************************/

/* using unordered_map, time complexity O(n), space complexity O(n) */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        unordered_map<int, int> mm;
        int size = nums.size();

        if(size==0)
            return -1;
        if(size==1)
            return 0;

        for(int i=0; i<size; i++)
            mm[nums[i]] = i;
        sort(nums.begin(), nums.end());
        if(nums[size-1]>=nums[size-2]*2)
            return mm[nums[size-1]];
        else
            return -1;
    }
};

/* time complexity O(n), space complexity O(1) */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1=0, max2=0, index=0;

        for(int i=0; i<nums.size(); i++) {
            if(max1<nums[i]) {
                max2 = max1;
                max1 = nums[i];
                index = i;
                continue;
            }
            if(max2<nums[i])
                max2 = nums[i];
        }

        return (max1>=2*max2) ? index : -1;
    }
};
