#include "myHeap.hpp"

void heapMedian(const std::vector<int> * instructions){
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
            if(small.empty() == true || *it <= small.top()){
                small.push(*it);
            }
            else{
                large.push(*it);
            }
        }
    }
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
}