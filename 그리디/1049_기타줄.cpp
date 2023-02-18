#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> v1(M);
    vector<int> v2(M);
    for(int i=0; i<M;i++){
        cin >> v1[i]>> v2[i];
        if(v1[i] > v2[i] * 6) v1[i] = 987654321;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if(N / 6 < 0) cout << v2[0]*N;

    else {
        if(v1[0] >= v2[0] * 6) cout << v2[0]*N;
        else {
            int sum = 0;
            sum += N / 6 * v1[0];
            if(N % 6){
                if(N % 6 * v2[0] > v1[0]){
                    sum += v1[0];
                }
                else sum += N % 6 * v2[0];
            }
            cout << sum;
        }
    }
    return 0;

}