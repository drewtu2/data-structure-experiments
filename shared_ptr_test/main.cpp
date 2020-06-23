#include <iostream>
#include <vector>
#include <memory>

void DoSomethingPtr(const std::shared_ptr<const std::vector<int>> vec) {
    return;
}

void DoSomethingReference(const std::shared_ptr<const std::vector<int>>& vec) {
    return;
}


int main() {
    srand((unsigned)time(NULL));
    const int vec_size = 10;

    std::vector<int> my_vec;
    my_vec.reserve(vec_size);
    for (int ii = 0; ii < vec_size; ++ii) {
        const int b = rand() % 20 + 1;
        my_vec.emplace_back(b);
    }
    auto ptr = std::make_shared<const std::vector<int>>(my_vec);

    const int num_runs = 10 * 1000 * 1000;
    for(int ii = 0; ii < num_runs; ++ii) {
        //DoSomethingPtr(ptr);
        DoSomethingReference(ptr);
    }

    return 0;
}
