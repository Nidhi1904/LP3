#include<iostream>
#include<vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem using memoization (top-down approach)
int solve(int index, int wt, vector<int>& value, vector<int>& weight, vector<vector<int>>& dp) {
    // Base case: If we are considering the first item
    if (index == 0) {
        // Check if the weight of the first item can be accommodated
        if (wt - weight[0] >= 0) {
            return value[0]; // Return value of the first item if weight allows
        } else {
            return 0; // Return 0 if weight doesn't allow inclusion of the first item
        }
    }

    // If the value for current index and weight is already calculated, return it from dp array
    if (dp[index][wt] != -1) {
        return dp[index][wt];
    }

    int nontake, take = INT_MIN;
    nontake = solve(index - 1, wt, value, weight, dp); // Don't include the current item

    // If weight allows, calculate maximum value including the current item
    if (wt - weight[index] >= 0) {
        take = value[index] + solve(index - 1, wt - weight[index], value, weight, dp);
    }

    // Store the maximum of including or excluding the current item in the dp array
    return dp[index][wt] = max(nontake, take);
}

int main() {
    int n, wt;
    cout << "Enter the number of items:\n";
    cin >> n;

    cout << "Enter the weight of the bag:\n";
    cin >> wt;

    vector<int> weight(n), value(n);

    // Input weights of the items
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    // Input values of the items
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // Initialize a DP array with -1 (to memorize subproblems)
    vector<vector<int>> dp(n, vector<int>(wt + 1, -1));

    // Calculate the maximum value that can be obtained
    int maxi = solve(n - 1, wt, value, weight, dp);
    cout << "Maximum value is: " << maxi;
    return 0;
}
