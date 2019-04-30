/*
2.	Implement Heap Sort(The program should report the number of comparisons)
*/

#include<iostream>
using namespace std;

class unsortedArray
{
private :
	int a[5], comp=0;
public :
	int len=0;

// The array to be sorted
	void array()
	{
		cout << "Enter the numbers : \n";
		for (int i=0; i<5; i++)
		{
			cout << "   a[" << i << "] = ";
			cin >> a[i];
		}
		len = ( sizeof(a)/sizeof(a[0]) );
	}

// Heap Sort
	void heapSort()
	{
		for(int i=(len/2)-1; i>=0; i--)
		{
			heapify(len,i);
		}

		for(int i=len-1; i>=0; i--)
		{
			swap(a[0],a[i]);
			heapify(i,0);
		}
	}

	void heapify(int n, int i)
	{
		int largest = i;			// root
		int left = 2*i + 1;			// left
		int right = 2*i + 2;		// right

		if(left<n && a[left]>a[largest])
		{
			largest=left;
			comp++;
		}

		if(right<n && a[right]>a[largest])
		{
			largest=right;
			comp++;
		}

		if(largest!=i)
		{
			swap(a[i], a[largest]);
			heapify(n,largest);
		}
	}

// Printing the array
	void printArray()
	{
		for (int i=0; i<len; i++)
			cout << a[i] << "\t";
		cout << endl << "Number of comparisons : " << comp << endl;
	}
};

int main()
{
	unsortedArray a1;
	a1.array();

	cout << "\nHeap Sort=>\n";
	a1.heapSort();
	a1.printArray();

	for(int i=0; i<211; i++)
		cout << "-";
	cout << endl;

	return 0;
}
