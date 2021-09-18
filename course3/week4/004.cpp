#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
public:
    Array2() {}

    Array2(int i, int j) : row(i), col(j), size(i*j) {
        arr = (int*)malloc(sizeof(int) * size);
    }
    ~Array2() {
        if (arr) free(arr);
    }

    Array2& operator=(const Array2& rhs) {
        if (rhs.arr) {
            if (arr == NULL) {
                arr = (int*)malloc(sizeof(int) * rhs.size);
            } else if (col < rhs.size) {
                free(arr);
                arr = (int*)malloc(sizeof(int) * rhs.size);
            }
            memcpy(arr, rhs.arr, sizeof(int) * rhs.size);
            row = rhs.row;
            col = rhs.col;
            size = rhs.size;
        } else {
            if (arr) free(arr);
            row = col = size = 0;
        }
        return *this;
    }

    int* operator[](int i) {
        return &(arr[i*col]);
    }

    int operator()(int i, int j) {
        return arr[i*col+j];
    }

private:
    int* arr;
    int row;
    int col;
    int size;
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}    