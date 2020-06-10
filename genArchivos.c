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
    Censo censo;
}ModifCenso;


int main(int argc, char *argv[])
{
    Provincia provincias[24];
    Provincia aux;
    strcpy(provincias[0].nomProv,"Buenos Aires");
    strcpy(provincias[0].codProv,"BUE");
    strcpy(aux.codProv,"CAB");
    strcpy(aux.nomProv,"CABA");
    provincias[1]=aux;
    strcpy(aux.codProv,"CAT");
    strcpy(aux.nomProv,"Catamarca");
    provincias[2]=aux; 
    strcpy(aux.codProv,"CHA");
    strcpy(aux.nomProv,"Chaco");
    provincias[3]=aux; 
    strcpy(aux.codProv,"CHU");
    strcpy(aux.nomProv,"Chubut");
    provincias[4]=aux; 
    strcpy(aux.codProv,"COR");
    strcpy(aux.nomProv,"Cordoba");
    provincias[5]=aux; 
    strcpy(aux.codProv,"CRR");
    strcpy(aux.nomProv,"Corrientes");
    provincias[6]=aux; 
    strcpy(aux.codProv,"ENR");
    strcpy(aux.nomProv,"Entre Rios");
    provincias[7]=aux; 
    strcpy(aux.codProv,"FOR");
    strcpy(aux.nomProv,"Formosa");
    provincias[8]=aux;
    strcpy(aux.codProv,"JUY");
    strcpy(aux.nomProv,"Jujuy");
    provincias[9]=aux; 
    strcpy(aux.codProv,"LAP");
    strcpy(aux.nomProv,"La Pampa");
    provincias[10]=aux; 
    strcpy(aux.codProv,"LAR");
    strcpy(aux.nomProv,"La Rioja");
    provincias[11]=aux; 
    strcpy(aux.codProv,"MEN");
    strcpy(aux.nomProv,"Mendoza");
    provincias[12]=aux; 
    strcpy(aux.codProv,"MIS");
    strcpy(aux.nomProv,"Misiones");
    provincias[13]=aux; 
    strcpy(aux.codProv,"NQN");
    strcpy(aux.nomProv,"Neuquen");
    provincias[14]=aux; 
    strcpy(aux.codProv,"RNE");
    strcpy(aux.nomProv,"Rio Negro");
    provincias[15]=aux; 
    strcpy(aux.codProv,"SAL");
    strcpy(aux.nomProv,"Salta");
    provincias[16]=aux; 
    strcpy(aux.codProv,"SJU");
    strcpy(aux.nomProv,"San Juan");
    provincias[17]=aux; 
    strcpy(aux.codProv,"SLU");
    strcpy(aux.nomProv,"San Luis");
    provincias[18]=aux; 
    strcpy(aux.codProv,"SCR");
    strcpy(aux.nomProv,"Santa Cruz");
    provincias[19]=aux; 
    strcpy(aux.codProv,"SFE");
    strcpy(aux.nomProv,"Santa Fe");
    provincias[20]=aux; 
    strcpy(aux.codProv,"SDE");
    strcpy(aux.nomProv,"Santiago del Estero");
    provincias[21]=aux; 
    strcpy(aux.codProv,"TFU");
    strcpy(aux.nomProv,"Tierra del Fuego");
    provincias[22]=aux; 
    strcpy(aux.codProv,"TUC");
    strcpy(aux.nomProv,"Tucuman");
    provincias[23]=aux; 

    FILE *fprov;
    if ((fprov = fopen("./provincias.dat","wb"))==NULL) {
        printf("No se pudo crear el archivo");
        getchar();
        exit(1);
    }
    
    for (int i = 0; i < 24; i++) {
        fwrite(&provincias[i],sizeof(Provincia),1,fprov);    
    }
    
    fclose(fprov);
            
   
    return 0;
}


/*BUE	Buenos Aires
CAB	CABA
CAT	Catamarca
CHA	Chaco
CHU	Chubut
COR	Córdoba
COR	Corrientes
ENR	Entre Ríos
FOR	Formosa
JUY	Jujuy
LAP	La Pampa
LAR	La Rioja
MEN	Mendoza
MIS	Misiones
NEQ	Neuquén
RNE	Río Negro
SAL	Salta
SJU	San Juan
SLU	San Luis
SCR	Santa Cruz
SFE	Santa Fe
SDE	Santiago del Estero
TFU	Tierra del Fuego
TUC	Tucumán
*/
