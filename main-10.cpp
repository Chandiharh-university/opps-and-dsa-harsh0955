#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
    
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose sorting algorithm:\n1. Insertion Sort\n2. Selection Sort\n";
    cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(arr);
            cout << "Array sorted using Insertion Sort: ";
            break;
        case 2:
            selectionSort(arr);
            cout << "Array sorted using Selection Sort: ";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    printArray(arr);
    return 0;
}