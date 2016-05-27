#include "hw4.h"

/*
Samyukta Satish Rao
University Of Southern California.

*/



int v_arr[16] = {}; // v array
int pc1a[28] = {}; // Pc1 first half
int pc1b[28] = {}; // Pc1 second half.
int pc2[48] = {}; // pc2 table.
int e_arr[48]  = {}; // E array. 
int p_arr[32] = {}; // P array
int ip_arr[64] = {}; // IP array
int invip_arr[64] = {}; // IP -1 array 
//s1-s8
int s1[4][16] = {};
int s2[4][16] = {};
int s3[4][16] = {};
int s4[4][16] = {};
int s5[4][16] = {};
int s6[4][16] = {};
int s7[4][16] = {};
int s8[4][16] = {};
int row;
int col;
//k1-k16 has the keys. 
//=========================
int binary_decimal(int * num) // converts binary string to decimal
{   
    int decimal_num = 0, base = 1, rem;
    //binary_num = num;
    int i;
    for(i=7;i>=0;i--)
    {
        rem = num[i];
        decimal_num = decimal_num + rem * base;
        //num = num / 10 ;
        base = base * 2;
    }
    return decimal_num;
}

int get_pos(int num) // returns position of number in the IP inverse table
{
	int i;
	for(i=0;i<64;i++)
	{
		if(ip_arr[i]==num)
			return i;
	}
	return 0;
}

void tobinstr(int value, int bitsCount, char* output) // converts decimal to binary string.
{
    int i;
    output[bitsCount] = '\0';
    for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
    {
        output[i] = (value & 1) + '0';
    }
}


void solve_s(int * six_bits) // gives row and col number from 6 bit input.
{

	row = (six_bits[0] * 2 )+ (six_bits[5] * 1);
	col = (six_bits[1]*8) + (six_bits[2]*4)+ (six_bits[3]*2)+ (six_bits[4]);
}

