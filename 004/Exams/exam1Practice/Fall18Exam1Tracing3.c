#include <stdio.h>
int main (void) {
 int a, b, c, d, e, f, g, h;
 int t;
 scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f,
&g, &h);
 if (b<a) { t=a; a=b; b=t; }
 printf("a=%d, b=%d\n", a, b);
 if (d<c) { t=c; c=d; d=t; }
 printf("c=%d, d=%d\n", c, d);
 if (f<e) { t=e; e=f; f=t; }
 printf("e=%d, f=%d\n", e, f);
 if (h<g) { t=g; g=h; h=t; }
 printf("g=%d, h=%d\n", g, h);
 if (c<a) a=c;
 if (d>b) b=d;
 printf("a=%d, b=%d\n", a, b);
 if (g<e) e=g;
 if (h>f) f=h;
 printf("e=%d, f=%d\n", e, f);
 if (e<a) a=e;
 if (f>b) b=f;
 printf("a=%d, b=%d\n", a, b);
 return 0;
}
