#include <iostream>
#include "lru_cache.hpp"

int main(){
  std::cout << "ran demo!" << std::endl;

  LRUCache<int, int> cache{2};
  cache.put(1, 1);
  cache.put(2, 2);

  std::cout << "1 exists: " << cache.exist(1) << std::endl;
  cache.put(3, 3);
  std::cout << "1 exists: " << cache.exist(1) << std::endl;
  return 0;
}
