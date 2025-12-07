#include <iostream>
using namespace std;
int main()
{
    char entity;
    cout<<"Enter your character\n";
    cin>>entity;
    int ascii= int(entity);
    if (ascii >=65 && ascii <=90 || ascii >=90 && ascii <=122  )
    {
        cout<<"It is an alphabet"<<endl;
        if (ascii >=65 && ascii <=90)
        {
            if ( entity == 'A'|| entity == 'E'|| entity == 'I'|| entity == 'O'|| entity == 'U')
            {
                cout<<"It is an Uppercase Vowel";
            }else
            {
                cout<<"It is an upper case Consonant ";
            }
        }else if (ascii >=97 && ascii <=122)
        {
            if ( entity == 'a'|| entity == 'e'|| entity == 'i'|| entity == 'o'|| entity == 'u')
            {
                cout<<"It is a lower case Vowel";
            }else
            {
                cout<<"It is a lower case Consonant ";
            }
        }

    }else
    {
        cout<<"It is not an alphabet";
    }
    return 0;

}