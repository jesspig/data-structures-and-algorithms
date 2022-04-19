class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = Node(None)
        print("init success")

    # 头部插入
    def insert_head(self, val):
        node = Node(val)
        node.next = self.head.next
        self.head.next = node
        print("insert_head success")

    # 尾部插入
    def insert_tail(self, val):
        node = Node(val)
        temp = self.head.next
        while temp.next:
            temp = temp.next
        temp.next = node
        print("insert_tail success")

    # 中间插入
    def insert_middle(self, val, index):
        node = Node(val)
        temp = self.head
        for _ in range(index):
            temp = temp.next
        node.next = temp.next
        temp.next = node
        print("insert_middle success")

    # 头部删除
    def delete_head(self):
        if self.head.next != None:
            print("head is empty")

        self.head.next = self.head.next.next
        print("delete_head success")

    # 尾部删除
    def delete_tail(self):
        if self.head.next == None:
            print("head is empty")

        temp = self.head.next
        while temp.next.next:
            temp = temp.next
        temp.next = None
        print("delete_tail success")

    # 中间删除
    def delete_middle(self, index):
        if self.head.next == None:
            print("head is empty")

        temp = self.head
        for _ in range(index):
            temp = temp.next
        temp.next = temp.next.next
        print("delete_middle success")

    # 修改链表中的值
    def modify(self, index, val):
        if self.head.next == None:
            print("head is empty")

        temp = self.head
        for _ in range(index):
            temp = temp.next
        temp.val = val
        print("modify success")

    # 打印链表
    def display(self):
        node = self.head.next
        flag = False
        print("[", end="")
        while node:
            if flag:
                print(", ", end="")
            print(node.val, end="")
            node = node.next
            flag = True
        print("]")

    # 查找链表中的值
    def search(self, index):
        if self.head.next == None:
            print("head is empty")
        temp = self.head
        for _ in range(index):
            if temp.next == None:
                print("index is error")
                return
            temp = temp.next
        print(temp.val)

    # 销毁链表
    def destroy(self):
        self.head.next = None
        print("destroy success")
