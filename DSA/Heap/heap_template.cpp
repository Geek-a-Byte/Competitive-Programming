///Max Heap

//leaf/external vertex-> kono child nai
//internal -> ontoto ekta child ase
//complete binary tree er n shonkhok vertex thakle 1 theke n/2 shonkhok vertex hoilo internal, bakigula external vertex
//max heap:  par>=left child && par>=right child
//min heap:  par<=left child && par<=right child
//insertion hobe array er last er dik diye
//notun element ke parent er shathe compare korbo
//then jeta max hobe ta ke root e boshabo
//jotokhon porjonto root boro hobe na totokhon swap korte thakbo
//insertion er belay bottom to top adjust hobe
//bottom to top dui belay thambe -> 1. root e pouchaile
//2. comparison e jawwar por heap er property noshto na hoile thambe
//insertion , deletion ->log n(worst case -karon leaf theke root e jaite hoite pare,height of a complete binary tree->logn)
//sort -> nlog n
//merge sort -> nlogn
//merge sort-> (worst case)-> n^2logn
//linear sort-> n^2
//insertion order er upor heap / bst er structure kivabe change hoy
//heap e only root element ke dlt korte pari
#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    int a[101], size;

public:
    Heap()
    {
        size = 0;
    }

private:
    void bottomTopAdjust(int index)
    {
        while (index != 1)
        {
            if (a[index] > a[index / 2])
            {
                swap(a[index], a[index / 2]);
            }
            else
            {
                break;
            }
            index = index / 2;
        }
    }
    //age left child and right child er moddhe max ber korbo
    //then parent jodi <= max hoy thn swap
    //r naile swap hobe na
    //heapify korte korte leaf node e pouchaile process end hobe
    //parent>max hoile theme jabe
    void topBottomAdjust(int i)
    {
        //heapify
        //size/2 hocche explorable node
        //baki gula hocche leaf node
        //jehetu parent theke leaf node e jete chai
        ///and i>size/2 hoile external node hobe
        while (i <= size / 2)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int max = a[leftChild];
            int maxIndex = leftChild;
            //ekta internal node er ekta child thakte pare or 2 ta
            //1 ta thakle oita hobe left child only

            if (rightChild <= size && a[rightChild] > max)
            {
                max = a[rightChild];
                maxIndex = rightChild;
            }
            if (a[maxIndex] > a[i])
            {
                swap(a[maxIndex], a[i]);
            }
            else
                return;
            i = maxIndex;
        }
    }

public:
    bool insert(int val)
    {
        if (size == 100)
        {
            return false; //O(1)
        }
        else
        {
            size++;                //O(1)
            a[size] = val;         //O(1)
            bottomTopAdjust(size); //->logn
            return true;
        }
    }

    int showMax()
    {
        return a[1];
    }

    int showSize()
    {
        return size;
    }
    //replace the first elemnt by last elemnt
    //reduce the size of the array by 1 or delete the last element
    //max complexity of deletion-> logn max she root theke leaf e jabe
    //heap sort e n-1 bar deleteroot call hobe
    //heap sort er complexity hobe nlogn
    //best ,worst, average complexity ->nlogn heap sort er

    bool deleteRoot()
    {
        if (size == 0)
            return false;
        else
        {
            swap(a[1], a[size]);
            size--;
            topBottomAdjust(1);
            return true;
        }
    }

    //buildheap and sort bade shob gular complexity hocche logn
    //build heap er complexity nlogn
    void buildHeap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            topBottomAdjust(i);
        }
    }

    void sort()
    {
        int actualSize = size;

        while (1)
        {
            if (size == 1)
            {
                break;
            }

            deleteRoot();
        }
        size = actualSize;
        cout << "Sorted: ";
        for (int i = 1; i <= size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    //sorted array ke reverse kore dilei hoye jabe heap er structure

    void bfs()
    {
        if (size == 0)
            return;
        int level = 2;
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            if (parent == level)
            {
                cout << endl;
                level = level * 2;
            }
            cout << a[parent] << " ";
            if (2 * parent <= size)
                q.push(2 * parent);
            if (2 * parent + 1 <= size)
                q.push(2 * parent + 1);
        }
    }
};

int main()
{

    Heap heap;

    while (1)
    {
        cout << "1. Insert    2. Show Max    3. Extract Max    4. Sort    5. Level    6. End" << endl
             << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(y);

            if (b)
                cout << y << " is inserted in the heap" << endl;
        }

        else if (choice == 2)
        {
            if (heap.showSize() != 0)
                cout << "Max Element: " << heap.showMax();
            else
                cout << "No element in the heap" << endl;
        }

        else if (choice == 3)
        {
            bool b = heap.deleteRoot();
            if (b)
                cout << "Root deleted from heap";
            else
                cout << "Heap is empty";
            cout << endl;
        }

        else if (choice == 4)
        {
            heap.sort();
        }

        else if (choice == 5)
        {
            cout << "Level Wise Traversal of the heap:" << endl;
            heap.bfs();
            cout << endl;
        }

        else if (choice == 6)
        {
            break;
        }

        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}

/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
*/
//