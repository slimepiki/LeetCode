/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include<string>
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        static int ansLength;

        static int i, j, k;
        static int ansj;
        
        ansLength = 1;
        ansj = 0;


        if(s.size() <= 1) return s;

        for(i = 1;i < s.size(); i++){

            j = i;
            k = i;
            while(j >= 0 && k < s.size() && s[j] == s[k]){
                j--;k++;
            }
            j++;k--;

            if(k - j + 1 > ansLength){
                ansLength = k - j + 1;
                ansj = j;
            }

            j = i - 1;
            k = i;
            while(j >= 0 && k < s.size() && s[j] == s[k]){
                j--;k++;
            }
            j++;k--;

            if(k - j + 1 > ansLength){
                ansLength = k - j + 1;
                ansj = j;
            }
        }
        return s.substr(ansj, ansLength);
    }
};
// @lc code=end

