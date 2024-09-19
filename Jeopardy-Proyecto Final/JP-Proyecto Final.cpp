#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PREGUNTAS 25
#define NUM_CATEGORIAS 5
#define NUM_RESPUESTAS 4

typedef struct {
    char categoria[50];
    int valor;
    char pregunta[100];
    char respuestas[NUM_RESPUESTAS][50];
    int correcta;
} Pregunta;

void cargar_preguntas(Pregunta preguntas[NUM_PREGUNTAS]) {
    FILE *archivo;
    char linea[200];
    int i = 0;

    archivo = fopen("Bancopreguntas.txt", "r");

    while(fgets(linea, 200, archivo)) {
        sscanf(linea, "%[^'\n']\n", preguntas[i].categoria);
        fgets(linea, 200, archivo);
        sscanf(linea, "%d\n", &preguntas[i].valor);
        fgets(linea, 200, archivo);
        sscanf(linea, "%[^'\n']\n", preguntas[i].pregunta);
        fgets(linea, 200, archivo);
        sscanf(linea, "%[^'\n']\n", preguntas[i].respuestas[0]);
        fgets(linea, 200, archivo);
        sscanf(linea, "%[^'\n']\n", preguntas[i].respuestas[1]);
        fgets(linea, 200, archivo);
        sscanf(linea, "%[^'\n']\n", preguntas[i].respuestas[2]);
        fgets(linea, 200, archivo);
        sscanf(linea, "%[^'\n']\n", preguntas[i].respuestas[3]);
        fgets(linea, 200, archivo);
        sscanf(linea, "%d\n", &preguntas[i].correcta);

        i++;
    }

    fclose(archivo);
}

void generar_matriz1(int m[5][5]){
	int f,c,n=1;	
	for(f=0;f<5;f++){		//for de filas matriz h
		for(c=0;c<5;c++){		//for de columnas
			m[c][f]=n;
			n++;			
		}
	}
}
void imprimir_matriz1(int m[5][5]){
	int f,c;
	printf("    Historia\t\t     Musica\t\t   Peliculas\t\t   Cultura General\t     Deportes");	
	for(f=0;f<5;f++){		//for de filas matriz h
	printf("\n");
		for(c=0;c<5;c++){		//for de columnas
			if(m[f][c]==0){
				printf("\tX \t\t");
			}
			else{
				printf("\t%d \t\t",m[f][c]);
			}			
		}
	}
	printf("\n");
}

void comprobar1(int m[5][5],int pregunta){
	int f,c;	
	for(f=0;f<5;f++){		//for de filas matriz h
		for(c=0;c<5;c++){		//for de columnas
		if(m[f][c]==pregunta){
			m[f][c]=0;
		}			
		}
	}
}

void generar_vector(int v[26]){
	int i;
	for(i=1;i<6;i++){
		v[i]=rand()%5+1;
	}
	for(i=6;i<11;i++){
		v[i]=rand()%5+6;
	}
	for(i=11;i<16;i++){
		v[i]=rand()%5+11;
	}
	for(i=16;i<21;i++){
		v[i]=rand()%5+16;
	}	
	for(i=21;i<26;i++){
		v[i]=rand()%5+21;
	}		
}

