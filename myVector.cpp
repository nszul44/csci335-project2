/**
 * @file myVector.cpp
 * @author Nicholas Szul
 * @brief implementation of VectorMedian
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "myVector.hpp"
/**
 * @brief Uses a vector to find the medians based on instructiond
 * 
 * @param instructions 
 */
void vectorMedian(const std::vector<int> *instructions)
{
    const auto t1_start = std::chrono::steady_clock::now();
    std::vector<int> sorted;
    std::vector<int> output;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){ //iterate through the instructions
        if(*it == -1){
            if(sorted.size() % 2 != 0){  // if the vector has odd size, then access the median element by dividing the list by 2 and rounding
                int increment = std::round(sorted.size()/2);
                output.push_back(sorted[increment]);
                sorted.erase(sorted.begin() + increment);
                increment = 0;
            }
            else{
                int increment_2 = sorted.size()/2 - 1; // if the vector has size, then access the median element by dividing the list by 2 and subtracting 1
                output.push_back(sorted[increment_2]);
                sorted.erase(sorted.begin() + increment_2);
                increment_2 = 0;
            }
        }
        else{
            auto i = std::lower_bound(sorted.begin(), sorted.end(), *it);  //insert elements into the vector in sorted position
            sorted.insert(i, *it);
        }
    }
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    std::cout << "Time for Vector Implementation: " << t1 << " microseconds" << std::endl;
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
}