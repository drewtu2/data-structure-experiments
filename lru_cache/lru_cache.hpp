#pragma once

#include <list>
#include <unordered_map>
#include <assert.h>

using namespace std;
/**
 * Notes: In order to be thread-safe, you need put lock whenever you modify the
 * state of the LRU.
 *
 *
 * Referenced from: https://stackoverflow.com/a/14503492/5977282
 */
template <class KEY_T, class VAL_T> 
class LRUCache {
 public:
  LRUCache(const int cache_size);

  void put(const KEY_T& key, const VAL_T& val);

  bool exist(const KEY_T& key);

  VAL_T get(const KEY_T& key);

 private:
  void clean();
 
 private:
  list< pair<KEY_T,VAL_T> > item_list;
  unordered_map<KEY_T, decltype(item_list.begin()) > item_map;
  size_t cache_size_;
};
