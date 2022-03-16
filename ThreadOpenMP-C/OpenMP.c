#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(){
    // Declarando variáveis
    int Threads = 4;
    int buff[10];
    srand(time(NULL));
    // Iniciando programação paralela
        #pragma omp parallel num_threads(Threads)
        {
                    int i;
                    int counter=0;
                    if(omp_get_thread_num()%2 == 0 || omp_get_thread_num() == 0){    
                        #pragma for critical
                        for(i=0;i<5;i++){
                                buff[counter++] = rand()%100;
                            // printf("buff[%i], %i, %i\n",counter,buff[counter],omp_get_thread_num());
                        }
                    printf("Número %i obtido pela thread %i\n",buff[counter],omp_get_thread_num());
                    }else{
                        #pragma for critical 
                        for(i=0;i<5;i++){
                            if(counter == 0) break;
                            else
                                buff[counter--] = -1;
                                // printf("\tbuff[%i], %i, %i\n",counter,buff[counter+1],omp_get_thread_num());
                        }            
                    printf("\tNúmero %i obtido pela thread %i\n",buff[counter],omp_get_thread_num());
                    }
        }
return 0;
}
