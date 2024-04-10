#include "myAVLtree.hpp"
//comment
void treeMedian(const std::vector<int> *instructions){
    
    
    AvlTree small;
    AvlTree large;
    std::vector<int> output;
    int count1 = 0;
    int count2 = 0;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        
        if(count1 > (count2 + 1)){ 
                    large.insert(small.findMax());
                    small.remove(small.findMax());
                    count1 --;
                    count2 ++;
                }
        else if(count2 > count1){
                small.insert(large.findMin());
                large.remove(large.findMin());
                count2 -= 1;
                count1 += 1;
            }
        if(small.isEmpty() == true){
            small.insert(*it);
            count1++;
        }
        else if(*it == -1){
            output.push_back(small.findMax());
            small.remove(small.findMax());
            count1 --;
            if(count2 > count1){
               small.insert(large.findMin());
               large.remove(large.findMin());
               count2 --;
               count1 ++;
            }
        }
        else{
            if(*it <= small.findMax()){
                small.insert(*it);
                count1 ++;
               
            }
            else{
                large.insert(*it);
                count2++;
                
            }
            
        }
    }
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
}