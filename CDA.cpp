//#include "CDA.h"
#include <iostream>
using namespace std;

template <typename T> 
class CDA{
    private:
        int front; 
        int end;
        T * array; 
        T nothing; 
        int length; 
        int capacity; 
        bool sorted; 
        int getNext(int p); 
        int getPre(int p);
        void resizeArray(bool flag);
        T kthSmallest(T arr[], int l, int r, int k);
        void iSort(T arr[], int low, int high);
        void qSort(T arr[], int low, int high);
    public: 
        void printArray(); 
        CDA();
        CDA(const CDA &a);
        CDA(int s);
        CDA& operator=(const CDA &a); 
        T& operator[](int i);
        void AddEnd(T v);
        void AddFront(T v);
        void DelEnd();
        void DelFront();
        int Length();
        int Capacity();
        void Clear();
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
    return (p == (capacity-1)) ? 0 : ++p; 
}

template <typename T>
int CDA<T>::getPre(int p){
    return (p == 0) ? (capacity -1) : --p; 
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
        if(i == front) cout << "\t\t<----- Front"; 
        if(i == end) cout << "\t\t<----- End"; 
        cout << endl; 
    }
    cout << "front  : " << front << " || end       : " << end << endl; 
    cout << "length : " << length << " || capacity  : " << capacity << endl; 
    cout << "Array  : "; 
    for(int j = front; j != getNext(end); j = getNext(j)) cout << array[j] << " " ; 
    cout << endl; 
}

template <typename T>
CDA<T>::CDA(){
    array = new T[1];
    capacity = 1;
    length = 0;
    sorted = false;
    front = end = -1; 
}

template <typename T>
CDA<T>::CDA(const CDA &a){
    if(this != &a){
        front = a.front; 
        end = a.end; 
        length = a.length;
        capacity = a.capacity;
        sorted = a.sorted;
        array = new T[capacity];
        for(int i = 0; i < capacity; i++) array[i] = a.array[i];
    }
}

template <typename T>
CDA<T>::CDA(int s){
    array = new T[s];
    capacity = s;
    length = s;
    sorted = false;
    front = 0;
    end = length - 1;  
}

template <typename T> 
CDA<T>& CDA<T>::operator=(const CDA &a){
    if(this != &a){
        front = a.front; 
        end = a.end; 
        length = a.length;
        capacity = a.capacity;
        sorted = a.sorted;
        array = new T[capacity];
        for(int i = 0; i < capacity; i++) array[i] = a.array[i];
        return *this; 
    }
}

template <typename T>
T& CDA<T>::operator[](int i){
    if(i < length){
        return array[((front + i)%capacity)];
    }else{
        cout << "Error: index out of bound" << endl; 
        return nothing; 
    } 
}

template <typename T>
void CDA<T>::AddEnd(T v){
    if (end != -1){
        end = getNext(end); 
        array[end] = v; 
        length++; 
        if(v <= array[getPre(end)]) sorted = false; 
    }
    else{
        array[0] = v; 
        length = 1; 
        front = end = 0; 
        sorted = true; 
    }
    if(length == capacity) resizeArray(true);
}

template <typename T>
void CDA<T>::AddFront(T v){
    if (front != -1){
        front = getPre(front); 
        array[front] = v; 
        length++; 
        if(v >= array[getNext(front)]) sorted = false; 
    }
    else{
        array[0] = v; 
        length = 1; 
        front = end = 0; 
        sorted = true; 
    }
    if(length == capacity) resizeArray(true);
}

template <typename T>
void CDA<T>::DelEnd(){
    if(end == front){
        end = front = -1; 
        Clear();
        return; 
    }
    if (end != -1){
        end = getPre(end);
        length--;
        if(length <= (capacity * 0.25)) resizeArray(false); 
        return; 
    }else{
        cout << "There are nothing in the array" << endl; 
        return;
    }
}

