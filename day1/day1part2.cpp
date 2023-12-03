#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>

using namespace std;

map<string, string> digits = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
        {"1", "1"},
        {"2", "2"},
        {"3", "3"},
        {"4", "4"},
        {"5", "5"},
        {"6", "6"},
        {"7", "7"},
        {"8", "8"},
        {"9", "9"},
};

int main(int argc, char* argv[]) {
    string file = "part2sample.txt";
    if(argc > 1)
        file = argv[1];
    fstream input(file);
    if (input.fail()) {
        cout << "Couldn't open input\n";
        return 1;
    }
    string line;
    long sum = 0;
    while(getline(input, line)) {
        string first, last;
        size_t i = line.length() + 1;
        for(auto [digit, val] : digits) {
            auto where = line.find(digit);
            if(where < i) {
                i = where;
                first = val;
            }
        }
        i = 0;
        for(auto [digit, val] : digits) {
            auto where = line.rfind(digit);
            if(where != string::npos && where >= i) {
                i = where;
                last = val;
            }
        }
        sum += stoul(first + last);
    }
    cout << sum << endl;
    return 0;
}
