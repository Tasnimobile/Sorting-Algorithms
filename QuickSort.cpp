/**
 * @file QuickSort.cpp
 * @author Tahsinul Majumder
 * @brief Implementation for QuickSort
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "QuickSort.hpp"

template <class T>
int QuickSort<T>::partition(std::vector<T>& list, int low, int high){
    // Choose the pivot element as the last element in the list
    T pivot = list[high];
    // Initialize index i to the lower bound of the partition
    int i = low - 1;
    // Loop through elements from low to high-1
    for (int j = low; j <= high - 1; j++){
        // Compare current element with the pivot using a comparator function
        if (this -> comparator(list[j], pivot)){
            i++;
            // Swap elements at indices i and j and increment swap counter
            std::swap(list[i], list[j]); 
            this -> swaps_++; 
        }
        // Increment comparison counter
        this -> comparisons_++; 
    }
    // Swap pivot element with element at index i+1 and increment swap counter
    std::swap(list[i + 1], list[high]); 
    this -> swaps_++;
    // Return the index of the pivot element
    return i + 1;
}

template <class T>
QuickSort<T>::QuickSort(const bool& ascending) : SortingAlgo<T>("Quick Sort", false, ascending) {}

template <class T>
void QuickSort<T>::sort(std::vector<T>& list) {
    //resets comparisons_ and swaps_
    this->comparisons_ = 0;
    this->swaps_ = 0;

    //if (!list.empty()) 
    quickSort(list, 0, list.size() - 1);
    
}

template <class T>
void QuickSort<T>::quickSort(std::vector<T>& list, int low, int high) {
    if (low < high) {
        //Creates partition
        int pivot_idx = partition(list, low, high);

        //sorts through both parts
        quickSort(list, low, pivot_idx - 1);
        quickSort(list, pivot_idx + 1, high);
    }
}