#include <iostream>
#include <vector>
using namespace std;


int sum(vector<int> arr){
    int sm = 0;
    for (int i = 0; i < arr.size(); i++){
        sm += arr[i];
    }
    return sm;
}



int main(){
    int N;
    cin >> N;

    vector<int> arr;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    int sm = sum(arr);

    if (sm % 2 != 0){
        cout << "NO";
        return 0;
    }


    // dp [consider up to i items] [can we get j sum?]
    bool dp[N + 1][sm / 2 + 1];
    
    for (int i = 0; i < N + 1; i++){
        dp[i][0] = true;
    }

    for (int i = 1; i < sm / 2 + 1; i++){
        dp[0][i] = false;
    }

    for (int i = 1; i < N + 1; i++){
        for(int j = 1; j < sm / 2 + 1; j++){
            dp[i][j] = dp[i-1][j];
            if (j - arr[i-1] >= 0){
                dp[i][j] = (dp[i][j] || dp[i-1][j-arr[i-1]]);
            }
        }
    }

    if (dp[N][sm / 2]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}