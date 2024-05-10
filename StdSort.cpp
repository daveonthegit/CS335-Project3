//David Xiao
//Project 3 StdSort.cpp

#include "StdSort.hpp"

void stdSort (const std::string & header, std::vector<int> data){
    std::sort(data.begin(), data.end());




    //Output
    std::cout<<header<<std::endl;
    std::cout<<"Min: "<< data[0] <<std::endl;

    std::cout<<"P25: "<< data[data.size()/4-1]<<std::endl;
    std::cout<<"P50: "<< data[data.size()/2]<<std::endl;
    std::cout<<"P75: "<< data[data.size()/4+data.size()/2-1]<<std::endl;
    std::cout<<"Max: "<< data[data.size()-1]<<std::endl;
}
