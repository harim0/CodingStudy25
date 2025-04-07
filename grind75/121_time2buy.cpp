// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int p:prices){
            min_price = min(min_price, p);   
            max_profit = max(max_profit, p - min_price);
        }
        return max_profit;
    }
};

int main(){
    Solution* sol = new Solution();
    vector v = {7,6,4,3,1};
    cout<<sol->maxProfit(v)<<endl;

    return 0;
}