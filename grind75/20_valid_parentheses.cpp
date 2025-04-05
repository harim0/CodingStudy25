// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> record;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                record.push_back(s[i]);
            }else{
                if(record.empty()) // open 없이 close (초반)
                    return false;
                char top = record.back(); // open 없이 close (중간)
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '[')) {
                    return false;
                }
                record.pop_back();
            }  
        }
        return record.empty();
    }
};

int main(){
    Solution* sol = new Solution();
    // string s = "([)]"; // invalid
    string s = "([]";
    
    cout<<sol->isValid(s)<<endl;
}