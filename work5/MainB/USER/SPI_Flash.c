#include "stm32f10x.h"
#include "SPI_Flash.h"
#include "stm32f10x_spi.h"

void SPI_Flash_Init(void);
u8 SPI_Flash_ReadByte(void);
u8 SPI_Flash_SendByte(u8 byte);

void wip(void);
void wen(void);
void wdis(void);
void wsr(void);
unsigned char rdsr(void);
void FlashReadID(void);
void sect_clr(unsigned long a1);
void SST25_W_BLOCK(uint32_t addr, u8 *readbuff, uint16_t BlockSize);
void SST25_R_BLOCK(uint32_t addr, u8 *readbuff, uint16_t BlockSize);
unsigned char SST25_buffer[4096],fac_id,dev_id;
unsigned char SST25_buffer99[4096];

//++++++++++++写使能 +++++++++++++++++
void wen(void){
	Select_Flash();
	SPI_Flash_SendByte(0x06);
	NotSelect_Flash();
}

//+++++ +++++++ 写禁止 ++++++++++++++++++
void wdis(void){

	Select_Flash();
	SPI_Flash_SendByte(0x04); 
	NotSelect_Flash();
	wip();
	
}	
//+++++++++++++++++++++++++++++++
void wsr(void){	
	Select_Flash();
	SPI_Flash_SendByte(0x50);
	NotSelect_Flash();
	//Delay(0xff);
	Select_Flash();
	SPI_Flash_SendByte(0x01);
	SPI_Flash_SendByte(0x00); 
	NotSelect_Flash();
    wip();
	
}

//++++++++++ 忙检测 +++++++++
void wip(void){
	unsigned char a=1;
	while((a&0x01)==1) a=rdsr();	

}
//++++++++++++++++++++++++++++++++
unsigned char rdsr(void){
	unsigned char busy;
	Select_Flash();
	SPI_Flash_SendByte(0x05);
	busy = SPI_Flash_ReadByte();
	NotSelect_Flash();
	return(busy);
	
}
            
//+++++++++++++字节写入+++++++++++++++++++++++
void bw1(unsigned long a1,unsigned char a2){

	
	wsr();	  
    wen();  
	Select_Flash();   
	SPI_Flash_SendByte(0x02);
	SPI_Flash_SendByte((a1&0xffffff)>>16);
	SPI_Flash_SendByte((a1&0xffff)>>8);
	SPI_Flash_SendByte(a1&0xff);
	SPI_Flash_SendByte(a2);	
	NotSelect_Flash();
	wip();				   	
	wdis();
	
}

//+++++++++字节读++++++++++++++++++++++++++++
unsigned char br1(unsigned long a1){
	unsigned char i;
	Select_Flash();
    SPI_Flash_SendByte(0x03);
	SPI_Flash_SendByte((a1&0xffffff)>>16);
	SPI_Flash_SendByte((a1&0xffff)>>8);
	SPI_Flash_SendByte(a1&0xff);
	i=SPI_Flash_ReadByte();	
	NotSelect_Flash(); 
	return(i);
}


//++++++++++连续读++++++++++++++++++++++++++++
void r_sect(unsigned long a){
	unsigned int i;
	Select_Flash();
	SPI_Flash_SendByte(0x03);
	SPI_Flash_SendByte((a&0xffffff)>>16);
	SPI_Flash_SendByte((a&0xffff)>>8);
	SPI_Flash_SendByte(a&0xff);
	for(i=0; i<816; i++){	
		SST25_buffer[i]=SPI_Flash_ReadByte();
	}
	NotSelect_Flash();
}

