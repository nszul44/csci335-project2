/**
 * @file myList.cpp
 * @author Nicholas Szul
 * @brief implementation of listMedian
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "myList.hpp"
/**
 * @brief Uses a list to keep the numbers sorted and find the media
 * 
 * @param instructions 
 */
void listMedian(const std::vector<int> *instructions){
    const auto t1_start = std::chrono::steady_clock::now();
    std::list<int> median;
    std::vector<int> output;
    int count = 0;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){   //iterate through the instructions
        if(*it == -1){
            if(median.size() % 2 == 0){   // if the list has even size, then access the median element by dividing the list by 2 and subtracting
                int increment = (median.size()/2) - 1;          
                auto median_it = median.begin();
                for(int i = 0; i < increment; i++){   //traverse through linked list until it is at the median element.
                    ++median_it;
                }
                output.push_back(*median_it);
                median.erase(median_it);
            }
            else{
                int increment_2 = std::round(median.size()/2);// if the list has odd size, then access the median element by dividing the list by 2 and rounding
                auto median_it = median.begin();
                for(int i = 0; i < increment_2; i++){ //traverse through linked list until it is at the median element.
                    ++median_it;
                }
                output.push_back(*median_it);
                median.erase(median_it);
            }  
            
        }
        else{
            auto i = std::lower_bound(median.begin(), median.end(), *it);  //insert the element into sorted position
            median.insert(i, *it);
        }
    }
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    std::cout << "Time for List Implementation: " << t1 << " microseconds" << std::endl;
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
}
