#include <iostream>
using namespace std;

char cmd = [100000];

struct list{
    char word;
    list* pre , next;
};

list* new_node(stirng word){
    return list* node{
        word,NULL,NULL,
    };
}



int main() {
    list* head;
    list* tail;

    node1 = new_node(c);
    node2 = new_node(o);
    node3 = new_node(d);
    node4 = new_node(e);
    node5 = new_node(t);

    head = node1;
    tail = node5;

    head->next = node2;
    node2->pre = head;
    node2->next = node3;
    node3->pre = node2;
    node3->next = node4;
    node4->pre = node3;
    node4->next = tail;
    tail->pre = node4; 
    

    int n = 0;
    int cmd = 0;
    
    cin >> n;

    return 0;
}