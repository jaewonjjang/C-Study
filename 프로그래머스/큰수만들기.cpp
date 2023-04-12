#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int stringlen = number.size()-k;
    int current =0;
    int pick;
    char tempmax='0';
    int i;
    for(pick=stringlen;pick>0;pick--){
        for(i=current;i<number.size()-pick+1;i++){
            if(tempmax < number[i]){
                current = i+1;
                tempmax = number[i];
            }
        }
        answer.push_back(tempmax);
        tempmax = '0';
    }
    
    return answer;
}