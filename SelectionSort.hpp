/**
 * @file SelectionSort.hpp
 * @author Tahsinul Majumder
 * @brief Header file for SelectionSort
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include "SortingAlgo.hpp"
#include <vector>

template <class T>
class SelectionSort : public SortingAlgo<T> {
    public:
        /**
         * @brief Construct a new Selection Sort object
         * 
         * @param ascending: boolean indicating the order of sorting
         */
        SelectionSort(const bool& ascending);

        /**
         * @brief function that overrides SortingAlgo's virtual function
         * and sorts through the list by calling on other functions
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         */
        void sort(std::vector<T>& list) override;
    private:

        /**
         * @brief Finds the index of the smallest or largest element
         * in the list, depending on ascending 
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         * @param start: starting value used
         * @return size_t: index of smallest value
         */
        size_t findMinMax(const std::vector<T>& list,size_t start);
};

#include "SelectionSort.cpp"
