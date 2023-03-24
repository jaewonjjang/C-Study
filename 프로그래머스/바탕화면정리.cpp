#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int left_x = wallpaper[0].length();
    int left_y = wallpaper.size();
    int right_x = 0;
    int right_y = 0;
    
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].length();j++){
            if(wallpaper[i][j]=='#'){
                left_x = left_x > j ? j : left_x;
                left_y = left_y > i ? i : left_y;
                right_x = right_x < j ? j : right_x;
                right_y = right_y < i ? i : right_y;
            }
        }
    }
    answer.push_back(left_y);
    answer.push_back(left_x);
    answer.push_back(right_y+1);
    answer.push_back(right_x+1);
    
    return answer;
}