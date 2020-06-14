#ifndef __SORTING_H__
#define __SORTING_H__

#include "Priority.h"

void BubbleSort(int arr[], int n, Priority p);
void SelectionSort(int arr[], int n, Priority p);
void InsertionSort(int arr[], int n, Priority p);
void HeapSort(int arr[], int n, Priority p);
void MergeSort(int arr[], int n, Priority p);
void QuickSort(int arr[], int n, Priority p);
void RadixSort(int arr[], int n, Priority p);
void PrintArray(int arr[], int n);

#endif