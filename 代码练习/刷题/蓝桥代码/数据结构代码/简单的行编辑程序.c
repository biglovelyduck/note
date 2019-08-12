#include   "stdio.h"   
#include   "stdlib.h"   
#include   "string.h"   
struct   line{   //�����нṹ��
           char   text[81];      //�������81���ַ�
           int   num;                 /*�к�*/
		   struct line *next;     /*ָ����һ��������Ŀ��ָ��   */       
	       struct line *prior;    /*ָ��ǰһ����Ŀ��ָ��   */   
};         
		   struct line *start;      /*ָ����е�һ����Ŀ��ָ��   */   
		   struct line *last;       /*ָ��������һ����Ŀ��ָ��   */   
		   struct line 
			   *find(int),         /*����һ���ı�,����ָ������ı���ָ��     */ 
			   *dls_store(struct   line   *);     /*���к���������,����ָ������ı���ָ��   */  
		            
		void   patchup(int,int),//����ɾ��ʱ�����к�
			delete_text(),// /*ɾ��һ��   */ 
			list(), /*��ʾ�ı�     */
			save(char   *), /*���ļ�   */     
			load(char   *);        /*��ȡ�ļ�   */    
		menu_select();      /*   ��ʾ�˵������û�ѡ��   */    
		enter(int   linenum); /*���ı�����ָ���ж˲�*/ 

 void   main(int   argc,char   *argv[])      {           
	 char   s[80],choice,fname[80];          
	 int   linenum=1;          
	 start=NULL;          
	 last=NULL;           
	 if(argc==2)   //�ڿ���̨��������������
		 load(argv[1]);/*��ȡ�������ϵ��ļ�   */   //argv[0]ͨ��Ϊ������    
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
 /*   ��ʾ�˵������û�ѡ��   */      
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
 /*���ı�����ָ���ж˲�*/   
 enter(int   linenum)      {           
	 struct   line   *info;          
	 for(;;)       {             
		 info=(struct   line  *)malloc(sizeof(struct   line));         
		 if(!info)        {          
			 printf("\t!   �ڴ治����\n");         
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
	             
 /*���ı����ݲ����ļ��м�ʱ����������ݵ��кű�������1����     */      
 /*ɾ��ʱ����ɾ�����ı�������кű����1   */      
 void   patchup(int   n,int   incr)      {           
	 struct   line   *i;          
	 i=find(n);          
	 while(i){          
		 i->num=i->num+incr;       
		 i=i->next;       
	 }   
 }       
 /*���к���������   */       
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
 /*ɾ��һ��   */      
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
 /*����һ���ı�     */       
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
 /*��ʾ�ı�     */      
 void   list()      {           
	 struct   line   *info;          
	 info=start;          
	 while(info)       {             
		 printf("%d:%s\n",info->num,info->text);         
		 info=info->next;       
	 }           
	 printf("\n\n");      
 }            
 /*���ļ�   */       
 void   save(char   *fname)      {           
	 struct   line   *info;          
	 char   *p;          
	 FILE   *fp;           
	 if((fp=fopen(fname,"w"))==NULL)       {             
		 printf("\t Can't open the file !\n");         
		 exit(0);       }           
	 printf("\t Saving :\n");       
	 info=start;          //startָ�����ڿ���̨������ĵ�һ�����ֵ��׵�ַ
	 while(info)       {          //info����  
		 p=info->text;         
		 while(*p)   
			 putc(*p++,fp);     //��pָ����ַ��浽fpָ����ļ���   
		 putc('\n',fp);        
		 info=info->next;      //infoָ����һ�� 
	 }        fclose(fp);      //�ر��ļ���
 }          
 /*��ȡ�ļ�   */    
 void   load(char   *fname)      {           
	 struct   line   *info,*temp;//infoָ��Ҫ��ȡ����һ�е��ڴ�ռ��ַ
	 char   *p;          
	 FILE   *fp;          
	 int   size,inct;           
	 if((fp=fopen(fname,"r+"))==NULL)         {            
		 printf("\t Can't open the file !\n");           
		 exit(0);         
	 }        
	 while(start)         {           //start��Ϊ�� 
		 temp=start;           
		 start=start->next;      //��һ��     
		 free(temp);         
	 }           
	 printf("\n\t Reading...\n");       
	 size=sizeof(struct   line);        
	 start=(struct   line*)malloc(size);       
	 if(!start)         {    //startΪ��         
		 printf("\n\t�ڴ��Ѿ����� !");            
		 return;         
	 }          
	 info=start;       
	 p=info->text;       
	 inct=1;        //�к�Ϊ1
	 while((*p=getc(fp))!=EOF)         {            
		 p++;             
		 while((*p=getc(fp))!='\n')   
			 p++;            
		 *p='\0';             
		 info->num=inct++;      //�к�����       
		 info->next=(struct   line*)malloc(size);   //ÿһ�����ֶ����ڴ���������һ�οռ�         
		 if(!info->next)             {   //��һ�в����ڣ�˵���ڴ濪�ٲ��ɹ�             
			 printf("\n\t�ڴ��Ѿ����� !");               
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