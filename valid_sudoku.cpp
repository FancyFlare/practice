#include <iostream>
#include <vector>
using namespace std;
/*
 * 36. Valid Sudoku
 */
bool isValidSudoku(vector<vector<char> >& board) {
    if (board.size() != 9) {
        return false;
    }
    char line[9];
    //rows
    for (int i = 0; i < 9; i ++) {
        if (board[i].size() != 9){
            return false;
        }
        memset (line, '\0', 9);
        for (int j = 0; j < 9; j ++){
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '0' -1;
            if (line[num] == board[i][j]) {
                cout << "return 24\n";
                return false;
            }
            line[num] = board[i][j];
        }
    }

    //columns
    for (int j = 0; j < 9; j ++) {
        memset (line, '\0', 9);
        cout << string(line);
        for (int i = 0; i < 9; i ++){
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '0' - 1;
            if (line[num] == board[i][j]) {
                cout << "number is " << num << " line[num] is " << line[num] << " return 40\n";
                return false;
            }
            line[num] = board[i][j];
        }
    }

    //subcube
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            memset (line, '\0', 9);
            //board[i*3][j*3]
            for (int ii = i*3; ii < i*3+3; ii ++){
                for (int jj = j*3; jj < j*3+3; jj ++){
                    if (board[ii][jj] == '.'){
                        continue;
                    }
                    int num = board[ii][jj] - '0' -1;
                    if (line[num] == board[ii][jj]) {
                        cout << "return 59 \n";
                        return false;
                    }
                    line[num] = board[ii][jj];
                }
            }
        }
    }
    return true;
}
/*
int main(int argc, char* argv[]) {
    string strs[] = {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};
    vector<vector<char> > input;
    for (int i = 0; i < 9; i ++){
        char* chars = (char*)strs[i].c_str();
        vector<char> vec(chars, chars+9);
        input.push_back(vec);
    }
    //vector<vector<char> > vec(arr, arr+9);
    cout << isValidSudoku(input);

}
*/
