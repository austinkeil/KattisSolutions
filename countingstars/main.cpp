#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void visitNeighbors(int r, int c, int maxRow, int maxCol, vector< vector< char > >& sky){
    sky[r][c] = '#';
    if(r-1 >= 0 && sky[r-1][c] == '-')
        visitNeighbors(r-1, c, maxRow, maxCol, sky);
    if(r+1 <= maxRow && sky[r+1][c] == '-')
        visitNeighbors(r+1, c, maxRow, maxCol, sky);
    if(c-1 >=0 && sky[r][c-1] == '-')
        visitNeighbors(r, c-1, maxRow, maxCol, sky);
    if(c+1 <= maxCol && sky[r][c+1] == '-')
        visitNeighbors(r, c+1, maxRow, maxCol, sky);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNumber = 1;
    int row, col;
    while(cin >> row >> col) {

        vector<vector<char> > sky(row);
        for (int i = 0; i < row; i++) {
            sky[i].resize(col);
        }

        for (int RR = 0; RR < row; RR++) {
            for (int CC = 0; CC < col; CC++) {
                cin >> sky[RR][CC];
            }
        }

        int starCount = 0;
        for (int RR = 0; RR < row; RR++) {
            for (int CC = 0; CC < col; CC++) {
                if (sky[RR][CC] == '-') {
                    starCount += 1;
                    visitNeighbors(RR, CC, row - 1, col - 1, sky);
                }
            }
        }
        cout << "Case " << caseNumber << ": " << starCount << endl;
        caseNumber++;
    }
}