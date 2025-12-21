#include <iostream>
#include <vector>
using namespace std;
int main(){
    cout<<"1. Remove Even Numbers\n";
    vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result1;
    cout<<"Original: ";
    for(int num : numbers1)
        cout<<num<<" ";
    cout<<endl;
    for(int i = 0; i < numbers1.size(); i++){
        if(numbers1[i] % 2 != 0)
            result1.push_back(numbers1[i]);
    }
    cout << "After removing even numbers= ";
    for(int num : result1)
        cout<<num<<" ";
    cout<<endl<<endl;
    cout<<"2. Find Missing Element:\n";
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr2 = {1, 3, 4, 5, 6, 7};
    cout<<"First array: ";
    for(int num : arr1)
        cout<<num<<" ";
    cout<<endl;
    cout<<"Second array= ";
    for(int num : arr2)
        cout<<num<<" ";
    cout<<endl;
    int sum1 = 0, sum2 = 0;
    for(int num : arr1)
        sum1 += num;
    for(int num : arr2)
        sum2 += num;
    cout<<"Missing elements= "<<(sum1 - sum2)<<endl<<endl;
    cout<<"3. Check for Duplicates:\n";
    vector<int> numbers3 = {1, 2, 3, 4, 5, 2, 6};
    
    cout << "Array: ";
    for(int num : numbers3)
        cout<<num<<" ";
    cout<<endl;
    
    bool hasDuplicate = false;
    for(int i = 0; i < numbers3.size(); i++){
        for(int j = i + 1; j < numbers3.size(); j++){
            if(numbers3[i] == numbers3[j]){
                hasDuplicate = true;
                break;
            }
        }
        if(hasDuplicate) break;
    }
    if(hasDuplicate)
        cout<<"The array has duplicates.\n\n";
    else{
        cout<<"The array has no duplicates.\n\n";}
    cout<<"4. Sum of Pairs:\n";
    vector<int> numbers4 = {1, 5, 7, 3, 2, 8};
    int target = 10;
    int pairCount = 0;
    cout<<"Array: ";
    for(int num : numbers4)
        cout<<num<<" ";
    cout<<endl;
    cout<<"Target sum: "<<target<<endl;
    for(int i = 0; i < numbers4.size(); i++){
        for(int j = i + 1; j < numbers4.size(); j++){
            if(numbers4[i] + numbers4[j] == target){
                pairCount++;
            }
        }
    }
    cout<<"Number of pairs= "<<pairCount<<endl;
    return 0;
}