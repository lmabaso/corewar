#include "../includes/corewar.h"
#include <fcntl.h>
#include <stdio.h>

t_obj       *initialize_obj(void)
{
    t_obj   *c;
    int i;

    i = 0;
    c = ft_memalloc(sizeof(t_obj));
    c->arena = ft_memalloc(sizeof(unsigned char *) * MEM_SIZE);
    while (i < MEM_SIZE)
    {
        c->arena[i] = 0;
        i++;
    }
    return (c);
}

void		ft_append(t_players** head, unsigned char *new_data)
{
    t_players	*new_node;
    t_players	*last;
    int         i;
    unsigned int         j;

    i = 4;
    j = 0;
	new_node = ft_memalloc(sizeof(t_players));
	last = *head;
    while (j < 129)
    {
        new_node->info.prog_name[j] = new_data[i];
        i++;
        j++;
    }
    i += 6;
    new_node->info.prog_size = new_data[i];
    i++;
    j = 0;
    while (j < 2049)
    {
        new_node->info.comment[j] = new_data[i];
        i++;
        j++;
    }
    i += 3;
    j = 0;
    new_node->code = &new_data[i];
    new_node->next = NULL;
    if (*head == NULL)
    {
       *head = new_node;
       return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return ;
}

void    load_players(t_players *pl, t_obj *c)
{
    
}

int     main(int ac, char **av)
{
    int fd;
    t_obj *c;
    unsigned int i;
    t_players *pl;
    
    if (ac < 2)
    {
        ft_putendl("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
        ft_putendl("#### TEXT OUTPUT MODE ##########################################################");
        ft_putendl("    -dump nbr_cycles    : Dumps memory after N cycles then exits");
        ft_putendl("################################################################################");
        return (0);
    }
    pl = NULL;
    c = initialize_obj();
    fd = 0;
    fd = open(av[1], O_RDONLY);
    i = 0;
    unsigned char *line;
    int j;

    line = NULL;
    j = ft_read_memory(fd, &line);
    ft_append(&pl, line);
    // printf("%d", pl->info.prog_size);
    while (i < MEM_SIZE)
    {
        printf("%x ", c->arena[i]);
        i++;
    }
    // ft_putendl(pl->info->prog_name);
    return (1);
}