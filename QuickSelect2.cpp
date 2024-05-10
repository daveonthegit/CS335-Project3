    //David Xiao
    //Project 3 QuickSelect2.cpp
    #include "InsertionSort.hpp"
    #include "QuickSelect2.hpp"

    void quickSelect2 (const std::string & header, std::vector<int> data){
        std::vector<int> result{-1,-1,-1,-1,-1};
        auto start = std::chrono::high_resolution_clock::now();
        int min;
        int p25;
        int p50;
        int p75;
        int max;
            std::vector<int> k_val{(int)data.size()/2-1,(int)data.size()/4-1,(int)(((75 * data.size()) / 100 )- 1),0,(int)data.size()-1};
        //Sorting code
        quickSelect(data, 0, data.size() - 1, k_val, result);
        p50 = result[0];
        p25 = result[1];
        p75 = result[2];
        min = result[3];
        max = result[4];


        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration in milliseconds
        std::chrono::duration<double> duration = end - start;
        //std::cout << "\nSort Completed in: " << duration.count() * 1000 << " milliseconds\n";

        //Output
        std::cout<<header<<std::endl;
        std::cout<<"Min: "<< min <<std::endl;

        std::cout<<"P25: "<< p25<<std::endl;
        std::cout<<"P50: "<< p50<<std::endl;
        std::cout<<"P75: "<< p75<<std::endl;
        std::cout<<"Max: "<< max<<std::endl;
    }
    /**
     2 * Internal selection method that makes recursive calls.
    3 * Uses median-of-three partitioning and a cutoff of 10.
    4 * Places the kth smallest item in a[k-1].
    5 * a is an array of Comparable items.
    6 * left is the left-most index of the subarray.
    7 * right is the right-most index of the subarray.
    8 * k is the desired rank (1 is minimum) in the entire array.
    9 */
   void quickSelect(std::vector<int>& data, int left, int right, const std::vector<int>& k_val, std::vector<int>& result) {
    if (left + 20 <= right) {
        const int& pivot = median3(data, left, right);
        
        int i = left, j = right - 1;
        for (;;) {
            while (data[++i] < pivot) {}
            while (pivot < data[--j]) {}
            if (i < j)
                std::swap(data[i], data[j]);
            else
                break;
        }

        std::swap(data[i], data[right - 1]); // Restore pivot
        
        // Update result for the percentiles within the current partition
        for (size_t idx = 0; idx < k_val.size(); ++idx) {
            if (left <= k_val[idx] && k_val[idx] <= right) {
                if (k_val[idx] == i) {
                    result[idx] = data[i];
                } else if (k_val[idx] < i) {
                    quickSelect(data, left, i - 1, k_val, result);
                } else {
                    quickSelect(data, i + 1, right, k_val, result);
                }
            }
        }
    } else {
        insertionSort(data, left, right);
        for (size_t idx = 0; idx < k_val.size(); ++idx) {
            if (k_val[idx] == left) {
                result[idx] = data[left];
            }
        }
        for (int i = left + 1; i <= right; ++i) {
            for (size_t idx = 0; idx < k_val.size(); ++idx) {
                if (k_val[idx] == i) {
                    result[idx] = data[i];
                }
            }
        }
    }
}
