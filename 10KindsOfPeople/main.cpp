#include <iostream>
#include <set>
#include <utility>
#include <stack>

using namespace std;

int main2() {
    int r;
    int c;
    scanf("%i %i", &r, &c);
    int graph[r + 2][c + 2];
    char temp [c];

    for (size_t i = 0; i < r + 2; i++) {
        for (size_t j = 0; j < c + 2; j++) {
            graph[i][j] = 2;
        }
    }

        for (int i = 1; i < r + 1; i++) {
            scanf("%s", temp);
            for (int j = 1; j < c + 1; j++) {
                graph[i][j] = (int)temp[j-1] - 48;
            }
        }

    int n = 0;
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        int result = -100;
        scanf("%i %i %i %i", &r1, &c1, &r2, &c2);


        int start = graph[r1][c1];
        pair<int, int> end = make_pair(r2, c2);
        stack< pair<int, int> > stack1;
        stack1.push(make_pair(r1, c1));
        set< pair<int, int> > visited;
        pair<int, int> vertex;
        //set<std::pair<int,int>>::iterator it;
        while(!stack1.empty()){
            vertex = stack1.top();
            stack1.pop();
            visited.insert(vertex);
            pair<int, int> cur = make_pair(vertex.first, vertex.second);
            if(cur == end){
                result = start;
                break;
            }
            if(graph[vertex.first-1][vertex.second] == start && visited.find(pair<int, int>(vertex.first-1, vertex.second)) == visited.end()){
                stack1.push(pair<int, int>(vertex.first-1, vertex.second));
            }
            if(graph[vertex.first+1][vertex.second] == start && visited.find(pair<int, int>(vertex.first+1, vertex.second)) == visited.end()){
                stack1.push(pair<int, int>(vertex.first+1, vertex.second));
            }
            if(graph[vertex.first][vertex.second+1] == start && visited.find(pair<int, int>(vertex.first, vertex.second+1)) == visited.end()){
                stack1.push(pair<int, int>(vertex.first, vertex.second+1));
            }
            if(graph[vertex.first][vertex.second-1] == start && visited.find(pair<int, int>(vertex.first, vertex.second-1)) == visited.end()){
                stack1.push(pair<int, int>(vertex.first, vertex.second-1));
            }
        }
        if(result == -100){
            result = -1;
        }

        if(result == 1)
            cout<<"decimal"<<endl;
        else if(result == 0)
            cout<<"binary"<<endl;
        else
            cout<<"neither"<<endl;
    }
        return 0;
    }