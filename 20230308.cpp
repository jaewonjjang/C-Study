// 연산자 오버로딩에 대하여 

// - 연산자 오버로딩은 사용자가 정의한 연산자를 사용할 수 있게 함


#include <iostream>

using namespace std;

class Point {
    int x;
    int y;

public :
    Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
    void Print() const {
        cout << x <<','<< y << endl;
    }
    void operator+(Point arg){
        cout << "operatior+() 함수 호출" << endl;
    }
};

int main() {
    Point p1(2, 3), p2(5, 5);

    p1 + p2;

    return 0;
}