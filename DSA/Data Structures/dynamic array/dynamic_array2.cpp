#include <bits/stdc++.h>

using namespace std;

int maxSize = 1000;
int *arr;
int curr_size;

int insertFirst(int val)
{
    if (curr_size == maxSize)
    {
        maxSize = 2 * maxSize;
        arr = (int *)realloc(arr, sizeof(int) * maxSize);
    }
    curr_size++;
    for (int i = curr_size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = val;
    return 1;
}

int insertLast(int val)
{

    if (curr_size == maxSize)
    {
        maxSize = 2 * maxSize;
        arr = (int *)realloc(arr, sizeof(int) * maxSize);
    }
    curr_size++;
    arr[curr_size - 1] = val;
    return 1;
}

int insertAt(int pos, int val)
{
    if (pos == 1)
    {
        insertFirst(val);
    }
    else
    {

        if (curr_size == maxSize)
        {
            maxSize = 2 * maxSize;
            arr = (int *)realloc(arr, sizeof(int) * maxSize);
        }
        curr_size++;
        for (int i = curr_size - 1; i >= pos; i--)
        {
            arr[i] = arr[i - 1]; //shift right
        }
        arr[pos - 1] = val;

        return 1;
    }
}

int deleteFirst()
{

    for (int i = 0; i < curr_size; i++)
    {
        arr[i] = arr[i + 1]; //shift left
    }
    curr_size--;
    return 1;
}

int deleteLast()
{
    curr_size--;
    return 1;
}

int deleteAt(int pos)
{
    for (int i = pos - 1; i < curr_size; i++)
    {
        arr[i] = arr[i + 1];
    }
    curr_size--;
    return 1;
}
//binary search er jonno list sorted hoye hoy
int binary_search(int x)
{
    int l = 0, h = curr_size - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1; //not found
}

void printArray()
{
    for (int i = 0; i < curr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int lastIndexOf(int val)
{
    for (int i = curr_size - 1; i >= 0; i--)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
int firstIndexOf(int val)
{
    for (int i = 0; i < curr_size; i++)
    {
        if (arr[i] == val)
        {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    printf("Enter the capacity of the array:\n");
    scanf("%d", &curr_size);
    arr = (int *)malloc(sizeof(int) * maxSize);
    printf("enter the elements of the array:\n");
    for (int i = 0; i < curr_size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 for Insertat\nEnter 2 for Deletefirst\nEnter 3 for Printarray\nEnter 4 for Quit\n");

    while (1)
    {
        int choose;
        printf("Enter the option you want to select\n");
        scanf("%d", &choose);
        if (choose == 1)
        {
            int val, pos;
            printf("enter the value and the pos:\n");
            scanf("%d%d", &val, &pos);
            //bound checking
            if (pos > 0 && pos <= curr_size && insertAt(pos, val)) //ekhane (InsertAt(val,pos) && pos<size) deya jabe na karon eta dile oitar khetre function e size ek baraye ashbe
            {
                printf("the first element was successfully inserted\n");
            }
            else if (pos > curr_size || pos <= 0)
            {
                printf("array bound exceeded, so The first element was not inserted\n");
            }
        }
        else if (choose == 2)
        {
            if (deleteFirst())
            {
                printf("The first element of the array was deleted\n");
            }
            else
            {
                printf("the first element of the array was not deleted\n");
            }
        }
        else if (choose == 3)
        {
            printArray();
        }
        else if (choose != 1 || choose != 2 || choose != 3)
            break;
    }
}