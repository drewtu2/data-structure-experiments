#include <stdio.h>
#include <type_traits>

struct A {
    int common = 0;
    int type_a = 0;
};

struct B {
    int common = 0;
    int type_b ;
};

template <typename T>
T ModifyType() {
    T type;
    type.common = 1;

    if(std::is_same<T, A>::value) {
        printf("Type A!\n");
        A* ptr = reinterpret_cast<A*>(&type);
        ptr->type_a = 26;
    } else if (std::is_same<T, B>::value) {
        printf("Type B!\n");
        B* ptr = reinterpret_cast<B*>(&type);
        ptr->type_b = 34;
    }
    
    return type;
}


int main() {

    const A a = ModifyType<A>();
    const B b = ModifyType<B>();

    printf("A: (%d, %d)\n", a.common, a.type_a);
    printf("B: (%d, %d)\n", b.common, b.type_b);

    return 0;
}
