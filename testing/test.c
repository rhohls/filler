/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:53:31 by lde-jage          #+#    #+#             */
/*   Updated: 2018/06/15 10:58:39 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
int getVelocity(int i);
bool myAssert(bool condition, char * str)
{
	if (condition == false)
	{
		printf("%s\n", str);
		return (false);
	}
	else
		return (true);
}

void vel_test(void)
{
	myAssert(getVelocity(20) == 25, "fail at velocity 20");

	myAssert(getVelocity(10) == 25, "fail at velocity 10");

	myAssert(getVelocity(1) == 1, "fail at velocity 1");

}
