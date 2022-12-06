#include <iostream>
#include <fstream>
#include <vector>

// Ugly way of doing it, but it works, and in 1 pass
int main() {
    std::string input;
    std::ifstream MyReadFile("input.txt");
    int highest = INT32_MIN;
    int second = INT32_MIN;
    int third = INT32_MIN;
    std::vector<int> currentNumbers = {};
    while (getline(MyReadFile, input)) {
        if (input.empty()) {
            int total = 0;
            for (int i : currentNumbers) {
                total += i;
            }
            currentNumbers.clear();
            if (total > highest) {
                third = second;
                second = highest;
                highest = total;
            } else if (total > second) {
                third = second;
                second = total;
            } else if (total > third) {
                third = total;
            }
        } else {
            int convert = std::stoi(input);
            currentNumbers.push_back(convert);
        }
    }
    MyReadFile.close();
    std::cout << "Done reading file.\n";
    std::cout << "Highest number is: " << highest << "\n";
    std::cout << "Second number is: " << second << "\n";
    std::cout << "Third number is: " << third << "\n";
    int result = highest + second + third;
    std::cout << "Total highest number is: " << result << "\n";
    return 0;
}