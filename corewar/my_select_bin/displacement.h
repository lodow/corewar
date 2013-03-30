/*
** displacement.h for displa in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 16 19:51:08 2013 luc sinet
** Last update Sat Jan 19 12:16:51 2013 luc sinet
*/

#ifndef DIS_H_
# define DIS_H_

# define NEXT(pos) (pos + sel->height + 1 > sel->max_elem - 1)
# define VMINPOS(pos) (pos == 0) ? (sel->max_elem - 1) : (pos - 1)
# define VMAXPOS(pos) (pos == sel->max_elem - 1) ? 0 : (pos + 1)
# define HMINPOS(pos) (pos - sel->height - 1 < 0) ? 0 : (pos - sel->height - 1)
# define HMAXPOS(pos) NEXT(pos) ? (sel->max_elem - 1) : (pos + sel->height + 1)

#endif
