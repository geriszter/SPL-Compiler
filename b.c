#include <stdio.h>
int main(void) {
int a, b;
char c;
float d, e;
scanf("%d", &a);
scanf("%d", &b);
if (a  >  b) { 
printf("%c", 'A');
}
else { 
printf("%c", 'B');
}
printf("\n");
scanf("%f", &d);
e = d * 2.3;
printf("%.2f", e);
printf("\n");
scanf(" %[^\n]c", &c);
printf("%c", c);
printf("\n");

return 0;
}