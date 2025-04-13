// https://leetcode.com/problems/binary-search/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start<end){
            int mid = (start+end)/2;
            if(nums[mid]<target) start = mid+1;
            else if(nums[mid]>target) end = mid-1;
            else return mid;
        }
        if(nums[start]!=target) return -1;
        else return start;
    }
};

int main(){
    Solution* sol = new Solution(); 
    vector<int> v = {-1,0,3,5,9,12};
    cout<<sol->search(v, 2)<<endl;
}