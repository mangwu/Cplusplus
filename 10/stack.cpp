#include "stack.h"

Stack::Stack() {
  top = 0;
}

bool Stack::isempty() const {
  return top == 0;
}

bool Stack::isfull() const {
  return top == MAX;
}

bool Stack::push(const Item &item) {
  if (isfull()) {
    return false;
  }
  items[top++] = item; // 副本copy
  return true;
}

bool Stack::pop(Item &item) {
  if (isempty()) {
    return false;
  }
  item = items[--top];
  return true;
}