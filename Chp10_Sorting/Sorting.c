#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include "Heap.h"
#include "Queue.h"


void BubbleSort(int arr[], int n, Priority p)
{
	int tmp;

	if (n <= 1)
	{
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p(arr[j + 1], arr[j]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void SelectionSort(int arr[], int n, Priority p)
{
	int mIDX;
	int mData;

	if (n <= 1)
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (j == i)
			{
				mIDX = j;
			}

			if (p(arr[j], arr[mIDX]) > 0)
			{
				mIDX = j;
			}
		}

		mData = arr[mIDX];
		arr[mIDX] = arr[i];
		arr[i] = mData;
	}
}

void InsertionSort(int arr[], int n, Priority p)
{
	int tIDX;
	int Data;

	if (n <= 1)
	{
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		tIDX = 0;

		for (int j = i; j >= 0; j--)
		{
			if (p(arr[j], arr[i + 1]) > 0)
			{
				tIDX = j + 1;
				break;
			}
		}

		if (tIDX != i + 1)
		{
			Data = arr[i + 1];

			for (int j = i + 1; j > tIDX; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[tIDX] = Data;
		}
	}
}

void HeapSort(int arr[], int n, Priority p)
{
	Heap h;

	HeapInit(&h, p);

	for (int i = 0; i < n; i++)
	{
		HeapInsert(&h, arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = HeapDelete(&h);
	}
}

void merge(int arr[], int start, int mid, int end, Priority p)
{
	int* tmpArr = (int*)malloc(((long long)end - start + 1) * sizeof(int));
	int step = 0;
	int idx1 = start;
	int idx2 = mid + 1;
	
	while (idx1 <= mid && idx2 <= end)
	{
		if (p(arr[idx1], arr[idx2]) > 0)
		{
			tmpArr[step] = arr[idx1];
			idx1++;
		}
		else
		{
			tmpArr[step] = arr[idx2];
			idx2++;
		}
		step++;
	}

	for (idx1; idx1 <= mid; idx1++)
	{
		tmpArr[step] = arr[idx1];
		step++;
	}

	for (idx2; idx2 <= end; idx2++)
	{
		tmpArr[step] = arr[idx2];
		step++;
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = tmpArr[i - start];
	}

	free(tmpArr);
}

void mergeSort(int arr[], int left, int right, Priority p)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		mergeSort(arr, left, mid, p);
		mergeSort(arr, mid + 1, right, p);

		merge(arr, left, mid, right, p);
	}
}

void MergeSort(int arr[], int n, Priority p)
{
	if (n <= 1)
	{
		return;
	}

	mergeSort(arr, 0, n - 1, p);
}

void swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right, Priority p)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	int tmp;

	while (1)
	{
		while (p(arr[low], pivot) > 0)
		{
			low++;
			if (low > high)
			{
				break;
			}
		}

		while (p(pivot, arr[high]) > 0)
		{
			high--;
			if (high < low)
			{
				break;
			}
		}

		if (high < low)
		{
			arr[left] = arr[high];
			arr[high] = pivot;
			break;
		}

		if (low < high)
		{
			tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	}

	return high;
}

void quickSort(int arr[], int left, int right, Priority p)
{
	int pivotIDX;

	if (left < right)
	{
		pivotIDX = partition(arr, left, right, p);
		quickSort(arr, left, pivotIDX - 1, p);
		quickSort(arr, pivotIDX + 1, right, p);
	}
}

void QuickSort(int arr[], int n, Priority p)
{
	if (n <= 1)
	{
		return;
	}

	quickSort(arr, 0, n - 1, p);
}

int maxE(int arr[], int n)
{
	int maxElem = -1;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxElem)
		{
			maxElem = arr[i];
		}
	}

	return maxElem;
}

int digit(int n)
{
	int i = 0;

	while (n / 10 > 0)
	{
		i++;
	}

	return i;
}


void RadixSort(int arr[], int n, Priority p)
{
	int maxDigit = digit(maxE(arr, n));
	int bn;
	Queue Buckets[10];
	int nums[10];
	int idx;

	for (int i = 0; i < 10; i++)
	{
		QueueInit(&Buckets[i]);
		nums[i] = 0;
	}

	for (int i = 0; i < maxDigit + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bn = arr[j];

			for (int k = 0; k < i; k++)
			{
				bn /= 10;
			}
			bn %= 10;

			Enqueue(&Buckets[bn], arr[j]);
			nums[bn]++;
		}

		idx = 0;
		for (int l = 0; l < 10; l++)
		{
			for (int m = 0; m < nums[l]; m++)
			{
				arr[idx] = Dequeue(&Buckets[l]);
				idx++;
			}
		}
	}
}

void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
