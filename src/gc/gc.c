#include <u.h>
#include "gc.h"

char *
gcstrdup(char *s)
{
	int  l;
	char *r;

	l = strlen(s);
	r = gcmalloc(l + 1);
	strncpy(r, s, l);
	return r;
}

char *gcprintf(char *fmt, ...)
{
	va_list va;
	int     n;
	char   *v;

	va_start(va, fmt);
	n = vsnprintf(0, 0, fmt, va);
	va_end(va);
	if(n < 0)
		panic("gcprintf internal error");
	n += 1;
	v = gcmalloc(n);
	va_start(va, fmt);
	n = vsnprintf(v, n, fmt, va);
	va_end(va);
	if(n < 0)
		panic("gcprintf internal error");
	return v;
}

void *
gcmalloc(int n)
{
	char *v;
	int  i;

	v = malloc(n);
	if(!v)
		gc();
	for(i = 0; i < n; i++)
		v[i] = 0;
	return v;
}

void
gc()
{
	panic("gc unimplemented");
}
