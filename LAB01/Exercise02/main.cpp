#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

    

int main() {
    string word = "ABC";

    cout << "All possible permutations of \"" << word << "\"" << endl;
    permutateWord(word, 0, word.size() - 1);
    return 0;
}
