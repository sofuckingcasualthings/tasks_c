#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *reverseList(struct ListNode *head);
struct ListNode *addlist(int val, struct ListNode *head);
void printList(struct ListNode *head);
void destroy(struct ListNode *head);

int main() {

  int val_array[5] = {1, 2, 3, 4, 5};
  struct ListNode *head = 0;

  for (int i = 0; i < 5; i++) {
    head = addlist(val_array[i], head);
  }

  printList(head);

  struct ListNode *reversed = NULL;
  reversed = reverseList(head);
  printList(reversed);
  destroy(head);
  return 0;
}

struct ListNode *addlist(int data, struct ListNode *head) {
  if (head == 0) {
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = data;
    head->next = NULL;
  } else {
    struct ListNode *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(struct ListNode));
    tmp->next->val = data;
    tmp->next->next = NULL;
  }

  return head;
}

void printList(struct ListNode *head) {
  while (head != NULL) {
    printf("%d, ", head->val);
    head = head->next;
  }
}

void destroy(struct ListNode *head) {
  while (head != NULL) {
    struct ListNode *tmp = head->next;
    free(head);
    head = tmp;
  }
}

struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *new = NULL;
  struct ListNode *curr = head;
  struct ListNode *tmp = NULL;

  while (curr != NULL) {
    tmp = curr->next;
    curr->next = new;
    new = curr;
    curr = tmp;
  }

  return new;
}
