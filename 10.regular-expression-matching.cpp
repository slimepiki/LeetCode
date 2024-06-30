/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include<string>
#include<stack>
#include<utility>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        //int is place
        stack<pair<pair<string, string>, int> > st;
        static pair<pair<string, string>, int> sp;
        static string ss, pp;
        static bool ans = false;
        static int place = 0;
        static int astPlace = 0;
        place = 0;
        ans = false;
        st.push(pair(pair(s, p), 0));
        while(!st.empty()){
            sp = st.top();st.pop();
            place = sp.second;
            ss = sp.first.first;
            pp = sp.first.second;

            while(place < 21){
                if(ss.size() == place && pp.size() == place){
                    ans = true;
                    break;
                }
                else if(ss.size() <= place || pp.size() <= place)break;
                else if(ss[place] == pp[place] || pp[place] == '.') place++;
                else if(pp[place] == '*'){
                    astPlace = place + 1;
                    if(astPlace == pp.size()){
                        ans = true;
                        break;
                    }
                    while(ss.size() <= place){
                        st.push(pair(pair(ss.substr(place), pp.substr(astPlace)), 0));
                        place++;
                    }
                }else break;
            }
            if(ans == true) break;
        }
        return ans;
    }
};
// @lc code=end

