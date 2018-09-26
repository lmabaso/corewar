#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "op.h"

typedef struct          s_players
{
    int                 *player_num;
    header_t            info;
    unsigned char       pc;
    int                 cool_time;
    unsigned char       registers[15];
    unsigned char       *code;
    struct s_players    *next;
}                       t_players;

typedef struct      s_obj
{
    int             no_of_worriors;
    t_players       *worriors;
    unsigned char   *arena;
    t_op            operation;
    char            *line;
}                   t_obj;
#endif