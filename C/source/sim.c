//Mod C by ackerman
//NOT C POSIX
#include <stdio.h>
#include <string.h>
#include "gbConfig.h"
#include "gbGlobal.h"
#include "z80.h"
#include "zxallbin.h"
#include <time.h>



//Inicio compila C POSIX
//RegisterPair regBC,regDE;
//void Z80Init();
//Fin compila C POSIX


#ifdef cfg_use_tstates_64bits
 #ifdef cfg_use_time_fast
  static unsigned long tstates;
 #else
  unsigned long tstates;
 #endif 
#else
 #ifdef cfg_use_time_fast
  static unsigned int tstates;
 #else
  unsigned int tstates;
 #endif 
#endif 

#ifdef cfg_use_z80RAM_fast
 static unsigned char z80Ram[0x10000];
#else
 unsigned char z80Ram[0x10000];
#endif 

#ifdef cfg_use_z80Ports_fast
 static unsigned char z80Ports[0x10000];
#else
 unsigned char z80Ports[0x10000];
#endif

#ifdef cfg_use_finish_fast
 static unsigned char finish;
#else
 unsigned char finish;
#endif 
char cadLog[64];

#ifdef cfg_use_time_show
 time_t rawtime;    
 struct tm * timeinfo;

 void ShowTime(void);

 void ShowTime()
 {
  time (&rawtime);
  timeinfo= localtime(&rawtime);
  printf(" (%02i:%02i:%02i) ",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
 }
#endif
 

//*****************
//* z80operations *
//*****************
unsigned char fetchOpcode(unsigned short int address)
{
 tstates += 4;
 //uint8_t opcode = z80Ram[address];
 //return (address != 0x0005 ? opcode : Z80_breakpoint(address, opcode));   
 #ifdef WITH_BREAKPOINT_SUPPORT
  return z80Ram[address];
 #else
  uint8_t opcode = z80Ram[address];
  return (address != 0x0005 ? opcode : Z80_breakpoint(address, opcode));
 #endif
}

unsigned char peek8(unsigned short int address)
{
 tstates += 3;
 return z80Ram[address];         
}

void poke8(unsigned short int address, unsigned char value)
{
 tstates += 3;
 z80Ram[address] = value;     
}

unsigned short int peek16(unsigned short int address)
{
 uint8_t lsb = peek8(address);
 uint8_t msb = peek8(address + 1);
 return (msb << 8) | lsb;         
}

void poke16(unsigned short int address, RegisterPair word)
{
 poke8(address, word.byte8.lo);
 poke8(address + 1, word.byte8.hi);     
}

void addressOnBus(unsigned short int address, int wstates)
{
 tstates += wstates;     
}

unsigned char inPort(unsigned short int port)
{
    tstates += 3;
    return z80Ports[port];
}

void outPort(unsigned short int port, unsigned char value)
{
    tstates += 4;
    z80Ports[port] = value;     
}

void interruptHandlingTime(int wstates)
{
 tstates += wstates;     
}

unsigned char isActiveINT(void)
{
 return false;         
}


unsigned char Z80_breakpoint(unsigned short int address, unsigned char opcode)
{
 // Emulate CP/M Syscall at address 5
 unsigned char contStr;
 switch (REG_C)
 {
  case 0: // BDOS 0 System Reset
  {
   printf("Z80 reset after %u t-states\n",tstates);
   finish = true;
   break;
  }
  case 2: // BDOS 2 console char output
  {
   putchar((char)REG_E);
   break;
  }
  case 9: // BDOS 9 console string output (string terminated by "$")
  {
   uint16_t strAddr = REG_DE;
   #if defined(cfg_use_time_show) && defined(cfg_use_time_per_line)
    ShowTime();
   #endif 
   contStr=0;
   cadLog[0]='\0';
   while (z80Ram[strAddr] != '$')
   {
    cadLog[contStr]= (char)z80Ram[strAddr];
    strAddr++;
    contStr++;
    if (contStr>32){
     break;
    }
   }
   cadLog[contStr]='\0';
   printf("%s",cadLog);
   break;
  }
  default:
  {
   printf("BDOS Call %c\n",REG_C);
   finish = true;
   break;
  }
 }
 // opcode would be modified before the decodeOpcode method
 return opcode;
}









void runTest()
{
 Z80Init();
 tstates=0;
 memset(z80Ram,0,0x10000);
 memcpy(&z80Ram[0x100],zx_all_bin,8590);
 reset();
 finish = false;

 z80Ram[0] = (uint8_t) 0xC3;
 z80Ram[1] = 0x00;
 z80Ram[2] = 0x01; // JP 0x100 CP/M TPA
 z80Ram[5] = (uint8_t) 0xC9; // Return from BDOS call

 while (!finish)
 {
  execute();
 }
}


//********
//* MAIN *
//********
int main(int argc, char *argv[])
{
 #if defined(cfg_use_time_show) && !defined(cfg_use_time_per_line)
  ShowTime();
  runTest();
  ShowTime();
 #else
  runTest();
 #endif
  
 return 0;
}
