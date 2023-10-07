#include <stdio.h>

int main(void)
{
  int n_dig = 0;
  int sig = 1;
  int value = 0;
  // may have a signal
  printf("Insert a number (optional sign + up to 9 digits): ");
  int ch = fgetc(stdin);
  if (ch == '-')
    sig = -1;
  else if (ch == '+')
    sig = 1;
  else if (ch < '0')
    return 0;
  else if (ch > '9')
    return 0;
  else
    n_dig = 1, value = ch - '0';
  // '\n' ends all
  while ((ch = fgetc(stdin)) != '\n')
  {
    if (ch < '0' || ch > '9') break;
    value = (10 * value) + (ch - '0');
    n_dig += 1;
    if (n_dig == 9) break;
  };
  if (n_dig == 0) return -1;
  printf("Decimal value is %d\n", sig * value);
  return 0;
}
