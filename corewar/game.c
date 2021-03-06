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
            my_putstr("le joueur ", 1, -1);
            my_put_nbr(vm->champs[i]->number, 1);
            my_putstr("(", 1, 1);
            my_putstr(vm->champs[i]->header.prog_name, 1, -1);
            my_putstr(") a gagne\n", 1, -1);
          }
        i++;
      }
}

int		rmv_dead_champ_proc(void *ptrproc, void *ptrchamp)
{
  t_process	*proc;
  t_champ	*champ;

  proc = ptrproc;
  champ = ptrchamp;

  if ((proc != NULL) && (champ != NULL))
    if (proc->associated_champ == champ)
      return (1);
  return (0);
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
          my_rm_from_list(&(vm->process_list), &rmv_dead_champ_proc,
                          &delete_process, vm->champs[i]);
        }
      else if (vm->champs[i]->alive != -1)
        {
          got_a_winner += 1;
          vm->champs[i]->alive = 0;
        }
      i++;
    }
  if (got_a_winner == 0)
    vm->cycle_to_die = 0;
  print_winner(vm, got_a_winner);
  return (got_a_winner);
}

int	handle_game(t_vm *vm, char **env)
{
  int	end_game;

  end_game = 0;
  vm->cycle_count++;
  if ((vm->nbr_live >= NBR_LIVE) && (vm->nbr_live != 0))
    {
      vm->cycle_to_die -= CYCLE_DELTA;
      vm->nbr_live = 0;
    }
  if (!GETFLAG(vm->flag, FLAGPOS(UNLIMITEDOPT)))
    if ((vm->cycle_to_die != 0) && (vm->cycle_count % vm->cycle_to_die) == 0)
      if (check_champs_alive_a_print(vm) == 1)
        end_game = 1;
  if ((vm->cycle_to_dump > 0) && (vm->cycle_count %  vm->cycle_to_dump) == 0)
    {
      dump_memory(vm, MEM_SIZE, env);
      if (!GETFLAG(vm->flag, FLAGPOS(UNLIMITEDOPT)))
        end_game = 1;
    }
  if ((vm->cycle_to_die <= 0) || (vm->process_list == NULL))
    {
      my_putstr("No winner, that's too bad !\n", 1, -1);
      end_game = 1;
    }
  return (end_game);
}
