/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 26 20:59:46 2013 luc sinet
*/

#include	"include.h"

void	print_winner(t_vm *vm, int got_a_winner)
{
  int	i;

  i = 0;
  if (got_a_winner == 1)
    while (vm->champs[i] != NULL)
      {
        if ((vm->champs[i]->alive) == 0)
          {
            my_putstr("le joueur ", 1, 10);
            my_put_nbr(vm->champs[i]->number, 1);
            my_putstr("(", 1, 1);
            my_putstr(vm->champs[i]->header.prog_name, 1, -1);
            my_putstr(") a gagne\n", 1, 10);
          }
        i++;
      }
}

void		rmv_dead_champ_proc(t_list **proc_list, t_champ *champ)
{
  t_list		*tmp_list;
  t_process	*tmp;

  tmp_list = *proc_list;
  while (tmp_list != NULL)
    {
      tmp = tmp_list->data;
      if (tmp->associated_champ == champ)
        my_rm_from_list(proc_list, tmp_list, &delete_process);
      tmp_list = tmp_list->next;
    }
}

int	check_champs_alive_a_print(t_vm *vm)
{
  int	i;
  int	got_a_winner;

  i = 0;
  got_a_winner = 0;
  while (vm->champs[i] != NULL)
    {
      if (vm->champs[i]->alive == 0)
        {
          vm->champs[i]->alive = -1;
          rmv_dead_champ_proc(&(vm->process_list), vm->champs[i]);
        }
      else
        {
          if (got_a_winner == 1)
            got_a_winner = 0;
          else
            got_a_winner = 1;
          vm->champs[i]->alive = 0;
        }
      i++;
    }
  print_winner(vm, got_a_winner);
  return (got_a_winner);
}

void			dump_memory(t_vmmem *mem, int size)
{
  int			i;
  char			*hexa;
  unsigned char		tmp;

  i = 0;
  hexa = "0123456789ABCDEF";
  while (i < size)
    {
      tmp = mem[i];
      my_putstr("0x", 1, 2);
      my_putstr(&hexa[tmp / 16], 1, 1);
      my_putstr(&hexa[tmp % 16], 1, 1);
      if (i != size - 1)
        my_putstr(",", 1, 1);
      i++;
    }
  my_putstr("\n", 1, 1);
}

int	handle_game(t_vm *vm)
{
  int	end_game;

  end_game = 0;
  vm->cycle_count++;
  if ((vm->cycle_count % vm->cycle_to_die) == 0)
    if (check_champs_alive_a_print(vm) == 1)
      end_game = 1;
  if (vm->nbr_live >= NBR_LIVE)
    vm->cycle_to_die -= CYCLE_DELTA;
  if ((vm->cycle_count >= vm->cycle_to_dump) && (vm->cycle_to_dump != -1))
    {
      dump_memory(vm->mem, MEM_SIZE);
      end_game = 1;
    }
  if (vm->cycle_to_die <= 0)
    end_game = 1;
  return (end_game);
}
