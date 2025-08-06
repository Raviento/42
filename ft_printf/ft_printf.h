/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:48:46 by mehkul            #+#    #+#             */
/*   Updated: 2025/08/01 12:48:46 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_ptr(unsigned long ptr);
int	print_int(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, char c);

#endif