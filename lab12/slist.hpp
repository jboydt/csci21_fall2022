// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;

template <typename T>
class SList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList() {

  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  ~SList() {
  }

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void pushFront(T value) {

  }

  // Remove the head node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  void popFront() noexcept(false) {

  }

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  T front() noexcept(false) {

  }

  // Return the number of nodes in this list.
  unsigned int getSize() const {

  }

  // Check to see if this list is empty.
  bool empty() const {

  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {

  }

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string toString() const {

  }

private:
  unsigned int size; // the number of nodes in this list

  // A singly-linked list node with a pointer to next and a value field.
  // Implements a constructor to initialize the value field to the parameter value
  // and the pointer to nullptr.
  struct Node {

  } * head; // a pointer to the first node in the list
};
