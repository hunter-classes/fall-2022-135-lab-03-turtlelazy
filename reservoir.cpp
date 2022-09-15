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
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;

    while (fin >> cDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                   //ignorring the remaining columns

        // for example, to print the date and East basin storage:
        if(date==cDate){
            return eastSt;
        }
    }

    return 0;
}

double get_west_storage(std::string date)
{
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
    double westEl;

    while (fin >> cDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                   //ignorring the remaining columns

        // for example, to print the date and East basin storage:
        if (date == cDate)
        {
            return westSt;
        }
    }

    return 0;
}

double get_min_east()
{
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
    double westEl;

    double minSt;

    bool first = true;
    while (fin >> cDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        

        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        
        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                   //ignorring the remaining columns

        if (first) {
            minSt = eastSt;
            first = false;
        }

        if (eastSt < minSt)
        {
            minSt = eastSt;
        }
    }

    return minSt;
}

double get_max_east()
{
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
    double westEl;

    double maxSt;

    bool first = true;
    while (fin >> cDate >> eastSt >> eastEl >> westSt >> westEl)
    {

        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                   //ignorring the remaining columns

        if (first)
        {
            maxSt = eastSt;
            first = false;
        }

        if (eastSt > maxSt)
        {
            maxSt = eastSt;
        }
    }

    return maxSt;
}

std::string compare_basins(std::string date)
{
    double eastSt = get_east_storage(date);
    double westSt = get_west_storage(date);

    if(eastSt > westSt){
        return "East";
    }
    else if(westSt > eastSt){
        return "West";
    }

    else{
        return "Equal";
    }

    return "";
}