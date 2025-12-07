#include <iostream>
using namespace std;
int main()
{
    char seat;
    int distance;
    int fare;
    cout<<"Choose in which class you want to travel\n";
    cout<<"a = economy\n";
    cout<<"b = business\n";
    cout<<"c = first class\n";
    cin>>seat;
    cout<<"Please enter the distance of your destination\n";
    cin>>distance;
    switch (seat)
    {
    case 'a': fare=distance*5;
        cout<<"Your fare for economy class at distance"<<distance<<"  Km = "<<fare<<endl;
        break;
    case'b': fare=distance*8;
        cout<<"Your fare for business class at distance"<<distance<<"  Km = "<<fare<<endl;
        break;
    case 'c': fare=distance*12;
        cout<<"Your fare for first class at distance"<<distance<<"  Km = "<<fare<<endl;
        break;
    default: cout<<"Invalid option";break;
    }
    return 0;
}