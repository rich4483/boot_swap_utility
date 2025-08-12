/*
 * Name:
 * Author:
 *
 * Description:
 *     "Main" for creation of reprogramming build.
 *     This version however is used as part of a Boot Swap Utility.
*/
#ifdef RPGM_BUILD

#include "hwlbltyp.h"

/*
 * These are defined as global variables, so they may be accessed in the debugger.
*/
BYTE Ve_y_EraseStatus;
BYTE Ve_y_WriteStatus;

void main(void)
{
    WORD Le_i_Index;
    LONGWORD Le_g_Length;
    LONGWORD Le_g_Source;
    LONGWORD Le_g_Destination;
    
    /* Initialize to undetermined. FLASH_SUCCESS == 0, FLASH_FAILURE == 1 */
    Ve_y_EraseStatus = 5;
    Ve_y_WriteStatus = 6;
    
    /* Call the required init function before erasing. */
    InitHWIO_Flash();
    
    /*
     * Erase the existing BootLoader, block-by-block.
     * Boot occupies 0x0000 thru 0x3FFF (i.e. 16kB).
     * For the NEC micro, each block is 4096 bytes (i.e. 4kB),
     * so there are a total of 4 blocks occupied by Boot.
    */
    for (Le_i_Index=0;Le_i_Index<4;Le_i_Index++)
    {
        Ve_y_EraseStatus = EraseHWIO_FlashBlock(Le_i_Index);
    }
    
    /* Erase cal presence pattern */
    EraseHWIO_FlashBlock((WORD)0x100);
    /* Erase app presence pattern */
    EraseHWIO_FlashBlock((WORD)0xFF);
    EraseHWIO_FlashBlock((WORD)0xFE);
    EraseHWIO_FlashBlock((WORD)0xFD);
    EraseHWIO_FlashBlock((WORD)0xFC);
    
    /* Call the required init function before writing. */
    InitHWIO_Flash();
    
    /* Write new BootLoader */
    Le_g_Length = 0x4000;           /* Download Boot binary is 16kB */
    Le_g_Source = 0x3FF5000;        /* Download Boot binary is here */
    Le_g_Destination = 0x0000;      /* New Boot should be written here */
    
    Ve_y_WriteStatus = WriteHWIO_FlashMemory(Le_g_Length,Le_g_Source,Le_g_Destination);
    
    /* Wait for watchdog timer to reset us */
    while(1)
    {
        ;
    }
}
#endif

