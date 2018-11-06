#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int nCS, nE;
        cin >> nCS >> nE;
        vector<int> cs(nCS);
        vector<int> econ(nE);
        int temp;
        for (int i = 0; i < nCS; i++) {
            cin >> temp;
            cs[i] = temp;
        }
        for (int i = 0; i < nE; i++) {
            cin >> temp;
            econ[i] = temp;
        }
        sort(cs.begin(), cs.end());
        sort(econ.begin(), econ.end());
        double avgEcon = accumulate(econ.begin(), econ.end(), 0.0) / nE;
        double avgCS = accumulate(cs.begin(), cs.end(), 0.0) / nCS;
//        cout << avgCS << " " << avgEcon << endl;
        int i = 0, count = 0;
        while(cs[i] < avgCS){
            if(cs[i] > avgEcon){
                count += 1;
//                cout << cs[i] << endl;
            }
            i++;
        }
        cout << count << endl;
    }
}