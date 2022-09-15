// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

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

  reverse_oreder("05/29/2018", "06/02/2018");
  return 0;
}
