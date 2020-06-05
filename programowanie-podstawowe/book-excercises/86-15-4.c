#include<stdio.h>
#include<stdlib.h>

#define write(x)    printf("%s\n", (x))
#define begin {
#define end }
#define then
#define readln(x)   scanf("%d", &(x))
#define writeln(x)  printf("%d\n", (x))
#define sqr(x)      (x) * (x)

int main(int argc, char *argv[])
begin
int a,b;
write("Podaj a ");//wyprowadzenie tekstu
readln(a); //wczytanie zmiennej
write("Podaj b ");
readln(b);
write("Podales: ");
writeln(a); //wyprowadzenie zmiennej
writeln(b);
if (a>b) then begin
write("a wieksze od b ");
write("--> Kwadrat a= ");
writeln(sqr(a)); //a*a
end;
if (a<b) then write("b wieksze od a");
if (a==b) then write(" a i b takie same");
return 0;
end