/***************************************************************
* problem id : 88
* problem title : Merget Sorted Array
* problem link : https://leetcode.com/problems/merge-sorted-array/description/
***************************************************************/

/* From the tail of nums1 to head */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end=m+n-1, i=m-1, j=n-1;

        while(i>=0 && j>=0) {
            if(nums1[i]>nums2[j]) {
                nums1[end] = nums1[i];
                i --;
            }
            else {
                nums1[end] = nums2[j];
                j --;
            }
            end --;
        }
        while(i>=0) {
            nums1[end] = nums1[i];
            i --;
            end --;
        }
        while(j>=0) {
            nums1[end] = nums2[j];
            j --;
            end --;
        }
    }
};
