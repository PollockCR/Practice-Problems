/* 8.1 MERGE TWO SORTED LISTS
Write a program that takes two lists, assumed to be sorted, and returns their merge.
The only field your program can change in a node is its next field.
*/

#include "list_node.h"
#include "test_framework/generic_test.h"

void AppendNode(shared_ptr<ListNode<int>> * node, shared_ptr<ListNode<int>> * tail){
  (*tail)->next = *node;
  *tail = (*tail)->next;
  *node = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  shared_ptr<ListNode<int>> head(new ListNode<int>);
  auto tail = head;
  while(L1 && L2){
    AppendNode(L1->data < L2->data ? &L1 : &L2, &tail);
  }
  tail->next = L1 ? L1 : L2;
  return head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}