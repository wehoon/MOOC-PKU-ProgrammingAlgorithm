// Aggressive cows
//
// 描述
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The
// stalls are located along a straight line at positions x1,...,xN (0 <= xi <=
// 1,000,000,000).
//
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive
// towards each other once put into a stall. To prevent the cows from hurting
// each other, FJ want to assign the cows to the stalls, such that the minimum
// distance between any two of them is as large as possible. What is the largest
// minimum distance? 输入
// * Line 1: Two space-separated integers: N and C
//
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// 输出
// * Line 1: One integer: the largest minimum distance
// 样例输入
// 5 3
// 1
// 2
// 8
// 4
// 9
// 样例输出
// 3
// 提示
// OUTPUT DETAILS:
//
// FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a
// minimum distance of 3.
//
// Huge input data,scanf is recommended.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int64;

int cmp(const void* a, const void* b) {
    int64& a_ = *(int64*)a;
    int64& b_ = *(int64*)b;
    if (a_ < b_)      return -1;
    else if (a_ > b_) return 1;
    return 0;
}

bool isValidD(int64* stalls, int N, int C, const int64& D) {
    int pre = 0, cur = 1;
    int64 distance = stalls[cur] - stalls[pre];
    --C;
    while (C > 0) {
        while (distance < D && cur < N) {
            distance = stalls[++cur] - stalls[pre];
        }
        if (cur >= N) return false;

        pre = cur;
        distance = 0;
        --C;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int N, C;
    scanf("%d %d", &N, &C);
    int64* stalls = new int64[N+1];
    for (int i = 0; i < N; ++i)
        scanf("%lld", &stalls[i]);
    
    qsort(stalls, N, sizeof(int64), cmp);

    int64 L = 1, R = 1000000000 / C;   
    int64 D, curD;
    while (L <= R) {
        curD = L + (R-L)/2;
        if (isValidD(stalls, N, C, curD)) {
            D = curD;
            L = curD + 1;
        } else {
            R = curD - 1;
        }
    }
    printf("%lld", D);
    delete[] stalls;
    return 0;
}
