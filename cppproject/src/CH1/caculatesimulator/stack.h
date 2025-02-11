#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack
{
private:
  std::vector<T> elements; // 使用 std::vector 存储堆栈元素

public:
  // 检查堆栈是否为空
  bool isEmpty() const
  {
    return elements.empty();
  }

  // 将元素压入堆栈
  void push(const T &value)
  {
    elements.push_back(value);
  }

  // 弹出堆栈顶部元素
  T pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack underflow: cannot pop from an empty stack.");
    }
    T topElement = elements.back();
    elements.pop_back();
    return topElement;
  }

  // 查看堆栈顶部元素
  T peek() const
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack underflow: cannot peek on an empty stack.");
    }
    return elements.back();
  }

  // 清空堆栈
  void clear()
  {
    elements.clear();
  }
};

#endif
