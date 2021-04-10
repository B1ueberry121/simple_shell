#include "holberton.h"

char *_scan(char *buf, int a)
{
	read(a, buf, sizeof(buf));
	return (buf);
}
