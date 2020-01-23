
#include <iostream>
#include "CDA.cpp"
using namespace std; 


int main(){
    
    CDA<int> a = CDA<int>(4); 
    cout << a.Capacity() << endl;

    return 0; 
}