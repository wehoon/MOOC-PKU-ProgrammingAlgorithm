// Openjudge: http://cxsjsxmooc.openjudge.cn/2019t2summer2/002/
//
// 2的幂次方表示
// 
// 描述
// 任何一个正整数都可以用2的幂次方表示。例如：
//    137=2^7+2^3+2^0
// 同时约定方次用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：
//    2(7)+2(3)+2(0)
// 进一步：7=2^2+2+2^0（2^1用2表示）
//    3=2+2^0
// 所以最后137可表示为：
//    2(2(2)+2+2(0))+2(2+2(0))+2(0)
// 又如：
//    1315=2^10+2^8+2^5+2+1
// 所以1315最后可表示为：
//    2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//
// 输入
//   一个正整数n（n≤20000）。
// 输出
//   一行，符合约定的n的0，2表示（在表示中不能有空格）。
// 样例输入
//   137
// 样例输出
//   2(2(2)+2+2(0))+2(2+2(0))+2(0)

#include <iostream>
#include <string>
using namespace std;

string PowerByTwo(int num) {
    if (num == 0) return "0";
    if (num == 1) return "2(0)";
    if (num == 2) return "2";

    int pow = 0;
    string exp;
    while (num > 0) {
        if (num & 1 == 1) {
            if (exp != "") exp = "+" + exp;
            if (pow == 1) {
                exp = "2" + exp;
            } else {
                exp = "2(" + PowerByTwo(pow) + ")" + exp;
            }
        }
        ++pow;
        num = num >> 1;
    }
    return exp;
}

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    cout << PowerByTwo(num) << endl;
    return 0;
}
