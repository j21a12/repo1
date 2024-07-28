/*
 * convertir a binario.c
 * 
 * Copyright 2020 Aroot <aroot@aroot-Intel>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
void tbin (long long int num);
void sumabin(long long int numdeci,long long int expo,long long int data);
long long int numxpo(long long int base);
long long int sum(long long int x, long long int y);
long long int  numdeci=0,expo,data=1,u=0,nx=0;
int ipbit[31],ipbi=31,ip=0;


int main()
{
	long long int oc1=0,dig,a=7;
	int ob,b=1;
	do {
	printf("--Ingrese el numero de una de las obciones que necesite--\n");
	printf("	Convertir numero decimal largo a binario --1--\n");
	printf("	Convertir IP en binario y decimal largo  --2--\n");
	printf("   	 Convertir decimal largo a IP             --3--\n");
	printf("    ----------  Salir   ------------        --0--\n");
	scanf("%i",&ob);
	switch(ob){
		case 0: b=0; break;
		case 1:	
	printf("Ingrese numero a convertir en binario\n");
	scanf("%lli", &numdeci);
	printf("Numero decimal ingresado %lli\n",numdeci);
	tbin(numdeci);
		break;
		case 2:
		printf("--Convertir IP en binario y numero decimal largo--\n");
			for (dig=1;dig<=4;dig++){
			printf("Ingrese el octeto %lli\n",dig);
			scanf("%lli", &numdeci);
			ip=1;
			tbin(numdeci);
		
		}
		printf("La direccion IP en binario es: \n");
		for(dig=31;dig>=0;dig--){
			oc1=ipbit[dig];
			printf("%lli",oc1);
			}
		for(dig=0;dig<=31;dig++){
			oc1=ipbit[dig];
			if(oc1==1){
				nx+=numxpo(dig);
				}
			}
			printf("La direccion IP en decimal largo es: %lli\n",nx);
			break;
		case 3:
			printf("Ingrese el Numero decimal largo %lli\n",dig);
			scanf("%lli", &numdeci);
			ip=1;
			tbin(numdeci);
			printf("La direccion IP en binario es: \n");
		for(dig=31;dig>=0;dig--){
			oc1=ipbit[dig];
			printf("%lli",oc1);
			}
			printf("La direccion IP es:");
		for(dig=31;dig>=0;dig--){
			if(a==-1){
				printf("!%lli.",nx);
				nx=0;
				a=7;
				}
			oc1=ipbit[dig];
			if(oc1==1){
				nx+=numxpo(a);
				}
				
				a--;
			}
			printf("!%lli.\n",nx);
			a=7;
			nx=0;
			break;
			default:
			printf("		Ingreso un valor incorrecto \n");
		}
		ipbi=31;
		ip=0;
		}while(b==1); 
	return 0;
}
void sumabin(long long int numdeci, long long int u, long long int data){
	long long int num=0,e=0;
	printf("data %lli++  %lli-- ",data,u);
	while(numdeci!=num){													//verifica hasta que el numero sumado sea 
				if(data>numdeci){											//igual al ingresado 
				printf("data --%lli",data);									//resta el exponente si el dato de este es
				u--;														//mayor que el numero ingresado 
				data=numxpo(u);												//resta el exponente 
				num=data;													//se le asigna el nuevo valor del exponente 
				printf("!1!");
				if(data<numdeci){
					ipbit[ipbi]=1;
							ipbi--;
					}														//a la variable que guarda el numero 
				}
				else {
					if(num>=0){												//para que no se verifiquen valores negativos
						e=sum(u,num);										//realizar suma del numero con el valor del
						if(e<=numdeci){										//siguiente exponente
						num=e;												//si es menor que el numero ingresado 
						u--;												//se realiza la suma y se guarda el nuevo
						printf("!1!");										//número , escribir 1
						if(ip==1){
							ipbit[ipbi]=1;									//a la matriz se le asigan 1 si suma
							ipbi--;											//disminuir el contador de la matriz
							}
						}
						else{
								printf("!0!");								//si no ecribir 0 y disminuir el exponente
						u--;
						if(ip==1){
							ipbit[ipbi]=0;
							ipbi--;
							}
						}
					}	
					}
		}
		
			while(u!=0){
				printf("0");
				u--;
					if(ip==1){
							ipbit[ipbi]=0;
							ipbi--;
							}
				}	
}

long long int numxpo(long long int expo){								//funcion que retorna el valor del exponente
	long long int i, dato=1;						//
	printf("--%lli  *--",expo);
		if(expo<0){
			return 0;
			}
		for(i=0;i<expo;i++){											//resultado el exponente  
			dato*=2;
			printf("resultado exponente %lli\n",dato);
			}
			
		return dato;
	}
long long int sum(long long int x, long long int y){						//funcion  que suma el dato mas el 
	long long int result=0,a2=0,a3=0;										//valor del siquiente exponente
	printf("expo x %lli //\n",x);
	a2=x-1;																	//exponente siguiente/
	printf("a2=%lli\n",a2);
	a3=numxpo(a2);															//resultado del exponente siguiente
	printf("result %lli \n",a3);
	result=a3+y;															//suma del exponente mas el numero 
	printf("sumatoria %lli",result);										//anterior 
	return result;
	}
	
	void tbin(long long int num){
	if(numdeci==1){
	printf("El numero decimal ingresado es 1");
	return;
	}
	else{
		if(numdeci==0){
	printf("El numero decimal ingresado es 0");
			if(ip==1){
				for(expo=0;expo<=8;expo++){
					ipbit[ipbi]=0;
					ipbi--;
					}
				}
	return;
	}
    }
	for(expo=0;data<=numdeci; expo++){										//para verificar el que el resultado el 
	printf(" for1  %lli\n",expo);											//valor del exponente no desface con el 
		printf("data %lli\n",data);											//numero ingresado, para optener le 
			if(expo==0){													//exponente mas sercano al valor del número
				printf("data %lli\n",data);			//
				u++;
				data++;
				printf("%lli--\n",u);
				}else{
					for(int i=1;i<=expo;i++){
				    printf("%i*\n",i);
					data*=2;
					printf("exponente while %lli\n",data);
					u++;
					printf("%lli--\n",u);
					if(data>numdeci){										//verifica resuldato del primer exponente
						break;												//sea mayor que el numero ingresado 
						}													// sale de la secuencia
				}
					
					}
		}																	//funcion que obtiene el numero decimal, el
	sumabin(numdeci,u,data); 												//exponente mas alto y el valor del exponente
																		//printf("***numero al exponente %lli es %lli\n", u,numxpo(u));
		}
