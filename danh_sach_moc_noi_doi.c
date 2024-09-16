//
// Created by ACER on 9/2/2024.
//

#include <stdio.h>
#include <stdlib.h>

// tạo cấu trúc của node
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

// con trỏ luôn trỏ tới node đầu
node *head = NULL;
// con trỏ luôn trỏ tới node cuối cùng
node *tail = NULL;

// khai báo node
node *makenode(int x)
{
    node *newnode= (node *)malloc(sizeof(node));

    if(newnode == NULL)
    {
        printf("khong du bo nho de cap phat\n");
        return NULL;
    }

    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;

}

// thêm node vào đầu
void addNodeFirst(int x)
{
    node *q = makenode(x);
    // nếu danh sách trống thì đưa node vừa tạo thành node cuối
    if(head == NULL)
    {
        tail = q;
    } else // nếu danh sách có phần tử rồi thì đưa phần tử đầu tiên của danh sách trỏ đến q
    {
         head->prev = q;
    }
    // q trỏ đến phần tử dầu tiên
    q->next = head;
    // chuyển phần tử đầu tiên thành q
    head = q;
}

// thêm node vào cuối
void addNodeLast(int x)
{
    node *q = makenode(x);
    // nếu danh sách rỗng thì đưa node vừa tạo thành node cuối
    if(head == NULL)
    {
        tail = q;
    }
    // nếu danh sách không rỗng thì cho node cuối cùng trỏ đến q
    else
    {
        tail->next = q;
    }

    // q trỏ dến phần tử cuối cùng
    q->prev = tail;

    // chuyển q thành phần tử cuối cùng
    tail = q;
}

// thêm node vào giữa trước 1 node khác
void addNode(int x, int c)
{
    node *p = makenode(c);
    // kiểm tra danh sách có trống hay không
    if(head == NULL)
    {
        addNodeFirst(x);
    }
    else
    {
        // tạo node cần thêm
        node *q = makenode(x);
        // tạo node đầu tiên
        node *phead = head;
        // tìm node có data là c
        while(phead!=NULL)
        {
            if(phead->data == c)
                break;
            phead = phead->next;
        }
        if(phead == NULL)
        {
            printf("Không tìm thấy node p trong danh sach ");
            return;
        } else if(phead == head) // trường hợp node có data là c ở đầu
        {
            addNodeFirst(x);
        }
        else
        {
            q->prev = phead->prev;
            q->next = phead->prev->next;
            phead->prev->next = q;
            phead->prev = q;
        }
    }


}

//xoá node
void deleteNode(int x)
{
    // tạo 1 node ở đầu
    node *q = head;
    while (q != NULL)
    {
        if(q->data == x)
        {
            break;
        }
        q = q->next;
    }
    if(q == NULL)
    {
        printf("Không tìm thấy %d trong danh sách " ,x);
    }
    else if(q == head)
    {
        head = head->next;

    }else if (q == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    } else
    {
        q->prev->next = q->next;
        q->next->prev = q->prev;
    }
    free(q);
}

// in danh sách
void display()
{
    node *q = head;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
}

int main ()
{
    for(int i = 1; i <= 10; i++)
    {
        if(i==1)
        addNodeFirst(i);
        else
        {
            addNodeLast(i);
        }
    }
    display();
    printf("\n");
    addNode(11,5);
    display();
    printf("\n");
    deleteNode(12);
    display();

}



















