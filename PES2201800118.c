#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

static char* add_zeros(char* intal1, char* intal2)
{
    int i=strlen(intal1),j=strlen(intal2),k;
    char* intal=(char*)malloc(sizeof(char)*(i+1));
    for(k=0;k<(i-j);k++)
        intal[k]='0';
    for(;k<i;k++)
        intal[k]=intal2[k-(i-j)];
    intal[k]='\0';
    return intal;
}

static char* intal2str(char* intal)
{
    char *t1=(char*)malloc(10000);
    while(intal[0]=='0')
        intal++;
    if(strlen(intal)==0)  
        strcpy(t1,"0");
    else
        strcpy(t1,intal);
    return t1;
}

char* intal_add(const char* intal1, const char* intal2)
{
    int i,j,c,n;
    char *t1=(char*)malloc(strlen(intal1)+1);
    char *t2=(char*)malloc(strlen(intal2)+1);
    strcpy(t1,intal1);
    strcpy(t2,intal2);
    char *temp1=t1; 
    char *temp2=t2;
    t1=intal2str(t1);
    t2=intal2str(t2);
    free(temp1);
    free(temp2);
    i=strlen(t1); 
    j=strlen(t2);
    char *sol,*a1,*a2;
    if(i>j)
    {
        a2=add_zeros(t1,t2);
        a1=t1;
        n=i;
    }
    else if(j>i)
    {
        a2=add_zeros(t2,t1);
        a1=t2;
        n=j;
    }
    else
    {
        a1=t1,a2=t2;
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
    free(t1);
    free(t2);
    temp1=sol;
    sol=intal2str(sol);
    free(temp1);
    return sol;
}

int intal_compare(const char* intal1, const char* intal2)
{
    char *a=(char*)malloc(strlen(intal1)+2);
    char *b=(char*)malloc(strlen(intal2)+2);
    strcpy(a,intal1);
    strcpy(b,intal2);
    char *temp1=a; 
    char *temp2=b;
    a=intal2str(a);
    b=intal2str(b);
    free(temp1);
    free(temp2);
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

char* intal_diff(const char* intal1, const char* intal2)
{
    char *t1=(char*)malloc(strlen(intal1)+2);
    char *t2=(char*)malloc(strlen(intal2)+2);
    strcpy(t1,intal1);
    strcpy(t2,intal2);
    char *temp1=t1,*temp2=t2;
    t1=intal2str(t1);
    t2=intal2str(t2);
    free(temp1);
    free(temp2);
    char *d1,*d2,*sol;
    int i=strlen(t1);
    int c=intal_compare(t1,t2);
    if(c==1)
    {
        d1=t1;
        d2=add_zeros(t1,t2);
    }
    else if(c==-1)
    {
        d1=t2;
        d2=add_zeros(t2,t1);
    }
    else
    {    
        sol=(char*)malloc(2);
        strcpy(sol,"0");
        return sol;
    }

    sol=(char*)malloc(strlen(d1)+1);
    for(i=strlen(d1)-1;i>=0;i--)
    {
        int a;
        if(d1[i]>=d2[i])
        {  
            a=(d1[i]-'0')-(d2[i]-'0');
        }
        else
        {
            a=((d1[i]-'0')+10)-(d2[i]-'0');
            d1[i-1]--;
        }
        sol[i]=a+'0';
    }
    sol[strlen(d1)]='\0';
    free(t1);
    free(t2);
    free(d2);
    temp1=sol;
    sol=intal2str(sol);
    return sol;
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
    int n1=strlen(a),n2=strlen(b);
    int *tmp=(int*)malloc(sizeof(int)*(n1+n2));
    for(i=0;i<(n1+n2);i++)
        tmp[i] = 0;
    for(i=n1-1;i>=0;i--)
    {
        for(j=n2-1;j>=0;j--)
        {
            int p1=i+j,p2=i+j+1;
            m=(a[i]-'0')*(b[j]-'0');
            s=m+tmp[p2];
            tmp[p1]+=(s/10);
            tmp[p2]=(s%10);
        }
    }
    char *sol=(char*)malloc(n1+n2+1);
    for(i=0;i<(n1+n2);i++)
        sol[i]=tmp[i]+'0';
    sol[i]='\0';
    free(a);
    free(b);
    free(tmp);
    char *temp1=sol;
    sol=intal2str(sol);
    free(temp1);
    return sol;
}

static char* append_char(char* intal1, char c)
{
    char* intal=(char*)malloc(strlen(intal1)+2);
    int i;
    for(i=0;i<strlen(intal1);i++)
        intal[i]=intal1[i];
    intal[i]=c;
    intal[i + 1]='\0';
    return intal;
}

char* intal_mod(const char* intal1, const char* intal2)
{
    int a=strlen(intal1),ind=0;
    char *d1=(char*)malloc(1000);
    strcpy(d1,"0");
    while(ind<a)
    {
        char *temp1; 
        char *temp2;
        d1=append_char(d1,intal1[ind]);
        temp1=d1;
        d1=intal2str(d1);
        free(temp1);
        ind++;
        while(ind<a && intal_compare(d1,intal2)==-1)
        {
            d1=strncat(d1, &(intal1[ind]), 1);
            d1=intal2str(d1);
            ind++;
        }
        if((intal_compare(intal2,d1)==1) || (intal_compare(d1,"0")==0))
            return d1;
        char *i=(char*)malloc(sizeof(char)*3);
        strcpy(i,"0");
        char *t1=(char*)malloc(sizeof(d1));
        strcpy(t1,"0");
        while(intal_compare(i,"11")==-1 && intal_compare(t1,d1) != 1 )
        {
            temp1=i; 
            temp2=t1;
            i=intal_add(i,"1");
            t1=intal_multiply(intal2,i);
            free(temp1);
            free(temp2);
        }
        temp1=i;
        temp2=t1;
        i=intal_diff(i,"1");
        t1=intal_multiply(intal2,i);
        free(temp1);
        free(temp2);
        temp1=d1;
        d1=intal_diff(d1, t1);
        free(temp1);
        free(i);
        free(t1);
    }
    return d1;
}

char* intal_pow(const char* intal1, unsigned int n)
{
    char* t1 = (char*)malloc(strlen(intal1)+1);
    strcpy(t1,intal1);
    char* temp1;
    if(intal_compare(t1,"0")==0)
    {    
        temp1=t1;
        t1=intal2str(t1);
        free(temp1);
        return t1;
    }
    if(n==0)
    {  
        strcpy(t1,"1");
        return t1;
    }
    char* p = intal_pow(intal1,n/2);
    char* m = intal_multiply(p,p);
    if(n%2==0)
    {
        free(t1);
        free(p);
        return m;
    }
    else
    {
        temp1=t1;
        t1=intal_multiply(intal1,m);
        free(temp1);
        free(m);
        free(p);
        return t1;
    }
}

char* intal_gcd(const char* intal1, const char* intal2)
{
    char* t1=(char*)malloc(strlen(intal1));
    char* t2=(char*)malloc(strlen(intal2));
    char* temp=(char*)malloc(1000);
    strcpy(t1,intal1);
    strcpy(t2,intal2);
    while(1)
    {
        if(intal_compare(t2,"0")==0)
        {
            return t1;
        }
        char* temp1=temp;
        temp=t2;
        free(temp1);
        t2=intal_mod(t1, t2);
        temp1=t1;
        t1=temp;
        free(temp1);
        temp=NULL;
    }
}

char* intal_fibonacci(unsigned int n)
{
    char *c=(char*)malloc(sizeof(char)*10001);
    if(n==0)
    {  
        strcpy(c,"0");    
        return c;
    }
    else if(n==1)
    {
        strcpy(c,"1"); 
        return c;
    }
    char first[10000]="0";
    char second[10000]="1";
    n--;
    while(n--)
    {
        strcpy(c,intal_add(first,second));
        strcpy(first,second);
        strcpy(second,c);
    }
    return c;
}



static unsigned int digits(unsigned int n)
{
    unsigned int dig=0;
    while(n>0)
    {
        dig++;
        n/=10;
    }
    return dig;
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
    unsigned int dig=digits(n);
    char* c=(char*)malloc(sizeof(char)*1000);
    for(i = dig - 1; i >= 0; i--)
    {
        c[i]=n%10+'0'; 
        n/=10;
    }
    c[dig]='\0';
    while(intal_compare(c,"1")!=0)
    {
        char* temp1=a;
        char* temp2=c;
        a=intal_multiply(a,c);
        free(temp1);
        c=intal_diff(c,"1");
        free(temp2);
    }
    free(c);
    return a;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    if(k>n-k)   
        k=n-k;
    char** c=(char**)malloc(sizeof(char*)*(k + 1));
    char* z=(char*)malloc(2);
    strcpy(z,"0");
    unsigned int m, i, j;
    for(i=0;i<=k;i++) c[i]=z;
    c[0]=(char*)malloc(2);
    strcpy(c[0],"1");
    for(i=1;i<=n;i++)
    {
        if(i<k)   
            m=i;
        else    
            m=k;
        for(j=m;j>0;j--)
        {
            c[j] = intal_add(c[j],c[j - 1]);
        }
    }
    free(z);
    return c[k];
}

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
        {
            return i;
        }
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    int l=0,h=n-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(intal_compare(arr[m],key)==1)    
            h=m-1;
        else if(intal_compare(arr[m],key)==-1)  
            l=m+1;
        else 
            return m;
    }
    return -1;
}

