/*Dados três vetores ordenados, implemente
uma função que intercala e retorne o vetor
resultante ordenado. Implemente uma função
merge3_sort, que faça ordenação em um vetor
utilizando a sua função de intercalação
(sugestão: se baseie no algoritmo do merge-sort
original). Qual a complexidade desse algoritmo?*/

#include <stdio.h>

// function to merge the 3 parts of the array using 3 way merging

void merge(int arr[], int menor, int m1, int m2, int maior, int final[]) {
  int i = menor, j = m1, k = m2, l = menor;

  while ((i < m1) && (j < m2) && (k < maior)) {
    if (arr[i] < arr[j])

    {

      if (arr[i] < arr[k])

        final[l++] = arr[i++];

      else

        final[l++] = arr[k++];
    }

    else

    {

      if (arr[j] < arr[k])

        final[l++] = arr[j++];

      else

        final[l++] = arr[k++];
    }
  }

  while ((i < m1) && (j < m2)) {
    if (arr[i] < arr[j])
      final[l++] = arr[i++];
    else
      final[l++] = arr[j++];
  }

  while ((j < m2) && (k < maior)) {
    if (arr[j] < arr[k])
      final[l++] = arr[j++];
    else
      final[l++] = arr[k++];
  }

  while ((i < m1) && (k < maior)) {
    if (arr[i] < arr[k])
      final[l++] = arr[i++];
    else
      final[l++] = arr[k++];
  }

  while (i < m1)
    final[l++] = arr[i++];

  while (j < m2)
    final[l++] = arr[j++];

  while (k < maior)
    final[l++] = arr[k++];
}

void sort_recursive(int arr[], int menor, int maior, int final[]) {
  int m1, m2;

  if (maior - menor < 2)
    return;

  // dividindo array em 3 partes

  // A primeira parte vai de menor até m1, a segunda de m1 até m2

  // a terceira de m2 até maior
  m1 = menor + ((maior - menor) / 3);
  m2 = menor + 2 * ((maior - menor) / 3) + 1;

  // calling the recursive function for 3 parts separately
  sort_recursive(final, menor, m1, arr);
  sort_recursive(final, m1, m2, arr);
  sort_recursive(final, m2, maior, arr);

  // merge das partes
  merge(final, menor, m1, m2, maior, arr);
}

void sort(int arr[], int n) {
  int i, duplica[n];

  // Se n existe elemento no array, retorna null
  if (n == 0)
    return;
  // copiando os elementos do array pra duplica
  for (i = 0; i < n; i++)
    duplica[i] = arr[i];

  sort_recursive(duplica, 0, n, arr);

  // copiando os elemtnos de duplica pra a array original
  for (i = 0; i < n; i++)
    arr[i] = duplica[i];
}

int main() {
  int arr[20], n, i;
  printf("Insira a quantidade de elementos do array: ");
  scanf("%d", &n);

  printf("Insira os elementos do array: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("\nArray desordenado: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  sort(arr, n);

  printf("\nArray Ordenado: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}