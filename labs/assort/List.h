#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <string>

// This is the linked list structure you need to implement.
// Do not edit this file.

struct Node {
  std::string data;
  Node*       next;
};


class List {
  Node* head;

public:
  List();
  List(const List& other);
  ~List();

  size_t             count() const;
  void               insert(const std::string& value);
  const std::string& lookup(size_t index) const;
  void               print(bool reverse) const;
  std::string        remove(size_t index);
  size_t             remove(const std::string& value);
};

#endif
