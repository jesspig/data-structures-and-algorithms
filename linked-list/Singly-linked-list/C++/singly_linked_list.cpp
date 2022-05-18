#include <bits/stdc++.h>

typedef char ElemType;

// 单链表结点结构
struct Node {
  ElemType val;  // 节点值
  struct Node * next;  // 后继节点
};


// 创建单链表
class SinglyLinkedList {
private:
  Node * head;// 头结点

public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  void Init(); // 初始化链表
  void Destroy(); // 销毁链表
  void Print(); // 打印链表
  void InsertHead(ElemType val); // 头部插入
  void InsertMiddle(ElemType val, int idx); // 中间插入
  void InsertTail(ElemType val); // 尾部插入
  void DeleteHead(); // 头部删除
  void DeleteMiddle(int idx); // 中间删除
  void DeleteTail(); // 尾部删除
  void Modify(ElemType val, int idx); // 修改值

  // Getter & Setter
  Node * GetHead() { return head; }
  void SetHead(Node * head) { this->head = head; }
  Node * GetNext(Node * node) { return node->next; }
  void SetNext(Node * node, Node * next) { node->next = next; }
  ElemType Getval(Node * node) { return node->val; }
  void Setval(Node * node, ElemType val) { node->val = val; }
};

// 构造函数
SinglyLinkedList::SinglyLinkedList() {
  Init(); // 初始化链表
}

// 析构函数
SinglyLinkedList::~SinglyLinkedList() {
  Destroy(); // 销毁链表
}

// 初始化链表
void SinglyLinkedList::Init() {
  // 创建头结点
  head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    // 内存分配失败
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }

  head->next = NULL; // 头结点指针指向空
  std::cout << "Init()" << std::endl;
}

// 销毁链表
void SinglyLinkedList::Destroy() {
  Node * temp; // 临时结点
  while (head->next != NULL) {
    temp = head->next; // 临时结点指向头结点的下一个结点
    head->next = temp->next; // 头结点指针指向临时结点的下一个结点
    free(temp); // 释放临时结点
  }
  free(head); // 释放头结点

  std::cout << "Destroy()" << std::endl;
}

// 打印链表
void SinglyLinkedList::Print() {
  Node * temp = head->next; // 临时结点指向头结点的后继
  std::cout << "List:[";

  bool flag = false; // 标记是否是第一个结点
  while (temp != NULL) {
    if (flag) {
      std::cout << ", ";
    }
    std::cout << temp->val; // 打印结点数据
    temp = temp->next; // 临时结点指向临时结点的后继
    flag = true; // 标记为非第一个结点
  }

  std::cout << "]" << std::endl;
}

// 头部插入
void SinglyLinkedList::InsertHead(ElemType val) {
  // 创建新结点
  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }

  node->val = val; // 给新节点赋值
  node->next = head->next; // 新结点的后继指向头结点的后继
  head->next = node; // 头结点指针指向新结点

  std::cout << "InsertHead(" << val << ")" << std::endl;
}

// 中间插入
void SinglyLinkedList::InsertMiddle(ElemType val, int idx) {

  Node * temp = head; // 临时结点指向头结点
  int i = 0;
  // 循环找到插入位置
  while (i < idx) {
    if (temp->next == NULL) {
      // 插入位置不存在
      std::cout << "index out of range" << std::endl;
      exit(1);
    }
    temp = temp->next; // 临时结点指向临时结点的后继
    i++;
  }

  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }

  node->val = val;
  node->next = temp->next; // 新结点的后继指向临时结点的后继
  temp->next = node; // 临时结点指向新结点

  std::cout << "InsertMiddle(" << val << ", " << idx << ")" << std::endl;
}

// 尾部插入
void SinglyLinkedList::InsertTail(ElemType val) {
  // 查找尾结点
  Node * temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }

  node->val = val;
  node->next = NULL;
  temp->next = node; // 尾结点指向新结点

  std::cout << "InsertTail(" << val << ")" << std::endl;
}

// 头部删除
void SinglyLinkedList::DeleteHead() {
  if (head->next == NULL) {
    std::cout << "list is empty" << std::endl;
    return;
  }

  Node * temp = head->next; // 临时结点指向头结点的后继
  head->next = temp->next; // 头结点的后继指向临时结点的后继
  free(temp); // 释放临时结点

  std::cout << "DeleteHead()" << std::endl;
}

// 中间删除
void SinglyLinkedList::DeleteMiddle(int idx) {
  if (head->next == NULL) {
    std::cout << "list is empty" << std::endl;
    return;
  }

  Node * temp = head;
  int i = 0;
  while (i < idx) {
    if (temp->next == NULL) {
      // 删除位置不存在
      std::cout << "index out of range" << std::endl;
      exit(1);
    }
    temp = temp->next;
    i++;
  }

  Node * node = temp->next; // 创建node指向临时结点的后继
  temp->next = node->next; // 临时结点的后继指向临时结点的后继
  free(node); // 释放node

  std::cout << "DeleteMiddle(" << idx << ")" << std::endl;
}

// 尾部删除
void SinglyLinkedList::DeleteTail() {
  if (head->next == NULL) {
    // 链表为空
    std::cout << "list is empty" << std::endl;
    return;
  }

  Node * temp = head; // 临时结点指向头结点
  while (temp->next->next != NULL) {
    temp = temp->next; // 临时结点指向临时结点的后继
  }

  Node * node = temp->next; // 创建node指向临时结点的后继
  temp->next = NULL; // 临时结点的后继指向空
  free(node); // 释放node

  std::cout << "DeleteTail()" << std::endl;
}

// 修改
void SinglyLinkedList::Modify(ElemType val, int idx) {
  if (head->next == NULL) {
    std::cout << "list is empty" << std::endl;
    return;
  }

  Node * temp = head->next;
  int i = 0;
  while (i < idx) {
    if (temp->next == NULL) {
      // 修改位置不存在
      std::cout << "index out of range" << std::endl;
      exit(1);
    }
    temp = temp->next;
    i++;
  }

  temp->val = val;

  std::cout << "Modify(" << val << ", " << idx << ")" << std::endl;
}