#include <vector>
#include <iostream>
using namespace std;

int minCostRec(int n, vector<int>& height, vector<int>& dp) {

    if (n == 0)
        return 0;

    if (n == 1)
        return abs(height[n] - height[n - 1]);

    if (dp[n] != -1)
        return dp[n];

    dp[n] = min(
        minCostRec(n - 1, height, dp) + abs(height[n] - height[n - 1]),
        minCostRec(n - 2, height, dp) + abs(height[n] - height[n - 2])
    );

    return dp[n];
}

int minCost(vector<int>& height) {
    int n = height.size();

    vector<int> dp(n + 1, -1); 
    return minCostRec(n-1, height, dp);
}

int main() {
    vector<int> height = {20, 30, 40, 20};
    cout << minCost(height);
}
