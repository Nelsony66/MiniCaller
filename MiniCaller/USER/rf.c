#include "global.h"

void RF_Init()
{       
  GPIO_Init(GPIOB,GPIO_Pin_1|GPIO_Pin_2,GPIO_Mode_Out_PP_Low_Slow);//初始化LED端口
  
}

unsigned char send_rfdata_433(unsigned char *inp)
{
   
	unsigned char i,j,cnt,t;
	unsigned char *dat;
	
	unsigned char data=0;
	
      
        unsigned int RF_X[5]={0x00,0x00,0x00,0x00,0x00};//Len_H,Len_L,Data_H,Data_L,Data_Vol;
        unsigned int  timer_cnt=0;
     
        
	    dat=inp;
        // syniot version
  
        RF_X[0]= 5365;	  // 引导码高电平
	RF_X[1]= 1600;    // 引导码低电平
	RF_X[2]= 400;	  // 0 高电平占空比
	RF_X[3]= 800;     // 1高电平占空比
    
  
     /*   RF_X[0]= 5135;	  // 引导码高电平
	RF_X[1]= 1600;    // 引导码低电平
	RF_X[2]= 400;	  // 0 高电平占空比
	RF_X[3]= 800;     // 1高电平占空比*/
	

	for(cnt=0;cnt<SEND_RF_TIMES;cnt++)
	{
	  
              Delay_ms(15);
			timer_cnt=0;
			RF433_H;
			while(timer_cnt<RF_X[0])
				{
				timer_cnt++;
				}	
			RF433_L;
			timer_cnt=0;
			while(timer_cnt<RF_X[1])
				{
				timer_cnt++;
				}	
 
			for(j=0;j<5;j++)   //cishu genggai
			{
				data = 	dat[j];
				for(i=0;i<8;i++)
				{
					t=data&0x80;
					data=data<<1;
					if(t== 0x80)
					{
					   RF433_H;
					   timer_cnt=0;
					   while(timer_cnt<RF_X[3])
					   {
                                              timer_cnt++;
					   }
					   RF433_L;
					   timer_cnt=0;
					while(timer_cnt<RF_X[2])
					{
							timer_cnt++;
					}						
					}	
					else
					{
					   	RF433_H;
					  
						timer_cnt=0;
						while(timer_cnt<RF_X[2])
						{
							
								timer_cnt++;
									
						}
					   RF433_L;
					
						timer_cnt=0;
					while(timer_cnt<RF_X[3])
						{
							
								timer_cnt++;
								
						}					
					}	
				}
		}		
	}
	return 0;
}

       
  



unsigned char send_rfdata_315(unsigned char *inp)
{
   
	unsigned char i,j,cnt,t;
	unsigned char *dat;
	unsigned int  time_len=0;
	unsigned char data=0;
	
       
        unsigned int RF_X[5]={0x00,0x00,0x00,0x00,0x00};//Len_H,Len_L,Data_H,Data_L,Data_Vol;
        unsigned int  timer_cnt=0;
     
        
	    dat=inp;
        // syniot version
        time_len=18600;
      
	RF_X[2]= 610;	  // short 
	RF_X[3]= 1760;		  // long
    
  
	

	for(cnt=0;cnt<SEND_RF_TIMES;cnt++)
	{
	
			timer_cnt=0;
			RF315_H;
			while(timer_cnt<RF_X[2])
				{
				timer_cnt++;
				}	
			RF315_L;
			timer_cnt=0;
			while(timer_cnt<time_len)
				{
				timer_cnt++;
				}	

			for(j=2;j<5;j++)
			{
				data = 	dat[j];
				for(i=0;i<8;i++)
				{
					t=data&0x80;
					data=data<<1;
					if(t== 0x80)
					{
					   RF315_H;
					   timer_cnt=0;
					   while(timer_cnt<RF_X[3])
					   {
                                              timer_cnt++;
					   }
					   RF315_L;
					   timer_cnt=0;
					while(timer_cnt<RF_X[2])
					{
							timer_cnt++;
					}						
					}	
					else
					{
					   	RF315_H;
					  
						timer_cnt=0;
						while(timer_cnt<RF_X[2])
						{
							
								timer_cnt++;
									
						}
					   RF315_L;
					
						timer_cnt=0;
					while(timer_cnt<RF_X[3])
						{
							
								timer_cnt++;
								
						}					
					}	
				}
		}		
	}
	return 0;
}