template <typename T>
void CDA<T>::DelFront(){
    if(end == front){
        end = front = -1; 
        Clear();
        return; 
    }
    if (front != -1){
        front = getNext(front);
        length--;
        if(length <= (capacity * 0.25)) resizeArray(false); 
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
void CDA<T>::Clear(){
    delete [] array; 
    array = new T[1]; 
    capacity = 1;
    length = 0;
    sorted = false;
    front = end = -1; 
}

template <typename T>
bool CDA<T>::Ordered(){
    return sorted;
}

template <typename T>
int CDA<T>::SetOrdered(){
    int j = front; 
    while(j != end){
        if(array[j] > array[getNext(j)]) return -1; 
        j = getNext(j); 
    }
    return 1; 
}

template <typename T>
T CDA<T>::Select(int k){
    if(sorted && k < length) return array[((front+(k-1))%capacity)];
    else{
        T *arr = new T[length]; 
        for(int i = 0; i < length; i++) arr[i] = array[((front + i)%capacity)];
        T ans =  kthSmallest(arr, 0, length-1, k);
        delete [] arr; 
        return ans; 
    }
}

template <typename T>
T CDA<T>::kthSmallest(T arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1) { 
        T x = arr[(l+r)/2], index = l; 
        for (int j = l; j <= r - 1; j++) { 
            if (arr[j] <= x) { 
                swap(arr[index], arr[j]); 
                index++; 
            } 
        } 
        swap(arr[index], arr[r]); 
        if (index - l == k - 1) return arr[index]; 
        if (index - l > k - 1) return kthSmallest(arr, l, index - 1, k); 
        return kthSmallest(arr, index + 1, r, k - index + l - 1); 
    } 
    return *(new T); 
}

template <typename T>
void CDA<T>::InsertionSort(){
    if(sorted) return; 
    int i, key, j;  
    for (i = getNext(front); i != getNext(end); i = getNext(i)){  
        key = array[i];  
        j = getPre(i);  
        while (j != getPre(front) && array[j] > key) {  
            array[getNext(j)] = array[j];  
            j = getPre(j);  
        } 
        array[getNext(j)] = key;  
    } 
}

template <typename T>
void CDA<T>::iSort(T arr[], int low, int high)  {  
    if(high <= low) return; 
    for (int i = low; i <= high; i++){  
        T key = arr[i];  
        int j = i - 1; 
        while (j >= 0 && arr[j] > key){  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;
    }
}

template <typename T>
void CDA<T>::qSort(T arr[], int low, int high){
    if(high <= low) return; 
    T pivot = arr[low] + arr[high] + arr[(low + high) / 2] - min(min(arr[low], arr[high]),arr[(low + high) / 2]) - max(max(arr[low], arr[high]), arr[(low + high) / 2]);
    int l = low; 
    int r = high; 
    while(l < r){
        while(arr[l] < pivot){
            ++l; 
            if(l == r) break; 
        }
        while(arr[r] > pivot){
            --r; 
            if(l == r) break; 
        }
        swap(arr[l], arr[r]); 
    }
    if(((r-1) - low) >= 10000) qSort(arr, low, r-1); 
    else iSort(arr, low, r-1);
    if((high - (l+1)) >= 10000) qSort(arr, l+1, high);
    else iSort(arr, l+1, high); 
}

template <typename T>
void CDA<T>::QuickSort(){
    if(sorted) return; 
    else{
        T *arr = new T[length]; 
        for(int i = 0; i < length; i++) arr[i] = array[((front + i)%capacity)];
        qSort(arr, 0, length-1);
        for(int i = 0; i < length; i++) array[((front + i)%capacity)] = arr[i];
        delete [] arr;
        sorted = true; 
    }
}

template <typename T>
void CDA<T>::CountingSort(int m){
    if(sorted) return; 
    else{
        int * countArr = new int[m+1]; 
        for(int i = 0; i < m+1; i++) countArr[i] = 0; 
        for(int i = 0; i < length; i++) ++countArr[array[(front + i) % capacity]];
        for(int i = 0, j = 0; i < m+1 && j < length; i++){
            while(countArr[i] != 0){
                array[(front + j) % capacity] = i; 
                --countArr[i]; 
                ++j;
            }
        }
        sorted = true; 
    }
}

template <typename T>
int CDA<T>::Search(T e){
    if (sorted){
        int len = length; 
        int l = front; 
        int r = end; 
        while(len >= 1){
            len /= 2; 
            int m = (l + len) % capacity; 
            if(array[m] == e) return m; 
            if(array[m] < e) l = getNext(m); 
            else r = getPre(m);
        }
        return -1; 
    }
    else for(int i = 0; i < length; i++) if(array[(front + i) % capacity] == e) return i;
}

template <typename T>
CDA<T>::~CDA(){
    Clear();
    delete[] array; 
}
