
/* Select SPI FLASH: ChipSelect pin low  */
#define Select_Flash()     GPIO_ResetBits(GPIOA, GPIO_Pin_4)
/* Deselect SPI FLASH: ChipSelect pin high */
#define NotSelect_Flash()    GPIO_SetBits(GPIOA, GPIO_Pin_4)



void SPI_Flash_Init(void);	         //SPI初始化
u8 SPI_Flash_ReadByte(void);		//flash操作基本函数，读一个字节
u8 SPI_Flash_SendByte(u8 byte);		//	FLASH操作基本函数，发送一个字节
void FlashWaitBusy(void);			    //Flash忙检测
void FlashReadID(void);		//读取flashID四个字节
	


