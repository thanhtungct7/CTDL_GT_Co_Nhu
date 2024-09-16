//
// Created by ACER on 9/12/2024.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* root = NULL;

// cap phat node
node* allocateNode()
{
    return (node*)malloc(sizeof(node));
}

// tao node voi gia tri cho truoc
node* createNode(int value)
{
    node* temp = allocateNode();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// tao node voi gia tri nhap vao tu ban phim
node* createAndInputNode()
{
    int value;
    scanf("%d",&value);
    return createNode(value);
}

// tao cay
void  createTree()
{
    root = NULL;
}

// gan gia tri cho 1 cay
void inputTree(int level, node **curentNode)
{
    if(level>0)
    {
        *curentNode = createAndInputNode();
        inputTree(level - 1, &(*curentNode)->left);
        inputTree(level - 1, &(*curentNode)->right);
    }
}

// tao stack
node* stack[100];
node* stack1[100];
node* stack2[100];

// ham push
void push(node * stack[100] , int *top , node * pNode )
{
    if(*top >=100)
    {
        printf("Stack Overflow\n");
    }
        stack[++(*top)] = pNode;
}
node* pop(node * stack[100], int *top)
{
    if((*top)<0)
    {
        printf("Stack Underflow\n");
        return NULL;
    }
    *top = (*top)-1;
    return stack[(*top)+1];
}

// duyet cay theo thu tu truoc khong de quy
void printTreePreOrder(node* pNode)
{
    int top;
    if(pNode == NULL)
    {
        printf("Cay rong\n");
        return;
    }
    else
    {
        top =-1;
        push(stack,&top,pNode);
    }
    while (top>-1)
    {
        node* p = pop(stack,&top);
        while(p!=NULL)
        {
            printf("%d ",p->data);
            if(p->right != NULL)
            {
                push(stack,&top,p->right);
            }
            p = p->left;
        }
    }
}

// duyet cay theo thu tu giua khong de quy
void printTreeInpreOrder(node* pNode)
{
    int top ;
    node * p;
    if(pNode == NULL)
    {
        printf("Cay rong\n");
        return;
    }
    else
    {
        top = -1;
        p = pNode;
    }
    while (top >-1||p!=NULL)
    {
        while(p!=NULL)
        {
            push(stack,&top,p);
            p = p->left;
        }
        p = pop(stack,&top);
        printf("%d ",p->data);
        p = p->right;
    }
}

// duyet cay theo thu tu sau khong de quy
void printTreePostOrder(node* pNode)
{
    int top1,top2;
    node * p;
    if(pNode == NULL)
    {
        printf("Cay rong\n");
        return;
    }
    else
    {
        top1 = -1;
        top2 = -1;
        push(stack1,&top1,pNode);
    }
    while (top1>-1)
    {
        p = pop(stack1,&top1);
        push(stack2,&top2,p);
        if(p->left !=NULL)
        {
            push(stack1,&top1,p->left);
        }
        if(p->right != NULL)
        {
            push(stack1,&top1,p->right);
        }

    }
    while (top2>-1)
    {
        p = pop(stack2,&top2);
        printf("%d ",p->data);
    }
}

int main()
{
    inputTree(3,&root);

   printTreePostOrder(root);
}

















