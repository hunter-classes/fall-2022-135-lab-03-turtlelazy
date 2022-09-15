// add your code as appropriate 
#include <iostream>
#include "reservoir.h"

int main()
{
  std::cout << get_east_storage("05/20/2018") << std::endl;
  std::cout << get_min_east() << std::endl;
  std::cout << get_max_east() << std::endl;

  std::cout << get_east_storage("09/13/2018") << std::endl;
  std::cout << get_west_storage("09/13/2018") << std::endl;

  std::cout << compare_basins("09/13/2018") << std::endl;
  std::cout << compare_basins("09/14/2018") << std::endl;
  std::cout << compare_basins("09/15/2018") << std::endl;

  return 0;
}