int preg_aleatoria1(int pregunta, int fd1,int fd2,int fd3,int fd4,int fd5, int a[26]){ //Pregunta aleatoria para Historia
	int f, c=0,d=0,e=45;
	
	if(pregunta>=1 && pregunta<=5){
		if(fd1==1){			
			f=a[1];
		}
		else if(fd1==2){			
			while(d!=1){
				if(a[1]!=a[2]){
					d=1;
				}
				else{
				a[2]=rand()%5+1;	
				}			
		}
		f=a[2];		
	}
		else if(fd1==3){			
			while(d!=1){
				if(a[3]!=a[1] && a[3]!=a[2]){
					d=1;
				}
				else{
				a[3]=rand()%5+1;	
				}			
		}
		f=a[3];		
	}
		else if(fd1==4){			
			while(d!=1){
				if(a[4]!=a[1] && a[4]!=a[2] && a[4]!=a[3]){
					d=1;
				}
				else{
				a[4]=rand()%5+1;	
				}			
		}
		f=a[4];		
	}
		else if(fd1==5){			
			while(d!=1){
				if(a[5]!=a[1] && a[5]!=a[2] && a[5]!=a[3] && a[5]!=a[4]){
					d=1;
				}
				else{
				a[5]=rand()%5+1;	
				}			
		}
		f=a[5];		
	}
		return f;			
	}
	
	if(pregunta>=6 && pregunta<=10){  //Pregunta aleatoria para MÃƒÂºsica
		if(fd2==6){			
			f=a[6];
		}
		else if(fd2==7){			
			while(d!=1){
				if(a[7]!=a[6]){
					d=1;
				}
				else{
				a[7]=rand()%5+6;	
				}			
		}
		f=a[7];		
	}
		else if(fd2==8){			
			while(d!=1){
				if(a[8]!=a[6] && a[8]!=a[7]){
					d=1;
				}
				else{
				a[8]=rand()%5+6;	
				}			
		}
		f=a[8];		
	}
		else if(fd2==9){			
			while(d!=1){
				if(a[9]!=a[6] && a[9]!=a[7] && a[9]!=a[8]){
					d=1;
				}
				else{
				a[9]=rand()%5+6;	
				}			
		}
		f=a[9];		
	}
		else if(fd2==10){			
			while(d!=1){
				if(a[10]!=a[6] && a[10]!=a[7] && a[10]!=a[8] && a[10]!=a[9]){
					d=1;
				}
				else{
				a[10]=rand()%5+6;	
				}			
		}
		f=a[10];		
	}
		return f;			
	}
	
	if(pregunta>=11 && pregunta<=15){		//Pregunta aleatoria para PelÃƒÂ­culas
		if(fd3==11){			
			f=a[11];
		}
		else if(fd3==12){			
			while(d!=1){
				if(a[12]!=a[11]){
					d=1;
				}
				else{
				a[12]=rand()%5+11;	
				}			
		}
		f=a[12];		
	}
		else if(fd3==13){			
			while(d!=1){
				if(a[13]!=a[11] && a[13]!=a[12]){
					d=1;
				}
				else{
				a[13]=rand()%5+11;	
				}			
		}
		f=a[13];		
	}
		else if(fd3==14){			
			while(d!=1){
				if(a[14]!=a[11] && a[14]!=a[12] && a[14]!=a[13]){
					d=1;
				}
				else{
				a[14]=rand()%5+11;	
				}			
		}
		f=a[14];		
	}
		else if(fd3==15){			
			while(d!=1){
				if(a[15]!=a[11] && a[15]!=a[12] && a[15]!=a[13] && a[15]!=a[14]){
					d=1;
				}
				else{
				a[15]=rand()%5+11;	
				}			
		}
		f=a[15];		
	}
		return f;			
	}
	
	
	if(pregunta>=16 && pregunta<=20){		//Pregunta aleatoria para Cultura General
		if(fd4==16){			
			f=a[16];
		}
		else if(fd4==17){			
			while(d!=1){
				if(a[17]!=a[16]){
					d=1;
				}
				else{
				a[17]=rand()%5+16;	
				}			
		}
		f=a[17];		
	}
		else if(fd4==18){			
			while(d!=1){
				if(a[18]!=a[16] && a[18]!=a[17]){
					d=1;
				}
				else{
				a[18]=rand()%5+16;	
				}			
		}
		f=a[18];		
	}
		else if(fd4==19){			
			while(d!=1){
				if(a[19]!=a[16] && a[19]!=a[17] && a[19]!=a[18]){
					d=1;
				}
				else{
				a[19]=rand()%5+16;	
				}			
		}
		f=a[19];		
	}
		else if(fd4==20){			
			while(d!=1){
				if(a[20]!=a[16] && a[20]!=a[17] && a[20]!=a[18] && a[20]!=a[19]){
					d=1;
				}
				else{
				a[20]=rand()%5+16;	
				}			
		}
		f=a[20];		
	}
		return f;			
	}
	
	if(pregunta>=21 && pregunta<=25){		//Pregunta aleatoria para Deportes
		if(fd5==21){			
			f=a[21];
		}
		else if(fd5==22){			
			while(d!=1){
				if(a[22]!=a[21]){
					d=1;
				}
				else{
				a[22]=rand()%5+21;
				}			
		}
		f=a[22];		
	}
		else if(fd5==23){			
			while(d!=1){
				if(a[23]!=a[21] && a[23]!=a[22]){
					d=1;
				}
				else{
				a[23]=rand()%5+21;	
				}			
		}
		f=a[23];		
	}
		else if(fd5==24){			
			while(d!=1){
				if(a[24]!=a[21] && a[24]!=a[22] && a[24]!=a[23]){
					d=1;
				}
				else{
				a[24]=rand()%5+21;	
				}			
		}
		f=a[24];		
	}
		else if(fd5==25){			
			while(d!=1){
				if(a[25]!=a[21] && a[25]!=a[22] && a[25]!=a[23] && a[25]!=a[24]){
					d=1;
				}
				else{
				a[25]=rand()%5+21;	
				}			
		}
		f=a[25];		
	}
		return f;			
	}
}



