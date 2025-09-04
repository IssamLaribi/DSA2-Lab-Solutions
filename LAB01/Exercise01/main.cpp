#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<pair<string, vector<pair<int, int>>>> pairs) {
    for (pair<string, vector<pair<int, int>>> p : pairs) {
        cout << "Word : \"" << p.first << "\"" << endl;
        cout << "Coordinates : ";
        for (pair<int, int> c : p.second){
            cout << "(" << c.first << "," << c.second << ") ";
        } 
        cout << endl << endl;
    }
}

bool contains(vector<string> words, string word) {
    for (string w : words) {
        if (w == word) return true;
    }

    return false;
}

vector<pair<string, vector<pair<int, int>>>> 
findWords(vector<vector<char>> &grid, vector<string> words) {

    vector<pair<string, vector<pair<int, int>>>> result;

    int rows = grid.size();
    int columns = (grid[0]).size();

    // Scanning the rows from left to right
    for (int col = 0; col < columns; col++) { // Looping over columns

        for (int row = 0; row < rows; row++) { // Looping over rows
        vector<pair<int, int>> coords;
        string word = "";
        
            for (int start = col; start < columns; start++) { // Scanning the row along columns
                word += grid[row][start];
                coords.push_back({row, start});
                if (contains(words, word)) {
                    result.push_back({word, coords});
                    break;
                }
            }
        }
    } 

    // Scanning the rows from right to left
    for (int col = columns - 1; col >= 0; col--) { // Looping over columns

        for (int row = 0; row < rows; row++) { // Looping over rows
        vector<pair<int, int>> coords;
        string word = "";
        
            for (int start = col; start >= 0; start--) { // Scanning the row along columns
                word += grid[row][start];
                coords.push_back({row, start});
                if (contains(words, word)) {
                    result.push_back({word, coords});
                    break;
                }
            }
        }
    }


    return result;

}

int main() {
    vector<vector<char>> grid = {
        {'J','S','O','L','U','T','I','S'},
        {'S','U','N','A','R','U','U','A'},
        {'N','E','P','T','U','N','E','T'},
        {'S','O','N','I','E','I','S','U'},
        {'R','C','E','V','T','R','E','R'},
        {'A','H','T','R','A','E','S','N'},
        {'M','M','E','R','C','U','R','Y'}
    };

    vector<string> words = {"EARTH", "JUPITER", "MARS", "MERCURY", 
                            "NEPTUNE", "SATURN", "URANUS", "VENUS"};

    vector<pair<string, vector<pair<int, int>>>> result;

    result = findWords(grid, words);

    print(result);

    return 0;
}
