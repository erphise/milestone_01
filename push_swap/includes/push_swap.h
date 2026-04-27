#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_libft/libft.h"

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

void	ft_error(char *msg);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);

int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif
