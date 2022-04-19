#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 节点结构
typedef struct Node {
  ElemType val;
  struct Node * next;
} Node;

// 初始化
Node * Init() {
  // 创建头节点
  Node * head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    printf("malloc failed\n");
    return NULL;
  }
  head->val = '\0';
  head->next = head; // 头节点指向自己
  printf("Init success\n");
  return head;
}

// 头部插入
void InsertHead(Node * head, ElemType val) {
  // 创建新节点
  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    printf("malloc failed\n");
    return;
  }
  // 初始化新节点
  node->val = val;
  node->next = head->next; // 新节点指向原头节点的下一个节点
  head->next = node; // 头节点指向新节点
  printf("InsertHead success\n");
}

// 尾部插入
void InsertTail(Node * head, ElemType val) {

  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    printf("malloc failed\n");
    return;
  }

  node->val = val;
  node->next = head; // 新节点指向头节点
  // 找到尾节点
  Node * temp = head; // 临时节点
  while (temp->next != head) {
    temp = temp->next;
  }
  temp->next = node; // 原尾节点指向新节点
  printf("InsertTail success\n");
}

// 中间插入
void InsertMiddle(Node * head, ElemType val, int pos) {

  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    printf("malloc failed\n");
    return;
  }

  // 找到pos位置的节点
  Node * temp = head;
  int i = 0;
  while (i < pos) {
    // 如果pos位置超出链表长度，则插入失败
    if (temp->next == head) {
      printf("position error \n");
      return;
    }
    temp = temp->next;
    i++;
  }

  node->val = val;
  node->next = temp->next; // 新节点指向pos位置的节点
  temp->next = node; // pos位置的节点指向新节点
  printf("InsertMiddle success\n");
}


// 头部删除
void DeleteHead(Node * head) {
  // 判断头节点是否为空
  if (head->next == head) {
    printf("DeleteHead failed\n");
    return;
  }
  // 找到头节点的下一个节点
  Node * temp = head->next; // 临时节点
  head->next = temp->next; // 头节点指向原头节点的下一个节点
  free(temp); // 释放临时节点
  printf("DeleteHead success\n");
}

// 尾部删除
void DeleteTail(Node * head) {
  if (head->next == head) {
    printf("DeleteTail failed\n");
    return;
  }

  // 找到尾节点
  Node * temp = head, * prev;
  while (temp->next != head) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = head; // 尾节点的前驱的next指向头节点
  free(temp); // 释放尾节点
  printf("DeleteTail success\n");
}

// 中间删除
void DeleteMiddle(Node * head, int pos) {
  if (head->next == head) {
    printf("DeleteMiddle failed\n");
    return;
  }

  // 找到pos位置的节点
  Node * temp = head, * prev;
  int i = 0;
  while (i < pos) {
    // 如果pos位置超出链表长度，则删除失败
    if (temp->next == head) {
      printf("position error \n");
      return;
    }
    prev = temp;
    temp = temp->next;
    i++;
  }
  prev->next = temp->next; // pos位置的前驱的next指向pos位置的后继
  free(temp); // 删除pos位置的节点
  printf("DeleteMiddle success\n");
}

// 修改节点
void Modify(Node * head, ElemType val, int pos) {
  if (head->next == head) {
    printf("Modify failed\n");
    return;
  }

  // 找到pos位置的节点
  Node * temp = head;
  int i = 0;
  while (i < pos) {
    // 如果pos位置超出链表长度，则修改失败
    if (temp->next == head) {
      printf("position error \n");
      return;
    }
    temp = temp->next;
    i++;
  }
  temp->val = val;
  printf("Modify success\n");
}

void Display(Node * head) {
  Node * temp = head->next;
  printf("[");
  int flag = 0;
  while (temp != head) {
    if (flag) {
      printf(", ");
    }
    printf("%c", temp->val);
    temp = temp->next;
    flag = 1;
  }
  printf("]\n");
}

// 销毁链表
void Destroy(Node * head) {
  // 判断头节点是否为空
  if (head->next == head) {
    free(head);
    return;
  }
  // 逐一释放节点
  while (head->next != head) {
    Node * temp = head->next;
    head->next = temp->next;
    free(temp);
  }
  free(head); // 释放头节点
  printf("Destroy success\n");
}