#include <iostream>
#include <vector>
#include <memory>
#include <string.h>

void DoSomethingPtr(const std::shared_ptr<const std::vector<int>> vec) {
    std::vector<int> test{vec->begin(), vec->end()};
    return;
}

void DoSomethingReference(const std::shared_ptr<const std::vector<int>>& vec) {
    std::vector<int> test{vec->begin(), vec->end()};
    return;
}


int main(int argc, char* argv[]) {

    if(argc != 2) {
        std::cout << "usage: main <ptr/ref>" << std::endl;
    } 

    srand((unsigned)time(NULL));
    const int vec_size = 10;
    const int num_runs = 10 * 1000 * 1000;

    // Create a random vector. 
    std::vector<int> my_vec;
    my_vec.reserve(vec_size);
    for (int ii = 0; ii < vec_size; ++ii) {
        const int b = rand() % 20 + 1;
        my_vec.emplace_back(b);
    }
    auto ptr = std::make_shared<const std::vector<int>>(my_vec);


    // Decide which version to run.
    if (strcmp(argv[1], "ptr") == 0) {
        std::cout << "running " << argv[1] << std::endl;
        for(int ii = 0; ii < num_runs; ++ii) {
            DoSomethingPtr(ptr);
        }
    } else if(strcmp(argv[1], "ref") == 0) {
        std::cout << "running " << argv[1] << std::endl;
        for(int ii = 0; ii < num_runs; ++ii) {
            DoSomethingReference(ptr);
        }
    }


    return 0;
}
