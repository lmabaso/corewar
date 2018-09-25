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

void        ft_puthex(unsigned char c)
{
    char *tab;

    tab = "0123456789abcdef";
    ft_putchar(tab[c / 16]);
    ft_putchar(tab[c % 16]);
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

// void    load_players(t_players *pl, t_obj *c)
// {
    
// }

void    ft_puthex2(int c)
{
    char *tab;

    tab = "0123456789abcdef";
    ft_putchar(tab[((c / 16 / 16) / 16)]);
    ft_putchar(tab[((c / 16) / 16)]);
    ft_putchar(tab[(c / 16) % 16]);
    ft_putchar(tab[c % 16]);
}

void    *ft_write_to(void *arena, void *code, size_t start, size_t size)
{
    unsigned char *d;
	unsigned char *s;
	d = (unsigned char *)arena;
	s = (unsigned char *)code;
	while (start < size)
	{
		d[start] = s[start];
		start++;
	}
	return (arena);
}

int     main(int ac, char **av)
{
    int fd;
    t_obj *c;
    unsigned int i;
    t_players *pl;
    
    if (ac < 2)
    {
        ft_putendl("Usage: ./corewar [-dump numbers_of_cycles] [ [-a load_address] champion1.cor] ...");
        return (0);
    }
    pl = NULL;
    c = initialize_obj();
    fd = 0;
   
    // printf("%d", pl->info.prog_size);
    if (ft_strequ(av[1], "-d"))
    { 
        fd = open(av[2], O_RDONLY);
        i = 0;
        unsigned char *line;
        int j;
        int x;
        int y;

        line = NULL;
        j = ft_read_memory(fd, &line);
        ft_append(&pl, line);
        ft_write_to(c->arena, pl->code, 0, pl->info.prog_size);
        x = 1;
        y = 0;
        ft_putstr("0x");
        ft_puthex2(i);
        ft_putstr(" : ");
        while (i < MEM_SIZE)
        {
            ft_puthex(c->arena[i]);
            if (i < MEM_SIZE - 1)
                ft_putchar(' ');
            if (x == 64)
            {
                if (i < MEM_SIZE - 1)
                {
                    ft_putchar('\n');
                    ft_putstr("0x");
                    // ft_putnbr(i);
                    ft_puthex2(i + 1);
                    ft_putstr(" : ");
                }
                x = 0;
            }
            x++;
            i++;
        }
    }
    
    // ft_putendl(pl->info->prog_name);
    return (1);
}