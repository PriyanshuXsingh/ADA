#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n; // number of cities
vector<vector<int>> dist; // distance matrix
vector<vector<int>> dp;   // memoization table

// tsp(mask, pos) - minimum cost to visit all cities starting from 'pos' with visited mask
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // return to starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;
    dist.assign(n, vector<int>(n));
    dp.assign(1 << n, vector<int>(n, -1));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int minCost = tsp(1, 0); // start from city 0, with only city 0 visited
    cout << "Minimum tour cost: " << minCost << endl;

    return 0;
}
