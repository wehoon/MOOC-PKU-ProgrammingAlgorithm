// OpenJudge: http://cxsjsxmooc.openjudge.cn/2019t2summer1/001/
//
// 特殊密码锁
//
// 描述
//   有一种特殊的二进制密码锁，由n个相连的按钮组成（n <30），按钮有凹/凸两种状态，用手按按钮会改变其状态。
//   然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。
//   当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
//   当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
// 输入 
//   两行，给出两个由0、1组成的等长字符串，表示当前目标密码锁状态，其中0代表凹，1代表凸。 
// 输出
//   至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。 
// 样例输入
//   011 
//   000 
// 样例输出 
//   1
//

#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

void Flip(char* status, int i) {
    status[i] = (status[i] == '0') ? '1' : '0';
}

void Switch(char* status, int n, int i) {
    Flip(status, i);
    if (i > 0) Flip(status, i-1);
    if (i < n-1) Flip(status, i+1);
}

int GetSteps(char* src_status, char* dst_status, int n) {
    char res_status[32];
    memcpy(res_status, src_status, sizeof(char) * n);

    int steps = 0;
    for (int i = 1; i < n; ++i) {
        if (res_status[i-1] != dst_status[i-1]) {
            Switch(res_status, n, i);
            ++steps;
        }
    }
    if (res_status[n-1] == dst_status[n-1]) {
        return steps;
    }
    return -2;
}

int main(int argc, char const *argv[])
{
    char src_status[32];
    char dst_status[32];
    cin >> src_status >> dst_status;
    int n = strlen(src_status);

    if (n == 1) {
        return (src_status[0] == dst_status[0]) ? 0 : 1;
    }
    
    int steps1 = GetSteps(src_status, dst_status, n);
    Switch(src_status, n, 0);
    int steps2 = GetSteps(src_status, dst_status, n) + 1;
    
    if (steps1 >= 0 && steps2 >= 0) {
        cout << ((steps1 < steps2) ? steps1 : steps2) << endl;
    } else if (steps1 < 0 && steps2 < 0) {
        cout << "impossible" << endl;
    } else {
        cout << ((steps1 > steps2) ? steps1 : steps2) << endl;
    }
    
    return 0;
}
