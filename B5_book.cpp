#include<iostream>
#include<string.h>
using namespace std;

struct node{
    string label;
    int ch_count;
    node *child[10];
}*root;

class GT
{
    public:
    GT(){
        root=NULL;
    }

    void create_tree();
    void display(node *r1);
};

void GT::create_tree()
{
    int tchapters;
    root=new node;
    cout<<"Enter Name of Book: ";
    cin>>root->label;
    cout<<"Enter Number of Chapters in Book: ";
    cin>>tchapters;
    root->ch_count=tchapters;

    for(int i=0;i<tchapters;i++)
    {
        root->child[i]=new node;
        cout<<"Enter Name of Chapter "<<i+1<<": ";
        cin>>root->child[i]->label;
        cout<<"Enter number of sections in Chapter "<<root->child[i]->label<<": ";
        cin>>root->child[i]->ch_count;

        for(int j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter Name of Section "<<j+1<<": ";
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter number of SubSections in Section: "<<root->child[i]->child[j]->label<<": ";
            cin>>root->child[i]->child[j]->ch_count;

            for(int k=0;k<root->child[i]->child[j]->ch_count;k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter Name of Sub-Section "<<k+1<<": ";
                cin>>root->child[i]->child[j]->child[k]->label;
                root->child[i]->child[j]->child[k]->ch_count=0;
            }
        }
    }
}

void GT::display(node *r1)
{
    if(r1 != NULL)
    {
        cout<<"\n----BOOK HIERARCHY----"<<endl;
        cout<<"\tBOOK TITLE: "<<r1->label<<"\n";
        for(int i=0;i<r1->ch_count;i++)
        {
            cout<<"\n \tCHAPTER "<<i+1;
            cout<<" - "<<r1->child[i]->label;
            for(int j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<"\n\tSECTION: "<<j+1<<" - "<<r1->child[i]->child[j]->label;

                for(int k=0;k<r1->child[i]->child[j]->ch_count;k++)
                {
                    cout<<"\n\tSUBSECTION: "<<k+1<<" - "<<r1->child[i]->child[j]->child[k]->label;
                    
                }
            }
            cout<<"\n-------------------------";
        }
    }
}

int main()
{

    GT gt;
    int flag=0;
    int ch;
    while(flag==0)
    {
        cout<<"\n--------TREE MENU--------";
        cout<<"\n1.CREATE TREE";
        cout<<"\n2.DISPLAY";
        cout<<"\n3.EXIT";
        cout<<"\n--------------------";
        cout<<"\nENTER UR CHOICE: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            gt.create_tree();
            break;
        
        case 2:
            gt.display(root);
            break;
        
        case 3: 
            cout<<"\nTERMINATED THE PROGRAM\n";
            exit(1);

        default:
            cout<<"\nWRONG CHOICE ENTERED\n";
            break;
        }
    }
    return 0;
}