int testSe(char * iptest, char * name) // TEsts S file and populates array
{
			
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
			
			int ctr = 0;
			while(lp!=NULL)
			{

				i=0;
				while(i<16)
				{
					char * num1 = strtok(lp, comma);
					int x = atoi(num1);
					if((x>=0) && (x<=15))
					{
						flag = 1;
						if(number ==1)
						{
							s1[ctr][i] = x;
							
						}
						if(number ==2)
						{
							s2[ctr][i] = x;
							
						}
						if(number ==3)
						{
							s3[ctr][i] = x;
							
						}
						if(number ==4)
						{
							s4[ctr][i] = x;
							
						}
						if(number ==5)
						{
							s5[ctr][i] = x;
							
						}
						if(number ==6)
						{
							s6[ctr][i] = x;
							
						}
						if(number ==7)
						{
							s7[ctr][i] = x;
							
						}
						if(number ==8)
						{
							s8[ctr][i] = x;
							
						}
					}
					else
					{
						flag = 0;
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
				ctr++;
				if(counter>64)
				{
					flag = 0;
					break;
				}
				
			
				
			}
			
			if(counter!=64)
				return 0;
			else
				return flag;
			
}

 char *byte_to_binary(char y) // converts char to  bit stream 
{
    int x = (int)y;
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

int testIPe(char * iptest) //checks IP table and populates ip_arr
{
	int ip_ctr = 0;
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
	//	printf("Num1: %s\n", num1 );
		//getchar();
		int num = atoi(num1);
		//printf("num1: %s\n", num1 );
		//getchar();
		if(1<=atoi(num1) && atoi(num1)<=64)
		{
			ip_arr[ip_ctr++] = num;
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
	if(counter!=64)
		return 0;
	else
		return flag;

}
int testEe(char * ipe) // checks E table an populates e_arr
{
	
	int num_arr[48]  = {}; 
	int counter = 0;
	int e_ctr = 0;
	char * eq = "=";
	char * comma = ",";
	int i=0, j, flag = 0;
	int count;
	strtok(ipe, eq);
	char * lp = strtok(NULL, "");
	
	do
	{
		char * num1 = strtok(lp, comma);
		num_arr[i] = atoi(num1);
		if(1<=atoi(num1) && atoi(num1)<=32)
		{
			flag = 1;
			e_arr[e_ctr++] = atoi(num1);

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
    if(counter!=48)
    	return 0;
    else
		return flag;
}

int testVe(char * iptest) // checks V table and populates v_arr
{
	int v_ctr = 0;
	int count1 = 0, count2 = 0;
	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	//for(i=0;i<16;i++)
	do{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		v_arr[v_ctr++] = num;
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
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	}while(lp!=NULL);
	//printf("Count1: %d  Count2: %d  Counter: %d\n", count1, count2, counter);
	if(count1==4 && count2==12 && counter==16)
		return flag;
	else
		return 0;
}

int testPC1e(char * iptest) // checks PC1 and populates pc1a and pc1b
{
	int pc1a_ctr = 0;
	int pc1b_ctr = 0;
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
			
			if(num%8==0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
			if(pc1a_ctr<29)
				pc1a[pc1a_ctr++] = num;

			if(pc1a_ctr>=29)
				pc1b[pc1b_ctr++] = num;

			
		}
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	} while(lp!=NULL);

	if(counter>56)
		return 0;
	else
		return flag;

}

int testPC2e(char * iptest) // checks PC2 and populates pc2
{
	//int pc2a_ctr = 0;
	int pc2_ctr = 0;
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
			
			pc2[pc2_ctr++] = num;
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

	if(counter>48)
		return 0;
	else
		return flag;

}
char * hex_to_bin(char c) // converts hex to binary string
{
    switch (c)
    {
        case '0':
            return("0000"); break;
        case '1':
            return("0001"); break;
        case '2':
            return("0010"); break;
        case '3':
            return("0011"); break;
        case '4':
            return("0100"); break;
        case '5':
            return("0101"); break;
        case '6':
            return("0110"); break;
        case '7':
            return("0111"); break;
        case '8':
            return("1000"); break;
        case '9':
            return("1001"); break;
        case 'A':
            return("1010"); break;
        case 'B':
            return("1011"); break;
        case 'C':
            return("1100"); break;
        case 'D':
            return("1101"); break;
        case 'E':
            return("1110"); break;
        case 'F':
            return("1111"); break;
        case 'a':
            return("1010"); break;
        case 'b':
            return("1011"); break;
        case 'c':
            return("1100"); break;
        case 'd':
            return("1101"); break;
        case 'e':
            return("1110"); break;
        case 'f':
            return("1111"); break;
        default:
               return 0;
    }

    
    return 0;
}

void toHex(int * bin, int len) // converts binay string to hex
{
    int i=0, j=0, sum=0;
   while(i<len)
    {
        for(j=3;j>=0;j--)
        {
            sum = sum+pow(2,j)*(bin[i]);
            i++;
        }
        if(sum<10)
            fprintf(stderr, "%d", sum);
        else
        {
            char pr = (char)(sum+87);
            fprintf(stderr, "%c", pr);
        }
        sum = 0;
    }
   
}
int testPe(char *iptest) // checks P table and populates p_arr
{
	int p_ctr=0;
	int counter = 0;
	char * eq = "=";
	char * comma = ",";
	int flag = 0;
	strtok(iptest, eq);
	char * lp = strtok(NULL, "");
	//for(i=0;i<32;i++)
	do
	{
		char * num1 = strtok(lp, comma);
		int num = atoi(num1);
		//printf("P: %d  ", num );
		//getchar();
		if(1<=num && num<=32)
		{
			flag = 1;
			p_arr[p_ctr++] = num;
		}
		else
		{
			flag = 0;
			break;
		}
		lp = strtok(NULL, "");
		counter++;
	}while(lp!=NULL);

	if(counter!=32)
		return 0;
	else
		return flag;

}

void encryption(char * tablefile, char * key, char * ipfilename, int df) // does encryption and decryption based on df flag. df=0 -> encryption
{
	char c;
	int count = 0;
	int i;

	FILE * fp = fopen(tablefile, "rb");
	if(fp==NULL)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
        if (c == '\n') 
            count = count + 1;
        else if(c==' ' || c=='\t' )
        {
        	fprintf(stderr, "Incorrect file format\n" );
        	exit(0);
        }
       
	}
	if(count!=14)
	{
		fprintf(stderr, "Incorrect file format\n");
		exit(0);
	}
	rewind(fp);
	//==========File open==================================
	FILE * ipf;
	if(ipfilename!=NULL)
	{
		ipf = fopen(ipfilename, "rb");
	}
	else
	{
		 ipf = stdin;
	}
	if(ipf==NULL)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}
//===============================================================
	
	int j;
	int k[17][48] = {};

//==================================================================================


	char * line = calloc(200, sizeof(char));
	line[0] = '\0';
	char *test = calloc(4, sizeof(char));
	test[0] = '\0';
	
//==================Line count===========================
	for(i=0;i<14;i++)
	{
		int f_isp = 1;
		if(fgets(line, 200, fp)==NULL)
			break;
		char* pos = strchr(line,'=');
		
		int pos_int = (int)(pos-line);

		strncpy(test, line, pos_int);
		test[pos_int+1] = '\0';

		if(strncmp(test, "PC1", 3)==0)
    	{
    		f_isp = 0;
    		if(!testPC1e(line))
    		{
    			fprintf(stderr, "PC1 table error!\n");
    			exit(0);
    		}

    	}
    	if(strncmp(test, "PC2", 3)==0)
    	{
    		f_isp = 0;
    		if(!testPC2e(line))
    		{
    			fprintf(stderr, "PC2 table error!\n");
    			exit(0);
    		}
    		
    	}
    	if(strncmp(test, "V", 1)==0)
    	{
    		if(!testVe(line))
    		{
    			fprintf(stderr, "V table error!\n" );
    			exit(0);
    		}

    	}
    	if(strncmp(test, "E", 1)==0)
    	{
    		
    			if(!testEe(line))
    			{
    				fprintf(stderr, "E table error!\n");
    				exit(0);
    			}
    	}
    	if(strncmp(test, "IP", 2)==0 )
		{
    		
    		if(!testIPe(line))
    		{
    			fprintf(stderr, "IP table error!\n");

    			exit(0);
    		}
    	}
    	if(strncmp(test, "S", 1)==0)
    	{
    		if(!testSe(line, test))
    		{
    			fprintf(stderr, "%s table error!\n", test);
    			exit(0);
    		}
    	}

    	if(strncmp(test, "P", 1)==0 && f_isp==1)
    	{
    	
    		if(!testPe(line))
    		{
    			fprintf(stderr, "P table error!\n");
    			exit(0);
    		}
    	}
    



    	else
    		continue;
    		test[0] = '\0';
		test[(int)(pos-line-1)] = '\0';
		line[0] = '\0';

	}
//=========================Key to binary===============================================
//Convert key to binary. 
	int * str = calloc(64, sizeof(int));
	int str_ctr = 0;
    char * str_temp = calloc(4, sizeof(char));
    int ptr = 0;
    
	for(i=0;i<16;i++)
    {
        str_temp  = hex_to_bin(key[i]);
        for(j=0;j<4;j++)
	        str[str_ctr++] = ((int)str_temp[j])-48;

        ptr+=4;
    }


//=============================C0,D0===========================================
    // Convert 64 to 28+28
    int * c0 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
    	c0[i] =  str[pc1a[i]-1];
    }
   	fprintf(stderr, "(C0,D0)=");
    toHex(c0, 28);
    int * d0 = calloc(29, sizeof(int));

	for(i=0;i<28;i++)
    {
    	d0[i] =  str[pc1b[i]-1];
    }
    toHex(d0, 28);
    fprintf(stderr, "\n");
    
//================================== C1,D1=========================================
    int * c1 = calloc(29, sizeof(int));
    int * d1 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
    	c1[i] = c0[i];
    	d1[i] = d0[i];
    }



    if(v_arr[0]==1) // shift by 1
    {	
    	
    	int xi = c1[0];
    	int yi = d1[0];
    	for(j=0;j<28;j++)
    	{
    		c1[j] = c1[j+1];
    		d1[j] = d1[j+1];
    	}
    	c1[27] = xi;
    	d1[27] = yi;  		
    	
    }

    else if(v_arr[0]==2) // shift by 2.
    {
    	int xi = c1[0];
    	int yi = d1[0];
    	for(j=0;j<28;j++)
    	{
    		c1[j] = c1[j+1];
    		d1[j] = d1[j+1];
    	}
    	c1[27] = xi;
    	d1[27] = yi;  

    	xi = c1[0];
    	yi = d1[0];
    	for(j=0;j<28;j++)
    	{
    		c1[j] = c1[j+1];
    		d1[j] = d1[j+1];
    	}
    	c1[27] = xi;
    	d1[27] = yi;  		

    }
    fprintf(stderr, "(C1,D1)=");
    toHex(c1, 28);
    toHex(d1, 28);
 
    int * t1= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
    	t1[i] =  c1[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
    	t1[i] = d1[j];
    }
    for(i=0;i<48;i++)
    {
    	k[1][i] =  t1[pc2[i]-1];
    }
    
   fprintf(stderr, "\nk1=");
    toHex(k[1], 48);
    fprintf(stderr, "\n" ); 

//=================================C2, D2==============================================

	int * c2 = calloc(29, sizeof(int));
    int * d2 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
    	c2[i] = c1[i];
    	d2[i] = d1[i];
    }



    if(v_arr[1]==1) // shift by 1
    {	
    	
    	int xi = c2[0];
    	int yi = d2[0];
    	for(j=0;j<28;j++)
    	{
    		c2[j] = c2[j+1];
    		d2[j] = d2[j+1];
    	}
    	c2[27] = xi;
    	d2[27] = yi;  		
    	
    }

    else if(v_arr[1]==2) // shift by 2.
    {
    	int xi = c2[0];
    	int yi = d2[0];
    	for(j=0;j<28;j++)
    	{
    		c2[j] = c2[j+1];
    		d2[j] = d2[j+1];
    	}
    	c2[27] = xi;
    	d2[27] = yi;  

    	xi = c2[0];
    	yi = d2[0];
    	for(j=0;j<28;j++)
    	{
    		c2[j] = c2[j+1];
    		d2[j] = d2[j+1];
    	}
    	c2[27] = xi;
    	d2[27] = yi;  		

    }
    fprintf(stderr, "(C2,D2)=");
    toHex(c2, 28);
    toHex(d2, 28);

    int * t2= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t2[i] =  c2[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t2[i] = d2[j];
    }
    for(i=0;i<48;i++)
    {
        k[2][i] =  t2[pc2[i]-1];
    }
   fprintf(stderr, "\nk2=");
   toHex(k[2], 48);
   fprintf(stderr, "\n" ); 

//=========================================C3, D3==============================================================================
	int * c3 = calloc(29, sizeof(int));
    int * d3 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
    	c3[i] = c2[i];
    	d3[i] = d2[i];
    }



    if(v_arr[2]==1) // shift by 1
    {	
 
    	int xi = c3[0];
    	int yi = d3[0];
    	for(j=0;j<28;j++)
    	{
    		c3[j] = c3[j+1];
    		d3[j] = d3[j+1];
    	}
    	c3[27] = xi;
    	d3[27] = yi;  		
    	
    }

    else if(v_arr[2]==2) // shift by 2.
    {
    	int xi = c3[0];
    	int yi = d3[0];
    	for(j=0;j<28;j++)
    	{
    		c3[j] = c3[j+1];
    		d3[j] = d3[j+1];
    	}
    	c3[27] = xi;
    	d3[27] = yi;  

    	xi = c3[0];
    	yi = d3[0];
    	for(j=0;j<28;j++)
    	{
    		c3[j] = c3[j+1];
    		d3[j] = d3[j+1];
    	}
    	c3[27] = xi;
    	d3[27] = yi;  		

    }
    fprintf(stderr, "(C3,D3)=");
    toHex(c3, 28);
    toHex(d3, 28);

    int * t3= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t3[i] =  c3[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t3[i] = d3[j];
    }
    for(i=0;i<48;i++)
    {
        k[3][i] =  t3[pc2[i]-1];
    }
   fprintf(stderr, "\nk3=");
   toHex(k[3], 48);
   fprintf(stderr, "\n" ); 
