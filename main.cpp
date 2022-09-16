/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Professor Zamansky
Assignment: Lab 2C
*/

// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  std::cout << "05/20/2018 East Storage: " << get_east_storage("05/20/2018") << std::endl;
  std::cout << "Minimum East Basin Storage: " << get_min_east() << std::endl;
  std::cout << "Maximum East Basin Storage: " << get_max_east() << std::endl;

  std::cout << "09/13/2018 East Storage: " << get_east_storage("09/13/2018") << std::endl;

  std::cout << "Compare Basin 09/13/2018: " << compare_basins("09/13/2018") << std::endl;
  std::cout << "Compare Basin 09/14/2018: " << compare_basins("09/14/2018") << std::endl;
  std::cout << "Compare Basin 09/15/2018: " << compare_basins("09/15/2018") << std::endl;

  reverse_oreder("05/29/2018", "06/02/2018");
  return 0;
}
