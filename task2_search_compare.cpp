#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

vector<int> generateRandomNumbers(size_t n, int minVal = 1, int maxVal = 1000000000) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);

    vector<int> arr;
    arr.reserve(n);

    for (size_t i = 0; i < n; i++) {
        arr.push_back(dist(gen));
    }
    return arr;
}

long long binarySearchCustom(const vector<int>& arr, int key) {
    long long left = 0;
    long long right = (long long)arr.size() - 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

long long interpolationSearch(const vector<int>& arr, int key) {
    long long low = 0;
    long long high = (long long)arr.size() - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == key) return low;
            return -1;
        }

        long double ratio = (long double)(key - arr[low]) / (arr[high] - arr[low]);
        long long pos = low + (long long)((high - low) * ratio);

        if (pos < low || pos > high) break;

        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }

    return -1;
}

int main() {
    const size_t N = 10000000;

    cout << "Generating " << N << " random numbers...\n";
    auto startGen = high_resolution_clock::now();
    vector<int> data = generateRandomNumbers(N);
    auto endGen = high_resolution_clock::now();

    cout << "Sorting the array...\n";
    auto startSort = high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto endSort = high_resolution_clock::now();

    // Choose a key that is guaranteed to exist in the array
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> distIndex(0, (long long)N - 1);
    long long randomIndex = distIndex(gen);
    int key = data[randomIndex];

    cout << "Key to search: " << key << "\n\n";

    auto startBin = high_resolution_clock::now();
    long long posBin = binarySearchCustom(data, key);
    auto endBin = high_resolution_clock::now();

    auto startInt = high_resolution_clock::now();
    long long posInt = interpolationSearch(data, key);
    auto endInt = high_resolution_clock::now();

    auto genTime = duration_cast<milliseconds>(endGen - startGen).count();
    auto sortTime = duration_cast<milliseconds>(endSort - startSort).count();
    auto binTime = duration_cast<microseconds>(endBin - startBin).count();
    auto intTime = duration_cast<microseconds>(endInt - startInt).count();

    cout << fixed << setprecision(3);

    cout << "===== RESULTS =====\n";
    cout << "Generation time: " << genTime << " ms\n";
    cout << "Sorting time: " << sortTime << " ms\n\n";

    cout << "Binary Search:\n";
    cout << "  Position found: " << posBin << "\n";
    cout << "  Time: " << binTime << " microseconds\n\n";

    cout << "Interpolation Search:\n";
    cout << "  Position found: " << posInt << "\n";
    cout << "  Time: " << intTime << " microseconds\n";

    return 0;
}