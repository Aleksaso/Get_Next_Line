/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:59:51 by asilva-o          #+#    #+#             */
/*   Updated: 2024/04/03 17:54:56 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

void ft_leaks(void){
	system("leaks -q a.out");
}
int main(){
	int fd;
	char *linea;
fd=open("test.txt", O_RDONLY);
linea=get_next_line(fd);
while(linea != NULL)
{
	printf("%s", linea);
	free(linea);
	linea=get_next_line(fd);
}
printf("%s", linea);
atexit(ft_leaks);
}*/
