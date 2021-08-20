#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int arr_numbin[50];
int ind_arr;
int ind_int;

void decimal_binario_float(float decimal)
{
	int arr_bin_float[50];
	int ind_float=0;
	int decimal_int=decimal;
	float decimal_float=decimal-decimal_int;
	
	
	ind_float=0;
	for(int k=0;k<5;k++)
	{
		
	 	decimal_float=decimal_float*2;
	 	
		int aux=decimal_float;
		arr_bin_float[ind_float]=aux;
		ind_float++;
		decimal_float = decimal_float-aux;
		
		if(decimal_float==0)
			break;
	}
	
	
	for(int k=0;k<ind_float;k++)
	{
		//printf("%d",arr_bin_float[k]);
		arr_numbin[ind_arr]=arr_bin_float[k];
		ind_arr++;
	}
		
		
	

}
void decimal_binario_int(float decimal)
{
    
	int arr_bin_int[50];
	ind_int=0;
	int decimal_int=decimal;
	bool ban=false;
	
	while(ban==false)
	{
		
		arr_bin_int[ind_int] = decimal_int % 2;	
		ind_int++;
		decimal_int = decimal_int /2;
			
		if(decimal_int==0)
			ban=true;
	}
	
	 
	
	for(int k=ind_int-1;k>=0;k--)
	{
		//printf("%d",arr_bin_int[k]);
		arr_numbin[ind_arr]=arr_bin_int[k];
		ind_arr++;
	}
	
	
	
	
	
}


int binario_decimal(char binario[],int lim)
{
	int cont=0;
	int pot=0;
	for(int k=lim-1;k>=0;k--)
	{
		
		cont = ((int)binario[k]-48)*(pow(2,pot))+cont;
		
		pot++;
	}
	//printf("%d\n",cont);	
	return cont;
}
int eliminar_ceros(char mantisa[])
{
	int lim;
	for(int k=23;k>=0;k--)
	{
		
		if(mantisa[k] == '1')
		{
			lim=k;
			break;
		}	
				
		
	}	
	return lim;
}

float binario_decimal_flotante(char binario[],int lim)
{
	lim=lim*(-1);
	int cont=0;
	float acum=0;
	for(int k=-1;k>=lim;k--)
	{
		
		acum = ((int)binario[cont]-48)*(pow(2,k))+acum;
		
		cont++;
	}
	
 return acum;
}
int main()
{
	
	int opc=1;
	printf("1.- Decimal a IEEE\n2.- Formato IEEE a Decimal\n");
	printf("Seleccione una opcion: ");
	scanf("%d",&opc);
	
	
	if(opc==1)
	{
		
		float decimal;
		int signo;
		ind_arr=0;
		printf("Ingrese el numero decimal: ");
		scanf("%f",&decimal);
		
		if(decimal>0)
			signo=0;
		else if(decimal<0)
		{
			decimal = decimal*(-1);
			signo=1;
		}
	
		printf("Signo    Exponente           Mantisa\n");
		decimal_binario_int(decimal);
		decimal_binario_float(decimal);
	
		int num_orig[50];
	
		for(int k=0;k<ind_arr;k++)
		{
			num_orig[k]=arr_numbin[k];
		}
	
		int ind_arr_orig=ind_arr;
		ind_arr=0;
	
		float exponente = ind_int-1+127;
		decimal_binario_int(exponente);
		printf("%d       ",signo);
	
		for(int k=0;k<ind_arr;k++)
		{
			printf("%d",arr_numbin[k]);	
		}
		printf("    ");
	
		for(int k=1;k<ind_arr_orig;k++)
		{
			printf("%d",num_orig[k]);	
		}
	
		for(int k=ind_arr_orig;k<=23;k++)
		{
			printf("0");
		}
	
	}

	else if(opc==2)
	{
		int bit=1;	
		char exponente[30];
		char mantisa[40];
		int lim=8;
		printf("Ingrse el primer bit: ");
		scanf("%d",&bit);
	
		printf("Ingrese el exponente: ");
		scanf("%s",&exponente);
	
	
		printf("Ingrese la mantisa: ");
		scanf("%s",&mantisa);
		int exponente_decimal = binario_decimal(exponente,lim);
		exponente_decimal=exponente_decimal-127;
	
	
    	int limite_mantisa	= eliminar_ceros(mantisa);
	
		char parte_entera[20];
		char parte_decimal[20];
	
		for(int k=0;k<=exponente_decimal;k++)
			parte_entera[k]=mantisa[k];	
	
		int contador=0;
		for(int k=exponente_decimal+1;k<=limite_mantisa;k++)
		{
			parte_decimal[contador]=mantisa[k];
	
			contador++;
		}
		
		
		int res_ent=binario_decimal(parte_entera,exponente_decimal+1);
		//printf("%d",res_ent);
	
		int limite_decimal = limite_mantisa-exponente_decimal;
		//printf("%d", limite_decimal);

	

		float res_flotante=binario_decimal_flotante(parte_decimal,limite_decimal);	
	
	
	
	
		
		float resultado = res_ent + res_flotante;

		if(bit==1)
			resultado= resultado*(-1);
	
		printf("%f",resultado);

		
	}
	
	
	
}



