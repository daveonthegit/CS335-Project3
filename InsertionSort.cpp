//David Xiao
//Project 3 InsertionSort.cpp

#include "InsertionSort.hpp"
 /**
 2 *Simple insertion sort.
 3 */
 void insertionSort( std::vector<int> & data, int left, int right )
 {
    for( ; left < right; ++left )
    {
        int tmp = std::move( data[ left ] );
        
        int j;
        for( j = left; j > 0 && tmp < data[ j- 1 ];--j )  
            data[ j ] = std::move( data[ j- 1 ] );
        data[ j ] = std::move( tmp );
    }
 }
