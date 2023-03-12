#include <iostream>

using namespace std;

int N;
int operand[11];
int operator_totalnum[4];
int operator_array[10];
int operator_array_perm[10];

int total_num = 0;
int max_result = 0;
int min_result = 0;
bool checklist[10] = {false};


void input();
void makeOperatorArray(int);
int cal();
int eval(int, int);
int main() {
    input();

    makeOperatorArray(0);

    cout << max_result << endl << min_result;
    return 0;
}

void input() {
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> operand[i];
    }
    int prev_j = 0;
    int j=0;
    for(int i=0;i<4;i++){
        cin >> operator_totalnum[i];
        total_num += operator_totalnum[i];
        for(j=prev_j;j<prev_j + operator_totalnum[i];j++){
            operator_array[j] = i;
        }
        prev_j = j;
    }
    
    int temp=operand[0];
    for(int i=0;i<total_num;i++){
        if(operator_array[i] == 0){
            temp = temp + operand[i+1];
        }
        else if(operator_array[i] == 1){
            temp = temp - operand[i+1];
        }
        else if(operator_array[i] == 2){
            temp = temp * operand[i+1];
        }
        else if(operator_array[i] == 3){
            temp = temp / operand[i+1];
        }
    }

    max_result = min_result = temp;
}

void makeOperatorArray(int idx) {
    if(idx == total_num){
        max_result = max_result > cal() ? max_result : cal();
        min_result = min_result < cal() ? min_result : cal();
    }
    else {
        for(int i=0;i<total_num;i++) {
            if(checklist[i] == false){
                operator_array_perm[idx] = operator_array[i];
                checklist[i] = true;
                makeOperatorArray(idx+1);
                checklist[i] = false;
            }
        }
    }
}


int cal() {
    int prev=operand[0];
    for(int i=0;i<total_num;i++){
        prev = eval(prev, i);
    }

    return prev; // 전체 계산 결과를 반환해준다. 
}

int eval(int prev, int i) {
    switch(operator_array_perm[i]){
        case 0 : return prev + operand[i+1];
        case 1 : return prev - operand[i+1];
        case 2 : return prev * operand[i+1];
        case 3 : return prev / operand[i+1];
    }

    return 0;
}