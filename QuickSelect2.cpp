//David Xiao
//Project 3 QuickSelect2.cpp

#include "QuickSelect2.hpp"

void quickSelect(std::vector<int> & data, int left, int right, std::vector<int>& k_vals) {
    // Modified and adapted quickSelect function
    if (left + 20 <= right) {
        int pivot = median3(data, left, right);
        std::vector<int> lhs, rhs; // Initialize vectors for left and right k_vals
        int i = left, j = right - 1;
        while (i <= j) {
            while (data[i] < pivot) { i++; }
            while (data[j] > pivot) { j--; }
            if (i <= j) {
                std::swap(data[i], data[j]);
                i++;
                j--;
            }
        }
        for(auto k : k_vals) {
            // If the key is less than pivot i, push back to the left vector, else to the right vector
            if (k < i) {
                lhs.push_back(k);
            } else if (k > i) {
                rhs.push_back(k);
            }
        }
        if (!lhs.empty()) {
            quickSelect(data, left, i - 1, lhs); // Recurse on the left side if there are k_vals present
        }
        if (!rhs.empty()) {
            quickSelect(data, i, right, rhs); // Recurse on the right side if there are k_vals present
        }
    } else {
        insertionSort2(data, left, right); // Default to insertion sort if the size is 20 or less
    }
}

void quickSelect2(const std::string& header, std::vector<int> data) {
    // Entry point for method 3 implementation
    const auto time_start = std::chrono::steady_clock::now();
    std::vector<int> k_vals; // Vector to store all k_vals for recursion
    k_vals.push_back(0); // Push the beginning, 25%, 50%, 75% and last pivot positions
    k_vals.push_back(int(data.size() / 2) - 1);
    k_vals.push_back(int(data.size() / 4) - 1);
    k_vals.push_back(int((data.size() / 4) * 3) - 1);
    k_vals.push_back(int(data.size()) - 1);

    // Call quickSelect with all the k_vals
    quickSelect(data, 0, data.size() - 1, k_vals);

    // Display the results
    int min = data[0];
    int p25 = data[data.size() / 4 - 1]; 
    int p50 = data[data.size() / 2 - 1];
    int p75 = data[(data.size() / 4) * 3 - 1];
    int max = data[data.size() - 1];

    std::cout << header << "\n";
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << p50 << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
        
    const auto time_end = std::chrono::steady_clock::now();
    // Calculate the duration in microseconds
    int time = std::chrono::duration <double, std::micro> (time_end - time_start).count();
    //std::cout << "\n" << time << " microseconds." << std::endl;
}
