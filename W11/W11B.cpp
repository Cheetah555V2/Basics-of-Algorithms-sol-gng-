#include <iostream>
#include <iomanip>
using namespace std;


long long gcd(long long a, long long b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}


long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}


int main(){
    int N;
    cin >> N;
    long long arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    long double rotation = 1;

    for(int i = 0; i < N; i++){
        rotation = lcm(rotation, arr[i] / gcd(arr[0], arr[i]));
    }

    cout << fixed << setprecision(0) << rotation;
    
    return 0;
}