//====================================C4, D4=======================================================================
    	
	int * c4 = calloc(29, sizeof(int));
    int * d4 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c4[i] = c3[i];
        d4[i] = d3[i];
    }

 

    if(v_arr[3]==1) // shift by 1
    {   
   
        int xi = c4[0];
        int yi = d4[0];
        for(j=0;j<28;j++)
        {
            c4[j] = c4[j+1];
            d4[j] = d4[j+1];
        }
        c4[27] = xi;
        d4[27] = yi;        
        
    }

    else if(v_arr[3]==2) // shift by 2.
    {
        int xi = c4[0];
        int yi = d4[0];
        for(j=0;j<28;j++)
        {
            c4[j] = c4[j+1];
            d4[j] = d4[j+1];
        }
        c4[27] = xi;
        d4[27] = yi;  

        xi = c4[0];
        yi = d4[0];
        for(j=0;j<28;j++)
        {
            c4[j] = c4[j+1];
            d4[j] = d4[j+1];
        }
        c4[27] = xi;
        d4[27] = yi;        

    }
    fprintf(stderr, "(C4,D4)=");
    toHex(c4, 28);
    toHex(d4, 28);

    int * t4= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t4[i] =  c4[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t4[i] = d4[j];
    }
    for(i=0;i<48;i++)
    {
        k[4][i] =  t4[pc2[i]-1];
    }
   fprintf(stderr, "\nk4=");
   toHex(k[4], 48);
   fprintf(stderr, "\n" ); 
