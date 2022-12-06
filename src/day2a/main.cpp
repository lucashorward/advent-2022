#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

// Perhaps not the most elegant, but very little calculation needs to be done per loop
int main() {
    std::unordered_map<std::string, int> result_map = {
        {"AX", 4},
        {"AY", 8},
        {"AZ", 3},
        {"BX", 1},
        {"BY", 5},
        {"BZ", 9},
        {"CX", 7},
        {"CY", 2},
        {"CZ", 6},

    };
    std::cout << "Hello world\n";
    std::string input;
    std::ifstream MyReadFile("input.txt");
    int score = 0;
    std::vector<int> currentNumbers = {};
    while (getline(MyReadFile, input)) {
        char one = input.at(0);
        char two = input.at(2);
        std::string combi = "";
        combi += one;
        combi += two;
        int result = result_map.at(combi);
        score += result;
    }
    MyReadFile.close();
    std::cout << "Done reading file.\n";
    std::cout << "Score is: " << score << "\n";
    return 0;
}