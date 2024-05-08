#include<iostream>
#include<string.h>
using namespace std;
struct node
{
    char data;
    node *left;
    node *right;
};

class tree
{
    char prefix[20];
    public:
        node *top;
        void expression(char []);
        void display(node *);
        void non_rec_post(node *);
        void del(node *);
};

class stack1
{
    node *data[30];
    int top;

    public:
        stack1()
        {
            top=-1;
        }

        int isEmp()
        {
            if(top==-1)
                return 1;
            return 0;
        }

        void push(node *p)
        {
            data[++top]=p;
        }

        node *pop()
        {
            return(data[top--]);
        }
};

void tree::expression(char prefix[])
{
    char c;
    stack1 s;
    node *t1,*t2;
    int len;
    len=strlen(prefix);
    for(int i=len-1;i>=0;i--)
    {
        top=new node;
        top->left=NULL;
        top->right=NULL;
        if(isalpha(prefix[i]))
        {
            top->data=prefix[i];
            s.push(top);
        }

        else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/')
        {
            t2=s.pop();
            t1=s.pop();

            top->data=prefix[i];
            top->left=t2;
            top->right=t1;
            s.push(top);
        }
    }
    top=s.pop();
}

void tree::display(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data;
        display(root->left);
        display(root->right);
    }
    
}

void tree::non_rec_post(node *top)
{
    stack1 s1,s2;
    node *T=top;
    cout<<"\n";
    s1.push(T);
    while(!s1.isEmp())
    {
        T=s1.pop();
        s2.push(T);
        if(T->left!=NULL)
        {
            s1.push(T->left);
        }
        if(T->right!=NULL)
        {
            s1.push(T->right);
        }

    }

    while(!s2.isEmp())
    {
        top=s2.pop();
        cout<<top->data<<" ";
    }

}

void tree::del(node *node)
{
    if(node==NULL)
        return;
    del(node->left);
    del(node->right);
    cout<<"Deleting node: "<<node->data<<" \n";
    free(node);
}
int main()
{
    char exp[20];
    
    tree t;
    int ch;
    char c;
    do
    {
    cout<<"***MENU***";
    cout<<"\n1.Enter Expression\n2.Display Expression\n3.Postorder Traversal\n4.Delete Tree\n5.EXIT";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
	case 1:
        cout<<"\nEnter a prefix expression: ";
        cin>>exp;
		t.expression(exp);
		break;
	case 2:
		t.display(t.top);
        cout<<endl;
        break;

    case 3:
        cout<<endl;
        t.non_rec_post(t.top);
        break;
    
    case 4:
        cout<<endl;
        t.del(t.top);
        cout<<endl;
        break;
    
    case 5:
        exit(1);

    default:
        cout<<"\nInvalid choice entered!! Enter a valid choice!";
        main();
        break;
	
    }
    cout<<"\nDo you want to continue(y/n): ";
    cin>>c;
    }while(c=='y'||'Y');
    
    return 0;
}
