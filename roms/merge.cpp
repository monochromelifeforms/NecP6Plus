// Hacked this together to join the ROMs.
// The order was 183, then 182.

#include <iostream>
#include <fstream>
#include <exception>
#include <cassert>

int main(int argc, char** argv)
{
    try
    {
        if (argc < 4)
        {
            std::cerr << "Usage: " << argv[0] << " file1 file2 outfile" << std::endl;
            return 3;
        }

        char c1, c2;
        std::ifstream file1(argv[1]);
        std::ifstream file2(argv[2]);
        std::ofstream outfile(argv[3]);
        while (true)
        {
            file1.read(&c1, 1);
            file2.read(&c2, 1);
            if (file1.eof())
            {
                if (file2.eof())
                {
                    break;
                }
                throw std::runtime_error("file1 is shorter than file2.");
            }
            if (file2.eof())
            {
                assert(!file1.eof());
                throw std::runtime_error("file1 is longer than file2.");
            }

            outfile.write(&c1, 1);
            outfile.write(&c2, 1);
        }
        file1.close();
        file2.close();
        outfile.close();
    }
    catch (std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "ERROR: Caught unknown exception." << std::endl;
        return 2;
    }
    return 0;
}
