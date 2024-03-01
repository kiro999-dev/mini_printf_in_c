
#include "format.h"
int ft_printf(char *string, ...)
{
    va_list args;
   int cheak =cheak_str(string);
   if (!cheak)  return 0;
   
    
    int (*ptr_to_fun[9])(char*,...);
    ptr_to_fun[0]=d_format;
    ptr_to_fun[1]=i_format;
    ptr_to_fun[2]=x_format;
    ptr_to_fun[3]=X_format;
    ptr_to_fun[4]=o_format;
    ptr_to_fun[5]=u_format;
    ptr_to_fun[6]=c_format;
    ptr_to_fun[7]=s_format;
    ptr_to_fun[8]=p_format;


    va_start(args,string);
    int i=0,x,count=0;
    void *c;
    
    while (args!=NULL&&string[i])
    {
       
        if (string[i]=='%')
        {
            if (string[i+1]=='%')
            {
                ft_putchar('%');
                i++;
				count++;
            }
            else
            {
                x=formats(string[i+1]);
                if (x!=-1)
                {
                   c=va_arg(args,void*);
                  count+= ptr_to_fun[x](string,c);
                   i++;
                }
                
            }
            
            
            
           
        }
        else 
		{
			ft_putchar(string[i]);
			count++;

		}
        i++;
		
    }
    va_end(args);

return count;
}
