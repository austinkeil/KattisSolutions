#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dfs(int RR, int CC, int maxRow, int maxCol, vector< vector<int > > &arr, set<pair<int, int> > &visited, vector< vector<int > > &arr2){

    // base cases
    if(RR > 0 && arr[RR-1][CC] < arr[RR][CC]){
        return 0;
    } else if (RR < maxRow && arr[RR+1][CC] < arr[RR][CC]){
        return 0;
    } else if (CC > 0 && arr[RR][CC-1] < arr[RR][CC]){
        return 0;
    } else if (CC < maxCol && arr[RR][CC+1] < arr[RR][CC]) {
        return 0;
    }
    visited.insert(make_pair(RR,CC));
    arr2[RR][CC] = 1;

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    bool upBool = true;
    bool downBool = true;
    bool leftBool = true;
    bool rightBool = true;

    if(RR > 0 && visited.count(make_pair(RR-1, CC)) == 0 && arr[RR-1][CC] == arr[RR][CC]){
        up = dfs(RR-1, CC, maxRow, maxCol, arr, visited, arr2);
        if( up == 0 ) upBool = false;
    }
    if(RR < maxRow && visited.count(make_pair(RR+1, CC)) == 0 && arr[RR+1][CC] == arr[RR][CC]){
        down = dfs(RR+1, CC, maxRow, maxCol, arr, visited, arr2);
        if( down == 0 ) downBool = false;
    }
    if(CC > 0 && visited.count(make_pair(RR, CC-1)) == 0 && arr[RR][CC-1] == arr[RR][CC]){
        left = dfs(RR, CC-1, maxRow, maxCol, arr, visited, arr2);
        if( left == 0 ) leftBool = false;
    }
    if(CC < maxCol && visited.count(make_pair(RR, CC+1)) == 0 && arr[RR][CC+1] == arr[RR][CC]){
        right = dfs(RR, CC+1, maxRow, maxCol, arr, visited, arr2);
        if( right == 0 ) rightBool = false;
    }

    if( upBool && downBool && leftBool && rightBool){
        return 1 + up + down + left + right;
    } else {
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    vector < vector < int > > v(y+2);
    vector < vector < int > > v2(y+2);
    for(int i = 0; i < y+2; i++){
        v[i].resize(x+2, 1000);
        v2[i].resize(x+2, 0);
    }

    for(int RR = 1; RR < y+1; RR++){
        for(int CC = 1; CC < x+1; CC++){
            cin >> v[RR][CC];
        }
    }

    set< pair <int, int> > visited;

    int count = 0;
    for(int RR = 1; RR < y+1; RR++){
        for(int CC = 1; CC < x+1; CC++){
            if(v2[RR][CC] == 0){
                visited.clear();
                count += dfs(RR, CC, y + 1, x + 1, v, visited, v2);
            }
        }
    }

    cout << count;
}