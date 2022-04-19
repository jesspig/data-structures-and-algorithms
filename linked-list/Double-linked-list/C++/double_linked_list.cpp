#include <bits/stdc++.h>

// 类型定义
typedef char ElemType;

typedef struct Node {
  ElemType val;
  struct Node * next;
  struct Node * prev;
} Node;

// 初始化链表
Node * Init() {
  // 创建头结点
  Node * head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    printf("malloc failed\n");
    return NULL;
  }

  head->val = '\0';
  head->next = NULL;  // 后继指针指向NULL
  head->prev = NULL;  // 前驱指针指向NULL
  printf("Init success\n");
  return head;
}

// 头部插入
void InsertHead(Node * head, ElemType val) {
  // 创建新结点
  Node * p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("malloc failed\n");
    return;
  }

  p->val = val;   // 值赋值
  p->next = head->next; // 后继指针指向原头结点的后继
  p->prev = head; // 前驱指针指向原头结点
  head->next = p; // 原头结点的后继指向新结点
  printf("InsertHead success\n");
}

// 尾部插入
void InsertTail(Node * head, ElemType val) {
  // 创建新结点
  Node * p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("malloc failed\n");
    return;
  }

  Node * temp = head; // 临时结点
  // 找到尾结点
  while (temp->next != NULL) {
    temp = temp->next;
  }
  p->val = val;
  p->next = NULL; // 后继指针指向NULL
  p->prev = temp; // 前驱指针指向尾结点
  temp->next = p; // 尾结点的后继指向新结点
  printf("InsertTail success\n");
}

// 中间插入
void InsertMiddle(Node * head, ElemType val, int position) {
  // 创建新结点
  Node * p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("malloc failed\n");
    return;
  }

  Node * temp = head; // 临时结点
  int i = 0;
  // 找到插入位置
  while (i < position) {
    temp = temp->next;
    i++;
  }
  p->val = val;
  p->next = temp->next; // 后继指针指向临时结点的后继
  p->prev = temp; // 前驱指针指向临时结点
  temp->next = p; // 临时结点的后继指向新结点
  printf("InsertMiddle success\n");
}

// 头部删除
void DeleteHead(Node * head) {
  // 判断链表是否为空
  if (head->next == NULL) {
    printf("DeleteHead failed\n");
    return;
  }

  Node * temp = head->next; // 临时结点
  head->next = temp->next; // 头结点的后继指向临时结点的后继
  temp->next->prev = head; // 临时结点的后继的前驱指向头结点
  free(temp); // 释放临时结点
  printf("DeleteHead success\n");
}

// 尾部删除
void DeleteTail(Node * head) {
  // 判断链表是否为空
  if (head->next == NULL) {
    printf("DeleteTail failed\n");
    return;
  }

  Node * temp = head; // 临时结点
  // 找到尾结点
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL; // 尾结点的前驱的后继指向NULL
  free(temp); // 释放尾结点
  printf("DeleteTail success\n");
}

// 中间删除
void DeleteMiddle(Node * head, int position) {
  // 判断链表是否为空
  if (head->next == NULL) {
    printf("DeleteMiddle failed\n");
    return;
  }

  Node * temp = head; // 临时结点
  // 找到插入位置
  int i = 0;
  while (i < position) {
    temp = temp->next;
    i++;
  }
  // 临时结点的前驱的后继指向临时结点的后继
  temp->prev->next = temp->next;
  // 临时结点的后继的前驱指向临时结点的前驱
  temp->next->prev = temp->prev;
  free(temp); // 释放临时结点
  printf("DeleteMiddle success\n");
}

// 修改节点
void Modify(Node * head, ElemType val, int position) {
  // 判断链表是否为空
  if (head->next == NULL) {
    printf("Modify failed\n");
    return;
  }

  Node * temp = head; // 临时结点
  // 找到插入位置
  int i = 0;
  while (i < position) {
    temp = temp->next;
    i++;
  }
  temp->val = val; // 修改临时结点的值
  printf("Modify success\n");
}

// 打印链表
void Display(Node * head) {
  Node * temp = head->next;
  bool flag = false;
  printf("[");
  while (temp != NULL) {
    if (flag) printf(", ");
    printf("%c", temp->val);
    temp = temp->next;
    flag = true;
  }
  printf("]\n");
}

// 销毁链表
void Destroy(Node * head) {
  Node * temp = head->next;
  while (temp != NULL) {
    head->next = temp->next;
    free(temp);
    temp = head->next;
  }
  printf("Destroy success\n");
}