#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x;
    cin >> n >> q;

    vector<bool> primeBits(n + 1, true);
    primeBits[0] = primeBits[1] = false;
    int count = n - 1;

    for (int i = 2; i * i <= n; ++i) {
        if (primeBits[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (primeBits[j] == true) {
                    primeBits[j] = false;
                    count--;
                }
            }
        }
    }

    cout << count << "\n";
    while (q--) {
        cin >> x;
        cout << primeBits[x] << "\n";

    }
    return 0;
}