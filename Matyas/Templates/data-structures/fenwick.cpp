
#include <iostream>
#include <vector>

#define LEN 200001

int counts[LEN];
int realCounts[LEN];

// Return sum from 0...i from array
int getSum(int fw[], int i)
{
  if (i < 0) return 0;
   int sum = 0;
   // Fenwick's index start from 1
   i++;

   while(i > 0)
   {
      sum += fw[i];
      // i & (-i)  returns the decimal value of last set digit
      // eg: if i = 12 (1100) then  i & (-i) will 4 (100)
      i -= i & (-i);
   }
   return sum;
}

// newVal will be updated to Fenwick and all its ancestor
void updateFW(int fw[], int n, int i, int newVal)
{
   // Fenwick's index start from 1
   i++;
   while (i <= n)
   {
      fw[i] += newVal;
      i += i & (-i);
   }
}

// Build Fenwick's tree
int *constructFenwick(int a[], int n)
{
  int *fw = new int [n+1];
  for (int i = 0; i <= n; i++)
    fw[i] = 0;

  for (int i=0; i<n; i++)
   updateFW(fw, n, i, a[i]);

  return fw;
}

using namespace std;
int main() {
  int k, n, q;
  scanf("%d %d %d", &n, &k, &q);

  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    counts[l] ++;
    counts[r + 1] --;
  }
  int d = 0;
  for (int i = 0; i < LEN; ++ i) {
    d += counts[i];
    if (d >= k)
      realCounts[i] = 1;
  }

  int* fen = constructFenwick(realCounts, LEN);

  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", getSum(fen, b) - getSum(fen, a - 1));
  }
  return 0;
}
