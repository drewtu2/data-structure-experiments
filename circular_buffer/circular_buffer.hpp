#pragma once
#include <cstddef>
#include <mutex>

/**
 *   tail           head 
 *    |               |
 *   ------------------------
 *  |   |   |   |   |   |   |
 *   ------------------------
 *
 *  Buffer is a fixed size.
 *  Increment head when we add to the buffer. 
 *  Increment tail when we pull from the buffer.
 *
 *  If head and tail are the same after the setup, the buffer is full.
 *
 * Taken from. 
 * https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/
 */
template <class T>
class CircularBuffer {
public:
  CircularBuffer(const size_t size);

  void put(const T item);
  T get();
  void reset();
  bool empty() const;
  bool full() const;
  size_t capacity() const;
  size_t size() const;

private:
  std::mutex mutex_;
  std::unique_ptr<T[]> buf_;
  size_t head_ = 0;
  size_t tail_ = 0;
  const size_t max_size_;
  bool full_ = 0;
};

