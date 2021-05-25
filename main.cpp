#include <iostream>
#include <cassert>
#include <vector>

int scanInteger(std::string tag, int min, int max)
{
    assert(min < max);
    int value = 0;
    do
    {
        std::cout << "Please enter the " << tag << ": ";
        std::cin >> value;
        if (value < min || value > max)
            std::cout << "Input error: value should be in between " << min << " and " << max << "\n";
    } while(value < min || value > max);

    return value;
}

void readTheVector(std::vector<int> vector)
{
    if (vector.empty()) std::cout << "Vector is empty!\n";
    else
    {
        for (int i = 0; i < vector.size(); i++)
        {
            std::cout << vector[i] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<int> removeEqualsTo(std::vector<int> vector, int number)
{
    if (vector.empty())
    {
        std::cout << "Vector is empty!\n";
        return vector;
    }
    else
    {
        std::vector<int> filteredVector;
        for (int i = 0; i < vector.capacity(); i++)
        {
            if (vector[i] != number) filteredVector.push_back(vector[i]);
        }
        return filteredVector;
    }

}

int main() {
    const int MAX_VECTOR_CAPACITY = 20; // Just for convenience
    const int MIN_VECTOR_CAPACITY = 1;

    int n = scanInteger("vector initial capacity", MIN_VECTOR_CAPACITY, MAX_VECTOR_CAPACITY);
    std::vector<int> numbers(n);
    std::cout << "Vector is created. Capacity is " << n << ".\n";
    std::cout << "Please enter the numbers for vector: \n";
    std::cout << "------------------------------------ \n";

    for (int i = 0; i < numbers.capacity(); i++)
    {
        numbers[i] = scanInteger("element " + std::to_string(i), -2000000000, 2000000000);
    }

    std::cout << "The vector is filled:\n";
    readTheVector(numbers);

    int numberToCompare = scanInteger("number to compare", -2000000000, 2000000000);
    numbers = removeEqualsTo(numbers, numberToCompare);

    std::cout << "Vector is filtered. Filtered vector is: \n";
    readTheVector(numbers);
    return 0;
}
