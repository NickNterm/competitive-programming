
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

void insertAtEnd(Node *&head, int data) {
  Node *newNode = new Node(data);

  if (head == nullptr) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

int removeItemWithValueX(Node *&head, int x) {
  Node *temp = head;
  int dist = 0;
  while (temp != nullptr) {
    if (temp->data == x) {
      if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
      } else {
        head = temp->next;
      }
      if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
      }
      delete temp;
      return dist;
    }
    temp = temp->next;
    dist++;
  }
  return -1;
}
void printListForward(Node *head) {
  Node *temp = head;
  cout << "Forward List: ";
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  int permutations = 0;
  int N = 0;
  vector<int> PermA;
  Node *PermB = nullptr;
  // vector<int> PermB;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int tmp;
    scanf("%d", &tmp);
    PermA.push_back(tmp);
  }
  // printf("insert\n");
  for (int i = 0; i < N; i++) {
    int tmp;
    scanf("%d", &tmp);
    insertAtEnd(PermB, tmp);
  }

  // printListForward(PermB);

  for (int i = 0; i < N; i++) {
    // printf("Pointer: %d element %d\n", *pointer, PermA[i]);

    // printf("-------------- %d\n", permutations);
    // for (auto a : PermB) {
    //   printf("%d ", a);
    // }
    // printf("\n");
    // for (int a = i; a < N; a++) {
    //   printf("%d ", PermA[a]);
    // }
    // printf("\n");
    // printf("--------------\n");
    if (PermB->data != PermA[i]) {
      // printf("ERR\n");
      int v = PermB->data;
      permutations += removeItemWithValueX(PermB, PermA[i]);
    } else {
      PermB = PermB->next;
    }
    // printListForward(PermB);
  }
  printf("%d\n", permutations);
}
