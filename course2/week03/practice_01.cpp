// http://cxsjsxmooc.openjudge.cn/2019t2summer3/001/
//
// Boolean Expressions
//
// 描述
// The objective of the program you are going to produce is to evaluate boolean
// expressions as the one shown next: Expression: ( V | V ) & F & ( F | V )
//
// where V is for True, and F is for False. The expressions may include the
// following operators: ! for not , & for and, | for or , the use of parenthesis
// for operations grouping is also allowed.
//
// To perform the evaluation of an expression, it will be considered the
// priority of the operators, the not having the highest, and the or the lowest.
// The program must yield V or F , as the result for each expression in the
// input file.
//
// 输入
// The expressions are of a variable length, although will
// never exceed 100 symbols. Symbols may be separated by any number of spaces or
// no spaces at all, therefore, the total length of an expression, as a number
// of characters, is unknown.
//
// The number of expressions in the input file is variable and will never be
// greater than 20. Each expression is presented in a new line, as shown below.
//
// 输出
// For each test expression, print "Expression " followed by its sequence
// number, ": ", and the resulting value of the corresponding test expression.
// Separate the output for consecutive test expressions with a new line.
//
// Use the same format as that shown in the sample output shown below.
//
// 样例输入
// ( V | V ) & F & ( F| V)
// !V | V & V & !F & (F | V ) & (!F | F | !V & V)
// (F&F|V|!V&!F&!(F|F&V))
//
// 样例输出
// Expression 1: F
// Expression 2: V
// Expression 3: V

// expression: ws term ws ([&|\|] ws term ws)
// term: (ws !)+ ws factor ws
// factor: ws [VF] ws | ws ( ws expression ws ) ws
// ws: whitespace

#include <iostream>
#include <cstdio>

using namespace std;

bool expression_value(char** exp);
bool term_value(char** exp);
bool factor_value(char** exp);

void skip_whitespace(char** exp);

int main(int argc, char const* argv[]) {
    char* buf = (char*)malloc(200);
    char* exp = buf;
    int idx = 1;
    while (gets(exp)) {
        cout << "Expression " << idx++ << ": ";
        cout << (expression_value(&exp) ? "V" : "F") << endl;
        exp = buf;
    }

    return 0;
}

bool expression_value(char** exp) {
    skip_whitespace(exp);
    bool result = term_value(exp);
    bool more = true;
    while (more) {
        skip_whitespace(exp);
        if (**exp == '&' || **exp == '|') {
            char op = **exp;
            ++(*exp);
            skip_whitespace(exp);
            bool value = term_value(exp);
            if (op == '&') result &= value;
            else result |= value;
        } else {
            more = false;
        }
    }
    return result;
}

bool term_value(char** exp) {
    skip_whitespace(exp);
    bool neg = false;
    while (**exp == '!') {
        neg = !neg;
        ++(*exp);
        skip_whitespace(exp);
    }
    skip_whitespace(exp);
    bool result = factor_value(exp) ^ neg;
    return result;
}

bool factor_value(char** exp) {
    bool result;
    skip_whitespace(exp);
    if (**exp == '(') {
        ++(*exp);
        skip_whitespace(exp);
        result = expression_value(exp);
        skip_whitespace(exp);
        ++(*exp);
    } else if (**exp == 'V') {
        result = true;
        ++(*exp);
    } else if (**exp == 'F') {
        result = false;
        ++(*exp);
    }
    return result;
}

void skip_whitespace(char** exp) {
    while (**exp == ' ') ++(*exp);
}