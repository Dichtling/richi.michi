#include <iostream>

struct ListNode{
  char key;
  ListNode* next;
  ListNode (): key('0'), next(0) {};
};

class List {
public:
  List (char c) {
    head = new ListNode;
    head->key = c;
    tail = head;
  }
  List (): head(0), tail(0) {};
  void push (char _key);
  bool pop_front ();
  bool pop_mid (char del);
  bool pop_back ();
  bool pop (char del);
  friend std::ostream& operator<< (std::ostream& out, const List r);
private:
  ListNode* head;
  ListNode* tail;
};

void List::push (char _key) {
  ListNode* newTail = new ListNode;
  newTail->key = _key;
  tail->next = newTail;
  tail = newTail;
}

bool List::pop_front () {
  ListNode* temp = head;
  head = head->next;
  delete temp;
  return true;
}

bool List::pop_mid (char del) {
  ListNode* current = head;
  while(current->next != 0) {
    if(current->next->key == del) {
      ListNode* temp = current->next;
      current->next = current->next->next;
      delete temp;
      return true;
    }
    else {
      current = current->next;
    }
  }
  std::cout << "Element '" << del << "' not found" << std::endl;
  return false;
}

bool List::pop_back () {
  ListNode* current = head;
  while (current->next != tail) current = current -> next;
  tail = current;
  delete tail->next;
  tail->next = 0;
  return true;
}

bool List::pop (char del) {
  if(del == head->key) return pop_front();
  if(del == tail->key) return pop_back();
  return pop_mid(del); 
}

std::ostream& operator<< (std::ostream& out, const List r) {
  ListNode* current = r.head;
  while(current != 0) {
    out << current->key << " ";
    current = current->next;
  }
  return out;
}

int main () {
  List michilist('M');
  char c;
  while(std::cin >> c) {
    if(c == '~') break;
    if(c == 'p') {
      std::string c;
      std::cin >> c;
      for (int i = 0; i < c.size(); i++) {
        michilist.push(c[i]);
      }
    }
    if (c == 'd') {
      std::string c;
      std::cin >> c;
      for (int i = 0; i < c.size(); i++) {
        michilist.pop(c[i]);
      }
    }
    std::cout << michilist << std::endl;
  }
}