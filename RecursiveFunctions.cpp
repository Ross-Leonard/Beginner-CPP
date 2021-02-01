

#include <iostream>
using namespace std;


//Write a recursive function that returns the number of digits in a nonnegative integer
int countdigits(int num)
{
	static int count = 0;
	if (num > 0)
	{
		count++;
		countdigits(num / 10);
	}
	else
	{
		return count;
	}
}
//Write a recursive function printReverse() that displays an integers digits in reverse order
int printReverse(int n)
{
	int rev = 0;
	int modding;
	if (n == 0)	
		return n;	
	else
	{
		modding = n % 10;		
		cout << modding <<" ";
		printReverse(n/10);	
	}	
}
//Write recursive definitions of the functions whose prototypes are given in Exercises 27-29
//27
void reverseArray(int array[], int first, int last)
{
	int i = 0;
	int temp;
	if (first > last)
	{
		cout << array[last];
		return;		
	}
	else
	{
		temp = array[first];
		array[first] = array[last];
		array[last] = temp;		
		reverseArray(array, first + 1, last - 1);		
	}
	cout << array[last];	
}

////Write recursive definitions of the functions whose prototypes are given in Exercises 27-29
//28
int sumArray(int array[], int n)
{
	int sum;
	int i = 1;
	if (n == 0)
		return 0;
	else
	return (sumArray(array,n-1)+array[n-1]);

}

////Write recursive definitions of the functions whose prototypes are given in Exercises 27-29
//29
int location(int array[], int first, int last, int target)
{
	int loc = 0;
	int i = first;
	if (first >= last)
	{
		cout << "Target not found";
		return 0;
	}
	if (array[first] == target)
	{
		return first;
	}
	if (array[last] == target)
	{
		first = last;
		return last;
	}
	return location(array, ++first, --last, target);
}

//# 33 Greatest Common Divisor Program
int GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (false)
		return 0;
	else
	{
		int r = a % b;
		if (0 == r)
			return 0;
		else
		{
			a = b;
			b = r;
		}
	}
	return b;
}

int main()
{
	//Number 21, Write a recursive function that returns the number of digits in a nonnegative integer
	int number, count;
	count = 0;
	cout << "Enter a positive number: ";
	cin >> number;
	count = countdigits(number);
	cout << "There are " << count << " digits in that certain number. " << endl;

	//Number 23, Write a recursive function printReverse() that displays an integers digits in reverse order
	int val, val2;
	cout << "Enter digit: ";
	cin >> val;
	cout << "Printing out in Reverse order: ";
	val2 = printReverse(val);
	cout << endl;
	//Number 27,Write recursive definitions of the functions whose prototypes are given in Exercises 27-29
	int val3[5] = { 1,2,3,4,5 };	
	int first = val3[0];
	int last=val3[4];	
	cout << "Printing out the array 1,2,3,4,5 in Reverse order: ";
	reverseArray(val3,first,last);
	cout << first;	
	cout << endl;

	//Number 28,Write recursive definitions of the functions whose prototypes are given in Exercises 27-29
	int val4[5] = { 1,2,3,4,5 };
	int n = sizeof(val4) / sizeof(val4[0]);
	cout << "Summing up the array 1,2,3,4,5: ";
	cout<<sumArray(val4, n);	
	cout << endl;

	//Number 29,Write recursive definitions of the functions whose prototypes are given in Exercises 27-29	
	int n1 = sizeof(val3) / sizeof(val3[0]);
	cout << "Searching for value 4 in array: ";
	int x = 4;
	int loc = location(val3, 0, n - 1, x);
	cout << "Searching for " << x;
	if (loc != -1)
	{
		cout <<"..Found it! "<< x << " is located in position " << loc;
	}
	else
		cout << x << " is not present in the array!";

	cout << endl;	

	//Number 33, GCD program
	while (true)
	{
		int a, b;
		cout << "Enter the two values: ";
		cin >> a >> b;
		cout << "Greatest Common Divisor is: " << GCD(a, b) << endl;
		char input;
		cout << "Continue? (Y/N)";
		cin >> input;
		if ('y' != input)
		{
			break;
		}
	}

	system("pause");
	return 0;
}
