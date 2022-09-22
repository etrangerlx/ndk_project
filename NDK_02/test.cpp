
#include "include/MemoryTrace.h"
#include <unistd.h>

class object {
public:
    int x = 0;
    int y = 0;

    void print() {
        cout << x << endl;
        cout << y << endl;
    }

    object() {
        cout << "construct object:" << this << endl;
    }

    ~object() {
        cout << "deconstruct object:" << this << endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    string str = "xian.lei";
    object *obj = nullptr;
    object *obj1 = nullptr;
    object *obj2 = nullptr;
    ALGO_NEW(object,obj);

    ALGO_NEW(object,obj1);
    ALGO_NEW(object,obj2);

    int *p1 = nullptr;
    ALGO_NEW(int,p1);
    ALGO_DELETE(p1, false);

    ALGO_DELETE(obj1,false);
    ALGO_DELETE(obj2,false);
    ALGO_DELETE(obj,false);

    return 0;
}
