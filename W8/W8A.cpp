#include <iostream>
#include <vector>
using namespace std;


int max(int x, int y){
    return (x > y) ? x : y;
}


int main(){
    int W, N;
    cin >> W >> N;

    int weight[N + 1], cost[N + 1];

    for (int i = 1; i <= N; i++){
        cin >> weight[i];
    }

    for (int i = 1; i <= N; i++){
        cin >> cost[i];
    }


    int dp[W + 1][N + 1];
    dp[0][0] = 0;
    for (int i = 1; i < W + 1; i++){
        dp[i][0] = 0;
    }

    for (int i = 1; i < N + 1; i++){
        dp[0][i] = 0;
    }

    for (int w = 1; w < W + 1; w++){
        for (int n = 1; n < N + 1; n++){
            if (w - weight[n] < 0){
                dp[w][n] = dp[w][n - 1];
            }
            else{
                dp[w][n] = max(dp[w][n - 1], dp[w - weight[n]][n - 1] + cost[n]);
            }
        }
    }

    cout << dp[W][N] << "\n";

    vector<int> answer;

    while(dp[W][N]){
        if (dp[W][N] != dp[W][N - 1]){
            W -= weight[N];
            answer.push_back(N);
        }
        N--;
    }

    cout << answer.size() << "\n";

    for(int i : answer){
        cout << i << " ";
    }

    return 0;
}