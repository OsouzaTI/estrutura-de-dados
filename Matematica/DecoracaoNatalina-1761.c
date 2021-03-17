#include <stdio.h>
#include <math.h>
/* http://portaldoprofessor.mec.gov.br/fichaTecnicaAula.html?aula=24138 */
/* https://www.youtube.com/watch?v=4aJ067kf7xE */
#define PI 3.141592654
#define RAD(deg) (deg * PI)/180.0
int main(void)
{
    double angulo, distancia, alturaElfo;
    while(scanf("%lf %lf %lf", &angulo, &distancia, &alturaElfo) != EOF){
        double tangente = tan(RAD(angulo));
        double tamanhoFinal = ((distancia*tangente)+alturaElfo)*5;
        printf("%.2lf\n", tamanhoFinal);
    }
    return 0;
}