#include <iostream>
#include <unordered_map>
using namespace std;

// A Trie node
struct node
{
    // true when node is a leaf node/end of word
    bool endmark;

    // each node stores a map to its child nodes
    unordered_map<char, node *> map;
    node()
    {
        // cout << "default constructor called" << endl;
        // cout << "auto node created" << endl;
        endmark = false;
    }
} * root;

// Iterative function to insert a string in node.
void insert(char *str)
{
    // start from root node
    node *curr = root;
    while (*str)
    {
        // create a new node if path doesn't exists
        if (curr->map.find(*str) == curr->map.end())
            curr->map[*str] = new node();

        // go to next node
        curr = curr->map[*str];

        // move to next character
        str++;
    }

    // mark current node as leaf
    curr->endmark = true;
}

// returns true if given node has any children
bool haveChildren(node const *curr)
{
    // don't use (curr->map).size() to check for children

    for (auto it : curr->map)
        if (it.second != nullptr)
            return true;

    return false;
}

// Iterative function to search a string in node. It returns true
// if the string is found in the node, else it returns false
bool search(char *str)
{
    // return false if node is empty
    if (root == nullptr)
        return false;

    node *curr = root;
    while (*str)
    {
        // go to next node
        curr = curr->map[*str];

        // if string is invalid (reached end of path in node)
        if (curr == nullptr)
            return false;

        // move to next character
        str++;
    }

    // if current node is a leaf and we have reached the
    // end of the string, return true
    return curr->endmark;
}

// Memory efficient node Implementation in C++ using Map
int main()
{
    root = new node();

    insert("hello");
    cout << search("hello") << " "; // print 1

    insert("helloworld");
    cout << search("helloworld") << " "; // print 1

    cout << search("helll") << " "; // print 0 (Not present)

    insert("hell");
    cout << search("hell") << " "; // print 1

    insert("h");
    cout << search("h") << endl; // print 1 + newline   
    cout << search("h") << endl;
  
    // node is empty now

    return 0;
}