//+++++++++++++连续写入+++++++++++++++++++++++
void w_sect(unsigned long a1){
	unsigned int i=0,a2;
	
	wsr();
  	wen(); 
	Select_Flash();    
	SPI_Flash_SendByte(0xad);
	SPI_Flash_SendByte((a1&0xffffff)>>16);
	SPI_Flash_SendByte((a1&0xffff)>>8);
	SPI_Flash_SendByte(a1&0xff);
  	SPI_Flash_SendByte(SST25_buffer[0]);
	SPI_Flash_SendByte(SST25_buffer[1]);
	NotSelect_Flash();
	i=2;
	while(i<4096){
		a2=130;
		while(a2>0) a2--;
		Select_Flash();
		SPI_Flash_SendByte(0xad);
		SPI_Flash_SendByte(SST25_buffer[i++]);
		SPI_Flash_SendByte(SST25_buffer[i++]);
		NotSelect_Flash();
	}
	
	a2=130;
	while(a2>0) a2--;
	wdis();	
	Select_Flash();  
	wip();	
	
}
//++++++++++块读++++++++++++++++++++++++++++
void SST25_R_BLOCK(uint32_t addr, u8 *readbuff, uint16_t BlockSize){
	unsigned int i=0;
	Select_Flash();
	SPI_Flash_SendByte(0x03);
	SPI_Flash_SendByte((addr&0xffffff)>>16);
	SPI_Flash_SendByte((addr&0xffff)>>8);
	SPI_Flash_SendByte(addr&0xff);
	while(i<BlockSize){	
		readbuff[i++]=SPI_Flash_ReadByte();
	}
	NotSelect_Flash();
}
//+++++++++++++块写入+++++++++++++++++++++++
void SST25_W_BLOCK(uint32_t addr, u8 *readbuff, uint16_t BlockSize){
	unsigned int i=0,a2;
	sect_clr(addr);    //清除addr开始的4096个字节的块
	wsr();
  	wen(); 
	Select_Flash();    
	SPI_Flash_SendByte(0xad);
	SPI_Flash_SendByte((addr&0xffffff)>>16);
	SPI_Flash_SendByte((addr&0xffff)>>8);
	SPI_Flash_SendByte(addr&0xff);
  	SPI_Flash_SendByte(readbuff[0]);
	SPI_Flash_SendByte(readbuff[1]);
	NotSelect_Flash();
	i=2;
	while(i<BlockSize){
		a2=130;
		while(a2>0) a2--;
		Select_Flash();
		SPI_Flash_SendByte(0xad);
		SPI_Flash_SendByte(readbuff[i++]);
		SPI_Flash_SendByte(readbuff[i++]);
		NotSelect_Flash();
	}
	
	a2=130;
	while(a2>0) a2--;
	wdis();	
	Select_Flash();  
	wip();	
	
}
//++++++++++++++++++++++++++++++++
void sect_clr(unsigned long a1){
	//wen();
	
	wsr();
	wen();     
	Select_Flash();

	SPI_Flash_SendByte(0x20);
	SPI_Flash_SendByte((a1&0xffffff)>>16);          //addh
	SPI_Flash_SendByte((a1&0xffff)>>8);          //addl 
	SPI_Flash_SendByte(a1&0xff);          //wtt
	NotSelect_Flash();
	wip();
	
}

//========读器件厂家信息
void FlashReadID(void)
{

	Select_Flash();	
  	SPI_Flash_SendByte(0x90);
	SPI_Flash_SendByte(0x00);
	SPI_Flash_SendByte(0x00);
	SPI_Flash_SendByte(0x00);
  	fac_id= SPI_Flash_ReadByte();		 //BFH: SST
	dev_id= SPI_Flash_ReadByte();	     //41H:SST25VF016B
  
  	NotSelect_Flash();	
}

/*******************************************************************************
* Function Name  : SPI_FLASH_Init
* Description    : Initializes the peripherals used by the SPI FLASH driver.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI_Flash_Init(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
   
  /* Enable SPI1 GPIOA clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 ,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  /* Configure SPI1 pins: SCK, MISO and MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);



  /* Configure PA.4 as Output push-pull, used as Flash Chip select */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

 
  /* SPI1 configuration */ 
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);
  
  /* Enable SPI1  */
  SPI_Cmd(SPI1, ENABLE);   
  NotSelect_Flash();
  
}

/*******************************************************************************
* Function Name  : SPI_FLASH_ReadByte
* Description    : Reads a byte from the SPI Flash.
*                  This function must be used only if the Start_Read_Sequence
*                  function has been previously called.
* Input          : None
* Output         : None
* Return         : Byte Read from the SPI Flash.
*******************************************************************************/
u8 SPI_Flash_ReadByte(void)
{
  return (SPI_Flash_SendByte(0));
}

/*******************************************************************************
* Function Name  : SPI_FLASH_SendByte
* Description    : Sends a byte through the SPI interface and return the byte 
*                  received from the SPI bus.
* Input          : byte : byte to send.
* Output         : None
* Return         : The value of the received byte.
*******************************************************************************/
u8 SPI_Flash_SendByte(u8 byte)
{
  /* Loop while DR register in not emplty */
  while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
  //NotSelect_Flash();  while(1);
  /* Send byte through the SPI2 peripheral */
  SPI_I2S_SendData(SPI1, byte);

  /* Wait to receive a byte */
  while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  return SPI_I2S_ReceiveData(SPI1);
}

