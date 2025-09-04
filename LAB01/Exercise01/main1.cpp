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

    vector<pair<int, int>> directions = 
        {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1}
        };

    for (pair<int, int> direction : directions) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                string word = "";
                word += grid[row][col];
                vector<pair<int, int>> coords = {{row, col}};
                int step = 0;
                while (!contains(words, word) &&
                        row + step * direction.first >= 0 && 
                        row + step * direction.first < rows && 
                        col + step * direction.second >= 0 && 
                        col + step * direction.second < columns) {
                    step++;
                    if (!(row + step * direction.first >= 0 && 
                        row + step * direction.first < rows && 
                        col + step * direction.second >= 0 && 
                        col + step * direction.second < columns)) break;
                    word += grid[row + direction.first * step][col + direction.second * step];
                    coords.push_back({row + direction.first * step, col + direction.second * step});
                }
                if (contains(words, word)) result.push_back({word, coords});
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

