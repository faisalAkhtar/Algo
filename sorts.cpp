/*
1.	Implement Bubble, Selection, Insertion, Merge, Quick Sort. And count number of comparisons in each case.
*/

#include<iostream>
using namespace std;

void swap(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

class unsortedArray
{
private :
	int a[7], comp=0;
public :
	int len=0;

// The array to be sorted
	void array()
	{
		cout << "Enter the numbers : \n";
		for (int i=0; i<7; i++)
		{
			cout << "   a[" << i << "] = ";
			cin >> a[i];
		}
		len = ( sizeof(a)/sizeof(a[0]) ) - 1;
	}

// Copying an array
	void operator = (const unsortedArray &uA)
	{
		for (int i=0; i<7; i++)
		{
			a[i]=uA.a[i];
		}
		len=uA.len;
	}

// Bubble Sort
	void bubbleSort()
	{
		for(int i=0; i<len; i++)
		{
			for(int j=0; j<len-i; j++)
			{
				if(a[j]>a[j+1])
				{
					swap(&a[j],&a[j+1]);
					comp++;
				}
			}
		}
	}

// Selection sort
	void selectionSort()
	{
		int min;
		for(int i=0; i<len; i++)
		{
			min=i;
			for(int j=i+1; j<=len; j++)
			{
				if(a[j]<a[min])
				{
					min=j;
					comp++;
				}
			}
			swap(&a[min], &a[i]);
		}
	}

// Insertion sort
	void insertionSort()
	{
		int temp, k;
		for(int i=1; i<=len; i++)
		{
			for(int j=0; j<=i; j++)
			{
				if(a[j]>a[i])
				{
					temp = a[j];
					a[j] = a[i];
					for(k=i; k>j; k--)
					{
						comp++;
						a[k] = a[k-1];
					}
					a[k+1] = temp;
				}
			}
		}
	}

// Merge sort
	void merge(int low, int high, int mid)
	{
		int i=low, k=low, j=mid+1, c[len+1];
		while(i<=mid && j<=high)
		{
			if(a[i]<a[j])
			{
				c[k]=a[i];
				k++;
				i++;
				comp++;
			}
			else
			{
				c[k]=a[j];
				k++;
				j++;
				comp++;
			}
		}
		while(i<=mid)
		{
			c[k]=a[i];
			k++;
			i++;
		}
		while(j<=high)
		{
			c[k]=a[j];
			k++;
			j++;
		}
		for(i=low; i<k; i++)
			a[i]=c[i];
	}

	void mergeSort(int low, int high)
	{
		int mid;
		if(low<high)
		{
			mid=(low+high)/2;
			mergeSort(low,mid);
			mergeSort(mid+1,high);
			merge(low,high,mid);
		}
		return;
	}

// Quick Sort
	int partition(int low, int high)
	{
		int pivot=a[high];				//pivot element=>last element of the array
		int i=(low-1);

		for(int j=low;j<=high-1;j++)
		{
			if(a[j]<=pivot)
			{
				i++;
				swap(&a[i],&a[j]);
				comp++;
			}
		}

		swap(&a[i+1],&a[high]);
		return(i+1);
	}

	void quickSort(int low, int high)
	{
		if(low<high)
		{
			int pi=partition(low,high);
			quickSort(low,pi-1);
			quickSort(pi+1,high);
		}
	}

// Printing the array
	void printArray()
	{
		for (int i=0; i<=len; i++)
			cout << a[i] << "\t";
		cout << endl << "   Number of comparisons : " << comp << endl;
	}
};

int main()
{
	unsortedArray a1, a2, a3, a4, a5;
	a1.array();
	a2=a1;
	a3=a1;
	a4=a1;
	a5=a1;

	cout << "\nBubble Sort=>\n   ";
	a1.bubbleSort();
	a1.printArray();

	cout << "\nSelection Sort=>\n   ";
	a2.selectionSort();
	a2.printArray();

	cout << "\nInsertion Sort=>\n   ";
	a3.insertionSort();
	a3.printArray();

	cout << "\nMerge Sort=>\n   ";
	a4.mergeSort(0,a4.len);
	a4.printArray();

	cout << "\nQuick Sort=>\n   ";
	a5.quickSort(0,a5.len);
	a5.printArray();

	for(int i=0; i<211; i++)
		cout << "-";
	cout << endl;

	return 0;
}
