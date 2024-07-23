/**
 * @file InsertionSort.hpp
 * @author Tahsinul Majumder
 * @brief Header file for InsertionSort
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
class InsertionSort : public SortingAlgo<T> {
    public:
        /**
         * @brief Construct a new Insertion Sort object
         * 
         * @param ascending: boolean indicating the order of sorting
         */
        InsertionSort(const bool& ascending);

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
         * @brief takes an element in an unsorted position and 
         * puts it into its correct position by comparing and swapping
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         */
        void insertionSort(std::vector<T>& list);
};

#include "InsertionSort.cpp"