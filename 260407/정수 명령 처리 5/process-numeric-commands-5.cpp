#include <iostream>

using namespace std;

int N;
int count = -1;
string command[10000];
int num[10000];



int main() {
    cin >> N;

    int* arr = new int[100000];

    int size = -1;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_back" || command[i] == "get") {
            cin >> num[i];
        }
    }

    for(int i = 0 ; i < N; i++){
        if(command[i] == "push_back"){
            arr[++size] = num[i];
        }
        if(command[i] == "pop_back"){
            arr[size] == 0;
            --size;
        }
        if(command[i] == "size"){
            cout << size + 1 << endl;
        }
        if(command[i] == "get"){
            cout << arr[num[i]-1] << endl;
        }
    }

    

    // Please write your code here.

    return 0;
}
