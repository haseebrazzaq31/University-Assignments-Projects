#include<iostream>
using namespace std;
int main()
{
    int income;
    int tax;
    int netsalary;
    cout<<"Enter your monthly income\n";
    cin>>income;
    if (income <=50000)
    {
        tax=0;
        netsalary=income-tax;
        cout<<"Tax amount = "<<tax<<endl;
        cout<<"Net salary after tax = "<<netsalary<<endl;
        cout<<"No tax on income less then 50k"<<endl;
    }else if (income >=50000 && income <=100000)
    {
        tax=income * 0.10;
        netsalary=income-tax;
        cout<<"Tax amount = "<<tax<<endl;
        cout<<"Net salary after tax = "<<netsalary<<endl;
    }else if (income >=100000 && income <=200000)
    {
        tax=income * 0.20;
        netsalary=income-tax;
        cout<<"Tax amount = "<<tax<<endl;
        cout<<"Net salary after tax = "<<netsalary<<endl;
    }else
    {
        tax=income * 0.30;
        netsalary=income-tax;
        cout<<"Tax amount = "<<tax<<endl;
        cout<<"Net salary after tax = "<<netsalary<<endl;
    }
    return 0;
}