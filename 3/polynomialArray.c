#include <stdio.h>

#define MaxDegree 255

typedef struct {
  int CoeffArray[MaxDegree + 1];
  int HighPower;
} *Polynomial;

int Max(int a, int b) {
  return a > b ? a : b;
}

void ZeroPolynomial(Polynomial Poly) {
  for (int i = 0; i <= MaxDegree; i++) {
    Poly->CoeffArray[i] = 0;
  }
  Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, 
              const Polynomial Poly2, Polynomial PolySum) 
{
  ZeroPolynomial(PolySum);
  PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
  for (int i = PolySum->HightPower; i >= 0; i--)
    PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1,
              const Polynomial Poly2, Polynomial PolyProd)
{
  ZeroPolynomial(PolyProd);
  PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

  if (PolyProd->HighPower > MaxDegree)
    printf("error\n");
  else {
    for (int i = 0; i <= Poly1->HighPower; i++) {
      for (int j = 0; j <= Poly2->HighPower; j++) {
        PolyProd->CoeffArray[i + j] +=
                Poly1->CoeffArray[i] * 
                Poly2->CoeffArray[j];
      }
    }
  }
}              
