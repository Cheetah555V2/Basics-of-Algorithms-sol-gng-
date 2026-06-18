#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


void swap(int& x, int& y){
    int tmp = x;
    x = y;
    y = tmp;
}


class MinHeap {
private:
    vector<long long> heap;

    vector<int> children(int i){ return {2 * i + 1, 2 * i + 2}; }

    int parant(int i){ return (i - 1) / 2; }

    void siftDown(int i){
        vector<int> c = children(i);
        int c1 = c[0], c2 = c[1];
        
        if (c1 >= heap.size()){
            return;
        }
        
        int c_min = c1;

        if (heap.size() > c2 && heap[c_min] > heap[c2]){
            c_min = c2;
        }

        if (heap[i] > heap[c_min]){
            swap(heap[i], heap[c_min]);
            siftDown(c_min);
        }
    }

    void siftUp(int i){
        if (i == 0) return;

        int p = parant(i);

        if (heap[i] < heap[p]){
            swap(heap[i], heap[p]);
            siftUp(p);
        }
    }

public:
    
    MinHeap(vector<long long>& value) : heap(value){
        for (int i = heap.size() / 2 - 1; i >= 0; i--){
            siftDown(i);
        }
    }

    void push(int x){
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    long long pop(int i=0){
        long long result = heap[i];
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
    long long x;
    vector<long long> arr;
    while(cin >> x){
        arr.push_back(x);
    }

    MinHeap heap(arr);

    long long total_cost = 0;

    while (heap.size() > 1){
        long long a = heap.pop();
        long long b = heap.pop();
        total_cost += a + b;
        heap.push(a + b);
    }

    cout << fixed << setprecision(10) << total_cost / 20.0;

    return 0;
}