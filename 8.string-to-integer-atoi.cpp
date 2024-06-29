/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include<string>
#include <climits>

using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        static int i, head, tail, minus;
        static const string intMax = to_string(INT_MAX);
        static const string intMin = intMax.substr(0,intMax.size() - 1) + "8";
        i = 0;minus = 1;
        while(i < s.size()){
            if(s[i] == ' ') i++;
            else if(s[i] == '-' || s[i] == '+'){ 
                minus = (s[i] == '-') ? -1 : 1;
                i++;
                break;
                }
            else if(s[i] >= '0' && s[i] <= '9') break;
            else return 0;
        }

        while(i < s.size()){
            if(s[i] == '0') i++;
            else if(s[i] > '0' && s[i] <= '9') break;
            else return 0;
        }
        head = i;tail = i;

        for(; i < s.size() ; i++){
            if(s[i] < '0' || s[i] > '9'){
                break;
            }
        }

        tail = i;
        if(head >= tail) return 0;

        if(tail - head > 10){
            if(minus == 1) return stoi(intMax);
            else if(minus == -1) return stoi("-" + intMin);
        }
        if(tail - head == 10){
            if(minus == 1 && s.substr(head, tail - head) > intMax) return stoi(intMax);
            else if(minus == -1 && s.substr(head, tail - head) > intMin) return stoi("-" + intMin);
            else{
            if(minus == -1) return stoi("-" + s.substr(head, tail - head));
            else return stoi(s.substr(head, tail - head));
            }
        }
        if(minus == -1) return stoi("-" + s.substr(head, tail - head));
        else return stoi(s.substr(head, tail - head));
    }
};
// @lc code=end

