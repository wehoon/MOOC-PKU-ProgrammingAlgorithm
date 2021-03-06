// 月度开销
//
// 描述
// 农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。他计算出并记录下了接下来
// N (1 ≤ N ≤ 100,000) 天里每天需要的开销。
//
// 约翰打算为连续的M (1 ≤ M ≤ N)
// 个财政周期创建预算案，他把一个财政周期命名为fajo月。每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。
//
// 约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。
//
//
//
// 输入
// 第一行包含两个整数N,M，用单个空格隔开。
// 接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
// 输出
// 一个整数，即最大月度开销的最小值。
// 样例输入
// 7 5
// 100
// 400
// 300
// 100
// 500
// 101
// 400
// 样例输出
// 500
// 提示
// 若约翰将前两天作为一个月，第三、四两天作为一个月，最后三天每天作为一个月，则最大月度开销为500。其他任何分配方案都会比这个值更大。

#include <iostream>
using namespace std;

typedef long long int64;

int money[100001];

bool isValid(int money[], int n, int m, int64 d) {
    int64 sum = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + money[i] > d) {
            ++t;
            sum = money[i];
        } else {
            sum += money[i];
        }
    }
    return t >= m;
}

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    int N, M;
    int64 low = 0, high = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> money[i];
        if (money[i] > low) low = money[i];
        high += money[i];
    }

    int64 mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (isValid(money, N, M, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << mid;

    return 0;
}