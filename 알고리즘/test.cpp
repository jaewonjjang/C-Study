#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    queue<pair<int,int> > q;

    pair<int, int> x =  make_pair(3, 4);

    q.push(x);

    cout << q.front().first << q.front().second;

    return 0;
}