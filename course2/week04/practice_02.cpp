// 派
// 
// 描述
// 我的生日要到了！根据习俗，我需要将一些派分给大家。我有N个不同口味、不同大小的派。有F个朋友会来参加我的派对，每个人会拿到一块派（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。
// 
// 我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。因此所有人拿到的派是同样大小的（但不需要是同样形状的），虽然这样有些派会被浪费，但总比搞砸整个派对好。当然，我也要给自己留一块，而这一块也要和其他人的同样大小。
// 
// 请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。
// 
// 输入
// 第一行包含两个正整数N和F，1 ≤ N, F ≤ 10 000，表示派的数量和朋友的数量。
// 第二行包含N个1到10000之间的整数，表示每个派的半径。
// 输出
// 输出每个人能得到的最大的派的体积，精确到小数点后三位。
// 样例输入
// 3 3
// 4 3 3
// 样例输出
// 25.133

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

#define ESP (0.000001)
#define M_PI (3.14159265358979323846)
#define IS_ZERO(x) ((x) <= ESP && (x) >= ESP)

int cmp(const void* a, const void* b) {
    double& a_ = *(double*)a;
    double& b_ = *(double*)b;
    if (a_ < b_) 
        return -1;
    else if (a_ > b_)
        return 1;
    return 0;
}

bool isValid(double* pies, int n, int f, double d) {
    int i = 0;
    double cur_pie;
    while (i < n && f > 0) {
        cur_pie = pies[i];
        while (cur_pie > d || IS_ZERO(cur_pie - d)) {
            cur_pie -= d;
            --f;
            if (f == 0) return true;
        }
        ++i;
    }
    return false;
}

double pies[10002];

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    int N, F;
    cin >> N >> F;
    for (int i = 0; i < N; ++i) {
        cin >> pies[i];
        pies[i] *= pies[i];
    }
    qsort(pies, N, sizeof(double), cmp);
    ++F;
    double L = 0, R = pies[N-1];
    double D = R, curD;
    while (L < R || IS_ZERO(R-L)) {
        double curD = L + (R-L)/2;
        if (isValid(pies, N, F, curD)) {
            D = curD;
            L = curD + ESP;
        } else {
            R = curD - ESP;
        }
    }
    printf("%.3lf", D * M_PI);

    return 0;
}