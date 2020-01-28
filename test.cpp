#include <iostream>
using namespace std;
#include "CDA.cpp"

void foo(CDA<int> x) {
	for (int i=0; i<x.Length()/2; i++)
		x[i] = x[x.Length()/2+i];
		cout << "SetOrdered in foo is " << x.SetOrdered() << endl;
		// x => "5 6 7 8 9 1 1 2 3 4 10" SetOrdered => -1	
}

int main(){
	CDA<float> C(10);
	for (int i=0; i< C.Length();i++) C[i] = i;
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.delFront();
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 9"
	C.delEnd();
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8"
	C.addEnd(100.0);
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100"
	C.addEnd(101.0);
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100 101"
	C.delEnd(); C.delEnd();
	C.addFront(-100.0); C.addFront(-200.0);
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "-200 -100 1 2 3 4 5 6 7 8"

	CDA<int> A;
	for(int i=0; i<10;i++) A.addEnd(i);
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" SetOrdered => 1
	cout << "Select is " << A.Select(3) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" Select => 2
	cout << "Select is " << A.Search(5) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" Search => 6
	A.addFront(10); 
	// A => "10 0 1 2 3 4 5 6 7 8 9"
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" SetOrdered => -1
	cout << "Select is " << A.Select(3) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" Select => 2
	cout << "Select is " << A.Search(5) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" Search => 6
	A.InsertionSort();
	// A => "0 1 2 3 4 5 6 7 8 9 10"
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10" SetOrdered => 1
	A.addEnd(-1);
	// A => "0 1 2 3 4 5 6 7 8 9 10 -1"
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10 -1" Ordered => False
	A.QuickSort();
	// A => "-1 0 1 2 3 4 5 6 7 8 9 10"
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "-1 0 1 2 3 4 5 6 7 8 9 10" Ordered => True
	A.delFront(); A.delFront(); A.addEnd(5);
	// A => "1 2 3 4 5 6 7 8 9 10 1"
	A.CountingSort(10);
	// A => "1 1 2 3 4 5 6 7 8 9 10"
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;

	foo(A);
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "1 1 2 3 4 5 6 7 8 9 10" Ordered => True
}
