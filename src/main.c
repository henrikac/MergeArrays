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

int cmp_dbl(double d1, double d2);

int main(void)
{
  int i;
  double arr1[7] = { 1.3, 2.1, 4.2, 7.0, 9.0, 53.23, 99.9 };
  double arr2[5] = { 2.1, 5.3, 7.0, 12.0, 32.35 };

  size_t arr1_size = sizeof(arr1) / sizeof(double);
  size_t arr2_size = sizeof(arr2) / sizeof(double);
  size_t num_uniques = 1;

  double *temp_arr = (double*)malloc((arr1_size + arr2_size) * sizeof(double));
  double *merged_arr;
  size_t merged_counter = 0;

  /* add items from arr1 to temp_arr */
  for (i = 0; i < arr1_size; i++)
  {
    temp_arr[i] = arr1[i];
  }
  
  /* add items from arr2 to temp_arr */
  for (i = 0; i < arr2_size; i++)
  {
    temp_arr[arr1_size + i] = arr2[i];
  }

  /* sort temp_arr */
  for (i = 1; i < (arr1_size + arr2_size); i++)
  {
    if (temp_arr[i] < temp_arr[i - 1])
    {
      /* swap items */
      double tmp = temp_arr[i];
      temp_arr[i] = temp_arr[i - 1];
      temp_arr[i - 1] = tmp;
      i = 1;
    }
  }

  /* get number of unique items */
  for (i = 1; i < (arr1_size + arr2_size); i++)
  {
    if (temp_arr[i] == temp_arr[i - 1])
      continue;
    num_uniques++;
  }

  merged_arr = (double*)malloc(num_uniques * sizeof(double));

  /* add items to merged arr */
  for (i = 0; i < (arr1_size + arr2_size); i++)
  {
    if (i > 0 && temp_arr[i] == temp_arr[i - 1])
      continue;
    merged_arr[merged_counter++] = temp_arr[i];
  }

  free(temp_arr);

  printf("\nMerged: ");
  for (i = 0; i < num_uniques; i++)
    printf(" %f", merged_arr[i]);

  free(merged_arr);

  return EXIT_SUCCESS;
}



int cmp_dbl(double d1, double d2)
{
  if (d1 < d2)
    return -1;
  else if (d1 > d2)
    return 1;
  else
    return 0;
}

