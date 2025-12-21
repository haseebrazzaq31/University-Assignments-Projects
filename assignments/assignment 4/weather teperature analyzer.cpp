#include <iostream>
#include <iomanip>
using namespace std;
void inputtmp(double temp[7][4]) {
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << " temperature data:" << endl;
        for (int j = 0; j < 4; j++) {
            cout << " reading " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }
}
void checkingforhal(double temp[7][4]) {
    double highest = temp[0][0];
    double lowest = temp[0][0];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (temp[i][j] > highest) {
                highest = temp[i][j];
            }
            if (temp[i][j] < lowest) {
                lowest = temp[i][j];
            }
        }
    }
    cout << endl;
    cout << "Highest Temperature: " << highest << endl;
    cout << " Lowest Temperature: " << lowest << endl;
    cout << "-----------------------------------" << endl;
}
void Averagecalculation(double temp[7][4], double avgs[7]) {
    for (int i = 0; i < 7; i++) {
        double sum = 0;
        for (int j = 0; j < 4; j++) {
            sum = sum + temp[i][j];
        }
        avgs[i] = sum / 4.0;
    }
}
void displayResults(double temp[7][4], double avgs[7]) {
    cout << endl;
    cout << "WEATHER ANALYSIS REPORT" << endl;
    cout << "Day\tT1\tT2\tT3\tT4\tAverage" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < 7; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 4; j++) {
            cout << temp[i][j] << "\t";
        }
        cout << fixed << setprecision(2) << avgs[i] << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}
int main() {
    double weeklyTemps[7][4];
    double dailyAverages[7];
    cout << "enter the readings for the week." << endl;
    cout << "-----------------------------------" << endl;
    inputtmp(weeklyTemps);
    Averagecalculation(weeklyTemps, dailyAverages);
    displayResults(weeklyTemps, dailyAverages);
    checkingforhal(weeklyTemps);
    cout << "Analysis complete" << endl;
    return 0;
}