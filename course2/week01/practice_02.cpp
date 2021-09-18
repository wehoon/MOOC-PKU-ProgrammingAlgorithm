// OpenJudge: http://cxsjsxmooc.openjudge.cn/2019t2summer1/002/
//
// 拨钟问题
//
// 描述
// 有9个时钟，排成一个3 * 3的矩阵。
//
//    | ------- | | ------- | | ------- | 
//    |         | |         | |    |    | 
//    | ---O    | | ---O    | |    O    |
//    |         | |         | |         |
//    | ------- | | ------- | | ------- |
//         A           B           C
//
//    | ------- | | ------- | | ------- |
//    |         | |         | |         |
//    |    O    | |    O    | |    O    |
//    |    |    | |    |    | |    |    |
//    | ------- | | ------- | | ------- |
//         D           E           F
//
//    | ------- | | ------- | | ------- |
//    |         | |         | |         |
//    |    O    | |    O--- | |    O    |
//    |    |    | |         | |    |    |
//    | ------- | | ------- | | ------- |
//         G           H           I
//
// 现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。
// 如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。
//
// 移动 影响的时钟
//  1     ABDE 
//  2     ABC 
//  3     BCEF 
//  4     ADG
//  5     BDEFH 
//  6     CFI 
//  7     DEGH 
//  8     GHI 
//  9     EFHI
//
// 输入
//   9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。
//   其中，0 = 12点、1 = 3点、2 = 6点、3 = 9点。 
// 输出
//   输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。 
// 样例输入
//   3 3 0 2 2 2 2 1 2 
// 样例输出 
//   4 5 8 9

#include <iostream>
#include <memory.h>
using namespace std;

static int OPTIONS[9][9] = {
    {1, 1, 0, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0}, 
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0}, 
    {0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0}, 
    {0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1}
};

void Move(int status[], int option[], int times) {
    if (times <= 0) return;
    for (int i = 0; i < 9; ++i) {
        status[i] += (option[i] * times);
        status[i] %= 4;
    }
}

bool isValidOrder(int status[], int order[]) {
    for (int i = 0; i < 9; ++i) {
        Move(status, OPTIONS[i], order[i]);
    }
    for (int i = 0; i < 9; ++i) {
        if (status[i] != 0) return false;
    }
    return true;
}

void NextOrder(int order[]) {
    int ca = 1;
    int i = 0;
    while (ca == 1 && i < 8) {
        order[i] += ca;
        if (order[i] >= 4) {
            ca = 1;
            order[i] %= 4;
        } else {
            ca = 0;
        }
        ++i;
    }
    if (ca == 1) order[8] += 1;
}

void PrintOrder(int order[]) {
    bool start_flag = false;
    for (int i = 0; i < 9; ++i) {
        while (order[i] > 0) {
            if (start_flag) cout << " ";
            cout << i + 1;
            if (!start_flag) start_flag = true;
            order[i] -= 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int status[10];
    for (int i = 0; i < 9; ++i){
        cin >> status[i];
    }

    int order[10] = {0};
    while (order[8] < 4) {
        int status_[10];
        memcpy(status_, status, sizeof(int) * 10);
        NextOrder(order);
        if (isValidOrder(status_, order)) {
            PrintOrder(order);
            break;
        }
    }

    return 0;
}
