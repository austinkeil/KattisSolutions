#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int d1, d2;
        cin >> d1;
        d1 += 1;
        vector<int> p1(d1);
        int temp;
        for(int i = 0; i < d1; i++) {
            cin >> temp;
            p1[i] = temp;
        }
        cin >> d2;
        d2 += 1;
        vector<int> p2(d2);
        for(int i = 0; i < d2; i++) {
            cin >> temp;
            p2[i] = temp;
        }

        vector<int> result(d1 + d2);
        for(int it2 = 0; it2 < d2; it2++){
            for(int it1 = 0; it1 < d1; it1++){
                result[it2 + it1] += p1[it1] * p2[it2];
            }
        }
        int result_degree = d1 + d2 - 2;
        cout << result_degree << endl;
        for(int i = 0; i < result_degree; i++){
            //fix this
            cout << result[i] << " ";
        }
        cout << result[result_degree] << endl;
    }
}
