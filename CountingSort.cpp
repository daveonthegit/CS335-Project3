#include "CountingSort.hpp"

void countingSort(const std::string& header, std::vector<int> data) {
    const auto time_start = std::chrono::steady_clock::now();

    // Create a hash map to store counts of each unique data value
    std::unordered_map<int, int> countMap;

    // Count occurrences of each data value
    for (int val : data) {
        if (countMap.find(val) != countMap.end()) {
            // If the value already exists in the map, increment its count
            countMap[val]++;
        } else {
            // If the value doesn't exist in the map, add it with count 1
            countMap[val] = 1;
        }
    }

    // Create a vector to store unique values and their counts
    std::vector<std::pair<int, int>> countVector;

    // Push key-value pairs from the hash map to the vector
    for (const auto& pair : countMap) {
        countVector.push_back(pair);
    }

    // Sort the vector based on data values
    std::sort(countVector.begin(), countVector.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    // Calculate total number of data points
    int totalDataPoints = 0;
    for (const auto& pair : countVector) {
        totalDataPoints += pair.second;
    }

    // Find P25, P50, and P75
    int p25 = -1, p50 = -1, p75 = -1;
    int count = 0;
    for (const auto& pair : countVector) {
        count += pair.second;
        if (p25 == -1 && count >= totalDataPoints / 4) {
            p25 = pair.first;
        }
        if (p50 == -1 && count >= totalDataPoints / 2) {
            p50 = pair.first;
        }
        if (p75 == -1 && count >= 3 * totalDataPoints / 4) {
            p75 = pair.first;
            break; // Exit loop once P75 is found
        }
    }

    // Calculate minimum and maximum values
    int minVal = countVector.front().first;
    int maxVal = countVector.back().first;

    // Output results
    std::cout << header << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << p50 << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Data Points: " << totalDataPoints << std::endl;

    const auto time_end = std::chrono::steady_clock::now();
    // Calculate the duration in microseconds
    int time = std::chrono::duration <double, std::micro> (time_end - time_start).count();
    //std::cout << "\n" << time << " microseconds." << std::endl;
}
