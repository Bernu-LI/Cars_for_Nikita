#include <iostream>

#include "functions.h"

using namespace std;

int main() {
    std::string command;
    while (std::cin >> command) {
        if (command == "findFastSlowCars") {
            findFastSlowCar();
        }
        else if (command == "findMatchingCars") {
            findMatchingCars();
        }
        else if (command == "new_car") {
            new_car();
        }
        else {
            std::cout << "Invalid command entered" << std::endl;
        }
    }
    return 0;
}
