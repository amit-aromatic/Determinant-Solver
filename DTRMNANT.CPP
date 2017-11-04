/*PROGRAM TO FIND DETERMINANT OF MAX. ORDER 80*/
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include"graphics.cpp"

void main()
{
float a[80][80],d[80][80];
int i,j,k,n,m,c,e,flag=0;
float p=1.0;
win err(25,10,55,20,LIGHTGREEN);

again:
window(1,1,80,25);//to resize to screen from error window.
clrscr();
printf("                        DETERMINANT EVALUATOR \n");
for(i=0;i<80;i++)
printf("Ä");


/**************************** for test purpose ****************************/

m=80; n=80;
float temp=1;
for( i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  a[i][j]=(temp+=0.01);
 }

/***************************** input ***************************************/

printf("\nEnter order of the determinant :");
scanf("%d",&n);
m=n;

if(m<1){ err.text("\nERROR! Order should be at \n\r\least one.\n\n\n\n\r\Press any key to\n\r\continue...");
	 err.draw();     getch();
	 goto again;
	 }

	 clrscr();

//	 printf("Enter elements:\n");

for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
  gotoxy(1,i); printf("³");
  gotoxy(9*n,i); printf("³");
}
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{

gotoxy(8*(j+1),(i+1));
//printf("Enter element a%d %d:",i+1,j+1);
scanf("%f",&a[i][j]);
}
}


/*printf("1");getch();/**/
/**************************** acknowledgement ***************************/
printf("\nThe deteminant entered is:\n\n");
for(i=0;i<n;i++)
{
printf("³");
for(j=0;j<n;j++)
{
printf("%8g",a[i][j]);
}
printf("³\n");
}
//printf("2");getch();/**/
/**************************** dummy creation ****************************/
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)          //the lines with /**/ are 4 checking.not reqd. for
		       //program
{
d[i][j]=a[i][j];
}
}
/*//check1
printf("\nd:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%8g ",d[i][j]);
}
printf("\n");
}
printf("3");getch();  /**/
/****************************** calculation begins *************************/
for(k=1;k<m;k++)
{
if(d[0][0]==0)
{
for(c=0;c<m;c++)
{
if(d[0][c]!=0){flag=1;break;}}
if(flag==0){printf("\nThe result is : 0");goto end;}
else {for(e=0;e<m;e++)
       {
       d[e][0]+=d[e][c];
       }
      }
/*	     printf("\nnew:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%8g ",d[i][j]);
}
printf("\n");
}
printf("howzatt!");getch();  /**/
}

p*=pow(d[0][0],(n-2));//printf("P:%g",p);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
 if(i==n-1||j==n-1){
		    a[i][j]=0;
		   }
 else{
      a[i][j]=d[0][0]*d[i+1][j+1]-d[i+1][0]*d[0][j+1];
     }
}
}
/*//check2
printf("\na:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%8g ",a[i][j]);
}
printf("\n");
}  */
/******************************* dummy redefination ***********************/
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
d[i][j]=a[i][j];
}
}
/*//check3
printf("\nd:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%8g ",d[i][j]);
}
printf("\n");
} */
n--;
};       //calculation finishes/**/
/*//check4
printf("\nd:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %8g ",d[i][j]);
}
printf("\n");
}
printf("5");getch(); */


//output
printf("\nAnd the result is=%8g",d[0][0]/p);
end:
getch();
cbab();
}
