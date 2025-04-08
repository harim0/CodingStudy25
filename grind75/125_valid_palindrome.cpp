// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        vector<char> sentence;
        for(char c:s){
            if(65<=c&&c<=90){ 
                c+=32;
                sentence.push_back(c);
            }
            else if(97<=c&&c<=122) sentence.push_back(c);
            else if(48<=c&&c<=57) sentence.push_back(c);
        }
        int length = sentence.size();
        cout<<length<<endl;
        for(int i=0; i<length/2; i++){
            if(sentence[i]!=sentence[length-1-i]) return false;
        }
        return true;
    }
};

int main(){
    Solution* sol = new Solution();
    cout<<sol->isPalindrome("0P")<<endl;
}