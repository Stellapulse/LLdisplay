#include<iostream>
using namespace std;


template <class T>// template make class usable for any data type

class Airthmatic{
    private:
    T a,b;
    public:
    Airthmatic(T a, T b); // Constructor to initialize a and b
        T add();
        T sub();
    };   
 
template <class T>
Airthmatic<T>::Airthmatic(T a, T b){//:: is used to define the function outside the class,<T> is used to define the template
    this->a=a;// 'this' pointer is used to refer to the current object
    this->b=b;// current object is the object that is being created expample ar,br 
}   

template <class T> 
T Airthmatic<T>::add() {
    T c;
  c= a + b;
  return c; // Return the sum of a and b
}
template <class T>
T Airthmatic<T>::sub() {
    T c;
    c= a - b; 
    return c;// Return the difference of a and b
}

int main(){
    Airthmatic<int> ar(10,5); // Create an instance of Airthmatic with int type
    cout<<ar.add()<<endl; // Call the add method and print the result
    cout<<ar.sub()<<endl; // Call the sub method and print the result

    Airthmatic<float> br(10.5,5.5); // Create an instance of Airthmatic with float type
    cout<<br.add()<<endl; // Call the add method and print the result
    cout<<br.sub()<<endl; // Call the sub method and print the result

    return 0; // Return success
}