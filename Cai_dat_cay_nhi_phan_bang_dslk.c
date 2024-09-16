//
// Created by ACER on 9/4/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// xây dựng cây nhị phân sử dụng danh sách liên kết

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* root = NULL;

node* allocateNode()
{
    return (node*)malloc(sizeof(node));
}

node* createNode(int value)
{
    node* pNode = allocateNode();
    pNode->data = value;
    pNode->left = pNode->right = NULL;
    return pNode;
}

node* createAndInputNode()
{
    int value;
    scanf("%d", &value);
    return createNode(value);
}

void createTree()
{
    root = NULL;
}

// gán giá trị cho 1 cây nhị phân hoàn chỉnh dựa trên mức tối đa cho phép của cây đó
void inputTree(int level, node** currentNode)
{
    if(level >0)
    {
        *currentNode = createAndInputNode();
        inputTree(level-1,&(*currentNode)->left);
        inputTree(level-1,&(*currentNode)->right);
    }
}

// tạo cây ngẫu nhiên
void generateRandomTree(int level, node** currentNode)
{
    if(level>0)
    {
        *currentNode = createNode(rand()%20);
        printf("%d ",(*currentNode)->data);
        generateRandomTree(level-1,&(*currentNode)->left);
        generateRandomTree(level-1,&(*currentNode)->right);
    }
}

// tạo ngẫu nhiên 1 cây có n phần tử, được phân chia ngẫu nhiên
// Cây này có thể không hoàn chỉnh ( chưa làm)



// Kiểm tra xem cây có là cây nhị phân tìm kiếm không
bool isBinarySearchTree(node* pNode)
{
    if(pNode == NULL)
    {
        return true;
    }
    if(pNode->left != NULL && pNode->left->data > pNode->data)
    {
        return false;
    }
    if(pNode -> right != NULL && pNode->right->data < pNode->data)
    {
        return false;
    }
    if(isBinarySearchTree(pNode->left) == false || isBinarySearchTree(pNode->right) == false)
    {
        return false;
    }

    return true;
}

// kiểm tra xem đã tồn tại giá trị value trong cây hay chưa
bool isValueExist(int value, node* pNode)
{
    if(pNode == NULL)
    {
        return false;
    }
    if(pNode->data == value)
    {
        return true;
    }
    return isValueExist(value, pNode->left) || isValueExist(value, pNode->right);
}

// Nhập giá trị, kiểm tra xem giá trị này đã tồn tại hay chưa, nếu chưa thì thêm giá trị này vào cây
//  sao cho cây vẫn là cây nhị phân tìm kiếm

void printTreePreorder(node * pNode)
{
    if(pNode != NULL)
    {
        printf("%d ",pNode->data);

        printTreePreorder(pNode->left);

        printTreePreorder(pNode->right);

    }
}

void printTreeInfix(node * pNode)
{
    if(pNode != NULL)
    {
        printTreeInfix(pNode->left);
        printf("%d ",pNode->data);
        printTreeInfix(pNode->right);
    }
}

void printTreePostorder(node * pNode)
{
    if(pNode != NULL)
    {
        printTreePostorder(pNode->left);
        printTreePostorder(pNode->right);
        printf("%d ",pNode->data);
    }
}

// kiểm tra 1 giá trị đã tồn tại trong cây nhị phân tìm kiếm hay chưa
bool isExist(int value, node* pNode)
{
    if(pNode == NULL)
    {
        return false;
    }
    if(pNode -> data == value)
    {
        return true;
    }
    if(value <pNode->data)
    {
        return isExist(value,pNode->left);
    } else
    {
        return isExist(value,pNode->right);
    }
}

// tim node truoc node có gia tri can xoa
node* findPreNode(int value, node* rootNode)
{
     if(value < rootNode ->data)
     {
         if(value == rootNode ->left -> data)
         {
             return rootNode;
         }
         return findPreNode(value , rootNode -> left);
     }
    else
    {
        if(value == rootNode->right->data)
        {
            return rootNode;
        }
        return findPreNode(value , rootNode->right);
    }
}


// xoa node
void deleteNode(int value, node* rootNode)
{
    if( rootNode == NULL)
    {
        return;
    }
    // tim node lien truoc
    node* preNode = findPreNode(value, rootNode);
    // kiem tra xem day la nut trai hay phai
    if(preNode->left->data == value)
    {
        preNode->left = NULL;
        free(preNode->left);
    }
    else
    {
        preNode->right = NULL;
        free(preNode->right);
    }
}

node* findMostRight(node* pNode)
{
    if(pNode == NULL)
    {
        return NULL;
    }

    if(pNode->right !=NULL)
    {
        return findMostRight(pNode->right);
    }

    return pNode;
}

void swapValue(node* pNode)
{
    int temp = pNode->data;
    pNode->data = pNode->right->data;
    pNode->right->data = temp;
}

// Thêm 1 giá trị vào cây nhị phân tìm kiếm sao cho
// vẫn giữ được đây là cây nhị phân tìm kiếm

void insertNode(int value, node* pNode)
{
    // Nếu có node mang giá trị thì dừng
    if(isExist(value,pNode))
    {
        printf("Gia tri %d da ton tai\n",value);
    }
    // Nếu chưa có node mang giá trị
    else
    {
        // Cây chưa có phần tử
        if(pNode == NULL)
        {
            root = createNode(value);
            return ;
        }
        // Thêm vào nhánh bên phải
        if(pNode -> data < value)
        {
            if(pNode -> right != NULL)
            {
                insertNode(value, pNode ->right);
            }
            else
            {
                pNode -> right = createNode(value);
                return ;
            }
        }
        else
        {
            if(pNode -> left != NULL)
            {
                insertNode(value, pNode -> left);
            }
            else
            {
                pNode -> left = createNode(value);
                return ;
            }
        }
    }
}


int main()
{
    // inputTree(3,&root);
    // printf("\n");
    // printTreePostorder(root);
    //
    // if(isBinarySearchTree(root))
    // {
    //     printf("Binary Search Tree is true\n");
    // } else
    // {
    //     printf("Binary Search Tree is false\n");
    // }


    int t = 20;
    while (t--)
    {
        insertNode(rand()%26,root);
    }
    printf("Cay vua sinh: \n");

    int seed = rand()%3;
    switch (seed)
    {
    case 0:
        {
            printf("PreOrder: ");
            printTreePreorder(root);
            printf("\n");

            printf("InOrder: ");
            printTreeInfix(root);
            printf("\n");
            break;
        }
    case 1:
        {
            printf("PreOrder: ");
            printTreePreorder(root);
            printf("\n");
            printf("PostOrder: ");
            printTreePostorder(root);
            break;
        }
    case 2:
        {
            printf("InOrder: ");
            printTreeInfix(root);
            printf("\n");

            printf("PostOrder: ");
            printTreePostorder(root);
        }
    }

    printf("Most right node has value:  %c ",findMostRight(root)->data+'A');
    return 0;
}






























































