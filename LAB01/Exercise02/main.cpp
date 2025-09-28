#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void permutateWord(string word, int l, int r) {
    if (l == r) {
        cout << word << endl;
        return;
    }

    for(int i = l; i <= r; i++) {
        swap(word[l], word[i]);
        permutateWord(word, l + 1, r);
        swap(word[l], word[i]);
    }
}


int main() {
    string word = "ABC";

    cout << "All possible permutations of \"" << word << "\"" << endl;
    permutateWord(word, 0, word.size() - 1);
    return 0;
}
