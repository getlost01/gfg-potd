#include <iostream>
#include <vector>
#include <numeric>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(std::string s) {
        std::vector<int> f(26, 0);

        for (auto i : s) {
            char cur = std::tolower(i);

            if (cur >= 'a' && cur <= 'z') {
                f[cur - 'a'] = 1;
            }
        }

        return std::accumulate(f.begin(), f.end(), 0) == 26;
    }
};

int main() {
    Solution solution;

    // Input from the user
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    // Check if the input is a pangram
    bool isPangram = solution.checkPangram(userInput);

    // Output the result
    if (isPangram) {
        std::cout << 1 << endl;
    } else {
        std::cout << 0 << endl;
    }

    return 0;
}
