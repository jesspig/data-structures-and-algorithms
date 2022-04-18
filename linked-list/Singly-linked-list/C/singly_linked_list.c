#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 节点
typedef  struct Node {
  ElemType val;  // 节点值
  struct Node * next;  // 后继节点
}Node;

// 初始化链表
Node * Init() {
  // 创建头节点
  Node * head = (Node *) malloc(sizeof(Node));
  // 判断头节点是否创建成功
  if (head == NULL) {
    printf("malloc failure\n");
    return NULL;
  }
  printf("Init success\n");

  head->next = NULL; // 头节点的后继为NULL
  return head;
}

// 头部插入节点
void InsertHead(Node * head, ElemType val) {
  // 创建新节点
  Node * p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("malloc failure\n");
    return;
  }

  p->val = val; // 设置新节点的值
  p->next = head->next; // 新节点的后继指向头节点的后继
  head->next = p; // 新节点成为头节点的后继

  printf("InsertHead success\n");
}

// 尾部插入节点
void InsertTail(Node * head, ElemType val) {
  // 创建新节点
  Node * p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("malloc failure\n");
    return;
  }

  p->val = val;
  p->next = NULL; // 新节点的后继指向NULL

  // 判断头节点是否为空
  if (head->next == NULL) head->next = p; // 头节点的后继为新节点
  else {
    // 循环遍历链表
    Node * q = head->next;
    while (q->next != NULL) {
      q = q->next; // 后继节点不为空，则继续循环
    }
    q->next = p; // 尾节点的后继为新节点
  }
  printf("InsertTail success\n");
}

// 中间插入节点 
void InsertMiddle(Node * head, ElemType val, int position) {

  // 查找插入位置
  Node * temp = head;
  int i;
  for (i = 0; i < position; i++) {
    temp = temp->next;
    if (temp == NULL) {
      printf("insert position error\n");
      return;
    }
  }

  // 创建新节点
  Node * p = (Node *) malloc(sizeof(Node));
  if (p == NULL) {
    printf("malloc failure\n");
    return;
  }

  p->val = val;
  p->next = temp->next; // 新节点的后继指向temp的后继
  temp->next = p; // temp的后继指向新节点
  printf("InsertMiddle success\n");
}

// 头部删除节点
void DeleteHead(Node * head) {
  // 判断头节点是否为空
  if (head->next == NULL) {
    printf("head is empty\n");
    return;
  }

  // 删除头节点
  Node * p = head->next;
  head->next = p->next;
  free(p); // 释放内存
  printf("DeleteHead success\n");
}

// 尾部删除节点
void DeleteTail(Node * head) {
  // 判断头节点是否为空
  if (head->next == NULL) {
    printf("head is empty\n");
    return;
  }

  // 循环遍历链表
  Node * p = head->next, * q; // p代表当前节点，q代表前驱节点
  while (p->next != NULL) {
    q = p; // p成为后继节点的前驱节点
    p = p->next; // p指向后继节点
  }
  // 将q的后继指向NULL
  q->next = NULL;
  free(p); // 释放内存
  printf("DeleteTail success\n");
}

// 中间删除节点
void DeleteMiddle(Node * head, int position) {

  Node * p = head, * q; // p代表当前节点，q代表前驱节点
  // 查找删除位置
  int i;
  for (i = 0; i < position; i++) {
    q = p; // p成为后继节点的前驱节点
    p = p->next;
    if (p == NULL) {
      // 删除位置不存在
      printf("delete position error\n");
      return;
    }
  }

  q->next = p->next; // 前驱节点的后继指向p的后继
  free(p); // 释放内存
  printf("DeleteMiddle success\n");
}

// 修改节点的值
void Modify(Node * head, ElemType val, int position) {

  Node * p = head;
  // 查找修改位置
  int i;
  for (i = 0; i < position; i++) {
    p = p->next;
    if (p == NULL) {
      // 修改位置不存在
      printf("modify position error\n");
      return;
    }
  }

  p->val = val;
  printf("Modify success\n");
}

void Display(Node * head) {
  Node * p = head->next;
  // 遍历链表
  while (p != NULL) {
    printf("%c", p->val);
    p = p->next;
  }
  printf("\n");
}

// 销毁链表
void Destroy(Node * head) {
  Node * p;
  // 释放链表中的节点
  while (head->next != NULL) {
    p = head->next;
    head->next = p->next;
    free(p);
  }
  printf("Destroy success\n");
}