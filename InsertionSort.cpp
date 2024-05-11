//David Xiao
//Project 3 InsertionSort.cpp

#include "InsertionSort.hpp"
 // Standard insertion sort algorithm
void insertionSort( std::vector<int> & data, int left, int right )
{
    // Iterate over the array from left to right
    for( ; left < right; ++left )
    {
        // Store the current element in a temporary variable
        int tmp = std::move( data[ left ] );
        
        // Initialize variable for inner loop
        int j;
        
        // Iterate backwards to find the correct position for the current element
        for( j = left; j > 0 && tmp < data[ j - 1 ]; --j )  
            // Shift elements to the right until the correct position is found
            data[ j ] = std::move( data[ j - 1 ] );
        
        // Place the current element in its correct position in the sorted sequence
        data[ j ] = std::move( tmp );
    }
}

// Modified and adapted insertion sort function
void insertionSort2(std::vector<int> & data, int left, int right) {
    // Initialize variable for the key element
    int key;
    
    // Iterate over the array from left to right
    for (left = 1; left < data.size(); left++) {
        // Store the current element as the key
        key = data[left];
        
        // Initialize variable for inner loop
        right = left - 1;

        // Iterate backwards to shift larger elements to the right
        while (right >= 0 && data[right] > key) {
            // Shift elements to the right
            data[right + 1] = data[right];
            right = right - 1;
        }
        
        // Place the key element in its correct position in the sorted sequence
        data[right + 1] = key;
    }
}

  const int & median3( std::vector<int> & a, int left, int right )
 {
    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );
    
    // Place pivot at position right- 1
        std::swap( a[ center ], a[ right- 1 ] );
    return a[ right- 1 ];
 }
