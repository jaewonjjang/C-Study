// sort 사용법

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> jaewon;

bool Greater(int a, int b){
    return a > b;
}

int main() {
    vector<int>::iterator iter;

    for(int i=0;i<10;i++){
        jaewon.push_back(rand() % 10);
    }

    for(iter = jaewon.begin() ; iter != jaewon.end() ; iter ++){
        cout << *iter << " "; 
    }
    cout << endl;

    sort(jaewon.begin(), jaewon.end(), Greater);

    for(iter = jaewon.begin() ; iter != jaewon.end() ; iter ++){
        cout << *iter << " "; 
    }

    return 0;
}