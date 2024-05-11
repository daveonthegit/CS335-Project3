//David Xiao
//Project 3 StdSort.cpp

#include "StdSort.hpp"

void stdSort (const std::string & header, std::vector<int> data){
    const auto time_start = std::chrono::steady_clock::now();
    //Sorting code

    std::sort(data.begin(), data.end());
    



    const auto time_end = std::chrono::steady_clock::now();
    // Calculate the duration in microseconds
    int time = std::chrono::duration <double, std::micro> (time_end - time_start).count();
    //std::cout << "\n" << time << " microseconds." << std::endl;
    
    //Output
    std::cout<<header<<std::endl;
    std::cout<<"Min: "<< data[0] <<std::endl;
    //std::cout<<"test: "<< data[1] <<std::endl;
    std::cout<<"P25: "<< data[data.size()/4-1]<<std::endl;
    std::cout<<"P50: "<< data[data.size()/2]<<std::endl;
    std::cout<<"P75: "<< data[data.size()/4+data.size()/2-1]<<std::endl;
    std::cout<<"Max: "<< data[data.size()-1]<<std::endl;
}
