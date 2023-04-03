#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long N, B, C;
vector<long long> A;
long long temp;

void input() {
    cin >> N;

    for(long long i=0;i<N;i++){
        cin >> temp;
        A.push_back(temp);
    }

    cin >> B >> C;
}

long long cal() {
    long long result=0;
    for(long long i=0;i<A.size();i++){
        if(A[i] <= B ) {
            result ++;
        }
        else {
            if((A[i]-B) % C){
                result = result + (A[i]-B)/C + 2;
            }
            else {
                result = result + (A[i]-B)/C + 1;
            }
        }
    }

    return result;
}

int main() {
    input();

    cout << cal();

    return 0;
}