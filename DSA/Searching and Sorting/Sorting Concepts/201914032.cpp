#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void printString(char *st)
{
    for (int i = 0; i < strlen(st); i++)
        cout << st[i];
    cout << endl;
}

void merge(char *left, char *right, char *st2, int n)
{

    int mid = n / 2;
    int ll = mid;
    int lr = n - mid;
    int i, j, k;
    i = j = k = 0;

    while (i < ll && j < lr)
    {
        if (tolower(left[i]) <= tolower(right[j]))
        {
            st2[k] = left[i];
            i++;
        }
        else
        {

            st2[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < ll)
    {
        st2[k] = left[i];
        i++;
        k++;
    }
    while (j < lr)
    {
        st2[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(char *st1, int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    char left[mid];
    char right[n - mid];
    for (int i = 0; i <= mid - 1; i++)
    {
        //left part
        left[i] = st1[i];
    }
    for (int i = mid; i <= n - 1; i++)
    {
        //right part
        right[i - mid] = st1[i];
    }

    mergesort(left, mid);
    mergesort(right, n - mid);
    merge(left, right, st1, n);
}

void sortString(char *st)
{

    /** GRADED CODE **/
    /// write your code here with comment
    int n = strlen(st);
    char temp[1000000];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (st[i] >= 48 && st[i] <= 57 || st[i] >= 65 && st[i] <= 90 || st[i] >= 97 && st[i] <= 122)
        {
            temp[k] = st[i];
            k++;
        }
    }
    temp[k] = '\0';

    mergesort(temp, strlen(temp));
    int i;
    for (i = 0; i < k; i++)
    {
        st[i] = temp[i];
    }
    st[i] = '\0';
}

int findValue(char ch, char *st)
{
    /** GRADED CODE **/
    /// write your code here with comment
    int n = strlen(st); //size of the array
    //traversing the array in reverse order
    for (int i = n - 1; i >= 0; i--)
    {
        //searching the character's last occurence
        if (st[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char st[1000000];
    cin.get(st, 1000000);
    int n = strlen(st);

    sortString(st); /// The essay is sorted

    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == 3)
            break;
        switch (choice)
        {
        case 1:
            printString(st); /// Prints the sorted Array.
            break;
        case 2:
            char cs;
            cin >> cs;
            int ret = findValue(cs, st);
            if (ret != -1)
                cout << "Character \'" << cs << "\' found at " << ret << endl;
            else
                cout << "Character \'" << cs << "\' not found." << endl;
            break;
        }
    }
}
