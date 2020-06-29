#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
  ElementType Element;
  Position    Next;
};

void init(List L, int a[], int n)
{
  Position p = Header(L);
  for (int i = 0; i < n; i++) {
    Insert(a[i], L, p);
    p = p->Next;
  }
}

int main()
{
  List L;
  L = MakeEmpty(L);
  int a[] = {1, 2, 3, 4, 5, 6};
  init(L, a, 6);
  
  Position p = First(L);
  while (p != NULL) {
    printf("%d\n", p->Element);
    p = p->Next;
  }
  DeleteList(L);

  return 0;  
}
