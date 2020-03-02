//
// Created by anonymus-raccoon on 2/27/20.
//

#include "my.h"

char *my_str_replace(char *str, const char *to_replace, char c)
{
	char *p;
	int len = my_strlen(to_replace);

	while ((p = my_strstr(str, to_replace))) {
		*p = c;
		p++;
		for (char *ptr = p + len; *ptr; ptr++, p++)
			*p = *ptr;
		*p = '\0';
	}
	return (str);
}