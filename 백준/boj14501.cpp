#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> v;
int N, T, P;
int max_result=0;
bool checklist[20];
int result=0;

void input() {
    cin >> N;
    pair<int, int> p = make_pair(0, 0);
    v.push_back(p);
    for(int i=0;i<N;i++){
        cin >> T >> P;
        v.push_back(make_pair(T, P));
    }
    memset(checklist, false, 20*sizeof(bool));
}

void cal(int cur) {
    if(cur > N){
        max_result = max_result > result ? max_result : result;
    }
    else {
        for(int i=cur;i<=N;i++){
            if(checklist[i] == false && i+v[i].first <= N+1){
                result += v[i].second;
                checklist[i] = true;
                cal(i+v[i].first);
                checklist[i] = false;
                result -= v[i].second;
            }
        }
        max_result = max_result > result ? max_result : result;
    }
}

int main() {
    input();

    cal(1);

    cout << max_result;

    return 0;
}