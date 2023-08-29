
#include "Std_types.h"
#include "Bit_Math.h"

#include "DMA_INTERFACE.h"
#include "DMA_private.h"

// DMA initialization function
void DMA_Init(DMA_Channel channel)
{
    DMA_ISR(channel) = 0xFFFFFFFF;
    DMA_IFCR(channel) = 0xFFFFFFFF;
}

// DMA configuration functions
void DMA_SetMemoryAddress(DMA_Channel channel, u32 address)
{
    DMA_CMAR(channel) = address;
}

void DMA_SetPeripheralAddress(DMA_Channel channel, u32 address)
{
    DMA_CPAR(channel) = address;
}

void DMA_SetTransferSize(DMA_Channel channel, u32 size)
{
    DMA_CNDTR(channel) = size;
}

void DMA_SetTransferDirection(DMA_Channel channel, DMA_Direction direction)
{
    if (direction == DMA_Direction_PeripheralToMemory)
    {
        DMA_CCR(channel) &= ~0x00000002;  // Clear DIR bit
    }
    else if (direction == DMA_Direction_MemoryToPeripheral)
    {
        DMA_CCR(channel) |= 0x00000002;   // Set DIR bit
    }
    else if (direction == DMA_Direction_MemoryToMemory)
    {
        DMA_CCR(channel) |= 0x00004000;   // Set MEM2MEM bit
    }
}

void DMA_EnableInterrupt(DMA_Channel channel, DMA_IT interrupt)
{
    DMA_CCR(channel) |= (1 << (interrupt + 1));
}

void DMA_SetInterruptCallback(DMA_Channel channel, DMA_Callback callback)
{
    // Implement your code to store the callback function and invoke it during interrupt handling
    // This may involve using function pointers or an interrupt vector table, depending on your implementation
    // You can store the callback function in a global array or structure, indexed by the channel number
    // Inside the interrupt handler, you can retrieve the callback function based on the channel number and invoke it
}

// DMA start and stop functions
void DMA_Start(DMA_Channel channel)
{
    DMA_CCR(channel) |= 0x00000001; // Set EN bit
}

void DMA_Stop(DMA_Channel channel)
{
    DMA_CCR(channel) &= ~0x00000001; // Clear EN bit
}
