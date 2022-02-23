#include <stdio.h>
#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* next, * prev;
};
struct List
{
    Node* Head, * Tail;
    List() {
        Head = new Node;
        Tail = new Node;
        Head->next = Tail;
        Head->prev = 0;
        Tail->next = 0;
        Tail->prev = Head;
    }
    ~List() {
        Clear();
        delete Head;
        delete Tail;
    }
    // ���������� �������� ����� ��������� ����
    void Addafter(int k, Node* pr) {
        Node* q = new Node;
        q->key = k;
        q->next = pr->next;
        q->prev = pr;
        pr->next = q;
        q->next->prev = q;
    }
    //���������� �������� � �����
    void AddTail(int k)
    {
        Addafter(k, Tail->prev);
    }
    //���������� �������� � ������
    void AddToHead(int k) {
        Addafter(k, Head);
    }
    // ������������ ������
    void Form(int n) {
        int x, i;
        for (i = 0; i < n; i++)
        {
            x = rand() % 100;
            AddTail(x);

        }
    }
    //�������� �������� �� ��������� p
    void Del(Node* p) {
        if (p != Head && p != Tail)
        {
            Node* t1 = p->prev;
            Node* t2 = p->next;
            t1->next = t2;
            t2->prev = t1;
            delete p;
        }
    }
    //�������� ������
    void DelHead()
    {
        if (Head->next == Tail)
            puts("list is empty");
        else
            Del(Head->next);
    }
    //�������� ������
    void DelTail() {
        if (Head->next == Tail)
            puts("list is empty");
        else
            Del(Tail->prev);
    }
    //����� ����� k � ������
    Node* FindKey(int k)
    {
        Node* p = Head->next;
        while (p != Tail && p->key != k)
            p = p->next;
        if (p == Tail)
            return NULL;
        else
            return p;
    }
    // ������� ������
    void Clear()
    {
        while (Head->next == Tail)
        {
            Del(Head->next);
        }
    }
    //����� ������
    void output() {
        Node* p;
        for (p = Head->next; p != Tail; p = p->next)
            cout << p->key << " ";
        cout << endl;
    }
    void AddAfterZ(int k) {
        Node* p = Tail->prev;
        while (p != Head && p->key != k)
            p = p->prev;
        if (p == Head)
            cout << "������� � ������ �� ������������ ";
        else
        {
            Del(p);
            for (p = Head->next; p != Tail; p = p->next)
                cout << p->key << " ";
        }
    }
};
//���������� �������� ����� ������ �� ����� �������� � �����
int main() {
    setlocale(LC_ALL,"rus");
    List p;
    int* s;
    int n, k;
    cout << " enter kolichestvo elementov v spiske" << endl;
    cin >> n;
    cout << "Enter key" << endl;
    cin >> k;
    p.Form(n);
    p.output();
    p.AddAfterZ(k);
}