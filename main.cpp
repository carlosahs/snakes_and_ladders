#include <iostream>
#include <stdexcept>

int main() {
    try {

    } catch (std::logic_error &e) {
        std::cerr << e.what() << "\n";
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << "\n";
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
