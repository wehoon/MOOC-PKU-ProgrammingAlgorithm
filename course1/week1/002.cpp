#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    scanf("%c", &c);
    for (int i = 1; i <= 5; ++i) {
        int k = abs(3-i);
        int m = 5 - 2*k;
        for (int j = 0; j < k; ++j) printf(" ");
        for (int j = 0; j < m; ++j) printf("%c", c);
        printf("\n");
    }
    return 0;
}
