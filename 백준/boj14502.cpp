#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


int N, M, T;
int lab[9][9];
int flab[9][9];
int wall[3];
int max_result=0;
queue<pair<int, int>> virus;

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
void input() {
    memset(lab, 0, sizeof(int)*9*9);
    cin >> N >> M;
    T = N*M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> lab[i][j];
        }
    }
    
}

int cal() {
    int temp=0;
    int lap=0;
    memcpy(flab, lab, sizeof(int)*9*9);

    for(int i=0;i<3;i++){
        flab[wall[i]/M][wall[i]%M] = 1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(flab[i][j]==2){
                virus.push(make_pair(i, j));
            }
        }
    }
    while(!virus.empty()) {
        pair<int, int> s = virus.front();
        virus.pop();

        for(int i=0;i<4;i++){
            //이동
            if((s.first + y[i] >= 0) && (s.first + y[i] < N) && (s.second + x[i] >= 0) && 
                (s.second + x[i] < M) && (flab[s.first + y[i]][s.second + x[i]]==0)){
                virus.push(make_pair(s.first + y[i], s.second + x[i]));
                flab[s.first + y[i]][s.second + x[i]]=2;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(flab[i][j]==0) temp++;
        }
    }

    return temp;

}


void selectWall(int level, int beginwith) {
    if(level==3){
        int temp = cal();
        max_result = max_result > temp ? max_result : temp;
    }
    else {
        for(int i=beginwith;i<T;i++){
            if(lab[i/M][i%M]!=1 && lab[i/M][i%M]!=2){
                wall[level] = i;
                selectWall(level+1, i+1);
            }

        }
    }
}

int main(){
    input();

    selectWall(0, 0);

    cout << max_result;

    return 0;
}