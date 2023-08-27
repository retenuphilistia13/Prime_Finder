#include <iostream>

#include <vector>

#include<memory>

#include <type_traits>


#include"Prime.h"
#include"otherFuncs.h"

using namespace std;




int main()
{


    while (true) {
                std::cout << "\nEnter a positive number\n-1 to leave\n";
        std::string input;
        std::cin >> input;

        if (input == "-1") {
            break;
        }

        try {
            if (std::stod(input) == static_cast<int>(std::stod(input))) {
                std::unique_ptr<Prime> p = std::make_unique<Prime>(std::stoi(input));
                menu(p.get()); // Pass the raw pointer to the menu function
            } else {
                std::cout << "Invalid Float" << std::endl;
            }
        } catch (const std::exception&) {
            std::cout << "Invalid input. Please enter a valid number: ";
        }
    }
    return 0;
}


