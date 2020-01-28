//#include "CDA.h"
#include <iostream>
using namespace std;

template <typename T> 
class CDA{
    private:
        int front; 
        int end;
        T * array; 
        int length; 
        int capacity; 
        bool sorted; 
        int getNext(int p); 
        int getPre(int p);
        void resizeArray(bool flag);
        
    public: 
        void printArray(); 
        CDA();
        CDA(const CDA &a);
        CDA(int s);
        T& operator[](int i);
        void addEnd(T v);
        void addFront(T v);
        void delEnd();
        void delFront();
        int Length();
        int Capacity();
        int Clear();
        bool Ordered();
        int SetOrdered();
        T Select(int k);
        void InsertionSort();
        void QuickSort();
        void CountingSort(int m);
        int Search(T e);
        ~CDA();
};

template <typename T>
int CDA<T>::getNext(int p){
    if(p == (capacity-1)) return 0; 
    else return ++p; 
}

template <typename T>
int CDA<T>::getPre(int p){
    if(p == 0) return (capacity -1); 
    else return --p; 
}

template <typename T>
void CDA<T>::resizeArray(bool flag){
    int i = 0;
    int j = front; 
    T * newArray = new T[(flag ? (capacity*2) : (capacity/2))]; 
    while(i < length){
        newArray[i] = array[j]; 
        j = getNext(j); 
        i++; 
    }
    capacity = (flag ? (capacity*2) : (capacity/2));
    front = 0; 
    end = (length-1); 
    delete[] array; 
    array = newArray; 
}

template <typename T>
void CDA<T>::printArray(){
    for (int i = 0; i < capacity; i++){
        cout << " " << &array[i] << " : " << array[i]; 
        if(i == front) cout << "\t\t\t<----- Front"; 
        if(i == end) cout << "\t\t\t<----- End"; 
        cout << endl; 
    }
    cout << "front  : " << front << " || end       : " << end << endl; 
    cout << "length : " << length << " || capacity : " << capacity << endl; 
    cout << "Array  : "; 
    int j = front; 
    while(j != end){
        cout << array[j] << " " ; 
        j = getNext(j);
    }
    cout << endl; 
}

template <typename T>
CDA<T>::CDA(){
    array = new T[1];
    capacity = 1;
    length = 0;
    sorted = false;
    front = -1; 
    end = -1;
}

template <typename T>
CDA<T>::CDA(const CDA &a){
    front = a.front; 
    end = a.end; 
    array = a.array;
    length = a.length;
    capacity = a.capacity;
    sorted = a.sorted;
}

template <typename T>
CDA<T>::CDA(int s){
    array = new T[s];
    capacity = s;
    length = 0;
    sorted = false;
    front = -1; 
    end = -1;
}

template <typename T>
T& CDA<T>::operator[](int i){
    if(i < length){
        return array[((front + i)%capacity)];
    }else{
        cout << "Error: index out of bound" << endl; 
    }
}

template <typename T>
void CDA<T>::addEnd(T v){
    if (end != -1){
        end = getNext(end); 
        array[end] = v; 
        length++; 
    }
    else{
        array[0] = v; 
        length = 1; 
        front = 0; 
        end = 0;
    }
    if(length == capacity) resizeArray(true);
}

template <typename T>
void CDA<T>::addFront(T v){
    if (front != -1){
        front = getPre(front); 
        array[front] = v; 
        length++; 
    }
    else{
        array[0] = v; 
        length = 1; 
        front = 0; 
        end = 0;
    }
    if(length == capacity) resizeArray(true);
}

template <typename T>
void CDA<T>::delEnd(){
    if (end != -1){
        end = getPre(end);
        length--;
        if(end == front){
            end = front = -1; 
            Clear();
        }
        if(length <= (capacity * 0.25) && end != -1) resizeArray(false); 
        return; 
    }else{
        cout << "There are nothing in the array" << endl; 
        return;
    }
}

template <typename T>
void CDA<T>::delFront(){
    if (front != -1){
        front = getNext(front);
        length--;
        if(end == front){
            end = front = -1; 
            Clear();
        }
        if(length <= (capacity * 0.25) && end != -1) resizeArray(false); 
        return; 
    }else{
        cout << "There are nothing in the array" << endl; 
        return;
    }
    
}

template <typename T>
int CDA<T>::Length(){
    return length;
}

template <typename T>
int CDA<T>::Capacity(){
    return capacity;
}

template <typename T>
int CDA<T>::Clear(){
    delete[] array; 
    array = new T[1];
    capacity = 1;
    length = 0;
    sorted = false;
    front = -1; 
    end = -1;
    return 0; 
}

template <typename T>
bool CDA<T>::Ordered(){
    return sorted;
}

template <typename T>
int CDA<T>::SetOrdered(){
    return 0; 
}

template <typename T>
T CDA<T>::Select(int k){
    return array[(front + k)%capacity];
}

template <typename T>
void CDA<T>::InsertionSort(){
}

template <typename T>
void CDA<T>::QuickSort(){
}

template <typename T>
void CDA<T>::CountingSort(int m){
}

template <typename T>
int CDA<T>::Search(T e){
    if (sorted){
    }
    else{
    }
    return 0;
}

template <typename T>
CDA<T>::~CDA(){
    delete[] array; 
}
