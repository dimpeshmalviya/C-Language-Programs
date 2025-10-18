#include <stdio.h>
#include <stdbool.h> // Include for using the bool type (true/false)

/**
 * @brief Checks if a given number is a Buzz number.
 * A Buzz number is a number that is either divisible by 7 or ends in the digit 7.
 *
 * @param num The integer to check.
 * @return true if the number is a Buzz number, false otherwise.
 */
bool isBuzzNumber(int num)
{
  // A number is a Buzz number if either of these conditions is true.
  if (num % 7 == 0 || num % 10 == 7)
  {
    return true;
  }
  return false;
}

int main()
{
  int number;

  // Prompt the user to enter a number
  printf("Enter a number to check if it's a Buzz number: ");

  // Read the integer from the user
  scanf("%d", &number);

  // Call the isBuzzNumber function and check the result
  if (isBuzzNumber(number))
  {
    printf("%d is a Buzz number.\n", number);
  }
  else
  {
    printf("%d is not a Buzz number.\n", number);
  }

  return 0;
}