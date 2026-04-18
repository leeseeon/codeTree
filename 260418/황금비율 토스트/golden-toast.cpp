#include <iostream>
using namespace std;

string cmd[10000];
string cmd_2[10000];
struct list{
    char word;
    list* pre;
    list* next;
};

list* new_node(char word){
    return new list{word,NULL,NULL};
}



int main() {
    list* head = NULL;
    list* tail = NULL;
    list* cursor = NULL;
    int n , m;
    string begin;

    cin >> n >> m;
    cin >> begin;

    
    for(int i = 0 ; i < n ; i++){
        list* node = new_node(begin[i]);
        if(head == NULL){
            head = node;
            tail = node;
        }
        tail->next = node;
        node->pre = tail;
        tail = node;
    }

    cursor = tail;

    for(int i = 0; i< m; i++){
        cin >> cmd[i];
        if(cmd[i] == "P"){
            cin >> cmd_2[i];
        }
    }
    
    for(int i = 0 ; i<m; i++){
        if(cmd[i] == "L"){
            if(cursor->pre == NULL){
                continue;
            }
            cursor = cursor->pre;
        }
        if(cmd[i] == "R"){
            if(cursor->next == NULL){
                continue;
            }
            cursor = cursor->next;
        }
        if(cmd[i] == "p"){
            if(cursor->next == NULL){
                continue;
            }
            list* node = new_node(cmd_2[i]);
            list* cur = cursor->next;
            cursor->next = node;
            node->pre = cursor;
            cursor = cur;
            cursor->pre = node;
            node->next= cursor; 
        }
    }

    return 0;
}
