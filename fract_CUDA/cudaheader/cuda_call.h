/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuda_call.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 05:42:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/16 05:43:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUDA_CALL_H
# define CUDA_CALL_H
# ifdef __cplusplus

extern "C"

# endif

void	cuda_call_mandelbrot(unsigned int* a_h, unsigned int constw, unsigned int consth, float middlex, float middley, float scale, unsigned int max, unsigned int reset);

#endif
