#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "FContact2D.h"
#include "EntSal2D.h"

main(){
int NDX=500;
float Lambda= 1.65;
float fracON = 0.01;
int NoPasos=2000;
int NDY=NDX;

estado e;
int np;
float q;
char contenedor[100];
FILE *RhoVsT;

	AlojaMemoria(&e,NDX,NDY);
//	init_JKISS();
	GeneraEstadoAleatorio(&e, fracON);

	sprintf(contenedor,"SimplePointP_Lado@%d_Lambda@%1.4f_qIni@%1.2f",NDX,Lambda,fracON);
	CreaContenedor(contenedor);
	RhoVsT=AbreRhoVsTEn(contenedor);
	//GuardaEstadoEn(contenedor,&e);
	ActualizaRhoVsT(&e,RhoVsT);
	

	for (np=1;np<=NoPasos;np++)
	{
		BarridoMonteCarlo(&e,Lambda);
	//	GuardaEstadoEn(contenedor,&e);
		q=ActualizaRhoVsT(&e,RhoVsT);

		if(q==0.0 && np<(NoPasos-3)){np=NoPasos-2;}
	}
	fclose(RhoVsT);
}
