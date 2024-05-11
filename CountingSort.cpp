// David Xiao
// CountingSort.cpp

#include "CountingSort.hpp"

void countingSort(const std::string& header, std::vector<int> data) {
    const auto time_start = std::chrono::steady_clock::now();

    int N = data.size();
    if (N == 0) {
        std::cerr << "Error: Empty input data.\n";
        return;
    }

    int M = *std::max_element(data.begin(), data.end()); // Finding the maximum element
    std::vector<int> countArray(M + 1, 0);

    // Counting occurrences of each data value
    for (int i = 0; i < N; i++) {
        countArray[data[i]]++; // Increment count for data value
    }

    // Creating sorted output array
    std::vector<int> outputArray(N);
    int idx = 0;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j < countArray[i]; j++) {
            outputArray[idx++] = i; // Place data value in output array
        }
    }

    const auto time_end = std::chrono::steady_clock::now();
    // Calculate the duration in microseconds
    int time = std::chrono::duration <double, std::micro> (time_end - time_start).count();
    //std::cout << "\n" << time << " microseconds." << std::endl;
    // Calculate the number of unique data points
    int data_points = std::count_if(countArray.begin(), countArray.end(), [](int count) { return count > 0; });

    // Output
    std::cout << header << std::endl;
    std::cout << "Min: " << outputArray[0] << std::endl;
    std::cout << "P25: " << outputArray[N / 4-1] << std::endl;
    std::cout << "P50: " << outputArray[N / 2] << std::endl;
    std::cout << "P75: " << outputArray[3 * N / 4-1] << std::endl;
    std::cout << "Max: " << outputArray[N - 1] << std::endl;
    std::cout << "Data Points: " << data_points << std::endl;
}
