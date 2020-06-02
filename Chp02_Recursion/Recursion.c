#include "stdio.h"

int BinarySearch(int arr[], int first, int last, int target_v)
{
	if (first > last)
	{
		return -1;
	}

	int mid = (first + last) / 2;
	if (arr[mid] == target_v)
	{
		return mid;
	}
	else if (target_v < arr[mid])
	{
		return BinarySearch(arr, first, mid - 1, target_v);
	}
	else
	{
		return BinarySearch(arr, mid + 1, last, target_v);
	}
}


void HanoiTower(int num, int * move_count, char from, char by, char to)
{
	if (num == 1)
	{	
		printf("%d 번째 원반을 %c에서 %c로 이동한다. (#: %d)\n", num, from, to, ++(*move_count));
	}
	else
	{
		HanoiTower(num - 1, move_count, from, to, by);
		printf("%d 번째 원반을 %c에서 %c로 이동한다. (#: %d)\n", num, from, to, ++(*move_count));
		HanoiTower(num - 1, move_count, by, from, to);
	}
}


void main()
{
	int arr[5] = { 1, 2, 5, 3, 8 };
	int at = BinarySearch(arr, 0, 4, 2);
	
	int move_count = 0;

	printf("2 is at %d on arr\n", at);
	HanoiTower(3, &move_count, 'A', 'B', 'C');
}