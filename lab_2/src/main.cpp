#include <iostream>

using namespace std;



class String {

    char *stringData;
    int length;
    int capacity;

  public:

};



int main() {
    String fStr;
    input(fStr, "\nEnter string:");
    print(fStr, "\nSource string: ");
    ++fStr;
    print(fStr, "\nCoded string: ");
    --fStr;
    print(fStr, "\nDecoded string: ");
    return 0;
}