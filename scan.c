#include "holberton.h"

char *_scan(int a)
{
	char buf[128];
	read(a, buf, sizeof(buf));
	return (&buf);
}
