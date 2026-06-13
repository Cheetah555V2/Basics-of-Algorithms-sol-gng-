#include <iostream>
using namespace std;

void merge(int arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[middle + i + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i++];
        }
        else{
            arr[k] = R[j++];
        }
        k++;
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int left, int right){
    if(left >= right){
        return;
    }

    int middle = (right - left) / 2 + left;
    mergesort(arr, left, middle);
    mergesort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

bool is_possible(int arr[],int num_student, int distance, int arr_size){
    int last_seat_pointer = 0;
    num_student--;
    for(int i = 1; i < arr_size; i++){
        if (arr[i] - arr[last_seat_pointer] >= distance){
            num_student--;
            last_seat_pointer = i;
        }
    }
    if (num_student <= 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n, student;
    cin >> n >> student;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    int left = 0, right = arr[n-1] - arr[0];
    int middle;
    while(left < right){
        middle = (left + right + 1) / 2;
        if (is_possible(arr, student, middle, n)){
            left = middle;
        }
        else{
            right = middle - 1;
        }
    }

    cout << left;

    return 0;
}