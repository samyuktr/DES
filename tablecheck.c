#include "hw4.h"
/*
Samyukta Satish Rao
University Of Southern California.

*/

/*Reads the table file and parses it.*/


int testIP(char * iptest) // tests the IP table.
{

	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	//for(i=0;i<64;i++)
	do
	{
		char * num1 = strtok(lp, comma);

		if(1<=atoi(num1) && atoi(num1)<=64)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	}while(lp!=NULL);
	if(counter<64)
	{
		fprintf(stderr, "( IP) too few values read\n");
		exit(0);
	}
	if(counter>64)
	{
		fprintf(stderr, "( IP) too many values read\n");
		exit(0);
	}
	if(counter!=64)
		return 0;
	else
		return flag;

}
int testE(char * ipe) // tests the E table.
{
	int test_e[32] = {0};
	int counter = 0;
	int num_arr[48]  = {};
	char * eq = "=";
	char * comma = ",";
	int i=0, j, flag = 0;
	int count;
	strtok(ipe, eq);
	char * lp = strtok(NULL, "");
	
	do
	{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		num_arr[i] = atoi(num1);
		if(1<=atoi(num1) && atoi(num1)<=32)
		{
			test_e[num-1]+=1;
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	} while(lp!=NULL);

	for(i=0;i<48;i++)
    {
        count=1;
        for(j=i+1;j<=47;j++)
        {
            if(num_arr[i]==num_arr[j] && num_arr[i]!='\0')
            {
                count++;
                num_arr[j]='\0';
            }
        }
        if(num_arr[i]!='\0')
        {
        	
            if(count>2)
            {
    			fprintf(stderr, "E table error!\n");
   				exit(0);
            }

        }
    }
    for(i=0;i<32;i++)
    {
		    if(test_e[i]==0)
		    {
		    	fprintf(stderr, "(E )The number %d did not occur in E table.\n", i+1 );
		    }
		    else if(test_e[i]>2)
		    {
		    	fprintf(stderr, "(  E) the value %d in the E table occur too many times\n", i+1 );
		    }
	}
    if(counter!=48)
    {
    	fprintf(stderr, "(E )Invalid number of entried in E table. \n");
    	exit(0);
    }
    if(counter!=48)
    	return 0;
    else
		return flag;
}

int testP(char *iptest) // tests the P table.
{
	
	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	
	do
	{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		
		if(1<=num && num<=32)
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	}while(lp!=NULL);
	if(counter>32)
	{
		fprintf(stderr, "(  P) %d values read while 32 was expected\n", counter);
		exit(0);
	}
	if(counter!=32)
	{
		fprintf(stderr, "( P) Invalid number of values in P file.\n" );
		exit(0);
	}
	if(counter!=32)
		return 0;
	else
		return flag;

}
int testS(char * iptest, char * name) //tests the S tables.
{
	int testst[16] = {0};
	int counter = 0;
	name++;
	int number = (int)(atoi(name));
	if(1>number || number>8)
	{
		fprintf(stderr, "S%d exceeding limit. \n", number);
		exit(0);
	}

	char * eq = "=";
	char * comma = ",";
	int i, flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");

	while(lp!=NULL)
	{
		
		i=0;
		while(i<16 && lp!=NULL)
		{
			char * num1 = strtok(lp, comma);
			int x = atoi(num1);
			if((x>=0) && (x<=15))
			{
				flag = 1;
				testst[x]+=1;
			}
			else
			{
				flag = 0;
				fprintf(stderr, "(S%d ) Invalid entry.\n", number);
				exit(0);
				break;
			}
			lp = strtok(NULL, "");
			i++;
			counter++;
			if(counter>64)
			{
				flag = 0;
				break;
			}
		}
		
		if(counter>64)
		{
			flag = 0;
			break;
		}
	
	
		
	}

	if(counter<64)
	{
		fprintf(stderr, "( S%d) %d values read while 64 was expected\n", number, counter);
		exit(0);
	}
	for(i=0;i<16;i++)
	{
		if(testst[i]!=4)
		{
			fprintf(stderr, "( S%d) the value %d in the S%d table did not occur 4 times\n", number, i, number);
			exit(0);
		}
	}
	if(flag==0)
	{
		fprintf(stderr, "Invalid entry.\n");
	}
	/*fprintf(stderr, "Start\n");
	for(i=0;i<16;i++)
		fprintf(stderr,"%d ", testst[i] );
	fprintf(stderr, "\nEnd\n");*/
	if(counter>64)
	{
		fprintf(stderr, "( S%d) %d values read while 64 was expected\n", number, counter);
		exit(0);
	}

	if(counter!=64)
		return 0;
	else
		return flag;
	
}

int testV(char * iptest) // tests the V table
{
	int count1 = 0, count2 = 0;
	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	
	do{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		if(num==1)
		{
			count1++;
			flag = 1;
		}
		else if(num==2)
		{
			count2++;
			flag = 1;
		}
		else
		{
			flag = 0;
			fprintf(stderr, "Number other than 1 or 2 encountered.\n");
			exit(0);
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	}while(lp!=NULL);
	
	if(count1!=4)
	{
		fprintf(stderr, "(  V) the value 1 in the V table did not occur 4 times\n");
		exit(0);
	}
	if(count2!=12)
	{
		fprintf(stderr, " (  V) the value 2 in the V table did not occur 12 times\n");
		exit(0);
	}
	if(count1==4 && count2==12 && counter==16)
		return flag;
	else
		return 0;
}

int testPC1(char * iptest) // tests PC1 table
{
	int test_pc1[64] = {0};
	int i;
	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	do
	{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		if(1<=atoi(num1) && atoi(num1)<=64)
		{
			test_pc1[num-1]+=1;
			
			if(num%8==0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	} while(lp!=NULL);

	for(i=0;i<64;i++)
		if(test_pc1[i]==0 && (i+1)%8!=0)
		{
			fprintf(stderr, "(PC1 )the value %d in the PC1 table did not occur\n", i+1);
			exit(0);
		}
		if(counter!=56)
		{
			fprintf(stderr, "Invalid number of values in PC1\n");
			exit(0);
		}
	if(counter>56)
		return 0;
	else
		return flag;

}

int testPC2(char * iptest) // tests PC2 table
{
	int test_pc2[56] = {0};
	int i;
	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	do
	{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		if(1<=atoi(num1) && atoi(num1)<=56)
		{
			test_pc2[num-1]+=1;
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	} while(lp!=NULL);

	for(i=0;i<56;i++)
		if(test_pc2[i]>1)
		{
			fprintf(stderr, "(PC2 ) the value %d in the PC1 table did not occur\n",i+1 );
		}
	if(counter!=48)
	{
		fprintf(stderr, "Invalid number of values in PC2.\n");
		exit(0);
	}
	if(counter>48)
		return 0;
	else
		return flag;

}


void tablecheck(char * filename) // check the table file with the above functions.
{
	char c;
	int count = 0;
	int i;

	FILE * fp = fopen(filename, "rb");
	if(fp==NULL)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
        else if(c==' ' || c=='\t' )
        {
        	fprintf(stderr, "Incorrect table file format\n" );
        	exit(0);
        }
       
	}
	if(count!=14)
	{
		fprintf(stderr, "Incorrect table file format\n");
		exit(0);
	}
	rewind(fp);
//===========================================================================================
	char * line = calloc(200, sizeof(char));
	line[0] = '\0';
	char *test = calloc(4, sizeof(char));
	test[0] = '\0';

	for(i=0;i<14;i++)
	{
		int f_isp = 1;
		if(fgets(line, 200, fp)==NULL)
			break;
		char* pos = strchr(line,'=');
		
		int pos_int = (int)(pos-line);

		strncpy(test, line, pos_int);
		test[pos_int+1] = '\0';

		if(strncmp(test, "IP", 2)==0 )
		{

    		if(!testIP(line))
    		{
    			fprintf(stderr, "IP table error!\n");

    			exit(0);
    		}
    	}
    	if(strncmp(test, "E", 1)==0)
    	{

    			if(!testE(line))
    			{
    				fprintf(stderr, "E table error!\n");
    				exit(0);
    			}
    	}
    	 
    	if(strncmp(test, "S", 1)==0)
    	{
    		if(!testS(line, test))
    		{
    			fprintf(stderr, "%s table error!\n", test);
    			exit(0);
    		}
    	}
    	if(strncmp(test, "V", 1)==0)
    	{
    		if(!testV(line))
    		{
    			fprintf(stderr, "V table error!\n" );
    			exit(0);
    		}
    	}
    	if(strncmp(test, "PC1", 3)==0)
    	{
    		f_isp = 0;
    		if(!testPC1(line))
    		{
    			fprintf(stderr, "PC1 table error!\n");
    			exit(0);
    		}
    	}
    	if(strncmp(test, "PC2", 3)==0)
    	{
    		f_isp = 0;
    		if(!testPC2(line))
    		{
    			fprintf(stderr, "PC2 table error!\n");
    			exit(0);
    		}
    	}
    	if(strncmp(test, "P", 1)==0 && f_isp==1)
    	{

    		if(!testP(line))
    		{
    			fprintf(stderr, "P table error!\n");
    			exit(0);
    		}
    	}


    	test[0] = '\0';
		test[(int)(pos-line-1)] = '\0';
		line[0] = '\0';

	}	
}
