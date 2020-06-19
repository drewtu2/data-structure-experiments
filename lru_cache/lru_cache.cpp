#include "lru_cache.hpp"

template <class KEY_T, class VAL_T> 
LRUCache<KEY_T, VAL_T>::LRUCache(const int cache_size) :
    cache_size_(cache_size) {
    };

template <class KEY_T, class VAL_T> 
void LRUCache<KEY_T, VAL_T>::put(const KEY_T& key, const VAL_T& val){
  auto it = item_map.find(key);
  if(it != item_map.end()){
    // If the item exists, remove it. 
    item_list.erase(it->second);
    item_map.erase(it);
  }

  // The list is responsible for storing the items in an ordered fashion
  // to make it easy to drop off the last used item (cacheing). 
  item_list.push_front(make_pair(key, val));

  // The map is used to give O(1) lookup to the item that was inserted via key. 
  item_map.insert(make_pair(key, item_list.begin()));

  // Eject nodes from the end of the list until our size is the appropriate
  // cache size.
  clean();
};

template <class KEY_T, class VAL_T> 
bool LRUCache<KEY_T, VAL_T>::exist(const KEY_T& key)
{
  return (item_map.count(key)>0);
};

template <class KEY_T, class VAL_T> 
VAL_T LRUCache<KEY_T, VAL_T>::get(const KEY_T& key){
  assert(exist(key));
  auto it = item_map.find(key); // iterator to the list
  // reorder list.
  item_list.splice(item_list.begin(), item_list, it->second);
  return it->second->second;
};

template <class KEY_T, class VAL_T> 
void LRUCache<KEY_T, VAL_T>::clean(){
  while(item_map.size()>cache_size_){
    auto last_it = item_list.end(); last_it--;
    item_map.erase(last_it->first);
    item_list.pop_back();
  }
};

template class LRUCache<int, int>;// OK: explicit instantiation
