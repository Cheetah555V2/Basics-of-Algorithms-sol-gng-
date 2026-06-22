#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int start, int middle, int end){
    int n1 = middle - start + 1;
    int n2 = end - middle;

    vector<int> head(n1);
    vector<int> tail(n2);

    for (int i = 0; i < n1; i++){
        head[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++){
        tail[i] = arr[middle + i + 1];
    }

    int i, j, k = start;
    i = j = 0;

    while(i < n1 && j < n2){
        if(head[i] > tail[j]){
            arr[k++] = head[i++];
        }
        else{
            arr[k++] = tail[j++];
        }
    }

    while(i < n1){
        arr[k++] = head[i++];
    }

    while(j < n2){
        arr[k++] = tail[j++];
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    if (end <= start) return;

    int middle = (start + end) / 2;

    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);
    merge(arr, start, middle, end);
}


void gcd(int a, int b, vector<int>& arr){
    if (a == 0){
        arr.push_back(b);
        return;
    }
    arr.push_back(a);
    gcd(b % a, a, arr);
}


int main(){
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, N-1);

    vector<int> res;

    gcd(arr[0], arr[1], res);

    for (int i = 0; i < N; i++){
        if (arr[i] != res[i]){
            cout << -1;
            return 0;
        }
    }

    cout << arr[0] << " " << arr[1];
    
    return 0;
}