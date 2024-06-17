/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include <string>
#include <algorithm>
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x >= 0){
            std::string str = std::to_string(x);
            std::string revstr = str;
            std::reverse(revstr.begin(), revstr.end());
            return str == revstr;
        }else return false;
    }
};
// @lc code=end

