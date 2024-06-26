/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include<string>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        static std::string ans;
        ans.clear();
//        static int numRminus1;

//        numRminus1 = numRows - 1;

        if(numRows == 1) return s;

        for(int i = 0; i < numRows; i++){
            for(int j = i; j < s.size(); j += 2){
                if((j - i) % ((numRows - 1) * 2)== 0) ans += s[j];
                else if((j - i) % ((numRows - 1) * 2) == (((numRows - 1) - i) * 2)) ans += s[j];
            }
//            ans += "/n";
        }
        return ans;
    }
};
// @lc code=end

