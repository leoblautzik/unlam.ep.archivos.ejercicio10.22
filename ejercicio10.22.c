/*Para estudiar la población extranjera en la Argentina, se decide realizar un censo por las distintas
provincias. Para ello, se dispone del archivo PROVINCIAS de 24 registros de dos campos:
• Código de Provincia (cadena de 3 posiciones)
• Nombre de la Provincia (cadena de 30 posiciones) Argentina tiene 24 provincias, incluyendo CABA.
La información sobre el censo realizado se encuentra en un archivo secuencial (CENSO) cuyos registros
están formados por:
•
Código de Provincia
•
Nacionalidad (entero 1 a 50)
•
Cantidad de habitantes (entero, mayor a cero)
El archivo no está ordenado.
En el archivo secuencial (MODIF_CENSO), que tampoco está ordenado, se tienen modificaciones, cuyo
formato de registro es:
•
Código de modificación (carácter:  ́A ́ o  ́M ́)
•
Código de Provincia
•
Nacionalidad
•
Cantidad (entero, mayor a cero)
Si el código de modificación es  ́A ́, debe sumarse la Cantidad a la existente; si es  ́M ́, debe reemplazarse
Cantidad de Habitantes con la informada. Se pide:
a. Almacenar la información del archivo en memoria utilizando una estructura adecuada. Puede ocurrir
que no haya información alguna Provincia – Nacionalidad, en cuyo caso se asume 0 habitantes.
b. Actualizar los datos con las modificaciones.
c. Informar el total de habitantes por Provincia ordenado en forma descendente por cantidad de
habitantes.
d. Grabar el archivo actualizado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char codProv[4];
	char nomProv[31];
}Provincia;

typedef struct 
{
    char codProv[4];
    int nacion;
    int cantHab;
}Censo;

typedef struct 
{
    char codModif;
    char codProv[4];
    int nacion;
    int cantHab;
}ModifCenso;

typedef struct
{
    int fila;
    int total;
}Total;

int buscar(Provincia [], char[], int);
void totalizar(Total [],int[][50]);


int main(int argc, char *argv[])
{
    Provincia provincias[24];
    int matDatos[24][50];
    Total totales[24];

    for(int i=0;i<24;i++)
        for(int j=0;j<50;j++)
            matDatos[i][j]=0;

    FILE *fprov;
    if ((fprov = fopen("provincias.dat","rb"))==NULL) {
        printf("ERROR");
        getchar();
        exit(1);
    }
 
    FILE *fcenso;
    if((fcenso = fopen("censo.dat","rb"))==NULL){
        printf("ERROR");
        getchar();
        exit(1);
    } 
 
    FILE *fModifCenso;
    if((fModifCenso = fopen("modif_censo.dat","rb"))==NULL){
        printf("ERROR");
        getchar();
        exit(1);
    } 
   
    for (int i = 0; i < 24; i++) {
        fread(&provincias[i],sizeof(Provincia),1,fprov);
    }
    fclose(fprov);
     
    int fila=0;
    Censo censoAux;
    while(!feof(fcenso)){
        fread(&censoAux,sizeof(Censo),1,fcenso);
        fila=buscar(provincias,censoAux.codProv,24);
        matDatos[fila][censoAux.nacion-1]=censoAux.cantHab;
    }
    fclose(fcenso);

    ModifCenso MCaux;
    while(!feof(fModifCenso)){
        fread(&MCaux,sizeof(ModifCenso),1,fModifCenso);
        fila=buscar(provincias,MCaux.codProv,24);
        if(MCaux.codModif=='A')
            matDatos[fila][censoAux.nacion-1]+=censoAux.cantHab;
        else
            matDatos[fila][censoAux.nacion-1]=censoAux.cantHab;
             
    }
    fclose(fModifCenso);
    
    for (int i = 0; i < 24; i++) {
        printf("Provincia[%d]: %s\t%s\n",i,provincias[i].codProv,provincias[i].nomProv); 

    }
   
    return 0;
}

int buscar(Provincia p [],char cp[],int tam){
    int i=0,encontrado=-1;
    while(encontrado<0 && i<tam){
        if(strcmp(p[i].codProv, cp)==0)
            encontrado=i;
        i++;
    }
    return encontrado;
}

void totalizar(Total t[],int m[24][50]){
    
    for (int i=0;i<24;i++){
        int auxTotal=0;
        for(int j=0;j<50;j++)
            auxTotal+=m[i][j];
        t[i].fila=i;
        t[i].total=auxTotal;
    }

}
