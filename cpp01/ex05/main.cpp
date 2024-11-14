#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Testing all complaint levels:\n\n";

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "Testing invalid level:\n";
    harl.complain("INVALID");

    return 0;
}
