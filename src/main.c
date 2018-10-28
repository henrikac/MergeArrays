/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Write a function that will merge the contents of two sorted arrays (ascending order)
 * The arrays should be of type double
 *
 * The funtion should not assume that both arrays are the same length
 * The function can assume that one array does not contain two copies of the same value
 *
 * The result array should also contain no dublicate values.
*/

#include <stdio.h>
#include <stdlib.h>

size_t get_num_uniques(const double a1[], const double a2[], size_t a1_size, size_t a2_size);
void merge(const double a1[], const double a2[], size_t a1_size, size_t a2_size, double *merged, size_t m_size);
int cmp_dbl(const double d1, const double d2);

int main(void)
{
  int i;
  double arr1[7] = { 1.3, 2.1, 4.2, 7.0, 9.0, 53.23, 99.9 };
  double arr2[5] = { 2.1, 5.3, 7.0, 12.0, 32.35 };
  double *merged_arr;

  size_t arr1_size = sizeof(arr1) / sizeof(double);
  size_t arr2_size = sizeof(arr2) / sizeof(double);
  size_t merged_size = get_num_uniques(arr1, arr2, arr1_size, arr2_size);
  
  merged_arr = (double*)malloc(merged_size * sizeof(double));
  if (merged_arr == NULL)
  {
    printf("\nCouldn't allocate memory");
    exit(EXIT_FAILURE);
  }

  merge(arr1, arr2, arr1_size, arr2_size, merged_arr, merged_size);

  printf("\n");
  for (i = 0; i < merged_size; i++)
    printf(" %f", merged_arr[i]);

  free(merged_arr);

  return EXIT_SUCCESS;
}

size_t get_num_uniques(const double a1[], const double a2[], size_t a1_size, size_t a2_size)
{
  int cmp;
  int i = 0, j = 0;
  size_t uniques = 0;

  while (i < a1_size || j < a2_size)
  {
    if (i < a1_size && j < a2_size)
    {
      cmp = cmp_dbl(a1[i], a2[j]);

      if (cmp == 1)
        j++;
      else if (cmp == 0)
      {
        i++;
        j++;
      }
      else if (cmp == -1)
        i++;

      uniques++;
    }
    else
    {
      if (i < a1_size)
        i++;
      else if (j < a2_size)
        j++;

      uniques++;
    }
  }

  return uniques;
}

void merge(const double a1[], const double a2[], size_t a1_size, size_t a2_size, double *merged, size_t m_size)
{
  int cmp;
  int i;
  int r = 0, s = 0, t = 0;

  for (i = 0; i < m_size; i++)
  {
    if (r < a1_size && s < a2_size)
    {
      cmp = cmp_dbl(a1[r], a2[s]);

      if (cmp == 1)
        merged[t++] = a2[s++];
      else if (cmp == 0)
      {
        merged[t++] = a1[r];
        r++;
        s++;
      }
      else if (cmp == -1)
        merged[t++] = a1[r++];
    }
    else
    {
      if (r < a1_size)
        merged[t++] = a1[r++];
      else if (s < a2_size)
        merged[t++] = a2[s++];
    }
  }
}

int cmp_dbl(const double d1, const double d2)
{
  if (d1 < d2)
    return -1;
  else if (d1 > d2)
    return 1;
  else
    return 0;
}
