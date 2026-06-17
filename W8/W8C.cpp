#include <iostream>
using namespace std;

int max(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}

int main(){
    int jam, pancake;
    cin >> jam >> pancake;

    if (jam > pancake || jam * 2 < pancake){
        cout << "Impossible";
        return 0;
    }

    int joy[jam + 1];
    for (int i = 1; i <= jam; i++){
        cin >> joy[i];
    }

    int dp[jam + 1][pancake + 1];
    for (int i = 0; i <= jam; i++){
        for (int j = 0; j <= pancake; j++){
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for (int j = 0; j <= jam; j++){
        for (int p = 0; p <= pancake; p++){
            if (dp[j][p] == -1){
                continue;
            }

            for (int t = 1; t <= jam - j; t++){
                
                // case we top the new tower with jam
                if (p + t <= pancake){
                    dp[j + t][p + t] = max(dp[j + t][p + t], dp[j][p] + joy[t]);
                }

                // case we top the new tower with pancake
                if (p + t + 1 <= pancake){
                    dp[j + t][p + t + 1] = max(dp[j + t][p + t + 1], dp[j][p] + joy[t]);
                }
            }
        }
    }

    cout << dp[jam][pancake];

    return 0;
}