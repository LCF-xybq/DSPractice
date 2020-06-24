#include <stdlib.h>
#include "list.h"

struct Node {
  ElementType Element;
  Position    Next;
};

int
IsEmpty(List L) 
{
  return L->next == NULL;
}

int
IsLast(Position P, List L)
{
  return P->next == NULL;
}

Position
Find(ElementType X, List L)
{
  Position P;

  P = L->Next;
  while (P != NULL && P->Element != X) {
    P = P->Next;
  }
  return P;
}

void
Delete(ElementType X, List L)
{
  Position P, TmpCell;

  P = FindPrevious(X, L);

  if (!IsLast(P, L)) {
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
  }
}

Position
FindPrevious(ElementType X, List L)
{
  Position P;

  P = L;
  while (P->Next != NULL && P->Next->Element != X) {
    P = P->Next;
  }

  return P;
}

void 
Insert(ElementType X, List L, Position P) 
{
  Position TmpCell;

  TmpCell = malloc(sizeof(struct Node));
  if (TmpCell == NULL) {
    printf("error\n");
  }

  TmpCell->Element = X;
  TmpCell->Next = P->Next;
  P->Next = TmpCell;
}

