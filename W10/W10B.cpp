#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    char map[N][M];

    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if (map[i][j] == 'E'){
                start_y = i;
                start_x = j;
            }
            else if (map[i][j] == 'X'){
                end_y = i;
                end_x = j;
            }
        }
    }

    queue<pair<int, int>> q;

    vector<vector<int>> distance(N, vector<int>(M, -1));

    distance[start_y][start_x] = 0;
    q.push({start_y, start_x});

    int dir_y[4] = {1, 0, -1, 0};
    int dir_x[4] = {0, -1, 0, 1};

    while(q.size()){
        auto [y, x] = q.front();
        q.pop();

        if (y == end_y && x == end_x) break;

        for (int i = 0; i < 4; i++){
            int target_y = y + dir_y[i];
            int target_x = x + dir_x[i];

            if (target_y >= N || target_y < 0 || target_x >= M || target_x < 0) continue;
            if (map[target_y][target_x] == '#') continue;
            if (distance[target_y][target_x] != -1) continue;

            distance[target_y][target_x] = distance[y][x] + 1;
            q.push({target_y, target_x});
        }
    }

    cout << distance[end_y][end_x];

    return 0;
}