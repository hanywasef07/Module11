//Name: Hany, Aleeza,Thanh, Victor, and Jacob
// Date: 11/09/2026
// Description: Module 11 - Balanced Trees Implementation

#include <iostream>
#include "input.h"
#include "MinHeap.h"
#include "MaxHeap.h"
#include "HeapMerge.h"

using namespace std;

// Function Prototypes
char menuOption();
void option1();
void option1A();
void option1B();
void option2();

int main()
{
    bool running = true;
    char option;

    while (running)
    {
        system("cls");

        option = menuOption();
        switch (option)
        {
        case '1':
        {
			option1();

            cout << "\n\n";
            system("pause");
            break;
        }
        case '2':
        {
            option2();
            cout << "\n\n";
            system("pause");
            break;

        }
        case '3':
        {
            cout << "\n\n";
            system("pause");
            break;

        }
        case '0':
            cout << "Exiting the program.\n";
            running = false;
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}

//main menu
char menuOption()
{
    cout << "\tCMPR131 Chapter 11: Heaps by Hany, Aleeza, Thanh, Victor, and Jacob (11/09/2026)\n";
    cout << "\t" << string(100, char(205));
    cout << "\n\t\t1> Heap using vector";
    cout << "\n\t\t2> Union and intersect of heaps";
    cout << "\n\t\t3> Heap in C++ STL\n";
    cout << "\t" << string(100, char(196));
    cout << "\n\t\t0> Exit\n";
    cout << "\t" << string(100, char(205));

    char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,3,0")));
    return option;
}

//precondition: none
// postcondition: displays the menu for heap operations and handles user input for min and max heaps
void option1()
{
	bool running = true;
    while (running)
    {
        system("cls");
        cout << "\t1> Heap using vector\n";
        cout << "\t" << string(100, char(205));
        cout << "\n\t\tA> Min heap";
        cout << "\n\t\tB> Max heap\n";
        cout << "\t" << string(100, char(196));
        cout << "\n\t\t0> Return\n";
        cout << "\t" << string(100, char(205));
        char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("A,B,0")));
        switch (option)
        {
        case 'A':
			option1A(); // Call function for Min Heap

			cout << "\n\n";
			system("pause");
            break;
        case 'B':
			option1B(); // Call function for Max Heap
            cout << "\n\n";
            system("pause");
            break;
        case '0':
            running = false; // Exit the loop to go back to main menu
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
	}

}

//precondition: none
// postcondition: displays the menu for min heap operations and handles user input for various heap operations
void option1A()
{
    MinHeap<int> heap;
    bool running = true;
    while (running)
    {
        system("cls");
        cout << "\tA> Min Heap\n";
        cout << "\t" << string(100, char(205));
        cout << "\n\t\t1> size";
        cout << "\n\t\t2> empty";
        cout << "\n\t\t3> push";
        cout << "\n\t\t4> front";
        cout << "\n\t\t5> pop";
        cout << "\n\t\t6> display\n";
        cout << "\t" << string(100, char(196));
        cout << "\n\t\t0> return\n";
        cout << "\t" << string(100, char(205));
        char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,3,4,5,6,0")));
        switch (option)
        {
        case '1':

        {
            // Return the size of the heap
            cout << "\n\t\tSize of the heap: " << heap.size() << "\n\n";
            system("pause");
            break;
        }
        case '2':
        {
            if (heap.empty())
            {
                cout << "\n\t\tThe heap is empty.\n";
            }
            else
            {
                cout << "\n\t\tThe heap is not empty.\n";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case '3':
        {
            // Push a new element into the heap
            int value = inputInteger("\n\t\tEnter an integer element to push onto the heap: ");

            heap.push(value);

            cout << "\n\n";
            system("pause");
            break;
        }
        case '4':
        {
            // Return the first element of the heap
            try
            {
                int value = heap.front();

                cout << "\n\t\tThe first element of the heap: " << value << "\n";
            }
            catch (const out_of_range& e)
            {
                cout << "\n\t\tERROR: " << e.what() << "\n";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case '5':
        {
            // Remove the first element of the heap
            try
            {
                int value = heap.front();

                heap.pop();

                cout << "\n\t\tThe first element of the heap " << "(" << value << ") " << "has been removed\n";
            }
            catch (const out_of_range& e)
            {
                cout << "\n\t\tERROR: " << e.what() << "\n";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case '6':
        {
            // Display all elements in the heap
            if (heap.empty())
            {
                cout << "\n\t\tThe heap is empty.\n";
            }
            else
            {
                cout << "\n\t\t" << heap << "\n";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case '0':
            running = false; // Exit the loop to go back to previous menu
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }
}

//precondition: none
// postcondition: displays the menu for max heap operations and handles user input for various heap operations
void option1B()
{
    MaxHeap<int> heap;
    bool running = true;
    while (running)
    {
        system("cls");
        cout << "\tB> Max Heap\n";
        cout << "\t" << string(100, char(205));
        cout << "\n\t\t1> size";
        cout << "\n\t\t2> empty";
        cout << "\n\t\t3> push";
        cout << "\n\t\t4> front";
        cout << "\n\t\t5> pop";
        cout << "\n\t\t6> display\n";
        cout << "\t" << string(100, char(196));
        cout << "\n\t\t0> return\n";
        cout << "\t" << string(100, char(205));
        char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,3,4,5,6,0")));
        switch (option)
        {
        case '1':
        {
            // Return the size of the heap
            cout << "\n\t\tSize of the heap: " << heap.size() << "\n";
			cout << "\n\n";
			system("pause");
            break;
        }
        case '2':
        {
            // Check if the heap is empty
            if (heap.empty())
            {
                cout << "\n\t\tThe heap is empty.\n";
            }
            else
            {
                cout << "\n\t\tThe heap is not empty.\n";
            }
			cout << "\n\n";
			system("pause");
            break;
        }
        case '3':
        {
            // Push a new element into the heap
            int value = inputInteger("\n\t\tEnter an integer element to push onto the heap: ");
            heap.push(value);

			cout << "\n\n";
			system("pause");
            break;
        }
        case '4':
        {
            // Return the first element of the heap
            try
            {
                int value = heap.front();

                cout << "\n\t\tThe first element of the heap: " << value << "\n";
            }
            catch (const out_of_range& e)
            {
                cout << "\n\t\tERROR: " << e.what() << "\n";
            }
			cout << "\n\n";
			system("pause");
            break;
        }
        case '5':
        {
            // Remove the first element of the heap
            try
            {
                int value = heap.front();

                heap.pop();

                cout << "\n\t\tThe first element of the heap " << "(" << value << ") " << "has been removed\n";
            }
            catch (const out_of_range& e)
            {
                cout << "\n\t\tERROR: " << e.what() << "\n";
            }
			cout << "\n\n";
			system("pause");
            break;
        }
        case '6':
        {
            // Display all elements in the heap
            if (heap.empty())
            {
                cout << "\n\t\tThe heap is empty.\n";
            }
            else
            {
                cout << "\n\t\t" << heap << "\n";
            }
			cout << "\n\n";
			system("pause");
            break;
        }
        case '0':
            running = false; // Exit the loop to go back to previous menu
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }
}

//precondition: none
// postcondition: displays the menu for union and intersection of heaps and handles user input for various heap operations
void option2()
{
    bool running = true;

	HeapMerge<int> merge; // Create an instance of HeapMerge for integer heaps

    // Create Max Heaps
    MaxHeap<int> maxHeap1;
    MaxHeap<int> maxHeap2;

    maxHeap1.push(12);
    maxHeap1.push(5);
    maxHeap1.push(6);
    maxHeap1.push(2);

    maxHeap2.push(12);
    maxHeap2.push(9);
    maxHeap2.push(6);

    // Create Min Heaps
    MinHeap<int> minHeap1;
    MinHeap<int> minHeap2;

    minHeap1.push(2);
    minHeap1.push(5);
    minHeap1.push(6);
    minHeap1.push(12);

    minHeap2.push(6);
    minHeap2.push(12);
    minHeap2.push(9);

    while (running)
    {
        system("cls");

        cout << "\t2> Union and intersect heap\n";
        cout << "\t" << string(100, char(205));

        cout << "\n\t\tA> Union two max Heaps";
        cout << "\n\t\tB> Intersect two max Heaps";
        cout << "\n\t\tC> Union two min Heaps";
        cout << "\n\t\tD> Intersect two min Heaps\n";

        cout << "\t" << string(100, char(196));
        cout << "\n\t\t0> return\n";
        cout << "\t" << string(100, char(205));
        char option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,C,D,0")));

        switch (option)
        {
        case 'A':
        {
            // Union of two Max Heaps
            MaxHeap<int> result = merge.heapUnion(maxHeap1, maxHeap2);

            cout << "\n\t\tMax heap1: " << maxHeap1 << "\n";
            cout << "\n\t\tMax heap2: " << maxHeap2 << "\n";
            cout << "\n\t\tMerged max heap: " << result << "\n";
			cout << "\n\n";
			system("pause");
            break;
        }

        case 'B':
        {
            // Intersection of two Max Heaps
            MaxHeap<int> result = merge.heapIntersection(maxHeap1, maxHeap2);

            cout << "\n\t\tMax heap1: " << maxHeap1 << "\n";
            cout << "\n\t\tMax heap2: " << maxHeap2 << "\n";
            cout << "\n\t\tIntersect heap: " << result << "\n";
			cout << "\n\n";
			system("pause");
            break;
        }

        case 'C':
        {
            // Union of two Min Heaps
            MinHeap<int> result = merge.heapUnion(minHeap1, minHeap2);

            cout << "\n\t\tMin heap1: " << minHeap1 << "\n";
            cout << "\n\t\tMin heap2: " << minHeap2 << "\n";
            cout << "\n\t\tMerged minheap: " << result << "\n";
			cout << "\n\n";
			system("pause");
            break;
        }

        case 'D':
        {
            // Intersection of two Min Heaps
            MinHeap<int> result = merge.heapIntersection(minHeap1, minHeap2);

            cout << "\n\t\tMin heap1: " << minHeap1 << "\n";
            cout << "\n\t\tMin heap2: " << minHeap2 << "\n";
            cout << "\n\t\tIntersect min heap: " << result << "\n";
			cout << "\n\n";
			system("pause");
            break;
        }

        case '0':
        {
            running = false;
            break;
        }

        default:
        {
            cout << "\n\t\tInvalid option. Please try again.\n";
            break;
        }
        }
    }
}