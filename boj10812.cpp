#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int N, M;
int i, j, k;
void PrintVector();
void input();

int main() {
    input();

    PrintVector();

    return 0;
}

void input(){
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        v.push_back(i);
    }

    for(int l=0;l<M;l++){
        cin >> i >> j >> k;

        v.insert(v.begin()+j, v.begin()+i-1, v.begin()+k-1);
        v.erase(v.begin()+i-1, v.begin()+k-1);
    }
}

void PrintVector(){
    vector<int>::iterator iter;

    for(iter=v.begin(); iter!=v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}