/**
 * @file SelectionSort.cpp
 * @author Tahsinul Majumder
 * @brief Implementation for SelectionSort
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "SelectionSort.hpp"

template <class T>
size_t SelectionSort<T>::findMinMax(const std::vector<T>& list, size_t start) {
    // Initialize the index of the smallest or largest element as the starting index
    size_t minmax = start;
    // Loop through the elements in the list starting from the given start index
    for (size_t i = start; i < list.size(); i++) {
        // Increment the number of comparisons made by the algorithm
        this->comparisons_++;
        // Check if the element at current index 'i' is smaller or larger than the current smallest or largest
        if (this->comparator(list[i], list[minmax])) {
            // If it is smaller or larger, update the index of the smallest or largest element
            minmax = i;
        }
    }
    // Return the index of the smallest or largest element found
    return minmax;
}

template <class T>
SelectionSort<T>::SelectionSort(const bool& ascending) : SortingAlgo<T>("Selection Sort", false, ascending) {}

template <class T>
void SelectionSort<T>::sort(std::vector<T>& list) {
    //resets comparisons_ and swaps_
    this->comparisons_ = 0;
    this->swaps_ = 0;

    int size = list.size();

    for (size_t first = 0; first < size; first++) {
        //finds smallest or largest index based on ascending value
        size_t idx = findMinMax(list, first);
        if (first != idx) {
            //swaps if the current value isn't the smallest/largest
            std::swap(list[idx], list[first]);
            this->swaps_++;
        }
    }
}
