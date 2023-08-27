//main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <algorithm>
#include <future>

#include "Prime.h"
#include"otherfuncs.h"

void parallelAssignBelowPrime(Prime *p) {
    int num = p->GetNum();
    int numThreads = std::thread::hardware_concurrency();
    int chunkSize = num / numThreads;

    std::vector<std::future<void>> futures;

    for (int i = 0; i < numThreads; ++i) {

        int start = i * chunkSize + 2;
        int end = (i == numThreads - 1) ? num : (i + 1) * chunkSize + 1;

        futures.push_back(std::async(std::launch::async, [p, start, end, num]() { // Add 'num' to the capture list
            for (int j = start; j <= end; ++j) {
                if (p->checkPrime(j) && j != num) {
                    p->setPrimes(j);
                    p->SetbelowPrimeNum(p->GetbelowPrimeNum() + 1);
                }
            }
        }));
    }

    for (auto &future : futures) {
        future.wait();
    }
}


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
                auto p = std::make_shared<Prime>(std::stoi(input));

                  // Use a future to wait for parallelAssignBelowPrime to finish
                std::future<void> assignmentFuture = std::async(std::launch::async, parallelAssignBelowPrime, p.get());

                // Wait for parallelAssignBelowPrime to finish
                assignmentFuture.wait();
 // p->printBelowPrime();
                menu(p.get());


            } else {
                std::cout << "Invalid input, Please enter a valid Integer number" << std::endl;
            }
        } catch (const std::exception&) {
            std::cout << "Invalid input. Please enter a valid number: ";
        }
    }
    return 0;
}


