#include <string>
#include <vector>
#include <queue>

using namespace std;
queue<int> q;


int DFS(int, int, vector<int>);
int result[3];
int res=0;

int solution(vector<int> number) {
    int answer = 0;
    answer = DFS(0, 0, number);
    return answer;
}

int DFS(int L, int beginwith, vector<int> number) {
    int ret=0;
    int numlen = number.size();
    if(L==3){
        ret=0;
        for(int i=0;i<3;i++){
            ret += result[i];
        }
        if(ret==0){
            res++;
        }
    }
    else {
        for(int i=beginwith;i<numlen;i++){
            result[L] = number[i];
            DFS(L+1, i+1, number);
        }
    }
    
    return res;
}