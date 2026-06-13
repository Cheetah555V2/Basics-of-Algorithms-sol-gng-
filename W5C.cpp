#include <iostream>
#include <vector>
using namespace std;

class EyeQueue {
private:
    vector<int> queue;
public:
    EyeQueue(){}

    int size(){
        return queue.size();
    }

    void enqueue(int x){
        queue.push_back(x);
    }

    void midEnqueue(int x){
        if (size() == 0){
            enqueue(x);
            return;
        }
        int mid_idx = (size() % 2 == 0) ? (size() / 2) : (size() / 2 + 1);
        queue.insert(queue.begin() + mid_idx, x);
    }

    int dequeue(){
        int front = queue.front();
        queue.erase(queue.begin());
        return front;
    }

};

int main(){
    int n;
    cin >> n;
    EyeQueue q[n];

    char operation;
    int tmp1, tmp2;
    while(true){
        cin >> operation;
        switch (operation) {
            case '+':
                cin >> tmp1 >> tmp2;
                q[tmp1].enqueue(tmp2);
                break;
            case '-':
                cin >> tmp1;
                cout << q[tmp1].dequeue() << "\n";
                break;
            case '!':
                cin >> tmp1 >> tmp2;
                q[tmp1].midEnqueue(tmp2);
                break;
            case '?':
                cin >> tmp1;
                cout << q[tmp1].size() << "\n";
                break;
            case '#':
                return 0;
        }
    }

    return 0;
}