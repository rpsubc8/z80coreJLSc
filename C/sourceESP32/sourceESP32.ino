//Mod C by ackerman
//NOT C POSIX
#include <stdio.h>
#include <string.h>
#include "gbConfig.h"
#include "gbGlobal.h"
//#include "z80.h"
#include "zxallbin.h"
#include <time.h>

//Inicio GB_GLOBAL_H
 //Inicio Z80_H
 typedef union 
 {
  struct {
   unsigned char lo, hi;
  } byte8;
  unsigned short int word;
 } RegisterPair;
  
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
  extern unsigned char z80Ports[0x2000]; //Deberia ser 0x10000
 #endif 
 
 #ifndef cfg_use_finish_fast
  extern unsigned char finish;
 #endif 
 //Fin simulador
//Fin GB_GLOBAL_H






//Inicio Z80_H
#define uint8_t unsigned char
#define int8_t char
#define uint16_t unsigned short int
 
#define IM0 0
#define IM1 1
#define IM2 2

#define true 1
#define false 0


#define REG_B   regBC.byte8.hi
#define REG_C   regBC.byte8.lo
#define REG_BC  regBC.word
#define REG_Bx  regBCx.byte8.hi
#define REG_Cx  regBCx.byte8.lo
#define REG_BCx regBCx.word

#define REG_D   regDE.byte8.hi
#define REG_E   regDE.byte8.lo
#define REG_DE  regDE.word
#define REG_Dx  regDEx.byte8.hi
#define REG_Ex  regDEx.byte8.lo
#define REG_DEx regDEx.word

#define REG_H   regHL.byte8.hi
#define REG_L   regHL.byte8.lo
#define REG_HL  regHL.word
#define REG_Hx  regHLx.byte8.hi
#define REG_Lx  regHLx.byte8.lo
#define REG_HLx regHLx.word

#define REG_IXh regIX.byte8.hi
#define REG_IXl regIX.byte8.lo
#define REG_IX  regIX.word

#define REG_IYh regIY.byte8.hi
#define REG_IYl regIY.byte8.lo
#define REG_IY  regIY.word

#define REG_Ax  regAFx.byte8.hi
#define REG_Fx  regAFx.byte8.lo
#define REG_AFx regAFx.word

#define REG_PCh regPC.byte8.hi
#define REG_PCl regPC.byte8.lo
#define REG_PC  regPC.word

#define REG_S   regSP.byte8.hi
#define REG_P   regSP.byte8.lo
#define REG_SP  regSP.word

#define REG_W   memptr.byte8.hi
#define REG_Z   memptr.byte8.lo
#define REG_WZ  memptr.word



//#define getRegA() regA
//#define setRegA(a) regA=a
//#define getRegB() REG_B
//#define setRegB(a) REG_B=a
//#define getRegC() REG_C
//#define setRegC(a) REG_C=a
//#define getRegD() REG_D
//#define setRegD(a) REG_D=a
//#define getRegE() REG_E
//#define setRegE(a) REG_E=a
//#define getRegH() REG_H
//#define setRegH(a) REG_H=a
//#define getRegL() REG_L
//#define setRegL(a) REG_L=a

//#define getRegAx() REG_Ax
//#define setRegAx(a) REG_Ax=a
//#define getRegFx() REG_Fx
//#define setRegFx(a) REG_Fx=a
//#define getRegBx() REG_Bx
//#define setRegBx(a) REG_Bx=a
//#define getRegCx() REG_Cx
//#define setRegCx(a) REG_Cx=a
//#define getRegDx() REG_Dx
//#define setRegDx(a) REG_Dx=a
//#define getRegEx() REG_Ex
//#define setRegEx(a) REG_Ex=a
//#define getRegHx() REG_Hx
//#define setRegHx(a) REG_Hx=a
//#define getRegLx() REG_Lx
//#define setRegLx(a) REG_Lx=a

//#define getRegAFx() REG_AFx
//#define setRegAFx(a) REG_AFx=a
//#define getRegBC() REG_BC
//#define setRegBC(a) REG_BC=a
//#define getRegBCx() REG_BCx
//#define setRegBCx(a) REG_BCx=a
//#define getRegDE() REG_DE
//#define setRegDE(a) REG_DE=a
//#define getRegDEx() REG_DEx
//#define setRegDEx(a) REG_DEx=a
//#define getRegHL() REG_HL
//#define setRegHL(a) REG_HL=a
//#define getRegHLx() REG_HLx
//#define setRegHLx(a) REG_HLx=a



void Z80Init(void);


//Operaciones externas
unsigned char getRegA(void);
void setRegA(unsigned char value);

unsigned char getRegB(void);
void setRegB(unsigned char value);

unsigned char getRegC(void);
void setRegC(unsigned char value);

unsigned char getRegD(void);
void setRegD(unsigned char value);

unsigned char getRegE(void);
void setRegE(unsigned char value);

unsigned char getRegH(void);
void setRegH(unsigned char value);

unsigned char getRegL(void);
void setRegL(unsigned char value);



unsigned char getRegAx(void);
void setRegAx(unsigned char value);

unsigned char getRegFx(void);
void setRegFx(unsigned char value);

unsigned char getRegBx(void);
void setRegBx(unsigned char value);

unsigned char getRegCx(void);
void setRegCx(unsigned char value);

unsigned char getRegDx(void);
void setRegDx(unsigned char value);

unsigned char getRegEx(void);
void setRegEx(unsigned char value);

unsigned char getRegHx(void);
void setRegHx(unsigned char value);

unsigned char getRegLx(void);
void setRegLx(unsigned char value);





unsigned short int getRegAF(void);
void setRegAF(unsigned short int word);

unsigned short int getRegAFx(void);
void setRegAFx(unsigned short int word);

unsigned short int getRegBC(void);
void setRegBC(unsigned short int word);

unsigned short int getRegBCx(void);
void setRegBCx(unsigned short int word);

unsigned short int getRegDE(void);
void setRegDE(unsigned short int word);

unsigned short int getRegDEx(void);
void setRegDEx(unsigned short int word);

unsigned short int getRegHL(void);
void setRegHL(unsigned short int word);

unsigned short int getRegHLx(void);
void setRegHLx(unsigned short int word);





unsigned short int getRegPC(void);
void setRegPC(unsigned short int address);

unsigned short int getRegSP(void);
void setRegSP(unsigned short int word);

unsigned short int getRegIX(void);
void setRegIX(unsigned short int word);

unsigned short int getRegIY(void);
void setRegIY(unsigned short int word);

unsigned char getRegI(void);
void setRegI(unsigned char value);

unsigned char getRegR(void);
void setRegR(unsigned char value);

unsigned short int getMemPtr(void);
void setMemPtr(unsigned short int word);

unsigned char isCarryFlag(void);
void setCarryFlag(unsigned char state);

unsigned char isAddSubFlag(void);
void setAddSubFlag(unsigned char state);

unsigned char isParOverFlag(void);
void setParOverFlag(unsigned char state);

unsigned char isBit3Flag(void);
void setBit3Fag(unsigned char state);

unsigned char isHalfCarryFlag(void);
void setHalfCarryFlag(unsigned char state);

unsigned char isBit5Flag(void);
void setBit5Flag(unsigned char state);

unsigned char isZeroFlag(void);
void setZeroFlag(unsigned char state);

unsigned char isSignFlag(void);
void setSignFlag(unsigned char state);
    
unsigned char getFlags(void);
void setFlags(unsigned char regF);





unsigned char isIFF1(void);
void setIFF1(unsigned char state);

unsigned char isIFF2(void);
void setIFF2(unsigned char state);

unsigned char isNMI(void);
void setNMI(unsigned char nmi);
    
void triggerNMI(void);
    
unsigned char getIM(void);
void setIM(unsigned char mode);

unsigned char isHalted(void);
void setHalted(unsigned char state);
    
void setPinReset(void);

unsigned char isPendingEI(void);
void setPendingEI(unsigned char state);



void reset(void);
    
void execute(void);

#ifdef WITH_BREAKPOINT_SUPPORT
 unsigned char Z80_isBreakpoint(void);
 void Z80_setBreakpoint(unsigned char state);
#endif


//Fin operaciones externas





void rlc(unsigned char * oper8); //referencia
void rl(unsigned char * oper8); //referencia
void sla(unsigned char * oper8); //referencia
void sll(unsigned char * oper8); //referencia
void rrc(unsigned char * oper8);//referencia
void rr(unsigned char * oper8);//referencia
void sra(unsigned char * oper8);//referencia
void srl(unsigned char * oper8);//referencia
void inc8(unsigned char * oper8);//referencia
void dec8(unsigned char * oper8);//referencia
void add(unsigned char oper8);
void adc(unsigned char oper8);
void add16(RegisterPair *reg16, unsigned short int oper16);//referencia
void adc16(unsigned short int reg16);
void sub(unsigned char oper8);
void sbc(unsigned char oper8);
void sbc16(unsigned short int reg16);
void and_(unsigned char oper8);
void xor_(unsigned char oper8);
void or_(unsigned char oper8);
void cp(unsigned char oper8);
void daa(void);
unsigned short int pop(void);
void push(unsigned short int word);
void ldi(void);
void ldd(void);
void cpi(void);
void cpd(void);
void ini(void);
void ind(void);
void outi(void);
void outd(void);
void bitTest(unsigned char mask, unsigned char reg);
void interrupt(void);
void nmi(void);
void decodeOpcode(unsigned char opCode);
void decodeCB(void);
void decodeDDFD(unsigned char opCode, RegisterPair * regIXY); //referencia
void decodeDDFDCB(unsigned char opCode, unsigned short int address);
void decodeED(unsigned char opCode);     




RegisterPair getPairIR(void);

void copyToRegister(uint8_t opCode, uint8_t value);
uint8_t breakpoint(uint16_t address, uint8_t opcode);













//Z80Operations
/*
unsigned char fetchOpcode(unsigned short int address);

unsigned char peek8(unsigned short int address);
void poke8(unsigned short int address, unsigned char value);

unsigned short int peek16(unsigned short int adddress);
void poke16(unsigned short int address, RegisterPair word);

unsigned char inPort(unsigned short int port);
void outPort(unsigned short int port, unsigned char value);

void addressOnBus(unsigned short int address, int wstates);
void interruptHandlingTime(int wstates);

unsigned char isActiveINT(void);
*/

unsigned char Z80_breakpoint(unsigned short int address, unsigned char opcode);
//Fin Z80_H


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
 static unsigned char z80Ports[0x2000];
#else
 unsigned char z80Ports[0x2000]; //Debe ser 0x10000
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
  Serial.printf(" (%02i:%02i:%02i) ",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
 }
#endif





//Begin z80.c
//Mod C by ackerman
//NOT C POSIX
// Original author Jose Luis Sanchez C++
//... https://github.com/jsanchezv/Z80Core
//... commit c4f267e3564fa89bd88fd2d1d322f4d6b0069dbd
//... GPL 3
//... v1.0.0 (13/02/2017)
//    quick & dirty conversion by dddddd (AKA deesix) 
//#ifndef _Z80_C
// #define _Z80_C
#include "gbConfig.h"
#include "gbGlobal.h"
#include "z80.h"
#include <string.h>

static unsigned char Z80_opCode;
static unsigned char Z80_prefixOpcode = 0x00;
static unsigned char Z80_execDone;
// Posiciones de los flags
static const unsigned char Z80_CARRY_MASK = 0x01;
static const unsigned char Z80_ADDSUB_MASK = 0x02;
static const unsigned char Z80_PARITY_MASK = 0x04;
static const unsigned char Z80_OVERFLOW_MASK = 0x04; // alias de PARITY_MASK
static const unsigned char Z80_BIT3_MASK = 0x08;
static const unsigned char Z80_HALFCARRY_MASK = 0x10;
static const unsigned char Z80_BIT5_MASK = 0x20;
static const unsigned char Z80_ZERO_MASK = 0x40;
static const unsigned char Z80_SIGN_MASK = 0x80;
//const unsigned char Z80_FLAG_53_MASK = Z80_BIT5_MASK | Z80_BIT3_MASK;
//const unsigned char Z80_FLAG_SZ_MASK = Z80_SIGN_MASK | Z80_ZERO_MASK;
//const unsigned char Z80_FLAG_SZHN_MASK = Z80_FLAG_SZ_MASK | Z80_HALFCARRY_MASK | Z80_ADDSUB_MASK;
//const unsigned char Z80_FLAG_SZP_MASK = Z80_FLAG_SZ_MASK | Z80_PARITY_MASK;
//const unsigned char Z80_FLAG_SZHP_MASK = Z80_FLAG_SZP_MASK | Z80_HALFCARRY_MASK; 
static const unsigned char Z80_FLAG_53_MASK = 0x20 | 0x08; //C POSIX
static const unsigned char Z80_FLAG_SZ_MASK = 0x80 | 0x40; //C POSIX
static const unsigned char Z80_FLAG_SZHN_MASK = (0x80 | 0x40) | 0x10 | 0x02; //C POSIX
static const unsigned char Z80_FLAG_SZP_MASK = (0x80 | 0x40) | 0x04; //C POSIX
static const unsigned char Z80_FLAG_SZHP_MASK = ((0x80 | 0x40) | 0x04) | 0x10; //C POSIX
static unsigned char Z80_regA;
static unsigned char Z80_sz5h3pnFlags;
static unsigned char Z80_carryFlag;
RegisterPair regBC, regBCx, regDE, regDEx, regHL, regHLx;
static unsigned char flagQ, lastFlagQ;
RegisterPair regAFx;
RegisterPair regPC; 
RegisterPair regIX;   
RegisterPair regIY;
RegisterPair regSP;
static unsigned char Z80_regI;
static unsigned char Z80_regR;
static unsigned char Z80_regRbit7;
static unsigned char Z80_ffIFF1 = false;
static unsigned char Z80_ffIFF2 = false;
static unsigned char Z80_pendingEI = false; 
static unsigned char Z80_activeNMI = false;
static unsigned char Z80_modeINT = IM0;
static unsigned char Z80_halted = false;
static unsigned char Z80_pinReset = false;
RegisterPair memptr;
static unsigned char Z80_sz53n_addTable[256];
static unsigned char Z80_sz53pn_addTable[256];
static unsigned char Z80_sz53n_subTable[256];
static unsigned char Z80_sz53pn_subTable[256];

#ifdef WITH_BREAKPOINT_SUPPORT
 unsigned char Z80_breakpointEnabled= false;
#endif 


#ifdef cfg_use_direct_RegA
 #define fast_getRegA() regA
 #define fast_setRegA(a) regA=a
#else
 inline unsigned char fast_getRegA(){ return Z80_regA; }
 inline void fast_setRegA(unsigned char value) { Z80_regA = value; }
#endif 

#ifdef cfg_use_direct_RegB
 #define fast_getRegB() REG_B
 #define fast_setRegB(a) REG_B=a
#else
 inline unsigned char fast_getRegB() { return REG_B; }
 inline void fast_setRegB(unsigned char value) { REG_B = value; }
#endif 

#ifdef cfg_use_direct_RegC
 #define fast_getRegC() REG_C
 #define fast_setRegC(a) REG_C=a
#else
 inline unsigned char fast_getRegC() { return REG_C; }
 inline void fast_setRegC(unsigned char value) { REG_C = value; }
#endif 

#ifdef cfg_use_direct_RegD
 #define fast_getRegD() REG_D
 #define fast_setRegD(a) REG_D=a
#else
 inline unsigned char fast_getRegD() { return REG_D; }
 inline void fast_setRegD(unsigned char value) { REG_D = value; }
#endif 

#ifdef cfg_use_direct_RegE
 #define fast_getRegE() REG_E
 #define fast_setRegE(a) REG_E=a
#else
 inline unsigned char fast_getRegE() { return REG_E; }
 inline void fast_setRegE(unsigned char value) { REG_E = value; }
#endif 

#ifdef cfg_use_direct_RegH
 #define fast_getRegH() REG_H
 #define fast_setRegH(a) REG_H=a
#else
 inline unsigned char fast_getRegH() { return REG_H; }
 inline void fast_setRegH(unsigned char value) { REG_H = value; }
#endif 

#ifdef cfg_use_direct_RegL
 #define fast_getRegL() REG_L
 #define fast_setRegL(a) REG_L=a
#else
 inline unsigned char fast_getRegL() { return REG_L; }
 inline void fast_setRegL(unsigned char value) { REG_L = value; }
#endif 






#ifdef cfg_use_direct_REG_Ax
 #define fast_getRegAx() REG_Ax
 #define fast_setRegAx(a) REG_Ax=a
#else
 inline unsigned char fast_getRegAx() { return REG_Ax; }
 inline void fast_setRegAx(unsigned char value) { REG_Ax = value; }
#endif

#ifdef cfg_use_direct_REG_Fx
 #define fast_getRegFx() REG_Fx
 #define fast_setRegFx(a) REG_Fx=a
#else
 inline unsigned char fast_getRegFx() { return REG_Fx; }
 inline void fast_setRegFx(unsigned char value) { REG_Fx = value; }
#endif 

#ifdef cfg_use_direct_REG_Bx
 #define fast_getRegBx() REG_Bx
 #define fast_setRegBx(a) REG_Bx=a
#else
 inline unsigned char fast_getRegBx() { return REG_Bx; }
 inline void fast_setRegBx(unsigned char value) { REG_Bx = value; }
#endif 

#ifdef cfg_use_direct_REG_Cx
 #define fast_getRegCx() REG_Cx
 #define fast_setRegCx(a) REG_Cx=a
#else
 inline unsigned char fast_getRegCx() { return REG_Cx; }
 inline void fast_setRegCx(unsigned char value) { REG_Cx = value; }
#endif 

#ifdef cfg_use_direct_REG_Dx
 #define fast_getRegDx() REG_Dx
 #define fast_setRegDx(a) REG_Dx=a
#else
 inline unsigned char fast_getRegDx() { return REG_Dx; }
 inline void fast_setRegDx(unsigned char value) { REG_Dx = value; }
#endif 

#ifdef cfg_use_direct_REG_Ex
 #define fast_getRegEx() REG_Ex
 #define fast_setRegEx(a) REG_Ex=a
#else
 inline unsigned char fast_getRegEx() { return REG_Ex; }
 inline void fast_setRegEx(unsigned char value) { REG_Ex = value; }
#endif 

#ifdef cfg_use_direct_REG_Hx
 #define fast_getRegHx() REG_Hx
 #define fast_setRegHx(a) REG_Hx=a
#else
 inline unsigned char fast_getRegHx() { return REG_Hx; }
 inline void fast_setRegHx(unsigned char value) { REG_Hx = value; }
#endif 

#ifdef cfg_use_direct_REG_Lx
 #define fast_getRegLx() REG_Lx
 #define fast_setRegLx(a) REG_Lx=a
#else
 inline unsigned char fast_getRegLx() { return REG_Lx; }
 inline void fast_setRegLx(unsigned char value) { REG_Lx = value; }
#endif 





inline unsigned short int fast_getRegAF() { return (Z80_regA << 8) | (Z80_carryFlag ? Z80_sz5h3pnFlags | Z80_CARRY_MASK : Z80_sz5h3pnFlags); }
inline void fast_setRegAF(unsigned short int word) { Z80_regA = word >> 8; Z80_sz5h3pnFlags = word & 0xfe; Z80_carryFlag = (word & Z80_CARRY_MASK) != 0; }

