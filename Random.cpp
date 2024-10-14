#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int random_number = std::rand() % 10 + 1; // generate random number between 1 and 10
    std::cout << "Random number between 1 and 10: " << random_number << std::endl;
    return 0;
}

