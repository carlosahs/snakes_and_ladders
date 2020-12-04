#include <iostream>

int main() {
    int i { 0 };

    std::cout << "enter a number \n";

    while (std::cin >> i) {
        if (i == 10) {
            std::cout << "Yes i like that number\n";
            break;
        }
    }

    return 0;
}
