/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:34:37 by daumis            #+#    #+#             */
/*   Updated: 2023/05/15 17:53:54 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<stdio.h>
# include<limits.h>
# include<stdbool.h>
# include<unistd.h>

/*Node Structure*/
typedef struct s_elem
{
	int				num;
	int				pos;
	int				prix;
	bool			above_median;
	bool			cheapest;
	struct s_elem	*target_node;
	struct s_elem	*next;

}	t_elem;

/*Data Collection*/
typedef struct s_data
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	t_elem	*head_a;
	t_elem	*head_b;

	char	**splited;
	int		*tab;
	int		numbelts;
	int		icheck;

}	t_data;

/*List Creation*/
t_elem	*initlist(t_elem **stack, t_elem **head);
void	fillstack_a(t_data *data);
void	addtoback(t_data *data, int value);
/*Utility*/
size_t	wdcount(char *s, char sep);
void	*ft_memset(void *s, int c, size_t n);
void	ft_lstclear(t_elem *stack);
void	freeall(t_data *data);
char	**ft_free(char **tab, int i);
char	**ft_split(char *s, char c);
char	*fill_tab(char *s, char sep);
int		splitcheck(char *s, t_data *data);
int		checkinput(char *s, t_data *data);
int		check_int(char *s);
int		signhandle(char c, int sign);
int		checkargv(int ac, char **av, t_data *data);
int		lastcheck(t_data *data);
int		ft_isspace(char c);
int		ft_atoi(char *str, int *flag);
int		ft_isdigit(int c);
/*Actions and list manipulation*/
t_elem	*find_high(t_elem *stack);
t_elem	*find_small(t_elem *stack);
t_elem	*return_cheapest(t_data	*data);
int		stacklen(t_elem *stack);
int		stacksorted(t_data *data);
void	end_rotation(t_data *data, t_elem *stack, t_elem *celem, char c);
void	showstacks(t_data *data);
void	set_props(t_data *data, t_elem *stack_a, t_elem *stack_b);
void	reverse_rotate_stacks(t_data *data, t_elem *cnode);
void	rotate_stacks(t_data *data, t_elem *cnode);
void	set_medians(t_elem *stack);
void	push_swap(t_data *data);
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	set_price(t_data *data);
void	set_cheapest(t_data *data);
void	set_targets(t_data	*data, t_elem *temp);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rotate_a(t_data *data, int flag);
void	rotate_b(t_data *data, int flag);
void	rotate_r(t_data *data);
void	reverse_ra(t_data *data, int flag);
void	reverse_rb(t_data *data, int flag);
void	reverse_rr(t_data *data);

#endif