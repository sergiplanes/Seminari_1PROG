/* 
 * Grup de Seminari: S205
 * Professor seminari: Dolors Sala
 * Nom Fitxer: FP-S205-6-Ez-18373-Planes-Sergi.c
 * Seminari: 6
 * Incidències:
 * 
 * Autor (Nom i NIA): Sergi Planes 183713
 * Data/hora: 14:15
 * Collaboradors (si cal):
 * 
 * Número problema: 15
 * Enunciat Problema:
 * 
 * En un fitxer estudiants.txt tenim les dades dels estudiants de Fonaments de la Programació. Cada estudiant apareix a una línia
 * diferent i segueix el següent format:
 * nom nia nota
 * on nom és una paraula de com a màxim 50 caràcters, nia és un nombre enter i nota un nombre real. Noteu que estan separats per
 * un caràcter en blanc. Escriviu un programa que calculi la nota mitjana i que indiqui quin ha estat l’estudiant amb una nota més alta
 * i quina nota ha obtingut. 
 * 
 * Ús del programa:
 * Estat de l'entrega:
 * Altres comentaris o incidències:
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50 //Maxims caracters per el nom.

int main(int argc, char**argv) {
  
    int nia;        //NIA numeric per cada alumne, identificador unic.
    float nota;     //Nota numerica del alumne
    char nom[N];    //Nom del alumne, maxim 49 caracters
    int alumnes;    //Contador.
    float notamitja; //contenidor de la nota mitjana.
    
      //Varibale del tipos salumne.
    
    FILE * f;       //Declarem el tipus fitxer.
    
    typedef struct {  //Structura del tipos salumne, per guardar tota la info del alumne.
        char nom[N];
        int nia;
        float nota;
    }salumne;
    
    salumne maxalumne;   //Declarem la variable del tipus salumne, per que sigui el contenidor de (nom,nia,nota)
    
    f=fopen("estudiants.txt","r");   //Obrim el fitxer "estudiants.txt" dins el punter de tipos fitxer f.
    
        if(f==NULL){                    //Aquesa clausula if, es per comprovar si el fitxer "estudiants.txt"
            printf("ERROR \n");         //te algun coningut o si el programa el carrega correctament.
            printf("Revisa el fitxer estudiants.txt");

            return 0;
        }
    while(!feof(f)){ //anirem guardantles dades sempre que no arrivem al final del fitxer.
    
        fscanf(f,"%s %d %f \m", nom, &nia, &nota); //guardem el contingut del fitxer en les variables creades anteriorment
        notamitja+=nota;                           //calculem la mitjana aritmetica del alumne.
                                        
        
        if(maxalumne.nota<nota){                   //Comprovem si la nota guardada en la nostra estructura es menor o major a la nota que hem agafat del fitxer
                                                   //de tal forma que si es menor entrara en el if, y aleshores la nota i el nia de la major nota es quedara guardada dins el contenidor "salumne" 
            maxalumne.nota=nota;                    
            maxalumne.nia=nia;
            
        }
        alumnes++;                                 //incrementem el contador.
    }
    notamitja/alumnes;                              //Convertim notamitjana, que fins ara nomes tenia notes(raw) a finalment la nota mitjana amb el contador que ha anat incrementatn per cada alumne.
    
    printf("El alumne amb la nota mes alta es: %d  amb una nota numerica: %d" , maxalumne.nia,maxalumne.nota);
    
    fclose(f);
    return 0;
}
