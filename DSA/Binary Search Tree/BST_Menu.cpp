#include "bst.h"

int main(){
    BST b;

    while(1){
        cout<<"1. Insert    2. Sort      3. Level Order    4. Minimum\n5. Maximum   6. Delete    7. Height         8. End\n\n";
        int x;
        cin>>x;

        if(x==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            b.insert(y);
            cout<<y<<" is inserted in the tree"<<endl;
        }

        else if(x==2){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Sorted List of the tree: ";
            b.dfs(b.getRoot());
            cout<<endl;
        }

        else if(x==3){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Level Wise Traversal of the tree:"<<endl;
            b.bfs();
            cout<<endl;
        }

        else if(x==4){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Minimum of the tree: ";
            Node *min = b.findMinimum(b.getRoot());
            cout<<min->key<<endl;
        }

        else if(x==5){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Maximum of the tree: ";
            Node *max = b.findMaximum(b.getRoot());
            cout<<max->key<<endl;
        }

        else if(x==6){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Delete Value: ";
            int y;
            cin>>y;
            bool test = b.deleteNode(y);
            if(test)   cout<<y<<" is deleted from the tree"<<endl;
            else    cout<<y<<" is not found in the tree"<<endl;
        }
        else if(x==7){
            if(b.getRoot()==NULL){
                cout<<"Tree is empty"<<endl;
                continue;
            }
            cout<<"Height of the tree: "<<b.height(b.getRoot())<<endl;
        }
        else if(x==8){
            break;
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
        cout<<endl;
    }
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/
