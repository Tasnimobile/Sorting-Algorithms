/**
 * @file BubbleSort.hpp
 * @author Tahsinul Majumder
 * @brief Header file for BubbleSort
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
class BubbleSort : public SortingAlgo<T> {
    public:

        /**
         * @brief Construct a new Bubble Sort object
         * 
         * @param ascending: boolean indicating the order of sorting
         */
        BubbleSort(const bool& ascending);

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
         * @brief compares adjacent elements and swaps when necessary
         * iterates through the list until the entirety comes back as sorted
         * 
         * @param list: the vector that will be sorted through
         * referenced of type T
         */
        void bubbleSort(std::vector<T>& list);
};

#include "BubbleSort.cpp"
