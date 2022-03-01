#include <bits/stdc++.h>
#define length 664728
using namespace std;
using namespace std::chrono;
int arr[length];

void insertionSort(int array[], int size)
{
   int key, j;
   for (int i = 1; i < size; i++)
   {
      key = array[i]; //take value
      j = i;
      while (j > 0 && array[j - 1] > key)
      {
         array[j] = array[j - 1];
         j--;
      }
      array[j] = key; //insert in right place
   }
}

void bubbleSort(int a[], int n)
{
   int i, j, temp;
   for (i = 1; i < n; ++i)
   {
      for (j = 0; j < (n - i); ++j)
         if (a[j] > a[j + 1])
         {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
         }
   }
}

int main()
{

   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   //int arr[length];
   for (int i = 0; i < length; i++)
   {
      cin >> arr[i];
   }

   //number of input 664728
   auto start = chrono::system_clock::now();

   insertionSort(arr, length);
   //bubbleSort(arr ,length);

   auto endtime = chrono::system_clock::now();

   //duration class , count object
   chrono::duration<double> elapsed_seconds_for_insertion_sort = endtime - start;

   auto start1 = chrono::system_clock::now();

   bubbleSort(arr, length);

   auto endtime1 = chrono::system_clock::now();

   chrono::duration<double> elapsed_seconds_for_bubble_sort = endtime1 - start1;

   cout << "elapsed time for insertion sort:" << elapsed_seconds_for_insertion_sort.count() << endl;
   cout << "elapsed time for bubble sort:" << elapsed_seconds_for_bubble_sort.count() << endl;
}
