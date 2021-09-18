#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> soldier_lifes;
int min_life;
string red_order[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
string blue_order[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};
string in_order[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};

class Command {
   public:
    string name;
    int total_life;
    int index;
    int num;
    bool isStoped;
    map<string, int> soldier_num;

    Command(const string& name_) : name(name_) {}

    void init(int life) {
        total_life = life;
        num = 0;
        index = 0;
        isStoped = false;
        for (auto& item : soldier_num) { item.second = 0; }
    }

    void Product(int hour, const string* order) {
        if (total_life < min_life) {
            printf("%03d %s headquarter stops making warriors\n", hour, name.c_str());
            isStoped = true;
            return;
        }
        while (total_life < soldier_lifes[order[index]]) {
            index = (index + 1) % 5;
        }
        const string& sname = order[index];
        total_life -= soldier_lifes[sname];
        ++(soldier_num[sname]);
        ++num;
        index = (index+1) % 5;
        printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
               hour, name.c_str(), sname.c_str(), num, soldier_lifes[sname],
               soldier_num[sname], sname.c_str(), name.c_str());
    }
};

int main(int argc, char const* argv[]) {
    int N;
    int hour;
    int total_life, soldier_life;
    Command red_command("red");
    Command blue_command("blue");
    cin >> N;
    for (int n = 1; n <= N; ++n) {
        cin >> total_life;
        red_command.init(total_life);
        blue_command.init(total_life);
        hour = 0;
        min_life = INT_MAX;
        for (int i = 0; i < 5; ++i) {
            cin >> soldier_life;
            soldier_lifes[in_order[i]] = soldier_life;
            if (soldier_life < min_life) min_life = soldier_life;
        }

        printf("Case:%d\n", n);
        while (!red_command.isStoped && !blue_command.isStoped) {
            red_command.Product(hour, red_order);
            blue_command.Product(hour, blue_order);
            ++hour;
        }
        while (!red_command.isStoped) {
            red_command.Product(hour, red_order);
            ++hour;
        }
        while (!blue_command.isStoped) {
            blue_command.Product(hour, blue_order);
            ++hour;
        }
    }

    return 0;
}
