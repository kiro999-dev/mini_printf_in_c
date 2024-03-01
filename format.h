#ifndef FORMAT
#define FORMAT
#include "ft_printf_help.h"
int formats_cheak(char c)
{
  
int i=0;
char formats[10]="idcsoxXup";
while (formats[i])
{
  if (c==formats[i])
  {
    return 1;
  }
  i++;
}
return 0;

  
}
int cheak_str(char *str)
{
  int i=0;
  while (str[i])
  {
     if (str[i]=='%' && !(formats_cheak(str[i+1])))
     {
       return -1;
     }
     i++;
  }
  return 1;
}
int formats(char c)
{
    char *arry_formats=malloc(sizeof(char)*10);
    arry_formats="dixXoucsp";
    int i=0;
    while (arry_formats[i])
    {
        if (c==arry_formats[i])
        {
          
            return i;
        }
        i++;
    }
  
    return -1;

}
int letter_formtas(char c)
{
  if (c=='d'|| c=='X'|| c=='x'|| c=='o'|| c=='p'|| c=='u' || c=='i')
  {
    return 1;
  }
  else return -1;
}

int  d_format(char *str,...) 
{
    va_list args;
    int i=0;
    va_start(args,str);

       int x=va_arg(args,int);
       i=ft_putnbr(x);

     va_end(args); 
return i;
}

int  i_format(char *str,...) 
{
      va_list args;
      int i=0;
    va_start(args,str);
    int x=va_arg(args,int);

    i=ft_putnbr(x);

     va_end(args); 
  return i;
}


int  c_format(char *str,...) 
{
      va_list args;
      
    va_start(args,str);
       char x=va_arg(args,int);
      ft_putchar(x);
     va_end(args); 
  return 1;
}


int  s_format(char *str,...) 
{
      va_list args;
      int i=0;
    va_start(args,str);
    char *x=va_arg(args,char*);
    if (!x)
    {
       i=ft_putstr("(null)");
      return i;
    }
    
      i=ft_putstr(x);
     va_end(args); 
  return i;
}

int  p_format(char *str,...) 
{
      va_list args;
    va_start(args,str);
    int   i=0;
     int *addrs=va_arg(args,int*);
    long long int adrs=(long long int) addrs;
    if (!addrs)
    {
      i+=ft_putstr("(nil)");
      return i;
      
    }
     i+=     ft_putstr("0x"); 
           i+=     ft_print_add(adrs,0);
           
    va_end(args); 
    return i;
}

int  o_format(char *str,...) 
{
      va_list args;
    va_start(args,str);
    int i ;
   unsigned int o=va_arg(args,unsigned int);
     if (o==0)
     {
        i=ft_putchar('0');
        return i;
     }
     i=ft_print_octal(o,0);
     va_end(args); 
return i;
}

int  u_format(char *str,...) 
{
      va_list args;
      int i=0;
    va_start(args,str);
        unsigned int u=va_arg(args,unsigned int);
        if (u==0)
        {
          i=ft_putchar('0');
          return i;
        }
        
                 i=ft_print_u(u,0);
     va_end(args); 
return i;
}

int  x_format(char *str,...) 
{
  int i=0;
      va_list args;
    va_start(args,str);
           unsigned int h=va_arg(args,unsigned int);
        if (h==0)
        {
          i=ft_putchar('0');
          return i;
        }
        i=ft_print_hex(h,1,0);
     va_end(args); 
return i;
}
int  X_format(char *str,...) 
{
       va_list args;
        int i=0;
        va_start(args,str);
        unsigned int h=va_arg(args,unsigned int);
        i= ft_print_hex(h,0,0);
        if (h==0)
        {
          i=ft_putchar('0');
          return i;
        }
     va_end(args); 
  return i;
}


#endif