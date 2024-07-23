/**
 * @file BubbleSort.cpp
 * @author Tahsinul Majumder
 * @brief Implementation for BubbleSort
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "BubbleSort.hpp"

template <class T>
BubbleSort<T>::BubbleSort(const bool& ascending) : SortingAlgo<T>("Bubble Sort", true, ascending) {}

template <class T>
void BubbleSort<T>::sort(std::vector<T>& list) {
    //resets comparisons_ and swaps_
    this->comparisons_ = 0;
    this->swaps_ = 0;

    //if (!list.empty()) 
    bubbleSort(list);
    
}


template <class T>
void BubbleSort<T>::bubbleSort(std::vector<T>& list) {
    int size = list.size();
    bool swapped = true;
    int passes = 1;

    while (swapped && (passes < size)) {
        swapped = false;

        for (int idx = 0; idx < size - passes; idx++) {
            //if list[idx] and list[idx+1] are out of order, then swap
            if (!this->comparator(list[idx], list[idx + 1]) && list[idx] != list[idx + 1]) {
                std::swap(list[idx], list[idx + 1]);
                this->swaps_++;
                swapped = true;
            }
            this->comparisons_++;
        }

        passes++;
    }
}