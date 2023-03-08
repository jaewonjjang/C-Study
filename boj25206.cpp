#include <iostream>
#include <string>


using namespace std;

typedef struct _classGrade{
    string lecture;
    float score;
    string grade;
}classGrade;

float gradeScore[9] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
classGrade chihun[20];
float result;
float totalscore;
int gradeToscore(string grade);
void input();
void cal();

int main(){
    input();

    cal();

    return 0;
}   

void input() {

    result = 0;
    totalscore = 0;

    for(int i=0l;i<20;i++){
        cin >> chihun[i].lecture >> chihun[i].score >> chihun[i].grade;
        if(gradeToscore(chihun[i].grade)==100){
            continue;
        }
        else {
            result += gradeScore[gradeToscore(chihun[i].grade)] * chihun[i].score;
            totalscore += chihun[i].score;
        }
    }

}

void cal() {
    cout << result / totalscore;
}

int gradeToscore(string grade){
    if(grade == "A+") return 0;
    else if(grade == "A0") return 1;
    else if(grade == "B+") return 2;
    else if(grade == "B0") return 3;
    else if(grade == "C+") return 4;
    else if(grade == "C0") return 5;
    else if(grade == "D+") return 6;
    else if(grade == "D0") return 7;
    else if(grade == "F") return 8;
    else return 100;
}