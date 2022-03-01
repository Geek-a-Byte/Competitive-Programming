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
    cout << "enter the length of the array\n";
    cin >> curr_size;

    arr = (int *)malloc(sizeof(int) * maxSize);
    for (int i = 0; i < curr_size; i++)
    {
        cin >> arr[i];
    }
    while (1)
    {
        //system("cls");
        printf("\n\tChoose Option: \n");
        printf("\t 1. Insert First\n");
        printf("\t 2. Insert Last\n");
        printf("\t 3. Insert At a Position\n");
        printf("\t 4. Delete First\n");
        printf("\t 5. Delete Last\n");
        printf("\t 6. Delete At a Position\n");
        printf("\t 7. Search in the Array\n");
        printf("\t 8. Print the Array\n");
        printf("\t 9. Quit\n");
        printf("\t10. Last Occurrence of an element\n");
        printf("\t11. Delete First Occurrence of an element\n");

        int choose;
        printf("\n\t Choose an option(1-11) : ");
        cin >> choose;
        if (choose == 1) ///For Question 1:
        {
            int x;
            printf("\t Enter the number: ");
            cin >> x;
            if (insertFirst(x))
                printf("\t%d has been successfully Inserted at First!\n\n\tPress Enter", x);
        }
        else if (choose == 2) ///For Question 2:
        {
            int x;
            printf("\t Enter the number: ");
            scanf("%d", &x);
            if (insertLast(x))
                printf("\t%d has been successfully Inserted at Last!\n\n\tPress Enter", x);
        }
        else if (choose == 3) ///For Question 3:
        {
            int x, pos;
            printf("\t Enter the number: ");
            scanf("%d", &x);
            printf("\t Enter the position: ");
            scanf("%d", &pos);
            if (insertAt(pos, x))
                printf("\t%d has been successfully Inserted at %d!\n\n\tPress Enter", x, pos);
        }
        else if (choose == 4) ///For Question 4:
        {
            if (deleteFirst())
                printf("\tFirst element has been deleted!\n\tPress Enter");
        }
        else if (choose == 5) ///For Question 5:
        {
            if (deleteLast())
                printf("\tLast element has been deleted!\n\tPress Enter");
        }
        else if (choose == 6) ///For Question 6:
        {
            int pos;
            printf("\t Enter the position: ");
            scanf("%d", &pos);
            if (deleteAt(pos))
                printf("\tThe Element in position %d has been deleted!\n\tPress Enter", pos);
        }
        else if (choose == 7) ///For Question 7:
        {
            int val;
            printf("\t Enter the number: ");
            scanf("%d", &val);
            int pos = binary_search(val);
            if (pos != -1)
                printf("\t%d is found at position %d\n\tPress Enter", val, pos + 1);
            else
                printf("\t%d is not found!\n\tPress Enter", val, pos);
        }
        else if (choose == 8) ///For Question 8:
        {
            printArray();
        }
        else if (choose == 9) ///For Question 9:
        {
            break;
        }
        else if (choose == 10) ///For Question 10:
        {
            int val;
            printf("Enter the number: ");
            scanf("%d", &val);
            int pos = lastIndexOf(val);
            if (pos != -1)
                printf("\tlast occurrence of %d is at position %d\n\tPress Enter", val, pos);
        }
        else if (choose == 11) ///For Question 11:
        {
            int val;
            printf("Enter the number: ");
            scanf("%d", &val);
            int pos = firstIndexOf(val);
            if (deleteAt(pos))
                printf("\tFirst occurrence of %d has been deleted!\n\tPress Enter", val);
        }
    }

    free(arr);
    return 0;
}