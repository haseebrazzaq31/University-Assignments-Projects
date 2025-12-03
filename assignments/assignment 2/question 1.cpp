#include <iostream>
using namespace std;

int main() {
    int rows, cols, r, c;
    cout << "Enter number of rows:";
    cin >> rows;
    cout << "Enter number of columns:";
    cin >> cols;

    char seats[10][10];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            seats[i][j] = 'F';

    cout << "\nInitial Seat Map:\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << "(" << i+1 << "-" << j+1 << " " << seats[i][j] << ") ";
        cout << "\n";
    }

    for (int booking = 0; booking < 100; booking++) {
        cout << "\nTo reserve a seat, please enter the Row (1-" << rows << ") and Column (1-" << cols << ") OR press 0 0 to Exit:";
        cin >> r >> c;

        if (r == 0 && c == 0) break;

        if (r >= 1 && r <= rows && c >= 1 && c <= cols && seats[r-1][c-1] == 'F') {
            seats[r-1][c-1] = 'R';
            cout << "\nYou have successfully reserved " << r << "-" << c << "\n";
        } else {
            cout << "\nInvalid or already reserved!\n";
        }

        cout << "\nUpdated Seat Map:\n\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (seats[i][j] == 'R')
                    cout << "(R) ";
                else
                    cout << "(" << i+1 << "-" << j+1 << " " << seats[i][j] << ") ";
            }
            cout << "\n";
        }
    }

    cout << "\nFinal Seat Map:\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (seats[i][j] == 'R')
                cout << "(R) ";
            else
                cout << "(" << i+1 << "-" << j+1 << " " << seats[i][j] << ") ";
        }
        cout << "\n";
    }

    return 0;
}
