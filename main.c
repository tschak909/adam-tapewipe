/**
 * Tape wipe
 *
 * @author Thomas Cherryhomes
 * @email <thom.cherryhomes@gmail.com>
 */

#include <msx.h>
#include <conio.h>
#include <stdbool.h>
#include "eoslib.h"

#define DEV_TAPE1 8
#define BLOCK_FILL_BYTE 0x00 // NOP

char buf[1024];

void progress(unsigned long block)
{
  vpoke(MODE2_ATTR + 768 + (int)block, INK_DARK_RED);
  gotoxy(28,23); cprintf("%02lX",block);
}

void main(void)
{
  unsigned long block;
  
  while (true)
    {
      memset(buf,BLOCK_FILL_BYTE,sizeof(buf));
      
      msx_color(15,4,4);
      msx_set_mode(2);
     
      gotoxy(0,0); 
      cprintf("TAPE WIPE\n\nINSERT TAPE IN DRIVE 1\n\nAND PRESS ANY KEY");
      cgetc();
      
      clrscr();
     
      gotoxy(11,12);
      cprintf("WIPING TAPE");

      for (block=0;block<256;block++)
	{
	  eos_writeblock(&buf,DEV_TAPE1,block);
	  progress(block);
	}
      
      gotoxy(2,2); cprintf("DONE. ANY KEY TO RESTART.");
      cgetc();
    }
}
