#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minStepsMemoization(int num, vector<int>& cache) {
    if (num == 1) return 0; 

    if (cache[num] != -1) return cache[num]; 

    int result = 1 + minStepsMemoization(num - 1, cache);

    if (num % 2 == 0)
        result = min(result, 1 + minStepsMemoization(num / 2, cache));

    if (num % 3 == 0)
        result = min(result, 1 + minStepsMemoization(num / 3, cache));

    cache[num] = result; 
    return result;
}

int minStepsBottomUp(int num) {
    vector<int> dp(num + 1, 0);  
    dp[1] = 0;  

    for (int i = 2; i <= num; i++) {
        dp[i] = dp[i - 1] + 1;  

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[num];
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    vector<int> cache(number + 1, -1);
    int stepsWithMemoization = minStepsMemoization(number, cache);
    cout << "\n[Memoization] Minimum steps to reduce " << number << " to 1: " << stepsWithMemoization << endl;

    int stepsWithBottomUp = minStepsBottomUp(number);
    cout << "[Bottom-Up DP] Minimum steps to reduce " << number << " to 1: " << stepsWithBottomUp << endl;

    cout << "\nNote: Both methods give the same result, but the Bottom-Up approach is more efficient for larger inputs.\n";
    return 0;
}
