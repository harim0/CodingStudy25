// 3502. Minimum Cost to Reach Every Position
// https://leetcode.com/contest/weekly-contest-443/problems/minimum-cost-to-reach-every-position/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int N = cost.size();
        vector<int> record;

        int front_idx = 0;
        for(int i=0; i<N; i++){
            if(cost[i]<=cost[front_idx]){
                for(int k=front_idx; k<i; k++)
                    record.push_back(cost[front_idx]);
                front_idx = i;
            }else if/*cost[i]>cost[front_idx]*/(front_idx<i && i==N-1){
                for(int k=front_idx; k<=i; k++)
                    record.push_back(cost[front_idx]);
            }
            
            if(front_idx==i &&i==N-1){
                record.push_back(cost[front_idx]);
            }
        }
        return record;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> v1 = {15,18,8,9,11,5,12,1,16,4,18,2};
    vector<int> v2 = {1,2,4,6,7};
    vector<int> v3 = {12,11};
    for(int content:sol->minCosts(v1))
        cout<<content<<" ";
    cout<<endl;
    for(int content:sol->minCosts(v2))
        cout<<content<<" ";
    cout<<endl;
    for(int content:sol->minCosts(v3))
        cout<<content<<" ";
    cout<<endl;
}