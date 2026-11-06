#ifndef HEAPMERGE_H
#define HEAPMERGE_H

#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"

using namespace std;

template <class T>
class HeapMerge
{
public:

    // Union of two heaps
    //precondition: heap1 and heap2 are valid HeapType objects
    // postcondition: returns a new heap containing the union of elements from heap1 and heap2
    template <class HeapType>
    HeapType heapUnion(HeapType heap1, HeapType heap2)
    {
        HeapType result{};

        // Insert unique elements from the first heap
        while (!heap1.empty())
        {
            T value = heap1.front();

            if (!result.find(value))
            {
                result.push(value);
            }

            heap1.pop();
        }

        // Insert unique elements from the second heap
        while (!heap2.empty())
        {
            T value = heap2.front();

            if (!result.find(value))
            {
                result.push(value);
            }

            heap2.pop();
        }

        return result;
    }

    // Intersection of two heaps
	//precondition: heap1 and heap2 are valid HeapType objects
	// postcondition: returns a new heap containing the intersection of elements from heap1 and heap2
    template <class HeapType>
    HeapType heapIntersection(HeapType heap1, HeapType heap2)
    {
        HeapType result{};

        while (!heap1.empty())
        {
            T value = heap1.front();

            if (heap2.find(value) && !result.find(value))
            {
                result.push(value);
            }

            heap1.pop();
        }

        return result;
    }
};

#endif