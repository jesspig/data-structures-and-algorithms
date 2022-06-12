#include <bits/stdc++.h>

// 类型定义
typedef char ElemType;

typedef struct Node {
  ElemType val;
  struct Node * next;
  struct Node * prev;
} Node;

class double_linked_list {
private:
  Node * head;
public:
  double_linked_list();
  ~double_linked_list();
  void InsertHead(ElemType val); // 头部插入
  void InsertMiddle(ElemType val, int idx); // 中间插入
  void InsertTail(ElemType val); // 尾部插入
  void DeleteHead(); // 头部删除
  void DeleteMiddle(int idx); // 中间删除
  void DeleteTail(); // 尾部删除
  void Modify(ElemType val, int idx); // 修改值
  void Print(); // 打印链表

  // Getter & Setter
  Node * GetHead() { return head; }
  void SetHead(Node * head) { this->head = head; }
  Node * GetNext(Node * node) { return node->next; }
  void SetNext(Node * node, Node * next) { node->next = next; }
  Node * GetPrev(Node * node) { return node->prev; }
  void SetPrev(Node * node, Node * prev) { node->prev = prev; }
  ElemType Getval(Node * node) { return node->val; }
  void Setval(Node * node, ElemType val) { node->val = val; }
};

// 初始化链表
double_linked_list::double_linked_list() {
  head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    // 内存分配失败
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }
  head->next = NULL;
  head->prev = NULL;
  std::cout << "init double linked list" << std::endl;
}
// 销毁链表
double_linked_list::~double_linked_list() {
  Node * temp = head;
  Node * node = NULL;
  while (temp != NULL) {
    node = temp;
    temp = temp->next;
    free(node);
  }
  std::cout << "destroy double linked list" << std::endl;
}
// 打印链表
void double_linked_list::Print() {
  Node * temp = head->next;
  std::cout << "List [";
  bool flag = false;
  while (temp != NULL) {
    if (flag) {
      std::cout << ", ";
    }
    std::cout << temp->val;
    temp = temp->next;
    flag = true;
  }
  std::cout << "]" << std::endl;
}

// 头部插入
void double_linked_list::InsertHead(ElemType val) {
  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    // 内存分配失败
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }
  node->val = val;
  node->next = head->next; // 新节点的后继指向头节点的后继
  node->prev = head; // 新节点的前驱指向头节点
  head->next = node; // 头节点的后继指向新节点
  std::cout << "InsertHead(" << val << ")" << std::endl;
}

// 中间插入
void double_linked_list::InsertMiddle(ElemType val, int idx) {
  Node * temp = head->next; // 创建临时节点
  int i = 0;
  while (i < idx && temp != NULL) {
    temp = temp->next; // 找到要插入的位置
    i++;
  }

  if (temp == NULL) {
    // 插入位置超出范围
    std::cout << "index out of range" << std::endl;
    return;
  }

  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    // 内存分配失败
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }

  node->val = val;
  node->next = temp->next; // 新节点的后继指向原节点的后继
  node->prev = temp; // 新节点的前驱指向原节点
  temp->next = node; // 原节点的后继指向新节点

  std::cout << "InsertMiddle(" << val << ", " << idx << ")" << std::endl;
}

// 尾部插入
void double_linked_list::InsertTail(ElemType val) {
  Node * temp = head;
  // 找到尾节点
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node * node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    std::cout << "malloc failed" << std::endl;
    exit(1);
  }
  node->val = val;
  node->next = NULL; // 新节点的后继指向空
  node->prev = temp; // 新节点的前驱指向原节点
  temp->next = node; // 原节点的后继指向新节点
  std::cout << "InsertTail(" << val << ")" << std::endl;
}

// 头部删除
void double_linked_list::DeleteHead() {
  if (head->next == NULL) {
    // 链表为空
    std::cout << "list is empty" << std::endl;
    return;
  }
  Node * temp = head->next;
  head->next = temp->next; // 头节点的后继指向原头节点的后继
  temp->next->prev = head; // 原节点的后继的前驱指向头节点
  free(temp);
  std::cout << "DeleteHead()" << std::endl;
}

// 中间删除
void double_linked_list::DeleteMiddle(int idx) {
  if (head->next == NULL) {
    // 链表为空
    std::cout << "list is empty" << std::endl;
    return;
  }
  Node * temp = head;
  int i = 0;
  while (i < idx) {
    temp = temp->next;
    i++;
  }
  if (temp == NULL) {
    // 插入位置超出范围
    std::cout << "index out of range" << std::endl;
    return;
  }
  temp->prev->next = temp->next; // 原节点的前驱的后继指向原节点的后继
  temp->next->prev = temp->prev; // 原节点的后继的前驱指向原节点的前驱
  free(temp);
  std::cout << "DeleteMiddle(" << idx << ")" << std::endl;
}

// 尾部删除
void double_linked_list::DeleteTail() {
  if (head->next == NULL) {
    // 链表为空
    std::cout << "list is empty" << std::endl;
    return;
  }
  Node * temp = head;
  // 找到尾节点
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL; // 原节点的前驱的后继指向空
  free(temp);
  std::cout << "DeleteTail()" << std::endl;
}
