#include <iostream>

using namespace std;

class Point {
    public :
        int x;
        int y;
        Point(int _x=0, int _y=0):x(_x), y(_y) {}
        void Print() const {
        	cout << x <<','<< y << endl;
        }
};

Point addPoint(Point a, Point b);

int main(){
    Point a(1, 1), b(2, 3);

    addPoint(a, b).Print();

    return 0;
}

Point addPoint(Point a, Point b){
    Point result(0, 0);

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}