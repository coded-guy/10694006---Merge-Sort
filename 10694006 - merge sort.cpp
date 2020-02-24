#include <iostream>

using namespace std;

// function to merge the two halves into a sorted data.
void Merge(int *a, int bottom, int mid, int top)
{
	// We have bottom to mid and mid+1 to top already sorted.
	int i, j, k, temp[top-bottom+1];
	i = bottom;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= top)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to top into temp[].
	while (j <= top)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = bottom; i <= top; i++)
	{
		a[i] = temp[i-bottom];
	}
}

// A function to split array into two parts.
void MergeSort(int *a, int bottom, int top)
{
	int mid;
	if (bottom < top)
	{
		mid=(bottom+top)/2;
		// Split the data into two half.
		MergeSort(a, bottom, mid);
		MergeSort(a, mid+1, top);

		// Merge them to get sorted output.
		Merge(a, bottom, top, mid);
	}
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	MergeSort(arr, 0, n-1);

	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<">>"<<arr[i];

	return 0;
}
