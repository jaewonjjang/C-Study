#include <iostream>
#include <cstring>

using namespace std;

int N;
int people[21];
int stat[21][21];
int team1[10] = {0};
int team2[10] = {0};
int team1_result = 0;
int team2_result = 0;
int result=1000000;
int n[3];


bool checklist[11];
void input();
void cal();
void teamSelect(int, int);
int evalScore();
void calScoreTeam1(int L);
void calScoreTeam2(int L);

int main() {

    input();

    teamSelect(0, 0);

    cout << result;
    return 0;
}


//people, stat 배열 입력과 초기화
void input() {
    cin >> N;

    for(int i=1;i<=N;i++){
        people[i] = i;
        for(int j=1;j<=N;j++){
            cin >> stat[i][j];
        }
    }
}

void cal() {
    int j=0;
    bool checklist[21] = {false};
    for(int i=0;i<N/2;i++){
        checklist[team1[i]] = true;
    }

    for(int i=1;i<=N;i++){
        if(checklist[i] == false){
            team2[j++] = i;
        }
    }
    /////// team1 team2 분리 완료 ////////

    //cout << evalScore() <<endl;
    result = result < evalScore() ? result : evalScore();
}

void teamSelect(int level, int beginwith){
    if(level == N/2){
        cal();
    }
    else {
        for(int i=beginwith;i<N;i++){
            team1[level] = people[i+1];
            teamSelect(level+1, i+1);
        }
    }
}


int evalScore() {
    team1_result = 0;
    team2_result = 0;

    memset(checklist, false, sizeof(bool)*11);
    calScoreTeam1(0);

    memset(checklist, false, sizeof(bool)*11);
    calScoreTeam2(0);

    return abs(team1_result - team2_result);
}

void calScoreTeam1(int L) {
    if(L==2) {
        team1_result += stat[n[0]][n[1]];
    }
    else {
        for(int i=0;i<N/2;i++){
            if(checklist[i] == false){
                n[L] = team1[i];
                checklist[i] = true;
                calScoreTeam1(L+1);
                checklist[i] = false;
            }
        }
    }
}

void calScoreTeam2(int L) {
    if(L==2) {
        team2_result += stat[n[0]][n[1]];
    }
    else {
        for(int i=0;i<N/2;i++){
            if(checklist[i] == false) {
                n[L] = team2[i];
                checklist[i] = true;
                calScoreTeam2(L+1);
                checklist[i] = false;
            }
        }
    }
}

