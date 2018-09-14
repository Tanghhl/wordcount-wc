#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
int cword = 0;
int cchar = 0;	
int aword=0;
int countw(char *file)//返回文件词的数目 
{   FILE *f;
	f=fopen(file,"r");
	char ch;
	if(NULL==(f=fopen(file,"r")))
    {
     printf("file is NULL");
    }
    else
	while(!feof(f))
	{
		ch=fgetc(f);
		if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_')
		aword=1;
	else if (aword)
	{
				cword++;
				aword=0;
	}
	}
	fclose(f); printf("wordnum:%d ",cword);
}
int countc(char *file) //返回文件的字符数 
{   FILE *f;
	f = fopen(file, "r");
	char a;
	if(NULL==(f=fopen(file,"r")))
    {
	    printf("file is NULL");
	}
    else
	while (!feof(f))
	{
		a=fgetc(f);
		if (a != ' '&&a != '\n'&&a != '\t')
		cchar++;
	}
	fclose(f);printf("charnum:%d ",cchar);
}
int countl(char *file) //返回文件的行数
{   FILE *f;
	f = fopen(file, "r");
    int cline = 0;
	char a;
	if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else while(!feof(f))
     {
         a=fgetc(f);
            if(a=='\n'||a=='\t')
               cline++;
     }
    
    fclose(f);printf("Linenum:%d ",cline);
    return 1;
}
int count_blankline(char *file) //返回文件的空行数 
{   FILE *f;
    int b_num = 0;
	int ch_num = 0;
	char ch;
	f = fopen(file, "r");
    if(NULL==(f=fopen(file,"r")))
    {
	    printf("file is NULL");
	}
    else
	while (!feof(f))
	{
		ch= fgetc(f);
		if (ch=='\n'){
			if (ch_num<= 1)
				b_num++;
			ch_num = 0;
		}
		else if (ch!=' '&&ch!='\t'&&ch!='}')
			ch_num++;
		else if(ch=='}')b_num++;
	}
	fclose(f);printf("blankline:%d  ",b_num);
}
int count_noteline(char *file) //返回文件的注释行数 
{   FILE *f;
    int ch_num = 0;int note_num=0;
	char ch;
	f=fopen(file, "r");
    if(NULL==(f=fopen(file,"r")))
    {
	    printf("file is NULL");
	}
    else
	while (!feof(f))
	{
		ch= fgetc(f);
		if(ch=='\n'){if(ch_num==2) note_num++; ch_num=0;}
        else if(ch=='/') ch_num++;
        else if(ch_num==1){if(ch=='/') ch_num++;} 
	} 
	fclose(f);
	printf("noteline:%d  ",note_num);
} 
int count_codeline(char *file)//返回文件的代码行数 
{   int ch_num = 0;
    int code_num=0;
	FILE *f;
	int tag=0; int flag=0;
	char a; 
	f = fopen(file, "r");
    if(NULL==(f=fopen(file,"r")))
    {printf("file is NULL");}
    else
	while (!feof(f))
	{
		a=fgetc(f);
		
		if(flag==2) {
		flag=0;tag++;}
		else{
		
		if(a=='\n'&&ch_num>1)
	     {code_num++; 
		 ch_num=0;	}
        else if(a != ' '&&a != '\n'&&a != '\t'&&a!='/') {
		ch_num++;}
        
        else if(a=='/'){ flag++;}
	}
         
	}
	
	fclose(f); printf("codeline:%d  ",code_num-tag); 
}
int searchfile(void) //寻找文件夹中的txt文件
{
    struct _finddata_t filefind;
    long handle;
    int t=0;
    
       if( (handle=_findfirst( "H:\\wordcount\\test\\*txt", &filefind)) == -1L ) 
        {
        printf( "没找到txt文件\n");
        }
    else
    do{
         t++;
        printf("找到文件:%s\n", filefind.name); 
    }while (_findnext(handle,&filefind)==0);

    _findclose(handle);

    printf("txt文件数量：%d\n",t);
    return 0;
}
int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("FileNull\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-w")) 
		countw(argv[2]);                
        else if(!strcmp(argv[1],"-c"))  
		countc(argv[2]);                
        else if(!strcmp(argv[1],"-l"))    
		countl(argv[2]);            
        else if(!strcmp(argv[1],"-a"))                
       {     
          count_blankline(argv[2]); 
		  count_noteline(argv[2]);
		  count_codeline(argv[2]);
	   }
	    else if(!strcmp(argv[1],"-s"))
	   {
		   searchfile();
	   }
		else
            printf("NullPoint\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}
