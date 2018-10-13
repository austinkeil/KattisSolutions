#include <bits/stdc++.h>

using namespace std;

bool comp(const string& string1,const string& string2){
    string str1Copy(string1);
    string str2Copy(string2);
    transform(str1Copy.begin(), str1Copy.end(), str1Copy.begin(), ::tolower);
    transform(str2Copy.begin(), str2Copy.end(), str2Copy.begin(), ::tolower);
    return (str1Copy < str2Copy);
}


int main() {
    int r, c;
    cin >> r >> c;
    while (r != 0 && c != 0) {

        vector<string> stringVector(c);
        for (int i = 0; i < r; i++) {
            string word = "";
            cin >> word;
            for (int j = 0; j < c; j++) {
                stringVector.at(j).push_back(word[j]);
            }
        }
        stable_sort(stringVector.begin(), stringVector.end(), comp);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << stringVector[j][i];
            }
            cout<<"\n";
        }
        cin >> r >> c;
        if(r == 0 && c == 0)
            break;
        cout<<"\n";
    }

    return 0;
}