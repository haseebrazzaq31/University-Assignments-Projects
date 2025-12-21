#include <iostream>
using namespace std;
void getMatrix(int m[10][10], int n){
    cout<<"enter the numbers for your " << n << "x" << n << " grid"<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter value for row " << i << " and column " << j << ": ";
            cin>>m[i][j];
        }
    }
}
void showNormal(int m[10][10], int n){
    cout<<endl;
    cout<<"Your original matrix looks like this:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<m[i][j] << "\t";
        }
        cout<<endl;
    }
}
void printSnake(int m[10][10], int n){
    cout<<"The Snake Pattern output is:" << endl;
    for(int i = 0; i < n; i++){
        int isOddRow = i % 2;
        for(int j = 0; j < n; j++){
            int column=(1 - isOddRow) * j + isOddRow * (n - 1 - j);
            cout<<m[i][column] << " ";
        }
    }
    cout<< endl;
}
int main(){
    int mat[10][10];
    int size;
    cout<<"Enter the size of the square matrix: ";
    cin>>size;
    getMatrix(mat, size);
    showNormal(mat, size);
    printSnake(mat, size);
    return 0;
}