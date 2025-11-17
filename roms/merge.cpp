// Hacked this together to join the ROMs.
// The order was 183, then 182.

#include <iostream>
#include <fstream>
#include <exception>

int main(int argc, char** argv)
{
    try
    {
        if (argc < 4)
        {
	    std::cerr << "Usage: " << argv[0] << " file1 file2 outfile" << std::endl;
	    return 3;
        }

        char c;
        std::ifstream file1(argv[1]);
        std::ifstream file2(argv[2]);
        std::ofstream outfile(argv[3]);
        while (!file1.eof())
        {
	    if (file2.eof())
	    {
		throw std::runtime_error("Input files do not have the same size.");
	    }
	    file1.read(&c, 1);
            outfile.write(&c, 1);
	    file2.read(&c, 1);
	    outfile.write(&c, 1);
        }
        file1.close();
        file2.close();
        outfile.close();
    }
    catch (std::exception& e)
    {
	std::cerr << e.what() << std::endl;
	return 1;
    }
    catch (...)
    {
	std::cerr << "Caught unknown exception." << std::endl;
	return 2;
    }

    return 0;
}
