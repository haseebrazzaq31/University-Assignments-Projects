#include <iostream>
using namespace std;
void inputMatrix(int mat[10][10], int r, int c){
    cout<<"Enter the values for image matrix:"<<endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<"Value for Row "<< i + 1<<" Column " << j + 1<<"= ";
            cin>>mat[i][j];
        }
    }
}
void rotateImage(int oldMat[10][10], int newMat[10][10], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            newMat[c - 1 - j][i] = oldMat[i][j];
        }
    }
}
void printMatrix(int mat[10][10], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<mat[i][j] << " ";
        }
        cout<<endl;
    }
}
int main(){
    int m, n;
    int original[10][10];
    int rotated[10][10];
    int runAgain = 1;
    while(runAgain == 1) {
        cout<<"Enter number of rows (m): ";
        cin>>m;
        cout<<"Enter number of columns (n): ";
        cin>>n;
        if(m > 10||n > 10){
            cout<<"Matrix size cannot exceed 10x10"<<endl;
        }else{
            inputMatrix(original, m, n);
            cout<<"\n Input Matrix:"<<endl;
            printMatrix(original, m, n);
            rotateImage(original, rotated, m, n);
            cout<<"\nResult After 90 Degree Counterclockwise Rotation:"<<endl;
            printMatrix(rotated, n, m);
        }
        cout<<"you want to rotate another image?"<<endl;
        cout<<"Enter 1 for Yes or 0 for No: ";
        cin>>runAgain;
        cout<<endl;
    }
    cout<<"program closed"<<endl;
    return 0;
}