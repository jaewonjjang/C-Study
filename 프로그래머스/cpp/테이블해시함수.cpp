#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int c;

bool comfunc(vector<int>, vector<int>);

bool comfunc(vector<int> a, vector<int> b) {
    if(a[c-1] == b[c-1]) {
        return a[0] > b[0];
    }
    else {
        return a[c-1] < b[c-1];
    }
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int result = 0;
    c = col;
    vector<int> temp;
    sort(data.begin(), data.end(), comfunc);
    
    for(int i=0;i<data.size();i++) {
        for(int j=0;j<data[0].size();j++) {
            result += (data[i][j] % (i+1));
        }
        temp.push_back(result);
        result = 0;
    }
    
    answer = temp[row_begin-1];
    int j;
    for(j = row_begin;j <row_end;j++) {
        answer ^= temp[j];
    }
    return answer;
}