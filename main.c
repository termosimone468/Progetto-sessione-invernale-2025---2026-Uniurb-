/************************************************************************************/
/* Prova progettuale di programmazione procedurale, sessione invernale 2025 / 2026 
s  A cura di Gianluca Cognome e Pietro Leone
   Università degli studi di Urbino Carlo Bò
   [Work in progress!]
                                                                                    */
/************************************************************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************/
/* definizione dei prototipi di funzione */
/*****************************************/


int controllo_alfanumerico(char *data);                             /*Procedura atta a verificare la sola presenza di caratteri numerici e '/' */

int conversione_numerica(int *giorni,                               
                         int *mesi,
                         int *anni,
                         char *data);

int valida_data(char *data, 
                int*giorni, 
                int *mesi, 
                int *anni);                                         /*Procedura che si occupa di combinare entrambi i controlli, in modo da segnalare gli errori in ogni caso, per educare l'utento al corretto utilizzo del software */               
int isBisestile(int anno);                                          /*Procedura per controllare se un dato anno è bisestile o meno */   

int main(){
    
/* dichiarazione delle variabili locali alla funzione */

  char prima_data[11],                  /*Input: buffer per la prima data   */                                
       seconda_data[11];                /*Input: buffer per la seconda data */
  
  int giorni_primaData,                 /*Lavoro: giorni del mese della prima data espressi in forma numerica*/
      mesi_primaData,                   /*Lavoro: numero del mese specificato, in forma numerica */ 
      anni_primaData,                   /*Lavoro: anno della prima data, espresso in forma numerica */
      giorni_secondaData,               /*Lavoro: giorni del mese della seconda data, espressi in forma numerica*/
      mesi_secondaData,                 /*Lavoro: numero del mese della seconda data, espresso in forma numerica*/
      anni_secondaData;                 /*Lavoro: anno della seconda data, espresso in forma numerica*/
  
  
 
 /*inserimento e controllo della prima data inputata*/
 do{
    
    printf("[>]Inserire la prima data, compresa tra il 01/01/2000 e il 12/12/2025 [formato: gg/mm/aaaa]: \n");
    scanf("%s", 
          prima_data);
 }while(valida_data(prima_data, &giorni_primaData, &mesi_primaData, &anni_primaData) == 1);
 
 /*Inserimento e controllo della seconda data inputata*/
 do{
    
    printf("[>]Inserire la seconda data, compresa tra il 01/01/2000 e il 12/12/2025 [formato: gg/mm/aaaa]: \n");
    scanf("%10s", 
          seconda_data);
    
 }while(valida_data(seconda_data, &giorni_secondaData, &mesi_secondaData, &anni_secondaData) == 1); 
 
 printf("\n(DEBUG) Date validate: %d/%d/%d , %d/%d/%d", giorni_primaData, mesi_primaData, anni_primaData, giorni_secondaData, mesi_secondaData, anni_secondaData);
 return 0;
}




int conversione_numerica(int *giorni,                                                                          /*Procedura dedicata alla conversione numerica della data in input e il controllo dei valori ottenuti */
                         int *mesi,
                         int *anni,
                         char *data){
                             
    int valori_mesi[] = {0, 31 , 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};                         /*Lavoro: array locale che per ogni mese, specifica quanti giorni sono necessari per arrivarci (Esempio: per dicembre occorrono 334 giorni) */
    *giorni = atoi(data);                                                                                      /*Conversione dei giorni*/          
    *mesi = atoi(data + 3);                                                                                    /*Conversione dei mesi*/
    *anni = atoi(data + 6);                                                                                    /*Conversione degli anni*/
    valori_mesi[2] = valori_mesi[2] + isBisestile(*anni);                                                      /*Aumento dei giorni consentiti del mese di febbraio in caso di anno bisestile*/
    
    if ((*giorni < 1) || (*giorni > 31) || (*mesi < 1) || (*mesi > 12) || (*anni < 2000) || (*anni > 2025)){   /*Controllo sulla corretta dei valori ricavati*/
     
      printf("Errore: data non valida, \n\n");
      return 1;
      
    }else{
     
      if (*giorni + valori_mesi[*mesi - 1] > valori_mesi[*mesi] ){                                             /*Controllo sul numero di giorni rispetto al mese indicato, avvalendosi dell'array di accumulazione*/
        printf("Errore: numero incorretto di giorni rispetto il mese specificato\n\n");
        return 1;
      }
    }
    
    return 0;
}


int valida_data(char *data, int *giorni, int *mesi, int *anni){                                               /*Procedura atta a combinare tutti i controlli*/
  int s;   
  s = controllo_alfanumerico(data);
  if (s == 0){
      s = s + conversione_numerica(giorni, mesi, anni, data);
  }else{
    return 1;
  }
  return s;
}


int controllo_alfanumerico(char *data){                                                                      /*Procedura atta a verificare la sola presenza di numeri o '/' bella stringa inputata*/
    int i = 0;
    while(data[i]!= '\0'){
      if((data[i] < 47)||(data[i] > 57)){
        printf("Errore di formato: la data non può contenere lettere \n\n");
        return 1;
      }
      i++;
    }
    return 0;
    }

int isBisestile(int anno){

  if(((anno%4)==0)||((anno%100)==0)){
      return 1;
  }else{
      return 0;
  }

}

