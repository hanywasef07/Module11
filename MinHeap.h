#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<class T>
class MinHeap
{
private:
	vector<T> A; // vector to store heap elements
	static const int ONE = 1;
	static const int TWO = 2;
	// return parent of A[i]
    int parent(int i)
    {
        return (i - ONE) / TWO;
    }

    // return left child of A[i]    
    int left(int i)
    {
        return (TWO * i + ONE);
    }

    // return right child of A[i]    
    int right(int i)
    {
        return (TWO * i + TWO);
    }

	//precondition: i is a valid index in the heap
	// postcondition: the subtree rooted at index i is a min-heap
    void heapify_down(int i)
    {
        // get left and right child of node at index i
        int l = left(i);
        int r = right(i);

		int smallest = i; // initialize smallest as root

        // compare A[i] with its left and right child
        // and find smallest value
        if (l < size() && A[l] < A[i])
        {
            smallest = l;
        }
		// compare A[smallest] with right child
        if (r < size() && A[r] < A[smallest])
        {
            smallest = r;
        }

        // swap with child having lesser value and 
        // call heapify-down on the child
        if (smallest != i)
        {
            swap(A[i], A[smallest]);
            heapify_down(smallest);
        }
    }

    // Recursive Heapify-up algorithm
	//precondition: i is a valid index in the heap
	// postcondition: the subtree rooted at index i is a min-heap
    void heapify_up(int i)
    {
        // check if node at index i and its parent violates 
        // the heap property
        if (i < 0 || i >= static_cast<int>(A.size()))
        {
            return;
        }
		// if the heap property is violated, swap the node with its parent
        if (i && A[parent(i)] > A[i])
        {
            // swap the two if heap property is violated
            swap(A[i], A[parent(i)]);

            // call Heapify-up on the parent
            heapify_up(parent(i));
        }
    }

public:
	//precondition: key is a valid value of type T
	// postcondition: returns true if key is found in the heap, false otherwise
    bool find(T key) const
    {
        for (size_t i = 0; i < A.size(); i++)
        {
            if (A[i] == key)
            {
                return true;
            }
        }

        return false;
    }
    
    //precondition: none
    // postcondition: returns the number of elements in the heap
    size_t size() const
    {
        return A.size();
    }

    // function to check if heap is empty or not
	//precondition: none
	// postcondition: returns true if the heap is empty, false otherwise
    bool empty()
    {
        return A.size() == 0;
    }

    // insert key into the heap
	//precondition: key is a valid value of type T
	// postcondition: key is added to the heap and the heap property is maintained
    void push(T key)
    {
        // insert the new element to the end of the vector
        A.push_back(key);

        // get element index and call heapify-up procedure
       heapify_up(static_cast<int>(size() - 1));
    }
	//precondition: none
	// postcondition: returns the minimum element in the heap without removing it
    T front()
    {
        if (empty())
        {
            throw out_of_range("Heap is empty.");
        }

        return A[0];
    }
	//precondition: none
	// postcondition: removes the minimum element from the heap and maintains the heap property
    void pop()
    {
        if (empty())
        {
            throw out_of_range("Heap is empty. Cannot pop.");
        }

        A[0] = A.back();
        A.pop_back();

        if (!empty())
        {
            heapify_down(0);
        }
    }

    template <typename U>
	friend ostream& operator<<(ostream& out, const MinHeap<U>& obj); // friend function to overload the << operator for printing the heap
};
//precondition: obj is a valid MinHeap object
// postcondition: prints the elements of the heap to the output stream
template<class T>
ostream& operator <<(ostream& out, const MinHeap<T>& obj)
{
    for (size_t i = 0; i < obj.A.size(); i++)
    {
        out << obj.A[i] << " ";
    }
    return out;
}

#endif // !MINHEAP_H


