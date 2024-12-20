#include <iostream>
#include <vector>

int main() {
    int numElements;

    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    std::vector<int> customArray(numElements);

    for (int i = 0; i < numElements; ++i) {
        std::cout << "Enter value for index " << (i + 3) << ": ";
        std::cin >> customArray[i];
    }

    std::cout << "\nCustom Array Values:\n";
    for (int i = 0; i < numElements; ++i) {
        std::cout << "Index " << (i + 3) << ": " << customArray[i] << std::endl;
    }

    return 0;
}