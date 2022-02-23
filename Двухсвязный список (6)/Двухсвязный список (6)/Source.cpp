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
        Head = NULL, Tail = NULL;
    }
    ~List() {
        Clear();
    }
    // ���������� �������� ����� ��������� ����
    void Addafter(int k, Node* pr) {
        Node* q = new Node;
        q->key = k;
        q->next = pr->next;
        q->prev = pr;
        pr->next = q;
        if (pr == Tail)
            Tail = q;
        else
            q->next->prev = q;
    }
    //���������� �������� � �����
    void AddTail(int k)
    {
        if (Tail)
            Addafter(k, Tail);
        else
        {
            Node* q = new Node;
            q->key = k;
            q->prev = 0;
            q->next = 0;
            Tail = q;
            Head = q;
        }
    }
    //���������� �������� � ������
    void AddToHead(int k) {
        Node* q = new Node;
        q->key = k;
        q->next = Head;
        q->prev = 0;
        if (Head == 0)
            Tail = q;
        else
            Head->prev = q;
        Head = q;
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
    //�������� ������
    void DelHead()
    {
        if (Head == NULL)
        {
            puts("list is empty");
            return;
        }
        Node* q = Head;
        if (Head == Tail)
            Head = Tail = NULL;
        else
        {
            Head = Head->next;
            Head->prev = 0;
        }
        delete q;
    }
    //�������� ������
    void DelTail() {
        if (Head == NULL)
        {
            puts("list is empty");
            return;
        }
        Node* p = Tail;
        if (Head == Tail)
            Head = Tail = NULL;
        else
        {
            Tail = Tail->prev;
            Tail->next = 0;
        }
        delete p;
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
        else
            if (p == Head)
                DelHead();
            else
                DelTail();
    }
    //����� ����� k � ������
    Node* FindKey(int k)
    {
        if (Head->key == k)
            return Head;
        else
        {
            Node* p = Head;
            while (p != NULL && p->key != k)
                p = p->next;
            if (p == NULL)
                return NULL;
            else
                return p;
        }
    }
    //����� ������� � ������
    Node* FindPos(int pos) {
        Node* p = Head;
        int i = 1;
        while ((p != NULL) && (i < pos))
        {
            i++;
            p = p->next;
        }
        if (p == NULL) {
            cout << "Nety pos";
            return NULL;
        }
        else return p;
    }
    //�������� ������� ������
    bool Empty() {
        if (Tail == NULL)
            return true;
        else
            return false;
    }
    // ������� ������
    void Clear()
    {
        while (Head)
            DelHead();
    }
    int top() {
        return Head->key;
    }
    //����� ������
    void output() {
        Node* p;
        for (p = Head; p != 0; p = p->next)
            cout << p->key << " ";
        cout << endl;
    }
    int popLIST() {
        int k = Tail->key;
        Node* p = Tail;
        Tail = Tail->prev;
        //Tail->next = 0;
        delete p;
        return k;
    }
    Node* AddAfterZ(int k) {
        if (Tail->key == k)
            return Tail;
        else
        {
            Node* p = Tail;
            while (p != NULL && p->key != k)
                p = p->prev;
            if (p == NULL)
                cout << "������� � ������ �� ������������ ";
            else
            {
                Del(p);
                for (p = Head; p != 0; p = p->next)
                    cout << p->key << " ";
            }
        }
    }
 
};
//���������� �������� ����� ������ �� ����� �������� � �����
int main() {
    List p,q;
    int* s;
    int n, k;
    setlocale(LC_ALL, "RUS");
    cout << " enter kolichestvo elementov v spiske" << endl;
    cin >> n;
    cout << "Enter key" << endl;
    cin >> k;
    p.Form(n);
    p.output();
    p.AddAfterZ(k);
}
