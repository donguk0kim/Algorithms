#include "ring_buffer.hpp"

/* constructor & destructor */
RingBuffer::RingBuffer() {
  start_ = 0;
  count_ = 0;
  capacity_ = 5;
  store_ = new int[capacity_];
  fill();
}

RingBuffer::~RingBuffer() {
  delete[] store_;
}

/* accessors */
// O(1)
int& RingBuffer::operator[] (int index) {
  int internal = intern(index);
  checkIndex(internal);
  return store_[internal];
}

/* basic operations */
// O(1) ammortized
void RingBuffer::push(int value) {
  if (count_ == capacity_) resize();
  (*this)[count_] = value;
  count_++;
}

// O(1) ammortized
void RingBuffer::unshift(int value) {
  if (count_ == capacity_) resize();
  (*this)[capacity_ - 1] = value;
  start_--;
  count_++;
}

// O(1)
int RingBuffer::pop() {
  int value = (*this)[count_ - 1];
  (*this)[count_ - 1] = NULL;
  count_--;
  return value;
}

// O(1)
int RingBuffer::shift() {
  int value = (*this)[0];
  (*this)[0] = NULL;
  start_++;
  count_--;
  return value;
}

/* debugger */
void RingBuffer::print() const {
  std::cout << "{ ";
  for (int index = 0; index < capacity_; index++) {
    std::cout << store_[index];
    if (index < capacity_ - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* private */
int RingBuffer::intern(int index) const {
  return wrap(index + start_) % capacity_;
}

int RingBuffer::wrap(int index) const {
  while (index < 0) {
    index += capacity_;
  }
  return index;
}

void RingBuffer::checkIndex(int index) const {
  if (isInvalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool RingBuffer::isInvalid(int index) const {
  return index > capacity_;
}

void RingBuffer::fill() {
  for (int index = 0; index < capacity_; index++) {
    store_[index] = NULL;
  }
}

void RingBuffer::resize() {
  int new_capacity = capacity_ * 2;
  int* new_store = new int[new_capacity];

  for (int index = 0; index < new_capacity; index++) {
    if (index < capacity_) {
      new_store[index] = (*this)[index];
    } else {
      new_store[index] = NULL;
    }
  }

  start_ = 0;
  delete[] store_;
  store_ = new_store;
  capacity_ = new_capacity;
}
