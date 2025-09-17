#include "rpn.hpp"
#include <iomanip>
#include <cstdlib>

int main(int ac, char **av)
{
    rpn rpn_obj;
    if (ac != 2)
    {
        std::cerr << "Error: args\n";
        exit(0);
    }
    else
    {
        try
        {
            rpn_obj.ReadInput(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        
    }
}

