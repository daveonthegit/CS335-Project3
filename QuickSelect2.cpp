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
            std::vector<int> k_val{0,(int)data.size()/4-1,(int)data.size()/2-1,(int)((( data.size()/4)*3 )- 1),(int)data.size()-1};
        //Sorting code
        quickSelect(data, 0, data.size() - 1, k_val);
        p50 = data[data.size()/2 - 1];
        p25 = data[data.size()/4 -1];
        p75 = data[(data.size()/4) *3 -1 ];
        min = data[0];
        max = data[data.size()-1];


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
   void quickSelect(std::vector<int>& data, int left, int right, const std::vector<int>& k_val) {
    if (left + 20 <= right) {
        const int& pivot = median3(data, left, right);
        
        int i = left, j = right - 1;
        while(i<=j){
            while(data[i]<pivot){
                i++;
                }
            while(data[j]>pivot){
                j--;
            }
            if(i<=j){
                std::swap(data[i],data[j]);
                i++;
                j--;
            }
        }
        std::vector<int> lhs,rhs;// initialize for lhs and rhs of keys
        for(auto k:k_val){
            if(k<i){
                lhs.push_back(k);
            }else if(k >i){
                rhs.push_back(k);
            }
        }
        if(!lhs.empty()){
            quickSelect(data,left,i-1,lhs);
        }
        if(!rhs.empty()){
            quickSelect(data,i,right,rhs);
        }

    } else {
        insertionSortQS2(data, left, right);

    }
}


void insertionSortQS2(std::vector<int> & data, int left, int right) {
    int key;
    for (left = 1; left < data.size(); left++) {
        key = data[left];
        right = left - 1;

        while (right >= 0 && data[right] > key) {
            data[right + 1] = data[right];
            right = right - 1;
        }
        data[right + 1] = key;
    }
}
