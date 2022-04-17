#include <bits/stdc++.h>

typedef char ElemType;

// 节点
struct Node {
  ElemType val;  // 节点值
  struct Node * next;  // 后继节点
};

// 初始化链表
Node * Init () {
  Node * head = (Node *) malloc (sizeof (Node));  // 创建头节点

  // 判断头节点是否创建成功
  if (head == NULL) {
    printf ("malloc failure\n");
    return NULL;
  }

  printf ("Init success\n");

  // 头节点的后继为NULL
  head->next = NULL;
  return head;
}

// 头部插入节点
Node * InsertHead (Node * head, ElemType val) {
  // 创建新节点
  Node * p = (Node *) malloc (sizeof (Node));

  if (p == NULL) {
    printf ("malloc failure\n");
    return head;
  }

  // 设置新节点的值
  p->val = val;
  // 新节点的下一个指向头节点的后继
  p->next = head->next;
  // 新节点成为头节点的后继
  head->next = p;

  printf ("InsertHead success\n");

  return head;
}

// 尾部插入节点
Node * InsertTail (Node * head, ElemType val) {
  // 创建新节点
  Node * p = (Node *) malloc (sizeof (Node));

  if (p == NULL) {
    printf ("malloc failure\n");
    return head;
  }

  p->val = val;
  // 新节点的下一个指向NULL
  p->next = NULL;

  // 判断头节点是否为空
  if (head->next == NULL) {
    // 头节点的后继为新节点
    head->next = p;
  } else {
    // 循环遍历链表
    Node * q = head->next;
    while (q->next != NULL) {
      // 后继节点不为空，则继续循环
      q = q->next;
    }
    // 尾节点的后继为新节点
    q->next = p;
  }

  printf ("InsertTail success\n");

  return head;
}

// 中间插入节点 
Node * InsertMiddle (Node * head, ElemType val, int position) {

  // 查找插入位置
  Node * temp = head;
  for (int i = 0; i < position; i++) {
    temp = temp->next;
    if (temp == NULL) {
      // 插入位置不存在
      printf ("insert position error\n");
      return head;
    }
  }

  // 创建新节点
  Node * p = (Node *) malloc (sizeof (Node));
  if (p == NULL) {
    printf ("malloc failure\n");
    return head;
  }

  p->val = val;
  // 新节点的下一个指向temp的后继
  p->next = temp->next;
  // temp的后继指向新节点
  temp->next = p;

  printf ("InsertMiddle success\n");

  return head;
}

// 头部删除节点
Node * DeleteHead (Node * head) {
  // 判断头节点是否为空
  if (head->next == NULL) {
    printf ("head is empty\n");
    return head;
  }

  // 删除头节点
  Node * p = head->next;
  head->next = p->next;
  free (p); // 释放内存

  printf ("DeleteHead success\n");

  return head;
}

// 尾部删除节点
Node * DeleteTail (Node * head) {
  // 判断头节点是否为空
  if (head->next == NULL) {
    printf ("head is empty\n");
    return head;
  }

  // 循环遍历链表
  Node * p = head->next, * q; // p代表当前节点，q代表前驱节点
  while (p->next != NULL) {
    q = p; // p成为后继节点的前驱节点
    p = p->next; // p指向后继节点
  }
  // 将q的后继指向NULL
  q->next = NULL;
  free (p); // 释放内存

  printf ("DeleteTail success\n");

  return head;
}

// 中间删除节点
Node * DeleteMiddle (Node * head, int position) {

  Node * p = head, * q; // p代表当前节点，q代表前驱节点
  // 查找删除位置
  for (int i = 0; i < position; i++) {
    q = p; // p成为后继节点的前驱节点
    p = p->next;
    if (p == NULL) {
      // 删除位置不存在
      printf ("delete position error\n");
      return head;
    }
  }

  q->next = p->next; // 前驱节点的后继指向p的后继
  free (p); // 释放内存

  printf ("DeleteMiddle success\n");

  return head;
}

// 修改节点的值
Node * Modify (Node * head, ElemType val, int position) {

  Node * p = head;
  // 查找修改位置
  for (int i = 0; i < position; i++) {
    p = p->next;
    if (p == NULL) {
      // 修改位置不存在
      printf ("modify position error\n");
      return head;
    }
  }

  p->val = val;

  printf ("Modify success\n");

  return head;
}

void Display (Node * head) {
  Node * p = head->next;
  // 遍历链表
  while (p != NULL) {
    std::cout << p->val;
    p = p->next;
  }
  std::cout << std::endl;
}

// 销毁链表
void Destroy (Node * head) {
  Node * p;
  // 释放链表中的节点
  while (head->next != NULL) {
    p = head->next;
    head->next = p->next;
    free (p);
  }

  if (p == NULL) {
    printf ("Destroy success\n");
  }
}