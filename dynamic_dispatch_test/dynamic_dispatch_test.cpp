#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Base {
  public:
    Base() {
        cout << "Base Created!" << endl;
    }
    
    void Internal() {
        cout << "Called base internal no virtual!" << endl;
    }

    virtual void InternalVirtual() const {
        cout << "Called base internal virtual!" << endl;
    }

    bool operator<(const Base& other) const {
        cout << "Called base < (no virtual)" << endl;
        return !other.Compare(this);
    }
    
    virtual bool operator>(const Base& other) const {
        cout << "Called base > (virtual)" << endl;
        return true;
    }
    
    bool operator=(const Base& other) const {
        cout << "Called base =" << endl;
        return true;
    }
    
    virtual bool Compare(const Base& other) const {
        cout << "Called Base Compare" << endl;
        return true;
    }
    
    virtual bool Compare(const Base* other) const {
        cout << "Called Base Compare raw" << endl;
        return true;
    }
    
    virtual bool Compare(const std::shared_ptr<Base> other) const {
        cout << "Called Base Compare raw" << endl;
        return true;
    }
};

class Derived : public Base {

  public:
    Derived() : Base() {
        cout << "Derived Created!" << endl;
    }
    
    void Internal() {
        cout << "Called derived internal no virtual!" << endl;
    }
    
    void InternalVirtual() const override {
        cout << "Called derived internal virtual!" << endl;
    }

    bool operator<(const Derived& other) const {
        cout << "Called derived < (no virtual)" << endl;
        return true;
    }

    bool operator>(const Derived& other) const {
        cout << "Called derived > (virtual)" << endl;
        return true;
    }
    
    bool operator=(const Base& other) const {
        cout << "Called derived = (no virtual)" << endl;
        return true;
    }
    
    bool Compare(const Base& other) const override {
        cout << "Called derived Compare ref" << endl;
        Base other_base = other;
        const Derived& other_derived = dynamic_cast<const Derived&>(other);
        other_derived.InternalVirtual();
        return true;
    }
    
    bool Compare(const Base* other) const override {
        cout << "Called derived Compare raw" << endl;
        const Derived* other_derived = dynamic_cast<const Derived*>(other);
        other_derived->InternalVirtual();
        return true;
    }
    
    bool Compare(const std::shared_ptr<Base> other) const override {
        cout << "Called derived Compare raw" << endl;
        return true;
    }
    
}; 

void DynamicDispatchCall(Base& base) {
    cout << "Called base function!" << endl;
}

void DynamicDispatchCall(Derived& base) {
    cout << "Called derived function!" << endl;
}

int main() {
    cout << "Hello world" << endl;

    std::shared_ptr<Base> base_ptr_to_base = std::make_shared<Base>();
    DynamicDispatchCall(*base_ptr_to_base);
    base_ptr_to_base->Internal();
    base_ptr_to_base->InternalVirtual();
    *base_ptr_to_base < *base_ptr_to_base;
    *base_ptr_to_base > *base_ptr_to_base;

    cout << endl;

    std::shared_ptr<Base> derived_ptr_to_base = std::make_shared<Derived>();
    DynamicDispatchCall(*derived_ptr_to_base);
    derived_ptr_to_base->Internal();
    derived_ptr_to_base->InternalVirtual();
    *derived_ptr_to_base < *derived_ptr_to_base;
    *derived_ptr_to_base > *derived_ptr_to_base;
    *derived_ptr_to_base = *derived_ptr_to_base;
    (*derived_ptr_to_base).InternalVirtual();
    derived_ptr_to_base->Compare(*derived_ptr_to_base);
    (*derived_ptr_to_base).Compare(*derived_ptr_to_base);
    (*derived_ptr_to_base).Compare(*derived_ptr_to_base);
    
    cout << endl;
    *derived_ptr_to_base < *derived_ptr_to_base;

    return 0;
}
