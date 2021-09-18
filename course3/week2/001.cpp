#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Student {
private:
    string name_;
    int age_;
    int num_;
    int score_1st_;
    int score_2nd_;
    int score_3rd_;
    int score_4th_;
    double score_avg_;

public:
    void input() {
        char c;
        while (scanf("%c", &c) != EOF) {
            if (c == ',') break;
            name_ += c;
        }
        scanf("%d,%d,%d,%d,%d,%d", 
            &age_, &num_, &score_1st_, &score_2nd_, &score_3rd_, &score_4th_);
    }

    void calculate() {
        score_avg_ = score_1st_ + score_2nd_ + score_3rd_ + score_4th_;
        score_avg_ /= 4;
    }

    void output() {
        cout << name_ << ",";
        cout << age_ << ",";
        cout << num_ << ",";
        cout << score_avg_;
    }
};

int main() {
    Student student;      // 定义类的对象
    student.input();      // 输入数据
    student.calculate();  // 计算平均成绩
    student.output();     // 输出数据
}