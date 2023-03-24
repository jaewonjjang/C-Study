#include <iostream>
#include <vector>

using namespace std;

int N;
int current;

int Narray[100000];
vector<int> stack;
vector<char> printstack;

void input();

int main() {
    input();
    current = 1;

    for(int i=0;i<N;i++){
        // 스택이 비어있으면 쌓는다
        if(stack.empty()){
            for(int j=current;j<=Narray[i];j++){
                stack.push_back(j);
                printstack.push_back('+');
            }
            stack.pop_back();
            printstack.push_back('-');
            current = Narray[i]+1;
        }
        else {
            if(stack.back() == Narray[i]) {
                stack.pop_back();
                printstack.push_back('-');
            }
            else {
                if(stack.back() > Narray[i]) {
                    cout << "NO";
                    return 0;
                }
                else {
                    for(int j=current;j<=Narray[i];j++){
                        stack.push_back(j);
                        printstack.push_back('+');
                    }
                    stack.pop_back();
                    printstack.push_back('-');
                    current = Narray[i]+1;
                }
            }
        }
    }

    vector<char>::iterator iter;
    for(iter = printstack.begin();iter != printstack.end();iter++){
        cout << *iter << "\n";
    }

    return 0;
}

void input() {
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> Narray[i];
    }
}