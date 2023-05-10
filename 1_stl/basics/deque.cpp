//TOPIC : std::deque in c++;
//deque -> double ended queue(not queue in ds)
//NOTES:
//0.std::deque is an indexed sequence container
//1.it allows fast insertion of both beginning and end -> O(1)
//2.Unlike vector, elements of deque are not stored contiguous
//3. it uses individual allocated fixed size array,
// with additional bookkeeping, meaning index based access to deque must perform two pointer dereference,
//but in vector we get in one dereference.
//4. The storage of a deque is automatically expanded and contracted as needed.
//5. Expension of deque is cheaper than expension of vector
//6. A deque holding just one element has to allocate its full internal array
//(e.g. 8 times the object size on 64-bit libstdc++;
//16 times the obj size or 4096 bytes,whichever is larger,on 64-bit libc++)

//TIME COMPLEXITY:
//random access- constant O(1)
//Insertion or removal of elements at the end or begenning -constant O(1)
//Insertion or removal in between of elements -linear O(n)

//push_back, push_front, pop_back, pop_front
//multiple arrays- arrays will be connected
#include <bits/stdc++.h>
using namespace std;

void print(std::deque<int> &dqu)
{
    for (auto num : dqu)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    std::deque<int> dqu = {2, 3, 4};
    std::deque<int> dqu1 = {2, 3, 4};
    dqu.push_front(1);
    dqu.push_back(5);
    dqu1.pop_back();
    dqu1.pop_front();
    print(dqu);
    print(dqu1);
}