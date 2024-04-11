/**
 * @file myAVLtree.cpp
 * @author Nicholas Szul
 * @brief Implementation of treeMedian
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "myAVLtree.hpp"
/**
 * @brief uses an Avl tree to output the medians based on the instructions
 * 
 * @param instructions 
 */
void treeMedian(const std::vector<int> *instructions){
    const auto t1_start = std::chrono::steady_clock::now();
    AvlTree small;
    AvlTree large;
    std::vector<int> output;
    int count1 = 0;
    int count2 = 0;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        
        if(count1 > (count2 + 1)){    //rebalance trees if small > large + 1
                    large.insert(small.findMax());
                    small.remove(small.findMax());
                    count1 --;
                    count2 ++;
                }
        else if(count2 > count1){  //rebalance trees if large > small
                small.insert(large.findMin());
                large.remove(large.findMin());
                count2 -= 1;
                count1 += 1;
            }
        if(small.isEmpty() == true){   //insert into small if it's empty
            small.insert(*it);
            count1++;
        }
        else if(*it == -1){        
            output.push_back(small.findMax());    //push the rightmost node(median) into outputs
            small.remove(small.findMax());
            count1 --;
            if(count2 > count1){                 //rebalance trees if large > small
               small.insert(large.findMin());
               large.remove(large.findMin());
               count2 --;
               count1 ++;
            }
        }
        else{
            if(*it <= small.findMax()){       //insert into small if <= median(rightmost node)
                small.insert(*it);
                count1 ++;
               
            }
            else{
                large.insert(*it);
                count2++;
                
            }
            
        }
    }
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    std::cout << "Time for Tree Implementation: " << t1 << " microseconds" << std::endl;
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
}