//=====================C5, D5==============================

    int * c5 = calloc(29, sizeof(int));
    int * d5 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c5[i] = c4[i];
        d5[i] = d4[i];
    }


    if(v_arr[4]==1) // shift by 1
    {   

        int xi = c5[0];
        int yi = d5[0];
        for(j=0;j<28;j++)
        {
            c5[j] = c5[j+1];
            d5[j] = d5[j+1];
        }
        c5[27] = xi;
        d5[27] = yi;        
        
    }

    else if(v_arr[4]==2) // shift by 2.
    {
        int xi = c5[0];
        int yi = d5[0];
        for(j=0;j<28;j++)
        {
            c5[j] = c5[j+1];
            d5[j] = d5[j+1];
        }
        c5[27] = xi;
        d5[27] = yi;  

        xi = c5[0];
        yi = d5[0];
        for(j=0;j<28;j++)
        {
            c5[j] = c5[j+1];
            d5[j] = d5[j+1];
        }
        c5[27] = xi;
        d5[27] = yi;        

    }
    fprintf(stderr, "(C5,D5)=");
    toHex(c5, 28);
    toHex(d5, 28);

    int * t5= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t5[i] =  c5[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t5[i] = d5[j];
    }
    for(i=0;i<48;i++)
    {
        k[5][i] =  t5[pc2[i]-1];
    }
   fprintf(stderr, "\nk5=");
   toHex(k[5], 48);
   fprintf(stderr, "\n" ); 
//=======================C6,D6================================================================================

	int * c6 = calloc(29, sizeof(int));
    int * d6 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c6[i] = c5[i];
        d6[i] = d5[i];
    }


    if(v_arr[5]==1) // shift by 1
    {   

        int xi = c6[0];
        int yi = d6[0];
        for(j=0;j<28;j++)
        {
            c6[j] = c6[j+1];
            d6[j] = d6[j+1];
        }
        c6[27] = xi;
        d6[27] = yi;        
        
    }

    else if(v_arr[5]==2) // shift by 2.
    {
        int xi = c6[0];
        int yi = d6[0];
        for(j=0;j<28;j++)
        {
            c6[j] = c6[j+1];
            d6[j] = d6[j+1];
        }
        c6[27] = xi;
        d6[27] = yi;  

        xi = c6[0];
        yi = d6[0];
        for(j=0;j<28;j++)
        {
            c6[j] = c6[j+1];
            d6[j] = d6[j+1];
        }
        c6[27] = xi;
        d6[27] = yi;        

    }
    fprintf(stderr, "(C6,D6)=");
    toHex(c6, 28);
    toHex(d6, 28);

    int * t6= calloc(56, sizeof(int));
   
    for(i=0;i<28;i++)
    {
        t6[i] =  c6[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t6[i] = d6[j];
    }
    for(i=0;i<48;i++)
    {
        k[6][i] =  t6[pc2[i]-1];
    }
   fprintf(stderr, "\nk6=");
   toHex(k[6], 48);
   fprintf(stderr, "\n" ); 

//===========================C7,D7==================================================

    int * c7 = calloc(29, sizeof(int));
    int * d7 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c7[i] = c6[i];
        d7[i] = d6[i];
    }

  

    if(v_arr[6]==1) // shift by 1
    {   

        int xi = c7[0];
        int yi = d7[0];
        for(j=0;j<28;j++)
        {
            c7[j] = c7[j+1];
            d7[j] = d7[j+1];
        }
        c7[27] = xi;
        d7[27] = yi;        
        
    }

    else if(v_arr[6]==2) // shift by 2.
    {
        int xi = c7[0];
        int yi = d7[0];
        for(j=0;j<28;j++)
        {
            c7[j] = c7[j+1];
            d7[j] = d7[j+1];
        }
        c7[27] = xi;
        d7[27] = yi;  

        xi = c7[0];
        yi = d7[0];
        for(j=0;j<28;j++)
        {
            c7[j] = c7[j+1];
            d7[j] = d7[j+1];
        }
        c7[27] = xi;
        d7[27] = yi;        

    }
    fprintf(stderr, "(C7,D7)=");
    toHex(c7, 28);
    toHex(d7, 28);

    int * t7= calloc(56, sizeof(int));
 
    for(i=0;i<28;i++)
    {
        t7[i] =  c7[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t7[i] = d7[j];
    }
    for(i=0;i<48;i++)
    {
        k[7][i] =  t7[pc2[i]-1];
    }
   fprintf(stderr, "\nk7=");
   toHex(k[7], 48);
   fprintf(stderr, "\n" ); 
//=======================================C8,D8==============================================

    int * c8 = calloc(29, sizeof(int));
    int * d8 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c8[i] = c7[i];
        d8[i] = d7[i];
    }

   

    if(v_arr[7]==1) // shift by 1
    {   
   
        int xi = c8[0];
        int yi = d8[0];
        for(j=0;j<28;j++)
        {
            c8[j] = c8[j+1];
            d8[j] = d8[j+1];
        }
        c8[27] = xi;
        d8[27] = yi;        
        
    }

    else if(v_arr[7]==2) // shift by 2.
    {
        int xi = c8[0];
        int yi = d8[0];
        for(j=0;j<28;j++)
        {
            c8[j] = c8[j+1];
            d8[j] = d8[j+1];
        }
        c8[27] = xi;
        d8[27] = yi;  

        xi = c8[0];
        yi = d8[0];
        for(j=0;j<28;j++)
        {
            c8[j] = c8[j+1];
            d8[j] = d8[j+1];
        }
        c8[27] = xi;
        d8[27] = yi;        

    }
    fprintf(stderr, "(C8,D8)=");
    toHex(c8, 28);
    toHex(d8, 28);
    
    int * t8= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t8[i] =  c8[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t8[i] = d8[j];
    }
    for(i=0;i<48;i++)
    {
        k[8][i] =  t8[pc2[i]-1];
    }
   fprintf(stderr, "\nk8=");
   toHex(k[8], 48);
   fprintf(stderr, "\n" ); 

