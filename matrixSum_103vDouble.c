#include <stdio.h>
#include <stdlib.h>
//#include <sys/time.h>
#include <time.h>


// -------------------------------------------------------------------------------
// --------------------------------------------double-----------------------------------
void SumMatv1d(int n, double* A) { //JI
    int i, j, k;
    double sum=0.0;
    /* This is ijk loop order. */
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++) {
            sum+= A[ j*n +  i ]; // sum+= A[j][i]  (a)Version 
        }
        
       //printf( "%3.4f " , sum);
}

void SumMatv2d(int n, double* A) { //IJ
    int i, j, k;
    double sum=0.0;
    /* This is ijk loop order. */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            sum+= A[j*n +i]; // sum+= A[i][j]  (b)Version 
        }
      //printf( "%3.4f " , sum);
}
 
void SumMatv3d(int n, double* A) { 
    int i, j, k;
    double sum=0.0;
    /* This is ijk loop order. */
  for (j = 0; j < n; j=j+2)
        for (i = 0; i < n; i=i+2) {
            sum+= A[(j)*n + (i)] + A[(j+1)*n + (i)] + A[(j)*n + (i+1)] + A[(j+1)*n + (i+1)]  ; // sum+= A[i][j] + A[i][j+1] + A[i+1][j] +A[i+1][j+1] (c)Version 
        }
      // printf( "%3.4f " , sum);
}

void SumMatv4d(int n, double* A) { 
    int i, j, k;
    double sum=0.0;
    /* This is ijk loop order. */
  for (i = 0; i < n; i=i+2)
        for (j = 0; j < n; j=j+2) {
            sum+= A[(j)*n + (i)] + A[(j+1)*n + (i)] + A[(j)*n + (i+1)] + A[(j+1)*n + (i+1)]  ; // sum+= A[i][j] + A[i][j+1] + A[i+1][j] +A[i+1][j+1] (d)Version 
        }
       // printf( "%3.4f " , sum);
}

//****************************************************************************************************/

int main(int argc, char *argv[]) {
    
  //  int n= argv[1];
  
    
if (argv[1]) {


  //printf( " input arg = %s " , argv[1]);
  int n= atoi(argv[1]);
//printf( " input n = %d " , n);
  int samples=50;

    double* A = (double*)malloc(n * n* sizeof(double));

    //struct timeval start, end;

    printf("version              n    time(s)  Normalized(ns)\n");

        
    for (int i = 0; i < n * n; i++) A[i] = 1;//;
    
    
  for(int s=0;s<samples;s++){
            // Start measuring time
            clock_t start = clock();
            SumMatv4d(n, A);     //select multMatv1, multMatv2, multMatv3, multMatv4
            // Stop measuring time and calculate the elapsed time
            clock_t end = clock();

           double seconds = (double)(end - start) / CLOCKS_PER_SEC;
           double N = n;
           double timeNormalized = (seconds * 1.0e9) / (N * N ); //ns
 
           printf( "%s\t   %05d  %2.4f   %2.4f \n" , "ver4d_local ", n, seconds, timeNormalized);

}
   free(A);
}
    printf("\n");

    return 0;
}
