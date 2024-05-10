//David xiao
//Project 3 QuickSelect1.hpp

#ifndef QUICKSELECT1_HPP
#define QUICKSELECT1_HPP

//libraries
#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>
#include "InsertionSort.hpp"

void quickSelect1 (const std::string & header, std::vector<int> data);
void quickSelect(std::vector<int>& data, int left, int right, int k );
const int & median3( std::vector<int> & a, int left, int right );


#endif