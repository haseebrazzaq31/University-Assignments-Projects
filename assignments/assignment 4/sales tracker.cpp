#include<iostream>
using namespace std;
void inputSales(double s[5][7]){
    for(int i = 0; i < 5; i++){
        cout<<"Enter sales for Product "<<i + 1 <<"=" << endl;
        for(int j = 0; j < 7; j++){
            cout<<" Day "<<j + 1<<"= ";
            cin>>s[i][j];
        }
        cout<<endl;
    }
}
void Revenuecalculate(double s[5][7], double totalRev[5]){
    for(int i = 0; i < 5; i++){
        double sum= 0;
        for(int j = 0; j < 7; j++){
            sum=sum + s[i][j];
        }
        totalRev[i]=sum;
    }
}
void findMaxProduct(double totalRev[5]){
    double maxVal=totalRev[0];
    int productNum = 1;
    for (int i = 1; i < 5; i++){
        if(totalRev[i] > maxVal){
            maxVal = totalRev[i];
            productNum = i + 1;
        }
    }
    cout<<"Product "<<productNum <<" had the most revenue with: "<<maxVal<<endl;
}
void BestDay(double s[5][7]){
    double maxDaySales = -1;
    int bestDay = 0;
    for (int j = 0; j < 7; j++){
        double dailyTotal = 0;
        for (int i = 0; i < 5; i++){
            dailyTotal = dailyTotal + s[i][j];
        }
        if(dailyTotal > maxDaySales){
            maxDaySales = dailyTotal;
            bestDay = j + 1;
        }
    }
    cout<<"The best sales day overall was Day "<<bestDay<<" with total sales: "<<maxDaySales<<endl;
}
int main(){
    double salesData[5][7];
    double productTotals[5];
    cout<<"nter sales for 5 products over 7 days."<<endl<<endl;
    inputSales(salesData);
    Revenuecalculate(salesData, productTotals);
    cout<<"--- Sales Results ---"<<endl;
    for(int i = 0; i < 5; i++){
        cout<<"Total Revenue for Product "<<i + 1<<": " << productTotals[i]<<endl;
    }
    cout<<endl;
    findMaxProduct(productTotals);
    BestDay(salesData);
    return 0;
}