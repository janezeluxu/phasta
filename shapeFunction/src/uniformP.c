#include "shapeFuncInternals.h"
#include <math.h>
#include <stdio.h>  
#ifdef __cplusplus
extern "C" {
#endif

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

  /* Calculate shape functions and derivative for tet elements */
int TetShapeAndDrv(int p,double par[3],double N[],double dN[][3]) {
  int i,j,nshp=0;
  double L[4];
  if(p<1)
    return nshp;
  L[0]=par[0];
  L[1]=par[1];
  L[2]=par[2];
  L[3]=1.0e0-par[0]-par[1]-par[2];
  
  if (p==1) {
	  printf("tetp1 = %d\n", p);
    for(i=0; i <4; i++) {
    N[i] = L[i];
    if(i==3) 
      dN[i][0]=dN[i][1]=dN[i][2]=-1.0e0;
    else {
      for(j=0; j <3; j++) {
	if(i==j)
	  dN[i][j] = 1.0e0;
	else
	  dN[i][j] = 0.0e0;
      }
    }
  }
  nshp=4;
  return nshp;
}
  if (p>1){
  int a[10][4];
  
  printf("tetp2 = %d\n", p);

  for (i=0; i<10; i++){
    for (j=0; j<4; j++)
    {
      a[i][j]=0;
    }
  }
  a[0][0]=2;a[1][1]=2;a[2][2]=2;a[3][3]=2;
  a[4][0]=1;a[4][2]=1;a[5][1]=1;a[5][2]=1;
  a[6][0]=1;a[6][1]=1;a[7][0]=1;a[7][3]=1;
  a[8][2]=1;a[8][3]=1;a[9][1]=1;a[9][3]=1;
  //printf("a[9][0]%d\n", a[9][0]); 
  
  
  /* collect all vertex modes */
  for(i=0; i <10; i++) {
          //printf("factorial%f, i=%d\n", factorial(a[i][0]),i);
          int tmp0 = a[i][0];
          int fac0 = factorial(tmp0);
          int tmp1 = a[i][1];
          int fac1 = factorial(tmp1);
          int tmp2 = a[i][2];
          int fac2 = factorial(tmp2);
          int tmp3 = a[i][3];
          int fac3 = factorial(tmp3);

          //printf("tmp = %d,fac = %d, i=%d\n",tmp0, fac0,i);

	  double coef = 2.0/(fac0*fac1*fac2*fac3);
	  //printf("coef%f, i = %d\n", coef,i); 
	  N[i] = coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*pow(L[2],a[i][2])*pow(L[3],a[i][3]);
	  //printf("shapefunction%f\n", N[i]); 
	  dN[i][0] = coef*a[i][0]*pow(L[0],a[i][0]-1)*pow(L[1],a[i][1])*pow(L[2],a[i][2])*pow(L[3],a[i][3])\
					-coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*pow(L[2],a[i][2])*a[i][3]*pow(L[3],a[i][3]-1);
	  dN[i][1] = coef*pow(L[0],a[i][0])*a[i][1]*pow(L[1],a[i][1]-1)*pow(L[2],a[i][2])*pow(L[3],a[i][3])\
					-coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*pow(L[2],a[i][2])*a[i][3]*pow(L[3],a[i][3]-1);			
	  dN[i][2] = coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*a[i][2]*pow(L[2],a[i][2]-1)*pow(L[3],a[i][3])\
					-coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*pow(L[2],a[i][2])*a[i][3]*pow(L[3],a[i][3]-1);
      	  //printf("shapefunctionDiv%f\n", dN[i][0]);

  }
  nshp=10;
  return nshp;
}
}

/* calculate the shape functions and their derivatives for
   triangular faces
   */

int TriShapeAndDrv(int p,double par[2],double N[],double dN[][2]){
  int i,j,nshp=0;
  double L[3];
  
  if(p<1)
    return nshp;
    
  L[0]=par[0];
  L[1]=par[1];
  L[2]=1.0e0-par[0]-par[1];
    
   if(p==1) {
	   printf("Trip = %d\n", p);
      for(i=0; i<3; i++) {
    N[i] = L[i];
    if(i==2)
      dN[i][0]=dN[i][1]=-1.0e0;
    else {
      for(j=0; j<2; j++) {
	if(i==j)
	  dN[i][j] = 1.0e0;
	else
	  dN[i][j] = 0.0e0;
      }
    }
  }
  nshp=3;
  return nshp;
}
if(p>1) {
	printf("Trip = %d\n", p);
    int a[6][3];
  
  for (i=0; i<6; i++)
    for (j=0; j<3; j++)
    {
      a[i][j]=0;
    }

  a[0][0]=2;a[1][1]=2;a[2][2]=2;
  a[3][0]=1;a[3][2]=1;a[4][1]=1;a[4][2]=1;
  a[5][0]=1;a[5][1]=1;
  //std::cout <<" a[0][] "<<a[0][0]<< '\n';
  
  
  /* collect all vertex modes */
  for(i=0; i <6; i++) {
	  int tmp0 = a[i][0];
          int fac0 = factorial(tmp0);

          int tmp1 = a[i][1];
          int fac1 = factorial(tmp1);
          int tmp2 = a[i][2];
          int fac2 = factorial(tmp2);

          double coef = 2.0/(fac0*fac1*fac2);

	  //std::cout <<" coef of SF "<<coef<< '\n';
	  N[i] = coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*pow(L[2],a[i][2]);
	  //std::cout <<" SF "<<N[i]<< '\n';
	  dN[i][0] = coef*a[i][0]*pow(L[0],a[i][0]-1)*pow(L[1],a[i][1])*pow(L[2],a[i][2])\
					-coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*a[i][2]*pow(L[2],a[i][2]-1);
	  dN[i][1] = coef*pow(L[0],a[i][0])*a[i][1]*pow(L[1],a[i][1]-1)*pow(L[2],a[i][2])\
					-coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*a[i][2]*pow(L[2],a[i][2]-1);			
	  dN[i][2] = coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*a[i][2]*pow(L[2],a[i][2]-1)\
					-coef*pow(L[0],a[i][0])*pow(L[1],a[i][1])*a[i][2]*pow(L[2],a[i][2]-1);
  }
  nshp=6;
  return nshp;
}
}
    
    
  
  


#ifdef __cplusplus
}
#endif

