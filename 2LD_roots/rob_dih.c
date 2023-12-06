#undef __STRICT_ANSI__
#include<stdio.h>
#include<math.h>
int main(){
//float a=0.01,b=1.5*M_PI, x ,delta_x=1.e-3,funkca,funkcb,funkcx;

float a, b, bc, ac, nac, nbc, c, x ,delta_x=1.e-3,funkca,funkcb,funkcx;

printf("Ievadiet funkcijas a vertibu \n)");
scanf("%f",&a);
printf("Ievadiet funkcijas b vertibu \n)");
scanf("%f",&b);
printf("Ievadiet funkciju nobīdes vertibu, kas nobīdīs abas funkciju, jeb c \n)");
scanf("%f",&c);

int k=0;


funkca = sin(a/2);funkcb=sin(b/2);
ac = a-c;
bc = b-c;
if(funkca * funkcb>0){
printf("Intervala [%.2f;%.2f] sin(x/2) funkcijai",a,b);
printf("Intervālā [%.2f;%.2f] sin(x/2) funkcijai, pēc nobīdes",ac,bc, "nobīde",c);
printf("saknu nav(vai taja ir paru saknu skaits)\n");
return 1;}

printf("sin(%7.3f)=%7.3f\t\t\t\t",a,sin(a));
printf("sin(%7.3f)=%7.3f\n",b,sin(b));

while((b-a)>delta_x){
k++;//k=k+1;//k+=1;
x=(a+b)/2.;
if(funkca*sin(x/2)>0)//piea=0->funkca=0->reizinaajumsirpreciizi0 visulaiku->visulaika"straadaa"b=x
a=x;
else
b=x;
printf("%2d.iteraacija: sin(%7.3f)=%7.3f\t",k,a,sin(a/2));
printf("sin(%7.3f)=%7.3f\t",x,sin(x/2));
printf("sin(%7.3f)=%7.3f\n",b,sin(b/2));}

nac = sin((a-c)/2);
nbc = sin((b-c)/2);



printf("Sakne atrodas pie x=%.3f,jo sin(x)ir %.3f\n",x,sin(x/2), "un pēc nobīdes c=%.3f, ir a=%.3f\n, b=%.3f\n",nac, nbc);


return 0;}