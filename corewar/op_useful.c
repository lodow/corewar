/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

/*
** Output the value at an adress or in a reg
** \param[in] value the value get from the instruction param (freed)
** \param[in] type param type
** \param[in] proc the current process
** \param[in] mod use IDX_MOD or not
** \return value value of the param (Must be free)
*/
char	*get_none_direct_value(char *value, char type, t_process *proc, int mod)
{
  char	*out;

  out = value;
  if (value != NULL)
    {
      if (type == T_REG)
        {

        }
    }
}
