#ifndef		DMA_PRIVATE_H
#define		DMA_PRIVATE_H

// DMA base address
#define DMA_BASE_ADDRESS 0x40020000

// DMA registers
#define DMA_ISR(channel)    (*((volatile unsigned int *)(DMA_BASE_ADDRESS + (channel * 0x14))))
#define DMA_IFCR(channel)   (*((volatile unsigned int *)(DMA_BASE_ADDRESS + 0x08 + (channel * 0x14))))
#define DMA_CCR(channel)    (*((volatile unsigned int *)(DMA_BASE_ADDRESS + 0x04 + (channel * 0x14))))
#define DMA_CNDTR(channel)  (*((volatile unsigned int *)(DMA_BASE_ADDRESS + 0x0C + (channel * 0x14))))
#define DMA_CPAR(channel)   (*((volatile unsigned int *)(DMA_BASE_ADDRESS + 0x10 + (channel * 0x14))))
#define DMA_CMAR(channel)   (*((volatile unsigned int *)(DMA_BASE_ADDRESS + 0x14 + (channel * 0x14))))

//typedef	struct
//{
//	volatile	u32		CCR;
//	volatile	u32		CNDTR;
//	volatile	u32		CPAR;
//	volatile	u32		CMAR;
//	volatile	u32		Reserverd;
//}Channel_Type;
//
//typedef	struct
//{
//	volatile	u32		ISR;
//	volatile	u32		IFCR;
//	Channel_Type		Channel[7];
//
//}DMA_Type;
//
//
//
//#define		DMA1	((DMA_Type *)0x40020000)

#endif
