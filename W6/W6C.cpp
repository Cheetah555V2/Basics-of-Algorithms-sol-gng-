#include <iostream>
#include <vector>
using namespace std;

int max(int arr[4]){
    int mx = arr[0];
    for (int i = 1; i < 4; i++){
        if (mx < arr[i]){
            mx = arr[i];
        }
    }
    return mx;
}


enum Direction {
    UpLeft,
    UpRight,
    DownLeft,
    DownRight
};


int solver(int arr[8][8], int black_location[2]){
    
    Direction directions[4] = {UpLeft, UpRight, DownLeft, DownRight};

    int mx_eat_direction[4] = {0, 0, 0, 0};

    for (Direction dir : directions){
        switch (dir) {
            case UpLeft:
                if ((arr[black_location[0] - 1][black_location[1] - 1] == 1) &&
                    (black_location[0] - 2 >= 0) &&
                    (black_location[1] - 2 >= 0) &&
                    (arr[black_location[0] - 2][black_location[1] - 2] == 0)) {

                    int curr_x = black_location[0];
                    int curr_y = black_location[1];
                    
                    arr[black_location[0] - 1][black_location[1] - 1] = 0;
                    arr[black_location[0]][black_location[1]] = 0;
                    arr[black_location[0] - 2][black_location[1] - 2] = 2;
                    black_location[0] = curr_x - 2;
                    black_location[1] = curr_y - 2;

                    mx_eat_direction[dir] = solver(arr, black_location) + 1;
                    
                    black_location[0] = curr_x;
                    black_location[1] = curr_y;
                    arr[black_location[0] - 1][black_location[1] - 1] = 1;
                    arr[black_location[0]][black_location[1]] = 2;
                    arr[black_location[0] - 2][black_location[1] - 2] = 0;
                }
                break;

            case UpRight:
                if ((arr[black_location[0] - 1][black_location[1] + 1] == 1) &&
                    (black_location[0] - 2 >= 0) &&
                    (black_location[1] + 2 < 8)  &&
                    (arr[black_location[0] - 2][black_location[1] + 2] == 0)) {
                    
                    int curr_x = black_location[0];
                    int curr_y = black_location[1];

                    arr[black_location[0] - 1][black_location[1] + 1] = 0;
                    arr[black_location[0]][black_location[1]] = 0;
                    arr[black_location[0] - 2][black_location[1] + 2] = 2;
                    black_location[0] = curr_x - 2;
                    black_location[1] = curr_y + 2;

                    mx_eat_direction[dir] = solver(arr, black_location) + 1;
                    
                    black_location[0] = curr_x;
                    black_location[1] = curr_y;
                    arr[black_location[0] - 1][black_location[1] + 1] = 1;
                    arr[black_location[0]][black_location[1]] = 2;
                    arr[black_location[0] - 2][black_location[1] + 2] = 0;
                }
                break;

            case DownLeft:
                if ((arr[black_location[0] + 1][black_location[1] - 1] == 1) &&
                    (black_location[0] + 2 < 8) &&
                    (black_location[1] - 2 >= 0)&&
                    (arr[black_location[0] + 2][black_location[1] - 2] == 0)) {
                
                    int curr_x = black_location[0];
                    int curr_y = black_location[1];

                    arr[black_location[0] + 1][black_location[1] - 1] = 0;
                    arr[black_location[0]][black_location[1]] = 0;
                    arr[black_location[0] + 2][black_location[1] - 2] = 2;
                    black_location[0] = curr_x + 2;
                    black_location[1] = curr_y - 2;

                    mx_eat_direction[dir] = solver(arr, black_location) + 1;
                    
                    black_location[0] = curr_x;
                    black_location[1] = curr_y;
                    arr[black_location[0] + 1][black_location[1] - 1] = 1;
                    arr[black_location[0]][black_location[1]] = 2;
                    arr[black_location[0] + 2][black_location[1] - 2] = 0;
                }
                break;
            
            case DownRight:
                if ((arr[black_location[0] + 1][black_location[1] + 1] == 1) &&
                    (black_location[0] + 2 < 8) &&
                    (black_location[1] + 2 < 8) &&
                    (arr[black_location[0] + 2][black_location[1] + 2] == 0)) {
                    
                    int curr_x = black_location[0];
                    int curr_y = black_location[1];

                    arr[black_location[0] + 1][black_location[1] + 1] = 0;
                    arr[black_location[0]][black_location[1]] = 0;
                    arr[black_location[0] + 2][black_location[1] + 2] = 2;
                    black_location[0] = curr_x + 2;
                    black_location[1] = curr_y + 2;

                    mx_eat_direction[dir] = solver(arr, black_location) + 1;
                    
                    black_location[0] = curr_x;
                    black_location[1] = curr_y;
                    arr[black_location[0] + 1][black_location[1] + 1] = 1;
                    arr[black_location[0]][black_location[1]] = 2;
                    arr[black_location[0] + 2][black_location[1] + 2] = 0;
                }
                break;
        }
    }

    return max(mx_eat_direction);
}


int main(){
    int arr[8][8];
    int black_position[2];
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 2){
                black_position[0] = i;
                black_position[1] = j;
            }
        }
    }

    cout << solver(arr, black_position);

    return 0;
}