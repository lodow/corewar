/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 26 21:35:42 2013 luc sinet
*/

#include "liste.h"

int	my_list_size(t_list *begin)
{
  int	i;

  i = 0;
  while (begin != NULL)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}

void		my_rm_from_list(t_list **begin, int (*remove)(void*, void*),
                      int (*f)(void*), void *arg)
{
  t_list	*ptr;
  t_list	*prec;

  while (((*begin) != NULL) && (remove((*begin)->data, arg)))
    {
      f((*begin)->data);
      ptr = (*begin);
      (*begin) = ptr->next;
      free(ptr);
    }
  if ((prec = (*begin)) != NULL)
    ptr = prec->next;
  while ((prec != NULL) && (ptr != NULL))
    if (remove(ptr->data, arg))
      {
        f(ptr->data);
        prec->next = ptr->next;
        free(ptr);
        ptr = prec->next;
      }
    else
      {
        prec = ptr;
        ptr = ptr->next;
      }
}

void		my_apply_on_list(t_list *begin,
                         int (*f)(void*, void*), void *arg)
{
  t_list	*list;

  list = begin;
  while (list != NULL)
    {
      (*f)(list->data, arg);
      list = list->next;
    }
}

void	my_rm_list(t_list *begin, int (*f)(void*))
{
  if (begin != NULL)
    {
      if (begin->next != NULL)
        my_rm_list(begin->next, f);
      (*f)(begin->data);
      free(begin);
    }
}

void		my_add_to_list(t_list **begin, void *data)
{
  t_list	*tmp;

  if (*begin == NULL)
    {
      if ((*begin = malloc(sizeof(t_list))) == NULL)
        return ;
      (*begin)->data = data;
      (*begin)->next = NULL;
      return ;
    }
  tmp = *begin;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = malloc(1 * sizeof(t_list));
  if ((tmp)->next != NULL)
    {
      (tmp)->next->data = data;
      (tmp)->next->next = NULL;
    }
}
