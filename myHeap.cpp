/**
 * @file myHeap.cpp
 * @author Nicholas Szul
 * @brief implementation of heapMedian
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "myHeap.hpp"
/**
 * @brief uses a heap to output the medians based on the instruction
 * 
 * @param instructions 
 */
void heapMedian(const std::vector<int> * instructions){
    const auto t1_start = std::chrono::steady_clock::now();
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;
    std::vector<int> output;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(small.size() > large.size() + 1){  //rebalance heaps if small is too big
                large.push(small.top());
                small.pop();
            } 
        else if (large.size() > small.size()) { //rebalance heaps if large is too big
            small.push(large.top());
            large.pop();
        }
        if(*it == -1){
            output.push_back(small.top());
            small.pop();
            if(small.size() == (large.size() - 1)){  //rebalance heaps if small is too big after popping the median
                small.push(large.top());
                large.pop();
            }
        }
        else{
            if(small.empty() == true || *it <= small.top()){  //push to small heap if <= median or if small is empty
                small.push(*it);
            }
            else{
                large.push(*it);  //push to large heap if > median
            }
        }
    }
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    std::cout << "Time for Heap Implementation: " << t1 << " microseconds" << std::endl;
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
}