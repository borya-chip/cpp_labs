#include <iostream>
#include <cstring>
#include <limits>

class MyString {
private:
    char* str;
    size_t length;

public:
    MyString() : str(nullptr), length(0) {
        str = new char[1];
        str[0] = '\0';
    }

    MyString(const char* s) {
        if (s == nullptr) {
            str = new char[1];
            str[0] = '\0';
            length = 0;
        } else {
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    void input() {
        char buffer[1000];
        std::cout << "Enter string: ";
        std::cin.getline(buffer, 1000);

        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy(str, buffer);
        
        std::cout << "String successfully entered!\n";
    }

    void print() const {
        if (str != nullptr) {
            std::cout << "String: '" << str << "'\n";
            std::cout << "Length: " << length << " characters\n";
        } else {
            std::cout << "String is empty\n";
        }
    }

    MyString intersection(const MyString& other) const {
        if (str == nullptr || other.str == nullptr || length == 0 || other.length == 0) {
            return MyString();
        }

        char* temp = new char[length + 1];
        int count = 0;

        for (size_t i = 0; i < length; i++) {
            if (strchr(other.str, str[i]) != nullptr && 
                strchr(temp, str[i]) == nullptr) {
                temp[count++] = str[i];
            }
        }
        temp[count] = '\0';

        MyString result(temp);
        delete[] temp;
        return result;
    }

    const char* c_str() const {
        return str;
    }

    size_t getLength() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0 || str == nullptr || str[0] == '\0';
    }
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "\n=== STRING OPERATIONS MENU ===\n";
    std::cout << "1. Enter first string\n";
    std::cout << "2. Enter second string\n";
    std::cout << "3. Show first string\n";
    std::cout << "4. Show second string\n";
    std::cout << "5. Find strings intersection\n";
    std::cout << "6. Show strings information\n";
    std::cout << "7. Clear strings\n";
    std::cout << "8. Exit program\n";
    std::cout << "Choose action (1-8): ";
}

int main() {
    setlocale(LC_ALL, "");
    
    MyString str1, str2;
    int choice;
    
    std::cout << "String operations program\n";
    
    do {
        showMenu();
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                std::cout << "\n--- Enter first string ---\n";
                str1.input();
                break;
            }
            
            case 2: {
                std::cout << "\n--- Enter second string ---\n";
                str2.input();
                break;
            }
            
            case 3: {
                std::cout << "\n--- First string ---\n";
                str1.print();
                break;
            }
            
            case 4: {
                std::cout << "\n--- Second string ---\n";
                str2.print();
                break;
            }
            
            case 5: {
                std::cout << "\n--- Strings intersection ---\n";
                if (str1.isEmpty() || str2.isEmpty()) {
                    std::cout << "One or both strings are empty!\n";
                    std::cout << "Please enter both strings first.\n";
                } else {
                    std::cout << "First string: ";
                    str1.print();
                    std::cout << "Second string: ";
                    str2.print();
                    
                    MyString result = str1.intersection(str2);
                    std::cout << "Intersection: ";
                    result.print();
                    
                    if (result.isEmpty()) {
                        std::cout << "No common characters found.\n";
                    }
                }
                break;
            }
            
            case 6: {
                std::cout << "\n--- Strings information ---\n";
                std::cout << "First string: ";
                str1.print();
                std::cout << "Second string: ";
                str2.print();
                break;
            }
            
            case 7: {
                std::cout << "\n--- Clear strings ---\n";
                str1 = MyString();
                str2 = MyString();
                std::cout << "Strings cleared!\n";
                break;
            }
            
            case 8: {
                std::cout << "\nExiting program...\n";
                break;
            }
            
            default: {
                std::cout << "\nInvalid choice! Please choose from 1 to 8.\n";
                break;
            }
        }
        
        if (choice != 8) {
            std::cout << "\nPress Enter to continue...";
            std::cin.get();
        }
        
    } while (choice != 8);
    
    return 0;
}