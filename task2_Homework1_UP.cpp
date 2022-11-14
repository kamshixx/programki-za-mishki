#include <iostream>
#include <assert.h>

bool
isPrime (int n)
{
  if (n == 0 || n == 1)
    return false;
  for (int i = 2; i <= n / 2; i++)
    {
      if (n % i == 0)
	{
	  return false;
	}
    }
  return true;
}

void
fillPrimes (int length, int arr[], bool primes[])
{
  for (int i = 0; i < length; i++)
    {
      if (isPrime (arr[i]))
	{
	  primes[i] = true;
	}
      else
	primes[i] = false;
    }
}

bool
isProblem (int i, int j, int arr[], bool primes[])
{
  if (!primes[i] && !primes[j])
    return false;
  else if (primes[i] && !primes[j])
    return true;
  else if (primes[i] && primes[j])
    {
      return arr[i] > arr[j];
    }
  else
    return false;
}

int
CountProblems (int length, int arr[], bool primes[])
{
  int count = 0;

  for (int i = 0; i < length - 1; i++)
    {
      for (int j = i+1; j < length; j++)
	{
	  if (isProblem (i, j, arr, primes))
	    count++;
	}
    }
  return count;
}

int
main ()
{
  int const MAXSIZE = 1024;
  int arr[MAXSIZE];
  int length;
  std::cin >> length;
  assert (length > 0 && length <= MAXSIZE);

  for (int i = 0; i < length; i++)
    {
      std::cin >> arr[i];
    }

  bool primes[MAXSIZE];
  fillPrimes (length, arr, primes);
  std::cout << CountProblems (length, arr, primes);
  return 0;

}