//===================================C9,D9===================================
    int * c9 = calloc(29, sizeof(int));
    int * d9 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c9[i] = c8[i];
        d9[i] = d8[i];
    }


    if(v_arr[8]==1) // shift by 1
    {   

        int xi = c9[0];
        int yi = d9[0];
        for(j=0;j<28;j++)
        {
            c9[j] = c9[j+1];
            d9[j] = d9[j+1];
        }
        c9[27] = xi;
        d9[27] = yi;        
        
    }

    else if(v_arr[8]==2) // shift by 2.
    {
        int xi = c9[0];
        int yi = d9[0];
        for(j=0;j<28;j++)
        {
            c9[j] = c9[j+1];
            d9[j] = d9[j+1];
        }
        c9[27] = xi;
        d9[27] = yi;  

        xi = c9[0];
        yi = d9[0];
        for(j=0;j<28;j++)
        {
            c9[j] = c9[j+1];
            d9[j] = d9[j+1];
        }
        c9[27] = xi;
        d9[27] = yi;        

    }
    fprintf(stderr, "(C9,D9)=");
    toHex(c9, 28);
    toHex(d9, 28);
    //fprintf(stderr, "\n" ); 

    int * t9= calloc(56, sizeof(int));
    //int * k9= calloc(48, sizeof(int));
    for(i=0;i<28;i++)
    {
        t9[i] =  c9[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t9[i] = d9[j];
    }
    for(i=0;i<48;i++)
    {
        k[9][i] =  t9[pc2[i]-1];
    }
   fprintf(stderr, "\nk9=");
   toHex(k[9], 48);
   fprintf(stderr, "\n" ); 

//==================================C10, D10==================================
    int * c10 = calloc(29, sizeof(int));
    int * d10 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c10[i] = c9[i];
        d10[i] = d9[i];
    }



    if(v_arr[9]==1) // shift by 1
    {   
        int xi = c10[0];
        int yi = d10[0];
        for(j=0;j<28;j++)
        {
            c10[j] = c10[j+1];
            d10[j] = d10[j+1];
        }
        c10[27] = xi;
        d10[27] = yi;        
        
    }

    else if(v_arr[9]==2) // shift by 2.
    {
        int xi = c10[0];
        int yi = d10[0];
        for(j=0;j<28;j++)
        {
            c10[j] = c10[j+1];
            d10[j] = d10[j+1];
        }
        c10[27] = xi;
        d10[27] = yi;  

        xi = c10[0];
        yi = d10[0];
        for(j=0;j<28;j++)
        {
            c10[j] = c10[j+1];
            d10[j] = d10[j+1];
        }
        c10[27] = xi;
        d10[27] = yi;        

    }
    fprintf(stderr, "(C10,D10)=");
    toHex(c10, 28);
    toHex(d10, 28);
    
    int * t10= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t10[i] =  c10[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t10[i] = d10[j];
    }
    for(i=0;i<48;i++)
    {
        k[10][i] =  t10[pc2[i]-1];
    }
   fprintf(stderr, "\nk10=");
   toHex(k[10], 48);
   fprintf(stderr, "\n" ); 
