#include <iostream>
#include <algorithm>
using namespace std;

int bsearch_l(int arr[], int key, int r){
    int l = -1;
    while(r - l > 1){
        int m = (l + r) / 2;
        if(arr[m] < key){
            l = m;
        }
        else{
            r = m;
        }
    }
    return r;
}

int bsearch_r(int arr[], int key, int r){
    int l = -1;
    while(r - l > 1){
        int m = (l + r) / 2;
        if(arr[m] <= key){
            l = m;
        }
        else{
            r = m;
        }
    }
    return r;
}

int main(){
    int n, m;
    cin >> n >> m;
    int score[n];
    for(int i = 0; i < n; i++){
        cin >> score[i];
    }

    sort(score, score + n);

    int left, right;
    int idx_l, idx_r;
    while(m--){
        cin >> left >> right;
        idx_l = bsearch_l(score, left, n);
        idx_r = bsearch_r(score, right, n);
        cout << idx_r - idx_l << "\n";
    }

    return 0;
}