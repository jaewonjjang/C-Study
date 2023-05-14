#include <iostream>
#include <vector>

using namespace std;


void quickSort(int*, int, int);

int main() {
    int jaewon[10] = {4, 5, 6, 7, 8, 1, 2, 3, 9, 10};
    quickSort(jaewon, 0, 9);

    for(int i=0;i<10;i++) {
        cout << jaewon[i] << " ";
    }
    return 0;
}

void quickSort(int* data, int start, int end) {
    if(start >= end) {
        return;
    }

    int key = start;
    int left = start+1;
    int right = end;
    int temp;
    while(left <= right) {
        while(data[left] <= data[key]) {
            left++;
        }
        while(right > start && data[right] >= data[key]) {
            right--;
        }

        if(left > right) {
            temp = data[right];
            data[right] = data[key];
            data[key] = temp;
        }
        else {
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
    }
    quickSort(data, start, right-1);
    quickSort(data, right+1, end);
}