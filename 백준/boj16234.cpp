#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int N, L, R;

int people[51][51];
bool check[51][51];
pair<bool,bool> room[51][51];
queue<pair<int,int>> q;
vector<pair<int,int>> v;

void input() {
    cin >> N >> L >> R;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> people[i][j];
        }
    }
}

bool door_open() {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            room[i][j].first = false;
            room[i][j].second = false;
        }
    }
    bool flag=false;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i==N-1){
                if(j==N-1){
                    continue;
                }
                int h_diff = abs(people[i][j] - people[i][j+1]);
                if(h_diff <= R && h_diff >= L) {
                    room[i][j].first = true;
                    flag = true;
                }
            }
            else if(j==N-1) {
                int v_diff = abs(people[i][j] - people[i+1][j]);
                if(v_diff <= R && v_diff >= L) {
                    room[i][j].second = true;
                    flag = true;
                }
            }
            else {
                int h_diff = abs(people[i][j] - people[i][j+1]);
                int v_diff = abs(people[i][j] - people[i+1][j]);
                if(v_diff <= R && v_diff >= L) {
                    room[i][j].second = true;
                    flag = true;
                }
                if(h_diff <= R && h_diff >= L) {
                    room[i][j].first = true;
                    flag = true;
                }
            }
        }
    }

    return flag;
}

void move() {
    memset(check, false, sizeof(bool)*51*51);
    int total;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(check[i][j]==false){
                total = 0;
                check[i][j] = true;
                q.push(make_pair(i, j));
                v.push_back(make_pair(i, j));

                while(!q.empty()) {
                    pair<int,int> s = q.front();
                    q.pop();
                    total += people[s.first][s.second];
                    //우로 이동
                    if(room[s.first][s.second].first && check[s.first][s.second+1]==false) {
                        q.push(make_pair(s.first, s.second+1));
                        v.push_back(make_pair(s.first, s.second+1));
                        check[s.first][s.second+1] = true;
                    }
                    //아래로 이동
                    if(room[s.first][s.second].second && check[s.first+1][s.second]==false) {
                        q.push(make_pair(s.first+1, s.second));
                        v.push_back(make_pair(s.first+1, s.second));
                        check[s.first+1][s.second] = true;
                    }
                    //위로 이동
                    if(s.first-1>=0 && room[s.first-1][s.second].second && check[s.first-1][s.second]==false) {
                        q.push(make_pair(s.first-1, s.second));
                        v.push_back(make_pair(s.first-1, s.second));
                        check[s.first-1][s.second] = true;
                    }
                    //좌로이동
                    if(s.second-1>=0 && room[s.first][s.second-1].first && check[s.first][s.second-1]==false) {
                        q.push(make_pair(s.first, s.second-1));
                        v.push_back(make_pair(s.first, s.second-1));
                        check[s.first][s.second-1] = true;
                    }
                }
                for(int k=0;k<v.size();k++){
                    people[v[k].first][v[k].second] = total / v.size();
                }
                v.clear();
            }
        }
    }
    
}

int main() {
    input();

    int result=0;
    while(door_open()) {
        result++;
        move();

        // for(int i=0;i<N;i++) {
        //     for(int j=0;j<N;j++) {
        //         cout << people[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        //sleep(3);
    }

    cout << result;
    return 0;
}