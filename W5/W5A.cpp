#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : next(nullptr), prev(nullptr){
        data = val;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    // free memory let's goooooo
    ~DoublyLinkedList(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }

    int front(){
        return head->data;
    }

    int back(){
        return tail->data;
    }

    void add_front(int val){
        Node* newNode = new Node(val);
        if (!head){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void pop_back(){
        Node* temp = tail;
        if (head == tail){
            head = tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
    }

    int size() const {
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    int arr[n][4];
    DoublyLinkedList queue;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int i = 0; i < n; i++){
        int arriveal_time = 60 * arr[i][0] + arr[i][1];

        while((queue.size() != 0) && (arr[queue.back()][3] <= arriveal_time)){
            queue.pop_back();
        }

        if (arr[i][2] < queue.size()){
            arr[i][3] = arriveal_time;
            continue;
        }

        if (queue.size() == 0){
            arr[i][3] = arriveal_time + 20;
            queue.add_front(i);
            continue;
        }

        arr[i][3] = arr[queue.front()][3] + 20;
        queue.add_front(i);
    }

    for(int i = 0; i < n; i++){
        cout << arr[i][3] / 60 << " " << arr[i][3] % 60 << "\n";
    }

    return 0;
}