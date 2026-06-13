#include <iostream>

using namespace std;

void merge(double arr[][3], int left, int middle, int right, int key_index, bool assending_order = true){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    double L[n1][3], R[n2][3];
    
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < 3; j++){
            L[i][j] = arr[left + i][j];
        }
    }

    for(int i = 0; i < n2; i++){
        for(int j = 0; j < 3; j++){
            R[i][j] = arr[middle + i + 1][j];
        }
    }

    int i = 0, j = 0;
    int k = left;
    
    while(i < n1 && j < n2){
        if(assending_order ? L[i][key_index] < R[j][key_index] : L[i][key_index] > R[j][key_index]){
            for(int l = 0; l < 3; l++){
                arr[k][l] = L[i][l];
            }
            i++;
        }
        else{
            for(int l = 0; l < 3; l++){
                arr[k][l] = R[j][l];
            }
            j++;
        }
        k++;
    }

    while(i < n1){
        for(int l = 0; l < 3; l++){
            arr[k][l] = L[i][l];
        }
        i++;
        k++;
    }

    while(j < n2){
        for(int l = 0; l < 3; l++){
            arr[k][l] = R[j][l];
        }
        j++;
        k++;
    }
}

void mergesort(double arr[][3], int left, int right, int key_index ,bool assending_order = true){
    if(left >= right){
        return;
    }
    
    long long middle = (right - left)/2 + left;
    
    mergesort(arr, left, middle, key_index, assending_order);
    mergesort(arr, middle + 1, right, key_index, assending_order);
    merge(arr, left, middle, right, key_index, assending_order);
}

int main(){
    long long n, bag_size;
    cin >> n >> bag_size;

    double arr[n][3];

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        if (arr[i][1] != 0){
            arr[i][2] = arr[i][0] / arr[i][1];
        }
        else{
            arr[i][2] = 2e9;
        }
    }

    mergesort(arr, 0, n-1, 2, false);

    long long sum = 0;
    
    for(int i = 0; i < n; i++){
        if (bag_size >= arr[i][1]){
            sum += arr[i][0];
            bag_size -= arr[i][1];
        }
        else{
            sum += (long long)(bag_size*arr[i][0] / arr[i][1]);
            break;
        }
    }

    cout << sum;
    return 0;
}