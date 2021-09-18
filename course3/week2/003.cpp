#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }

    Complex() : r(0), i(0) {}
    Complex(const char* s) {
        int num = 0;
        while (*s != 'i') {
            if (*s == '+') {
                r = num;
                num = 0;
            } else {
                num = num * 10 + *s - '0';
            }
            ++s;
        }
        i = num;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}