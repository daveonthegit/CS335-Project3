//David xiao
//Project 3 QuickSelect2.hpp

#ifndef QUICKSELECT2_HPP
#define QUICKSELECT2_HPP

//libraries
#include <chrono>   
#include <vector>
#include <algorithm>
#include <iostream>
#include "InsertionSort.hpp"

void quickSelect2 (const std::string & header, std::vector<int> data);
void quickSelect(std::vector<int>& data, int left, int right,const std::vector<int>&k_val, std::vector<int>& result);
const int & median3( std::vector<int> & a, int left, int right );

#endif