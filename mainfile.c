#include "hw4.h"
/*
Samyukta Satish Rao
University Of Southern California.

*/



/*Reads input and parses commandline arguements.*/

int main(int argc, char * argv[])
{
    

    char * input_str;
    char * key;
	if(argc==1)
    {
        fprintf(stderr, "Error: Information given is not enough.\n");
        exit(0);
    }
    else
    {

    	if(strcmp(argv[1], "tablecheck")==0)
        {	
        	if(argc!=3)
        	{
        		fprintf(stderr, "Error: Malformed command. Please enter in the following format \nhw4 tablecheck -t=tablefile\n");
                exit(0);
        	}
        	else
        	{
 
        		if(argv[2][1]=='t')
                {
                    input_str = strchr(argv[2], '=');
                  
                    input_str++;
                }
             
                tablecheck(input_str);

        	}
        }

        else if(strcmp(argv[1], "encrypt")==0)
        {
        	if(argc<4)
        	{
        		fprintf(stderr, "Error: Malformed command. Please enter in the following format \nhw4 encrypt -k=key -t=tablefile [file]\n");
                exit(0);	
        	}
        	if(argc==4)
        	{
        		if(argv[2][1]=='k')
        		{
        			key = strchr(argv[2], '=');
        			key++;
                    int i; 
                    int len=strlen(key);
                    if(len!=16)
                    {
                        fprintf(stderr, "Key  error!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid  key.\n");
                            exit(0);;
                        }  
                       
                    }    
        		}
        		if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
                
                encryption(input_str,key, NULL, 0);
        	}
        	else if(argc==5)
        	{
        		if(argv[2][1]=='k')
        		{
                    
        			key = strchr(argv[2], '=');
        			key++;
                    int i; 
                    int len=strlen(key);
                    if(len!=16)
                    {
                        fprintf(stderr, "Key error!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid key.\n");
                            exit(0);;
                        }  
                       
                    }    
        		}
        		if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
                encryption(input_str,key, argv[4], 0);
        	}
        }
        else if(strcmp(argv[1], "decrypt")==0)
        {
            if(argc<4)
            {
                fprintf(stderr, "Error: Malformed command. Please enter in the following format \nhw4 decrypt -k=key -t=tablefile [file]\n");
                exit(0);    
            }
            if(argc==4)
            {
                if(argv[2][1]=='k')
                {
                    key = strchr(argv[2], '=');
                    key++;
                    int i; 
                    int len=strlen(key);
                    if(len!=16)
                    {
                        fprintf(stderr, "Key lerror!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid key.\n");
                            exit(0);;
                        }  
                       
                    }    
                }
                if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
                
                encryption(input_str,key, NULL, 1);
            }
            else if(argc==5)
            {
                if(argv[2][1]=='k')
                {
                    key = strchr(argv[2], '=');
                    key++;
                    int i; 
                    int len=strlen(key);
                    if(len!=16)
                    {
                        fprintf(stderr, "Key error!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid  key.\n");
                            exit(0);;
                        }  
                       
                    }    
                }
                if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
                encryption(input_str,key, argv[4], 1);
            }
        }
        else if(strcmp(argv[1], "decrypt3")==0)
        {
            if(argc<4)
            {
                fprintf(stderr, "Error: Malformed command. Please enter in the following format \nhw4 decrypt -k=key -t=tablefile [file]\n");
                exit(0);    
            }
            if(argc==4)
            {
                if(argv[2][1]=='k')
                {
                    key = strchr(argv[2], '=');
                    key++;
                    int i; 
                    int len=strlen(key);
                    if(len<48)
                    {
                        fprintf(stderr, "Key to short!\n");
                        exit(0);
                    }
                    else if(len>48)
                    {
                        fprintf(stderr, "Key too long!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid key.\n");
                            exit(0);;
                        }  
                       
                    }    
                }
                if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
                
         
            }
            else if(argc==5)
            {
                if(argv[2][1]=='k')
                {
                    key = strchr(argv[2], '=');
                    key++;
                    int i; 
                    int len=strlen(key);
                    if(len<48)
                    {
                        fprintf(stderr, "Key to short!\n");
                        exit(0);
                    }
                    else if(len>48)
                    {
                        fprintf(stderr, "Key too long!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid  key.\n");
                            exit(0);;
                        }  
                       
                    }    
                }
                if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
            
            }
        }
        else if(strcmp(argv[1], "encrypt3")==0)
        {
            if(argc<4)
            {
                fprintf(stderr, "Error: Malformed command. Please enter in the following format \nhw4 decrypt -k=key -t=tablefile [file]\n");
                exit(0);    
            }
            if(argc==4)
            {
                if(argv[2][1]=='k')
                {
                    key = strchr(argv[2], '=');
                    key++;
                    int i; 
                    int len=strlen(key);
                    if(len<48)
                    {
                        fprintf(stderr, "Key to short!\n");
                        exit(0);
                    }
                    else if(len>48)
                    {
                        fprintf(stderr, "Key too long!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid key.\n");
                            exit(0);;
                        }  
                       
                    }    
                }
                if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
                
            }
            else if(argc==5)
            {
                if(argv[2][1]=='k')
                {
                    key = strchr(argv[2], '=');
                    key++;
                    int i; 
                    int len=strlen(key);
                    if(len<48)
                    {
                        fprintf(stderr, "Key to short!\n");
                        exit(0);
                    }
                    else if(len>48)
                    {
                        fprintf(stderr, "Key too long!\n");
                        exit(0);
                    }
                    for(i=0;i<len;i++)
                    {
                        if(!( ( (key[i]>='a') && (key[i]<='f') ) || ( (key[i]>='0') && (key[i]<='9') )  ))
                        {
                            fprintf(stderr, "Invalid  key.\n");
                            exit(0);;
                        }  
                       
                    }    
                }
                if(argv[3][1]=='t')
                {
                    input_str = strchr(argv[3], '=');
                    input_str++;
                }
                tablecheck(input_str);
          
            }
        }
        else
        {
            fprintf(stderr, "Malformed command\n");
            exit(0);
        }
    }


    return 0;
}
