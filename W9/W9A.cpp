#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y){
    int tmp = x;
    x = y;
    y = tmp;
}


long long min(long long x, long long y){
    return (x > y) ? y : x;
}


bool priority(vector<long long> arr1, vector<long long> arr2){
    int length = min(arr1.size(), arr2.size());
    if (arr1[1] > arr2[1]){
        return true;
    }
    if (arr1[1] == arr2[1] && arr1[0] < arr2[0]){
        return true;
    }
    return false;
}


class MaxHeap {
private:
    vector<vector<long long>> heap;

    vector<int> children(int i){ return {2 * i + 1, 2 * i + 2}; }

    int parant(int i){ return (i - 1) / 2; }

    void siftDown(int i){
        vector<int> c = children(i);
        int c1 = c[0], c2 = c[1];
        
        if (c1 >= heap.size()){
            return;
        }
        
        int c_max = c1;

        if (heap.size() > c2 && priority(heap[c2], heap[c_max])){
            c_max = c2;
        }

        if (priority(heap[c_max],heap[i])){
            swap(heap[i], heap[c_max]);
            siftDown(c_max);
        }
    }

    void siftUp(int i){
        if (i == 0) return;

        int p = parant(i);

        if (priority(heap[i],heap[p])){
            swap(heap[i], heap[p]);
            siftUp(p);
        }
    }

public:
    
    MaxHeap(vector<vector<long long>>& value) : heap(value){
        for (int i = heap.size() / 2 - 1; i >= 0; i--){
            siftDown(i);
        }
    }

    void push(vector<long long> x){
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    vector<long long> pop(int i=0){
        vector<long long> result = heap[i];
        swap(heap[i], heap[heap.size() - 1]);
        heap.pop_back();
        siftUp(i);
        siftDown(i);
        return result;
    }

    int size(){
        return heap.size();
    }
};


int main(){
    int N;
    cin >> N;
    
    vector<vector<long long>> arr;
    MaxHeap heap(arr);

    char op;
    int tmp1, tmp2;

    while(N--){
        cin >> op;

        switch (op)
        {
            case '+':
                cin >> tmp1 >> tmp2;
                heap.push({tmp1, tmp2});
                break;
            
            case '-':
                cout << heap.pop()[0] << "\n";
        }
    }

    return 0;
}