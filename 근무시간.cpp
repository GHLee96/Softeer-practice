#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class People {
   private:
    int work_time;

   public:
    People() { work_time = 0; }
    void add_work_time(int time) { work_time += time; }

    int get_time(string str) {
        int hour, min;
        int result;
        hour = std::stoi(str.substr(0, 2));
        min = std::stoi(str.substr(3));
        result = hour * 60 + min;
        return result;
    }

    int get_work_time() { return work_time; }
};

int main(void) {
    int start;
    int end;
    int work_day = 5;
    string str1;
    string str2;
    string separator = ":";

    People data;

    for (int i = 0; i < work_day; i++) {
        cin >> str1;
        cin >> str2;

        start = data.get_time(str1);
        end = data.get_time(str2);
        data.add_work_time(end - start);
    }
    cout << data.get_work_time();
    return 0;
}