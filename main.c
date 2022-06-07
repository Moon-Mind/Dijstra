#include<stdio.h>
#include<stdlib.h>
#define INIFINITY 999



void dijkstra(int** c_matrix, int *pred, int *d,int v0,int v_num);
int getMindDist(int** c_matrix,int *visited,int v_num,int *d,int* pred);
void ausgabe_matrix(int** adj_matrix,int anzahl);
int getMintDist_advanced(int start,int** conections,int knoten,int* besucht,int* knoten_gewichte);
void ausgabe_weight_matrix(int** adj_matrix,int anzahl);


int main(void)
{
    int kanten,knoten;
    int v0=0; //start knoten
    int v_num; //knoten
    int count=0;

    kanten=7;
    knoten=5;


    int *d=(int*)calloc(knoten,sizeof(int*));

    int **adj_matrix = (int**)calloc(knoten,sizeof(int*));    //speicherreserveirung 
    for (int o = 0; o < knoten; o++) {                  //Speicherreservierungsloop da 2d Matrix
        adj_matrix[o] = (int**)calloc(knoten, sizeof(int*));
    }
    
    int **c_matrix = (int**)calloc(knoten,sizeof(int*));    //speicherreserveirung 
    for (int o = 0; o < knoten; o++) {                  //Speicherreservierungsloop da 2d Matrix
        c_matrix[o] = (int**)calloc(knoten, sizeof(int*));
    }
    
    int *pred = (int**)calloc(knoten,sizeof(int*));    //speicherreserveirung 
    for (int o = 0; o < knoten; o++) {                  //Speicherreservierungsloop da 2d Matrix
        c_matrix[o] = (int**)calloc(knoten, sizeof(int*));
    }

    //form a to b


    c_matrix[0][1]=100;
    c_matrix[0][3]=50;
    c_matrix[1][4]=250;
    c_matrix[1][2]=100;
    c_matrix[2][4]=50;
    c_matrix[3][1]=100;
    c_matrix[3][4]=250;
    //create arrays
    for (int i = 0; i < knoten; i++)
    {
       for (int g = 0; g < knoten; g++)
       {
           if (c_matrix[i][g]>0)
           {

              d[count]=c_matrix[i][g];
              //printf("%d\n",d[count]);
              //adj_matrix[i][g]=1;
              count+=1;

           }
           
       }
       
    }

    
    ausgabe_matrix(c_matrix,knoten);
    printf("\n");
    ausgabe_weight_matrix(c_matrix,knoten);
    
    dijkstra(c_matrix, pred, d,v0,knoten);

    return(0);
}



void dijkstra(int** c_matrix, int *pred, int *d,int v0,int v_num){
    int u=v0; //knoten mit der nidrigsten kanten gewicht
    int z=4; //ziel
    int count=0; //zähler

    //speicher initalisieren
    int *visited= (int*)calloc(v_num,sizeof(int*));

    //initalisiert alle mit unendlich
    for (int i = 0; i < v_num; i++)
    {
        pred[i]=INIFINITY;
    }
    
    //startwert
    visited[v0]=1;//startwert wird in beuscht eingetragen
    d[v0]=0;
    pred[v0]=0;

    for (int i = 0; i < count; i++)
    {
        //u=getMindDist(c_matrix,visited,v_num,d,pred);
        u=getMintDist_advanced(visited[i],c_matrix,v_num,visited ,d);
        visited[u]=1;//setzt kürztest stecke auf besucht
        count+=1;
    }
    

    for (int i = 0; i < v_num; i++)
    {
        //printf("%d \n",z);
        //z=pred[z];
        printf("Gewicht :%d Vorgänger: %d \n",d[i],pred[i]);
        
    }    
}

int getMintDist_advanced(int start,int** conections,int knoten,int* besucht,int* knoten_gewichte){
    for (int i = 0; i < knoten; i++)
    {
        //diagonal
        if(besucht[i]==0&&conections[start][i]!=0){
            if (conections[start][i]<knoten_gewichte[i])
            {
                
            }
            

            

        }
        //vertical
        if(besucht[i]==0&&conections[i][start]!=0){
        }
    }
    
}


void ausgabe_matrix(int** array,int anzahl)
{
    int n=0;

    for (int i = 0; i < anzahl; i++) //add first row from 1 to eingabe
    {
        printf(" %d ",i+1);
    }


    for (int i = 0; i < anzahl; i++)    //Prints matrix
    {
        printf("\n%i",i+1);
        for (int j = 0; j < anzahl; j++)
        {
			if (array[i][j]<1)
			{
				printf("|%d|", 1);
			}else{
				printf("|%d|", 0);
			}

 
        }

    }

}

void ausgabe_weight_matrix(int** array,int anzahl)
{
    int n=0;

    for (int i = 0; i < anzahl; i++) //add first row from 1 to eingabe
    {
        printf(" %d ",i+1);
    }


    for (int i = 0; i < anzahl; i++)    //Prints matrix
    {
        printf("\n%i",i+1);
        for (int j = 0; j < anzahl; j++)
        {
                printf("|%d|", array[i][j]);
        }

    }

}

