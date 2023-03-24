#include <iostream>
#include <vector>
#include <string>

using namespace std;

void input();
int cal();

vector<char> vectorstring;
string originstring;

int result=1;

int main() {
    input();

    cout << cal();

    return 0;
}

void input(){
    cin >> originstring;

    for(int i=0; i<originstring.length(); i++){
        vectorstring.push_back(originstring[i]);
    }
}

int cal(){
    vector<char>::iterator riter;
    vector<char>::reverse_iterator liter = vectorstring.rbegin();

    for(riter=vectorstring.begin(); riter!= vectorstring.end() ; riter++){
        if(liter == vectorstring.rend()){
            return result;
        }

        if(*riter == *liter) {
            liter++;
        }
        else {
            result = 0;
            return result;
        }
    }

    return result;
}