#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int totalAngle = 0;
    int initial, a, b, c;
    cin >> initial >> a >> b >> c;
    while(!(initial == 0 && a == 0 && b == 0 && c == 0)){
        totalAngle = 1080;
        totalAngle += ((initial - a + 40) % 40) * 9;
        totalAngle += ((b - a + 40) % 40) * 9;
        totalAngle += ((b - c + 40) % 40) * 9;

        if(b == c)
            totalAngle += 360;

        cout << totalAngle << endl;
        cin >> initial >> a >> b >> c;
    }
}
