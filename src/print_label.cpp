#include "p6.h"

#include <exception>

int main(int argc, char* argv[])
{
    try
    {
        std::string text{"Hello, World!"};
        std::cout << text << "\n" 
                  << p6::highspeed12
                  << p6::underline << text << "\n"
                  << p6::tripplewide << p6::doublehigh << text << "\n"
                  << p6::reset << p6::doublewide << p6::doublehigh << text << "\n"
                  << p6::reset << p6::cpi20 << text << p6::subscript << text << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception occurred" << std::endl;
        return 1;
    }
    return 0;
}