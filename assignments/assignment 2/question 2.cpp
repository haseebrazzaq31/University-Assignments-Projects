#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
        cout << "Step " << i+1 << ": swap " << arr[size - 1 - i] << " and " << arr[i] << "\n";
    }
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[100];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: {";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ",";
    }
    cout << "}\n\n";

    reverseArray(arr, size);

    cout << "\nReversed Array: {";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ",";
    }
    cout << "}\n";

    return 0;
}
