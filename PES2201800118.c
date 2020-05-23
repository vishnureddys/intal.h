/*
Author: Vishnu S Reddy
SRN: PES2201800118
Class and Section: 4th semester EC campus B section.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

//Addition function that I have added
static char* addZeros(char* intal1, char* intal2)
{
    int a=strlen(intal1),b=strlen(intal2),k;
    char* intal=(char*)malloc(sizeof(char)*(a+1));
    for(k=0;k<(a-b);k++)
        intal[k]='0';
    for(;k<a;k++)
        intal[k]=intal2[k-(a-b)];
    intal[k]='\0';
    return intal;
}


//Addition function that I have added
static char* intalToStr(char* intal)
{
    char *temp=(char*)malloc(10000);
    while(intal[0]=='0')
        intal++;
    if(strlen(intal)==0)  
        strcpy(temp,"0");
    else
        strcpy(temp,intal);
    return temp;
}

//This is the function to add two intals.
char* intal_add(const char* intal1, const char* intal2)
{
    int i,j,c,n;
    char *tmp1=(char*)malloc(strlen(intal1)+1);//This is add the terminating characters at the end
    char *tmp2=(char*)malloc(strlen(intal2)+1);//This is add the terminating characters at the end
    strcpy(tmp1,intal1);
    strcpy(tmp2,intal2);
    char *temp1=tmp1; 
    char *temp2=tmp2;
    tmp1=intalToStr(tmp1);
    tmp2=intalToStr(tmp2);
    free(temp1);
    free(temp2);
    i=strlen(tmp1); 
    j=strlen(tmp2);
    char *sol,*a1,*a2;
    if(i>j)
    {
        a2=addZeros(tmp1,tmp2);
        a1=tmp1;
        n=i;
    }
    else if(j>i)
    {
        a2=addZeros(tmp2,tmp1);
        a1=tmp2;
        n=j;
    }
    else
    {
        a1=tmp1,a2=tmp2;
        n=i;
    }
    sol=(char*)malloc(n+2);
    c=0,i=n+1;
    for(n=n-1;n>=1;n--)
    {
        int a=(a1[n]-'0')+(a2[n]-'0')+c;
        c=a/10;
        sol[n+1]=(a%10)+'0';
    }
    int a=(a1[n]-'0')+(a2[n]-'0')+c;
    sol[1]=(a%10)+'0';
    sol[0]=(a/10)+'0';
    sol[i]='\0';
    free(tmp1);
    free(tmp2);
    temp1=sol;
    sol=intalToStr(sol);
    free(temp1);
    return sol;
}

//This is the function to compare 2 intals, if they are equal then we get 0.
int intal_compare(const char* intal1, const char* intal2)
{
    char *a=(char*)malloc(strlen(intal1)+2);
    char *b=(char*)malloc(strlen(intal2)+2);
    strcpy(a,intal1);
    strcpy(b,intal2);
    char *tempa=a; 
    char *tempb=b;
    a=intalToStr(a);
    b=intalToStr(b);
    free(tempa);
    free(tempb);
    //First we compare the number of digits.
    //Based on the number of digits, we can remove further analysis and improve efficiency.
    if(strlen(a)>strlen(b))
    { 
        free(a);
        free(b);
        return 1;
    }
    else if(strlen(a)<strlen(b))
    {  
        free(a);
        free(b);
        return -1;
    }
    else
    {
        int i;
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]>b[i])
            {   
                free(a);
                free(b);
                return 1;
            }
            else if(a[i]<b[i])
            {  
                free(a);
                free(b);
                return -1;
            }
        }
        free(a);
        free(b);
        return 0;
    }
}

//This is the function to compute the abs value of difference between the 2 intals.
char* intal_diff(const char* intal1, const char* intal2)
{
    char *tmp1=(char*)malloc(strlen(intal1)+2);
    char *tmp2=(char*)malloc(strlen(intal2)+2);
    strcpy(tmp1,intal1);
    strcpy(tmp2,intal2);
    char *temp1=tmp1,*temp2=tmp2;
    tmp1=intalToStr(tmp1);
    tmp2=intalToStr(tmp2);
    free(temp1);
    free(temp2);
    char *t1,*t2,*solution;
    int i=strlen(tmp1);
    int c=intal_compare(tmp1,tmp2);
    if(c==1)
    {
        t1=tmp1;
        t2=addZeros(tmp1,tmp2);
    }
    else if(c==-1)
    {
        t1=tmp2;
        t2=addZeros(tmp2,tmp1);
    }
    else
    {    
        solution=(char*)malloc(2);
        strcpy(solution,"0");
        return solution;
    }

    solution=(char*)malloc(strlen(t1)+1);
    for(i=strlen(t1)-1;i>=0;i--)
    {
        int a;
        if(t1[i]>=t2[i])
        {  
            a=(t1[i]-'0')-(t2[i]-'0');
        }
        else
        {
            a=((t1[i]-'0')+10)-(t2[i]-'0');
            t1[i-1]--;
        }
        solution[i]=a+'0';
    }
    solution[strlen(t1)]='\0';
    free(tmp1);
    free(tmp2);
    free(t2);
    temp1=solution;
    solution=intalToStr(solution);
    return solution;
}

char* intal_multiply(const char* intal1, const char* intal2)
{
    char *a;
    char *b;
    int i,s,m,j;
    if(intal_compare(intal1, intal2) == 1)
    {
        a=(char*)malloc(strlen(intal1)+2);
        b=(char*)malloc(strlen(intal2)+2);
        strcpy(a,intal1);
        strcpy(b,intal2);
    }
    else
    {
        a=(char*)malloc(strlen(intal2)+2);
        b=(char*)malloc(strlen(intal1)+2);
        strcpy(a,intal2);
        strcpy(b,intal1);
    }
    int t1=strlen(a),t2=strlen(b);
    int *temp=(int*)malloc(sizeof(int)*(t1+t2));
    for(i=0;i<(t1+t2);i++)
        temp[i] = 0;
    for(i=t1-1;i>=0;i--)
    {
        for(j=t2-1;j>=0;j--)
        {
            int p1=i+j,p2=i+j+1;
            m=(a[i]-'0')*(b[j]-'0');
            s=m+temp[p2];
            temp[p1]+=(s/10);
            temp[p2]=(s%10);
        }
    }
    char *solution=(char*)malloc(t1+t2+1);
    for(i=0;i<(t1+t2);i++)
        solution[i]=temp[i]+'0';
    solution[i]='\0';
    free(a);
    free(b);
    free(temp);
    char *temp1=solution;
    solution=intalToStr(solution);
    free(temp1);
    return solution;
}

static char* appendChar(char* int1, char c)
{
    char* intal=(char*)malloc(strlen(int1)+2);
    int i;
    for(i=0;i<strlen(int1);i++)
        intal[i]=int1[i];
    intal[i]=c;
    intal[i + 1]='\0';
    return intal;
}

char* intal_mod(const char* intal1, const char* intal2)
{
    int a=strlen(intal1),ind=0;
    char *dmp=(char*)malloc(1000);
    strcpy(dmp,"0");
    while(ind<a)
    {
        char *tmp1; 
        char *tmp2;
        dmp=appendChar(dmp,intal1[ind]);
        tmp1=dmp;
        dmp=intalToStr(dmp);
        free(tmp1);
        ind++;
        while(ind<a && intal_compare(dmp,intal2)==-1)
        {
            dmp=strncat(dmp, &(intal1[ind]), 1);
            dmp=intalToStr(dmp);
            ind++;
        }
        if((intal_compare(intal2,dmp)==1) || (intal_compare(dmp,"0")==0))
            return dmp;
        char *i=(char*)malloc(sizeof(char)*3);
        strcpy(i,"0");
        char *tmp=(char*)malloc(sizeof(dmp));
        strcpy(tmp,"0");
        while(intal_compare(i,"11")==-1 && intal_compare(tmp,dmp) != 1 )
        {
            tmp1=i; 
            tmp2=tmp;
            i=intal_add(i,"1");
            tmp=intal_multiply(intal2,i);
            free(tmp1);
            free(tmp2);
        }
        tmp1=i;
        tmp2=tmp;
        i=intal_diff(i,"1");
        tmp=intal_multiply(intal2,i);
        free(tmp1);
        free(tmp2);
        tmp1=dmp;
        dmp=intal_diff(dmp, tmp);
        free(tmp1);
        free(i);
        free(tmp);
    }
    return dmp;
}

char* intal_pow(const char* intal1, unsigned int n)
{
    char* t = (char*)malloc(strlen(intal1)+1);
    strcpy(t,intal1);
    char* tmp1;
    if(intal_compare(t,"0")==0)
    {    
        tmp1=t;
        t=intalToStr(t);
        free(tmp1);
        return t;
    }
    if(n==0)
    {  
        strcpy(t,"1");
        return t;
    }
    char* p = intal_pow(intal1,n/2);
    char* m = intal_multiply(p,p);
    if(n%2==0)
    {
        free(t);
        free(p);
        return m;
    }
    else
    {
        tmp1=t;
        t=intal_multiply(intal1,m);
        free(tmp1);
        free(m);
        free(p);
        return t;
    }
}

char* intal_gcd(const char* intal1, const char* intal2)
{
    char* a1=(char*)malloc(strlen(intal1));
    char* a2=(char*)malloc(strlen(intal2));
    char* temp=(char*)malloc(1000);
    strcpy(a1,intal1);
    strcpy(a2,intal2);
    while(1)
    {
        if(intal_compare(a2,"0")==0)
        {
            return a1;
        }
        char* temp1=temp;
        temp=a2;
        free(temp1);
        a2=intal_mod(a1, a2);
        temp1=a1;
        a1=temp;
        free(temp1);
        temp=NULL;
    }
}

char* intal_fibonacci(unsigned int n)
{
    char *chr=(char*)malloc(sizeof(char)*10001);
    if(n==0)
    {  
        strcpy(chr,"0");    
        return chr;
    }
    else if(n==1)
    {
        strcpy(chr,"1"); 
        return chr;
    }
    char fst[10000]="0";
    char snd[10000]="1";
    n--;
    while(n--)
    {
        strcpy(chr,intal_add(fst,snd));
        strcpy(fst,snd);
        strcpy(snd,chr);
    }
    return chr;
}


//Addition function that I have added
static unsigned int numOfDigits(unsigned int n)
{
    unsigned int digits=0;
    while(n>0)
    {
        digits++;
        n/=10;
    }
    return digits;
}

char* intal_factorial(unsigned int n)
{
    char* a=(char*)malloc(sizeof(char)*10001);
    strcpy(a,"1");
    if(n==0)
    {
        return a;
    }
    int i;
    unsigned int digits=numOfDigits(n);
    char* ch=(char*)malloc(sizeof(char)*1000);
    for(i = digits - 1; i >= 0; i--)
    {
        ch[i]=n%10+'0'; 
        n/=10;
    }
    ch[digits]='\0';
    while(intal_compare(ch,"1")!=0)
    {
        char* temp1=a;
        char* temp2=ch;
        a=intal_multiply(a,ch);
        free(temp1);
        ch=intal_diff(ch,"1");
        free(temp2);
    }
    free(ch);
    return a;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    if(k>n-k)
    {   
        k=n-k;
    }
    char** ch=(char**)malloc(sizeof(char*)*(k + 1));
    char* z=(char*)malloc(2);
    strcpy(z,"0");
    unsigned int m, i, j;
    for(i=0;i<=k;i++)
    {
        ch[i]=z;
    }
    ch[0]=(char*)malloc(2);
    strcpy(ch[0],"1");
    for(i=1;i<=n;i++)
    {
        if(i<k)   
            m=i;
        else    
            m=k;
        for(j=m;j>0;j--)
        {
            ch[j] = intal_add(ch[j],ch[j - 1]);
        }
    }
    free(z);
    return ch[k];
}

//Funtion to return maximum
int intal_max(char **arr, int n)
{
    int i,maximum=0;
    for(i=1;i<n;i++)
    {
        if(intal_compare(arr[i],arr[maximum])==1)
        {
            maximum=i;
        }
    }
    return maximum;
}
//Function to return minimum
int intal_min(char **arr, int n)
{
    int i,minimum=0;
    for(i=1;i<n;i++)
    {
        if(intal_compare(arr[i],arr[minimum])==-1)
        {
            minimum=i;
        }
    }
    return minimum;
}

int intal_search(char **arr, int n, const char* key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(intal_compare(arr[i],key)==0)
            return i;
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    int low=0,high=n-1,m;
    while(low<=high)
    {
        m=(low+high)/2;
        if(intal_compare(arr[m],key)==1)    
            high=m-1;
        else if(intal_compare(arr[m],key)==-1)  
            low=m+1;
        else 
            return m;
    }
    return -1;
}
//Addition function that I have added
static void heapify(char** arr, int n, int idx)
{
    int left=2*idx+1,right=2*idx+2,temp=idx;
    if(left<n && intal_compare(arr[left],arr[temp])==1)  
        temp=left;
    if(right<n && intal_compare(arr[right],arr[temp])==1)  
        temp=right;
    if(temp!=idx)
    {
        char* t1=arr[idx];
        arr[idx]=arr[temp];
        arr[temp]=t1;
        heapify(arr,n,temp);
    }
}

void intal_sort(char **arr, int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(i=n;i>0;i--)
    {
        char* t=arr[0];
        arr[0]=arr[i-1];
        arr[i-1]=t;
        heapify(arr,i-1,0);
    }
}

char* coin_row_problem(char **arr, int n)
{
    char** cr=(char**)calloc(3,sizeof(char*));
    int j;
    cr[0]="0";
    cr[1]=(char*)calloc(strlen(arr[0]), sizeof(char));
    strcpy(cr[1],arr[0]);

    for(j=1;j<n;j++)
    {
        char* a = intal_add(arr[j],cr[0]);
        if(intal_compare(a,cr[1])==1)
        {
            cr[2]=a;
        }
        else
        {
            cr[2]=cr[1];
        }
        cr[0]=cr[1];
        cr[1]=cr[2];
    }
    return cr[2];
}