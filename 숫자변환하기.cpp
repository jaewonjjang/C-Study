#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {

    queue<pair<int,int>> q;
    
    q.push(make_pair(y, 0));
    
    while(!q.empty()) {
        int pop = q.front().first;
        int calNum = q.front().second;
        q.pop();
        
        if(pop == x){
            return calNum;
        }
        
        for(int i=0;i<3;i++){
            if(i==0 && pop-n >= x){
                q.push(make_pair(pop-n, calNum+1));
            }
            else if(i==1 && pop%2==0 && pop/2>= x) {
                q.push(make_pair(pop/2, calNum+1));
            }
            else if(i==2 && pop%3==0 && pop/3 >= x) {
                q.push(make_pair(pop/3, calNum+1));
            }
        }
    }
    return -1;
}