#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

void reverse_oreder(std::string date1, std::string date2)
{
    std::string endPrint = "";

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;
    getline(fin, junk);

    std::string cDate;
    double eastSt;
    double eastEl;
    double westSt;
    std::string westEl;

    bool add = true;
    while (fin >> cDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                   //ignorring the remaining columns

        // for example, to print the date and East basin storage:
        if(!add){
            if (cDate == date1){
                add = true;
            }
        }

        if(add){
            endPrint = cDate + " : " + westEl + "\n" + endPrint;

            if (cDate == date2){
                add = false;
            }
        }
        
    }

    std::cout << endPrint;

}