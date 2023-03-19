#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class student {
    int age;
    int height;
    int stID;
    public : 
        student(int _age = 0, int _height = 0, int _stID = 0) : age(_age), height(_height), stID(_stID){}
        int getAge() const { return age; }
        int getHeight() const { return height; }
        void hello() const { cout << "hello I'm " << getAge() << " " << getHeight() << endl; }
};


bool AgeCompare(student s1, student s2){
    return s1.getAge() < s2.getAge();
}

bool HeightCompare(student s1, student s2) {
    return s1.getHeight() < s2.getHeight();
}

int main() {
    student jaewon(32, 178, 00000000);
    student heeju(29, 168, 00000001);

    student s1 = max(jaewon, heeju, AgeCompare);
    student s2 = min(jaewon, heeju, HeightCompare);

    s1.hello();
    s2.hello();

    return 0;
}