//================================C11,D11========================================
    int * c11 = calloc(29, sizeof(int));
    int * d11 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c11[i] = c10[i];
        d11[i] = d10[i];
    }



    if(v_arr[10]==1) // shift by 1
    {   
  
        int xi = c11[0];
        int yi = d11[0];
        for(j=0;j<28;j++)
        {
            c11[j] = c11[j+1];
            d11[j] = d11[j+1];
        }
        c11[27] = xi;
        d11[27] = yi;        
        
    }

    else if(v_arr[10]==2) // shift by 2.
    {
        int xi = c11[0];
        int yi = d11[0];
        for(j=0;j<28;j++)
        {
            c11[j] = c11[j+1];
            d11[j] = d11[j+1];
        }
        c11[27] = xi;
        d11[27] = yi;  

        xi = c11[0];
        yi = d11[0];
        for(j=0;j<28;j++)
        {
            c11[j] = c11[j+1];
            d11[j] = d11[j+1];
        }
        c11[27] = xi;
        d11[27] = yi;        

    }
    fprintf(stderr, "(C11,D11)=");
    toHex(c11, 28);
    toHex(d11, 28);

    int * t11= calloc(56, sizeof(int));
 
    for(i=0;i<28;i++)
    {
        t11[i] =  c11[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t11[i] = d11[j];
    }
    for(i=0;i<48;i++)
    {
        k[11][i] =  t11[pc2[i]-1];
    }
   fprintf(stderr, "\nk11=");
   toHex(k[11], 48);
   fprintf(stderr, "\n" ); 
//===========================C12,D12===========================================

    int * c12 = calloc(29, sizeof(int));
    int * d12 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c12[i] = c11[i];
        d12[i] = d11[i];
    }



    if(v_arr[11]==1) // shift by 1
    {   
   
        int xi = c12[0];
        int yi = d12[0];
        for(j=0;j<28;j++)
        {
            c12[j] = c12[j+1];
            d12[j] = d12[j+1];
        }
        c12[27] = xi;
        d12[27] = yi;        
        
    }

    else if(v_arr[11]==2) // shift by 2.
    {
        int xi = c12[0];
        int yi = d12[0];
        for(j=0;j<28;j++)
        {
            c12[j] = c12[j+1];
            d12[j] = d12[j+1];
        }
        c12[27] = xi;
        d12[27] = yi;  

        xi = c12[0];
        yi = d12[0];
        for(j=0;j<28;j++)
        {
            c12[j] = c12[j+1];
            d12[j] = d12[j+1];
        }
        c12[27] = xi;
        d12[27] = yi;        

    }
    fprintf(stderr, "(C12,D12)=");
    toHex(c12, 28);
    toHex(d12, 28);

    int * t12= calloc(56, sizeof(int));
 
    for(i=0;i<28;i++)
    {
        t12[i] =  c12[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t12[i] = d12[j];
    }
    for(i=0;i<48;i++)
    {
        k[12][i] =  t12[pc2[i]-1];
    }
   fprintf(stderr, "\nk12=");
   toHex(k[12], 48);
   fprintf(stderr, "\n" ); 
//=======================C13,D13====================================================

    int * c13 = calloc(29, sizeof(int));
    int * d13 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c13[i] = c12[i];
        d13[i] = d12[i];
    }



    if(v_arr[12]==1) // shift by 1
    {   
   
        int xi = c13[0];
        int yi = d13[0];
        for(j=0;j<28;j++)
        {
            c13[j] = c13[j+1];
            d13[j] = d13[j+1];
        }
        c13[27] = xi;
        d13[27] = yi;        
        
    }

    else if(v_arr[12]==2) // shift by 2.
    {
        int xi = c13[0];
        int yi = d13[0];
        for(j=0;j<28;j++)
        {
            c13[j] = c13[j+1];
            d13[j] = d13[j+1];
        }
        c13[27] = xi;
        d13[27] = yi;  

        xi = c13[0];
        yi = d13[0];
        for(j=0;j<28;j++)
        {
            c13[j] = c13[j+1];
            d13[j] = d13[j+1];
        }
        c13[27] = xi;
        d13[27] = yi;        

    }
    fprintf(stderr, "(C13,D13)=");
    toHex(c13, 28);
    toHex(d13, 28);

    int * t13= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t13[i] =  c13[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t13[i] = d13[j];
    }
    for(i=0;i<48;i++)
    {
        k[13][i] =  t13[pc2[i]-1];
    }
   fprintf(stderr, "\nk13=");
   toHex(k[13], 48);
   fprintf(stderr, "\n" ); 

//====================C14,D14========================================
    int * c14 = calloc(29, sizeof(int));
    int * d14 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c14[i] = c13[i];
        d14[i] = d13[i];
    }



    if(v_arr[13]==1) // shift by 1
    {   

        int xi = c14[0];
        int yi = d14[0];
        for(j=0;j<28;j++)
        {
            c14[j] = c14[j+1];
            d14[j] = d14[j+1];
        }
        c14[27] = xi;
        d14[27] = yi;        
        
    }

    else if(v_arr[13]==2) // shift by 2.
    {
        int xi = c14[0];
        int yi = d14[0];
        for(j=0;j<28;j++)
        {
            c14[j] = c14[j+1];
            d14[j] = d14[j+1];
        }
        c14[27] = xi;
        d14[27] = yi;  

        xi = c14[0];
        yi = d14[0];
        for(j=0;j<28;j++)
        {
            c14[j] = c14[j+1];
            d14[j] = d14[j+1];
        }
        c14[27] = xi;
        d14[27] = yi;        

    }
    fprintf(stderr, "(C14,D14)=");
    toHex(c14, 28);
    toHex(d14, 28);


    int * t14= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t14[i] =  c14[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t14[i] = d14[j];
    }
    for(i=0;i<48;i++)
    {
        k[14][i] =  t14[pc2[i]-1];
    }
   fprintf(stderr, "\nk14=");
   toHex(k[14], 48);
   fprintf(stderr, "\n" ); 
