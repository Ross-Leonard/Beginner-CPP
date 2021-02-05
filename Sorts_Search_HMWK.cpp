//John Ross Leonard
//CS 372
//Sorts Search HomeWork

#include <iostream>

using namespace std;

//PRINT MIDDLE 50 NUMS
void printfifty(int arr[])
{
	for (int i = 2475; i < 2525; i++)
	{
		for (int r = 0; r < 10; r++,i++)
		{
			cout << arr[i] << " ";			
		}		
		cout<< endl;		
	}
	cout << endl;
}


void dotheswap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;	
}
//swap specifically for selection
int selectionswap(int* xp, int* yp, int count)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	count++;
	return count;
}
//Bubble sort
int bubblesort(int array[], int n)
{
	int i, j;
	bool swapped;
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				dotheswap(&array[j], &array[j + 1]);
				swapped = true;
				count =count+ 1;
			}
		}
		if (swapped == false)
			break;
	}
	return count;
}
//Selection sort
int selectionsort(int arr[], int n)
{
	int i, j, min_index, count;
	count = 0;
	int swapqty = 0;
	for (i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_index])
				min_index = j;
		
		swapqty=swapqty+selectionswap(&arr[min_index], &arr[i], count);
	}
	return swapqty;
}
//insertion sort
int insertionsort(int arr[], int s)
{
	int current, j, count = 0;
	for (int i = 1; i < s; i++)
	{
		current = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > current)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		count++;
		arr[j + 1] = current;
	}
	return count;
}
//Quick sort
int quicksort(int arr[], int first, int last)
{
	int jr, j, temp, i;
	int SwapCount = 0;
	if (first < last)
	{		
		jr = first;
		i = first;
		j = last;
		while (i < j)
		{			
			while (arr[i] <= arr[jr] && i < last)
				i++;
			while (arr[j] > arr[jr])
				j--;
			if (i < j)
			{				
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[jr];
		arr[jr] = arr[j];
		arr[j] = temp;
		SwapCount++;
		quicksort(arr, first, j - 1);
		quicksort(arr, i+1, last);
	}
	return SwapCount;
}
//getting num from subscript to search
int getnumtosearch(int arr[],int x)
{
	int i;
	for (i = 0; i < arr[x]; i++)
	{
		if (i == x)
			return arr[i-1];		
	}
}
// linear search
int linearsearch(int arr[],int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == x)
			return i;		
	}
	return -1;
}

// binary search
int binarysearch(int arr[], int l,int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarysearch(arr, l, mid - 1, x);
		else
			return binarysearch(arr, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	int array[5000];
	int i, t, res;
	for (i = 0; i < 5000; i++)
	{
		array[i] = rand() % 10000;
	}
	int n = sizeof(array) / sizeof(array[0]);	
	printfifty(array);	
	int bubblecount=bubblesort(array, n);	
	for (i = 0; i < 5000; i++)
	{
		array[i] = rand() % 10000;
	}	
	int selectioncount = selectionsort(array, n);	
	for (i = 0; i < 5000; i++)
	{
		array[i] = rand() % 10000;
	}	
	int insertioncount = insertionsort(array, n);	
	for (i = 0; i < 5000; i++)
	{
		array[i] = rand() % 10000;
	}

	int quicksortcount = quicksort(array, 0,n-1);	
	
	cout << "Bubble sort count is " << bubblecount << " " << endl;
	cout << "Selection sort count is " << selectioncount << " " << endl;
	cout << "Insertion sort count is " << insertioncount << " " << endl;
	cout << "Quick sort count is " << quicksortcount << " " << endl << endl;

	int z = 0;
	float howmanylinearprobes = 0;
	float howmanybinaryprobes = 0;

	while(z<2000)
	{
		int randnum = rand() % 5000;		
		int num = getnumtosearch(array, randnum);
		howmanylinearprobes=howmanylinearprobes+ linearsearch(array, n, num);		
		howmanybinaryprobes=howmanybinaryprobes+ binarysearch(array, 0, n - 1, num);
		z++;
	}

	cout << "Theortically, it should take 2500 probes (5000 / 2) to find said number" << endl;
	cout << "How many probes on average, it took to find said number using a linear search: " << howmanylinearprobes/2000 << endl;
	cout << "How many probes on average, it took to find said number using a binary search: " << howmanybinaryprobes/2000 << endl;
	system("pause");
	return 0; 
}