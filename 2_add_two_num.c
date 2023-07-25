#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);
struct ListNode *addList(struct ListNode *head, int val);
void printList(struct ListNode *head);
unsigned long long int makeAnum(struct ListNode *head);
struct ListNode *reverseList(struct ListNode *head);

int main() {
  int val_array_l1[10] = {1,9,9,9,9,9,9,9,9,9};
  struct ListNode *l1 = NULL;

  for (int i = 0; i < 3; i++) {
    l1 = addList(l1, val_array_l1[i]);
  }
  
  int val_array_l2[3] = {5, 6, 4};
  struct ListNode *l2 = NULL;

  for (int i = 0; i < 3; i++) {
    l2 = addList(l2, val_array_l2[i]);
  }
  addTwoNumbers(l1, l2);
  return 0;
}
void printList(struct ListNode *head) {
  while (head != NULL) {
    printf("%d, ", head->val);
    head = head->next;
  }
}

struct ListNode *addList(struct ListNode *head, int val) {
  if (head == NULL) {
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = val;
    head->next = NULL;
  } else {
    struct ListNode *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(struct ListNode));
    tmp->next->val = val;
    tmp->next->next = NULL;
  }
  return head;
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

unsigned long long int makeAnum(struct ListNode *head) {
  unsigned long long int res = 0;
  int dec = 1;
  struct ListNode *t = head;
  while (t->next != NULL) {
    dec *= 10;
    t = t->next;
  }
  if(dec == 1){
    return head->val;
  }
  struct ListNode *tt = reverseList(head);
  while (tt != NULL) {
    res += tt->val * dec;
    dec /= 10;
    struct ListNode *tmp = tt;
    tt = tt->next;
    free(tmp);
  }
  return res;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *result = NULL;
  unsigned long long int res = 0;
  res = makeAnum(l1) + makeAnum(l2);
    if (res == 0)
    {
      result= (struct ListNode *)malloc(sizeof(struct ListNode));
      result->val = res;
      result->next = NULL;
      return result;
    }

  while (res > 0) {
    int temp = res % 10;
    result = addList(result, temp);
    res = res / 10;
  }
  printList(result); 
  return result;
}