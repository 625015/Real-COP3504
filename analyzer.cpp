// Liam Ballard
// COP3504
// Lab 05
// Partner: Nick Lucindo

#include "stringdata.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

int linearSearch (std::vector<std::string> container, std::string element) {
    // Uses linear search to find specified element in container
    // Returns index of element, or -1 if not found
        for (int i = 0; i < container.size(); ++i)
        {
            if (container.at(i) == element)
            {
                return i;
            }
        }
        return -1;
}

int binarySearch(std::vector<std::string> container, std::string element) {
    // Uses binary search to find specified element in container
    // Returns index of element, or -1 if not found
    int low_index = 0;
    int middle_index = 0;
    int high_index = container.size() - 1;
    while (low_index <= high_index)
    {
        middle_index = (high_index + low_index) / 2;
        // If x is greater, ignore left half
        if (container.at(middle_index) > element)
        {
            high_index = middle_index - 1;
        }

        // If x is smaller, ignore right half
        else if (container.at(middle_index) < element)
        {
            low_index = middle_index + 1;
        }

        // If element is in middle of vector
        else
        {
            return middle_index;
        }
    }

    // Element was not in the vector
    return -1;
}


int main()
{
    std::vector<std::string> container = getStringData();

    // Test time for "not_here"
    auto start_time = std::chrono::high_resolution_clock::now();
    std::cout << linearSearch(container, "not-here") << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by linear search for not-here: " << duration.count() << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    std::cout << binarySearch(container, "not-here") << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by binary seach for not-here: " << duration.count() << std::endl;

    // Test time for "aaaaa"
    start_time = std::chrono::high_resolution_clock::now();
    std::cout << linearSearch(container, "aaaaa") << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by linear search for aaaaa: " << duration.count() << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    std::cout << binarySearch(container, "aaaaa") << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by binary search for aaaaa: " << duration.count() << std::endl;

    // Test time for "mzzzz"
    start_time = std::chrono::high_resolution_clock::now();
    std::cout << linearSearch(container, "mzzzz") << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by linear search for mzzzz: " << duration.count() << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    std::cout << binarySearch(container, "mzzzz") << std::endl;
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by binary search for mzzzz: " << duration.count() << std::endl;
}
