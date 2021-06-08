#include<iostream>
#include<vector>
using namespace std;
//Time complexity: O(N), Space complexity: O(N)
void minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++)
        {
            //cout<<dp[i]<<endl;
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
            //cout<<dp[i]<<endl;
        }
        cout<< min(dp[cost.size()-2], dp[cost.size()-1]);
}
int main()
{
    vector<int>cost;
    cost.push_back(1);
    cost.push_back(100);
    cost.push_back(1);
    cost.push_back(1);
    cost.push_back(1);
    cost.push_back(100);
    cost.push_back(1);
    cost.push_back(1);
    cost.push_back(100);
    cost.push_back(1);
    minCostClimbingStairs(cost);
}
