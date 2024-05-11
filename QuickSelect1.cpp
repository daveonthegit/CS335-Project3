//David Xiao
//Project 3 QuickSelect1.cpp
#include "InsertionSort.hpp"
#include "QuickSelect1.hpp"

void quickSelect1 (const std::string & header, std::vector<int> data){
    const auto time_start = std::chrono::steady_clock::now();
    int min;
    int p25;
    int p50;
    int p75;
    int max;
    //Sorting code
    quickSelect(data, 0, data.size() , data.size()/2); 
    p50 = data[data.size()/2];
    quickSelect(data, 0, data.size()/2, data.size()/4-1); 
    p25 = data[data.size()/4-1];
    quickSelect(data, data.size()/2, data.size(), ((data.size()/4)+(data.size()/2))-1);
    p75 = data[((data.size()/4)+(data.size()/2))-1];
    insertionSort(data, 0, data.size()/4);
    min = data[0];
    insertionSort(data, ((data.size()/4)+(data.size()/2))-1, data.size());
    max = data[data.size()-1];


    const auto time_end = std::chrono::steady_clock::now();
    // Calculate the duration in microseconds
    int time = std::chrono::duration <double, std::micro> (time_end - time_start).count();
    //std::cout << "\n" << time << " microseconds." << std::endl;

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
void quickSelect(std::vector<int>& data, int left, int right, int k )
 {
  if( left + 20 <= right )
  {
    const int & pivot = median3( data, left, right );
    
    // Begin partitioning
    int i= left, j = right- 1;
    for( ; ; )
    {
        while( data[ ++i ] < pivot ){ }
        while( pivot < data[--j ] ){ }
        if( i < j )
            std::swap( data[ i ], data[ j ] );
        else
            break;
    }
    
    std::swap( data[ i ], data[ right-1 ] ); // Restore pivot

    // Recurse; only this part changes
    if( k<= i )
    quickSelect( data, left, i-1, k );
    else if( k>i+1)
    quickSelect( data, i + 1, right, k );
 }
 else{ // Do an insertion sort on the subarray
    insertionSort( data, left, right );
 }
 }

