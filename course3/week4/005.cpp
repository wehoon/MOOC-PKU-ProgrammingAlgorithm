#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 110;
class CHugeInt {
public:
	CHugeInt() : len(0) {}
    explicit CHugeInt(int n) {
		if (n == 0) {
			num[0] = '0';
			len = 1;
			return;
		}
		len = 0;
		while (n > 0) {
			num[len++] = (n % 10) + '0';
			n /= 10;
		}
	}
    CHugeInt(const char* s) {
		int n = strlen(s);
		for (int i = 0; i < n; ++i) {
			num[i] = s[n-i-1];
		}
		len = n;
	}
    CHugeInt(const CHugeInt& rhs) {
		len = rhs.len;
		memcpy(num, rhs.num, len);
	}

    CHugeInt& operator++() {
		int ca = 1, i = 0;
		while (ca == 1) {
			int cur = (num[i] - '0') + ca;
			num[i] = '0' + (cur % 10);
			ca = cur / 10;
			++i;
		}
		if (i >= len) len = i;
		return *this;
	}
    CHugeInt operator++(int) {
		CHugeInt cur(*this);
		++(*this);
		return cur;
	}

    CHugeInt operator+(const CHugeInt& rhs) {
		CHugeInt res;
		int ca = 0, i = 0;
		while (i < len || i < rhs.len) {
			int left = (i < len) ? (num[i] - '0') : 0;
			int right = (i < rhs.len) ? (rhs.num[i] - '0') : 0;
			int cur = left + right + ca;
			res.num[i] = '0' + cur % 10;
			ca = cur / 10;
			++i;
		}
		if (ca == 1) {
			res.num[i++] = '1';
		}
		res.len = i;

		return res;
	}
    CHugeInt& operator+=(int n) {
		if (n == 0) return *this;
		int i = 0;
		while (n > 0) {
			int left = (i < len) ? num[i] - '0' : 0;
			int cur = n % 10 + left;
			n = n / 10 + cur / 10;
			num[i] = '0' + cur % 10;
			++i;
		}
		if (i > len) len = i;
		return *this;
	}

    friend CHugeInt operator+(const CHugeInt& lhs, int rhs);
    friend CHugeInt operator+(int lhs, const CHugeInt& rhs);
    friend ostream& operator<<(ostream& os, const CHugeInt& rhs);

private:
    char num[210];
    int len;
};

CHugeInt operator+(const CHugeInt& lhs, int rhs) {
	CHugeInt res(lhs);
	res += rhs;
	return res;
}

CHugeInt operator+(int lhs, const CHugeInt& rhs) {
	return rhs + lhs;
}

ostream& operator<<(ostream& os, const CHugeInt& rhs) {
	for (int i = rhs.len - 1; i >= 0; --i) {
		os << rhs.num[i];
	}
	return os;
}

class _Invalid{
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}