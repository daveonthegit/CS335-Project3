    //David xiao
    //Project 3 COUNTINGSORT.cpp


    #include "CountingSort.hpp"


    void countingSort(const std::string& header, std::vector<int> data) {
        const auto time_start = std::chrono::steady_clock::now();

        int N = data.size();
        if (N == 0) {
            std::cerr << "Error: Empty input data.\n";
            return;
        }

        // Create a hash map to count occurrences of each data value
        std::unordered_map<int, int> countMap;
        for (int i = 0; i < N; i++) {
            countMap[data[i]]++;
        }

        // Create a vector of pairs from the hash map
        std::vector<std::pair<int, int>> countVector(countMap.begin(), countMap.end());

        // Sort the vector by key (data value)
        std::sort(countVector.begin(), countVector.end());

        // Calculate P25, P50, and P75
        int total = 0, P25 = 0, P50 = 0, P75 = 0;
        for (const auto& pair : countVector) {
            for (int i = 0; i < pair.second; i++) {
                total++;
                if (total == N / 4) P25 = pair.first;
                if (total == N / 2) P50 = pair.first;
                if (total == 3 * N / 4) P75 = pair.first;
            }
        }

        const auto time_end = std::chrono::steady_clock::now();
        // Calculate the duration in microseconds
        int time = std::chrono::duration <double, std::micro> (time_end - time_start).count();

        // Output
        std::cout << header << std::endl;
        std::cout << "Min: " << countVector.front().first << std::endl;
        std::cout << "P25: " << P25 << std::endl;
        std::cout << "P50: " << P50 << std::endl;
        std::cout << "P75: " << P75 << std::endl;
        std::cout << "Max: " << countVector.back().first << std::endl;
        //std::cout << "Time: " << time << " microseconds." << std::endl;
        std::cout << "Unique Data Points: " << countMap.size() << std::endl;
    }