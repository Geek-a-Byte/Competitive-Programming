#include <stdio.h>
#include <stdlib.h>

//maxsize ,array, length globally declare korate egula jekono jaigay use kora jabe

int maxsize=12;//array er size declare
int *array;//pointer diye array er first element er address ke point
int length;//array er size max size er cheye choto or boro hoile condition hishebe nibo

//array declare korar jonno function
void init()
{
    array = (int*) malloc(sizeof(int) * maxsize);
    length = 0;//length ke initialize korlam
}

///For Question 1:
int insertFirst(int val)
{
    if(length == maxsize)
    //length jodi max size er shoman hoi mane array er size er beshi na hoi
    //then insert kora jabe na,tai realloc korte hobe
    {
        maxsize = 2*maxsize;
        array = (int*) realloc(array, sizeof(int) *maxsize);
    }

    //right shift by one time
    for(int i=length; i>0; i--)
    {
        array[i]=array[i-1]; ///shift the elements to right
    }



    array[0] = val;//first position e element insert//val scan korbo main function theke
    length++;//length ek barabo insertion er por
    return 1;//successfully inserted the element at the first position
}

///For Question 2:

int insertLast(int *a, int val)
{
    if(length == maxsize)//same reason e jodi array er size choto thake size baraye then insertion
    {
        maxsize = 2*maxsize;
        array = (int*) realloc(array, sizeof(int) *maxsize);
    }
    array[length] = val;
    length++;
    return 1;
}

///For Question 3:
int insertAt(int *a, int pos, int val)
{
    if(length == maxsize)
    {
        maxsize = 2*maxsize;
        array = (int*) realloc(array, sizeof(int) *maxsize);
    }
    for(int i=length; i>pos; i--)
    {
        array[i]=array[i-1]; ///shift the elements to right up to the selected position
    }
    array[pos] = val;
    length++;
    return 1;//will show successful insertion
}

///For Question 4:
int deleteFirst(int *a)
{
    for(int i=0; i<length; i++)
    {
        array[i]=array[i+1]; ///shift the elements to left
    }
    length--;//length komano hobe
    return 1;
}

///For Question 5:
int deleteLast(int *a)
{
    length--;//length ek komaile print koranor somoy last er ta deleted dekhabe
    return 1;//successfully deleted the last element
}

///For Question 6:
int deleteAt(int *a, int pos)
{
    //position will be scanned from the main function
    for(int i=pos; i<length; i++)
    {
        a[i]=a[i+1]; ///shift the elements to right from selected position
    }
    length--;
    return 1;//successfully deleted from a random position
}
//concept of binary search
//https://dev.to/hakan/binary-search-algorithm---c-programming-example-47cg
/*The steps of binary search algorithm:

1- Select the element in the middle of the array.

2- Compare the selected element to the searched element, if it is equal to the searched element, terminate.

3- If the searched element is larger than the selected element, repeat the search operation in the major part of the selected element.

4- If the searched element is smaller than the selected element, repeat the search in the smaller part of the selected element.

5- Repeat the steps until the smallest index in the search space is less than or equal to the largest index.

For example; 2,3,4,5,6,7,8,9,22,33,45.

The following steps will be followed to find the number 4 with binary search in a sequential array of these numbers.

The middle element of the array is selected as 7 and compared with the searched element 4. The searched element (4) is not equal to the middle element (7), the part at the center of the array which is less than 7.

Our new search array: 2,3,4,5,6.

The middle element of our new search array is 4 and the search is completed.

With binary search algorithm, it is possible to find the searched value to log2N comparisons in an N-element array.*/

///For Question 7:
int binarySearch(int *a, int x)
{
    //x= searched element
    //a[mid]= middle element
    int low = 0, high = length-1 , mid;
    while(low<=high)//array er first element theke last element porjonto loop cholbe
    {
        mid = (low+high) / 2;
        if(a[mid]==x)
            return mid;//position e middle element er index return korbe
        else if(x<a[mid])
            high = mid-1;//lower part e abar binary search
        else
            low = mid+1;//higher part e binary search
    }
    return -1;//jodi searched element na pawa jay then pos e -1 return korbe
}

