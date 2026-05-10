/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:41:06 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/10 12:52:06 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>
# include "get_next_line.h"

typedef enum e_strat
{
	INVALID,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}	t_strat;

typedef struct s_env
{
	unsigned long	sa;
	unsigned long	sb;
	unsigned long	ss;
	unsigned long	pa;
	unsigned long	pb;
	unsigned long	ra;
	unsigned long	rb;
	unsigned long	rr;
	unsigned long	rra;
	unsigned long	rrb;
	unsigned long	rrr;
	double			disorder;
	t_strat			strat;
	t_strat			real_strat;
	int				bench;
	size_t			len;
}	t_env;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

int				not_params(int ac, char **av);
int				benchmode(int ac, char **av);
t_env			*init_env(t_list *l, int ac, char **av);
int				addnbrs(t_list **l, char *s);
int				ft_isspace(char c);
int				is_valid_str(char *s);
int				is_valid_input(int ac, char **av);
int				is_keyword(char *s);
t_list			*create_list(int ac, char **av);
int				is_int(long n);
long			ft_atol(const char *nptr);
double			calc_disorder(t_list *l);
int				exist_dups(t_list *l);
t_strat			calc_real_strat(int ac, char **av);
t_strat			which_strat(char *s);
int				ft_strcmp(char *s1, char *s2);
t_strat			calc_strat(t_env *env);
unsigned long	calc_total_ops(t_env *env);
char			*calc_complexity(t_env *env);
char			*printable_strat(t_env *env);
int				print_bench(t_env *env);
int				print_percentage(double x);
int				print_op(char *s, unsigned long n);
int				print_ops(t_env *env);
int				parse_input(t_node **l, t_env **env, int argc, char **argv);
int				get_index(t_list *l, t_list *p);
int				lst_to_node(t_list **l, t_node **n);
void			push_swap(t_node **stack_a, t_env *env, bool print);
t_node			*ft_nodenew(int value, int index);
void			ft_nodeadd_back(t_node **node, t_node *new);
void			ft_nodeclear(t_node **lst);
void			push_swap_medium(t_node **a, t_node **b, t_env *env, bool p);

//aux

//void			print_node(t_node *n);

// bernat:

void			ft_error(char *msg);
int				ft_nodesize(t_node *head);
t_node			*ft_nodelast(t_node *head);

int				swap(t_node **stack);
int				push(t_node **stack_to, t_node **stack_from);
int				rotate(t_node **stack);
int				reverse_rotate(t_node **stack);

int				sa(t_node **stack_a, t_env *env, bool print);
int				sb(t_node **stack_b, t_env *env, bool print);
int				ss(t_node **stack_a, t_node **stack_bs, t_env *env, bool print);
int				pa(t_node **stack_a, t_node **stack_b, t_env *env, bool print);
int				pb(t_node **stack_a, t_node **stack_b, t_env *env, bool print);
int				ra(t_node **stack_a, t_env *env, bool print);
int				rb(t_node **stack_b, t_env *env, bool print);
int				rr(t_node **stack_a, t_node **stack_b, t_env *env, bool print);
int				rra(t_node **stack_a, t_env *env, bool print);
int				rrb(t_node **stack_b, t_env *env, bool print);
int				rrr(t_node **stack_a, t_node **stack_b, t_env *env, bool print);

int				is_sorted(t_node **stack);
int				get_distance(t_node **stack, int index);
int				get_min(t_node **stack, int val);
void			sort_3(t_node **stack_a, t_env *env, bool print);
void			move_min_top(t_node **a, t_env *env, bool print);
void			sort_simple(t_node **a, t_node **b, t_env *env, bool print);
void			push_swap_simple(t_node **a, t_node **b, t_env *env, bool p);
int				get_max_bits(t_node **stack);
void			push_swap_complex(t_node **a, t_node **b, t_env *env, bool p);

#endif
