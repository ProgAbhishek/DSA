#include <iostream>
#define N 100
using namespace std;

class StaticList {
    int arr[N], count = 0;

public:
    void insertBeg(int val) {
        if (count == N) return;
        for (int i = count; i > 0; i--) arr[i] = arr[i - 1];
        arr[0] = val; count++;
    }

    void insertEnd(int val) {
        if (count == N) return;
        arr[count++] = val;
    }

    void insertAfter(int key, int val) {
        if (count == N) return;
        for (int i = 0; i < count; i++) {
            if (arr[i] == key) {
                for (int j = count; j > i + 1; j--) arr[j] = arr[j - 1];
                arr[i + 1] = val; count++;
                return;
            }
        }
    }

    void delBeg() {
        if (count == 0) return;
        for (int i = 0; i < count - 1; i++) arr[i] = arr[i + 1];
        count--;
    }

    void delEnd() {
        if (count > 0) count--;
    }

    void delAfter(int key) {
        for (int i = 0; i < count - 1; i++) {
            if (arr[i] == key) {
                for (int j = i + 1; j < count - 1; j++) arr[j] = arr[j + 1];
                count--; return;
            }
        }
    }

    void show() {
        for (int i = 0; i < count; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    StaticList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(4);
    l.insertAfter(2, 3);
    l.insertBeg(0);
    l.delAfter(2);
    l.delBeg();
    l.delEnd();
    l.show();
    return 0;
}