///For Question 8:
void printArray(int *a)
{
    printf("\n\tArray: ");
    for(int i=0; i<length; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n\tPress Enter");
}

//last occurence er index or pos janabe just
///For Question 10:
int lastIndexOf(int *a, int x)
{
    int low = 0, high = length-1 , mid, index = -1;
    while(low<=high)
    {
        mid = (low+high) / 2;
        if(a[mid]==x)
        {
            index = mid;
            low = mid+1;
        }
        else if(x<a[mid]) high = mid-1;
        else low = mid+1;
    }
    return index;
}

//first occurence er element ke khuje dibe
///For Question 11:
int firstIndexOf(int *a, int x)
{
    int low = 0, high = length-1 , mid , index = -1;
    while(low<=high)
    {
        mid = (low+high) / 2;
        if(a[mid]==x)
        {
            index = mid;
            high = mid - 1;
        }
        else if(x<a[mid]) high = mid-1;
        else low = mid+1;
    }
    return index;
}

int main()
{
    //declare the array by calling the init function
    init();

    //length input
    printf("Enter the length of the array: ");
    scanf("%d",&length);

    //array te first e input
    printf("Enter %d integers: ",length);
    for(int i=0; i<length; i++)
        scanf("%d",&array[i]);


    printf("\n\tAn Array has been created!\n\n\tPress Enter");
    getch();

    while(1)
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
        scanf("%d",&choose);
        if(choose == 1) ///For Question 1:
        {
            int x;
            printf("\t Enter the number: ");
            scanf("%d",&x);
            if(insertFirst(x))
                printf("\t%d has been successfully Inserted at First!\n\n\tPress Enter",x);
            getch();
        }
        else if(choose == 2) ///For Question 2:
        {
            int x;
            printf("\t Enter the number: ");
            scanf("%d",&x);
            if(insertLast(array,x))
                printf("\t%d has been successfully Inserted at Last!\n\n\tPress Enter",x);
            getch();
        }
        else if(choose == 3) ///For Question 3:
        {
            int x,pos;
            printf("\t Enter the number: ");
            scanf("%d",&x);
            printf("\t Enter the position: ");
            scanf("%d",&pos);
            if(insertAt(array,pos,x))
                printf("\t%d has been successfully Inserted at %d!\n\n\tPress Enter",x,pos);
            getch();
        }
        else if(choose == 4) ///For Question 4:
        {
            if(deleteFirst(array))
                printf("\tFirst element has been deleted!\n\tPress Enter");
            getch();
        }
        else if(choose == 5) ///For Question 5:
        {
            if(deleteLast(array))
                printf("\tLast element has been deleted!\n\tPress Enter");
            getch();
        }
        else if(choose == 6) ///For Question 6:
        {
            int pos;
            printf("\t Enter the position: ");
            scanf("%d",&pos);
            if(deleteAt(array,pos))
                printf("\tThe Element in position %d has been deleted!\n\tPress Enter",pos);
            getch();
        }
        else if(choose == 7) ///For Question 7:
        {
            int val;
            printf("\t Enter the number: ");
            scanf("%d",&val);
            int pos = binarySearch(array,val);
            if(pos != -1)
                printf("\t%d is found at position %d\n\tPress Enter",val,pos);
            else
                printf("\t%d is not found!\n\tPress Enter",val,pos);
            getch();
        }
        else if(choose == 8) ///For Question 8:
        {
            printArray(array);
            getch();
        }
        else if(choose == 9) ///For Question 9:
        {
            break;
        }
        else if(choose == 10) ///For Question 10:
        {
            int val;
            printf("Enter the number: ");
            scanf("%d",&val);
            int pos = lastIndexOf(array,val);
            if(pos != -1)
                printf("\tlast occurrence of %d is at position %d\n\tPress Enter",val,pos);
            getch();
        }
        else if(choose == 11) ///For Question 11:
        {
            int val;
            printf("Enter the number: ");
            scanf("%d",&val);
            int pos = firstIndexOf(array,val);
            if(deleteAt(array,pos))
                printf("\tFirst occurrence of %d has been deleted!\n\tPress Enter",val);
            getch();
        }
    }
    free(array);
    return 0;
}

