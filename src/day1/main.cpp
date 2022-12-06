#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::cout << "Hello world\n";
    std::string input;
    std::ifstream MyReadFile("input.txt");
    int highest = INT32_MIN;
    std::vector<int> currentNumbers = {};
    while (getline(MyReadFile, input)) {
        if (input.empty()) {
            std::cout << "newline detected!\n";
            int total = 0;
            for (int i : currentNumbers) {
                total += i;
            }
            std::cout << "Total of the numbers is: " << total << "\n";
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
    std::cout << "Highest number is: " << highest << "\n";
    return 0;
}