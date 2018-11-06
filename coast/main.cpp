#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(int RR, int CC, int maxCol, int maxRow, vector< vector< int > >& arr, int & count){
    arr[RR][CC] = 9;
    if(RR > 0 && (arr[RR-1][CC] == 0 || arr[RR-1][CC] == 1 )){
        if (arr[RR-1][CC] == 1 ){
            count++;
        } else {
            dfs(RR - 1, CC, maxCol, maxRow, arr, count);
        }
    }
    if(RR < maxRow && (arr[RR+1][CC] == 0 || arr[RR+1][CC] == 1 )){
        if(arr[RR+1][CC] == 1 ){
            count++;
        } else {
            dfs(RR + 1, CC, maxCol, maxRow, arr, count);
        }
    }
    if(CC > 0 && (arr[RR][CC-1] == 0||arr[RR][CC-1] == 1)){
        if(arr[RR][CC-1] == 1){
            count++;
        } else {
            dfs(RR, CC - 1, maxCol, maxRow, arr, count);
        }
    }
    if(CC < maxCol && (arr[RR][CC+1] == 0||arr[RR][CC+1] == 1)){
        if(arr[RR][CC+1] == 1){
            count++;
        } else {
            dfs(RR, CC + 1, maxCol, maxRow, arr, count);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector< vector < int > > v(n+2);
    for(int i = 0; i < n+2; i++){
        v[i].resize(m+2);
    }

    string temp;
    for(int RR = 1; RR < n+1; RR++){
        cin >> temp;
        for(int CC = 1; CC < m+1; CC++){
            v[RR][CC] = temp[CC-1] - '0';
        }
    }

    int count = 0;
    dfs(0, 0, m+1, n+1, v, count);

    cout<<count;
}
