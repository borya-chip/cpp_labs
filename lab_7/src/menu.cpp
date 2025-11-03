#include<limits>
#include<iostream>
#include "menu.h"

void showMenu() {
  std::cout << "1. Read data from file" << std::endl;
  std::cout << "2. Add emloyee to file" << std::endl;
  std::cout << "3. Get a name based on the number of hours worked" << std::endl;
  std::cout << "4. Delete data from file" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "Your choice:";
}


