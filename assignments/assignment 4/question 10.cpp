#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> numbers = {10, 20, 30, 40, 50};
    cout<<"Using traditional for loop: ";
    for(int i = 0; i < numbers.size(); i++){
        cout<<numbers[i]<<" ";}
    cout<<endl;
    cout<<"Using range-based for loop: ";
    for(int num : numbers){
        cout<<num<<" ";
    }
    cout<<endl<<endl
    int N;
    cout<<"Enter number inputs: ";
    cin>>N;
    
    vector<int> userNumbers(N);
    cout<<"Enter "<<N<<" integers: ";
    for(int i = 0; i < N; i++){
        cin >> userNumbers[i];
    }
    int maximum = userNumbers[0];
    int minimum = userNumbers[0];
    
    for(int i = 1; i < N; i++){
        if(userNumbers[i] > maximum)
            maximum = userNumbers[i];
        if(userNumbers[i] < minimum)
            minimum = userNumbers[i];
    }
    cout<<"Maximum: "<<maximum<<endl;
    cout<<"Minimum: "<<minimum<<endl<<endl;
    vector<int> reversedVector = userNumbers;
    int start = 0;
    int end = reversedVector.size() - 1;
    while(start < end){
        int temp = reversedVector[start];
        reversedVector[start] = reversedVector[end];
        reversedVector[end] = temp;
        start++;
        end--;
    }
    cout<<"Reversed vector: ";
    for(int num : reversedVector){
        cout<<num<<" ";
    }
    cout<<endl<<endl;
    int target;
    cout<<"Enter a number to count: ";
    cin>>target;
    int count = 0;
    for(int i = 0; i < userNumbers.size(); i++){
        if(userNumbers[i] == target)
            count++;
    }
    cout<<"The number "<<target<<" appears "<<count<<" times."<<endl;
    return 0;
}