static void heap(char** arr, int n, int index)
{
    int left=2*index+1,right=2*index+2,temp=index;
    if(left<n && intal_compare(arr[left],arr[temp])==1)  
        temp=left;
    if(right<n && intal_compare(arr[right],arr[temp])==1)  
        temp=right;
    if(temp!=index)
    {
        char* t1=arr[index];
        arr[index]=arr[temp];
        arr[temp]=t1;
        heap(arr,n,temp);
    }
}

void intal_sort(char **arr, int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heap(arr,n,i);
    for(i=n;i>0;i--)
    {
        char* t1=arr[0];
        arr[0]=arr[i-1];
        arr[i-1]=t1;
        heap(arr,i-1,0);
    }
}

char* coin_row_problem(char **arr, int n)
{
    char** table=(char**)calloc(3,sizeof(char*));
    int j;
    table[0]="0";
    table[1]=(char*)calloc(strlen(arr[0]), sizeof(char));
    strcpy(table[1],arr[0]);
    for(j=1;j<n;j++)
    {
        char* a = intal_add(arr[j],table[0]);
        if(intal_compare(a,table[1])==1)
        {
            table[2]=a;
        }
        else
        {
            table[2]=table[1];
        }
        table[0]=table[1];
        table[1]=table[2];
    }
    return table[2];
}