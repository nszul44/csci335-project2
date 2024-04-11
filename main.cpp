/**
 * @file main.cpp
 * @author Nicholas Szul
 * @brief Passes the data from the txt file to the implemented functions
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLTree.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
/**
 * @brief converts a txt file to an accesible vector 
 * 
 * @param in_file 
 * @return std::vector<int> 
 */
std::vector<int> instructions(const std::string& in_file){
    std::ifstream inputfile;
    inputfile.open(in_file);
    std::string line, instruction, temp;
    int median;
    std::vector<int> instructions;
    while(std::getline(inputfile, line)){
        std::stringstream inputstring(line);
        std::getline(inputstring, instruction, ' ');
        if(instruction == "insert"){
            std::getline(inputstring, temp, '\r');
            median = std::stoi(temp.c_str());
            instructions.push_back(median);
            temp = "";
        }
        else{
            std::getline(inputstring, temp, '\r');
            instructions.push_back(-1);
            temp = "";
        }

    }
    return instructions;
}

int main(){
    std::vector<int>  test;
     test = instructions("testinput.txt");
     vectorMedian(&test);
     listMedian(&test);
     heapMedian(&test);
     treeMedian(&test);
}
