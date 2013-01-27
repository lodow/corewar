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

void	init_instr_params(t_params *params)
{
  params->param1 = NULL;
  params->param2 = NULL;
  params->param3 = NULL;
  params->param4 = NULL;
}

void	delete_instr_params(t_params *params)
{
  params->type = 0x00;
  free(params->param1);
  free(params->param2);
  free(params->param3);
  free(params->param4);
  init_instr_params(params);
}

void	fill_param_struct(t_vm *vm, t_process *proc)
{

}
