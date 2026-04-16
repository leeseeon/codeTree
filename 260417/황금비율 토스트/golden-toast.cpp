#include <iostream>
using namespace std;

string cmd[10000];
string cmd_2[10000];
struct list{
    string word;
    list* pre;
    list* next;
};

list* new_node(string word){
    return new list{word,NULL,NULL};
}



int main() {
    list* head = NULL;
    list* tail = NULL;
    list* iterator = NULL;
    int n = 0;
    int m = 0;
    string begin[10000];

    cin >> n ;
    cout << " " ;
    cin >> m;

    for(int i = 0; i < n; i++){
        cin >> begin[i];
    }

    for(int i = 0; i < n; i++){
        list* node = new_node(begin[i]);
        if(head == NULL){
            head = node;
            tail = node;
            iterator = tail;
        }
        else if(head == tail){
            head->next = node;
            node->pre = head;
            tail = node;
            iterator = tail;
        }
        else{
            iterator->next = node;
            node->pre = iterator;
            tail = node;
            iterator = tail;
        }
        
    }

    

    for(int i = 0 ; i < m; i++){
        cin >> cmd[i];
        if(cmd[i] == "P"){
            cout << " ";
            cin >> cmd_2[i];
        }
    }


    
    for(int i = 0 ; i < n; i++){
        if(cmd[i] == "L"){
            if(head == NULL){
                continue;
            }
            if(iterator->pre == NULL){
                continue;
            }
            iterator = iterator->pre;
        }
        if(cmd[i] == "R"){
            if(head == NULL){
                continue;
            }
            if(iterator->next == NULL){
                continue;
            }
            iterator = iterator->next;
        }
        if(cmd[i] == "D"){
            if(head == NULL){
                continue;
            }
            if(head == tail){
                head = NULL;
                tail = NULL;
                iterator = NULL;
            }

            if(iterator == head){
                head = head->next;
            }
            else if(iterator == tail){
                tail = tail->pre;
            }
            else{
                list* node = iterator->next;
                node->pre = iterator;
                iterator->next = node;
                
                delete node;
            } 
            
        }
        if(cmd[i] == "P"){
            list* node = new_node(cmd_2[i]);
            if(head == NULL){
                continue;
            }

            if(head == tail){
                tail->next = node;
                node->pre = tail;
                tail = node;
            }
            else{
                list* node2 = iterator->next;
                iterator->next = node;
                node->pre = iterator;
                node->next = node2;
                node2 -> pre = node;
            }
            
        }

        list* node = head;
        while(node != NULL){
            cout << node->word;
            node = node->next;
        }
    }
   
    return 0;
}