#ifdef cfg_use_direct_REG_AFx
 #define fast_getRegAFx() REG_AFx
 #define fast_setRegAFx(a) REG_AFx=a
#else
 inline unsigned short int fast_getRegAFx() { return REG_AFx; }
 inline void fast_setRegAFx(unsigned short int word) { REG_AFx = word; }
#endif 

#ifdef cfg_use_direct_REG_BC
 #define fast_getRegBC() REG_BC
 #define fast_setRegBC(a) REG_BC=a
#else
 inline unsigned short int fast_getRegBC() { return REG_BC; }
 inline void fast_setRegBC(unsigned short int word) { REG_BC = word; }
#endif 

#ifdef cfg_use_direct_REG_BCx
 #define fast_getRegBCx() REG_BCx
 #define fast_setRegBCx(a) REG_BCx=a
#else
 inline unsigned short int fast_getRegBCx() { return REG_BCx; }
 inline void fast_setRegBCx(unsigned short int word) { REG_BCx = word; }
#endif 

#ifdef cfg_use_direct_REG_DE
 #define fast_getRegDE() REG_DE
 #define fast_setRegDE(a) REG_DE=a
#else
 inline unsigned short int fast_getRegDE() { return REG_DE; }
 inline void fast_setRegDE(unsigned short int word) { REG_DE = word; }
#endif 

#ifdef cfg_use_direct_REG_DEx
 #define fast_getRegDEx() REG_DEx
 #define fast_setRegDEx(a) REG_DEx=a
#else
 inline unsigned short int fast_getRegDEx() { return REG_DEx; }
 inline void fast_setRegDEx(unsigned short int word) { REG_DEx = word; }
#endif 

#ifdef cfg_use_direct_REG_HL
 #define fast_getRegHL() REG_HL
 #define fast_setRegHL(a) REG_HL=a
#else
 unsigned short int fast_getRegHL() { return REG_HL; }
 void fast_setRegHL(unsigned short int word) { REG_HL = word; }
#endif 

#ifdef cfg_use_direct_REG_HLx
 #define fast_getRegHLx() REG_HLx
 #define fast_setRegHLx(a) REG_HLx=a
#else
 inline unsigned short int fast_getRegHLx() { return REG_HLx; }
 inline void fast_setRegHLx(unsigned short int word) { REG_HLx = word; }
#endif 




#ifdef cfg_use_direct_REG_PC
 #define fast_getRegPC() REG_PC
 #define fast_setRegPC(a) REG_PC=a
#else
 inline unsigned short int fast_getRegPC() { return REG_PC; }
 inline void fast_setRegPC(unsigned short int address) { REG_PC = address; }
#endif 

#ifdef cfg_use_direct_REG_SP
 #define fast_getRegSP() REG_SP
 #define fast_setRegSP(a) REG_SP=a
#else
 inline unsigned short int fast_getRegSP() { return REG_SP; }
 inline void fast_setRegSP(unsigned short int word) { REG_SP = word; }
#endif 

#ifdef cfg_use_direct_REG_IX
 #define fast_getRegIX() REG_IX
 #define fast_setRegIX(a) REG_IX=a
#else
 inline unsigned short int fast_getRegIX() { return REG_IX; }
 inline void fast_setRegIX(unsigned short int word) { REG_IX = word; }
#endif 

#ifdef cfg_use_direct_REG_IY
 #define fast_getRegIY() REG_IY
 #define fast_setRegIY(a) REG_IY=a
#else
 inline unsigned short int fast_getRegIY() { return REG_IY; }
 inline void fast_setRegIY(unsigned short int word) { REG_IY = word; }
#endif 

#ifdef cfg_use_direct_REG_I
 #define fast_getRegI() Z80_regI
 #define fast_setRegI(a) Z80_regI=a
#else
 inline unsigned char fast_getRegI() { return Z80_regI; }
 inline void fast_setRegI(unsigned char value) { Z80_regI = value; }
#endif 

inline unsigned char fast_getRegR() { return Z80_regRbit7 ? Z80_regR | Z80_SIGN_MASK : Z80_regR & 0x7f; }
inline void fast_setRegR(unsigned char value) { Z80_regR = value & 0x7f; Z80_regRbit7 = (value > 0x7f); }

#ifdef cfg_use_direct_MemPtr
 #define fast_getMemPtr() REG_WZ
 #define fast_setMemPtr(a) REG_WZ=a
#else
 inline unsigned short int fast_getMemPtr() { return REG_WZ; }
 inline void fast_setMemPtr(unsigned short int word) { REG_WZ = word; }
#endif 

#ifdef cfg_use_direct_CarryFlag
 #define fast_isCarryFlag() Z80_carryFlag
 #define fast_setCarryFlag(a) Z80_carryFlag=a
#else
 inline unsigned char fast_isCarryFlag() { return Z80_carryFlag; }
 inline void fast_setCarryFlag(unsigned char state) { Z80_carryFlag = state; }
#endif 

inline unsigned char fast_isAddSubFlag() { return (Z80_sz5h3pnFlags & Z80_ADDSUB_MASK) != 0; }
inline void fast_setAddSubFlag(unsigned char state);

inline unsigned char fast_isParOverFlag() { return (Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0; }
inline void fast_setParOverFlag(unsigned char state);

inline unsigned char fast_isBit3Flag() { return (Z80_sz5h3pnFlags & Z80_BIT3_MASK) != 0; }
inline void fast_setBit3Fag(unsigned char state);

inline unsigned char fast_isHalfCarryFlag(void) { return (Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) != 0; }
inline void fast_setHalfCarryFlag(unsigned char state);

inline unsigned char fast_isBit5Flag() { return (Z80_sz5h3pnFlags & Z80_BIT5_MASK) != 0; }
inline void fast_setBit5Flag(unsigned char state);

inline unsigned char fast_isZeroFlag() { return (Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0; }
inline void fast_setZeroFlag(unsigned char state);

inline unsigned char fast_isSignFlag() { return Z80_sz5h3pnFlags >= Z80_SIGN_MASK; }
inline void fast_setSignFlag(unsigned char state);
    
inline unsigned char fast_getFlags() { return Z80_carryFlag ? Z80_sz5h3pnFlags | Z80_CARRY_MASK : Z80_sz5h3pnFlags; }
inline void fast_setFlags(unsigned char regF) { Z80_sz5h3pnFlags = regF & 0xfe; Z80_carryFlag = (regF & Z80_CARRY_MASK) != 0; }        




#ifdef cfg_use_direct_IFF1
 #define fast_isIFF1() Z80_ffIFF1
 #define fast_setIFF1(a) Z80_ffIFF1=a
#else
 inline unsigned char fast_isIFF1() { return Z80_ffIFF1; }
 inline void fast_setIFF1(unsigned char state) { Z80_ffIFF1 = state; }
#endif 

#ifdef cfg_use_direct_IFF2
 #define fast_isIFF2() Z80_ffIFF2
 #define fast_setIFF2(a) Z80_ffIFF2=a
#else
 inline unsigned char fast_isIFF2() { return Z80_ffIFF2; }
 inline void fast_setIFF2(unsigned char state) { Z80_ffIFF2 = state; }
#endif 

#ifdef cfg_use_direct_NMI
 #define fast_isNMI() Z80_activeNMI
 #define fast_setNMI(a) Z80_activeNMI=a
#else
 inline unsigned char fast_isNMI() { return Z80_activeNMI; }
 inline void fast_setNMI(unsigned char nmi) { Z80_activeNMI = nmi; }
#endif 
    
#ifdef cfg_use_direct_triggerNMI
 #define fast_triggerNMI() Z80_activeNMI = true
#else    
 inline void fast_triggerNMI() { Z80_activeNMI = true; }
#endif 

#ifdef cfg_use_direct_IM
 #define fast_getIM() Z80_modeINT
 #define fast_setIM(a) Z80_modeINT=a
#else
 inline unsigned char fast_getIM() { return Z80_modeINT; }
 inline void fast_setIM(unsigned char mode) { Z80_modeINT = mode; }        
#endif 

#ifdef cfg_use_direct_Halted
 #define fast_isHalted() Z80_halted
 #define fast_setHalted(a) Z80_halted=a
#else
 inline unsigned char fast_isHalted() { return Z80_halted; }
 inline void fast_setHalted(unsigned char state) { Z80_halted = state; }
#endif 

#ifdef cfg_use_direct_PinReset
 #define fast_setPinReset() Z80_pinReset=true
#else    
 inline void fast_setPinReset() { Z80_pinReset = true; }
#endif 

#ifdef cfg_use_direct_PendingEI
 #define fast_isPendingEI() Z80_pendingEI
 #define fast_setPendingEI(a) Z80_pendingEI=a
#else    
 inline unsigned char fast_isPendingEI() { return Z80_pendingEI; }
 inline void fast_setPendingEI(unsigned char state) { Z80_pendingEI = state; }
#endif 





void Z80Init()
{
 unsigned char evenBits;
 unsigned int idx;
 unsigned char mask;
 memset(Z80_sz53n_addTable,0,256);
 memset(Z80_sz53pn_addTable,0,256);
 memset(Z80_sz53n_subTable,0,256);
 memset(Z80_sz53pn_subTable,0,256);


    //for (unsigned int idx = 0; idx < 256; idx++)
    for (idx = 0; idx < 256; idx=idx+1) //C POSIX
    {
        if (idx > 0x7f) {
            Z80_sz53n_addTable[idx] |= Z80_SIGN_MASK;
        }

        evenBits = true;
        //for (unsigned char mask = 0x01; mask != 0; mask <<= 1) //C POSIX
        for (mask = 0x01; mask != 0; mask <<= 1)
        {
            if ((idx & mask) != 0) {
                evenBits = !evenBits;
            }
        }

        Z80_sz53n_addTable[idx] |= (idx & Z80_FLAG_53_MASK);
        Z80_sz53n_subTable[idx] = Z80_sz53n_addTable[idx] | Z80_ADDSUB_MASK;

        if (evenBits) {
            Z80_sz53pn_addTable[idx] = Z80_sz53n_addTable[idx] | Z80_PARITY_MASK;
            Z80_sz53pn_subTable[idx] = Z80_sz53n_subTable[idx] | Z80_PARITY_MASK;
        } else {
            Z80_sz53pn_addTable[idx] = Z80_sz53n_addTable[idx];
            Z80_sz53pn_subTable[idx] = Z80_sz53n_subTable[idx];
        }
    }

    Z80_sz53n_addTable[0] |= Z80_ZERO_MASK;
    Z80_sz53pn_addTable[0] |= Z80_ZERO_MASK;
    Z80_sz53n_subTable[0] |= Z80_ZERO_MASK;
    Z80_sz53pn_subTable[0] |= Z80_ZERO_MASK;
    
    Z80_execDone = false;
    reset();                
}





RegisterPair getPairIR(void) {
    RegisterPair IR;
    IR.byte8.hi = Z80_regI;
    IR.byte8.lo = Z80_regR & 0x7f;
    if (Z80_regRbit7) {
        IR.byte8.lo |= Z80_SIGN_MASK;
    }
    return IR;
}

inline void setAddSubFlag(unsigned char state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_ADDSUB_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_ADDSUB_MASK;
    }
}

inline void setParOverFlag(unsigned char state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_PARITY_MASK;
    }
}

inline void setBit3Fag(unsigned char  state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_BIT3_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_BIT3_MASK;
    }
}

inline void setHalfCarryFlag(unsigned char state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_HALFCARRY_MASK;
    }
}

inline void setBit5Flag(unsigned char state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_BIT5_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_BIT5_MASK;
    }
}

inline void setZeroFlag(unsigned char state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_ZERO_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_ZERO_MASK;
    }
}

inline void setSignFlag(unsigned char state) {
    if (state) {
        Z80_sz5h3pnFlags |= Z80_SIGN_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_SIGN_MASK;
    }
}



void reset(void)
{
    if (Z80_pinReset) {
        Z80_pinReset = false;
    } else {
        Z80_regA = 0xff;
        
        fast_setFlags(0xfd); // The only one flag reset at cold start is the add/sub flag

        REG_AFx = 0xffff;
        REG_BC = REG_BCx = 0xffff;
        REG_DE = REG_DEx = 0xffff;
        REG_HL = REG_HLx = 0xffff;

        REG_IX = REG_IY = 0xffff;

        REG_SP = 0xffff;

        REG_WZ = 0xffff;
    }

    REG_PC = 0;
    Z80_regI = Z80_regR = 0;
    Z80_regRbit7 = false;
    Z80_ffIFF1 = false;
    Z80_ffIFF2 = false;
    Z80_pendingEI = false;
    Z80_activeNMI = false;
    Z80_halted = false;    
    Z80_modeINT = IM0; //JJ setIM(IM0);
    lastFlagQ = false;
    Z80_prefixOpcode = 0x00;
}



void rlc(unsigned char * oper8) {
    Z80_carryFlag = ((*oper8) > 0x7f);
    (*oper8) <<= 1;
    if (Z80_carryFlag) {
        (*oper8) |= Z80_CARRY_MASK;
    }
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void rl(unsigned char * oper8) {
    unsigned char carry = Z80_carryFlag;
    Z80_carryFlag = ((*oper8) > 0x7f);
    (*oper8) <<= 1;
    if (carry) {
        (*oper8) |= Z80_CARRY_MASK;
    }
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void sla(unsigned char * oper8) {
    Z80_carryFlag = ((*oper8) > 0x7f);
    (*oper8) <<= 1;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void sll(unsigned char * oper8) {
    Z80_carryFlag = ((*oper8) > 0x7f);
    (*oper8) <<= 1;
    (*oper8) |= Z80_CARRY_MASK;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void rrc(unsigned char * oper8) {
    Z80_carryFlag = ((*oper8) & Z80_CARRY_MASK) != 0;
    (*oper8) >>= 1;
    if (Z80_carryFlag) {
        (*oper8) |= Z80_SIGN_MASK;
    }
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void rr(unsigned char * oper8) {
    unsigned char carry = Z80_carryFlag;
    Z80_carryFlag = ((*oper8) & Z80_CARRY_MASK) != 0;
    (*oper8) >>= 1;
    if (carry) {
        (*oper8) |= Z80_SIGN_MASK;
    }
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void sra(unsigned char * oper8) {
    unsigned char sign = (*oper8) & Z80_SIGN_MASK;
    Z80_carryFlag = ((*oper8) & Z80_CARRY_MASK) != 0;
    (*oper8) = ((*oper8) >> 1) | sign;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void srl(unsigned char * oper8) {
    Z80_carryFlag = ((*oper8) & Z80_CARRY_MASK) != 0;
    (*oper8) >>= 1;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[(*oper8)];
    flagQ = true;
}

void inc8(unsigned char * oper8) {
    (*oper8)++;

    Z80_sz5h3pnFlags = Z80_sz53n_addTable[(*oper8)];

    if (((*oper8) & 0x0f) == 0) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if ((*oper8) == 0x80) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    flagQ = true;
    return;
}

void dec8(unsigned char * oper8) {
    (*oper8)--;

    Z80_sz5h3pnFlags = Z80_sz53n_subTable[(*oper8)];

    if (((*oper8) & 0x0f) == 0x0f) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if ((*oper8) == 0x7f) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    flagQ = true;
    return;
}

void add(unsigned char oper8) {
    unsigned short int res = Z80_regA + oper8;

    Z80_carryFlag = res > 0xff;
    res &= 0xff;
    Z80_sz5h3pnFlags = Z80_sz53n_addTable[res];

    /* El m?dulo 16 del resultado ser? menor que el m?dulo 16 del registro A
     * si ha habido HalfCarry. Sucede lo mismo para todos los m?todos suma
     * SIN carry */
    if ((res & 0x0f) < (Z80_regA & 0x0f)) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((Z80_regA ^ ~oper8) & (Z80_regA ^ res)) > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    Z80_regA = res;
    flagQ = true;
}


void adc(unsigned char oper8) {
    unsigned short int res = Z80_regA + oper8;

    if (Z80_carryFlag) {
        res++;
    }

    Z80_carryFlag = res > 0xff;
    res &= 0xff;
    Z80_sz5h3pnFlags = Z80_sz53n_addTable[res];

    if (((Z80_regA ^ oper8 ^ res) & 0x10) != 0) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((Z80_regA ^ ~oper8) & (Z80_regA ^ res)) > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    Z80_regA = res;
    flagQ = true;
}

// Suma dos operandos de 16 bits sin carry afectando a los flags
void add16(RegisterPair *reg16, unsigned short int oper16) {
    unsigned int tmp = oper16 + (*reg16).word;

    REG_WZ = (*reg16).word + 1;
    Z80_carryFlag = tmp > 0xffff;
    (*reg16).word = tmp;
    Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (((*reg16).word >> 8) & Z80_FLAG_53_MASK);

    if (((*reg16).word & 0x0fff) < (oper16 & 0x0fff)) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    flagQ = true;
    return;
}

// Suma con acarreo de 16 bits
void adc16(unsigned short int reg16) {
    unsigned short int tmpHL = REG_HL;
    REG_WZ = REG_HL + 1;

    unsigned int res = REG_HL + reg16;
    if (Z80_carryFlag) {
        res++;
    }

    Z80_carryFlag = res > 0xffff;
    res &= 0xffff;
    REG_HL = (unsigned short int) res;

    Z80_sz5h3pnFlags = Z80_sz53n_addTable[REG_H];
    if (res != 0) {
        Z80_sz5h3pnFlags &= ~Z80_ZERO_MASK;
    }

    if (((res ^ tmpHL ^ reg16) & 0x1000) != 0) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((tmpHL ^ ~reg16) & (tmpHL ^ res)) > 0x7fff) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    flagQ = true;
}

// Resta de 8 bits
void sub(unsigned char oper8) {
    short int res = Z80_regA - oper8;

    Z80_carryFlag = res < 0;
    res &= 0xff;
    Z80_sz5h3pnFlags = Z80_sz53n_subTable[res];

    /* El m?dulo 16 del resultado ser? mayor que el m?dulo 16 del registro A
     * si ha habido HalfCarry. Sucede lo mismo para todos los m?todos resta
     * SIN carry, incluido cp */
    if ((res & 0x0f) > (Z80_regA & 0x0f)) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((Z80_regA ^ oper8) & (Z80_regA ^ res)) > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    Z80_regA = res;
    flagQ = true;
}


void sbc(unsigned char oper8) {
    short int res = Z80_regA - oper8;

    if (Z80_carryFlag) {
        res--;
    }

    Z80_carryFlag = res < 0;
    res &= 0xff;
    Z80_sz5h3pnFlags = Z80_sz53n_subTable[res];

    if (((Z80_regA ^ oper8 ^ res) & 0x10) != 0) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((Z80_regA ^ oper8) & (Z80_regA ^ res)) > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    Z80_regA = res;
    flagQ = true;
}

void sbc16(unsigned short int reg16) {
    unsigned short int tmpHL = REG_HL;
    REG_WZ = REG_HL + 1;

    int res = REG_HL - reg16;
    if (Z80_carryFlag) {
        res--;
    }

    Z80_carryFlag = res < 0;
    res &= 0xffff;
    REG_HL = (unsigned short int) res;

    Z80_sz5h3pnFlags = Z80_sz53n_subTable[REG_H];
    if (res != 0) {
        Z80_sz5h3pnFlags &= ~Z80_ZERO_MASK;
    }

    if (((res ^ tmpHL ^ reg16) & 0x1000) != 0) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((tmpHL ^ reg16) & (tmpHL ^ res)) > 0x7fff) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }
    flagQ = true;
}

void and_(unsigned char oper8) {
    Z80_regA &= oper8;
    Z80_carryFlag = false;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[Z80_regA] | Z80_HALFCARRY_MASK;
    flagQ = true;
}

// Operaci?n XOR l?gica
void xor_(unsigned char oper8) {
    Z80_regA ^= oper8;
    Z80_carryFlag = false;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[Z80_regA];
    flagQ = true;
}

void or_(unsigned char oper8) {
    Z80_regA |= oper8;
    Z80_carryFlag = false;
    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[Z80_regA];
    flagQ = true;
}

void cp(unsigned char oper8) {
    short int res = Z80_regA - oper8;

    Z80_carryFlag = res < 0;
    res &= 0xff;

    Z80_sz5h3pnFlags = (Z80_sz53n_addTable[oper8] & Z80_FLAG_53_MASK)
            | // No necesito preservar H, pero est? a 0 en la tabla de todas formas
            (Z80_sz53n_subTable[res] & Z80_FLAG_SZHN_MASK);

    if ((res & 0x0f) > (Z80_regA & 0x0f)) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
    }

    if (((Z80_regA ^ oper8) & (Z80_regA ^ res)) > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_OVERFLOW_MASK;
    }

    flagQ = true;
}

void daa(void)
{
    unsigned char suma = 0;
    unsigned char carry = Z80_carryFlag;

    if ((Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) != 0 || (Z80_regA & 0x0f) > 0x09) {
        suma = 6;
    }

    if (carry || (Z80_regA > 0x99)) {
        suma |= 0x60;
    }

    if (Z80_regA > 0x99) {
        carry = true;
    }

    if ((Z80_sz5h3pnFlags & Z80_ADDSUB_MASK) != 0) {
        sub(suma);
        Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) | Z80_sz53pn_subTable[Z80_regA];
    } else {
        add(suma);
        Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) | Z80_sz53pn_addTable[Z80_regA];
    }

    Z80_carryFlag = carry;
    // Los add/sub ya ponen el resto de los flags
    flagQ = true;
}


unsigned short int pop(void) {
    unsigned short int word = peek16(REG_SP);
    REG_SP = REG_SP + 2;
    return word;
}

// PUSH
void push(unsigned short int word) {
    poke8(--REG_SP, word >> 8);
    poke8(--REG_SP, word);
}

void ldi(void) {
    unsigned char work8 = peek8(REG_HL);
    poke8(REG_DE, work8);
    addressOnBus(REG_DE, 2);
    REG_HL++;
    REG_DE++;
    REG_BC--;
    work8 += Z80_regA;

    Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZ_MASK) | (work8 & Z80_BIT3_MASK);

    if ((work8 & Z80_ADDSUB_MASK) != 0) {
        Z80_sz5h3pnFlags |= Z80_BIT5_MASK;
    }

    if (REG_BC != 0) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    }
    flagQ = true;
}

