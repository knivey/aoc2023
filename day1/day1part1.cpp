#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    string file = "part1sample.txt";
    if(argc > 1)
        file = argv[1];
    fstream input(file);
    if (input.fail()) {
        cout << "Couldn't open input\n";
        return 1;
    }
    string line;
    char first, last;
    int sum = 0;
    while(getline(input, line)) {
        for(auto c : line) {
            if(isdigit(c)) {
                if(first == '\0')
                    first = c;
                last = c;
            }
        }
        char num[3] = {first, last, '\0'};
        sum += atoi(num);
        first = '\0';
    }
    cout << sum << endl;
    return 0;
}
