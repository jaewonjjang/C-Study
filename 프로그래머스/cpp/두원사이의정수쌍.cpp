#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = (long long)r1*r1;
    long long R2 = (long long)r2*r2;
    
    for(int i=1;i<r2;i++) {
        long long ii = (long long)i*i;
        long long temp = (long long)sqrt(R2 - ii);
        if(R1 >= i*i) {
            long double temp2 = (long double)sqrt(R1 - ii);
            if(temp2!= 0 && temp2 == (long long)temp2){
                answer += (temp - (long long)temp2 + 1);
            }
            else {
                answer += temp - (long long)temp2;
            }
        }
        else {
            answer += temp;
        }
    }
    answer += (r2-r1+1);
    answer *= 4;
    return answer;
}