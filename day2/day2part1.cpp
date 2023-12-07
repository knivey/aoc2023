#include <iostream>
#include <string>
#include <fstream>
#include <re2/re2.h>
#include <absl/strings/string_view.h>

using namespace std;

int main(int argc, char* argv[]) {
    string file = "sample1.txt";
    if (argc > 1)
        file = argv[1];
    fstream input(file);
    if (input.fail()) {
        cout << "Couldn't open input\n";
        return 1;
    }

    string line;
    int sum = 0;

    RE2 gameRE("Game (\\d+): (.*)");
    RE2 setsRE(" *([^;]+)(?:;|$)");
    RE2 reeeRE("(\\d+) (red|green|blue),? ?");
    while(getline(input, line)) {
        bool goodgame = true;
        int game;
        string sets;
        bool matched = RE2::FullMatch(line, gameRE, &game, &sets);
        if(!matched)
            continue;

        absl::string_view setssv(sets);
        string set;
        while(RE2::Consume(&setssv, setsRE, &set)) {
            auto rolls = absl::string_view(set);
            int cubes;
            string color;
            while(RE2::Consume(&rolls, reeeRE, &cubes, &color)) {
                if(color == "red" && cubes > 12)
                    goodgame = false;
                if(color == "green" && cubes > 13)
                    goodgame = false;
                if(color == "blue" && cubes > 14)
                    goodgame = false;
            }
        }

        if(goodgame) {
            sum += game;
        }
    }

    cout << sum << endl;
}