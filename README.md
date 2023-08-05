# 125_9.11尾插法创建链表

## 上官原始代码（运行环境linux)
```cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test
{
    int data;
    struct test* next;
}test, * ptest;

void printLink(ptest head)
{
    int i;
    ptest p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

ptest insertTail(ptest head, ptest news)
{
    ptest p = head;
    if (p == NULL) {
        head = news;
        return head;//没有此句段错误
    }
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = news;

    return head;
}

ptest creatLink(ptest head)
{
    ptest news;
    while (1) {
        news = (ptest)malloc(sizeof(test));
                // 检查内存分配是否成功
        if (news == NULL)
        {
            printf("内存分配失败\n");
            return head; // 返回链表头指针
        }
        printf("请输入新的节点,输入999结束输入\n");
        scanf_s("%d", &news->data);
        if (news->data == 999) {
            free(news);
            news = NULL;
            return head;
        }
        head = insertTail(head, news);
    }
}

int main()
{
    ptest head = NULL;
    head = creatLink(head);
    printLink(head);
    return 0;
}
```

## 上官的代码在windows的vs2022环境出现的错误如下
根据你提供的输入数据和错误信息，在创建链表过程中出现了问题。
### 这是报错信息
请输入新的节点,输入数字0结束输入
4
请输入新的节点,输入数字0结束输入
4

C:\Users\86181\source\repos\125_9.11尾插法创建链表\x64\Debug\125_9.11尾插法创建链表.exe (进程 19736)已退出，代码为 -1073741819。
按任意键关闭此窗口. . .
问题可能出现在插入节点时的逻辑上。在他的代码中，insertTail 函数使用的是尾插法将新节点插入链表。然而，在遍历链表找到尾部节点之后，他没有为新节点的 next 指针赋值为 NULL，导致链表最后一个节点的 next 指针未正确设置为 NULL。
为了解决这个问题，可以在 insertTail 函数中为新节点的 next 指针赋值为 NULL。修改代码如下：
### 只有这个函数报错，所以只单独拿出这段原始代码
```cpp 
ptest insertTail(ptest head, ptest news)
{
    ptest p = head;
    if (p == NULL) {
        head = news;
        return head;//没有此句段错误
    }
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = news;

    return head;
}
```
### 这是修改后的代码
```cpp
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
```
通过上述修改，新节点插入链表尾部后，将正确地设置 next 指针为 NULL。
请重新编译和运行修改后的代码，并输入新的节点数据进行测试。如果问题仍然存在，请提供详细的输入数据和完整的错误信息，以便更好地帮助你解决问题。

## 附上VS2022环境下可运行的完整代码
```cpp
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


```












