#include <iostream>
using namespace std;
int main()
{
    int marks;
    int attendance;
    int familyincome;
    cout<<"Enter your marks(out of 100) please\n";
    cin>>marks;
    cout<<"Next enter your attendace in the terms of percentage\n ";
    cin>>attendance;
    cout<<"What's your family income?\n";
    cin>>familyincome;
    if (attendance>=80 && marks>=85)
    {
        cout<<"Congratulations! you got full scholarship";
    }else if(marks >=70)
    {
        cout<<"Congratulations! you got half scholarship";
    }else
    {
        cout<<"Sorry! no scholarship";
    }
    return 0;
}