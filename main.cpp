#include "myVector.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>

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
     test = instructions("180999424.txt");
     vectorMedian(&test);
}
