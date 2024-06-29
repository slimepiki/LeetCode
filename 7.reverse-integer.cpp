/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include<string>
#include <climits>
class Solution {
public:
    int reverse(int x) {
        static std::string str;
        static int div10intMax = INT_MAX / 10;
        static int div10;

        if(std::abs(x) < 10) return x;
        str = std::to_string(x);
        std::reverse(str.begin(), str.end());
        if(x < 0)std::rotate(str.rbegin(), str.rbegin() + 1, str.rend());
        div10 = std::stoi(str.substr(0, str.size() - 1));
        return (abs(div10) < div10intMax || (abs(div10) == div10intMax && int(str[str.size()-1] - '0') <= ((x < 0) ? 8 : 7))) 
        ? std::stoi(str) : 0;
    }
};
// @lc code=end

