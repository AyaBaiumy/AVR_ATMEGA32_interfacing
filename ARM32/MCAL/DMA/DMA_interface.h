#ifndef		DMA_INTERFACE_H
#define		DMA_INTERFACE_H


// DMA channel identifiers
typedef enum {
    DMA_Channel_1,
    DMA_Channel_2,
    DMA_Channel_3,
    DMA_Channel_4,
    DMA_Channel_5,
    DMA_Channel_6,
    DMA_Channel_7
} DMA_Channel;
// DMA data transfer direction
typedef enum {
    DMA_Direction_PeripheralToMemory,
    DMA_Direction_MemoryToPeripheral,
    DMA_Direction_MemoryToMemory
} DMA_Direction;

// DMA interrupt status
typedef enum {
    DMA_IT_TC,      // Transfer Complete
    DMA_IT_HT,      // Half Transfer
    DMA_IT_TE       // Transfer Error
} DMA_IT;

// DMA interrupt callback function type
typedef void (*DMA_Callback)(void);

// DMA initialization function
void DMA_Init(DMA_Channel channel);

// DMA configuration functions
void DMA_SetMemoryAddress(DMA_Channel channel, u32 address);
void DMA_SetPeripheralAddress(DMA_Channel channel, u32 address);
void DMA_SetTransferSize(DMA_Channel channel, u32 size);
void DMA_SetTransferDirection(DMA_Channel channel, DMA_Direction direction);
void DMA_EnableInterrupt(DMA_Channel channel, DMA_IT interrupt);
void DMA_SetInterruptCallback(DMA_Channel channel, DMA_Callback callback);

// DMA start and stop functions
void DMA_Start(DMA_Channel channel);
void DMA_Stop(DMA_Channel channel);

#endif /* DMA_INTERFACE_H */
