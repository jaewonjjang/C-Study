#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i=0;i<=t.length()-p.length();i++){
        if(stoull(t.substr(i, p.length())) <= stoull(p)){
            answer++;
        }
    }
    return answer;
}