int valr_pregun(int pregunta){
	int vans1;	
        if(pregunta==1 || pregunta==6 || pregunta==11 || pregunta==16 || pregunta==21){
        	vans1=1;
		}
		if(pregunta==2 || pregunta==7 || pregunta==12 || pregunta==17 || pregunta==22){
        	vans1=2;
		}
		if(pregunta==3 || pregunta==8 || pregunta==13 || pregunta==18 || pregunta==23){
        	vans1=3;
		}
		if(pregunta==4 || pregunta==9 || pregunta==14 || pregunta==19 || pregunta==24){
        	vans1=4;
		}
		if(pregunta==5 || pregunta==10 || pregunta==15 || pregunta==20 || pregunta==25){
        	vans1=1;
		}
		return vans1;
}
int puntr_pregun(int pregunta){
	int puas1;	
        if(pregunta==1 || pregunta==6 || pregunta==11 || pregunta==16 || pregunta==21){
        	puas1=100;
		}
		if(pregunta==2 || pregunta==7 || pregunta==12 || pregunta==17 || pregunta==22){
        	puas1=250;
		}
		if(pregunta==3 || pregunta==8 || pregunta==13 || pregunta==18 || pregunta==23){
        	puas1=500;
		}
		if(pregunta==4 || pregunta==9 || pregunta==14 || pregunta==19 || pregunta==24){
        	puas1=750;
		}
		if(pregunta==5 || pregunta==10 || pregunta==15 || pregunta==20 || pregunta==25){
        	puas1=1000;
		}
		return puas1;
}

void imprimir(){
	printf("	          #   ('-.   #             #   _ (`-.  #   ('-.     # _  .-')   # _ .-') _   #             #\n");
	printf("	          # _(  OO)  #             #  ( (OO  ) #  ( OO ).-. #( \\( -O )  #( (  OO) )  #             #\n");
	printf("	     ,--. #(,------. # .-'),-----. # _.`     \\ #  / . --. / # ,------.  # \\     .'_  #  ,--.   ,--.#\n");
	printf("	 .-')| ,| # |  .---' #( OO'  .-.  '#(__...--'' #  | \\-.  \\  # |   /`. ' # ,`'--..._) #   \\  `.'  / #\n");
	printf("	( OO |(_| # |  |     #/   |  | |  |# |  /  | | #.-'-'  |  | # |  /  | | # |  |  \\  ' # .-')     /  #\n");
	printf("	| `-'|  | #(|  '--.  #\\_) |  |\\|  |# |  |_.' | # \\| |_.'  | # |  |_.' | # |  |   ' | #(OO  \\   /   #\n");
	printf("	,--. |  | # |  .--'  #  \\ |  | |  |# |  .___.' #  |  .-.  | # |  .  '.' # |  |   / : # |   /  /\\_  #\n");
	printf("	|  '-'  / # |  `---. #   `'  '-'  '# |  |      #  |  | |  | # |  |\\  \\  # |  '--'  / # `-./  /.__) #\n");
	printf("	 `-----'  ## `------' ##     `-----' ## `--'      ##  `--' `--' ## `--' '--' ## `-------'  ##   `--'      ##\n\n");
	printf("INSTRUCCIONES: Bienvenido a Jeopardy. \nA continuacion se presentaran 25 preguntas acerca de historia, cultura general, peliculas, musica y deportes; en cada una de estas preguntas tendran 4 opciones que senalaran colocando numeros del 1-4, al colocar la respuesta correcta, se les sumara el puntaje asignado a esa pregunta, en cambio, si responden de manera incorrecta, se les restaran esos puntos.\nPara elegir cada una de las preguntas segun la categoria simplemente tienen que colocar un numero del 1-25, una vez que hayan colocado el numero de una pregunta, no la podran volver a colocar.\nA la mitad del juego se les preguntara si les gustaria continuar con ese juego o si les gustaria iniciar de nuevo, al iniciar de nuevo, se reiniciaran tanto las preguntas como los puntajes de los jugadores. Al finalizar se les mostraran los puntajes de cada uno de los jugadores. Para seleccionar quien es el jugador 1 y quien el jugador 2, pueden jugar un piedra, papel o tijera; o lanzar una moneda para elegir al azar.\nAhora que conoces como funciona el juego, puedes iniciar. Disfruta! \n\n");
}


