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
void ModifyCommon() {
    T type;
    type.common = 1;
    
    return type;
}

template <typename T>
T ModifyUniqueA() {
    T type = ModifyCommon();

    type.a = 26;
    return type;
}

int main() {

    const B b = ModifyCommon<B>();
    const A a = ModifyUniqueA<A>();

    printf("A: (%d, %d)\n", a.common, a.type_a);
    printf("B: (%d, %d)\n", b.common, b.type_b);

    return 0;
}
