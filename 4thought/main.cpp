#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int eval(string a, string b, string op){
    int ia = stoi(a);
    int ib = stoi(b);
    if(op == "/") return ia / ib;
    else if (op == "*") return ia * ib;
    else if (op == "+") return ia + ib;
    else if (op == "-") return ia - ib;
}

string eval2(string str_exp){
    istringstream exp(str_exp);
    vector<string> tokens{istream_iterator<string>(exp),istream_iterator<string>()};
    reverse(tokens.begin(), tokens.end());
    stack<string, vector<string>> stack1(tokens);
    stack<string, vector<string>> stack2;
    while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
        string top2 = stack2.top();
        if(top2 == "*" || top2 == "/"){
            stack2.pop();
            string result = (to_string(eval(stack2.top(), stack1.top(), top2)));
            stack2.pop();
            stack2.push(result);
            stack1.pop();
        }
    }
    while(!stack2.empty()){
        stack1.push(stack2.top());
        stack2.pop();
    }
    while(stack1.size()>1){
        string a = stack1.top();
        stack1.pop();
        string op = stack1.top();
        stack1.pop();
        string b = stack1.top();
        stack1.pop();
        stack1.push(to_string(eval(a, b, op)));
    }
    return stack1.top();
}


vector<string> results;
vector<string> expressions;
string ops[] = {"*", "+", "-", "/"};

int main() {
    results.reserve(100);
    expressions.reserve(100);
    string result;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                string exp = "4 " + ops[i] + " 4 " + ops[j] + " 4 " + ops[k] + " 4";
                result = eval2(exp);
                results.push_back(result);
                expressions.push_back(exp + " = " + result);
//                cout<<exp;
//                cout<<" = "<<eval2(exp);
//                cout<<endl;
            }
        }
    }
    vector<string>::iterator it;

    int m;
    scanf("%d", &m);
    int n;
    for(int i = 0; i < m; i++){
        scanf("%d", &n);
        it = find(results.begin(), results.end(), to_string(n));
        if(it != results.end())
            cout<<expressions[it - results.begin()]<<endl;
        else
            printf("no solution\n");

    }
//    cout<<eval2("4 * 4 * 4 - 4");
    return 0;
}