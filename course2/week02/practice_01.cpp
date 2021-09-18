// OpenJudge: http://cxsjsxmooc.openjudge.cn/2019t2summer2/001/
//
// 全排列
// 
// 描述
//   给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。
// 我们假设对于小写字母有 'a' < 'b' < ... < 'y' <
// 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。
//
// 输入
//   输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
// 输出
//   输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：
// 已知 S = s1s2... sk, T = t1t2... tk，则S < T 等价于，存在p(1 <= p <= k) ，
// 使得 s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
//
// 样例输入
//   abc
// 样例输出
//   abc
//   acb
//   bac
//   bca
//   cab
//   cba

#include <iostream>
#include <cstring>
#include <memory.h>
using namespace std;

const int MAX_LEN = 7;

void Permutation(char* str, int start, int end) {
    if (start >= end) {
        cout << str << endl;
        return;
    }

    Permutation(str, start+1, end);
    char cur_str[MAX_LEN];
    memcpy(cur_str, str, sizeof(char) * MAX_LEN);
    for (int i = start+1; i <= end; ++i) {
        char tmp = cur_str[start];
        cur_str[start] = cur_str[i];
        cur_str[i] = tmp;
        Permutation(cur_str, start + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    char str[MAX_LEN];
    cin >> str;
    int n = strlen(str);
    Permutation(str, 0, n-1);
    return 0;
}
