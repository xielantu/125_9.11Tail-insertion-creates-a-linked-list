//// 125_9.11尾插法创建链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test
{
    int data;
    struct test* next;
}test, * ptest;

// 打印链表
void printLink(ptest head)
{
    ptest p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

// 头插法插入节点
ptest inserBehind(ptest head, ptest news)
{
    if (head == NULL)
    {
        news->next = NULL;  // 将新节点的 next 指针设为 NULL
        head = news;
    }
    else
    {
        news->next = head;
        head = news;
    }
    return head;
}

ptest insertTail(ptest head, ptest news)
{
   
    if (head == NULL) {
        head = news;
        news->next = NULL;
        return head;//没有此句段错误
    }
    else
    {
        ptest p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = news;
        news->next = NULL;
    }
    

    return head;
}


// 创建链表
ptest creatLink(ptest head)
{
    while (1)
    {
        ptest news = (ptest)malloc(sizeof(test)); // 创建新的节点结构体并分配内存空间

        // 检查内存分配是否成功
        if (news == NULL)
        {
            printf("内存分配失败\n");
            return head; // 返回链表头指针
        }

        printf("请输入新的节点,输入数字0结束输入\n");
        scanf_s("%d", &(news->data)); // 从用户输入读取新节点的数据

        // 如果输入数据为0，则释放新节点的内存并返回链表头指针
        if (news->data == 0)
        {
            free(news);
            news = NULL;
            printf("0 quit\n");
            return head; // 返回链表头指针
        }

        head = insertTail(head, news); // 将新节点使用头插法插入链表的尾部
    }
}

int main()
{
    ptest head = NULL;
    head = creatLink(head); // 创建链表并将返回的头指针赋值给 head 变量
    printLink(head); // 打印链表

    return 0;
}

