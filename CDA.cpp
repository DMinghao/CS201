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
        bool resizeArray(bool flag);
        void printArray(); 
    public: 
        CDA();
        CDA(const CDA &a);
        CDA(int s);
        T& operator[](int i);
        void AddEnd(T v);
        void AddFront(T v);
        void DelEnd();
        void DelFront();
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
    if(p == end) return end; 
    else if(p == (capacity-1)) return 0; 
    else return ++p; 
}

template <typename T>
bool CDA<T>::resizeArray(bool flag){
    int i = 0;
    T * newArray = new T[capacity]; 
    capacity = flag ? capacity*2 : capacity/2;
    while(i < length){
        newArray[i] = array[front]; 
        front = getNext(front); 
        i+=1; 
    }
    front = 0; 
    end = (length-1); 
    array = newArray; 
    return flag; 
}

template <typename T>
void CDA<T>::printArray(){
    int i = 0; 
    int j = front; 
    while(i<length){
        cout << " " << array[j] << " "; 
        j = getNext(j);
        i++
    }
    cout << endl; 
}

template <typename T>
CDA<T>::CDA(){
}

template <typename T>
CDA<T>::CDA(const CDA &a){
    front = a.front; 
    end = a.end; 
    array = a.array;
    length = a.length;
    capacity = a.capacity;
    sorted = a.sorted;
    empty = a.empty; 
}

template <typename T>
CDA<T>::CDA(int s){
    array = new T[s];
    capacity = s;
    length = 0;
    sorted = false;
}

template <typename T>
T& CDA<T>::operator[](int i){
    if (i > length){
        cout << "Error: Index out of bound" << endl;
        return NULL;
    }
    else{
        return &array[i];
    }
}

template <typename T>
void CDA<T>::AddEnd(T v){
    if (end != NULL){
        array[end+1] = v; 
        end+=1; 
        if(length == capacity) resizeArray(true); 
    }
    else{
        array[0] = v; 
        size = 1; 
        front = 0; 
        end = 0;
    }
}

template <typename T>
void CDA<T>::AddFront(T v){
    if (front != NULL){
    }
    else
        return;
}

template <typename T>
void CDA<T>::DelEnd(){
    if (end != NULL){
    }
    else
        return;
}

template <typename T>
void CDA<T>::DelFront(){
    if (front != NULL){
    }
    else
        return;
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
}
