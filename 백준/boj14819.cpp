#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


vector<vector<int>> t;

int K, rot[101], direction[101];
bool check[4] = { false };

void input() {
   vector<int> temp = { 0 };
   t.push_back(temp);
   for (int i = 1; i <= 4; i++) {
      vector<int> vtemp(8);
      int itemp;
      cin >> itemp;
      for (int j = 7; j >= 0; j--) {
         vtemp[j] = itemp % 10;
         itemp /= 10;

      }
      t.push_back(vtemp);
   }
   cin >> K;
   for (int i = 0; i < K; i++) {
      cin >> rot[i] >> direction[i];
   }
}

void init() {
   memset(check, false, sizeof(bool) * 4);
   for (int i = 1; i <= 3; i++) {
      if (t[i][2] == t[i + 1][6]) {
         check[i] = true;
      }
   }
}

vector<int> rotate_right(vector<int> a) {
   a.insert(a.begin(), a.end() - 1, a.end());
   a.pop_back();

   return a;
}

vector<int> rotate_left(vector<int> a) {
   a.insert(a.end(), a.begin(), a.begin()+1);
   a.erase(a.begin());

   return a;
}

void rotation() {
   for (int i = 0; i < K; i++) {
      int rtemp = rot[i];
      int dtemp = direction[i];
      if (dtemp == 1) {
         t[rtemp] = rotate_right(t[rtemp]);
      }
      else {
         t[rtemp] = rotate_left(t[rtemp]);
      }
      
      while (rtemp >= 2) {
         if (check[rtemp - 1]) {
            break;
         }
         else {
            dtemp *= -1;
            if (dtemp == 1) {
               t[rtemp - 1] = rotate_right(t[rtemp - 1]);
            }
            else {
               t[rtemp - 1] = rotate_left(t[rtemp - 1]);
            }
         }
         rtemp--;
      }

      rtemp = rot[i];
      dtemp = direction[i];

      while (rtemp <= 3) {   
         if (check[rtemp]) {
            break;
         }
         else {
            dtemp *= -1;
            if (dtemp == 1) {
               t[rtemp + 1] = rotate_right(t[rtemp + 1]);
            }
            else {
               t[rtemp + 1] = rotate_left(t[rtemp + 1]);
            }
         }
         rtemp++;
      }
      init();
   }
}
int main() {
   input();

   init();

   rotation();
   int result = 0;

   result = t[1][0] * 1 + t[2][0] * 2 + t[3][0] * 4 + t[4][0] * 8;

   cout << result;
   return 0;
}