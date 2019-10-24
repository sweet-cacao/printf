#include "ft_printf.h"

t_list	zero_struct()
{
	t_list a;
	a.hash = 0;
	a.min = 0;
	a.plus = 0;
	a.precision = 0;
	a.space = 0;
	a.width = 0;
	return (a);
}
