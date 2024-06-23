/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<string>
#include <algorithm>
class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {
        static bool usedChar[0x80];
        static int i;
        static int j;
        static int ans;
        i = 0;
        j = 0;
        ans = 0;
        memset(usedChar, 0, sizeof(usedChar));

        while(j < s.length() && i + ans < s.length()){
            if(usedChar[(int)s[j]] == false){
                usedChar[(int)s[j]] = true;
                j++;
            }else{
                ans = std::max(ans, j - i);
                while(s[i] != s[j]){
                    usedChar[(int)s[i]] = false;    
                    i++;
                }
                if(i + 1 < j){
                    usedChar[(int)s[i]] = false;   
                    i++;
                }else{
                    while(s[i] == s[j] && j < s.length()){
                    usedChar[(int)s[i]] = false;
                    usedChar[(int)s[j]] = true;
                    i++;
                    j++;
                    }
                }
                usedChar[(int)s[i]] = true;
            }
        }
        ans = std::max(ans, j - i);
        return ans;
    }
};
// @lc code=end

