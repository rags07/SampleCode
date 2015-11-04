#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void revStr(char str[]);
char* itoa(int Value, int Base);

int main()
{
      int Value, Base;
      printf("\n Value:");
      scanf("%d", &Value);
      
      printf("\n Base:");
      scanf("%d", &Base);
      
      itoa(Value,Base);
      return(0);
}

void revStr(char str[])
{
  int i=0, j, length=0;
  char temp;
  while(str[length]!='\0')
  {
      length++;
  }
  j=length-1;
  
  while (i < j) 
  {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
 }
 printf("\nReverse string is :%s", str);
}

char* itoa(int Value, int Base) 
{
    int i=0;
    char str[100];
    bool isNegative = false;

    //handle 0 explicitly
    if(Value == 0)
    {
        str[i] = '0';
        str[i++] = '\0';
        return str;
    }
    
    //handle negative numbers with base 10
    if(Value < 0 && Base == 10)
    {
        isNegative = true;
        Value = -Value;
    }
    
    //Actual code for evaluating individual digits
    while(Value!=0)
    {
        int rem = Value%Base;
        str[i++] = (rem > 9) ? (rem-10) + 'A' : rem + '0';
        Value = Value/Base;
    }
    
    if(isNegative)
        str[i++] = '-';
    
    str[i] = '\0';
    
    //Reverse string been called.
    revStr(str);
}
