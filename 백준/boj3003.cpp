#include <iostream>

using namespace std;

int OriginPiece[6] = {1, 1, 2, 2, 2, 8};
int FindPiece[6];
int result[6];


void input();
void cal();
void Print();

int main(){

    input();
    cal();
    Print();

    return 0;
}

void input() {
    for(int i=0;i<6;i++){
        cin >> FindPiece[i];
    }
}

void cal() {
    for(int i=0;i<6;i++){
        result[i] = OriginPiece[i] - FindPiece[i];
    }
}

void Print() {
    for(int i=0;i<6;i++){
        cout << result[i] << ' ';
    }
}