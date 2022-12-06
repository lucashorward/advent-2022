#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::string input;
    std::ifstream MyReadFile("input.txt");
    int highest = INT32_MIN;
    std::vector<int> currentNumbers = {};
    std::cout << "Reading file.\n";
    while (getline(MyReadFile, input)) {
        if (input.empty()) {
            int total = 0;
            for (int i : currentNumbers) {
                total += i;
            }
            currentNumbers.clear();
            if (total > highest) {
                highest = total;
            }
        } else {
            int convert = std::stoi(input);
            currentNumbers.push_back(convert);
        }
    }
    MyReadFile.close();
    std::cout << "Done reading file.\n";
    std::cout << "Highest number is: " << highest << ".\n";
    return 0;
}