// LDD
void ldd(void) {
    unsigned char work8 = peek8(REG_HL);
    poke8(REG_DE, work8);
    addressOnBus(REG_DE, 2);
    REG_HL--;
    REG_DE--;
    REG_BC--;
    work8 += Z80_regA;

    Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZ_MASK) | (work8 & Z80_BIT3_MASK);

    if ((work8 & Z80_ADDSUB_MASK) != 0) {
        Z80_sz5h3pnFlags |= Z80_BIT5_MASK;
    }

    if (REG_BC != 0) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    }
    flagQ = true;
}

// CPI
void cpi(void) {
    unsigned char memHL = peek8(REG_HL);
    unsigned char carry = Z80_carryFlag; // lo guardo porque cp lo toca
    cp(memHL);
    Z80_carryFlag = carry;
    addressOnBus(REG_HL, 5);
    REG_HL++;
    REG_BC--;
    memHL = Z80_regA - memHL - ((Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) != 0 ? 1 : 0);
    Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHN_MASK) | (memHL & Z80_BIT3_MASK);

    if ((memHL & Z80_ADDSUB_MASK) != 0) {
        Z80_sz5h3pnFlags |= Z80_BIT5_MASK;
    }

    if (REG_BC != 0) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    }

    REG_WZ++;
    flagQ = true;
}

// CPD
void cpd(void) {
    unsigned char memHL = peek8(REG_HL);
    unsigned char carry = Z80_carryFlag; // lo guardo porque cp lo toca
    cp(memHL);
    Z80_carryFlag = carry;
    addressOnBus(REG_HL, 5);
    REG_HL--;
    REG_BC--;
    memHL = Z80_regA - memHL - ((Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) != 0 ? 1 : 0);
    Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHN_MASK) | (memHL & Z80_BIT3_MASK);

    if ((memHL & Z80_ADDSUB_MASK) != 0) {
        Z80_sz5h3pnFlags |= Z80_BIT5_MASK;
    }

    if (REG_BC != 0) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    }

    REG_WZ--;
    flagQ = true;
}

void ini(void) {
    REG_WZ = REG_BC;
    addressOnBus(getPairIR().word, 1);
    unsigned char work8 = inPort(REG_WZ++);
    poke8(REG_HL, work8);

    REG_B--;
    REG_HL++;

    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_B];
    if (work8 > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_ADDSUB_MASK;
    }

    Z80_carryFlag = false;
    unsigned short int tmp = work8 + REG_C + 1;
    if (tmp > 0xff) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
        Z80_carryFlag = true;
    }

    if ((Z80_sz53pn_addTable[((tmp & 0x07) ^ REG_B)]
            & Z80_PARITY_MASK) == Z80_PARITY_MASK) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_PARITY_MASK;
    }
    flagQ = true;
}

// IND
void ind(void) {
    REG_WZ = REG_BC;
    addressOnBus(getPairIR().word, 1);
    unsigned char work8 = inPort(REG_WZ--);
    poke8(REG_HL, work8);

    REG_B--;
    REG_HL--;

    Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_B];
    if (work8 > 0x7f) {
        Z80_sz5h3pnFlags |= Z80_ADDSUB_MASK;
    }

    Z80_carryFlag = false;
    unsigned short int tmp = work8 + (REG_C - 1);
    if (tmp > 0xff) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
        Z80_carryFlag = true;
    }

    if ((Z80_sz53pn_addTable[((tmp & 0x07) ^ REG_B)]
            & Z80_PARITY_MASK) == Z80_PARITY_MASK) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    } else {
        Z80_sz5h3pnFlags &= ~Z80_PARITY_MASK;
    }
    flagQ = true;
}

// OUTI
void outi(void) {

    addressOnBus(getPairIR().word, 1);

    REG_B--;
    REG_WZ = REG_BC;

    unsigned char work8 = peek8(REG_HL);
    outPort(REG_WZ++, work8);

    REG_HL++;

    Z80_carryFlag = false;
    if (work8 > 0x7f) {
        Z80_sz5h3pnFlags = Z80_sz53n_subTable[REG_B];
    } else {
        Z80_sz5h3pnFlags = Z80_sz53n_addTable[REG_B];
    }

    if ((REG_L + work8) > 0xff) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
        Z80_carryFlag = true;
    }

    if ((Z80_sz53pn_addTable[(((REG_L + work8) & 0x07) ^ REG_B)]
            & Z80_PARITY_MASK) == Z80_PARITY_MASK) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    }
    flagQ = true;
}


// OUTD
void outd(void) {

    addressOnBus(getPairIR().word, 1);

    REG_B--;
    REG_WZ = REG_BC;

    unsigned char work8 = peek8(REG_HL);
    outPort(REG_WZ--, work8);

    REG_HL--;

    Z80_carryFlag = false;
    if (work8 > 0x7f) {
        Z80_sz5h3pnFlags = Z80_sz53n_subTable[REG_B];
    } else {
        Z80_sz5h3pnFlags = Z80_sz53n_addTable[REG_B];
    }

    if ((REG_L + work8) > 0xff) {
        Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
        Z80_carryFlag = true;
    }

    if ((Z80_sz53pn_addTable[(((REG_L + work8) & 0x07) ^ REG_B)]
            & Z80_PARITY_MASK) == Z80_PARITY_MASK) {
        Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
    }
    flagQ = true;
}

void bitTest(unsigned char mask, unsigned char reg) {
    unsigned char zeroFlag = (mask & reg) == 0;

    Z80_sz5h3pnFlags = (Z80_sz53n_addTable[reg] & ~Z80_FLAG_SZP_MASK) | Z80_HALFCARRY_MASK;

    if (zeroFlag) {
        Z80_sz5h3pnFlags |= (Z80_PARITY_MASK | Z80_ZERO_MASK);
    }

    if (mask == Z80_SIGN_MASK && !zeroFlag) {
        Z80_sz5h3pnFlags |= Z80_SIGN_MASK;
    }
    flagQ = true;
}

void interrupt(void) {
    // Si estaba en un HALT esperando una INT, lo saca de la espera
    if (Z80_halted) {
        Z80_halted = false;
        REG_PC++;
    }

    interruptHandlingTime(7);

    Z80_regR++;
    Z80_ffIFF1 = Z80_ffIFF2 = false;
    push(REG_PC); // el push a?adir? 6 t-estados (+contended si toca)
    if (Z80_modeINT == IM2) 
    {
        REG_PC = peek16((Z80_regI << 8) | 0xff); // +6 t-estados
    } else {
        REG_PC = 0x0038;
    }
    REG_WZ = REG_PC;
}

void nmi(void) {
    // Esta lectura consigue dos cosas:
    //      1.- La lectura del opcode del M1 que se descarta
    //      2.- Si estaba en un HALT esperando una INT, lo saca de la espera
    fetchOpcode(REG_PC);
    interruptHandlingTime(1);
    if (Z80_halted) {
        Z80_halted = false;
        REG_PC++;
    }
    Z80_regR++;
    Z80_ffIFF1 = false;
    push(REG_PC); // 3+3 t-estados + contended si procede
    REG_PC = REG_WZ = 0x0066;
}



void execute(void) 
{    
    Z80_opCode = fetchOpcode(REG_PC);
    //printf ("0x%04X 0x%02X T:0x%08X\n",REG_PC,opCode,tstates);
    Z80_regR++;

#ifdef WITH_BREAKPOINT_SUPPORT
    if (Z80_breakpointEnabled && Z80_prefixOpcode == 0) {
        Z80_opCode = Z80_breakpoint(REG_PC, Z80_opCode);
    }
#endif

    REG_PC++;

    // El prefijo 0xCB no cuenta para esta guerra.
    // En CBxx todas las xx producen un c?digo v?lido
    // de instrucci?n, incluyendo CBCB.
    switch (Z80_prefixOpcode) {
        case 0x00:
            flagQ = Z80_pendingEI = false;
            decodeOpcode(Z80_opCode);
            break;
        case 0xDD:
            Z80_prefixOpcode = 0;
            decodeDDFD(Z80_opCode, &regIX);
            break;
        case 0xED:
            Z80_prefixOpcode = 0;
            decodeED(Z80_opCode);
            break;
        case 0xFD:
            Z80_prefixOpcode = 0;
            decodeDDFD(Z80_opCode, &regIY);
            break;
        default:
            return;
    }

    if (Z80_prefixOpcode != 0)
        return;

    lastFlagQ = flagQ;


    // Primero se comprueba NMI
    // Si se activa NMI no se comprueba INT porque la siguiente
    // instrucci?n debe ser la de 0x0066.
    if (Z80_activeNMI) {
        Z80_activeNMI = false;
        lastFlagQ = false;
        nmi();
        return;
    }

    // Ahora se comprueba si est? activada la se?al INT
    if (Z80_ffIFF1 && !Z80_pendingEI && isActiveINT()) {
        lastFlagQ = false;
        interrupt();
    }
}



