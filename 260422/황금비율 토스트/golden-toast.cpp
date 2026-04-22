#include <iostream>
using namespace std;

char cmd[10000];
char cmd2[10000];

struct list{
    char word;
    list* pre;
    list* next;
};

list* new_node(char word){
    return new list{word, NULL, NULL};
}

int main() {
    list* head = NULL;
    list* tail = NULL;
    list* iterator = NULL;

    int n, m;
    string begin;

    cin >> n >> m;
    cin >> begin;

    // 초기 리스트 생성
    for(int i = 0 ; i < n; i++){
        list* node = new_node(begin[i]);

        if(head == NULL){
            head = tail = node;
        }
        else{
            tail->next = node;
            node->pre = tail;
            tail = node;
        }
    }

    iterator = tail; // 커서는 맨 뒤

    // 명령 입력
    for(int i = 0 ; i < m; i++){
        cin >> cmd[i];
        if(cmd[i] == 'P'){
            cin >> cmd2[i];
        }
    }

    // 명령 처리
    for(int i = 0 ; i < m; i++){

        // L : 왼쪽 이동
        if(cmd[i] == 'L'){
            if(iterator != NULL)
                iterator = iterator->pre;
        }

        // R : 오른쪽 이동
        else if(cmd[i] == 'R'){
            if(iterator == NULL){
                if(head != NULL) iterator = head;
            }
            else if(iterator->next != NULL){
                iterator = iterator->next;
            }
        }

        // D : 오른쪽 삭제 (핵심)
        else if(cmd[i] == 'D'){
            list* del;

            if(iterator == NULL){
                del = head;
                if(del == NULL) continue;

                head = head->next;
                if(head != NULL) head->pre = NULL;
                else tail = NULL;
            }
            else{
                del = iterator->next;
                if(del == NULL) continue;

                iterator->next = del->next;

                if(del->next != NULL)
                    del->next->pre = iterator;
                else
                    tail = iterator;
            }

            delete del;
        }

        // P x : 삽입
        else if(cmd[i] == 'P'){
            list* node = new_node(cmd2[i]);

            if(iterator == NULL){
                node->next = head;
                if(head != NULL) head->pre = node;
                head = node;

                if(tail == NULL) tail = node;
            }
            else{
                node->next = iterator->next;
                node->pre = iterator;

                if(iterator->next != NULL)
                    iterator->next->pre = node;
                else
                    tail = node;

                iterator->next = node;
            }

            iterator = node;
        }
    }

    // 출력
    list* cur = head;
    while(cur != NULL){
        cout << cur->word;
        cur = cur->next;
    }

    return 0;
}