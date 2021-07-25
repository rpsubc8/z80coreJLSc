#ifndef _GB_GLOBAL_H
 #define _GB_GLOBAL_H
 
#include "gbConfig.h" 


 //Inicio Z80_H
 typedef union 
 {
  struct {
   unsigned char lo, hi;
  } byte8;
  unsigned short int word;
 } RegisterPair;
 
 extern unsigned char Z80_opCode;
 extern unsigned char Z80_prefixOpcode;
 extern unsigned char Z80_execDone;
 // Posiciones de los flags
 extern const unsigned char Z80_CARRY_MASK;
 extern const unsigned char Z80_ADDSUB_MASK;
 extern const unsigned char Z80_PARITY_MASK;
 extern const unsigned char Z80_OVERFLOW_MASK; // alias de PARITY_MASK
 extern const unsigned char Z80_BIT3_MASK;
 extern const unsigned char Z80_HALFCARRY_MASK;
 extern const unsigned char Z80_BIT5_MASK;
 extern const unsigned char Z80_ZERO_MASK;
 extern const unsigned char Z80_SIGN_MASK; 
 extern const unsigned char Z80_FLAG_53_MASK;
 extern const unsigned char Z80_FLAG_SZ_MASK;
 extern const unsigned char Z80_FLAG_SZHN_MASK;
 extern const unsigned char Z80_FLAG_SZP_MASK;
 extern const unsigned char Z80_FLAG_SZHP_MASK; 
 extern unsigned char Z80_regA;
 extern unsigned char Z80_sz5h3pnFlags;
 extern unsigned char Z80_carryFlag;
 extern RegisterPair regBC, regBCx, regDE, regDEx, regHL, regHLx;
 extern unsigned char flagQ, lastFlagQ;
 extern RegisterPair regAFx;
 extern RegisterPair regPC; 
 extern RegisterPair regIX;   
 extern RegisterPair regIY;
 extern RegisterPair regSP;
 extern unsigned char Z80_regI;
 extern unsigned char Z80_regR;
 extern unsigned char Z80_regRbit7;
 extern unsigned char Z80_ffIFF1;
 extern unsigned char Z80_ffIFF2;
 extern unsigned char Z80_pendingEI; 
 extern unsigned char Z80_activeNMI;
 extern unsigned char Z80_modeINT;
 extern unsigned char Z80_halted;
 extern unsigned char Z80_pinReset;
 extern RegisterPair memptr;
 extern unsigned char Z80_sz53n_addTable[256];
 extern unsigned char Z80_sz53pn_addTable[256];
 extern unsigned char Z80_sz53n_subTable[256];
 extern unsigned char Z80_sz53pn_subTable[256];
 
#ifdef WITH_BREAKPOINT_SUPPORT
 extern unsigned char Z80_breakpointEnabled;
#endif 
 
 //Fin Z80_H

 
 //Inicio simulador 
 #ifdef cfg_use_tstates_64bits
  #ifndef cfg_use_time_fast
   extern unsigned long tstates;
  #endif 
 #else
  #ifndef cfg_use_time_fast
   extern unsigned int tstates;
  #endif
 #endif
  
 #ifndef cfg_use_z80RAM_fast
  extern unsigned char z80Ram[0x10000];
 #endif 
 
 #ifndef cfg_use_z80Ports_fast
  extern unsigned char z80Ports[0x10000];
 #endif 
 
 #ifndef cfg_use_finish_fast
  extern unsigned char finish;
 #endif 
 //Fin simulador

#endif


