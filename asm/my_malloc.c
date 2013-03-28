/*
** my_malloc.c for corewar in /home/maxime/Bureau/projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Thu Mar 28 16:32:59 2013 maxime lavandier
** Last update Thu Mar 28 16:38:57 2013 maxime lavandier
*/

#include "parse_cmd.h"
#include "asm.h"

void	put_malloc_error()
{
  my_putstr("Can’t perform malloc", 1, -1);
  exit(0);
}