//========================C15,D15=================================
    int * c15 = calloc(29, sizeof(int));
    int * d15 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c15[i] = c14[i];
        d15[i] = d14[i];
    }



    if(v_arr[14]==1) // shift by 1
    {   

        int xi = c15[0];
        int yi = d15[0];
        for(j=0;j<28;j++)
        {
            c15[j] = c15[j+1];
            d15[j] = d15[j+1];
        }
        c15[27] = xi;
        d15[27] = yi;        
        
    }

    else if(v_arr[14]==2) // shift by 2.
    {
        int xi = c15[0];
        int yi = d15[0];
        for(j=0;j<28;j++)
        {
            c15[j] = c15[j+1];
            d15[j] = d15[j+1];
        }
        c15[27] = xi;
        d15[27] = yi;  

        xi = c15[0];
        yi = d15[0];
        for(j=0;j<28;j++)
        {
            c15[j] = c15[j+1];
            d15[j] = d15[j+1];
        }
        c15[27] = xi;
        d15[27] = yi;        

    }
    fprintf(stderr, "(C15,D15)=");
    toHex(c15, 28);
    toHex(d15, 28);
    int * t15= calloc(56, sizeof(int));
   
    for(i=0;i<28;i++)
    {
        t15[i] =  c15[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t15[i] = d15[j];
    }
    for(i=0;i<48;i++)
    {
        k[15][i] =  t15[pc2[i]-1];
    }
   fprintf(stderr, "\nk15=");
   toHex(k[15], 48);
   fprintf(stderr, "\n" ); 
//=====================================C16,D16============================================
    int * c16 = calloc(29, sizeof(int));
    int * d16 = calloc(29, sizeof(int));
    for(i=0;i<28;i++)
    {
        c16[i] = c15[i];
        d16[i] = d15[i];
    }

    if(v_arr[15]==1) // shift by 1
    {   

        int xi = c16[0];
        int yi = d16[0];
        for(j=0;j<28;j++)
        {
            c16[j] = c16[j+1];
            d16[j] = d16[j+1];
        }
        c16[27] = xi;
        d16[27] = yi;        
        
    }

    else if(v_arr[15]==2) // shift by 2.
    {
        int xi = c16[0];
        int yi = d16[0];
        for(j=0;j<28;j++)
        {
            c16[j] = c16[j+1];
            d16[j] = d16[j+1];
        }
        c16[27] = xi;
        d16[27] = yi;  

        xi = c16[0];
        yi = d16[0];
        for(j=0;j<28;j++)
        {
            c16[j] = c16[j+1];
            d16[j] = d16[j+1];
        }
        c16[27] = xi;
        d16[27] = yi;        

    }
    fprintf(stderr, "(C16,D16)=");
    toHex(c16, 28);
    toHex(d16, 28);
    fprintf(stderr, "\n" ); 

    int * t16= calloc(56, sizeof(int));

    for(i=0;i<28;i++)
    {
        t16[i] =  c16[i];
    }
    for(i=28,j=0;i<56&&j<28;i++, j++)
    {
        t16[i] = d16[j];
    }
    for(i=0;i<48;i++)
    {
        k[16][i] =  t16[pc2[i]-1];
    }
   fprintf(stderr, "k16=");
   toHex(k[16], 48);
   fprintf(stderr, "\n" ); 
//=============================All keys generated.=======================
    int fless=1;
    int flag_first = 1;
    int l[16][32] = {};
    int r[16][32] = {};
    int dec;
    int after_xor[48] = {0};
    int rt[48] = {0};
    int after_p[32] = {0};
    int temp[6] = {0};
    int after_s[48] = {0};
    int temp1[8] = {0};
    int input_bin1[64] = {0};
    char ip_str[8] = {};


while(!feof(ipf))
{   
   
   for(i=0;i<8;i++)
   {
   		if(feof(ipf))
   		{
   			i=i-1;
   			fless = 0;
   			break;
   		}
   		ip_str[i] = getc(ipf);
   }
   if(fless==0 && i==0)
   		break;
   	while(i<8)
   	{
   		ip_str[i] = NULL;
   		i++;
   	}
	


	
	char * ip_temp = calloc(8, sizeof(char));
	int ipbin_ctr = 0;
	for(i=0;i<8;i++) //"Now "
	{
		ip_temp = byte_to_binary(ip_str[i]);
		
		for(j=0;j<8;j++)
		{
			input_bin1[ipbin_ctr++] = ((int)ip_temp[j]) - 48 ;
		}

	}
    free(ip_temp);
	// use input_bin1 as the 64 bit as the input. 
	// Pass this through the IP table and generate l0 and r0.
    if(df==0)
    {

               int q;

            	//
               for(i=0;i<32;i++)
               {

               		l[0][i] = input_bin1[ip_arr[i]-1];
               }
               for(i=32, j=0; i<64&&j<32;i++,j++)
               {
               		r[0][j] = input_bin1[ip_arr[i]-1];
               }
             
               if(flag_first==1)
               {
               		fprintf(stderr, "(L0,R0)=" );
            	   	toHex(l[0], 32);
            	   	toHex(r[0], 32);
            	   	fprintf(stderr, "\n" ); 
               }
               
               	
            	for(q=0;q<16;q++)
            	{
            		//===============================Expansion takes r0 - gives r ================================================
            		   	 
            			
            		   for(i=0;i<48;i++)
            		   {
            		   	rt[i] = r[q][e_arr[i]-1];
            		   }

            		//===============XOR======================
            			
            		



            		   	for(i=0;i<48;i++)
            		   	{
            		   		after_xor[i] = rt[i] ^ k[q+1][i];
            		   	}


            		 //============================S=============================================
            		
            		   int li=0;
            		   int k_ctr = 0;
            		   //int val = 0;
            		   int m;
            		   int s_val = 0;
            		   for(i=0;i<8;i++) // i:0-8 l: 0-8, 8-16..
            		   {
            		   		for(j=0;j<6;j++)
            		   		{
            				   	temp[j] = after_xor[li++];
            				   	
            		   		}
            		   		solve_s(temp);
            		   		
            		   		if(i+1==1)
            		   		{
            		   			s_val = s1[row][col];
            		   		}
            		   		if(i+1==2)
            		   		{
            		   			s_val = s2[row][col];
            		   		}
            		   		if(i+1==3)
            		   		{
            		   			s_val = s3[row][col];
            		   		}
            		   		if(i+1==4)
            		   		{
            		   			s_val = s4[row][col];
            		   		}
            		   		if(i+1==5)
            		   		{
            		   			s_val = s5[row][col];
            		   		}
            		   		if(i+1==6)
            		   		{
            		   			s_val = s6[row][col];
            		   		}
            		   		if(i+1==7)
            		   		{
            		   			s_val = s7[row][col];
            		   		}
            		   		if(i+1==8)
            		   		{
            		   			s_val = s8[row][col];
            		   		}
            				
            				char * x= calloc(4, sizeof(char));
            				tobinstr(s_val, 4, x);
            				
            				for(m=0;m<4;m++)
            					after_s[k_ctr++] = ((int)x[m])-48;
                            free(x);
            			
            		   }

            		//=============================P============================================

            	
            		   	for(i=0;i<32;i++)
            		   		after_p[i] = after_s[p_arr[i]-1];


            		//===========================XOR with l[i-1]=========================================
            	
            		for(i=0;i<32;i++)
            			r[q+1][i] = after_p[i]^l[q][i];

         
            		for(i=0;i<32;i++)
            			l[q+1][i] = r[q][i];
            		
            		if(flag_first==1)
            		{
            			fprintf(stderr, "(L%d,R%d)=", q+1, q+1);
            			toHex(l[q+1],32);
            			toHex(r[q+1], 32); 
            			fprintf(stderr, "\n" ); 

            		}

           



            	}

            //=====================================IP-1======================
           
            	int * out = calloc(64, sizeof(int));
            	int * fout = calloc(64, sizeof(int));
            	for(i=0;i<64;i++)
            	{	
            		invip_arr[i] = get_pos(i+1)+1;
            	}
            	for(i=0;i<32;i++)
            	{
            		out[i] = r[16][i];
            	}
            	for(i=32, j=0;i<64&&j<32;i++, j++)
            	{
            		out[i] = l[16][j];
            	}
            	for(i=0;i<64;i++)
            		fout[i] = out[invip_arr[i]-1];
            


          
            	int temp[8] = {};
            	int kz=0;
            	for(i=0;i<8;i++)
            	{
            		for(j=0;j<8;j++)
            		{
            			temp[j] = fout[kz++];
            			
            			
            		}
            		int ch_num = binary_decimal(temp);
            		fprintf(stdout, "%c",(char)ch_num);
            	
            		
            	}
            	flag_first=0;
    }

    else if(df==1) // decryption
    {
   

               int q;

                //
               for(i=0;i<32;i++)
               {

                    r[0][i] = input_bin1[ip_arr[i]-1];
               }
               for(i=32, j=0; i<64&&j<32;i++,j++)
               {
                    l[0][j] = input_bin1[ip_arr[i]-1];
               }
              
               if(flag_first==1)
               {
                    fprintf(stderr, "(L0,R0)=" );
                    toHex(r[0], 32);
                    toHex(l[0], 32);
                    fprintf(stderr, "\n" ); 
               }


                for(q=0,dec=16;q<16&&dec>=1;q++,dec--)
                {
                   
                    //===============================Expansion takes r0 - gives r ================================================
                         
                     
                       
                       for(i=0;i<48;i++)
                       {
                        rt[i] = l[q][e_arr[i]-1];
                       }

                    //===============XOR======================
                        
                        



                        for(i=0;i<48;i++)
                        {
                            after_xor[i] = rt[i] ^ k[dec][i];
                        }


                     //============================S=============================================
                      
                      for(i=0;i<6;i++)
                        temp[i] = 0;
                       int li=0;
                       int k_ctr = 0;
                       //int val = 0;
                       int m;
                       int s_val = 0;
                       for(i=0;i<8;i++) // i:0-8 l: 0-8, 8-16..
                       {
                            for(j=0;j<6;j++)
                            {
                                temp[j] = after_xor[li++];
                                
                            }
                            row = 0; col = 0;
                            solve_s(temp);
                            
                            if(i+1==1)
                            {
                                s_val = s1[row][col];
                            }
                            if(i+1==2)
                            {
                                s_val = s2[row][col];
                            }
                            if(i+1==3)
                            {
                                s_val = s3[row][col];
                            }
                            if(i+1==4)
                            {
                                s_val = s4[row][col];
                            }
                            if(i+1==5)
                            {
                                s_val = s5[row][col];
                            }
                            if(i+1==6)
                            {
                                s_val = s6[row][col];
                            }
                            if(i+1==7)
                            {
                                s_val = s7[row][col];
                            }
                            if(i+1==8)
                            {
                                s_val = s8[row][col];
                            }
                       
                            char * x= calloc(4, sizeof(char));
                            tobinstr(s_val, 4, x);
                            
                            for(m=0;m<4;m++)
                                after_s[k_ctr++] = ((int)x[m])-48;
                            free(x);

                        
                       }

                    //=============================P============================================

                        
                        for(i=0;i<32;i++)
                            after_p[i] = after_s[p_arr[i]-1];


                    //===========================XOR with r[i-1]=========================================
                  
                    for(i=0;i<32;i++)
                        l[q+1][i] = after_p[i]^r[q][i];

                    //int l1[32] = {};
                    for(i=0;i<32;i++)
                        r[q+1][i] = l[q][i];
                    
                    if(flag_first==1)
                    {
                        fprintf(stderr, "(L%d,R%d)=", q+1, q+1);
                        toHex(r[q+1],32);
                        toHex(l[q+1], 32); 
                        fprintf(stderr, "\n" ); 

                    }




                } // end of for loop

            //=====================================IP-1======================
               
                int * out = calloc(64, sizeof(int));
                int * fout = calloc(64, sizeof(int));
                for(i=0;i<64;i++)
                {   
                    invip_arr[i] = get_pos(i+1)+1;
                }
                for(i=0;i<32;i++)
                {
                    out[i] = l[16][i];
                }
                for(i=32, j=0;i<64&&j<32;i++, j++)
                {
                    out[i] = r[16][j];
                }
                for(i=0;i<64;i++)
                    fout[i] = out[invip_arr[i]-1];
            
                int kz=0;
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        temp1[j] = fout[kz++];
                        
                        
                    }
                    int ch_num = binary_decimal(temp1);
                    fprintf(stdout, "%c",(char)ch_num);
                    
                    
                }
                free(fout);
                free(out);
                flag_first=0;
    }
}

}


