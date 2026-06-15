#include <iostream>
#include <vector>
using namespace std;


void swap(int& val_1, int& val_2){
    val_1 = val_1 ^ val_2;
    val_2 = val_1 ^ val_2;
    val_1 = val_1 ^ val_2;
}


vector<vector<int>> permutations(const vector<int>& nums){
    vector<vector<int>> result;

    // Base case:
    if (nums.empty()){
        result.push_back({});
        return result;
    }

    for (int i = 0; i < nums.size(); i++){
        vector<int> remaining;
        for (int j = 0; j < nums.size(); j++){
            if (j != i){
                remaining.push_back(nums[j]);
            }
        }

        vector<vector<int>> subPerms = permutations(remaining);

        for (vector<int>& perm : subPerms){
            perm.insert(perm.begin(), nums[i]); // push_front
            result.push_back(perm);
        }
    }


    return result;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> relation;

    vector<int> friends;
    for (int i = 0; i < N; i++){
        friends.push_back(i);
    }

    for (int i = 0; i < N; i++){
        relation.push_back({});
        for (int j = 0; j < N; j++){
            relation[i].push_back(false);
        }
    }

    int temp1, temp2;
    for (int i = 0; i < M; i++){
        cin >> temp1 >> temp2;
        relation[temp1][temp2] = relation[temp2][temp1] = true;
    }

    bool possible;

    for(vector<int> perm : permutations(friends)){
        for (int i = 0; i < N - 1; i++){
            possible = true;
            if (!relation[perm[i]][perm[i + 1]]){
                possible = false;
                break;
            }
        }
        if (possible){
            for (int i : perm){
                cout << i << " ";
            }
            return 0;
        }
    }

    cout << "Impossible";

    return 0;
}