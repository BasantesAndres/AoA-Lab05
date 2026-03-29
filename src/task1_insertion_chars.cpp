#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<char> generateRandomArray(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 25);

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = 'A' + dist(gen); // letters from A to Z
    }
    return arr;
}

void printArray(const vector<char>& arr) {
    for (char c : arr) {
        cout << c << ' ';
    }
    cout << '\n';
}

void insertionSort(vector<char>& arr) {
    for (int i = 1; i < (int)arr.size(); i++) {
        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the size of the character array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The size must be greater than 0.\n";
        return 1;
    }

    vector<char> letters = generateRandomArray(n);

    cout << "\nOriginal array:\n";
    printArray(letters);

    insertionSort(letters);

    cout << "\nSorted array:\n";
    printArray(letters);

    return 0;
}