#include "RingBuffer.hpp"

/* constructor & destructor */
RingBuffer::RingBuffer() {
  start = 0;
  count = 0;
  capacity = 5;
  store = new int[capacity];
  fill();
}

RingBuffer::~RingBuffer() {
  delete[] store;
}

/* accessors */
// O(1)
int& RingBuffer::operator[] (int index) {
  int internal = intern(index);
  checkIndex(internal);
  return store[internal];
}

/* basic operations */
// O(1) ammortized
void RingBuffer::push(int value) {
  if (count == capacity) resize();
  (*this)[count] = value;
  count++;
}

// O(1) ammortized
void RingBuffer::unshift(int value) {
  if (count == capacity) resize();
  (*this)[capacity - 1] = value;
  start--;
  count++;
}

// O(1)
int RingBuffer::pop() {
  int value = (*this)[count - 1];
  (*this)[count - 1] = NULL;
  count--;
  return value;
}

// O(1)
int RingBuffer::shift() {
  int value = (*this)[0];
  (*this)[0] = NULL;
  start++;
  count--;
  return value;
}

/* debugger */
void RingBuffer::print() const {
  std::cout << "{ ";
  for (int index = 0; index < capacity; index++) {
    std::cout << store[index];
    if (index < capacity - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* private */
int RingBuffer::intern(int index) const {
  return wrap(index + start) % capacity;
}

int RingBuffer::wrap(int index) const {
  while (index < 0) {
    index += capacity;
  }
  return index;
}
  
void RingBuffer::checkIndex(int index) const {
  if (isInvalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool RingBuffer::isInvalid(int index) const {
  return index > capacity;
}

void RingBuffer::fill() {
  for (int index = 0; index < capacity; index++) {
    store[index] = NULL;
  }
}

void RingBuffer::resize() {
  int new_capacity = capacity * 2;
  int* new_store = new int[new_capacity];
  
  for (int index = 0; index < new_capacity; index++) {
    if (index < capacity) {
      new_store[index] = (*this)[index];
    } else {
      new_store[index] = NULL;
    }
  }
  
  start = 0;
  delete[] store;
  store = new_store;
  capacity = new_capacity;
}
