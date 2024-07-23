/**
 * @file InsertionSort.cpp
 * @author Tahsinul Majumder
 * @brief Implementation for InsertionSort
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "InsertionSort.hpp"

template <class T>
InsertionSort<T>::InsertionSort(const bool& ascending) : SortingAlgo<T>("Insertion Sort", true, ascending) {}

template <class T>
void InsertionSort<T>::sort(std::vector<T>& list) {
    this->comparisons_ = 0;
    this->swaps_ = 0;

    //if (!list.empty()) 
    insertionSort(list);
    
}

template <class T>
void InsertionSort<T>::insertionSort(std::vector<T>& list) {
    int size = list.size();

    //iterates through list
    for (int check = 1; check < size; check++) {
        int curr = check;
        this->comparisons_++;
        //when list[curr] and list[curr-1] are out of order, it will swap
        while ((curr > 0) && !this->comparator(list[curr - 1], list[curr]) && list[curr - 1] != list[curr]) {    
            std::swap(list[curr], list[curr - 1]);
            this->swaps_++;
            this->comparisons_++;
            curr--;
        }
        
    }
}