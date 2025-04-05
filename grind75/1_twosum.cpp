// 1. Two Sum
// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// bruteforce
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++)
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }       
        return {};
    }
};

// hashtable
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // default = 0;
        for(int i=0; i<nums.size(); i++){
            int complement = target-nums[i];
            if(map.count(complement)){
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution2* sol = new Solution2();
    vector<int> nums = {3,3};
    int target = 6;
    for(int con:sol->twoSum(nums, target))
        cout<<con<<" ";
    cout<<endl;
}