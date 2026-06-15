#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> arr){
    int sm = 0;
    for(int i : arr){
        sm += i;
    }
    return sm;
}


vector<vector<int>> subset(vector<int> arr){
    if (arr.empty()){
        return {};
    }


    // sorry, it works but I don't know how :(
    vector<vector<int>> result;

    int a = arr[arr.size() - 1];
    arr.pop_back();
    vector<vector<int>> sub = subset(arr);
    result.push_back({{a}});
    for(int i = 0; i < sub.size(); i++){
        vector<int> tmp = sub[i];
        result.push_back(tmp);
        tmp.push_back(a);
        result.push_back(tmp);
    }

    return result;
}


int main(){
    int target, N;
    cin >> target >> N;
    
    vector<int> blocks;
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        blocks.push_back(tmp);
    }

    vector<vector<int>> sub = subset(blocks);
    
    for(vector<int> i : sub){
        int sm = sum(i);
        if (sm == target){
            for(int j = 0; j < i.size(); j++){
                cout << i[j] << " ";
            }
            return 0;
        }
    }

    cout << "Impossible";

    return 0;
}