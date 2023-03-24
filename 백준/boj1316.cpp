#include <iostream>
#include <string>

using namespace std;

int input();
int cal();

bool words[26];
char charstring[100];
int N;
int result;

int main() {
    cout << input();
    return 0;
}

int input() {
    result = 0;
    cin >> N;
    cin.ignore();
    for(int i=0;i<N;i++){

        memset(words, false, 26*sizeof(bool));

        cin.getline(charstring, 100);

        result += cal();

        memset(charstring, 0, 100);
    }

    return result;
}

int cal() {
    for(int j=0;j<strlen(charstring);j++){
        if(j>0){
            if(charstring[j-1] == charstring[j]) {
                continue;
            }
            else {
                if(words[charstring[j]-97]==true){
                    return 0;
                }
            }
        }
        words[charstring[j]-97]=true;
    }
    return 1;
}