//Mod C by ackerman
//NOT C POSIX
// Original author Jose Luis Sanchez C++
// Converted to C++ from Java at
//... https://github.com/jsanchezv/Z80Core
//... commit c4f267e3564fa89bd88fd2d1d322f4d6b0069dbd
//... GPL 3
//... v1.0.0 (13/02/2017)
//    quick & dirty conversion by dddddd (AKA deesix)
#ifndef _Z80_H
 #define _Z80_H

#include "gbConfig.h"
#include "gbGlobal.h"

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

unsigned char Z80_breakpoint(unsigned short int address, unsigned char opcode);






#endif


