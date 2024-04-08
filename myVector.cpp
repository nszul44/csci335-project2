#include "myVector.hpp"

void vectorMedian(const std::vector<int> *instructions)
{
    std::vector<int> sorted;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it == -1){
            if(sorted.size() % 2 != 0){
                int increment = std::round(sorted.size()/2);
                std::cout << sorted[increment] << " ";
                sorted.erase(sorted.begin() + increment);
                increment = 0;
            }
            else{
                int increment_2 = sorted.size()/2 - 1;
                std::cout << sorted[increment_2] << " ";
                sorted.erase(sorted.begin() + increment_2);
                increment_2 = 0;
            }
        }
        else{
            auto i = std::lower_bound(sorted.begin(), sorted.end(), *it);
            sorted.insert(i, *it);
        }
    }

}