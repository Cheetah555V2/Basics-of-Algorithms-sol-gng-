#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int x[N];
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    int S;
    cin >> S;

    int dp[S+10];
    dp[0] = 0;
    for (int i = 1; i <= S; i++){
        dp[i] = 1e7;
        for (int j : x){
            if (i - j < 0){
                continue;
            }
            dp[i] = min(dp[i-j] + 1, dp[i]);
        }
    }

    if (dp[S] < 1e7){
        cout << dp[S];
    }
    else{
        cout << -1;
    }
    return 0;
}