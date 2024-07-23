/**
 * @file MergeSort.cpp
 * @author Tahsinul Majumder
 * @brief Implementation for MergeSort
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "MergeSort.hpp"

template <class T>
std::vector<T> MergeSort<T>::merge(std::vector<T>& left, std::vector<T>& right) {
    // Vector to store the merged result
    std::vector<T> result;
    // Index for left and right vectors
    size_t l = 0;  
    size_t r = 0;
    // Merge the elements from left and right vectors into the result vector
    while (l < left.size() && r < right.size()) {
        // Compare elements using comparator and also check for equality to add equal elements from left first (<=)
        if (this->comparator(left[l], right[r]) or (left[l] == right[r])) {
            // Add element from left vector to result and move to the next element in left vector
            result.push_back(left[l]);  
            l++;
        } else {
            // Add element from right vector to result and move to the next element in right vector
            result.push_back(right[r]);  
            r++;
            // Increment swap count as adding an element from right half before left is to be counted as a swap operation
            this -> swaps_++;
        }
        // Increment comparison count
        this -> comparisons_++;  
    }
    // Add remaining elements from left vector to result
    while (l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    // Add remaining elements from right vector to result
    while (r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    // Return the merged and sorted result vector
    return result;
}

template <class T>
MergeSort<T>::MergeSort(const bool& ascending) : SortingAlgo<T>("Merge Sort", true, ascending){}

template <class T>
void MergeSort<T>::sort(std::vector<T>& list) {
    //resets comparisons_ and swaps_
    this->comparisons_ = 0;
    this->swaps_ = 0;

    //if (!list.empty()) 
    mergeSort(list);
    
}

template <class T>
std::vector<T> MergeSort<T>::mergeSort(std::vector<T>& list) {
    //if it has 1 or less elements, it is already sorted
    if (list.size() <= 1)
        return list;

    //split into two halves
    size_t mid = list.size() / 2;
    std::vector<T> left(mid);
    std::vector<T> right(list.size() - mid);

    //putting it into both vectors
    for (int i = 0; i < mid; i++)
        left[i] = list[i];

    for (int j = mid; j < list.size(); j++)
        right[j - mid] = list[j];

    //actually sorting each half
    left = mergeSort(left);
    right = mergeSort(right);

    list = merge(left, right);

    //returns sorted list
    return list;
}