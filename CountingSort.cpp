#include "CountingSort.hpp"
#include <unordered_map>
#include <algorithm>
#include <chrono>
void countingSort(const std::string& header, std::vector<int> data) {
    auto start = std::chrono::high_resolution_clock::now();

    int N = data.size();
    int data_points = 0; // Track the total number of unique data points
    int M = 0; // Finding the maximum element of array inputArray[].
    std::unordered_map<int, bool> uniqueMap; // Hash map to store whether a value is unique

    // Counting unique data points
    for (int i = 0; i < N; i++) {
        // Check if the current value has been encountered before
        if (uniqueMap.find(data[i]) == uniqueMap.end()) {
            // If not encountered before, increment data_points
            data_points++;
            uniqueMap[data[i]] = true; // Mark this value as unique
        }
        M = std::max(M, data[i]); // Finding the maximum element
    }

    // Sorting the data
    std::vector<int> countArray(M + 1, 0);
    for (int i = 0; i < N; i++) {
        countArray[data[i]]++; // Update count of data value
    }

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    std::vector<int> outputArray(N);
    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[data[i]] - 1] = data[i];
        countArray[data[i]]--;
    }

    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration in milliseconds
    std::chrono::duration<double> duration = end - start;

    // Output
    std::cout << header << std::endl;
    std::cout << "Min: " << outputArray[0] << std::endl;
    std::cout << "P25: " << outputArray[N / 4 - 1] << std::endl;
    std::cout << "P50: " << outputArray[N / 2] << std::endl;
    std::cout << "P75: " << outputArray[N / 4 + N / 2 - 1] << std::endl;
    std::cout << "Max: " << outputArray[N - 1] << std::endl;
    std::cout << "Data Points: " << data_points << std::endl;
}
