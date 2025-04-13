// https://leetcode.com/problems/valid-anagram/description/
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        int total = 0;
        for(char c:s){
            hash[c]+=1;
            total+=1;
        }
        for(char c:t){
            if(!hash[c]||hash[c]==0) return false;
            hash[c]-=1;
            total-=1;
        }
        if(total!=0) return false;
        else return true;
    }
};

int main(){
    Solution* sol = new Solution();
    cout<<sol->isAnagram("atnagram", "nagaram")<<endl;
}