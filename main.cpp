//David Xiao
//project 3 main.cpp

//libraries
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

//class information
#include "CountingSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "StdSort.hpp"

int main(){
    std::ifstream input_testdata("test_input.txt");
    std::ifstream input_testdata2("test_input2.txt");
    std::ifstream input_testdata3("test_input3.txt");
    std::string header_testdata;
    std::string header_testdata2;
    std::string header_testdata3;
    std::vector<int> read_testdata;
    std::vector<int> read_testdata2;
    std::vector<int> read_testdata3;

    if (input_testdata.is_open()) {
        std::string line;
        std::getline(input_testdata, line);
        header_testdata=line;
        while (std::getline(input_testdata, line)) {
            std::istringstream iss(line);
            int value;
            while (iss >> value) {
                read_testdata.push_back(value);
            }
        }

        input_testdata.close();
    }
        if (input_testdata2.is_open()) {
        std::string line;
        std::getline(input_testdata2, line);
        header_testdata2=line;
        while (std::getline(input_testdata2, line)) {
            std::istringstream iss(line);
            int value;
            while (iss >> value) {
                read_testdata2.push_back(value);
            }
        }

        input_testdata2.close();
    }
    if (input_testdata3.is_open()) {
        std::string line;
        std::getline(input_testdata3, line);
        header_testdata3=line;
        while (std::getline(input_testdata3, line)) {
            std::istringstream iss(line);
            int value;
            while (iss >> value) {
                read_testdata3.push_back(value);
            }
        }

        input_testdata3.close();
    }
    //stdSort(header_testdata,read_testdata);
    quickSelect1(header_testdata,read_testdata);
    //quickSelect2(header_testdata,read_testdata);
    //countingSort(header_testdata,read_testdata);
}