#include <iostream>
#include <string>

using namespace std;

int N;
string command[10000];
int num[10000];

struct list{
    int data;
    list* next;
};

list* new_node(int n){
    return new list{n,NULL};
}

int main() {
    cin >> N;

    list* head = NULL;
    list* tail = NULL;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> num[i];
        }
    }

    for (int i = 0 ; i< N; i++){
        if(command[i] == "push_front"){
            list* node = new_node(num[i]);
            if(head == NULL){
                head = node;
                tail = node;
            }
            else if(head == tail){
                node->next = tail;
                head = node;
            }
            else{
                node->next = head;
                head = node;
            }
        }
        if(command[i] == "push_back"){
            list* node = new_node(num[i]);
            if(head == NULL){
                head = node;
                tail = node;
            }
            else if( head == tail ){
                head->next = node;
                tail = node;
            }
            else{
                tail->next = node;
                tail = node;
            }
        }
        if(command[i] == "pop_front"){
            if(head == NULL){
                continue;
            }
            else if(head == tail){
                cout << head->data << endl;
                head = NULL;
                tail = NULL;
            }
            else{
                cout << head->data << endl;
                list* temp = head;
                head = head->next;
                delete temp;
            }
        }
        if(command[i] == "pop_back"){
            if(head == NULL){
                continue;
            }
            else if(head == tail ){
                cout << tail->data << endl;
                head = NULL;
                tail = NULL;
            }
            else{
                list* node = head;
                cout << tail->data << endl;
                while(node->next !=tail){
                    node = node->next;
                }
                list* temp = tail;
                node->next = NULL;
                tail = node;
                delete temp;
            }
        }
        if(command[i] == "size"){
            int count = 0;
            if(head == NULL){
                continue;
            }
            else if(head == tail){
                cout << 1 << endl;
            }
            else{
                list* node = head;
                while(node !=NULL){
                    count++;
                    node = node->next;
                }
                cout << count << endl;
            }
        
        }
        if(command[i] == "empty"){
            if(head == NULL){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        if(command[i] == "front"){
            if(head == NULL){
                continue;
            }
            cout << head->data << endl;
        }
        if(command[i] == "back"){
            if(head == NULL){
                continue;
            }
            cout << tail->data << endl;
        }
    }



    // Please write your code here.

    return 0;
}
