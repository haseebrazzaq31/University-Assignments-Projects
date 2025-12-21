#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Employee
{
    string name;
    int age;
    vector<string> skills;
};
int main(){
    int numEmployees;
    cout<<"How many employees? ";
    cin>>numEmployees;
    vector<Employee> employees(numEmployees);
    for(int i = 0; i < numEmployees; i++){
        cout<<"\nEmployee " << i + 1 << ":\n";
        cout<< "Name: ";
        cin>>ws;
        getline(cin, employees[i].name);
        cout<<"Age: ";
        cin>>employees[i].age;
        int numSkills;
        cout<<"How many skills? ";
        cin>>numSkills;
        for(int j = 0; j < numSkills; j++){
            string skill;
            cout<<"Skill " << j + 1 << ": ";
            cin>>ws;
            getline(cin, skill);
            employees[i].skills.push_back(skill);
        }
    }
    cout<<"\n--- Employee Details ---\n";
    for(int i = 0; i < numEmployees; i++){
        cout<<"\nEmployee "<<i + 1<<":\n";
        cout<<"Name: "<<employees[i].name<<endl;
        cout<<"Age: "<<employees[i].age<<endl;
        cout<<"Skills: ";
        if(employees[i].skills.size() == 0){
            cout<<"None";
        }
        else{
            for(int j = 0; j < employees[i].skills.size(); j++)
            {
                cout<<employees[i].skills[j];
                if(j != employees[i].skills.size() - 1)
                {
                    cout<<", ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}