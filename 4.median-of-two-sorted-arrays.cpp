/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include<vector>;

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        static int num1itr, num2itr, size, evenMed, nums1size, nums2size;
        static double ans;
        num1itr = 0;
        num2itr = 0;

        nums1size = nums1.size();
        nums2size = nums2.size();

        if(nums1.empty()){
            if(nums2size % 2 == 0) return (nums2[nums2size / 2 - 1] + nums2[nums2size / 2]) / 2.0l;
            else return nums2[nums2size / 2];
        }else if(nums2.empty()){
            if(nums1size % 2 == 0) return (nums1[nums1size / 2 - 1] + nums1[nums1size / 2]) / 2.0l;
            else return nums1[nums1.size() / 2];
        }

        size = nums1size + nums2size;

        for(int i = 0; i < size / 2.0f - 1 ; i++){
            if(num2itr >= nums2size) num1itr++;
            else if(num1itr < nums1size && nums1[num1itr] <= nums2[num2itr]) num1itr++;
            else num2itr++;
        }
        if(num2itr >= nums2size){
            ans = nums1[num1itr];
            num1itr++;
        }
        else if(num1itr < nums1size && nums1[num1itr] <= nums2[num2itr]){
            ans = nums1[num1itr];
            num1itr++;
        }else{
            ans = nums2[num2itr];
            num2itr++;
        }

        if(size % 2 == 0){
            if(num2itr >= nums2size) evenMed = nums1[num1itr];
            else if(num1itr < nums1size && nums1[num1itr] <= nums2[num2itr]) evenMed = nums1[num1itr];
            else evenMed = nums2[num2itr];

            ans = (ans + evenMed) / 2.0l;
        }

        return ans;
    }
};
// @lc code=end

