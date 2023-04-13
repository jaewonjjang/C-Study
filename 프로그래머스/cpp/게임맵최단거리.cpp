#include<vector>
#include<queue>
#include <cstring>
using namespace std;

typedef struct _triplet{
    int x;
    int y;
    int dist;
}triplet;

queue<triplet> q;
int movex[4] = {1, 0, -1, 0};
int movey[4] = {0, 1, 0, -1};
bool checklist[101][101];
int findpath(vector<vector<int> >);
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    memset(checklist, false, sizeof(bool)*101*101);
    answer = findpath(maps);
    return answer;
}

int findpath(vector<vector<int> > maps){

    triplet jaewon;
    jaewon.x = 0; jaewon.y = 0; jaewon.dist=1;
    
    q.push(jaewon);
    
    while(!q.empty()){
        triplet cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            if(cur.y + movey[i] < maps.size() && cur.y + movey[i] >= 0 && cur.x + movex[i] < maps[0].size() && cur.x + movex[i] >= 0 && maps[cur.y + movey[i]][cur.x + movex[i]]==1 && checklist[cur.y + movey[i]][cur.x + movex[i]]==false){
                if(cur.y + movey[i]==maps.size()-1 && cur.x + movex[i]==maps[0].size()-1){
                    return cur.dist+1;
                }
                checklist[cur.y + movey[i]][cur.x + movex[i]]=true;
                triplet heeju;
                heeju.y = cur.y + movey[i]; heeju.x = cur.x + movex[i]; heeju.dist = cur.dist+1;
                q.push(heeju);
            }
        }
    }
    
    return -1;
}