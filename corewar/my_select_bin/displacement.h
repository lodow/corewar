#ifndef DIS_H_
# define DIS_H_

# define NEXT(pos) (pos + sel->height + 1 > sel->max_elem - 1)
# define VMINPOS(pos) (pos == 0) ? (sel->max_elem - 1) : (pos - 1)
# define VMAXPOS(pos) (pos == sel->max_elem - 1) ? 0 : (pos + 1)
# define HMINPOS(pos) (pos - sel->height - 1 < 0) ? 0 : (pos - sel->height - 1)
# define HMAXPOS(pos) NEXT(pos) ? (sel->max_elem - 1) : (pos + sel->height + 1)

#endif
