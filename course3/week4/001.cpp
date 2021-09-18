#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
    
    void Copy(const char* s) {
        if (s) {
			if (p == NULL) {
				p = new char[strlen(s) + 1];
			}else if (strlen(p) < strlen(s)) {
                delete p;
                p = new char[strlen(s) + 1];
            }
            strcpy(p, s);
        } else {
            if (p) {
				delete p;
            	p = NULL;
			}
        }
    }

    MyString(const MyString& rhs) {
        if (rhs.p == p) return;
        if (rhs.p) {
            p = new char[strlen(rhs.p) + 1];
            strcpy(p, rhs.p);
        } else
            p = NULL;
    }

    MyString& operator=(const MyString& rhs) {
        if (rhs.p == p) return *this;
        if (rhs.p == NULL) {
            if (p) delete p;
            p = NULL;
        } else {
            if (strlen(p) < strlen(rhs.p)) {
                delete p;
                p = new char[strlen(rhs.p) + 1];
            }
            strcpy(p, rhs.p);
        }
        return *this;
	}

    friend ostream& operator<<(ostream& os, const MyString& ms);

};

ostream& operator<<(ostream& os, const MyString& ms) {
	os << ms.p;
	return os;
}

class _Invalid {
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}