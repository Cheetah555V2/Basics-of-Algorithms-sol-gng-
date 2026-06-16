#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int min(int x, int y){
    return (x > y) ? y : x;
}


int main(){
    int n;
    cin >> n;
    vector<int> nails;
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        nails.push_back(tmp);
    }

    sort(nails.begin(), nails.end());

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 10e6;
    dp[2] = nails[1] - nails[0];
    dp[3] = nails[2] - nails[0];

    for (int i = 4; i < n + 1; i++){
        dp[i] = min(dp[i-2] + nails[i-1] - nails[i-2], dp[i-3] + nails[i-1] - nails[i-3]);
    }

    cout << dp[n];
    return 0;
}