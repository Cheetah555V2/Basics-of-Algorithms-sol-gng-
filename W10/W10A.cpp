#include <iostream>
#include <vector>
using namespace std;


void dfs(const vector<vector<int>>& edge, vector<int>& visited, int curr_vectex, int curr_iter){
    visited[curr_vectex] = curr_iter;
    for (int i : edge[curr_vectex]){
        if (!visited[i]){
            visited[i] = curr_iter;
            dfs(edge, visited, i, curr_iter);
        }
    }
}


int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge;
    vector<int> visited;
    vector<vector<int>> counter;
    for (int i = 0; i < N; i++){
        edge.push_back({});
        visited.push_back(0);
    }

    int tmp1, tmp2;
    for (int i = 0; i < M; i++){
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }

    int curr_iter = 1;
    for (int i = 0; i < visited.size(); i++){
        if (!visited[i]){
            dfs(edge, visited, i, curr_iter);
            curr_iter++;
            counter.push_back({i});
        }
        else{
            counter[visited[i] - 1].push_back(i);
        }
    }

    cout << counter.size() << "\n";
    for (int i = 0; i < counter.size(); i++){
        cout << counter[i].size() << "\n";
        for (int j : counter[i]){
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}