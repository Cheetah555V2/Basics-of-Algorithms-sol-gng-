#include <iostream>
using namespace std;

int min(int x, int y){
    if (x > y){
        return y;
    }
    return x;
}

int main(){
    int N;
    cin >> N;
    int dp[N + 1];
    dp[1] = 0;
    for (int i = 2; i < N + 1; i++){
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0){
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0){
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    cout << dp[N];
    return 0;
}