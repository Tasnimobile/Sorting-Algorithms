/**
 * @file QuickSort.hpp
 * @author Tahsinul Majumder
 * @brief Header file for QuickSort
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
class QuickSort : public SortingAlgo<T>{
    public:
        /**
         * @brief Construct a new Quick Sort object
         * 
         * @param ascending: boolean indicating the order of sorting
         */
        QuickSort(const bool& ascending);

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
         * @brief creates partition and recursively iterates through two 
         * parts made by partition
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         * @param low: lower bound of partition
         * @param high: upper bound of partition
         */
        void quickSort(std::vector<T>& list, int low, int high);

        /**
         * @brief chooses a pivot and swaps when necessary
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         * @param low: lower bound of partition
         * @param high: upper bound of partition
         * @return int: index of pivot element
         */
        int partition(std::vector<T>& list, int low, int high);
};

#include "QuickSort.cpp"