void decodeOpcode(uint8_t opCode) 
{

    switch (opCode) {
        case 0x00:
        { /* NOP */
            break;
        }
        case 0x01:
        { /* LD BC,nn */
            REG_BC = peek16(REG_PC);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x02:
        { /* LD (BC),A */
            poke8(REG_BC, Z80_regA);
            REG_W = Z80_regA;
            REG_Z = REG_C + 1;
            //REG_WZ = (regA << 8) | (REG_C + 1);
            break;
        }
        case 0x03:
        { /* INC BC */
            addressOnBus(getPairIR().word, 2);
            REG_BC++;
            break;
        }
        case 0x04:
        { /* INC B */
            inc8(&REG_B);
            break;
        }
        case 0x05:
        { /* DEC B */
            dec8(&REG_B);
            break;
        }
        case 0x06:
        { /* LD B,n */
            REG_B = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x07:
        { /* RLCA */
            Z80_carryFlag = (Z80_regA > 0x7f);
            Z80_regA <<= 1;
            if (Z80_carryFlag) {
                Z80_regA |= Z80_CARRY_MASK;
            }
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
            flagQ = true;
            break;
        }
        case 0x08:
        { /* EX AF,AF' */
            uint8_t work8 = Z80_regA;
            Z80_regA = REG_Ax;
            REG_Ax = work8;

            work8 = fast_getFlags();
            fast_setFlags(REG_Fx);
            REG_Fx = work8;
            break;
        }
        case 0x09:
        { /* ADD HL,BC */
            addressOnBus(getPairIR().word, 7);
            add16(&regHL, REG_BC);
            break;
        }
        case 0x0A:
        { /* LD A,(BC) */
            Z80_regA = peek8(REG_BC);
            REG_WZ = REG_BC + 1;
            break;
        }
        case 0x0B:
        { /* DEC BC */
            addressOnBus(getPairIR().word, 2);
            REG_BC--;
            break;
        }
        case 0x0C:
        { /* INC C */
            inc8(&REG_C);
            break;
        }
        case 0x0D:
        { /* DEC C */
            dec8(&REG_C);
            break;
        }
        case 0x0E:
        { /* LD C,n */
            REG_C = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x0F:
        { /* RRCA */
            Z80_carryFlag = (Z80_regA & Z80_CARRY_MASK) != 0;
            Z80_regA >>= 1;
            if (Z80_carryFlag) {
                Z80_regA |= Z80_SIGN_MASK;
            }
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
            flagQ = true;
            break;
        }
        case 0x10:
        { /* DJNZ e */
            addressOnBus(getPairIR().word, 1);
            int8_t offset = peek8(REG_PC);
            if (--REG_B != 0) {
                addressOnBus(REG_PC, 5);
                REG_PC = REG_WZ = REG_PC + offset + 1;
            } else {
                REG_PC++;
            }
            break;
        }
        case 0x11:
        { /* LD DE,nn */
            REG_DE = peek16(REG_PC);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x12:
        { /* LD (DE),A */
            poke8(REG_DE, Z80_regA);
            REG_W = Z80_regA;
            REG_Z = REG_E + 1;
            //REG_WZ = (regA << 8) | (REG_E + 1);
            break;
        }
        case 0x13:
        { /* INC DE */
            addressOnBus(getPairIR().word, 2);
            REG_DE++;
            break;
        }
        case 0x14:
        { /* INC D */
            inc8(&REG_D);
            break;
        }
        case 0x15:
        { /* DEC D */
            dec8(&REG_D);
            break;
        }
        case 0x16:
        { /* LD D,n */
            REG_D = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x17:
        { /* RLA */
            unsigned char oldCarry = Z80_carryFlag;
            Z80_carryFlag = Z80_regA > 0x7f;
            Z80_regA <<= 1;
            if (oldCarry) {
                Z80_regA |= Z80_CARRY_MASK;
            }
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
            flagQ = true;
            break;
        }
        case 0x18:
        { /* JR e */
            int8_t offset = peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC = REG_WZ = REG_PC + offset + 1;
            break;
        }
        case 0x19:
        { /* ADD HL,DE */
            addressOnBus(getPairIR().word, 7);
            add16(&regHL, REG_DE);
            break;
        }
        case 0x1A:
        { /* LD A,(DE) */
            Z80_regA = peek8(REG_DE);
            REG_WZ = REG_DE + 1;
            break;
        }
        case 0x1B:
        { /* DEC DE */
            addressOnBus(getPairIR().word, 2);
            REG_DE--;
            break;
        }
        case 0x1C:
        { /* INC E */
            inc8(&REG_E);
            break;
        }
        case 0x1D:
        { /* DEC E */
            dec8(&REG_E);
            break;
        }
        case 0x1E:
        { /* LD E,n */
            REG_E = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x1F:
        { /* RRA */
            unsigned char oldCarry = Z80_carryFlag;
            Z80_carryFlag = (Z80_regA & Z80_CARRY_MASK) != 0;
            Z80_regA >>= 1;
            if (oldCarry) {
                Z80_regA |= Z80_SIGN_MASK;
            }
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
            flagQ = true;
            break;
        }
        case 0x20:
        { /* JR NZ,e */
            int8_t offset = peek8(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
                addressOnBus(REG_PC, 5);
                REG_PC += offset;
                REG_WZ = REG_PC + 1;
            }
            REG_PC++;
            break;
        }
        case 0x21:
        { /* LD HL,nn */
            REG_HL = peek16(REG_PC);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x22:
        { /* LD (nn),HL */
            REG_WZ = peek16(REG_PC);
            poke16(REG_WZ, regHL);
            REG_WZ++;
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x23:
        { /* INC HL */
            addressOnBus(getPairIR().word, 2);
            REG_HL++;
            break;
        }
        case 0x24:
        { /* INC H */
            inc8(&REG_H);
            break;
        }
        case 0x25:
        { /* DEC H */
            dec8(&REG_H);
            break;
        }
        case 0x26:
        { /* LD H,n */
            REG_H = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x27:
        { /* DAA */
            daa();
            break;
        }
        case 0x28:
        { /* JR Z,e */
            int8_t offset = peek8(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
                addressOnBus(REG_PC, 5);
                REG_PC += offset;
                REG_WZ = REG_PC + 1;
            }
            REG_PC++;
            break;
        }
        case 0x29:
        { /* ADD HL,HL */
            addressOnBus(getPairIR().word, 7);
            add16(&regHL, REG_HL);
            break;
        }
        case 0x2A:
        { /* LD HL,(nn) */
            REG_WZ = peek16(REG_PC);
            REG_HL = peek16(REG_WZ);
            REG_WZ++;
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x2B:
        { /* DEC HL */
            addressOnBus(getPairIR().word, 2);
            REG_HL--;
            break;
        }
        case 0x2C:
        { /* INC L */
            inc8(&REG_L);
            break;
        }
        case 0x2D:
        { /* DEC L */
            dec8(&REG_L);
            break;
        }
        case 0x2E:
        { /* LD L,n */
            REG_L = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x2F:
        { /* CPL */
            Z80_regA ^= 0xff;
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | Z80_HALFCARRY_MASK
                    | (Z80_regA & Z80_FLAG_53_MASK) | Z80_ADDSUB_MASK;
            flagQ = true;
            break;
        }
        case 0x30:
        { /* JR NC,e */
            int8_t offset = peek8(REG_PC);
            if (!Z80_carryFlag) {
                addressOnBus(REG_PC, 5);
                REG_PC += offset;
                REG_WZ = REG_PC + 1;
            }
            REG_PC++;
            break;
        }
        case 0x31:
        { /* LD SP,nn */
            REG_SP = peek16(REG_PC);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x32:
        { /* LD (nn),A */
            REG_WZ = peek16(REG_PC);
            poke8(REG_WZ, Z80_regA);
            REG_WZ = (Z80_regA << 8) | ((REG_WZ + 1) & 0xff);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x33:
        { /* INC SP */
            addressOnBus(getPairIR().word, 2);
            REG_SP++;
            break;
        }
        case 0x34:
        { /* INC (HL) */
            uint8_t work8 = peek8(REG_HL);
            inc8(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x35:
        { /* DEC (HL) */
            uint8_t work8 = peek8(REG_HL);
            dec8(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x36:
        { /* LD (HL),n */
            poke8(REG_HL, peek8(REG_PC));
            REG_PC++;
            break;
        }
        case 0x37:
        { /* SCF */
            uint8_t regQ = lastFlagQ ? Z80_sz5h3pnFlags : 0;
            Z80_carryFlag = true;
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (((regQ ^ Z80_sz5h3pnFlags) | Z80_regA) & Z80_FLAG_53_MASK);
            flagQ = true;
            break;
        }
        case 0x38:
        { /* JR C,e */
            int8_t offset = peek8(REG_PC);
            if (Z80_carryFlag) {
                addressOnBus(REG_PC, 5);
                REG_PC += offset;
                REG_WZ = REG_PC + 1;
            }
            REG_PC++;
            break;
        }
        case 0x39:
        { /* ADD HL,SP */
            addressOnBus(getPairIR().word, 7);
            add16(&regHL, REG_SP);
            break;
        }
        case 0x3A:
        { /* LD A,(nn) */
            REG_WZ = peek16(REG_PC);
            Z80_regA = peek8(REG_WZ);
            REG_WZ++;
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x3B:
        { /* DEC SP */
            addressOnBus(getPairIR().word, 2);
            REG_SP--;
            break;
        }
        case 0x3C:
        { /* INC A */
            inc8(&Z80_regA);
            break;
        }
        case 0x3D:
        { /* DEC A */
            dec8(&Z80_regA);
            break;
        }
        case 0x3E:
        { /* LD A,n */
            Z80_regA = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x3F:
        { /* CCF */
            uint8_t regQ = lastFlagQ ? Z80_sz5h3pnFlags : 0;
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (((regQ ^ Z80_sz5h3pnFlags) | Z80_regA) & Z80_FLAG_53_MASK);
            if (Z80_carryFlag) {
                Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
            }
            Z80_carryFlag = !Z80_carryFlag;
            flagQ = true;
            break;
        }
//      case 0x40: {     /* LD B,B */
//           break;
//    }
        case 0x41:
        { /* LD B,C */
            REG_B = REG_C;
            break;
        }
        case 0x42:
        { /* LD B,D */
            REG_B = REG_D;
            break;
        }
        case 0x43:
        { /* LD B,E */
            REG_B = REG_E;
            break;
        }
        case 0x44:
        { /* LD B,H */
            REG_B = REG_H;
            break;
        }
        case 0x45:
        { /* LD B,L */
            REG_B = REG_L;
            break;
        }
        case 0x46:
        { /* LD B,(HL) */
            REG_B = peek8(REG_HL);
            break;
        }
        case 0x47:
        { /* LD B,A */
            REG_B = Z80_regA;
            break;
        }
        case 0x48:
        { /* LD C,B */
            REG_C = REG_B;
            break;
        }
//        case 0x49: {     /* LD C,C */
//            break;
//        }
        case 0x4A:
        { /* LD C,D */
            REG_C = REG_D;
            break;
        }
        case 0x4B:
        { /* LD C,E */
            REG_C = REG_E;
            break;
        }
        case 0x4C:
        { /* LD C,H */
            REG_C = REG_H;
            break;
        }
        case 0x4D:
        { /* LD C,L */
            REG_C = REG_L;
            break;
        }
        case 0x4E:
        { /* LD C,(HL) */
            REG_C = peek8(REG_HL);
            break;
        }
        case 0x4F:
        { /* LD C,A */
            REG_C = Z80_regA;
            break;
        }
        case 0x50:
        { /* LD D,B */
            REG_D = REG_B;
            break;
        }
        case 0x51:
        { /* LD D,C */
            REG_D = REG_C;
            break;
        }
//            case 0x52: {     /* LD D,D */
//                break;
//            }
        case 0x53:
        { /* LD D,E */
            REG_D = REG_E;
            break;
        }
        case 0x54:
        { /* LD D,H */
            REG_D = REG_H;
            break;
        }
        case 0x55:
        { /* LD D,L */
            REG_D = REG_L;
            break;
        }
        case 0x56:
        { /* LD D,(HL) */
            REG_D = peek8(REG_HL);
            break;
        }
        case 0x57:
        { /* LD D,A */
            REG_D = Z80_regA;
            break;
        }
        case 0x58:
        { /* LD E,B */
            REG_E = REG_B;
            break;
        }
        case 0x59:
        { /* LD E,C */
            REG_E = REG_C;
            break;
        }
        case 0x5A:
        { /* LD E,D */
            REG_E = REG_D;
            break;
        }
//            case 0x5B: {     /* LD E,E */
//                break;
//            }
        case 0x5C:
        { /* LD E,H */
            REG_E = REG_H;
            break;
        }
        case 0x5D:
        { /* LD E,L */
            REG_E = REG_L;
            break;
        }
        case 0x5E:
        { /* LD E,(HL) */
            REG_E = peek8(REG_HL);
            break;
        }
        case 0x5F:
        { /* LD E,A */
            REG_E = Z80_regA;
            break;
        }
        case 0x60:
        { /* LD H,B */
            REG_H = REG_B;
            break;
        }
        case 0x61:
        { /* LD H,C */
            REG_H = REG_C;
            break;
        }
        case 0x62:
        { /* LD H,D */
            REG_H = REG_D;
            break;
        }
        case 0x63:
        { /* LD H,E */
            REG_H = REG_E;
            break;
        }
//            case 0x64: {     /* LD H,H */
//                break;
//            }
        case 0x65:
        { /* LD H,L */
            REG_H = REG_L;
            break;
        }
        case 0x66:
        { /* LD H,(HL) */
            REG_H = peek8(REG_HL);
            break;
        }
        case 0x67:
        { /* LD H,A */
            REG_H = Z80_regA;
            break;
        }
        case 0x68:
        { /* LD L,B */
            REG_L = REG_B;
            break;
        }
        case 0x69:
        { /* LD L,C */
            REG_L = REG_C;
            break;
        }
        case 0x6A:
        { /* LD L,D */
            REG_L = REG_D;
            break;
        }
        case 0x6B:
        { /* LD L,E */
            REG_L = REG_E;
            break;
        }
        case 0x6C:
        { /* LD L,H */
            REG_L = REG_H;
            break;
        }
//            case 0x6D: {     /* LD L,L */
//                break;
//            }
        case 0x6E:
        { /* LD L,(HL) */
            REG_L = peek8(REG_HL);
            break;
        }
        case 0x6F:
        { /* LD L,A */
            REG_L = Z80_regA;
            break;
        }
        case 0x70:
        { /* LD (HL),B */
            poke8(REG_HL, REG_B);
            break;
        }
        case 0x71:
        { /* LD (HL),C */
            poke8(REG_HL, REG_C);
            break;
        }
        case 0x72:
        { /* LD (HL),D */
            poke8(REG_HL, REG_D);
            break;
        }
        case 0x73:
        { /* LD (HL),E */
            poke8(REG_HL, REG_E);
            break;
        }
        case 0x74:
        { /* LD (HL),H */
            poke8(REG_HL, REG_H);
            break;
        }
        case 0x75:
        { /* LD (HL),L */
            poke8(REG_HL, REG_L);
            break;
        }
        case 0x76:
        { /* HALT */
            REG_PC--;
            Z80_halted = true;
            break;
        }
        case 0x77:
        { /* LD (HL),A */
            poke8(REG_HL, Z80_regA);
            break;
        }
        case 0x78:
        { /* LD A,B */
            Z80_regA = REG_B;
            break;
        }
        case 0x79:
        { /* LD A,C */
            Z80_regA = REG_C;
            break;
        }
        case 0x7A:
        { /* LD A,D */
            Z80_regA = REG_D;
            break;
        }
        case 0x7B:
        { /* LD A,E */
            Z80_regA = REG_E;
            break;
        }
        case 0x7C:
        { /* LD A,H */
            Z80_regA = REG_H;
            break;
        }
        case 0x7D:
        { /* LD A,L */
            Z80_regA = REG_L;
            break;
        }
        case 0x7E:
        { /* LD A,(HL) */
            Z80_regA = peek8(REG_HL);
            break;
        }
//            case 0x7F: {     /* LD A,A */
//                break;
//            }
        case 0x80:
        { /* ADD A,B */
            add(REG_B);
            break;
        }
        case 0x81:
        { /* ADD A,C */
            add(REG_C);
            break;
        }
        case 0x82:
        { /* ADD A,D */
            add(REG_D);
            break;
        }
        case 0x83:
        { /* ADD A,E */
            add(REG_E);
            break;
        }
        case 0x84:
        { /* ADD A,H */
            add(REG_H);
            break;
        }
        case 0x85:
        { /* ADD A,L */
            add(REG_L);
            break;
        }
        case 0x86:
        { /* ADD A,(HL) */
            add(peek8(REG_HL));
            break;
        }
        case 0x87:
        { /* ADD A,A */
            add(Z80_regA);
            break;
        }
        case 0x88:
        { /* ADC A,B */
            adc(REG_B);
            break;
        }
        case 0x89:
        { /* ADC A,C */
            adc(REG_C);
            break;
        }
        case 0x8A:
        { /* ADC A,D */
            adc(REG_D);
            break;
        }
        case 0x8B:
        { /* ADC A,E */
            adc(REG_E);
            break;
        }
        case 0x8C:
        { /* ADC A,H */
            adc(REG_H);
            break;
        }
        case 0x8D:
        { /* ADC A,L */
            adc(REG_L);
            break;
        }
        case 0x8E:
        { /* ADC A,(HL) */
            adc(peek8(REG_HL));
            break;
        }
        case 0x8F:
        { /* ADC A,A */
            adc(Z80_regA);
            break;
        }
        case 0x90:
        { /* SUB B */
            sub(REG_B);
            break;
        }
        case 0x91:
        { /* SUB C */
            sub(REG_C);
            break;
        }
        case 0x92:
        { /* SUB D */
            sub(REG_D);
            break;
        }
        case 0x93:
        { /* SUB E */
            sub(REG_E);
            break;
        }
        case 0x94:
        { /* SUB H */
            sub(REG_H);
            break;
        }
        case 0x95:
        { /* SUB L */
            sub(REG_L);
            break;
        }
        case 0x96:
        { /* SUB (HL) */
            sub(peek8(REG_HL));
            break;
        }
        case 0x97:
        { /* SUB A */
            sub(Z80_regA);
            break;
        }
        case 0x98:
        { /* SBC A,B */
            sbc(REG_B);
            break;
        }
        case 0x99:
        { /* SBC A,C */
            sbc(REG_C);
            break;
        }
        case 0x9A:
        { /* SBC A,D */
            sbc(REG_D);
            break;
        }
        case 0x9B:
        { /* SBC A,E */
            sbc(REG_E);
            break;
        }
        case 0x9C:
        { /* SBC A,H */
            sbc(REG_H);
            break;
        }
        case 0x9D:
        { /* SBC A,L */
            sbc(REG_L);
            break;
        }
        case 0x9E:
        { /* SBC A,(HL) */
            sbc(peek8(REG_HL));
            break;
        }
        case 0x9F:
        { /* SBC A,A */
            sbc(Z80_regA);
            break;
        }
        case 0xA0:
        { /* AND B */
            and_(REG_B);
            break;
        }
        case 0xA1:
        { /* AND C */
            and_(REG_C);
            break;
        }
        case 0xA2:
        { /* AND D */
            and_(REG_D);
            break;
        }
        case 0xA3:
        { /* AND E */
            and_(REG_E);
            break;
        }
        case 0xA4:
        { /* AND H */
            and_(REG_H);
            break;
        }
        case 0xA5:
        { /* AND L */
            and_(REG_L);
            break;
        }
        case 0xA6:
        { /* AND (HL) */
            and_(peek8(REG_HL));
            break;
        }
        case 0xA7:
        { /* AND A */
            and_(Z80_regA);
            break;
        }
        case 0xA8:
        { /* XOR B */
            xor_(REG_B);
            break;
        }
        case 0xA9:
        { /* XOR C */
            xor_(REG_C);
            break;
        }
        case 0xAA:
        { /* XOR D */
            xor_(REG_D);
            break;
        }
        case 0xAB:
        { /* XOR E */
            xor_(REG_E);
            break;
        }
        case 0xAC:
        { /* XOR H */
            xor_(REG_H);
            break;
        }
        case 0xAD:
        { /* XOR L */
            xor_(REG_L);
            break;
        }
        case 0xAE:
        { /* XOR (HL) */
            xor_(peek8(REG_HL));
            break;
        }
        case 0xAF:
        { /* XOR A */
            xor_(Z80_regA);
            break;
        }
        case 0xB0:
        { /* OR B */
            or_(REG_B);
            break;
        }
        case 0xB1:
        { /* OR C */
            or_(REG_C);
            break;
        }
        case 0xB2:
        { /* OR D */
            or_(REG_D);
            break;
        }
        case 0xB3:
        { /* OR E */
            or_(REG_E);
            break;
        }
        case 0xB4:
        { /* OR H */
            or_(REG_H);
            break;
        }
        case 0xB5:
        { /* OR L */
            or_(REG_L);
            break;
        }
        case 0xB6:
        { /* OR (HL) */
            or_(peek8(REG_HL));
            break;
        }
        case 0xB7:
        { /* OR A */
            or_(Z80_regA);
            break;
        }
        case 0xB8:
        { /* CP B */
            cp(REG_B);
            break;
        }
        case 0xB9:
        { /* CP C */
            cp(REG_C);
            break;
        }
        case 0xBA:
        { /* CP D */
            cp(REG_D);
            break;
        }
        case 0xBB:
        { /* CP E */
            cp(REG_E);
            break;
        }
        case 0xBC:
        { /* CP H */
            cp(REG_H);
            break;
        }
        case 0xBD:
        { /* CP L */
            cp(REG_L);
            break;
        }
        case 0xBE:
        { /* CP (HL) */
            cp(peek8(REG_HL));
            break;
        }
        case 0xBF:
        { /* CP A */
            cp(Z80_regA);
            break;
        }
        case 0xC0:
        { /* RET NZ */
            addressOnBus(getPairIR().word, 1);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
                REG_PC = REG_WZ = pop();
            }
            break;
        }
        case 0xC1:
        { /* POP BC */
            REG_BC = pop();
            break;
        }
        case 0xC2:
        { /* JP NZ,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xC3:
        { /* JP nn */
            REG_WZ = REG_PC = peek16(REG_PC);
            break;
        }
        case 0xC4:
        { /* CALL NZ,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xC5:
        { /* PUSH BC */
            addressOnBus(getPairIR().word, 1);
            push(REG_BC);
            break;
        }
        case 0xC6:
        { /* ADD A,n */
            add(peek8(REG_PC));
            REG_PC++;
            break;
        }
        case 0xC7:
        { /* RST 00H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x00;
            break;
        }
        case 0xC8:
        { /* RET Z */
            addressOnBus(getPairIR().word, 1);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
                REG_PC = REG_WZ = pop();
            }
            break;
        }
        case 0xC9:
        { /* RET */
            REG_PC = REG_WZ = pop();
            break;
        }
        case 0xCA:
        { /* JP Z,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xCB:
        { /* Subconjunto de instrucciones */
            decodeCB();
            break;
        }
        case 0xCC:
        { /* CALL Z,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xCD:
        { /* CALL nn */
            REG_WZ = peek16(REG_PC);
            addressOnBus(REG_PC + 1, 1);
            push(REG_PC + 2);
            REG_PC = REG_WZ;
            break;
        }
        case 0xCE:
        { /* ADC A,n */
            adc(peek8(REG_PC));
            REG_PC++;
            break;
        }
        case 0xCF:
        { /* RST 08H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x08;
            break;
        }
        case 0xD0:
        { /* RET NC */
            addressOnBus(getPairIR().word, 1);
            if (!Z80_carryFlag) {
                REG_PC = REG_WZ = pop();
            }
            break;
        }
        case 0xD1:
        { /* POP DE */
            REG_DE = pop();
            break;
        }
        case 0xD2:
        { /* JP NC,nn */
            REG_WZ = peek16(REG_PC);
            if (!Z80_carryFlag) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xD3:
        { /* OUT (n),A */
            uint8_t work8 = peek8(REG_PC);
            REG_PC++;
            REG_WZ = Z80_regA << 8;
            outPort(REG_WZ | work8, Z80_regA);
            REG_WZ |= (work8 + 1);
            break;
        }
        case 0xD4:
        { /* CALL NC,nn */
            REG_WZ = peek16(REG_PC);
            if (!Z80_carryFlag) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xD5:
        { /* PUSH DE */
            addressOnBus(getPairIR().word, 1);
            push(REG_DE);
            break;
        }
        case 0xD6:
        { /* SUB n */
            sub(peek8(REG_PC));
            REG_PC++;
            break;
        }
        case 0xD7:
        { /* RST 10H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x10;
            break;
        }
        case 0xD8:
        { /* RET C */
            addressOnBus(getPairIR().word, 1);
            if (Z80_carryFlag) {
                REG_PC = REG_WZ = pop();
            }
            break;
        }
        case 0xD9:
        { /* EXX */
            uint16_t tmp;
            tmp = REG_BC;
            REG_BC = REG_BCx;
            REG_BCx = tmp;

            tmp = REG_DE;
            REG_DE = REG_DEx;
            REG_DEx = tmp;

            tmp = REG_HL;
            REG_HL = REG_HLx;
            REG_HLx = tmp;
            break;
        }
        case 0xDA:
        { /* JP C,nn */
            REG_WZ = peek16(REG_PC);
            if (Z80_carryFlag) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xDB:
        { /* IN A,(n) */
            REG_W = Z80_regA;
            REG_Z = peek8(REG_PC);
            //REG_WZ = (regA << 8) | peek8(REG_PC);
            REG_PC++;
            Z80_regA = inPort(REG_WZ);
            REG_WZ++;
            break;
        }
        case 0xDC:
        { /* CALL C,nn */
            REG_WZ = peek16(REG_PC);
            if (Z80_carryFlag) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xDD:
        { /* Subconjunto de instrucciones */
            opCode = fetchOpcode(REG_PC++);
            Z80_regR++;
            decodeDDFD(opCode, &regIX);
            break;
        }
        case 0xDE:
        { /* SBC A,n */
            sbc(peek8(REG_PC));
            REG_PC++;
            break;
        }
        case 0xDF:
        { /* RST 18H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x18;
            break;
        }
        case 0xE0: /* RET PO */
            addressOnBus(getPairIR().word, 1);
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == 0) {
                REG_PC = REG_WZ = pop();
            }
            break;
        case 0xE1: /* POP HL */
            REG_HL = pop();
            break;
        case 0xE2: /* JP PO,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == 0) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xE3:
        { /* EX (SP),HL */
            // Instrucci?n de ejecuci?n sutil.
            RegisterPair work = regHL;
            REG_HL = peek16(REG_SP);
            addressOnBus(REG_SP + 1, 1);
            // No se usa poke16 porque el Z80 escribe los bytes AL REVES
            poke8(REG_SP + 1, work.byte8.hi);
            poke8(REG_SP, work.byte8.lo);
            addressOnBus(REG_SP, 2);
            REG_WZ = REG_HL;
            break;
        }
        case 0xE4: /* CALL PO,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == 0) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xE5: /* PUSH HL */
            addressOnBus(getPairIR().word, 1);
            push(REG_HL);
            break;
        case 0xE6: /* AND n */
            and_(peek8(REG_PC));
            REG_PC++;
            break;
        case 0xE7: /* RST 20H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x20;
            break;
        case 0xE8: /* RET PE */
            addressOnBus(getPairIR().word, 1);
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0) {
                REG_PC = REG_WZ = pop();
            }
            break;
        case 0xE9: /* JP (HL) */
            REG_PC = REG_HL;
            break;
        case 0xEA: /* JP PE,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xEB:
        { /* EX DE,HL */
            uint16_t tmp = REG_HL;
            REG_HL = REG_DE;
            REG_DE = tmp;
            break;
        }
        case 0xEC: /* CALL PE,nn */
            REG_WZ = peek16(REG_PC);
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xED: /*Subconjunto de instrucciones*/
            opCode = fetchOpcode(REG_PC++);
            Z80_regR++;
            decodeED(opCode);
            break;
        case 0xEE: /* XOR n */
            xor_(peek8(REG_PC));
            REG_PC++;
            break;
        case 0xEF: /* RST 28H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x28;
            break;
        case 0xF0: /* RET P */
            addressOnBus(getPairIR().word, 1);
            if (Z80_sz5h3pnFlags < Z80_SIGN_MASK) {
                REG_PC = REG_WZ = pop();
            }
            break;
        case 0xF1: /* POP AF */
            fast_setRegAF(pop());
            break;
        case 0xF2: /* JP P,nn */
            REG_WZ = peek16(REG_PC);
            if (Z80_sz5h3pnFlags < Z80_SIGN_MASK) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xF3: /* DI */
            Z80_ffIFF1 = Z80_ffIFF2 = false;
            break;
        case 0xF4: /* CALL P,nn */
            REG_WZ = peek16(REG_PC);
            if (Z80_sz5h3pnFlags < Z80_SIGN_MASK) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xF5: /* PUSH AF */
            addressOnBus(getPairIR().word, 1);
            push(fast_getRegAF());
            break;
        case 0xF6: /* OR n */
            or_(peek8(REG_PC));
            REG_PC++;
            break;
        case 0xF7: /* RST 30H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x30;
            break;
        case 0xF8: /* RET M */
            addressOnBus(getPairIR().word, 1);
            if (Z80_sz5h3pnFlags > 0x7f) {
                REG_PC = REG_WZ = pop();
            }
            break;
        case 0xF9: /* LD SP,HL */
            addressOnBus(getPairIR().word, 2);
            REG_SP = REG_HL;
            break;
        case 0xFA: /* JP M,nn */
            REG_WZ = peek16(REG_PC);
            if (Z80_sz5h3pnFlags > 0x7f) {
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xFB: /* EI */
            Z80_ffIFF1 = Z80_ffIFF2 = true;
            Z80_pendingEI = true;
            break;
        case 0xFC: /* CALL M,nn */
            REG_WZ = peek16(REG_PC);
            if (Z80_sz5h3pnFlags > 0x7f) {
                addressOnBus(REG_PC + 1, 1);
                push(REG_PC + 2);
                REG_PC = REG_WZ;
                break;
            }
            REG_PC = REG_PC + 2;
            break;
        case 0xFD: /* Subconjunto de instrucciones */
            opCode = fetchOpcode(REG_PC++);
            Z80_regR++;
            decodeDDFD(opCode, &regIY);
            break;
        case 0xFE: /* CP n */
            cp(peek8(REG_PC));
            REG_PC++;
            break;
        case 0xFF: /* RST 38H */
            addressOnBus(getPairIR().word, 1);
            push(REG_PC);
            REG_PC = REG_WZ = 0x38;
    } /* del switch( codigo ) */
}

//Subconjunto de instrucciones 0xCB

void decodeCB(void) {
    uint8_t opCode = fetchOpcode(REG_PC++);
    Z80_regR++;

    switch (opCode) {
        case 0x00:
        { /* RLC B */
            rlc(&REG_B);
            break;
        }
        case 0x01:
        { /* RLC C */
            rlc(&REG_C);
            break;
        }
        case 0x02:
        { /* RLC D */
            rlc(&REG_D);
            break;
        }
        case 0x03:
        { /* RLC E */
            rlc(&REG_E);
            break;
        }
        case 0x04:
        { /* RLC H */
            rlc(&REG_H);
            break;
        }
        case 0x05:
        { /* RLC L */
            rlc(&REG_L);
            break;
        }
        case 0x06:
        { /* RLC (HL) */
            uint8_t work8 = peek8(REG_HL);
            rlc(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x07:
        { /* RLC A */
            rlc(&Z80_regA);
            break;
        }
        case 0x08:
        { /* RRC B */
            rrc(&REG_B);
            break;
        }
        case 0x09:
        { /* RRC C */
            rrc(&REG_C);
            break;
        }
        case 0x0A:
        { /* RRC D */
            rrc(&REG_D);
            break;
        }
        case 0x0B:
        { /* RRC E */
            rrc(&REG_E);
            break;
        }
        case 0x0C:
        { /* RRC H */
            rrc(&REG_H);
            break;
        }
        case 0x0D:
        { /* RRC L */
            rrc(&REG_L);
            break;
        }
        case 0x0E:
        { /* RRC (HL) */
            uint8_t work8 = peek8(REG_HL);
            rrc(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x0F:
        { /* RRC A */
            rrc(&Z80_regA);
            break;
        }
        case 0x10:
        { /* RL B */
            rl(&REG_B);
            break;
        }
        case 0x11:
        { /* RL C */
            rl(&REG_C);
            break;
        }
        case 0x12:
        { /* RL D */
            rl(&REG_D);
            break;
        }
        case 0x13:
        { /* RL E */
            rl(&REG_E);
            break;
        }
        case 0x14:
        { /* RL H */
            rl(&REG_H);
            break;
        }
        case 0x15:
        { /* RL L */
            rl(&REG_L);
            break;
        }
        case 0x16:
        { /* RL (HL) */
            uint8_t work8 = peek8(REG_HL);
            rl(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x17:
        { /* RL A */
            rl(&Z80_regA);
            break;
        }
        case 0x18:
        { /* RR B */
            rr(&REG_B);
            break;
        }
        case 0x19:
        { /* RR C */
            rr(&REG_C);
            break;
        }
        case 0x1A:
        { /* RR D */
            rr(&REG_D);
            break;
        }
        case 0x1B:
        { /* RR E */
            rr(&REG_E);
            break;
        }
        case 0x1C:
        { /*RR H*/
            rr(&REG_H);
            break;
        }
        case 0x1D:
        { /* RR L */
            rr(&REG_L);
            break;
        }
        case 0x1E:
        { /* RR (HL) */
            uint8_t work8 = peek8(REG_HL);
            rr(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x1F:
        { /* RR A */
            rr(&Z80_regA);
            break;
        }
        case 0x20:
        { /* SLA B */
            sla(&REG_B);
            break;
        }
        case 0x21:
        { /* SLA C */
            sla(&REG_C);
            break;
        }
        case 0x22:
        { /* SLA D */
            sla(&REG_D);
            break;
        }
        case 0x23:
        { /* SLA E */
            sla(&REG_E);
            break;
        }
        case 0x24:
        { /* SLA H */
            sla(&REG_H);
            break;
        }
        case 0x25:
        { /* SLA L */
            sla(&REG_L);
            break;
        }
        case 0x26:
        { /* SLA (HL) */
            uint8_t work8 = peek8(REG_HL);
            sla(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x27:
        { /* SLA A */
            sla(&Z80_regA);
            break;
        }
        case 0x28:
        { /* SRA B */
            sra(&REG_B);
            break;
        }
        case 0x29:
        { /* SRA C */
            sra(&REG_C);
            break;
        }
        case 0x2A:
        { /* SRA D */
            sra(&REG_D);
            break;
        }
        case 0x2B:
        { /* SRA E */
            sra(&REG_E);
            break;
        }
        case 0x2C:
        { /* SRA H */
            sra(&REG_H);
            break;
        }
        case 0x2D:
        { /* SRA L */
            sra(&REG_L);
            break;
        }
        case 0x2E:
        { /* SRA (HL) */
            uint8_t work8 = peek8(REG_HL);
            sra(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x2F:
        { /* SRA A */
            sra(&Z80_regA);
            break;
        }
        case 0x30:
        { /* SLL B */
            sll(&REG_B);
            break;
        }
        case 0x31:
        { /* SLL C */
            sll(&REG_C);
            break;
        }
        case 0x32:
        { /* SLL D */
            sll(&REG_D);
            break;
        }
        case 0x33:
        { /* SLL E */
            sll(&REG_E);
            break;
        }
        case 0x34:
        { /* SLL H */
            sll(&REG_H);
            break;
        }
        case 0x35:
        { /* SLL L */
            sll(&REG_L);
            break;
        }
        case 0x36:
        { /* SLL (HL) */
            uint8_t work8 = peek8(REG_HL);
            sll(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x37:
        { /* SLL A */
            sll(&Z80_regA);
            break;
        }
        case 0x38:
        { /* SRL B */
            srl(&REG_B);
            break;
        }
        case 0x39:
        { /* SRL C */
            srl(&REG_C);
            break;
        }
        case 0x3A:
        { /* SRL D */
            srl(&REG_D);
            break;
        }
        case 0x3B:
        { /* SRL E */
            srl(&REG_E);
            break;
        }
        case 0x3C:
        { /* SRL H */
            srl(&REG_H);
            break;
        }
        case 0x3D:
        { /* SRL L */
            srl(&REG_L);
            break;
        }
        case 0x3E:
        { /* SRL (HL) */
            uint8_t work8 = peek8(REG_HL);
            srl(&work8);
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x3F:
        { /* SRL A */
            srl(&Z80_regA);
            break;
        }
        case 0x40:
        { /* BIT 0,B */
            bitTest(0x01, REG_B);
            break;
        }
        case 0x41:
        { /* BIT 0,C */
            bitTest(0x01, REG_C);
            break;
        }
        case 0x42:
        { /* BIT 0,D */
            bitTest(0x01, REG_D);
            break;
        }
        case 0x43:
        { /* BIT 0,E */
            bitTest(0x01, REG_E);
            break;
        }
        case 0x44:
        { /* BIT 0,H */
            bitTest(0x01, REG_H);
            break;
        }
        case 0x45:
        { /* BIT 0,L */
            bitTest(0x01, REG_L);
            break;
        }
        case 0x46:
        { /* BIT 0,(HL) */
            bitTest(0x01, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x47:
        { /* BIT 0,A */
            bitTest(0x01, Z80_regA);
            break;
        }
        case 0x48:
        { /* BIT 1,B */
            bitTest(0x02, REG_B);
            break;
        }
        case 0x49:
        { /* BIT 1,C */
            bitTest(0x02, REG_C);
            break;
        }
        case 0x4A:
        { /* BIT 1,D */
            bitTest(0x02, REG_D);
            break;
        }
        case 0x4B:
        { /* BIT 1,E */
            bitTest(0x02, REG_E);
            break;
        }
        case 0x4C:
        { /* BIT 1,H */
            bitTest(0x02, REG_H);
            break;
        }
        case 0x4D:
        { /* BIT 1,L */
            bitTest(0x02, REG_L);
            break;
        }
        case 0x4E:
        { /* BIT 1,(HL) */
            bitTest(0x02, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x4F:
        { /* BIT 1,A */
            bitTest(0x02, Z80_regA);
            break;
        }
        case 0x50:
        { /* BIT 2,B */
            bitTest(0x04, REG_B);
            break;
        }
        case 0x51:
        { /* BIT 2,C */
            bitTest(0x04, REG_C);
            break;
        }
        case 0x52:
        { /* BIT 2,D */
            bitTest(0x04, REG_D);
            break;
        }
        case 0x53:
        { /* BIT 2,E */
            bitTest(0x04, REG_E);
            break;
        }
        case 0x54:
        { /* BIT 2,H */
            bitTest(0x04, REG_H);
            break;
        }
        case 0x55:
        { /* BIT 2,L */
            bitTest(0x04, REG_L);
            break;
        }
        case 0x56:
        { /* BIT 2,(HL) */
            bitTest(0x04, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x57:
        { /* BIT 2,A */
            bitTest(0x04, Z80_regA);
            break;
        }
        case 0x58:
        { /* BIT 3,B */
            bitTest(0x08, REG_B);
            break;
        }
        case 0x59:
        { /* BIT 3,C */
            bitTest(0x08, REG_C);
            break;
        }
        case 0x5A:
        { /* BIT 3,D */
            bitTest(0x08, REG_D);
            break;
        }
        case 0x5B:
        { /* BIT 3,E */
            bitTest(0x08, REG_E);
            break;
        }
        case 0x5C:
        { /* BIT 3,H */
            bitTest(0x08, REG_H);
            break;
        }
        case 0x5D:
        { /* BIT 3,L */
            bitTest(0x08, REG_L);
            break;
        }
        case 0x5E:
        { /* BIT 3,(HL) */
            bitTest(0x08, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x5F:
        { /* BIT 3,A */
            bitTest(0x08, Z80_regA);
            break;
        }
        case 0x60:
        { /* BIT 4,B */
            bitTest(0x10, REG_B);
            break;
        }
        case 0x61:
        { /* BIT 4,C */
            bitTest(0x10, REG_C);
            break;
        }
        case 0x62:
        { /* BIT 4,D */
            bitTest(0x10, REG_D);
            break;
        }
        case 0x63:
        { /* BIT 4,E */
            bitTest(0x10, REG_E);
            break;
        }
        case 0x64:
        { /* BIT 4,H */
            bitTest(0x10, REG_H);
            break;
        }
        case 0x65:
        { /* BIT 4,L */
            bitTest(0x10, REG_L);
            break;
        }
        case 0x66:
        { /* BIT 4,(HL) */
            bitTest(0x10, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x67:
        { /* BIT 4,A */
            bitTest(0x10, Z80_regA);
            break;
        }
        case 0x68:
        { /* BIT 5,B */
            bitTest(0x20, REG_B);
            break;
        }
        case 0x69:
        { /* BIT 5,C */
            bitTest(0x20, REG_C);
            break;
        }
        case 0x6A:
        { /* BIT 5,D */
            bitTest(0x20, REG_D);
            break;
        }
        case 0x6B:
        { /* BIT 5,E */
            bitTest(0x20, REG_E);
            break;
        }
        case 0x6C:
        { /* BIT 5,H */
            bitTest(0x20, REG_H);
            break;
        }
        case 0x6D:
        { /* BIT 5,L */
            bitTest(0x20, REG_L);
            break;
        }
        case 0x6E:
        { /* BIT 5,(HL) */
            bitTest(0x20, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x6F:
        { /* BIT 5,A */
            bitTest(0x20, Z80_regA);
            break;
        }
        case 0x70:
        { /* BIT 6,B */
            bitTest(0x40, REG_B);
            break;
        }
        case 0x71:
        { /* BIT 6,C */
            bitTest(0x40, REG_C);
            break;
        }
        case 0x72:
        { /* BIT 6,D */
            bitTest(0x40, REG_D);
            break;
        }
        case 0x73:
        { /* BIT 6,E */
            bitTest(0x40, REG_E);
            break;
        }
        case 0x74:
        { /* BIT 6,H */
            bitTest(0x40, REG_H);
            break;
        }
        case 0x75:
        { /* BIT 6,L */
            bitTest(0x40, REG_L);
            break;
        }
        case 0x76:
        { /* BIT 6,(HL) */
            bitTest(0x40, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x77:
        { /* BIT 6,A */
            bitTest(0x40, Z80_regA);
            break;
        }
        case 0x78:
        { /* BIT 7,B */
            bitTest(0x80, REG_B);
            break;
        }
        case 0x79:
        { /* BIT 7,C */
            bitTest(0x80, REG_C);
            break;
        }
        case 0x7A:
        { /* BIT 7,D */
            bitTest(0x80, REG_D);
            break;
        }
        case 0x7B:
        { /* BIT 7,E */
            bitTest(0x80, REG_E);
            break;
        }
        case 0x7C:
        { /* BIT 7,H */
            bitTest(0x80, REG_H);
            break;
        }
        case 0x7D:
        { /* BIT 7,L */
            bitTest(0x80, REG_L);
            break;
        }
        case 0x7E:
        { /* BIT 7,(HL) */
            bitTest(0x80, peek8(REG_HL));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK) | (REG_W & Z80_FLAG_53_MASK);
            addressOnBus(REG_HL, 1);
            break;
        }
        case 0x7F:
        { /* BIT 7,A */
            bitTest(0x80, Z80_regA);
            break;
        }
        case 0x80:
        { /* RES 0,B */
            REG_B &= 0xFE;
            break;
        }
        case 0x81:
        { /* RES 0,C */
            REG_C &= 0xFE;
            break;
        }
        case 0x82:
        { /* RES 0,D */
            REG_D &= 0xFE;
            break;
        }
        case 0x83:
        { /* RES 0,E */
            REG_E &= 0xFE;
            break;
        }
        case 0x84:
        { /* RES 0,H */
            REG_H &= 0xFE;
            break;
        }
        case 0x85:
        { /* RES 0,L */
            REG_L &= 0xFE;
            break;
        }
        case 0x86:
        { /* RES 0,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xFE;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x87:
        { /* RES 0,A */
            Z80_regA &= 0xFE;
            break;
        }
        case 0x88:
        { /* RES 1,B */
            REG_B &= 0xFD;
            break;
        }
        case 0x89:
        { /* RES 1,C */
            REG_C &= 0xFD;
            break;
        }
        case 0x8A:
        { /* RES 1,D */
            REG_D &= 0xFD;
            break;
        }
        case 0x8B:
        { /* RES 1,E */
            REG_E &= 0xFD;
            break;
        }
        case 0x8C:
        { /* RES 1,H */
            REG_H &= 0xFD;
            break;
        }
        case 0x8D:
        { /* RES 1,L */
            REG_L &= 0xFD;
            break;
        }
        case 0x8E:
        { /* RES 1,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xFD;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x8F:
        { /* RES 1,A */
            Z80_regA &= 0xFD;
            break;
        }
        case 0x90:
        { /* RES 2,B */
            REG_B &= 0xFB;
            break;
        }
        case 0x91:
        { /* RES 2,C */
            REG_C &= 0xFB;
            break;
        }
        case 0x92:
        { /* RES 2,D */
            REG_D &= 0xFB;
            break;
        }
        case 0x93:
        { /* RES 2,E */
            REG_E &= 0xFB;
            break;
        }
        case 0x94:
        { /* RES 2,H */
            REG_H &= 0xFB;
            break;
        }
        case 0x95:
        { /* RES 2,L */
            REG_L &= 0xFB;
            break;
        }
        case 0x96:
        { /* RES 2,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xFB;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x97:
        { /* RES 2,A */
            Z80_regA &= 0xFB;
            break;
        }
        case 0x98:
        { /* RES 3,B */
            REG_B &= 0xF7;
            break;
        }
        case 0x99:
        { /* RES 3,C */
            REG_C &= 0xF7;
            break;
        }
        case 0x9A:
        { /* RES 3,D */
            REG_D &= 0xF7;
            break;
        }
        case 0x9B:
        { /* RES 3,E */
            REG_E &= 0xF7;
            break;
        }
        case 0x9C:
        { /* RES 3,H */
            REG_H &= 0xF7;
            break;
        }
        case 0x9D:
        { /* RES 3,L */
            REG_L &= 0xF7;
            break;
        }
        case 0x9E:
        { /* RES 3,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xF7;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0x9F:
        { /* RES 3,A */
            Z80_regA &= 0xF7;
            break;
        }
        case 0xA0:
        { /* RES 4,B */
            REG_B &= 0xEF;
            break;
        }
        case 0xA1:
        { /* RES 4,C */
            REG_C &= 0xEF;
            break;
        }
        case 0xA2:
        { /* RES 4,D */
            REG_D &= 0xEF;
            break;
        }
        case 0xA3:
        { /* RES 4,E */
            REG_E &= 0xEF;
            break;
        }
        case 0xA4:
        { /* RES 4,H */
            REG_H &= 0xEF;
            break;
        }
        case 0xA5:
        { /* RES 4,L */
            REG_L &= 0xEF;
            break;
        }
        case 0xA6:
        { /* RES 4,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xEF;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xA7:
        { /* RES 4,A */
            Z80_regA &= 0xEF;
            break;
        }
        case 0xA8:
        { /* RES 5,B */
            REG_B &= 0xDF;
            break;
        }
        case 0xA9:
        { /* RES 5,C */
            REG_C &= 0xDF;
            break;
        }
        case 0xAA:
        { /* RES 5,D */
            REG_D &= 0xDF;
            break;
        }
        case 0xAB:
        { /* RES 5,E */
            REG_E &= 0xDF;
            break;
        }
        case 0xAC:
        { /* RES 5,H */
            REG_H &= 0xDF;
            break;
        }
        case 0xAD:
        { /* RES 5,L */
            REG_L &= 0xDF;
            break;
        }
        case 0xAE:
        { /* RES 5,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xDF;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xAF:
        { /* RES 5,A */
            Z80_regA &= 0xDF;
            break;
        }
        case 0xB0:
        { /* RES 6,B */
            REG_B &= 0xBF;
            break;
        }
        case 0xB1:
        { /* RES 6,C */
            REG_C &= 0xBF;
            break;
        }
        case 0xB2:
        { /* RES 6,D */
            REG_D &= 0xBF;
            break;
        }
        case 0xB3:
        { /* RES 6,E */
            REG_E &= 0xBF;
            break;
        }
        case 0xB4:
        { /* RES 6,H */
            REG_H &= 0xBF;
            break;
        }
        case 0xB5:
        { /* RES 6,L */
            REG_L &= 0xBF;
            break;
        }
        case 0xB6:
        { /* RES 6,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0xBF;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xB7:
        { /* RES 6,A */
            Z80_regA &= 0xBF;
            break;
        }
        case 0xB8:
        { /* RES 7,B */
            REG_B &= 0x7F;
            break;
        }
        case 0xB9:
        { /* RES 7,C */
            REG_C &= 0x7F;
            break;
        }
        case 0xBA:
        { /* RES 7,D */
            REG_D &= 0x7F;
            break;
        }
        case 0xBB:
        { /* RES 7,E */
            REG_E &= 0x7F;
            break;
        }
        case 0xBC:
        { /* RES 7,H */
            REG_H &= 0x7F;
            break;
        }
        case 0xBD:
        { /* RES 7,L */
            REG_L &= 0x7F;
            break;
        }
        case 0xBE:
        { /* RES 7,(HL) */
            uint8_t work8 = peek8(REG_HL) & 0x7F;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xBF:
        { /* RES 7,A */
            Z80_regA &= 0x7F;
            break;
        }
        case 0xC0:
        { /* SET 0,B */
            REG_B |= 0x01;
            break;
        }
        case 0xC1:
        { /* SET 0,C */
            REG_C |= 0x01;
            break;
        }
        case 0xC2:
        { /* SET 0,D */
            REG_D |= 0x01;
            break;
        }
        case 0xC3:
        { /* SET 0,E */
            REG_E |= 0x01;
            break;
        }
        case 0xC4:
        { /* SET 0,H */
            REG_H |= 0x01;
            break;
        }
        case 0xC5:
        { /* SET 0,L */
            REG_L |= 0x01;
            break;
        }
        case 0xC6:
        { /* SET 0,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x01;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xC7:
        { /* SET 0,A */
            Z80_regA |= 0x01;
            break;
        }
        case 0xC8:
        { /* SET 1,B */
            REG_B |= 0x02;
            break;
        }
        case 0xC9:
        { /* SET 1,C */
            REG_C |= 0x02;
            break;
        }
        case 0xCA:
        { /* SET 1,D */
            REG_D |= 0x02;
            break;
        }
        case 0xCB:
        { /* SET 1,E */
            REG_E |= 0x02;
            break;
        }
        case 0xCC:
        { /* SET 1,H */
            REG_H |= 0x02;
            break;
        }
        case 0xCD:
        { /* SET 1,L */
            REG_L |= 0x02;
            break;
        }
        case 0xCE:
        { /* SET 1,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x02;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xCF:
        { /* SET 1,A */
            Z80_regA |= 0x02;
            break;
        }
        case 0xD0:
        { /* SET 2,B */
            REG_B |= 0x04;
            break;
        }
        case 0xD1:
        { /* SET 2,C */
            REG_C |= 0x04;
            break;
        }
        case 0xD2:
        { /* SET 2,D */
            REG_D |= 0x04;
            break;
        }
        case 0xD3:
        { /* SET 2,E */
            REG_E |= 0x04;
            break;
        }
        case 0xD4:
        { /* SET 2,H */
            REG_H |= 0x04;
            break;
        }
        case 0xD5:
        { /* SET 2,L */
            REG_L |= 0x04;
            break;
        }
        case 0xD6:
        { /* SET 2,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x04;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xD7:
        { /* SET 2,A */
            Z80_regA |= 0x04;
            break;
        }
        case 0xD8:
        { /* SET 3,B */
            REG_B |= 0x08;
            break;
        }
        case 0xD9:
        { /* SET 3,C */
            REG_C |= 0x08;
            break;
        }
        case 0xDA:
        { /* SET 3,D */
            REG_D |= 0x08;
            break;
        }
        case 0xDB:
        { /* SET 3,E */
            REG_E |= 0x08;
            break;
        }
        case 0xDC:
        { /* SET 3,H */
            REG_H |= 0x08;
            break;
        }
        case 0xDD:
        { /* SET 3,L */
            REG_L |= 0x08;
            break;
        }
        case 0xDE:
        { /* SET 3,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x08;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xDF:
        { /* SET 3,A */
            Z80_regA |= 0x08;
            break;
        }
        case 0xE0:
        { /* SET 4,B */
            REG_B |= 0x10;
            break;
        }
        case 0xE1:
        { /* SET 4,C */
            REG_C |= 0x10;
            break;
        }
        case 0xE2:
        { /* SET 4,D */
            REG_D |= 0x10;
            break;
        }
        case 0xE3:
        { /* SET 4,E */
            REG_E |= 0x10;
            break;
        }
        case 0xE4:
        { /* SET 4,H */
            REG_H |= 0x10;
            break;
        }
        case 0xE5:
        { /* SET 4,L */
            REG_L |= 0x10;
            break;
        }
        case 0xE6:
        { /* SET 4,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x10;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xE7:
        { /* SET 4,A */
            Z80_regA |= 0x10;
            break;
        }
        case 0xE8:
        { /* SET 5,B */
            REG_B |= 0x20;
            break;
        }
        case 0xE9:
        { /* SET 5,C */
            REG_C |= 0x20;
            break;
        }
        case 0xEA:
        { /* SET 5,D */
            REG_D |= 0x20;
            break;
        }
        case 0xEB:
        { /* SET 5,E */
            REG_E |= 0x20;
            break;
        }
        case 0xEC:
        { /* SET 5,H */
            REG_H |= 0x20;
            break;
        }
        case 0xED:
        { /* SET 5,L */
            REG_L |= 0x20;
            break;
        }
        case 0xEE:
        { /* SET 5,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x20;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xEF:
        { /* SET 5,A */
            Z80_regA |= 0x20;
            break;
        }
        case 0xF0:
        { /* SET 6,B */
            REG_B |= 0x40;
            break;
        }
        case 0xF1:
        { /* SET 6,C */
            REG_C |= 0x40;
            break;
        }
        case 0xF2:
        { /* SET 6,D */
            REG_D |= 0x40;
            break;
        }
        case 0xF3:
        { /* SET 6,E */
            REG_E |= 0x40;
            break;
        }
        case 0xF4:
        { /* SET 6,H */
            REG_H |= 0x40;
            break;
        }
        case 0xF5:
        { /* SET 6,L */
            REG_L |= 0x40;
            break;
        }
        case 0xF6:
        { /* SET 6,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x40;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xF7:
        { /* SET 6,A */
            Z80_regA |= 0x40;
            break;
        }
        case 0xF8:
        { /* SET 7,B */
            REG_B |= 0x80;
            break;
        }
        case 0xF9:
        { /* SET 7,C */
            REG_C |= 0x80;
            break;
        }
        case 0xFA:
        { /* SET 7,D */
            REG_D |= 0x80;
            break;
        }
        case 0xFB:
        { /* SET 7,E */
            REG_E |= 0x80;
            break;
        }
        case 0xFC:
        { /* SET 7,H */
            REG_H |= 0x80;
            break;
        }
        case 0xFD:
        { /* SET 7,L */
            REG_L |= 0x80;
            break;
        }
        case 0xFE:
        { /* SET 7,(HL) */
            uint8_t work8 = peek8(REG_HL) | 0x80;
            addressOnBus(REG_HL, 1);
            poke8(REG_HL, work8);
            break;
        }
        case 0xFF:
        { /* SET 7,A */
            Z80_regA |= 0x80;
            break;
        }
        default:
        {
            break;
        }
    }
}

//Subconjunto de instrucciones 0xDD / 0xFD
/*
 * Hay que tener en cuenta el manejo de secuencias c?digos DD/FD que no
 * hacen nada. Seg?n el apartado 3.7 del documento
 * [http://www.myquest.nl/z80undocumented/z80-documented-v0.91.pdf]
 * secuencias de c?digos como FD DD 00 21 00 10 NOP NOP NOP LD HL,1000h
 * activan IY con el primer FD, IX con el segundo DD y vuelven al
 * registro HL con el c?digo NOP. Es decir, si detr?s del c?digo DD/FD no
 * viene una instrucci?n que maneje el registro HL, el c?digo DD/FD
 * "se olvida" y hay que procesar la instrucci?n como si nunca se
 * hubiera visto el prefijo (salvo por los 4 t-estados que ha costado).
 * Naturalmente, en una serie repetida de DDFD no hay que comprobar las
 * interrupciones entre cada prefijo.
 */
void decodeDDFD(uint8_t opCode, RegisterPair* regIXY) {
    switch (opCode) {
        case 0x09:
        { /* ADD IX,BC */
            addressOnBus(getPairIR().word, 7);
            add16(regIXY, REG_BC);
            break;
        }
        case 0x19:
        { /* ADD IX,DE */
            addressOnBus(getPairIR().word, 7);
            add16(regIXY, REG_DE);
            break;
        }
        case 0x21:
        { /* LD IX,nn */
            (*regIXY).word = peek16(REG_PC);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x22:
        { /* LD (nn),IX */
            REG_WZ = peek16(REG_PC);
            poke16(REG_WZ++, (*regIXY));
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x23:
        { /* INC IX */
            addressOnBus(getPairIR().word, 2);
            (*regIXY).word++;
            break;
        }
        case 0x24:
        { /* INC IXh */
            inc8(&((*regIXY).byte8.hi));
            break;
        }
        case 0x25:
        { /* DEC IXh */
            dec8(&((*regIXY).byte8.hi));
            break;
        }
        case 0x26:
        { /* LD IXh,n */
            (*regIXY).byte8.hi = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x29:
        { /* ADD IX,IX */
            addressOnBus(getPairIR().word, 7);
            add16(regIXY, (*regIXY).word);
            break;
        }
        case 0x2A:
        { /* LD IX,(nn) */
            REG_WZ = peek16(REG_PC);
            (*regIXY).word = peek16(REG_WZ++);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x2B:
        { /* DEC IX */
            addressOnBus(getPairIR().word, 2);
            (*regIXY).word--;
            break;
        }
        case 0x2C:
        { /* INC IXl */
            inc8(&((*regIXY).byte8.lo));
            break;
        }
        case 0x2D:
        { /* DEC IXl */
            dec8(&((*regIXY).byte8.lo));
            break;
        }
        case 0x2E:
        { /* LD IXl,n */
            (*regIXY).byte8.lo = peek8(REG_PC);
            REG_PC++;
            break;
        }
        case 0x34:
        { /* INC (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            uint8_t work8 = peek8(REG_WZ);
            addressOnBus(REG_WZ, 1);
            inc8(&work8);
            poke8(REG_WZ, work8);
            break;
        }
        case 0x35:
        { /* DEC (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            uint8_t work8 = peek8(REG_WZ);
            addressOnBus(REG_WZ, 1);
            dec8(&work8);
            poke8(REG_WZ, work8);
            break;
        }
        case 0x36:
        { /* LD (IX+d),n */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            REG_PC++;
            uint8_t work8 = peek8(REG_PC);
            addressOnBus(REG_PC, 2);
            REG_PC++;
            poke8(REG_WZ, work8);
            break;
        }
        case 0x39:
        { /* ADD IX,SP */
            addressOnBus(getPairIR().word, 7);
            add16(regIXY, REG_SP);
            break;
        }
        case 0x44:
        { /* LD B,IXh */
            REG_B = (*regIXY).byte8.hi;
            break;
        }
        case 0x45:
        { /* LD B,IXl */
            REG_B = (*regIXY).byte8.lo;
            break;
        }
        case 0x46:
        { /* LD B,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            REG_B = peek8(REG_WZ);
            break;
        }
        case 0x4C:
        { /* LD C,IXh */
            REG_C = (*regIXY).byte8.hi;
            break;
        }
        case 0x4D:
        { /* LD C,IXl */
            REG_C = (*regIXY).byte8.lo;
            break;
        }
        case 0x4E:
        { /* LD C,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            REG_C = peek8(REG_WZ);
            break;
        }
        case 0x54:
        { /* LD D,IXh */
            REG_D = (*regIXY).byte8.hi;
            break;
        }
        case 0x55:
        { /* LD D,IXl */
            REG_D = (*regIXY).byte8.lo;
            break;
        }
        case 0x56:
        { /* LD D,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            REG_D = peek8(REG_WZ);
            break;
        }
        case 0x5C:
        { /* LD E,IXh */
            REG_E = (*regIXY).byte8.hi;
            break;
        }
        case 0x5D:
        { /* LD E,IXl */
            REG_E = (*regIXY).byte8.lo;
            break;
        }
        case 0x5E:
        { /* LD E,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            REG_E = peek8(REG_WZ);
            break;
        }
        case 0x60:
        { /* LD IXh,B */
            (*regIXY).byte8.hi = REG_B;
            break;
        }
        case 0x61:
        { /* LD IXh,C */
            (*regIXY).byte8.hi = REG_C;
            break;
        }
        case 0x62:
        { /* LD IXh,D */
            (*regIXY).byte8.hi = REG_D;
            break;
        }
        case 0x63:
        { /* LD IXh,E */
            (*regIXY).byte8.hi = REG_E;
            break;
        }
        case 0x64:
        { /* LD IXh,IXh */
            break;
        }
        case 0x65:
        { /* LD IXh,IXl */
            (*regIXY).byte8.hi = (*regIXY).byte8.lo;
            break;
        }
        case 0x66:
        { /* LD H,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            REG_H = peek8(REG_WZ);
            break;
        }
        case 0x67:
        { /* LD IXh,A */
            (*regIXY).byte8.hi = Z80_regA;
            break;
        }
        case 0x68:
        { /* LD IXl,B */
            (*regIXY).byte8.lo = REG_B;
            break;
        }
        case 0x69:
        { /* LD IXl,C */
            (*regIXY).byte8.lo = REG_C;
            break;
        }
        case 0x6A:
        { /* LD IXl,D */
            (*regIXY).byte8.lo = REG_D;
            break;
        }
        case 0x6B:
        { /* LD IXl,E */
            (*regIXY).byte8.lo = REG_E;
            break;
        }
        case 0x6C:
        { /* LD IXl,IXh */
            (*regIXY).byte8.lo = (*regIXY).byte8.hi;
            break;
        }
        case 0x6D:
        { /* LD IXl,IXl */
            break;
        }
        case 0x6E:
        { /* LD L,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            REG_L = peek8(REG_WZ);
            break;
        }
        case 0x6F:
        { /* LD IXl,A */
            (*regIXY).byte8.lo = Z80_regA;
            break;
        }
        case 0x70:
        { /* LD (IX+d),B */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, REG_B);
            break;
        }
        case 0x71:
        { /* LD (IX+d),C */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, REG_C);
            break;
        }
        case 0x72:
        { /* LD (IX+d),D */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, REG_D);
            break;
        }
        case 0x73:
        { /* LD (IX+d),E */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, REG_E);
            break;
        }
        case 0x74:
        { /* LD (IX+d),H */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, REG_H);
            break;
        }
        case 0x75:
        { /* LD (IX+d),L */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, REG_L);
            break;
        }
        case 0x77:
        { /* LD (IX+d),A */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            poke8(REG_WZ, Z80_regA);
            break;
        }
        case 0x7C:
        { /* LD A,IXh */
            Z80_regA = (*regIXY).byte8.hi;
            break;
        }
        case 0x7D:
        { /* LD A,IXl */
            Z80_regA = (*regIXY).byte8.lo;
            break;
        }
        case 0x7E:
        { /* LD A,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            Z80_regA = peek8(REG_WZ);
            break;
        }
        case 0x84:
        { /* ADD A,IXh */
            add((*regIXY).byte8.hi);
            break;
        }
        case 0x85:
        { /* ADD A,IXl */
            add((*regIXY).byte8.lo);
            break;
        }
        case 0x86:
        { /* ADD A,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            add(peek8(REG_WZ));
            break;
        }
        case 0x8C:
        { /* ADC A,IXh */
            adc((*regIXY).byte8.hi);
            break;
        }
        case 0x8D:
        { /* ADC A,IXl */
            adc((*regIXY).byte8.lo);
            break;
        }
        case 0x8E:
        { /* ADC A,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            adc(peek8(REG_WZ));
            break;
        }
        case 0x94:
        { /* SUB IXh */
            sub((*regIXY).byte8.hi);
            break;
        }
        case 0x95:
        { /* SUB IXl */
            sub((*regIXY).byte8.lo);
            break;
        }
        case 0x96:
        { /* SUB (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            sub(peek8(REG_WZ));
            break;
        }
        case 0x9C:
        { /* SBC A,IXh */
            sbc((*regIXY).byte8.hi);
            break;
        }
        case 0x9D:
        { /* SBC A,IXl */
            sbc((*regIXY).byte8.lo);
            break;
        }
        case 0x9E:
        { /* SBC A,(IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            sbc(peek8(REG_WZ));
            break;
        }
        case 0xA4:
        { /* AND IXh */
            and_((*regIXY).byte8.hi);
            break;
        }
        case 0xA5:
        { /* AND IXl */
            and_((*regIXY).byte8.lo);
            break;
        }
        case 0xA6:
        { /* AND (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            and_(peek8(REG_WZ));
            break;
        }
        case 0xAC:
        { /* XOR IXh */
            xor_((*regIXY).byte8.hi);
            break;
        }
        case 0xAD:
        { /* XOR IXl */
            xor_((*regIXY).byte8.lo);
            break;
        }
        case 0xAE:
        { /* XOR (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            xor_(peek8(REG_WZ));
            break;
        }
        case 0xB4:
        { /* OR IXh */
            or_((*regIXY).byte8.hi);
            break;
        }
        case 0xB5:
        { /* OR IXl */
            or_((*regIXY).byte8.lo);
            break;
        }
        case 0xB6:
        { /* OR (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            or_(peek8(REG_WZ));
            break;
        }
        case 0xBC:
        { /* CP IXh */
            cp((*regIXY).byte8.hi);
            break;
        }
        case 0xBD:
        { /* CP IXl */
            cp((*regIXY).byte8.lo);
            break;
        }
        case 0xBE:
        { /* CP (IX+d) */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            addressOnBus(REG_PC, 5);
            REG_PC++;
            cp(peek8(REG_WZ));
            break;
        }
        case 0xCB:
        { /* Subconjunto de instrucciones */
            REG_WZ = (*regIXY).word + (int8_t) peek8(REG_PC);
            REG_PC++;
            opCode = peek8(REG_PC);
            addressOnBus(REG_PC, 2);
            REG_PC++;
            decodeDDFDCB(opCode, REG_WZ);
            break;
        }
        case 0xDD:
            Z80_prefixOpcode = 0xDD;
            break;
        case 0xE1:
        { /* POP IX */
            (*regIXY).word = pop();
            break;
        }
        case 0xE3:
        { /* EX (SP),IX */
            // Instrucci?n de ejecuci?n sutil como pocas... atento al dato.
            RegisterPair work16 = *regIXY;
            (*regIXY).word = peek16(REG_SP);
            addressOnBus(REG_SP + 1, 1);
            // I can't call to poke16 from here because the Z80 do the writes in inverted order
            // Same for EX (SP), HL
            poke8(REG_SP + 1, work16.byte8.hi);
            poke8(REG_SP, work16.byte8.lo);
            addressOnBus(REG_SP, 2);
            REG_WZ = (*regIXY).word;
            break;
        }
        case 0xE5:
        { /* PUSH IX */
            addressOnBus(getPairIR().word, 1);
            push((*regIXY).word);
            break;
        }
        case 0xE9:
        { /* JP (IX) */
            REG_PC = (*regIXY).word;
            break;
        }
        case 0xED:
        {
            Z80_prefixOpcode = 0xED;
            break;
        }
        case 0xF9:
        { /* LD SP,IX */
            addressOnBus(getPairIR().word, 2);
            REG_SP = (*regIXY).word;
            break;
        }
        case 0xFD:
        {
            Z80_prefixOpcode = 0xFD;
            break;
        }
        default:
        {
            // Detr?s de un DD/FD o varios en secuencia ven?a un c?digo
            // que no correspond?a con una instrucci?n que involucra a
            // IX o IY. Se trata como si fuera un c?digo normal.
            // Sin esto, adem?s de emular mal, falla el test
            // ld <bcdexya>,<bcdexya> de ZEXALL.
#ifdef WITH_BREAKPOINT_SUPPORT
            if (Z80_breakpointEnabled && Z80_prefixOpcode == 0) {
                opCode = Z80_breakpoint(REG_PC, opCode);
            }
#endif
            decodeOpcode(opCode);
            break;
        }
    }
}



// Subconjunto de instrucciones 0xDDCB
void decodeDDFDCB(uint8_t opCode, uint16_t address) {

    switch (opCode) {
        case 0x00: /* RLC (IX+d),B */
        case 0x01: /* RLC (IX+d),C */
        case 0x02: /* RLC (IX+d),D */
        case 0x03: /* RLC (IX+d),E */
        case 0x04: /* RLC (IX+d),H */
        case 0x05: /* RLC (IX+d),L */
        case 0x06: /* RLC (IX+d)   */
        case 0x07: /* RLC (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            rlc(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x08: /* RRC (IX+d),B */
        case 0x09: /* RRC (IX+d),C */
        case 0x0A: /* RRC (IX+d),D */
        case 0x0B: /* RRC (IX+d),E */
        case 0x0C: /* RRC (IX+d),H */
        case 0x0D: /* RRC (IX+d),L */
        case 0x0E: /* RRC (IX+d)   */
        case 0x0F: /* RRC (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            rrc(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x10: /* RL (IX+d),B */
        case 0x11: /* RL (IX+d),C */
        case 0x12: /* RL (IX+d),D */
        case 0x13: /* RL (IX+d),E */
        case 0x14: /* RL (IX+d),H */
        case 0x15: /* RL (IX+d),L */
        case 0x16: /* RL (IX+d)   */
        case 0x17: /* RL (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            rl(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x18: /* RR (IX+d),B */
        case 0x19: /* RR (IX+d),C */
        case 0x1A: /* RR (IX+d),D */
        case 0x1B: /* RR (IX+d),E */
        case 0x1C: /* RR (IX+d),H */
        case 0x1D: /* RR (IX+d),L */
        case 0x1E: /* RR (IX+d)   */
        case 0x1F: /* RR (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            rr(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x20: /* SLA (IX+d),B */
        case 0x21: /* SLA (IX+d),C */
        case 0x22: /* SLA (IX+d),D */
        case 0x23: /* SLA (IX+d),E */
        case 0x24: /* SLA (IX+d),H */
        case 0x25: /* SLA (IX+d),L */
        case 0x26: /* SLA (IX+d)   */
        case 0x27: /* SLA (IX+d),A */
        {
             uint8_t work8 = peek8(address);
             sla(&work8);
             addressOnBus(address, 1);
             poke8(address, work8);
             copyToRegister(opCode, work8);
            break;
        }
        case 0x28: /* SRA (IX+d),B */
        case 0x29: /* SRA (IX+d),C */
        case 0x2A: /* SRA (IX+d),D */
        case 0x2B: /* SRA (IX+d),E */
        case 0x2C: /* SRA (IX+d),H */
        case 0x2D: /* SRA (IX+d),L */
        case 0x2E: /* SRA (IX+d)   */
        case 0x2F: /* SRA (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            sra(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x30: /* SLL (IX+d),B */
        case 0x31: /* SLL (IX+d),C */
        case 0x32: /* SLL (IX+d),D */
        case 0x33: /* SLL (IX+d),E */
        case 0x34: /* SLL (IX+d),H */
        case 0x35: /* SLL (IX+d),L */
        case 0x36: /* SLL (IX+d)   */
        case 0x37: /* SLL (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            sll(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x38: /* SRL (IX+d),B */
        case 0x39: /* SRL (IX+d),C */
        case 0x3A: /* SRL (IX+d),D */
        case 0x3B: /* SRL (IX+d),E */
        case 0x3C: /* SRL (IX+d),H */
        case 0x3D: /* SRL (IX+d),L */
        case 0x3E: /* SRL (IX+d)   */
        case 0x3F: /* SRL (IX+d),A */
        {
            uint8_t work8 = peek8(address);
            srl(&work8);
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        { /* BIT 0,(IX+d) */
            bitTest(0x01, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x48:
        case 0x49:
        case 0x4A:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x4E:
        case 0x4F:
        { /* BIT 1,(IX+d) */
            bitTest(0x02, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        { /* BIT 2,(IX+d) */
            bitTest(0x04, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x5F:
        { /* BIT 3,(IX+d) */
            bitTest(0x08, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        { /* BIT 4,(IX+d) */
            bitTest(0x10, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x68:
        case 0x69:
        case 0x6A:
        case 0x6B:
        case 0x6C:
        case 0x6D:
        case 0x6E:
        case 0x6F:
        { /* BIT 5,(IX+d) */
            bitTest(0x20, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x70:
        case 0x71:
        case 0x72:
        case 0x73:
        case 0x74:
        case 0x75:
        case 0x76:
        case 0x77:
        { /* BIT 6,(IX+d) */
            bitTest(0x40, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x78:
        case 0x79:
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
        { /* BIT 7,(IX+d) */
            bitTest(0x80, peek8(address));
            Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZHP_MASK)
                    | ((address >> 8) & Z80_FLAG_53_MASK);
            addressOnBus(address, 1);
            break;
        }
        case 0x80: /* RES 0,(IX+d),B */
        case 0x81: /* RES 0,(IX+d),C */
        case 0x82: /* RES 0,(IX+d),D */
        case 0x83: /* RES 0,(IX+d),E */
        case 0x84: /* RES 0,(IX+d),H */
        case 0x85: /* RES 0,(IX+d),L */
        case 0x86: /* RES 0,(IX+d)   */
        case 0x87: /* RES 0,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xFE;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x88: /* RES 1,(IX+d),B */
        case 0x89: /* RES 1,(IX+d),C */
        case 0x8A: /* RES 1,(IX+d),D */
        case 0x8B: /* RES 1,(IX+d),E */
        case 0x8C: /* RES 1,(IX+d),H */
        case 0x8D: /* RES 1,(IX+d),L */
        case 0x8E: /* RES 1,(IX+d)   */
        case 0x8F: /* RES 1,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xFD;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x90: /* RES 2,(IX+d),B */
        case 0x91: /* RES 2,(IX+d),C */
        case 0x92: /* RES 2,(IX+d),D */
        case 0x93: /* RES 2,(IX+d),E */
        case 0x94: /* RES 2,(IX+d),H */
        case 0x95: /* RES 2,(IX+d),L */
        case 0x96: /* RES 2,(IX+d)   */
        case 0x97: /* RES 2,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xFB;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0x98: /* RES 3,(IX+d),B */
        case 0x99: /* RES 3,(IX+d),C */
        case 0x9A: /* RES 3,(IX+d),D */
        case 0x9B: /* RES 3,(IX+d),E */
        case 0x9C: /* RES 3,(IX+d),H */
        case 0x9D: /* RES 3,(IX+d),L */
        case 0x9E: /* RES 3,(IX+d)   */
        case 0x9F: /* RES 3,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xF7;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xA0: /* RES 4,(IX+d),B */
        case 0xA1: /* RES 4,(IX+d),C */
        case 0xA2: /* RES 4,(IX+d),D */
        case 0xA3: /* RES 4,(IX+d),E */
        case 0xA4: /* RES 4,(IX+d),H */
        case 0xA5: /* RES 4,(IX+d),L */
        case 0xA6: /* RES 4,(IX+d)   */
        case 0xA7: /* RES 4,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xEF;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xA8: /* RES 5,(IX+d),B */
        case 0xA9: /* RES 5,(IX+d),C */
        case 0xAA: /* RES 5,(IX+d),D */
        case 0xAB: /* RES 5,(IX+d),E */
        case 0xAC: /* RES 5,(IX+d),H */
        case 0xAD: /* RES 5,(IX+d),L */
        case 0xAE: /* RES 5,(IX+d)   */
        case 0xAF: /* RES 5,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xDF;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xB0: /* RES 6,(IX+d),B */
        case 0xB1: /* RES 6,(IX+d),C */
        case 0xB2: /* RES 6,(IX+d),D */
        case 0xB3: /* RES 6,(IX+d),E */
        case 0xB4: /* RES 6,(IX+d),H */
        case 0xB5: /* RES 6,(IX+d),L */
        case 0xB6: /* RES 6,(IX+d)   */
        case 0xB7: /* RES 6,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0xBF;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xB8: /* RES 7,(IX+d),B */
        case 0xB9: /* RES 7,(IX+d),C */
        case 0xBA: /* RES 7,(IX+d),D */
        case 0xBB: /* RES 7,(IX+d),E */
        case 0xBC: /* RES 7,(IX+d),H */
        case 0xBD: /* RES 7,(IX+d),L */
        case 0xBE: /* RES 7,(IX+d)   */
        case 0xBF: /* RES 7,(IX+d),A */
        {
            uint8_t work8 = peek8(address) & 0x7F;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xC0: /* SET 0,(IX+d),B */
        case 0xC1: /* SET 0,(IX+d),C */
        case 0xC2: /* SET 0,(IX+d),D */
        case 0xC3: /* SET 0,(IX+d),E */
        case 0xC4: /* SET 0,(IX+d),H */
        case 0xC5: /* SET 0,(IX+d),L */
        case 0xC6: /* SET 0,(IX+d)   */
        case 0xC7: /* SET 0,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x01;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xC8: /* SET 1,(IX+d),B */
        case 0xC9: /* SET 1,(IX+d),C */
        case 0xCA: /* SET 1,(IX+d),D */
        case 0xCB: /* SET 1,(IX+d),E */
        case 0xCC: /* SET 1,(IX+d),H */
        case 0xCD: /* SET 1,(IX+d),L */
        case 0xCE: /* SET 1,(IX+d)   */
        case 0xCF: /* SET 1,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x02;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xD0: /* SET 2,(IX+d),B */
        case 0xD1: /* SET 2,(IX+d),C */
        case 0xD2: /* SET 2,(IX+d),D */
        case 0xD3: /* SET 2,(IX+d),E */
        case 0xD4: /* SET 2,(IX+d),H */
        case 0xD5: /* SET 2,(IX+d),L */
        case 0xD6: /* SET 2,(IX+d)   */
        case 0xD7: /* SET 2,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x04;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xD8: /* SET 3,(IX+d),B */
        case 0xD9: /* SET 3,(IX+d),C */
        case 0xDA: /* SET 3,(IX+d),D */
        case 0xDB: /* SET 3,(IX+d),E */
        case 0xDC: /* SET 3,(IX+d),H */
        case 0xDD: /* SET 3,(IX+d),L */
        case 0xDE: /* SET 3,(IX+d)   */
        case 0xDF: /* SET 3,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x08;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xE0: /* SET 4,(IX+d),B */
        case 0xE1: /* SET 4,(IX+d),C */
        case 0xE2: /* SET 4,(IX+d),D */
        case 0xE3: /* SET 4,(IX+d),E */
        case 0xE4: /* SET 4,(IX+d),H */
        case 0xE5: /* SET 4,(IX+d),L */
        case 0xE6: /* SET 4,(IX+d)   */
        case 0xE7: /* SET 4,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x10;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xE8: /* SET 5,(IX+d),B */
        case 0xE9: /* SET 5,(IX+d),C */
        case 0xEA: /* SET 5,(IX+d),D */
        case 0xEB: /* SET 5,(IX+d),E */
        case 0xEC: /* SET 5,(IX+d),H */
        case 0xED: /* SET 5,(IX+d),L */
        case 0xEE: /* SET 5,(IX+d)   */
        case 0xEF: /* SET 5,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x20;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xF0: /* SET 6,(IX+d),B */
        case 0xF1: /* SET 6,(IX+d),C */
        case 0xF2: /* SET 6,(IX+d),D */
        case 0xF3: /* SET 6,(IX+d),E */
        case 0xF4: /* SET 6,(IX+d),H */
        case 0xF5: /* SET 6,(IX+d),L */
        case 0xF6: /* SET 6,(IX+d)   */
        case 0xF7: /* SET 6,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x40;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
        case 0xF8: /* SET 7,(IX+d),B */
        case 0xF9: /* SET 7,(IX+d),C */
        case 0xFA: /* SET 7,(IX+d),D */
        case 0xFB: /* SET 7,(IX+d),E */
        case 0xFC: /* SET 7,(IX+d),H */
        case 0xFD: /* SET 7,(IX+d),L */
        case 0xFE: /* SET 7,(IX+d)   */
        case 0xFF: /* SET 7,(IX+d),A */
        {
            uint8_t work8 = peek8(address) | 0x80;
            addressOnBus(address, 1);
            poke8(address, work8);
            copyToRegister(opCode, work8);
            break;
        }
    }
}



//Subconjunto de instrucciones 0xED

void decodeED(uint8_t opCode) {
    switch (opCode) {
        case 0x40:
        { /* IN B,(C) */
            REG_WZ = REG_BC;
            REG_B = inPort(REG_WZ);
            REG_WZ++;
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_B];
            flagQ = true;
            break;
        }
        case 0x41:
        { /* OUT (C),B */
            REG_WZ = REG_BC;
            outPort(REG_WZ, REG_B);
            REG_WZ++;
            break;
        }
        case 0x42:
        { /* SBC HL,BC */
            addressOnBus(getPairIR().word, 7);
            sbc16(REG_BC);
            break;
        }
        case 0x43:
        { /* LD (nn),BC */
            REG_WZ = peek16(REG_PC);
            poke16(REG_WZ, regBC);
            REG_WZ++;
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x44:
        case 0x4C:
        case 0x54:
        case 0x5C:
        case 0x64:
        case 0x6C:
        case 0x74:
        case 0x7C:
        { /* NEG */
            uint8_t aux = Z80_regA;
            Z80_regA = 0;
            Z80_carryFlag = false;
            sbc(aux);
            break;
        }
        case 0x45:
        case 0x4D: /* RETI */
        case 0x55:
        case 0x5D:
        case 0x65:
        case 0x6D:
        case 0x75:
        case 0x7D:
        { /* RETN */
            Z80_ffIFF1 = Z80_ffIFF2;
            REG_PC = REG_WZ = pop();
            break;
        }
        case 0x46:
        case 0x4E:
        case 0x66:
        case 0x6E:
        { /* IM 0 */
            //JJ modeINT = IntMode::IM0;
            Z80_modeINT = IM0;
            break;
        }
        case 0x47:
        { /* LD I,A */
            /*
             * El par IR se pone en el bus de direcciones *antes*
             * de poner A en el registro I. Detalle importante.
             */
            addressOnBus(getPairIR().word, 1);
            Z80_regI = Z80_regA;
            break;
        }
        case 0x48:
        { /* IN C,(C) */
            REG_WZ = REG_BC;
            REG_C = inPort(REG_WZ);
            REG_WZ++;
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_C];
            flagQ = true;
            break;
        }
        case 0x49:
        { /* OUT (C),C */
            REG_WZ = REG_BC;
            outPort(REG_WZ, REG_C);
            REG_WZ++;
            break;
        }
        case 0x4A:
        { /* ADC HL,BC */
            addressOnBus(getPairIR().word, 7);
            adc16(REG_BC);
            break;
        }
        case 0x4B:
        { /* LD BC,(nn) */
            REG_WZ = peek16(REG_PC);
            REG_BC = peek16(REG_WZ);
            REG_WZ++;
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x4F:
        { /* LD R,A */
            /*
             * El par IR se pone en el bus de direcciones *antes*
             * de poner A en el registro R. Detalle importante.
             */
            addressOnBus(getPairIR().word, 1);
            fast_setRegR(Z80_regA);
            break;
        }
        case 0x50:
        { /* IN D,(C) */
            REG_WZ = REG_BC;
            REG_D = inPort(REG_WZ);
            REG_WZ++;
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_D];
            flagQ = true;
            break;
        }
        case 0x51:
        { /* OUT (C),D */
            REG_WZ = REG_BC;
            outPort(REG_WZ++, REG_D);
            break;
        }
        case 0x52:
        { /* SBC HL,DE */
            addressOnBus(getPairIR().word, 7);
            sbc16(REG_DE);
            break;
        }
        case 0x53:
        { /* LD (nn),DE */
            REG_WZ = peek16(REG_PC);
            poke16(REG_WZ++, regDE);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x56:
        case 0x76:
        { /* IM 1 */
            //JJ modeINT = IntMode::IM1;
            Z80_modeINT = IM1;
            break;
        }
        case 0x57:
        { /* LD A,I */
            addressOnBus(getPairIR().word, 1);
            Z80_regA = Z80_regI;
            Z80_sz5h3pnFlags = Z80_sz53n_addTable[Z80_regA];
            if (Z80_ffIFF2 && !isActiveINT()) {
                Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
            }
            flagQ = true;
            break;
        }
        case 0x58:
        { /* IN E,(C) */
            REG_WZ = REG_BC;
            REG_E = inPort(REG_WZ++);
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_E];
            flagQ = true;
            break;
        }
        case 0x59:
        { /* OUT (C),E */
            REG_WZ = REG_BC;
            outPort(REG_WZ++, REG_E);
            break;
        }
        case 0x5A:
        { /* ADC HL,DE */
            addressOnBus(getPairIR().word, 7);
            adc16(REG_DE);
            break;
        }
        case 0x5B:
        { /* LD DE,(nn) */
            REG_WZ = peek16(REG_PC);
            REG_DE = peek16(REG_WZ++);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x5E:
        case 0x7E:
        { /* IM 2 */
            //JJ modeINT = IntMode::IM2;
            Z80_modeINT = IM2;
            break;
        }
        case 0x5F:
        { /* LD A,R */
            addressOnBus(getPairIR().word, 1);
            Z80_regA = fast_getRegR();
            Z80_sz5h3pnFlags = Z80_sz53n_addTable[Z80_regA];
            if (Z80_ffIFF2 && !isActiveINT()) {
                Z80_sz5h3pnFlags |= Z80_PARITY_MASK;
            }
            flagQ = true;
            break;
        }
        case 0x60:
        { /* IN H,(C) */
            REG_WZ = REG_BC;
            REG_H = inPort(REG_WZ++);
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_H];
            flagQ = true;
            break;
        }
        case 0x61:
        { /* OUT (C),H */
            REG_WZ = REG_BC;
            outPort(REG_WZ++, REG_H);
            break;
        }
        case 0x62:
        { /* SBC HL,HL */
            addressOnBus(getPairIR().word, 7);
            sbc16(REG_HL);
            break;
        }
        case 0x63:
        { /* LD (nn),HL */
            REG_WZ = peek16(REG_PC);
            poke16(REG_WZ++, regHL);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x67:
        { /* RRD */
            // A = A7 A6 A5 A4 (HL)3 (HL)2 (HL)1 (HL)0
            // (HL) = A3 A2 A1 A0 (HL)7 (HL)6 (HL)5 (HL)4
            // Los bits 3,2,1 y 0 de (HL) se copian a los bits 3,2,1 y 0 de A.
            // Los 4 bits bajos que hab?a en A se copian a los bits 7,6,5 y 4 de (HL).
            // Los 4 bits altos que hab?a en (HL) se copian a los 4 bits bajos de (HL)
            // Los 4 bits superiores de A no se tocan. ?p'habernos matao!
            uint8_t aux = Z80_regA << 4;
            REG_WZ = REG_HL;
            uint16_t memHL = peek8(REG_WZ);
            Z80_regA = (Z80_regA & 0xf0) | (memHL & 0x0f);
            addressOnBus(REG_WZ, 4);
            poke8(REG_WZ++, (memHL >> 4) | aux);
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[Z80_regA];
            flagQ = true;
            break;
        }
        case 0x68:
        { /* IN L,(C) */
            REG_WZ = REG_BC;
            REG_L = inPort(REG_WZ++);
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[REG_L];
            flagQ = true;
            break;
        }
        case 0x69:
        { /* OUT (C),L */
            REG_WZ = REG_BC;
            outPort(REG_WZ++, REG_L);
            break;
        }
        case 0x6A:
        { /* ADC HL,HL */
            addressOnBus(getPairIR().word, 7);
            adc16(REG_HL);
            break;
        }
        case 0x6B:
        { /* LD HL,(nn) */
            REG_WZ = peek16(REG_PC);
            REG_HL = peek16(REG_WZ++);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x6F:
        { /* RLD */
            // A = A7 A6 A5 A4 (HL)7 (HL)6 (HL)5 (HL)4
            // (HL) = (HL)3 (HL)2 (HL)1 (HL)0 A3 A2 A1 A0
            // Los 4 bits bajos que hab?a en (HL) se copian a los bits altos de (HL).
            // Los 4 bits altos que hab?a en (HL) se copian a los 4 bits bajos de A
            // Los bits 3,2,1 y 0 de A se copian a los bits 3,2,1 y 0 de (HL).
            // Los 4 bits superiores de A no se tocan. ?p'habernos matao!
            uint8_t aux = Z80_regA & 0x0f;
            REG_WZ = REG_HL;
            uint16_t memHL = peek8(REG_WZ);
            Z80_regA = (Z80_regA & 0xf0) | (memHL >> 4);
            addressOnBus(REG_WZ, 4);
            poke8(REG_WZ++, (memHL << 4) | aux);
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[Z80_regA];
            flagQ = true;
            break;
        }
        case 0x70:
        { /* IN (C) */
            REG_WZ = REG_BC;
            uint8_t aux_inPort = inPort(REG_WZ++); //raro tenia inPort
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[aux_inPort];
            flagQ = true;
            break;
        }
        case 0x71:
        { /* OUT (C),0 */
            REG_WZ = REG_BC;
            outPort(REG_WZ++, 0x00);
            break;
        }
        case 0x72:
        { /* SBC HL,SP */
            addressOnBus(getPairIR().word, 7);
            sbc16(REG_SP);
            break;
        }
        case 0x73:
        { /* LD (nn),SP */
            REG_WZ = peek16(REG_PC);
            poke16(REG_WZ++, regSP);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0x78:
        { /* IN A,(C) */
            REG_WZ = REG_BC;
            Z80_regA = inPort(REG_WZ++);
            Z80_sz5h3pnFlags = Z80_sz53pn_addTable[Z80_regA];
            flagQ = true;
            break;
        }
        case 0x79:
        { /* OUT (C),A */
            REG_WZ = REG_BC;
            outPort(REG_WZ++, Z80_regA);
            break;
        }
        case 0x7A:
        { /* ADC HL,SP */
            addressOnBus(getPairIR().word, 7);
            adc16(REG_SP);
            break;
        }
        case 0x7B:
        { /* LD SP,(nn) */
            REG_WZ = peek16(REG_PC);
            REG_SP = peek16(REG_WZ++);
            REG_PC = REG_PC + 2;
            break;
        }
        case 0xA0:
        { /* LDI */
            ldi();
            break;
        }
        case 0xA1:
        { /* CPI */
            cpi();
            break;
        }
        case 0xA2:
        { /* INI */
            ini();
            break;
        }
        case 0xA3:
        { /* OUTI */
            outi();
            break;
        }
        case 0xA8:
        { /* LDD */
            ldd();
            break;
        }
        case 0xA9:
        { /* CPD */
            cpd();
            break;
        }
        case 0xAA:
        { /* IND */
            ind();
            break;
        }
        case 0xAB:
        { /* OUTD */
            outd();
            break;
        }
        case 0xB0:
        { /* LDIR */
            ldi();
            if (REG_BC != 0) {
                REG_PC = REG_PC - 2;
                REG_WZ = REG_PC + 1;
                addressOnBus(REG_DE - 1, 5);
            }
            break;
        }
        case 0xB1:
        { /* CPIR */
            cpi();
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == Z80_PARITY_MASK
                    && (Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
                REG_PC = REG_PC - 2;
                REG_WZ = REG_PC + 1;
                addressOnBus(REG_HL - 1, 5);
            }
            break;
        }
        case 0xB2:
        { /* INIR */
            ini();
            if (REG_B != 0) {
                REG_PC = REG_PC - 2;
                addressOnBus(REG_HL - 1, 5);
            }
            break;
        }
        case 0xB3:
        { /* OTIR */
            outi();
            if (REG_B != 0) {
                REG_PC = REG_PC - 2;
                addressOnBus(REG_BC, 5);
            }
            break;
        }
        case 0xB8:
        { /* LDDR */
            ldd();
            if (REG_BC != 0) {
                REG_PC = REG_PC - 2;
                REG_WZ = REG_PC + 1;
                addressOnBus(REG_DE + 1, 5);
            }
            break;
        }
        case 0xB9:
        { /* CPDR */
            cpd();
            if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == Z80_PARITY_MASK
                    && (Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
                REG_PC = REG_PC - 2;
                REG_WZ = REG_PC + 1;
                addressOnBus(REG_HL + 1, 5);
            }
            break;
        }
        case 0xBA:
        { /* INDR */
            ind();
            if (REG_B != 0) {
                REG_PC = REG_PC - 2;
                addressOnBus(REG_HL + 1, 5);
            }
            break;
        }
        case 0xBB:
        { /* OTDR */
            outd();
            if (REG_B != 0) {
                REG_PC = REG_PC - 2;
                addressOnBus(REG_BC, 5);
            }
            break;
        }
        case 0xDD:
            Z80_prefixOpcode = 0xDD;
            break;
        case 0xED:
            Z80_prefixOpcode = 0xED;
            break;
        case 0xFD:
            Z80_prefixOpcode = 0xFD;
            break;
        default:
        {
            break;
        }
    }
}

void copyToRegister(uint8_t opCode, uint8_t value)
{
    switch (opCode & 0x07)
    {
        case 0x00:
            REG_B = value;
            break;
        case 0x01:
            REG_C = value;
            break;
        case 0x02:
            REG_D = value;
            break;
        case 0x03:
            REG_E = value;
            break;
        case 0x04:
            REG_H = value;
            break;
        case 0x05:
            REG_L = value;
            break;
        case 0x07:
            Z80_regA = value;
        default:
            break;
    }
}









//Llamadas externas
unsigned char getRegA(){ return Z80_regA; }
void setRegA(unsigned char value) { Z80_regA = value; }

unsigned char getRegB() { return REG_B; }
void setRegB(unsigned char value) { REG_B = value; }

unsigned char getRegC() { return REG_C; }
void setRegC(unsigned char value) { REG_C = value; }

unsigned char getRegD() { return REG_D; }
void setRegD(unsigned char value) { REG_D = value; }

unsigned char getRegE() { return REG_E; }
void setRegE(unsigned char value) { REG_E = value; }

unsigned char getRegH() { return REG_H; }
void setRegH(unsigned char value) { REG_H = value; }

unsigned char getRegL() { return REG_L; }
void setRegL(unsigned char value) { REG_L = value; }







unsigned char getRegAx() { return REG_Ax; }
void setRegAx(unsigned char value) { REG_Ax = value; }

unsigned char getRegFx() { return REG_Fx; }
void setRegFx(unsigned char value) { REG_Fx = value; }

unsigned char getRegBx() { return REG_Bx; }
void setRegBx(unsigned char value) { REG_Bx = value; }

unsigned char getRegCx() { return REG_Cx; }
void setRegCx(unsigned char value) { REG_Cx = value; }

unsigned char getRegDx() { return REG_Dx; }
void setRegDx(unsigned char value) { REG_Dx = value; }

unsigned char getRegEx() { return REG_Ex; }
void setRegEx(unsigned char value) { REG_Ex = value; }

unsigned char getRegHx() { return REG_Hx; }
void setRegHx(unsigned char value) { REG_Hx = value; }

unsigned char getRegLx() { return REG_Lx; }
void setRegLx(unsigned char value) { REG_Lx = value; }





unsigned short int getRegAF() { return (Z80_regA << 8) | (Z80_carryFlag ? Z80_sz5h3pnFlags | Z80_CARRY_MASK : Z80_sz5h3pnFlags); }
void setRegAF(unsigned short int word) { Z80_regA = word >> 8; Z80_sz5h3pnFlags = word & 0xfe; Z80_carryFlag = (word & Z80_CARRY_MASK) != 0; }

unsigned short int getRegAFx() { return REG_AFx; }
void setRegAFx(unsigned short int word) { REG_AFx = word; }

unsigned short int getRegBC() { return REG_BC; }
void setRegBC(unsigned short int word) { REG_BC = word; }

unsigned short int getRegBCx() { return REG_BCx; }
void setRegBCx(unsigned short int word) { REG_BCx = word; }

unsigned short int getRegDE() { return REG_DE; }
void setRegDE(unsigned short int word) { REG_DE = word; }

unsigned short int getRegDEx() { return REG_DEx; }
void setRegDEx(unsigned short int word) { REG_DEx = word; }

unsigned short int getRegHL() { return REG_HL; }
void setRegHL(unsigned short int word) { REG_HL = word; }

unsigned short int getRegHLx() { return REG_HLx; }
void setRegHLx(unsigned short int word) { REG_HLx = word; }





unsigned short int getRegPC() { return REG_PC; }
void setRegPC(unsigned short int address) { REG_PC = address; }

unsigned short int getRegSP() { return REG_SP; }
void setRegSP(unsigned short int word) { REG_SP = word; }

unsigned short int getRegIX() { return REG_IX; }
void setRegIX(unsigned short int word) { REG_IX = word; }

unsigned short int getRegIY() { return REG_IY; }
void setRegIY(unsigned short int word) { REG_IY = word; }

unsigned char getRegI() { return Z80_regI; }
void setRegI(unsigned char value) { Z80_regI = value; }

unsigned char getRegR() { return Z80_regRbit7 ? Z80_regR | Z80_SIGN_MASK : Z80_regR & 0x7f; }
void setRegR(unsigned char value) { Z80_regR = value & 0x7f; Z80_regRbit7 = (value > 0x7f); }

unsigned short int getMemPtr() { return REG_WZ; }
void setMemPtr(unsigned short int word) { REG_WZ = word; }

unsigned char isCarryFlag() { return Z80_carryFlag; }
void setCarryFlag(unsigned char state) { Z80_carryFlag = state; }

unsigned char isAddSubFlag() { return (Z80_sz5h3pnFlags & Z80_ADDSUB_MASK) != 0; }
void setAddSubFlag(unsigned char state);

unsigned char isParOverFlag() { return (Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0; }
void setParOverFlag(unsigned char state);

unsigned char isBit3Flag() { return (Z80_sz5h3pnFlags & Z80_BIT3_MASK) != 0; }
void setBit3Fag(unsigned char state);

unsigned char isHalfCarryFlag(void) { return (Z80_sz5h3pnFlags & Z80_HALFCARRY_MASK) != 0; }
void setHalfCarryFlag(unsigned char state);

unsigned char isBit5Flag() { return (Z80_sz5h3pnFlags & Z80_BIT5_MASK) != 0; }
void setBit5Flag(unsigned char state);

unsigned char isZeroFlag() { return (Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0; }
void setZeroFlag(unsigned char state);

unsigned char isSignFlag() { return Z80_sz5h3pnFlags >= Z80_SIGN_MASK; }
void setSignFlag(unsigned char state);
    
unsigned char getFlags() { return Z80_carryFlag ? Z80_sz5h3pnFlags | Z80_CARRY_MASK : Z80_sz5h3pnFlags; }
void setFlags(unsigned char regF) { Z80_sz5h3pnFlags = regF & 0xfe; Z80_carryFlag = (regF & Z80_CARRY_MASK) != 0; }        





unsigned char isIFF1() { return Z80_ffIFF1; }
void setIFF1(unsigned char state) { Z80_ffIFF1 = state; }

unsigned char isIFF2() { return Z80_ffIFF2; }
void setIFF2(unsigned char state) { Z80_ffIFF2 = state; }

unsigned char isNMI() { return Z80_activeNMI; }
void setNMI(unsigned char nmi) { Z80_activeNMI = nmi; }
    
void triggerNMI() { Z80_activeNMI = true; }
    
unsigned char getIM() { return Z80_modeINT; }
void setIM(unsigned char mode) { Z80_modeINT = mode; }        

unsigned char isHalted() { return Z80_halted; }
void setHalted(unsigned char state) { Z80_halted = state; }
    
void setPinReset() { Z80_pinReset = true; }

unsigned char isPendingEI() { return Z80_pendingEI; }
void setPendingEI(unsigned char state) { Z80_pendingEI = state; }


#ifdef WITH_BREAKPOINT_SUPPORT
 unsigned char Z80_isBreakpoint()
 {
  return Z80_breakpointEnabled;
 }

 void Z80_setBreakpoint(unsigned char state)
 {
  Z80_breakpointEnabled = state;
 }
#endif


//#endif
//End z80.c








//*****************
//* z80operations *
//*****************
#ifdef cfg_use_test_fps_48k
 inline unsigned char fetchOpcode(unsigned short int address)
 {
  tstates += 4;
  return z80Ram[address];
 }
#else
 inline unsigned char fetchOpcode(unsigned short int address)
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
#endif 

inline unsigned char peek8(unsigned short int address)
{
 tstates += 3;
 return z80Ram[address];         
}

inline void poke8(unsigned short int address, unsigned char value)
{
 tstates += 3;
 z80Ram[address] = value;     
}

inline unsigned short int peek16(unsigned short int address)
{
 uint8_t lsb = peek8(address);
 uint8_t msb = peek8(address + 1);
 return (msb << 8) | lsb;         
}

inline void poke16(unsigned short int address, RegisterPair word)
{
 poke8(address, word.byte8.lo);
 poke8(address + 1, word.byte8.hi);     
}

void addressOnBus(unsigned short int address, int wstates)
{
 tstates += wstates;     
}

inline unsigned char inPort(unsigned short int port)
{
    tstates += 3;
    return z80Ports[port];
}

inline void outPort(unsigned short int port, unsigned char value)
{
    tstates += 4;
    z80Ports[port] = value;     
}

inline void interruptHandlingTime(int wstates)
{
 tstates += wstates;     
}

inline unsigned char isActiveINT(void)
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
   Serial.printf("%c",(char)REG_E);
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
   Serial.printf("%s",cadLog);
   break;
  }
  default:
  {
   Serial.printf("BDOS Call %c\n",REG_C);
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

 #ifdef cfg_use_test_fps_48k
  unsigned int cur_fps=0;
  unsigned int time_end;
  unsigned int gb_min_frame;
  unsigned int gb_max_frame;
  unsigned int gb_cur_frame;  
  unsigned int aux_time_frame_ini;
  unsigned int ini_time_one_second= millis();   
  while ((millis()-ini_time_one_second)<1000)
  {   
   gb_min_frame=10000;
   gb_max_frame=0;
   gb_cur_frame=0;
   aux_time_frame_ini;
   tstates = 0;
   time_end= tstates + 69887;
   aux_time_frame_ini=millis();
   while (tstates <= time_end)
   {
    execute();
   }   
   gb_cur_frame= (millis()- aux_time_frame_ini);
   if (gb_cur_frame < gb_min_frame)
    gb_min_frame= gb_cur_frame;
   if (gb_cur_frame > gb_max_frame)   
    gb_max_frame= gb_cur_frame;
   cur_fps++; 
  }
  Serial.printf("fps(%d) - ms cur(%d) min(%d) max(%d)\n",cur_fps,gb_cur_frame,gb_min_frame,gb_max_frame);
 #else
  while (!finish)
  {
   execute();
  }
 #endif 
}



void setup()
{
 Serial.begin(115200);
 Serial.printf("BEGIN Test\n");
}

void loop()
{
 if (!finish)
 {
  #if defined(cfg_use_time_show) && !defined(cfg_use_time_per_line)
   ShowTime();
   runTest();
   ShowTime();
  #else
   runTest();
  #endif
  
  #ifndef cfg_use_test_fps_48k  
   Serial.printf("END Test\n");
  #endif 
 }
}
