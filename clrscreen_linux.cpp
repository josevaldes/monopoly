#include "clrscreen_linux.h"

#include <unistd.h>
#include <term.h>
void clrscreen()
{
   if(!cur_term)
   {
      int result;
      setupterm(NULL, STDOUT_FILENO, &result);
      if(result <= 0) return;
   }

   putp( tigetstr( "clear" ));
}
