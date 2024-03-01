#ifndef FT_PRINTF
#define FT_PRINTF
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
   int i=0;
   while (str[i])
   {
      i++;
   }
 return i;  
}
int  ft_putchar(char c)
{
   write(1,&c,1);
   return 1;
}
 int  ft_putstr(char const *s)
{
   int i=0;
  
   
   while (s[i])
   {
      ft_putchar(s[i]);
      i++;
   }
   return i;
}
int ft_print_add(long long int addrs,int i)
{

long long unsigned int adrs=(long long unsigned int ) addrs;


if (adrs==0)
{
   return i;
}


int count= ft_print_add(adrs/16,i+1);
ft_putchar("0123456789abcdef"[adrs%16]);
return count;
}
int  ft_print_octal(unsigned int x,int i)
{
   if (x==0)
{
   return i;
}
int count=ft_print_octal(x/8,i+1);
ft_putchar("01234567"[x%8]);
return count;
}

int ft_print_hex(unsigned int x,int cheak,int i)
{
if (x==0)
{
    
     return i;
}   


 int count=ft_print_hex(x/16,cheak,i+1);
if (cheak)
{
  ft_putchar("0123456789abcdef"[x%16]);
}
else   ft_putchar("0123456789ABCDEF"[x%16]);
return count;
}
int  ft_print_u(unsigned int u,int i)
{
  
   if (u<=0)
   {
     
      return i;
   }
  int count= ft_print_u(u/10,i+1);
   ft_putchar((u%10)+48);
   return count;
}

int nbr_len_count(int n,int *cheak_ptr)
{
   
   if (n<0)
   {
      *cheak_ptr=1;
      n=n*-1;
   }
   else *cheak_ptr=0;
   
   int i=0;
   while (n>0)
   {
      n=n/10;
      i++;
   }
   return i;
}

char * ft_itoa(int n)
{
   int cheak=0;
   int len_str=nbr_len_count(n,&cheak)+1;
   char *res;
   if (n==0)
   {
     res=malloc(2);
     res[0]='0';
     res[1]='\0';
     return res;
      
   }
   
   if (cheak)
   {
      res=(char*)malloc(sizeof(char)*len_str+1);
      res[0]='-';
      n=n*-1;
      res[len_str]='\0';
      int i=len_str-1;
      while (n>0)
      {
         res[i]=(n%10)+48;
         i--;
         n=n/10;
      }
      
   }
   else
   {
      res=(char*)malloc(sizeof(char)*len_str);
      res[len_str-1]='\0';
      int i=len_str-2;
      while (n>0)
      {
         res[i]=(n%10)+48;
         i--;
         n=n/10;
      }
      
   }
   return res;
 }

 int  ft_putnbr(int n)
{
   int i=0;
   if (n==-2147483648)
   {
     i=ft_putstr("-2147483648");
     return i;
   }
  
   
   
   char *res=ft_itoa(n);
   i=ft_putstr(res);
   return i;
}







#endif