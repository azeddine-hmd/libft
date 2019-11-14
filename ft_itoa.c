/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 06:25:05 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/25 22:56:30 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int i;

	i = 1;
	while ((n /= 10) != 0)
		i++;
	return (i);
}

static char	*zero_condition(void)
{
	char	*n;

	if (!(n = (char*)malloc(2)))
		return (NULL);
	*n = '0';
	*(n + 1) = '\0';
	return (n);
}

static char	*negative_condition(unsigned int n)
{
	char	*strnum;
	int		len;

	len = numlen(n);
	if (!(strnum = (char*)malloc(len + 2)))
		return (NULL);
	ft_bzero(strnum, len + 2);
	strnum[0] = '-';
	while (n)
	{
		strnum[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (strnum);
}

char		*ft_itoa(int n)
{
	char	*strnum;
	int		len;

	if (n == 0)
		return (zero_condition());
	if (n < 0)
		return (negative_condition((unsigned int)(n * -1)));
	len = numlen(n);
	if (!(strnum = (char*)malloc(len + 1)))
		return (NULL);
	ft_bzero(strnum, len + 1);
	while (n)
	{
		--len;
		strnum[len] = (n % 10) + '0';
		n /= 10;
	}
	return (strnum);
}
