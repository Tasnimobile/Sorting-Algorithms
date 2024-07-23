/**
 * @file MergeSort.hpp
 * @author Tahsinul Majumder
 * @brief Header file for MergeSort
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
class MergeSort : public SortingAlgo<T> {
    public:
        /**
         * @brief Construct a new Merge Sort object
         * 
         * @param ascending: boolean indicating the order of sorting
         */
        MergeSort(const bool& ascending);

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
         * @brief merges left and right vectors by sorting them and 
         * pushing them into the result vector
         * 
         * @param left: left vector given
         * @param right: right vector given
         * @return std::vector<T>: result of the two vectors merged and sorted
         */
        std::vector<T> merge(std::vector<T>& left, std::vector<T>& right);

        /**
         * @brief splits list into two halves and recursively calls 
         * itself (mergeSort) on each half, then calls merge to combine 
         * the two halves and sort
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         * @return std::vector<T>: result of list sorted through
         */
        std::vector<T> mergeSort(std::vector<T>& list);
};

#include "MergeSort.cpp"
