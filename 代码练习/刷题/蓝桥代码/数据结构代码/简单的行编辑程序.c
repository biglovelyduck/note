#include   "stdio.h"   
#include   "stdlib.h"   
#include   "string.h"   
struct   line{   //定义行结构体
           char   text[81];      //最多输入81个字符
           int   num;                 /*行号*/
		   struct line *next;     /*指向下一个输入项目的指针   */       
	       struct line *prior;    /*指向前一个项目的指针   */   
};         
		   struct line *start;      /*指向表中第一个项目的指针   */   
		   struct line *last;       /*指向表中最后一个项目的指针   */   
		   struct line 
			   *find(int),         /*查找一行文本,返回指向该行文本的指针     */ 
			   *dls_store(struct   line   *);     /*按行号排序后插入,返回指向该行文本的指针   */  
		            
		void   patchup(int,int),//插入删除时更改行号
			delete_text(),// /*删除一行   */ 
			list(), /*显示文本     */
			save(char   *), /*存文件   */     
			load(char   *);        /*读取文件   */    
		menu_select();      /*   显示菜单，供用户选择   */    
		enter(int   linenum); /*将文本插在指定行端部*/ 

 void   main(int   argc,char   *argv[])      {           
	 char   s[80],choice,fname[80];          
	 int   linenum=1;          
	 start=NULL;          
	 last=NULL;           
	 if(argc==2)   //在控制台输入了两个参数
		 load(argv[1]);/*读取命令行上的文件   */   //argv[0]通常为程序名    
	 do{              
		 choice=menu_select();          
		 switch(choice)          {            
		 case   1:printf("\tlinenum :");           
			 gets(s);           linenum=atoi(s);           
			 enter(linenum);           break;            
		 case   2:delete_text();           break;            
		 case   3:list();           break;            
		 case   4:printf("\tfilename :");           
			 gets(fname);           
			 save(fname);           break;            
		 case   5:printf("\tfilename :");           
			 gets(fname);           
			 load(fname);           break;            
		 case   6:exit(0);           
		 }        
	 }while(1);
	 }            
 /*   显示菜单，供用户选择   */      
 menu_select()      {           
	 char   s[80];          
	 int   c;           
	 printf("\t\t1.Enter\n");       
	 printf("\t\t2.Delete a line\n");       
	 printf("\t\t3.Display a line\n");      
	 printf("\t\t4.Save the file\n");       
	 printf("\t\t5.Read the file\n");       
	 printf("\t\t6.Quit\n");       
	 do{            
		 printf("\n\n\t\t Please choice a num :");        
		 gets(s);        
		 c=atoi(s);       
	 }while(c<0||c>6);       
	 return(c);      
 }            
 /*将文本插在指定行端部*/   
 enter(int   linenum)      {           
	 struct   line   *info;          
	 for(;;)       {             
		 info=(struct   line  *)malloc(sizeof(struct   line));         
		 if(!info)        {          
			 printf("\t!   内存不够！\n");         
			 return(NULL);        
		 }        
		 printf("%d:",linenum);          
		 gets(info->text);          
		 info->num=linenum;          
		 if(*info->text)        {          
			 if(find(linenum))   
				 patchup(linenum,1);         
			 if(*info->text)   
				 start=dls_store(info);        
		 }        
		 else   break;          
		 linenum++;         
	 }           
	 return(linenum);
 }
	             
 /*当文本内容插在文件中间时其下面的内容的行号必须增加1，而     */      
 /*删除时，被删除的文本后面的行号必须减1   */      
 void   patchup(int   n,int   incr)      {           
	 struct   line   *i;          
	 i=find(n);          
	 while(i){          
		 i->num=i->num+incr;       
		 i=i->next;       
	 }   
 }       
 /*按行号排序后插入   */       
 struct   line   *dls_store(struct   line   *i)      {           
	 struct   line   *old,*p;          
	 if(last==NULL)       {         
		 i->next=NULL;        
		 i->prior=NULL;        
		 last=i;        
		 return(i);       
	 }        
	 p=start;          
	 old=NULL;          
	 while(p)       {          
		 if(p->num)         {          
			 old=p;          
			 p=p->next;         
		 }         
		 else         {            
			 if(p->prior)           {              
				 p->prior->next=i;             
				 i->next=p;             
				 p->prior=i;             
				 return   start;           
			 }            
			 i->next=p;          
			 i->prior=NULL;           
			 p->prior=i;           
			 return(i);
			  }       
	 }        
	 old->next=i;       
	 i->next=NULL;       
	 i->prior=old;       
	 last=i;        
	 return   start;   
 }            
 /*删除一行   */      
 void   delete_text()      {           
	 struct   line   *info;          
	 char   s[80];          
	 int   linenum;          
	 printf("\tlinenum :");       
	 gets(s);          
	 linenum=atoi(s);          
	 info=find(linenum);          
	 if(info)       {          
		 if(start==info)         {            
			 start=info->next;            
			 if(start)   start->prior=NULL;           
			 else       last=NULL;         
		 }         
		 else         {          
			 info->prior->next=info->next;         
			 if(info!=last)          
				 info->next->prior=info->prior;         
			 else   last=info->prior;         
		 }          free(info);          
		 patchup(linenum+1,-1);       
	 }   
 }            
 /*查找一行文本     */       
 struct   line   *find(int   linenum)      {           
	 struct   line   *info;          
	 info=start;          
	 while(info)       {
		 if(linenum==info->num)   
			 return(info);         
		 info=info->next;       
	 }           
	 return(NULL);      
 }            
 /*显示文本     */      
 void   list()      {           
	 struct   line   *info;          
	 info=start;          
	 while(info)       {             
		 printf("%d:%s\n",info->num,info->text);         
		 info=info->next;       
	 }           
	 printf("\n\n");      
 }            
 /*存文件   */       
 void   save(char   *fname)      {           
	 struct   line   *info;          
	 char   *p;          
	 FILE   *fp;           
	 if((fp=fopen(fname,"w"))==NULL)       {             
		 printf("\t Can't open the file !\n");         
		 exit(0);       }           
	 printf("\t Saving :\n");       
	 info=start;          //start指向你在控制台上输入的第一行文字的首地址
	 while(info)       {          //info存在  
		 p=info->text;         
		 while(*p)   
			 putc(*p++,fp);     //将p指向的字符存到fp指向的文件中   
		 putc('\n',fp);        
		 info=info->next;      //info指向下一行 
	 }        fclose(fp);      //关闭文件流
 }          
 /*读取文件   */    
 void   load(char   *fname)      {           
	 struct   line   *info,*temp;//info指向要读取的下一行的内存空间地址
	 char   *p;          
	 FILE   *fp;          
	 int   size,inct;           
	 if((fp=fopen(fname,"r+"))==NULL)         {            
		 printf("\t Can't open the file !\n");           
		 exit(0);         
	 }        
	 while(start)         {           //start不为空 
		 temp=start;           
		 start=start->next;      //下一行     
		 free(temp);         
	 }           
	 printf("\n\t Reading...\n");       
	 size=sizeof(struct   line);        
	 start=(struct   line*)malloc(size);       
	 if(!start)         {    //start为空         
		 printf("\n\t内存已经用完 !");            
		 return;         
	 }          
	 info=start;       
	 p=info->text;       
	 inct=1;        //行号为1
	 while((*p=getc(fp))!=EOF)         {            
		 p++;             
		 while((*p=getc(fp))!='\n')   
			 p++;            
		 *p='\0';             
		 info->num=inct++;      //行号增加       
		 info->next=(struct   line*)malloc(size);   //每一行文字都在内存区开辟了一段空间         
		 if(!info->next)             {   //下一行不存在，说明内存开辟不成功             
			 printf("\n\t内存已经用完 !");               
			 return;            
		 }              
		 info->prior=temp;             
		 temp=info;             
		 info=info->next;             
		 p=info->text;         
	 }          
	 temp->next=NULL;         
	 last=temp;         
	 free(info);         
	 start->prior=NULL;
	 fclose(fp); 
  }