//list in STL
//this is double linked list
//sequence container
//allows non contiguous memory allocation
//faster than other sequence containers -> vector,forward_list,deque
//in terms for insertion, removal, and moving elements in any position

//max_size-> will return the maximum element that can be inserted
//clear ->will clear the list
//insert -> can insert an element between two elements in the list
//emplace
//unique -> removes duplicates when they are in consecutive position i.e -> {2,2,2,2} ->{2} and {2,3,4,2,2} -> {2,3,4,2}
//remove_if ->
//resize ->

#include <bits/stdc++.h>
using namespace std;

void printList(list<int> &l)
{
    for (auto it : l)
    {
        cout << it << " ";
    }
    cout << endl;
}

void printReverse(list<int> &l)
{
    cout << "the reverse order of the list is: ";
    for (auto it = l.rbegin(); it != l.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> list1 = {2, 9, 6, 4};
    list<int> list2 = {8, 3, 5, 7};

    cout << "b4 sorting list1:" << endl;
    printList(list1);
    cout << "b4 sorting list2:" << endl;
    printList(list2);

    list<int> list3 = {};
    list<int> list4 = {10, 20, 30};
    list3 = list4;
    cout << "after using '=' operator list4 will be assigned in empty list3 " << endl;
    printList(list3);

    list1.sort();
    list2.sort();
    cout << "after sorting list1:" << endl;
    printList(list1);
    cout << "after sorting list2:" << endl;
    printList(list2);

    //before merging we must ensure that the lists are in sorted order
    //otherwise it will merge them in the wrong order
    //without comparator in merge function:
    //same output for both merging ->list2.merge(list1), list1.merge(list2) ->
    //as the merged order will be sorted always
    cout << "after merging list1 will be :" << endl;

    //after merging the list2 will be added at the end of list1
    //and list1 will be empty therefore
    list1.merge(list2);
    printList(list1);

    if (list2.size() == 0)
    {
        cout << "after merging list2 will be empty" << endl;
    }

    //reverse the first list
    list1.reverse();
    cout << "The reversed list1 is: " << endl;
    printList(list1);

    //before splicing the list3 will be full
    printList(list3);

    //add the list3 to the begining of the list1
    list1.splice(list1.begin(), list3);
    printList(list1);

    //after splicing the list3 will be empty
    if (list3.empty())
    {
        cout << "after splicing list3 is empty" << endl;
    }

    //you can also add list items at the end of another list
    list<int> list5 = {100, 200};
    list5.splice(list5.end(), list1);
    printList(list5);

    cout << "front is " << list5.front() << " and back is " << list5.back() << endl;

    list5.push_front(1000);
    list5.push_back(2000);
    printList(list5);
    printReverse(list5);

    list5.pop_back();
    list5.pop_front();
    printList(list5);

    //assign method will remove all the previous data and assign new data completely
    //assign(count,value)
    list5.assign(5, 100);
    printList(list5);

    //resize(the_new_size,The_value)
    //if the list has less than n values then it will increase the size and resize it to n
    //and rest of the values will be the parameter value
    list5.resize(3);
    cout << "The list was resized" << endl;
    printList(list5);
    list5.resize(5, 200);
    printList(list5);

    //remove() works in linear time complexity
    //remove() method will search for a certain value in the whole list
    // and will remove all the elements similar to it
    list5.remove(100);
    cout << list5.size() << endl;
}