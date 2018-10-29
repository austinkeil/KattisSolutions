#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t1, t2;
    cin >> t1 >> t2;
    int t1Hours = stoi(t1.substr(0, 2));
    int t1Mins = stoi(t1.substr(3, 2));
    int t1Secs = stoi(t1.substr(6, 2));

    int t2Hours = stoi(t2.substr(0, 2));
    int t2Mins = stoi(t2.substr(3, 2));
    int t2Secs = stoi(t2.substr(6, 2));

    ll t1Total = t1Hours * 3600 + t1Mins * 60 + t1Secs;
    ll t2Total = t2Hours * 3600 + t2Mins * 60 + t2Secs;

    ll t3Secs = ((t2Total - t1Total) + 86400) % 86400;
    if(t3Secs == 0){
        cout<<"24:00:00";
        return 0;
    }
    int t3Hours = (t3Secs / 3600);
    int t3Mins = ((t3Secs % 3600) / 60);
    int t3Secs2 = ((t3Secs % 3600) % 60);

    if (t3Hours < 10)
        cout << 0;
    cout << t3Hours << ":";
    if (t3Mins < 10)
        cout << 0;
    cout << t3Mins << ":";
    if (t3Secs2 < 10)
        cout << 0;
    cout << t3Secs2;
    return 0;
}

