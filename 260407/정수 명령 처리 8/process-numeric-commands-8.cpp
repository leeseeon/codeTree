#include <iostream>

using namespace std;

int num[100000];
string commend[100000];

struct list{
    int data;
    list* next;
};

list* new_node(int n){
    return new list{n, NULL};
}

int main() {
    int n;

    cin >> n;

    string cmd;

    list* head = NULL;
    list* tail = NULL;

    for(int i = 0 ; i < n ; i++){
        cin >> cmd;
        commend[i] = cmd;
        if(commend[i] == "push_front" || commend[i] == "push_back"){
            cin >> num[i];
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(commend[i] == "push_front"){
            list* node = new_node(num[i]);
            if(head == NULL){
               head = node;
               tail = node;  
            }
            else{
                node->next = head;
                head = node;
            }

        }
        if(commend[i] == "push_back"){
            list* node = new_node(num[i]);
            if(head == NULL){
                head = node;
                tail = node;
            }
            else{
                tail->next = node;
                tail = node;
            }
            
        }
        if(commend[i] == "pop_front"){
            if(head == NULL){
                head = NULL;
            }
            else if( head == tail){
                cout << head->data << endl;
                head = NULL;
                tail = NULL;
            }
            cout << head->data << endl;
            head = head->next;
        }
        if(commend[i] == "pop_back"){
            if(head == NULL){
                head = NULL;
            }
            else if (head == tail){
                cout << tail->data << endl;
                head =NULL;
                tail =NULL;
            }
            else{
                cout << tail->data << endl;
                list* node = head;
                while(node->next != tail){
                    node = node->next;
                }
                tail = node;
                tail->next = NULL;
            }
            
        }
        if(commend[i] == "size"){
            int count = 0;
            list* node = head;
            while(node->next != NULL){
                node = node->next;
                count++;
            }
            cout << count+1 << endl;
        }
        if(commend[i] == "empty"){
            if(head == NULL){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        if(commend[i] == "front"){
            cout << head->data << endl;
        }
        if(commend[i] == "back"){
            cout << tail->data << endl;
            
        }

    }
    return 0;
}