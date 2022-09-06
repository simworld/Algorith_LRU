//simulazione algoritmo LRU
//Simone Susino matr. 138

#include"stdio.h"
#include"string.h"
#include"stdlib.h"

#define MAX 350


typedef struct {
int contatore;
int tag;
char blocco[10];
}linea;

linea cache[200];

typedef struct {
int etichetta;
char word[10];
}parola;

parola ram[MAX];

int main (){
int i,j,x;
int temp=0;
int tag,num;
char var[10]="HelloWorld";

srand(time(NULL));
	//riempiamo la ram
	for(i=0;i<MAX;i++){
		for(j=0;j<10;j++){	
		ram[i].word[j]=var[j];
				}
	ram[i].etichetta=i;	
	}
	
	//stampa il contenuto della ram
	/*for (i=0;i<MAX;i++){
		for(j=0;j<10;j++){
			printf("%c", ram[i].word[j]);
		}
	}*/


			i=0;
			j=0;				
			//copia dalla ram alla cache fino a riempirla e incrementiamo il contatore di ogni linea di cache piena
			while(j<200){									
		
								
					if(strcmp(cache[j].blocco,"")==0){						
						strncpy(cache[j].blocco,ram[i].word, 10);
						j++;
						i++;
						for(x=0;x<200;x++){						//incrementiamo il contatore delle linee piene
							if(strcmp(cache[x].blocco,"")!=0) {
								temp=cache[x].contatore;
								temp++;							
								cache[x].contatore=temp;
							}
						}

					}				
			}
			//simuliamo l'utilizzo randomizzato di una linea di cache, azzerandone il contatore e incrementando gli altri di 1
			while(i<MAX){		
					num=(rand()%200);
					cache[num].contatore=0;
					for(x=0;x<200;x++){
							temp=cache[x].contatore;
							temp++;							
							cache[x].contatore=temp;
						}
						cache[num].contatore=0;	

						temp=0;							
						for(x=0;x<200;x++){	//individuiamo la linea di cache con il valore pi alto che sarˆ quello non referenziato da pi tempo
							if(cache[x].contatore>temp){
								temp=cache[x].contatore;
								tag=cache[x].contatore;
							}	
						}	
						//copiamo il blocco di ram nella linea di cache individuata
						strncpy(cache[tag].blocco,ram[i].word,10);
						
						for(x=0;x<200;x++){			//incrementiamo i contatori delle altre linee
							temp=cache[x].contatore;
							temp++;							
							cache[x].contatore=temp;
						}
						cache[tag].contatore=0;	  		//settiamo a zero il contatore della linea utilizzata

					i++;		
	
			}	

	//stampa il contenuto della cache
	for (i=0;i<200;i++){
		printf("[%d]-Cache.blocco:",i);
		for(j=0;j<10;j++){
			printf("%c", cache[i].blocco[j]);
		}
	printf("\tCache.contatore:%d\n", cache[i].contatore);
	}

}	
