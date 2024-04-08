#include "myList.hpp"

void listMedian(const std::vector<int> *instructions){
    std::list<int> median;
    int count = 0;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it == -1){
            if(median.size() % 2 == 0){
                int increment = (median.size()/2) - 1;
                auto median_it = median.begin();
                for(int i = 0; i < increment; i++){
                    ++median_it;
                }
                std::cout<< *median_it << " ";
                median.erase(median_it);
            }
            else{
                int increment_2 = std::round(median.size()/2);
                auto median_it = median.begin();
                for(int i = 0; i < increment_2; i++){
                    ++median_it;
                }
                std::cout << *median_it << " ";
                median.erase(median_it);
            }  
            
        }
        else{
            auto i = std::lower_bound(median.begin(), median.end(), *it);
            median.insert(i, *it);
        }
    }
}