int main() {
	imprimir();
	char jf1[20],jf2[20];
	printf("Jugador 1, ingrese su nombre\n");
	scanf("%s",&jf1);
	printf("Jugador 2, ingrese su nombre\n");
	scanf("%s",&jf2);
    Pregunta preguntas[NUM_PREGUNTAS];
    int puntajes[2] = {0, 0};
    int jugador = 0;
    int pregunta_actual = 0;
    int respuesta;
    int opcion;
	char matriz[5][5];
    char categorias[NUM_CATEGORIAS][50] = {"Historia Mundial", "Musica", "Peliculas", "Cultura General", "Deportes"};
        int i, j, pregunta, fila, columna;
	int A[5][5]; int con,num,f,f1=0;
	int fd1=0,fd2=5,fd3=10,fd4=15,fd5=20,c=0, a[26];
	int ans, sumj1=0, sumj2=0,valr1=0, puntr1=0;

    srand(time(NULL));
    cargar_preguntas(preguntas);
	generar_matriz1(A);
	imprimir_matriz1(A);
	generar_vector(a);
    // Inicializar matriz con nÃƒÂºmeros de pregunta
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            matriz[i][j] = '0' + i * 5 + j + 1;
        }
    }

    // Jugar
    while(f1<25) {
    	  	
    	if(jugador==0){
    	printf("%s, escoja una pregunta (1-25): ",jf1);  //Jugador 1
        scanf("%d", &pregunta);
		}
		else if(jugador==1){
    	printf("%s, escoja una pregunta (1-25): ",jf2);
        scanf("%d", &pregunta);
		} 

		
    comprobar1(A,pregunta);   
        
        
        fila = (pregunta - 1) / 5;
        columna = (pregunta - 1) % 5;

        if(matriz[fila][columna] == 'X') {
            printf("Esa pregunta ya ha sido usada. Por favor, escoja otra.\n");
            continue;
        }
        if(pregunta<=0 || pregunta>=26){
           	printf("Esa pregunta no se encuentra disponible. Por favor, escoja otra.\n");
           	continue;
		}        
        
		if (pregunta>=1 && pregunta<=5){		//valor de pregunta aleatorio		
				fd1++;
				pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
			}
		if (pregunta>=6 && pregunta<=10){		//valor de pregunta aleatorio		
				fd2++;
				pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
			}
		if (pregunta>=11 && pregunta<=15){		//valor de pregunta aleatorio		
				fd3++;
				pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
			}
		if (pregunta>=16 && pregunta<=20){		//valor de pregunta aleatorio		
				fd4++;
				pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
			}
		if (pregunta>=21 && pregunta<=25){		//valor de pregunta aleatorio		
				fd5++;
				pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
			}
		       
		
        matriz[fila][columna] = 'X';

        printf("Pregunta:\n");
        printf("%s por %d puntos:\n", preguntas[pregunta - 1].categoria, preguntas[pregunta - 1].valor);
        printf("%s\n", preguntas[pregunta - 1].pregunta);
        printf("1. %s\n", preguntas[pregunta - 1].respuestas[0]);
        printf("2. %s\n", preguntas[pregunta - 1].respuestas[1]);
        printf("3. %s\n", preguntas[pregunta - 1].respuestas[2]);
        printf("4. %s\n", preguntas[pregunta - 1].respuestas[3]);
        
        
        valr1=valr_pregun(pregunta), puntr1=puntr_pregun(pregunta);    //valores segÃƒÂºn el nÃƒÂºmero de pregunta   
		//printf("El valor de respuestas es %d\n",valr1);
    
		printf("Ingrese su respuesta (1-4): ");
        scanf("%d", &ans);
        	
        if(ans == valr1) {
            printf("Respuesta correcta! Suma %d puntos.\n", puntr1);		
            if(jugador==0){
            	sumj1=sumj1+puntr1;
			}
            if(jugador==1){
            	sumj2=sumj2+puntr1;
			}			
        } 
		else {
            printf("Respuesta incorrecta! Resta %d puntos.\n", puntr1);
            if(jugador==0){
            	sumj1=sumj1-puntr1;
			}
            if(jugador==1){
            	sumj2=sumj2-puntr1;
			}
        }       



        if(pregunta_actual == NUM_PREGUNTAS/2) {
            printf("Llegamos a la mitad del juego. Desean repetir? (1 = Si, 0 = No): ");
            scanf("%d", &opcion);

            if(opcion == 1) {						//Reiniciar todo el juego
            	opcion=0;
            	puntajes[jugador=1]=0;
                puntajes[jugador=0]=0;  
				sumj1=0, sumj2=0; 
				f1=0;   
				fd1=0,fd2=5,fd3=10,fd4=15,fd5=20,c=0;          
                printf("%s: %d puntos\n",jf1, puntajes[0]);
    			printf("%s: %d puntos\n",jf2, puntajes[1]);
    			
            	generar_matriz1(A);
            	imprimir_matriz1(A);
            	generar_vector(a);
                pregunta_actual = 0;
                
    			jugador=0;
    					for(i = 0; i < 5; i++) {
        					for(j = 0; j < 5; j++) {
          					  matriz[i][j] = '0' + i * 5 + j + 1;
      					  }
  					  }
                printf("%s, escoja una pregunta (1-25): ",jf1);
        		scanf("%d", &pregunta);
           				 comprobar1(A,pregunta);   
        				
        
           				 fila = (pregunta - 1) / 5;
           				 columna = (pregunta - 1) % 5;

           				 if(matriz[fila][columna] == 'X') {
           				     printf("Esa pregunta ya ha sido usada. Por favor, escoja otra.\n");
           				     continue;
           				 }
           				 if(pregunta<=0 || pregunta>=26){
           				 	printf("Esa pregunta no se encuentra disponible. Por favor, escoja otra.\n");
           				    continue;
							}
		
						if (pregunta>=1 && pregunta<=5){		//valor de pregunta aleatorio		
								fd1++;
								pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
							}
						if (pregunta>=6 && pregunta<=10){		//valor de pregunta aleatorio		
								fd2++;
								pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
							}
						if (pregunta>=11 && pregunta<=15){		//valor de pregunta aleatorio		
								fd3++;
								pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
							}
						if (pregunta>=16 && pregunta<=20){		//valor de pregunta aleatorio		
								fd4++;
								pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
							}
						if (pregunta>=21 && pregunta<=25){		//valor de pregunta aleatorio		
								fd5++;
								pregunta=preg_aleatoria1(pregunta, fd1,fd2,fd3,fd4,fd5,a); 
							}
		       
		
       			 matriz[fila][columna] = 'X';

        			printf("Pregunta:\n");
        			printf("%s por %d puntos:\n", preguntas[pregunta - 1].categoria, preguntas[pregunta - 1].valor);
        			printf("%s\n", preguntas[pregunta - 1].pregunta);
        			printf("1. %s\n", preguntas[pregunta - 1].respuestas[0]);
        			printf("2. %s\n", preguntas[pregunta - 1].respuestas[1]);
        			printf("3. %s\n", preguntas[pregunta - 1].respuestas[2]);
        			printf("4. %s\n", preguntas[pregunta - 1].respuestas[3]);
        
        
        			valr1=valr_pregun(pregunta), puntr1=puntr_pregun(pregunta);    //valores segÃƒÂºn el nÃƒÂºmero de pregunta   
					printf("El valor de respuestas es %d\n",valr1);
    
					printf("Ingrese su respuesta (1-4): ");
        			scanf("%d", &ans);
        	
        			if(ans == valr1) {
            			printf("Respuesta correcta! Suma %d puntos.\n", puntr1);		
            			if(jugador==0){
            				sumj1=sumj1+puntr1;
						}
            			if(jugador==1){
            				sumj2=sumj2+puntr1;
						}			
        			} 
					else {
            			printf("Respuesta incorrecta! Resta %d puntos.\n", puntr1);
            			if(jugador==0){
            				sumj1=sumj1-puntr1;
						}
            			if(jugador==1){
            				sumj2=sumj2-puntr1;
						}
			        }       

        pregunta_actual++;      		
            }
        }
        
        pregunta_actual++;
        
         imprimir_matriz1(A);
		f1++;
        jugador=(jugador+1) % 2;
    }

    printf("Juego terminado! El puntaje final es:\n");
    printf("%s: %d puntos\n",jf1, sumj1);
    printf("%s: %d puntos\n",jf2, sumj2);
    if(sumj1>sumj2){
    	printf("%s has GANADO\n",jf1);
	}
	else if(sumj1<sumj2){
    	printf("%s has GANADO\n",jf2);
	}
	else {
    	printf("%s y %s han EMPATADO\n",jf1,jf2);
	}				
	
	FILE *archivo1;
	archivo1 = fopen("Resultados.txt","w");	
	fprintf(archivo1, "Resultados del juego:\n");
fprintf(archivo1, "%s: %d puntos\n", jf1, sumj1);
fprintf(archivo1, "%s: %d puntos\n", jf2, sumj2);
	if (sumj1 > sumj2) {
    	fprintf(archivo1, "%s ha GANADO\n", jf1);
	} 
	else if (sumj1 < sumj2) {
    	fprintf(archivo1, "%s ha GANADO\n", jf2);
	} 
	else {
    	fprintf(archivo1, "%s y %s han EMPATADO\n", jf1, jf2);
	}

fclose(archivo1);

}

