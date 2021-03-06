#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE		(6 * 1024)
# define IDX_MOD		512

/*
** Registres
*/
# define REG_NUMBER		16

/*
** size in Bytes
*/
# define IND_SIZE		2
# define REG_SIZE		4
# define DIR_SIZE		REG_SIZE

/*
** Cycle things
*/
# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		5
# define NBR_LIVE		40

# define MAX_ARGS_NUMBER	4     /* this may not be changed 2^*IND_SIZE */

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

typedef char	args_type_t;

# define T_REG			1	/* registre */
# define T_DIR			2	/* directe  (ld  #1, r1  met 1 dans r1) */
# define T_IND			4	/* indirecte toujours relatif should be 3 */
# define T_LAB			8	/* LABEL */

/*
** header
*/
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

/*
** extern op_t	g_op_tab[];
*/
typedef struct	s_op
{
  char		*mnemonique;
  char		nbr_args;
  args_type_t	type[MAX_ARGS_NUMBER];
  char		code;
  int		nbr_cycles;
  char		*comment;
}		t_op;

typedef struct	s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

#endif
