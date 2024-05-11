#include "CountingSort.hpp"
#include <unordered_map>
#include <algorithm>
#include <chrono>

void countingSort(const std::string& header, std::vector<int> data) {
    auto start = std::chrono::high_resolution_clock::now();

    int N = data.size();
    int data_points = 0; // Track the total number of data points
    int M = 0; // Finding the maximum element of array inputArray[].
    std::unordered_map<int, int> countMap; // Hash map to store counts of each data value

    for (int i = 0; i < N; i++) {
        M = std::max(M, data[i]);
        countMap[data[i]]++; // Update count of data value
    }

    // Calculating prefix sum at every index of array countArray[]
    std::vector<int> countArray(M + 1, 0);
    for (const auto& pair : countMap) {
        countArray[pair.first] = pair.second;
        data_points += pair.second; // Increment data points count
    }

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    std::vector<int> outputArray(N);
    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[data[i]] - 1] = data[i];
        countArray[data[i]]--;
    }

    data = outputArray;

    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration in milliseconds
    std::chrono::duration<double> duration = end - start;

    //Output
    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << data[data.size() / 4 - 1] << std::endl;
    std::cout << "P50: " << data[data.size() / 2] << std::endl;
    std::cout << "P75: " << data[data.size() / 4 + data.size() / 2 - 1] << std::endl;
    std::cout << "Max: " << data[data.size() - 1] << std::endl;
    std::cout << "Data Points: " << data_points << std::endl;
}
