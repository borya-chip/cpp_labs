#include "menu.h"
#include "myalgorithm.h"
#include "mycontainer.h"
#include "myexception.h"
#include "myiterator.h"
#include<limits>

int main() {

  char choice;

  MyContainer<int> matrix(1, 1);
  matrix.fill(0);

  do {
    showMenu();

    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
      case '1':
        inputMatrix<int>(matrix);
        break;
      case '2':
        printMatrix<int>(matrix);
        break;
      case '3':
        findElement<int>(matrix);
        break;
      case '4':
        sortMatrix<int>(matrix);
        break;
      case '0':
        std::cout << "Exit" << std::endl;
        break;
      default:
        std::cout << "Error" << std::endl;
        break;
    }

  } while (choice != '0');

  return 0;
}
