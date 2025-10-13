#include<iostream>
#include<iomanip>

using namespace std;

template<typename T>
class MyArray{
    T* data;
    int size;
    public:
    template<typename U>
    friend ostream& operator <<(ostream & os,const MyArray<U>& array);
    template<typename U>
    friend istream& operator >>(istream& in,MyArray<U>& array); 
    MyArray():data(NULL),size(0){}

    ~MyArray(){
      delete [] data;
    }

    T& operator[](int ind)
     {       
         return data[ind];
     }
     
     MyArray(const MyArray &other):size(other.size){
      data = new T[other.size];

      for(int i = 0;i < other.size;i++){
         data[i] = other.data[i];
      }
     }
      
      MyArray& operator =(const MyArray& other){
         if(&other != this){
            delete [] data;
            size = other.size;
             data = new T[size];
            for(int i = 0;i < other.size;i++){
               data[i] = other.data[i];
            }
         }

         return *this;
      }

     void printArray(){
      for(int i = 0;i < size;i++){
         cout << setw(3) << data[i];
         cout << endl;
      }
     }

     void pushElement(const T &element){
      T *newData = new T[size + 1];

      for(int i = 0;i < size;i++){
         newData[i] = data[i];  
      }

      newData[size] = element;
      delete [] data;
      data = newData;
      size++;
     }

};
template<typename T>
ostream & operator <<(ostream &os,const MyArray<T>& array){
     for(int i = 0;i < array.size;i++){
      os << setw(3) <<array.data[i];
     }
     os << endl;
     return os;
}

template<typename T>
istream & operator >>(istream &in,MyArray<T>& array){
   for(int i = 0;i < array.size;i++){
      in >> array.data[i];
   }

   return in;
}
int getValue() {
    int value;
    
    while (true) {
        if (cin >> value) {
            if (cin.get() == '\n') {
                return value;
            }
        }
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error, enter a valid number: ";
    }
} 

int main(){

 MyArray<int> arr;
  int value;
  cout << "Enter array element: ";
  value = getValue();
  arr.pushElement(value);
  cout << arr;
   return 0;
}