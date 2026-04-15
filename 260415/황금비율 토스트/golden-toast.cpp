#include <iostream>
using namespace std;

string cmd[100000][100000];

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

    

    

    for(int i = 0 ; i < m; i++){
        cin >> cmd[i][0];
        if(cmd[i][0] == "P"){
            cout << " ";
            cin >> cmd[i][i];
        }
    }


    
    for(inti = 0 ; i < n; i++){
        if(cmd[i][0] == "L"){

        }
        if(cmd[i][0] == "R"){

        }
        if(cmd[i][0] == "D"){

        }
        if(cmd[i][0] == "P"){

        }
    }
   
    return 0;
}