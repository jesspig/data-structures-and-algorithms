class Node {
  public char val;
  public Node next;

  public Node() {
  }

  @Override
  public String toString() {
    return "Node{" +
        "val=" + val +
        ", next=" + next +
        '}';
  }
}

public class SinglyLinkedList {

  public Node Init() {
    Node head = new Node();
    head.next = null;
    System.out.println("Init success");
    return head;
  }

  public void InsertHead(Node head, char val) {
    Node p = new Node();
    p.val = val;
    p.next = head.next;
    head.next = p;
    System.out.println("InsertHead success");
  }

  public void InsertTail(Node head, char val) {
    Node p = new Node();
    p.val = val;
    p.next = null;
    if (head.next == null)
      head.next = p;
    else {
      Node q = head.next;
      while (q.next != null)
        q = q.next;
      q.next = p;
    }
    System.out.println("InsertTail success");
  }

  public void InsertMiddle(Node head, char val, int idx) {
    Node t = head;
    for (int i = 0; i < idx; i++) {
      t = t.next;
      if (t.next == null)
        System.out.println("insert position error");
    }

    Node p = new Node();
    p.val = val;
    p.next = t.next;
    t.next = p;
    System.out.println("InsertMiddle success");
  }

  public void DeleteHead(Node head) {
    if (head.next == null) {
      System.out.println("head is empty");
      return;
    }
    Node p = head.next;
    head.next = p.next;
    System.out.println("DeleteHead success");
  }

  public void DeleteTail(Node head) {
    if (head.next == null) {
      System.out.println("head is empty");
      return;
    }
    Node p = head.next, q = null;
    while (p.next != null) {
      q = p;
      p = p.next;
    }
    q.next = null;
    System.out.println("DeleteTail success");
  }

  public void DeleteMiddle(Node head, int idx) {
    Node p = head.next, q = null;
    for (int i = 0; i < idx; i++) {
      q = p;
      p = p.next;
      if (p == null) {
        System.out.println("delete position error");
        return;
      }
    }
    q.next = p.next;
    System.out.println("DeleteMiddle success");
  }

  public void Modify(Node head, int idx, char val) {
    Node p = head;
    for (int i = 0; i < idx; i++) {
      p = p.next;
      if (p == null)
        System.out.println("modify position error");
    }
    p.val = val;
    System.out.println("Modify success");
  }

  public void Display(Node head) {
    Node p = head.next;
    boolean flag = false;
    System.out.print('[');
    while (p != null) {
      if (flag)
        System.out.print(", ");
      System.out.print(p.val);
      p = p.next;
      flag = true;
    }
    System.out.println("]");
  }

  public void Destroy(Node head) {
    Node p = null;
    while (head.next != null) {
      p = head.next;
      head.next = p.next;
      p = null;
    }
    System.out.println("Destroy success");
  }

}