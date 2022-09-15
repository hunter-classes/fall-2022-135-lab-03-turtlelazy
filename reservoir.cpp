// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

double get_east_storage(std::string date)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;
    getline(fin,junk);

    std::string cDate;
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;

    while (fin >> cDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                   //ignorring the remaining columns

        // for example, to print the date and East basin storage:
        std::cout << cDate << " " << eastSt << std::endl;
    }

    return 0;
}