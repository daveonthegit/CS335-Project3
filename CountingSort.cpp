#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>

void countingSort(const std::string& header, std::vector<int> data) {
    auto start = std::chrono::high_resolution_clock::now();

    int N = data.size();
    int M = *std::max_element(data.begin(), data.end()); // Finding the maximum element
    std::unordered_map<int, int> countMap; // Hash map to store counts of each data value

    // Counting occurrences of each data value
    for (int i = 0; i < N; i++) {
        countMap[data[i]]++; // Update count of data value
    }

    // Calculating prefix sum at every index of array countArray[]
    std::vector<int> countArray(M + 1, 0);
    for (const auto& pair : countMap) {
        countArray[pair.first] = pair.second;
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

    // Calculate the number of unique data points
    int data_points = countMap.size();

    // Output
    std::cout << header << std::endl;
    std::cout << "Min: " << outputArray[0] << std::endl;
    std::cout << "P25: " << outputArray[N / 4 - 1] << std::endl;
    std::cout << "P50: " << outputArray[N / 2] << std::endl;
    std::cout << "P75: " << outputArray[N / 4 + N / 2 - 1] << std::endl;
    std::cout << "Max: " << outputArray[N - 1] << std::endl;
    std::cout << "Data Points: " << data_points << std::endl;
}

