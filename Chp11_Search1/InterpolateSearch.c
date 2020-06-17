#include <stdio.h>
#include "InterpolateSearch.h"

int ISearch(int arr[], int first, int last, int target)
{
	int mid;

	if (target < arr[first] || target > arr[last])
	{
		return -1;
	}

	if (first == last)
	{
		mid = first;
	}
	else
	{
		mid = (int)(((double)target - arr[first]) / ((double)arr[last] - arr[first]) * ((double)last - first) + first);
	}

	printf("Interpolate Middle %d First %d Last %d\n", mid, first, last);

	if (arr[mid] == target)
	{
		return mid;
	}
	else if (arr[mid] > target)
	{
		return ISearch(arr, first, mid - 1, target);
	}
	else
	{
		return ISearch(arr, mid + 1, last, target);
	}
}