//Mod C by ackerman ANDROID
//Compile with c4droid
//NOT C POSIX
#include <stdio.h>
#include <string.h>

#define cfg_use_time_show

#ifdef cfg_use_time_show
 #include <time.h>
#endif 




//GB_CONFIG_H BEGIN

//#define cfg_use_big_endian
//WITH_BREAKPOINT_SUPPORT

//Timer options
//#define cfg_use_time_show
#define cfg_use_time_per_line
//64 bits (slow) vs 32 bits (fast)
#define cfg_use_tstates_64bits

//Fast direct registers
#define cfg_use_direct_RegA
#define cfg_use_direct_RegB
#define cfg_use_direct_RegC
#define cfg_use_direct_RegD
#define cfg_use_direct_RegE
#define cfg_use_direct_RegH
#define cfg_use_direct_RegL

#define cfg_use_direct_REG_Ax
#define cfg_use_direct_REG_Fx
#define cfg_use_direct_REG_Bx
#define cfg_use_direct_REG_Cx
#define cfg_use_direct_REG_Dx
#define cfg_use_direct_REG_Ex
#define cfg_use_direct_REG_Hx
#define cfg_use_direct_REG_Lx

#define cfg_use_direct_REG_AFx
#define cfg_use_direct_REG_BC
#define cfg_use_direct_REG_BCx
#define cfg_use_direct_REG_DE
#define cfg_use_direct_REG_DEx
#define cfg_use_direct_REG_HL
#define cfg_use_direct_REG_HLx

#define cfg_use_direct_REG_PC
#define cfg_use_direct_REG_SP
#define cfg_use_direct_REG_IX
#define cfg_use_direct_REG_IY
#define cfg_use_direct_REG_I
#define cfg_use_direct_MemPtr
#define cfg_use_direct_CarryFlag

#define cfg_use_direct_IFF1
#define cfg_use_direct_IFF2
#define cfg_use_direct_NMI
#define cfg_use_direct_triggerNMI
#define cfg_use_direct_IM
#define cfg_use_direct_Halted
#define cfg_use_direct_PinReset
#define cfg_use_direct_PendingEI

//#define cfg_use_table_decode


//Options simulator
#define cfg_use_finish_fast
#define cfg_use_z80RAM_fast
#define cfg_use_z80Ports_fast
#define cfg_use_time_fast
//#define cfg_use_test_fps_48k
//GB_CONFIG_H END

//Inicio compila C POSIX
//RegisterPair regBC,regDE;
//void Z80Init();

//Fin compila C POSIX







//GB_GLOBAL_H BEGIN
 //Inicio Z80_H
 typedef union
 {
  #ifdef cfg_use_big_endian
   struct {
    unsigned char hi, lo;
   } byte8;  
  #else
   struct {
    unsigned char lo, hi;
   } byte8;
  #endif
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
//GB_GLOBAL_H END







//Z80_H BEGIN
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
//Z80_H END




//Z80_C BEGIN
unsigned char Z80_opCode;
unsigned char Z80_prefixOpcode = 0x00;
unsigned char Z80_execDone;
// Posiciones de los flags
const unsigned char Z80_CARRY_MASK = 0x01;
const unsigned char Z80_ADDSUB_MASK = 0x02;
const unsigned char Z80_PARITY_MASK = 0x04;
const unsigned char Z80_OVERFLOW_MASK = 0x04; // alias de PARITY_MASK
const unsigned char Z80_BIT3_MASK = 0x08;
const unsigned char Z80_HALFCARRY_MASK = 0x10;
const unsigned char Z80_BIT5_MASK = 0x20;
const unsigned char Z80_ZERO_MASK = 0x40;
const unsigned char Z80_SIGN_MASK = 0x80;
//const unsigned char Z80_FLAG_53_MASK = Z80_BIT5_MASK | Z80_BIT3_MASK;
//const unsigned char Z80_FLAG_SZ_MASK = Z80_SIGN_MASK | Z80_ZERO_MASK;
//const unsigned char Z80_FLAG_SZHN_MASK = Z80_FLAG_SZ_MASK | Z80_HALFCARRY_MASK | Z80_ADDSUB_MASK;
//const unsigned char Z80_FLAG_SZP_MASK = Z80_FLAG_SZ_MASK | Z80_PARITY_MASK;
//const unsigned char Z80_FLAG_SZHP_MASK = Z80_FLAG_SZP_MASK | Z80_HALFCARRY_MASK; 
const unsigned char Z80_FLAG_53_MASK = 0x20 | 0x08; //C POSIX
const unsigned char Z80_FLAG_SZ_MASK = 0x80 | 0x40; //C POSIX
const unsigned char Z80_FLAG_SZHN_MASK = (0x80 | 0x40) | 0x10 | 0x02; //C POSIX
const unsigned char Z80_FLAG_SZP_MASK = (0x80 | 0x40) | 0x04; //C POSIX
const unsigned char Z80_FLAG_SZHP_MASK = ((0x80 | 0x40) | 0x04) | 0x10; //C POSIX
unsigned char Z80_regA;
unsigned char Z80_sz5h3pnFlags;
unsigned char Z80_carryFlag;
RegisterPair regBC, regBCx, regDE, regDEx, regHL, regHLx;
unsigned char flagQ, lastFlagQ;
RegisterPair regAFx;
RegisterPair regPC; 
RegisterPair regIX;   
RegisterPair regIY;
RegisterPair regSP;
unsigned char Z80_regI;
unsigned char Z80_regR;
unsigned char Z80_regRbit7;
unsigned char Z80_ffIFF1 = false;
unsigned char Z80_ffIFF2 = false;
unsigned char Z80_pendingEI = false; 
unsigned char Z80_activeNMI = false;
unsigned char Z80_modeINT = IM0;
unsigned char Z80_halted = false;
unsigned char Z80_pinReset = false;
RegisterPair memptr;
unsigned char Z80_sz53n_addTable[256];
unsigned char Z80_sz53pn_addTable[256];
unsigned char Z80_sz53n_subTable[256];
unsigned char Z80_sz53pn_subTable[256];

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


void execute(void) {    
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

#ifdef cfg_use_table_decode
//Tabla void opcode Ini
void op_table_opcode0x00(){}
void op_table_opcode0x01(){ REG_BC = peek16(REG_PC); REG_PC = REG_PC + 2; }
void op_table_opcode0x02(){ poke8(REG_BC, Z80_regA); REG_W = Z80_regA; REG_Z = REG_C + 1; }
void op_table_opcode0x03(){ addressOnBus(getPairIR().word, 2); REG_BC++; }
void op_table_opcode0x04(){ inc8(&REG_B); }
void op_table_opcode0x05(){ dec8(&REG_B); }
void op_table_opcode0x06(){ REG_B = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x07(){
 Z80_carryFlag = (Z80_regA > 0x7f);
 Z80_regA <<= 1;
 if (Z80_carryFlag) {
  Z80_regA |= Z80_CARRY_MASK;
 }
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
 flagQ = true; 
}
void op_table_opcode0x08(){
 uint8_t work8 = Z80_regA;
 Z80_regA = REG_Ax;
 REG_Ax = work8;
 work8 = fast_getFlags();
 fast_setFlags(REG_Fx);
 REG_Fx = work8; 
}
void op_table_opcode0x09(){ addressOnBus(getPairIR().word, 7); add16(&regHL, REG_BC); }
void op_table_opcode0x0A(){ Z80_regA = peek8(REG_BC); REG_WZ = REG_BC + 1; }
void op_table_opcode0x0B(){ addressOnBus(getPairIR().word, 2); REG_BC--; }
void op_table_opcode0x0C(){ inc8(&REG_C); }
void op_table_opcode0x0D(){ dec8(&REG_C); }
void op_table_opcode0x0E(){ REG_C = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x0F(){
 Z80_carryFlag = (Z80_regA & Z80_CARRY_MASK) != 0;
 Z80_regA >>= 1;
 if (Z80_carryFlag) {
  Z80_regA |= Z80_SIGN_MASK;
 }
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
 flagQ = true; 
}
void op_table_opcode0x10(){
 addressOnBus(getPairIR().word, 1);
 int8_t offset = peek8(REG_PC);
 if (--REG_B != 0) {
  addressOnBus(REG_PC, 5);
  REG_PC = REG_WZ = REG_PC + offset + 1;
 } else {
  REG_PC++;
 } 
}
void op_table_opcode0x11(){ REG_DE = peek16(REG_PC); REG_PC = REG_PC + 2; }
void op_table_opcode0x12(){ poke8(REG_DE, Z80_regA); REG_W = Z80_regA; REG_Z = REG_E + 1; }
void op_table_opcode0x13(){ addressOnBus(getPairIR().word, 2); REG_DE++; }
void op_table_opcode0x14(){ inc8(&REG_D); }
void op_table_opcode0x15(){ dec8(&REG_D); }
void op_table_opcode0x16(){ REG_D = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x17(){
 unsigned char oldCarry = Z80_carryFlag;
 Z80_carryFlag = Z80_regA > 0x7f;
 Z80_regA <<= 1;
 if (oldCarry) {
  Z80_regA |= Z80_CARRY_MASK;
 }
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
 flagQ = true; 
}
void op_table_opcode0x18(){
 char offset = peek8(REG_PC);
 addressOnBus(REG_PC, 5);
 REG_PC = REG_WZ = REG_PC + offset + 1; 
}
void op_table_opcode0x19(){ addressOnBus(getPairIR().word, 7); add16(&regHL, REG_DE); }
void op_table_opcode0x1A(){ Z80_regA = peek8(REG_DE); REG_WZ = REG_DE + 1; }
void op_table_opcode0x1B(){ addressOnBus(getPairIR().word, 2); REG_DE--; }
void op_table_opcode0x1C(){ inc8(&REG_E); }
void op_table_opcode0x1D(){ dec8(&REG_E); }
void op_table_opcode0x1E(){ REG_E = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x1F(){ 
 unsigned char oldCarry = Z80_carryFlag;
 Z80_carryFlag = (Z80_regA & Z80_CARRY_MASK) != 0;
 Z80_regA >>= 1;
 if (oldCarry) {
  Z80_regA |= Z80_SIGN_MASK;
 }
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (Z80_regA & Z80_FLAG_53_MASK);
 flagQ = true; 
}
void op_table_opcode0x20(){
 char offset = peek8(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
  addressOnBus(REG_PC, 5);
  REG_PC += offset;
  REG_WZ = REG_PC + 1;
 }
 REG_PC++; 
}
void op_table_opcode0x21(){ REG_HL = peek16(REG_PC); REG_PC = REG_PC + 2; }
void op_table_opcode0x22(){ REG_WZ = peek16(REG_PC); poke16(REG_WZ, regHL); REG_WZ++; REG_PC = REG_PC + 2; }
void op_table_opcode0x23(){ addressOnBus(getPairIR().word, 2); REG_HL++; }
void op_table_opcode0x24(){ inc8(&REG_H); }
void op_table_opcode0x25(){ dec8(&REG_H); }
void op_table_opcode0x26(){ REG_H = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x27(){ daa(); }
void op_table_opcode0x28(){ 
 char offset = peek8(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
  addressOnBus(REG_PC, 5);
  REG_PC += offset;
  REG_WZ = REG_PC + 1;
 }
 REG_PC++; 
}
void op_table_opcode0x29(){ addressOnBus(getPairIR().word, 7); add16(&regHL, REG_HL); }
void op_table_opcode0x2A(){ REG_WZ = peek16(REG_PC); REG_HL = peek16(REG_WZ); REG_WZ++; REG_PC = REG_PC + 2; }
void op_table_opcode0x2B(){ addressOnBus(getPairIR().word, 2); REG_HL--; }
void op_table_opcode0x2C(){ inc8(&REG_L); }
void op_table_opcode0x2D(){ dec8(&REG_L); }
void op_table_opcode0x2E(){ REG_L = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x2F(){
 Z80_regA ^= 0xff;
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | Z80_HALFCARRY_MASK | (Z80_regA & Z80_FLAG_53_MASK) | Z80_ADDSUB_MASK;
 flagQ = true;
}
void op_table_opcode0x30(){
 char offset = peek8(REG_PC);
 if (!Z80_carryFlag) {
  addressOnBus(REG_PC, 5);
  REG_PC += offset;
  REG_WZ = REG_PC + 1;
 }
 REG_PC++; 
}
void op_table_opcode0x31(){ REG_SP = peek16(REG_PC); REG_PC = REG_PC + 2; }
void op_table_opcode0x32(){ REG_WZ = peek16(REG_PC); poke8(REG_WZ, Z80_regA); REG_WZ = (Z80_regA << 8) | ((REG_WZ + 1) & 0xff); REG_PC = REG_PC + 2; }
void op_table_opcode0x33(){ addressOnBus(getPairIR().word, 2); REG_SP++; }
void op_table_opcode0x34(){ 
 unsigned char work8 = peek8(REG_HL);
 inc8(&work8);
 addressOnBus(REG_HL, 1);
 poke8(REG_HL, work8); 
}
void op_table_opcode0x35(){
 unsigned char work8 = peek8(REG_HL);
 dec8(&work8);
 addressOnBus(REG_HL, 1);
 poke8(REG_HL, work8); 
}
void op_table_opcode0x36(){ poke8(REG_HL, peek8(REG_PC)); REG_PC++; }
void op_table_opcode0x37(){
 unsigned char regQ = lastFlagQ ? Z80_sz5h3pnFlags : 0;
 Z80_carryFlag = true;
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (((regQ ^ Z80_sz5h3pnFlags) | Z80_regA) & Z80_FLAG_53_MASK);
 flagQ = true; 
}
void op_table_opcode0x38(){
 char offset = peek8(REG_PC);
 if (Z80_carryFlag) {
  addressOnBus(REG_PC, 5);
  REG_PC += offset;
  REG_WZ = REG_PC + 1;
 }
 REG_PC++; 
}
void op_table_opcode0x39(){ addressOnBus(getPairIR().word, 7); add16(&regHL, REG_SP); }
void op_table_opcode0x3A(){ REG_WZ = peek16(REG_PC); Z80_regA = peek8(REG_WZ); REG_WZ++; REG_PC = REG_PC + 2; }
void op_table_opcode0x3B(){ addressOnBus(getPairIR().word, 2); REG_SP--; }
void op_table_opcode0x3C(){ inc8(&Z80_regA); }
void op_table_opcode0x3D(){ dec8(&Z80_regA); }
void op_table_opcode0x3E(){ Z80_regA = peek8(REG_PC); REG_PC++; }
void op_table_opcode0x3F(){
 unsigned char regQ = lastFlagQ ? Z80_sz5h3pnFlags : 0;
 Z80_sz5h3pnFlags = (Z80_sz5h3pnFlags & Z80_FLAG_SZP_MASK) | (((regQ ^ Z80_sz5h3pnFlags) | Z80_regA) & Z80_FLAG_53_MASK);
 if (Z80_carryFlag) {
  Z80_sz5h3pnFlags |= Z80_HALFCARRY_MASK;
 }
 Z80_carryFlag = !Z80_carryFlag;
 flagQ = true; 
}
void op_table_opcode0x40(){}
void op_table_opcode0x41(){ REG_B = REG_C; }
void op_table_opcode0x42(){ REG_B = REG_D; }
void op_table_opcode0x43(){ REG_B = REG_E; }
void op_table_opcode0x44(){ REG_B = REG_H; }
void op_table_opcode0x45(){ REG_B = REG_L; }
void op_table_opcode0x46(){ REG_B = peek8(REG_HL); }
void op_table_opcode0x47(){ REG_B = Z80_regA; }
void op_table_opcode0x48(){ REG_C = REG_B; }
void op_table_opcode0x49(){}
void op_table_opcode0x4A(){ REG_C = REG_D; }
void op_table_opcode0x4B(){ REG_C = REG_E; }
void op_table_opcode0x4C(){ REG_C = REG_H; }
void op_table_opcode0x4D(){ REG_C = REG_L; }
void op_table_opcode0x4E(){ REG_C = peek8(REG_HL); }
void op_table_opcode0x4F(){ REG_C = Z80_regA; }
void op_table_opcode0x50(){ REG_D = REG_B; }
void op_table_opcode0x51(){ REG_D = REG_C; }
void op_table_opcode0x52(){}
void op_table_opcode0x53(){ REG_D = REG_E; }
void op_table_opcode0x54(){ REG_D = REG_H; }
void op_table_opcode0x55(){ REG_D = REG_L; }
void op_table_opcode0x56(){ REG_D = peek8(REG_HL); }
void op_table_opcode0x57(){ REG_D = Z80_regA; }
void op_table_opcode0x58(){ REG_E = REG_B; }
void op_table_opcode0x59(){ REG_E = REG_C; }
void op_table_opcode0x5A(){ REG_E = REG_D; }
void op_table_opcode0x5B(){}
void op_table_opcode0x5C(){ REG_E = REG_H; }
void op_table_opcode0x5D(){ REG_E = REG_L; }
void op_table_opcode0x5E(){ REG_E = peek8(REG_HL); }
void op_table_opcode0x5F(){ REG_E = Z80_regA; }
void op_table_opcode0x60(){ REG_H = REG_B; }
void op_table_opcode0x61(){ REG_H = REG_C; }
void op_table_opcode0x62(){ REG_H = REG_D; }
void op_table_opcode0x63(){ REG_H = REG_E; }
void op_table_opcode0x64(){}
void op_table_opcode0x65(){ REG_H = REG_L; }
void op_table_opcode0x66(){ REG_H = peek8(REG_HL); }
void op_table_opcode0x67(){ REG_H = Z80_regA; }
void op_table_opcode0x68(){ REG_L = REG_B; }
void op_table_opcode0x69(){ REG_L = REG_C; }
void op_table_opcode0x6A(){ REG_L = REG_D; }
void op_table_opcode0x6B(){ REG_L = REG_E; }
void op_table_opcode0x6C(){ REG_L = REG_H; }
void op_table_opcode0x6D(){}
void op_table_opcode0x6E(){ REG_L = peek8(REG_HL); }
void op_table_opcode0x6F(){ REG_L = Z80_regA; }
void op_table_opcode0x70(){ poke8(REG_HL, REG_B); }
void op_table_opcode0x71(){ poke8(REG_HL, REG_C); }
void op_table_opcode0x72(){ poke8(REG_HL, REG_D); }
void op_table_opcode0x73(){ poke8(REG_HL, REG_E); }
void op_table_opcode0x74(){ poke8(REG_HL, REG_H); }
void op_table_opcode0x75(){ poke8(REG_HL, REG_L); }
void op_table_opcode0x76(){ REG_PC--; Z80_halted = true; }
void op_table_opcode0x77(){ poke8(REG_HL, Z80_regA); }
void op_table_opcode0x78(){ Z80_regA = REG_B; }
void op_table_opcode0x79(){ Z80_regA = REG_C; }
void op_table_opcode0x7A(){ Z80_regA = REG_D; }
void op_table_opcode0x7B(){ Z80_regA = REG_E; }
void op_table_opcode0x7C(){ Z80_regA = REG_H; }
void op_table_opcode0x7D(){ Z80_regA = REG_L; }
void op_table_opcode0x7E(){ Z80_regA = peek8(REG_HL); }
void op_table_opcode0x7F(){}
void op_table_opcode0x80(){ add(REG_B); }
void op_table_opcode0x81(){ add(REG_C); }
void op_table_opcode0x82(){ add(REG_D); }
void op_table_opcode0x83(){ add(REG_E); }
void op_table_opcode0x84(){ add(REG_H); }
void op_table_opcode0x85(){ add(REG_L); }
void op_table_opcode0x86(){ add(peek8(REG_HL)); }
void op_table_opcode0x87(){ add(Z80_regA); }
void op_table_opcode0x88(){ adc(REG_B); }
void op_table_opcode0x89(){ adc(REG_C); }
void op_table_opcode0x8A(){ adc(REG_D); }
void op_table_opcode0x8B(){ adc(REG_E); }
void op_table_opcode0x8C(){ adc(REG_H); }
void op_table_opcode0x8D(){ adc(REG_L); }
void op_table_opcode0x8E(){ adc(peek8(REG_HL)); }
void op_table_opcode0x8F(){ adc(Z80_regA); }
void op_table_opcode0x90(){ sub(REG_B); }
void op_table_opcode0x91(){ sub(REG_C); }
void op_table_opcode0x92(){ sub(REG_D); }
void op_table_opcode0x93(){ sub(REG_E); }
void op_table_opcode0x94(){ sub(REG_H); }
void op_table_opcode0x95(){ sub(REG_L); }
void op_table_opcode0x96(){ sub(peek8(REG_HL)); }
void op_table_opcode0x97(){ sub(Z80_regA); }
void op_table_opcode0x98(){ sbc(REG_B); }
void op_table_opcode0x99(){ sbc(REG_C); }
void op_table_opcode0x9A(){ sbc(REG_D); }
void op_table_opcode0x9B(){ sbc(REG_E); }
void op_table_opcode0x9C(){ sbc(REG_H); }
void op_table_opcode0x9D(){ sbc(REG_L); }
void op_table_opcode0x9E(){ sbc(peek8(REG_HL)); }
void op_table_opcode0x9F(){ sbc(Z80_regA); }
void op_table_opcode0xA0(){ and_(REG_B); }
void op_table_opcode0xA1(){ and_(REG_C); }
void op_table_opcode0xA2(){ and_(REG_D); }
void op_table_opcode0xA3(){ and_(REG_E); }
void op_table_opcode0xA4(){ and_(REG_H); }
void op_table_opcode0xA5(){ and_(REG_L); }
void op_table_opcode0xA6(){ and_(peek8(REG_HL)); }
void op_table_opcode0xA7(){ and_(Z80_regA); }
void op_table_opcode0xA8(){ xor_(REG_B); }
void op_table_opcode0xA9(){ xor_(REG_C); }
void op_table_opcode0xAA(){ xor_(REG_D); }
void op_table_opcode0xAB(){ xor_(REG_E); }
void op_table_opcode0xAC(){ xor_(REG_H); }
void op_table_opcode0xAD(){ xor_(REG_L); }
void op_table_opcode0xAE(){ xor_(peek8(REG_HL)); }
void op_table_opcode0xAF(){ xor_(Z80_regA); }
void op_table_opcode0xB0(){ or_(REG_B); }
void op_table_opcode0xB1(){ or_(REG_C); }
void op_table_opcode0xB2(){ or_(REG_D); }
void op_table_opcode0xB3(){ or_(REG_E); }
void op_table_opcode0xB4(){ or_(REG_H); }
void op_table_opcode0xB5(){ or_(REG_L); }
void op_table_opcode0xB6(){ or_(peek8(REG_HL)); }
void op_table_opcode0xB7(){ or_(Z80_regA); }
void op_table_opcode0xB8(){ cp(REG_B); }
void op_table_opcode0xB9(){ cp(REG_C); }
void op_table_opcode0xBA(){ cp(REG_D); }
void op_table_opcode0xBB(){ cp(REG_E); }
void op_table_opcode0xBC(){ cp(REG_H); }
void op_table_opcode0xBD(){ cp(REG_L); }
void op_table_opcode0xBE(){ cp(peek8(REG_HL)); }
void op_table_opcode0xBF(){ cp(Z80_regA); }
void op_table_opcode0xC0(){
 addressOnBus(getPairIR().word, 1);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xC1(){ REG_BC = pop(); }
void op_table_opcode0xC2(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xC3(){ REG_WZ = REG_PC = peek16(REG_PC); }
void op_table_opcode0xC4(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) == 0) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xC5(){ addressOnBus(getPairIR().word, 1); push(REG_BC); }
void op_table_opcode0xC6(){ add(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xC7(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x00; }
void op_table_opcode0xC8(){
 addressOnBus(getPairIR().word, 1);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xC9(){ REG_PC = REG_WZ = pop(); }
void op_table_opcode0xCA(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xCB(){ decodeCB(); }
void op_table_opcode0xCC(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_ZERO_MASK) != 0) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xCD(){ REG_WZ = peek16(REG_PC); addressOnBus(REG_PC + 1, 1); push(REG_PC + 2); REG_PC = REG_WZ; }
void op_table_opcode0xCE(){ adc(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xCF(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x08; }
void op_table_opcode0xD0(){
 addressOnBus(getPairIR().word, 1);
 if (!Z80_carryFlag) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xD1(){ REG_DE = pop(); }
void op_table_opcode0xD2(){
 REG_WZ = peek16(REG_PC);
 if (!Z80_carryFlag) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xD3(){
 unsigned char work8 = peek8(REG_PC);
 REG_PC++;
 REG_WZ = Z80_regA << 8;
 outPort(REG_WZ | work8, Z80_regA);
 REG_WZ |= (work8 + 1);
}
void op_table_opcode0xD4(){
 REG_WZ = peek16(REG_PC);
 if (!Z80_carryFlag) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xD5(){ addressOnBus(getPairIR().word, 1); push(REG_DE); }
void op_table_opcode0xD6(){ sub(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xD7(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x10; }
void op_table_opcode0xD8(){
 addressOnBus(getPairIR().word, 1);
 if (Z80_carryFlag){
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xD9(){
 unsigned short int tmp;
 tmp = REG_BC;
 REG_BC = REG_BCx;
 REG_BCx = tmp;
 tmp = REG_DE;
 REG_DE = REG_DEx;
 REG_DEx = tmp;
 tmp = REG_HL;
 REG_HL = REG_HLx;
 REG_HLx = tmp;
}
void op_table_opcode0xDA(){
 REG_WZ = peek16(REG_PC);
 if (Z80_carryFlag) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xDB(){ REG_W = Z80_regA; REG_Z = peek8(REG_PC); REG_PC++; Z80_regA = inPort(REG_WZ); REG_WZ++; }
void op_table_opcode0xDC(){
 REG_WZ = peek16(REG_PC);
 if (Z80_carryFlag) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
//JJ revisar
void op_table_opcode0xDD(){ unsigned char opCode = fetchOpcode(REG_PC++); Z80_regR++; decodeDDFD(opCode, &regIX); }
//JJ fin revisar
void op_table_opcode0xDE(){ sbc(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xDF(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x18; }
void op_table_opcode0xE0(){
 addressOnBus(getPairIR().word, 1);
 if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == 0) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xE1(){ REG_HL = pop(); }
void op_table_opcode0xE2(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == 0){
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xE3(){
 RegisterPair work = regHL;
 REG_HL = peek16(REG_SP);
 addressOnBus(REG_SP + 1, 1);    
 poke8(REG_SP + 1, work.byte8.hi);
 poke8(REG_SP, work.byte8.lo);
 addressOnBus(REG_SP, 2);
 REG_WZ = REG_HL;
}
void op_table_opcode0xE4(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) == 0) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xE5(){ addressOnBus(getPairIR().word, 1); push(REG_HL); }
void op_table_opcode0xE6(){ and_(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xE7(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x20; }
void op_table_opcode0xE8(){
 addressOnBus(getPairIR().word, 1);
 if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xE9(){ REG_PC = REG_HL; }
void op_table_opcode0xEA(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xEB(){
 unsigned short int tmp = REG_HL;
 REG_HL = REG_DE;
 REG_DE = tmp;
}
void op_table_opcode0xEC(){
 REG_WZ = peek16(REG_PC);
 if ((Z80_sz5h3pnFlags & Z80_PARITY_MASK) != 0) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
//JJ revisar
void op_table_opcode0xED(){ unsigned char opCode = fetchOpcode(REG_PC++); Z80_regR++; decodeED(opCode); }
//fin revisar fin
void op_table_opcode0xEE(){ xor_(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xEF(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x28; }
void op_table_opcode0xF0(){
 addressOnBus(getPairIR().word, 1);
 if (Z80_sz5h3pnFlags < Z80_SIGN_MASK) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xF1(){ fast_setRegAF(pop()); }
void op_table_opcode0xF2(){ REG_WZ = peek16(REG_PC);
 if (Z80_sz5h3pnFlags < Z80_SIGN_MASK) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xF3(){ Z80_ffIFF1 = Z80_ffIFF2 = false; }
void op_table_opcode0xF4(){
 REG_WZ = peek16(REG_PC);
 if (Z80_sz5h3pnFlags < Z80_SIGN_MASK) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xF5(){ addressOnBus(getPairIR().word, 1); push(fast_getRegAF()); }
void op_table_opcode0xF6(){ or_(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xF7(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x30;}
void op_table_opcode0xF8(){
 addressOnBus(getPairIR().word, 1);
 if (Z80_sz5h3pnFlags > 0x7f) {
  REG_PC = REG_WZ = pop();
 }
}
void op_table_opcode0xF9(){ addressOnBus(getPairIR().word, 2); REG_SP = REG_HL; }
void op_table_opcode0xFA(){
 REG_WZ = peek16(REG_PC);
 if (Z80_sz5h3pnFlags > 0x7f) {
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
void op_table_opcode0xFB(){ Z80_ffIFF1 = Z80_ffIFF2 = true; Z80_pendingEI = true; }
void op_table_opcode0xFC(){
 REG_WZ = peek16(REG_PC);
 if (Z80_sz5h3pnFlags > 0x7f) {
  addressOnBus(REG_PC + 1, 1);
  push(REG_PC + 2);
  REG_PC = REG_WZ;
  return;
 }
 REG_PC = REG_PC + 2;
}
//JJ revisar ini
void op_table_opcode0xFD(){unsigned char opCode = fetchOpcode(REG_PC++); Z80_regR++; decodeDDFD(opCode, &regIY); }
//JJ fin revisar
void op_table_opcode0xFE(){ cp(peek8(REG_PC)); REG_PC++; }
void op_table_opcode0xFF(){ addressOnBus(getPairIR().word, 1); push(REG_PC); REG_PC = REG_WZ = 0x38; }
//Tabla void opcode FIN

//0x00 0x40 0x49 0x52 0x5B 0x64 0x6D 0x7F iguales
void (* gb_array_ptr_table_opcode[0xFF])() = {
op_table_opcode0x00,
op_table_opcode0x01,op_table_opcode0x02,op_table_opcode0x03,op_table_opcode0x04,op_table_opcode0x05,op_table_opcode0x06,op_table_opcode0x07,op_table_opcode0x08,op_table_opcode0x09,op_table_opcode0x0A,op_table_opcode0x0B,op_table_opcode0x0C,op_table_opcode0x0D,op_table_opcode0x0E,op_table_opcode0x0F,op_table_opcode0x10,
op_table_opcode0x11,op_table_opcode0x12,op_table_opcode0x13,op_table_opcode0x14,op_table_opcode0x15,op_table_opcode0x16,op_table_opcode0x17,op_table_opcode0x18,op_table_opcode0x19,op_table_opcode0x1A,op_table_opcode0x1B,op_table_opcode0x1C,op_table_opcode0x1D,op_table_opcode0x1E,op_table_opcode0x1F,op_table_opcode0x20,
op_table_opcode0x21,op_table_opcode0x22,op_table_opcode0x23,op_table_opcode0x24,op_table_opcode0x25,op_table_opcode0x26,op_table_opcode0x27,op_table_opcode0x28,op_table_opcode0x29,op_table_opcode0x2A,op_table_opcode0x2B,op_table_opcode0x2C,op_table_opcode0x2D,op_table_opcode0x2E,op_table_opcode0x2F,op_table_opcode0x30,
op_table_opcode0x31,op_table_opcode0x32,op_table_opcode0x33,op_table_opcode0x34,op_table_opcode0x35,op_table_opcode0x36,op_table_opcode0x37,op_table_opcode0x38,op_table_opcode0x39,op_table_opcode0x3A,op_table_opcode0x3B,op_table_opcode0x3C,op_table_opcode0x3D,op_table_opcode0x3E,op_table_opcode0x3F,op_table_opcode0x00,
op_table_opcode0x41,op_table_opcode0x42,op_table_opcode0x43,op_table_opcode0x44,op_table_opcode0x45,op_table_opcode0x46,op_table_opcode0x47,op_table_opcode0x48,op_table_opcode0x00,op_table_opcode0x4A,op_table_opcode0x4B,op_table_opcode0x4C,op_table_opcode0x4D,op_table_opcode0x4E,op_table_opcode0x4F,op_table_opcode0x50,
op_table_opcode0x51,op_table_opcode0x00,op_table_opcode0x53,op_table_opcode0x54,op_table_opcode0x55,op_table_opcode0x56,op_table_opcode0x57,op_table_opcode0x58,op_table_opcode0x59,op_table_opcode0x5A,op_table_opcode0x00,op_table_opcode0x5C,op_table_opcode0x5D,op_table_opcode0x5E,op_table_opcode0x5F,op_table_opcode0x60,
op_table_opcode0x61,op_table_opcode0x62,op_table_opcode0x63,op_table_opcode0x00,op_table_opcode0x65,op_table_opcode0x66,op_table_opcode0x67,op_table_opcode0x68,op_table_opcode0x69,op_table_opcode0x6A,op_table_opcode0x6B,op_table_opcode0x6C,op_table_opcode0x00,op_table_opcode0x6E,op_table_opcode0x6F,op_table_opcode0x70,
op_table_opcode0x71,op_table_opcode0x72,op_table_opcode0x73,op_table_opcode0x74,op_table_opcode0x75,op_table_opcode0x76,op_table_opcode0x77,op_table_opcode0x78,op_table_opcode0x79,op_table_opcode0x7A,op_table_opcode0x7B,op_table_opcode0x7C,op_table_opcode0x7D,op_table_opcode0x7E,op_table_opcode0x00,op_table_opcode0x80,
op_table_opcode0x81,op_table_opcode0x82,op_table_opcode0x83,op_table_opcode0x84,op_table_opcode0x85,op_table_opcode0x86,op_table_opcode0x87,op_table_opcode0x88,op_table_opcode0x89,op_table_opcode0x8A,op_table_opcode0x8B,op_table_opcode0x8C,op_table_opcode0x8D,op_table_opcode0x8E,op_table_opcode0x8F,op_table_opcode0x90,
op_table_opcode0x91,op_table_opcode0x92,op_table_opcode0x93,op_table_opcode0x94,op_table_opcode0x95,op_table_opcode0x96,op_table_opcode0x97,op_table_opcode0x98,op_table_opcode0x99,op_table_opcode0x9A,op_table_opcode0x9B,op_table_opcode0x9C,op_table_opcode0x9D,op_table_opcode0x9E,op_table_opcode0x9F,op_table_opcode0xA0,
op_table_opcode0xA1,op_table_opcode0xA2,op_table_opcode0xA3,op_table_opcode0xA4,op_table_opcode0xA5,op_table_opcode0xA6,op_table_opcode0xA7,op_table_opcode0xA8,op_table_opcode0xA9,op_table_opcode0xAA,op_table_opcode0xAB,op_table_opcode0xAC,op_table_opcode0xAD,op_table_opcode0xAE,op_table_opcode0xAF,op_table_opcode0xB0,
op_table_opcode0xB1,op_table_opcode0xB2,op_table_opcode0xB3,op_table_opcode0xB4,op_table_opcode0xB5,op_table_opcode0xB6,op_table_opcode0xB7,op_table_opcode0xB8,op_table_opcode0xB9,op_table_opcode0xBA,op_table_opcode0xBB,op_table_opcode0xBC,op_table_opcode0xBD,op_table_opcode0xBE,op_table_opcode0xBF,op_table_opcode0xC0,
op_table_opcode0xC1,op_table_opcode0xC2,op_table_opcode0xC3,op_table_opcode0xC4,op_table_opcode0xC5,op_table_opcode0xC6,op_table_opcode0xC7,op_table_opcode0xC8,op_table_opcode0xC9,op_table_opcode0xCA,op_table_opcode0xCB,op_table_opcode0xCC,op_table_opcode0xCD,op_table_opcode0xCE,op_table_opcode0xCF,op_table_opcode0xD0,
op_table_opcode0xD1,op_table_opcode0xD2,op_table_opcode0xD3,op_table_opcode0xD4,op_table_opcode0xD5,op_table_opcode0xD6,op_table_opcode0xD7,op_table_opcode0xD8,op_table_opcode0xD9,op_table_opcode0xDA,op_table_opcode0xDB,op_table_opcode0xDC,op_table_opcode0xDD,op_table_opcode0xDE,op_table_opcode0xDF,op_table_opcode0xE0,
op_table_opcode0xE1,op_table_opcode0xE2,op_table_opcode0xE3,op_table_opcode0xE4,op_table_opcode0xE5,op_table_opcode0xE6,op_table_opcode0xE7,op_table_opcode0xE8,op_table_opcode0xE9,op_table_opcode0xEA,op_table_opcode0xEB,op_table_opcode0xEC,op_table_opcode0xED,op_table_opcode0xEE,op_table_opcode0xEF,op_table_opcode0xF0,
op_table_opcode0xF1,op_table_opcode0xF2,op_table_opcode0xF3,op_table_opcode0xF4,op_table_opcode0xF5,op_table_opcode0xF6,op_table_opcode0xF7,op_table_opcode0xF8,op_table_opcode0xF9,op_table_opcode0xFA,op_table_opcode0xFB,op_table_opcode0xFC,op_table_opcode0xFD,op_table_opcode0xFE
};
#endif


#ifdef cfg_use_table_decode
void decodeOpcode(unsigned char opCode)
{
 (*gb_array_ptr_table_opcode[opCode])();
}
#else
void decodeOpcode(unsigned char opCode) 
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
#endif

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

//Z80_C END





//ZXALLBIN_H BEGIN
 //8590 bytes
unsigned char zx_all_bin[]={
0xC3,0x13,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x2A,0x06,0x00,0xF9,0x11,0xDC,0x1D,0x0E,0x09,0xCD,0xD0,0x1D,0x21,
0x3C,0x01,0x7E,0x23,0xB6,0xCA,0x2F,0x01,0x2B,0xCD,0xE4,0x1A,0xC3,0x22,0x01,0x11,
0xFB,0x1D,0x0E,0x09,0xCD,0xD0,0x1D,0x0E,0x00,0xCD,0xD0,0x1D,0xC4,0x01,0x24,0x02,
0x84,0x02,0xE4,0x02,0x44,0x03,0xA4,0x03,0x04,0x04,0x64,0x04,0xC4,0x04,0x24,0x05,
0x84,0x05,0xE4,0x05,0x44,0x06,0xA4,0x06,0x04,0x07,0x64,0x07,0xC4,0x07,0x24,0x08,
0x84,0x08,0xE4,0x08,0x44,0x09,0xA4,0x09,0x04,0x0A,0x64,0x0A,0xC4,0x0A,0x24,0x0B,
0x84,0x0B,0xE4,0x0B,0x44,0x0C,0xA4,0x0C,0x04,0x0D,0x64,0x0D,0xC4,0x0D,0x24,0x0E,
0x84,0x0E,0xE4,0x0E,0x44,0x0F,0xA4,0x0F,0x04,0x10,0x64,0x10,0xC4,0x10,0x24,0x11,
0x84,0x11,0xE4,0x11,0x44,0x12,0xA4,0x12,0x04,0x13,0x64,0x13,0xC4,0x13,0x24,0x14,
0x84,0x14,0xE4,0x14,0x44,0x15,0xA4,0x15,0x04,0x16,0x64,0x16,0xC4,0x16,0x24,0x17,
0x84,0x17,0xE4,0x17,0x44,0x18,0xA4,0x18,0x04,0x19,0x64,0x19,0xC4,0x19,0x24,0x1A,
0x84,0x1A,0x00,0x00,0xFF,0xED,0x42,0x00,0x00,0x2C,0x83,0x88,0x4F,0x2B,0xF2,0x39,
0xB3,0x1F,0x7E,0x63,0x15,0xD3,0x89,0x5E,0x46,0x00,0x38,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD7,0x00,0xFF,
0xFF,0xD4,0x8A,0xD5,0x19,0x3C,0x61,0x64,0x63,0x2C,0x73,0x62,0x63,0x3E,0x20,0x68,
0x6C,0x2C,0x3C,0x62,0x63,0x2C,0x64,0x65,0x2C,0x68,0x6C,0x2C,0x73,0x70,0x3E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x09,0x00,0x00,0x00,0xA5,0xC4,0xC7,0xC4,0x26,0xD2,0x50,
0xA0,0xEA,0x58,0x66,0x85,0xC6,0xDE,0xC9,0x9B,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD7,0x00,0xFF,
0xFF,0xD9,0xA4,0xCA,0x05,0x61,0x64,0x64,0x20,0x68,0x6C,0x2C,0x3C,0x62,0x63,0x2C,
0x64,0x65,0x2C,0x68,0x6C,0x2C,0x73,0x70,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x09,0x00,0x00,0xAC,0xDD,0x94,0xC2,0x5B,0x63,0xD3,
0x33,0x76,0x6A,0x20,0xFA,0x94,0x68,0xF5,0x36,0x00,0x30,0x00,0x00,0x00,0x00,0x00,
0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0x00,0xFF,
0xFF,0xB1,0xDF,0x8E,0xC0,0x61,0x64,0x64,0x20,0x69,0x78,0x2C,0x3C,0x62,0x63,0x2C,
0x64,0x65,0x2C,0x69,0x78,0x2C,0x73,0x70,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xFD,0x09,0x00,0x00,0xC2,0xC7,0x07,0xF4,0xC1,0x51,0x96,
0x3E,0xF4,0x0B,0x0F,0x51,0x92,0x1E,0xEA,0x71,0x00,0x30,0x00,0x00,0x00,0x00,0x21,
0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0x00,0xFF,
0xFF,0x39,0xC8,0x58,0x9B,0x61,0x64,0x64,0x20,0x69,0x79,0x2C,0x3C,0x62,0x63,0x2C,
0x64,0x65,0x2C,0x69,0x79,0x2C,0x73,0x70,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xC6,0x00,0x00,0x00,0x40,0x91,0x3C,0x7E,0x67,0x7A,0x6D,
0xDF,0x61,0x5B,0x29,0x0B,0x10,0x66,0xB2,0x85,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x51,0xC1,0x9C,0x2E,0x61,0x6C,0x75,0x6F,0x70,0x20,0x61,0x2C,0x6E,0x6E,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x80,0x00,0x00,0x00,0x3E,0xC5,0x3A,0x57,0x4D,0x4C,0x03,
0x01,0x09,0xE3,0x66,0xA6,0xD0,0x3B,0xBB,0xAD,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0x00,0x00,
0x00,0x06,0xC7,0xAA,0x8E,0x61,0x6C,0x75,0x6F,0x70,0x20,0x61,0x2C,0x3C,0x62,0x2C,
0x63,0x2C,0x64,0x2C,0x65,0x2C,0x68,0x2C,0x6C,0x2C,0x28,0x68,0x6C,0x29,0x2C,0x61,
0x3E,0x2E,0x2E,0x24,0xFF,0xDD,0x84,0x00,0x00,0xF7,0xD6,0x6E,0xC7,0xCF,0xAC,0x47,
0x28,0xDD,0x22,0x35,0xC0,0xC5,0x38,0x4B,0x23,0x20,0x39,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0x00,0x00,
0x00,0xA8,0x86,0xCC,0x44,0x61,0x6C,0x75,0x6F,0x70,0x20,0x61,0x2C,0x3C,0x69,0x78,
0x68,0x2C,0x69,0x78,0x6C,0x2C,0x69,0x79,0x68,0x2C,0x69,0x79,0x6C,0x3E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x86,0x01,0x00,0xB7,0x90,0x02,0x01,0x02,0x01,0xFD,
0x32,0x6E,0x40,0xDC,0xC1,0x45,0x6E,0xFA,0xE5,0x20,0x38,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xD3,0xF2,0xD7,0x4A,0x61,0x6C,0x75,0x6F,0x70,0x20,0x61,0x2C,0x28,0x3C,0x69,
0x78,0x2C,0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0xCB,0x01,0x46,0x75,0x20,0x02,0x01,0x02,0x01,0xFC,
0x3C,0x9A,0xA7,0x74,0x3D,0x51,0x27,0x14,0xCA,0x20,0x00,0x00,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x83,0x53,0x4E,0xE1,0x62,0x69,0x74,0x20,0x6E,0x2C,0x28,0x3C,0x69,0x78,0x2C,
0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xCB,0x40,0x00,0x00,0xF1,0x3E,0xFC,0x9D,0xCC,0x7A,0x03,
0x01,0x61,0xBE,0x86,0x7A,0x50,0x24,0x98,0x19,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0x00,
0x00,0x5E,0x02,0x0E,0x98,0x62,0x69,0x74,0x20,0x6E,0x2C,0x3C,0x62,0x2C,0x63,0x2C,
0x64,0x2C,0x65,0x2C,0x68,0x2C,0x6C,0x2C,0x28,0x68,0x6C,0x29,0x2C,0x61,0x3E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0xA9,0x00,0x00,0xB6,0xC7,0xB4,0x72,0xF6,0x18,0x14,
0x01,0xBD,0x8D,0x01,0x00,0xC0,0x30,0xA3,0x94,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x13,0x4B,0x62,0x2D,0x63,0x70,0x64,0x3C,0x72,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0xA1,0x00,0x00,0x48,0x4D,0x4A,0xAF,0x6B,0x90,0x03,
0x01,0x71,0x4E,0x01,0x00,0x93,0x6A,0x7C,0x90,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x2D,0xA4,0x2D,0x19,0x63,0x70,0x69,0x3C,0x72,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x27,0x00,0x00,0x00,0x41,0x21,0xFA,0x09,0x60,0x1D,0x59,
0xA5,0x5B,0x8D,0x79,0x90,0x04,0x8E,0x9D,0x29,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x6D,0x2D,0xD2,0x13,0x3C,0x64,0x61,0x61,0x2C,0x63,0x70,0x6C,0x2C,0x73,0x63,
0x66,0x2C,0x63,0x63,0x66,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x3C,0x00,0x00,0x00,0xDF,0x4A,0xD8,0xD5,0x98,0xE5,0x2B,
0x8A,0xB0,0xA7,0x1B,0x43,0x44,0x5A,0x30,0xD0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x81,0xFA,0x81,0x00,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x61,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x04,0x00,0x00,0x00,0x23,0xD6,0x2D,0x43,0x61,0x7A,0x80,
0x81,0x86,0x5A,0x85,0x1E,0x86,0x58,0xBB,0x9B,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x77,0xF3,0x5A,0x73,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x62,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x03,0x00,0x00,0x00,0x97,0xCD,0xAB,0x44,0xC9,0x8D,0xE3,
0xE3,0xCC,0x11,0xA4,0xE8,0x02,0x49,0x4D,0x2A,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xD2,0xAE,0x3B,0xEC,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x62,
0x63,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x0C,0x00,0x00,0x00,0x89,0xD7,0x35,0x09,0x5B,0x05,0x85,
0x9F,0x27,0x8B,0x08,0xD2,0x95,0x05,0x60,0x06,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x1A,0xF6,0x12,0xA7,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x63,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x14,0x00,0x00,0x00,0xEA,0xA0,0xBA,0x5F,0xFB,0x65,0x1C,
0x98,0xCC,0x38,0xBC,0xDE,0x43,0x5C,0xBD,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xD1,0x46,0xBF,0x51,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x64,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x13,0x00,0x00,0x00,0x2E,0x34,0x1D,0x13,0xC9,0x28,0xCA,
0x0A,0x67,0x99,0x2E,0x3A,0x92,0xF6,0x54,0x9D,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xAE,0xC6,0xD4,0x2C,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x64,
0x65,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x1C,0x00,0x00,0x00,0x2F,0x60,0x0D,0x4C,0x02,0x24,0xF5,
0xE2,0xF4,0xA0,0x0A,0xA1,0x13,0x32,0x25,0x59,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xCA,0x8C,0x6A,0xC2,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x65,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x24,0x00,0x00,0x00,0x06,0x15,0xEB,0xF2,0xDD,0xE8,0x2B,
0x26,0xA6,0x11,0x1A,0xBC,0x17,0x06,0x18,0x28,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x56,0x0F,0x95,0x5E,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x68,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x23,0x00,0x00,0x00,0xF4,0xC3,0xA5,0x07,0x6D,0x1B,0x04,
0x4F,0xC2,0xE2,0x2A,0x82,0x57,0xE0,0xE1,0xC3,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xFC,0x0D,0x6D,0x4A,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x68,
0x6C,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x23,0x00,0x00,0x3C,0xBC,0x9B,0x0D,0x81,0xE0,0xFD,
0xAD,0x7F,0x9A,0xE5,0x96,0x13,0x85,0xE2,0x0B,0x00,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x21,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xA5,0x4D,0xBE,0x31,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x69,
0x78,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xFD,0x23,0x00,0x00,0x02,0x94,0x7A,0x63,0x82,0x31,0x5A,
0xC6,0xE9,0xB2,0xB4,0xAB,0x16,0xF2,0x05,0x6D,0x00,0x08,0x00,0x00,0x00,0x00,0x21,
0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x50,0x5D,0x51,0xA3,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x69,
0x79,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x2C,0x00,0x00,0x00,0x31,0x80,0x20,0xA5,0x56,0x43,0x09,
0xB4,0xC1,0xF4,0xA2,0xDF,0xD1,0x3C,0xA2,0x3E,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xA0,0xA1,0xB4,0x9F,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x6C,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x34,0x00,0x00,0x00,0x56,0xB8,0x7C,0x0C,0x3E,0xE5,0x03,
0x01,0x7E,0x87,0x58,0xDA,0x15,0x5C,0x37,0x1F,0x01,0x00,0x00,0x00,0xFF,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x28,0x29,0x5E,0xCE,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x28,
0x68,0x6C,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x33,0x00,0x00,0x00,0x6F,0x34,0x82,0xD4,0x69,0xD1,0xB6,
0xDE,0x94,0xA4,0x76,0xF4,0x53,0x02,0x5B,0x85,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0xF8,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x5D,0xAC,0xD5,0x27,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x73,
0x70,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x34,0x01,0x00,0x6E,0xFA,0x02,0x01,0x02,0x01,0x28,
0x2C,0x94,0x88,0x57,0x50,0x16,0x33,0x6F,0x28,0x20,0x01,0x00,0x00,0xFF,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x0B,0x95,0xA8,0xEA,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x28,
0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x24,0x00,0x00,0x38,0xB8,0x6C,0x31,0xD4,0xC6,0x01,
0x3E,0x58,0x83,0xB4,0x15,0x81,0xDE,0x59,0x42,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x6F,0x46,0x36,0x62,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x69,
0x78,0x68,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x2C,0x00,0x00,0x14,0x4D,0x60,0x74,0xD4,0x76,0xE7,
0x06,0xA2,0x32,0x3C,0x21,0xD6,0xD7,0xA5,0x99,0x00,0x01,0x00,0x00,0x00,0x00,0xFF,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x02,0x7B,0xEF,0x2C,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x69,
0x78,0x6C,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x24,0x00,0x00,0x36,0x28,0x6F,0x9F,0x16,0x91,0xB9,
0x61,0xCB,0x82,0x19,0xE2,0x92,0x73,0x8C,0xA9,0x00,0x01,0x00,0x00,0x00,0xFF,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x2D,0x96,0x6C,0xF3,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x69,
0x79,0x68,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x2C,0x00,0x00,0xC6,0xD7,0xD5,0x62,0x9E,0xA0,0x39,
0x70,0x7E,0x3E,0x12,0x9F,0x90,0xD9,0x0F,0x22,0x00,0x01,0x00,0x00,0xFF,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x36,0xC1,0x1E,0x75,0x3C,0x69,0x6E,0x63,0x2C,0x64,0x65,0x63,0x3E,0x20,0x69,
0x79,0x6C,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0x4B,0x03,0x01,0xA8,0xF9,0x59,0xF5,0xA4,0x93,0xED,
0xF5,0x96,0x6F,0x68,0xD9,0x86,0xE6,0xD8,0x4B,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x4D,0x45,0xA9,0xAC,0x6C,0x64,0x20,0x3C,0x62,0x63,0x2C,0x64,0x65,0x3E,0x2C,
0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x2A,0x03,0x01,0x00,0x63,0x98,0x30,0x78,0x77,0x20,0xFE,
0xB1,0xFA,0xB9,0xB8,0xAB,0x04,0x06,0x15,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x5F,0x97,0x24,0x87,0x6C,0x64,0x20,0x68,0x6C,0x2C,0x28,0x6E,0x6E,0x6E,0x6E,
0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0x7B,0x03,0x01,0xFC,0x8D,0xD7,0x57,0x61,0x21,0x18,
0xCA,0x85,0xC1,0xDA,0x27,0x83,0x1E,0x60,0xF4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7A,0xCE,0xA1,0x1B,0x6C,0x64,0x20,0x73,0x70,0x2C,0x28,0x6E,0x6E,0x6E,0x6E,
0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x2A,0x03,0x01,0xD7,0xDE,0xFA,0xA6,0x80,0xF7,0x4C,
0x24,0xDE,0x87,0xC2,0xBC,0x16,0x63,0x96,0x4C,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x85,0x8B,0xF1,0x6D,0x6C,0x64,0x20,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,0x2C,
0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0x43,0x03,0x01,0x98,0x1F,0x4D,0x84,0xAC,0xE8,0xED,
0xC9,0x5D,0xC9,0x61,0x8F,0x80,0x3F,0xBF,0xC7,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,
0x00,0x64,0x1E,0x87,0x15,0x6C,0x64,0x20,0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2C,0x3C,
0x62,0x63,0x2C,0x64,0x65,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x22,0x03,0x01,0x00,0x03,0xD0,0x72,0x77,0x53,0x7F,0x72,
0x3F,0xEA,0x64,0x80,0xE1,0x10,0x2D,0xE9,0x35,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xA3,0x60,0x8B,0x47,0x6C,0x64,0x20,0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2C,0x68,
0x6C,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0x73,0x03,0x01,0xDC,0xC0,0xD6,0xD1,0x5A,0xED,0x56,
0xF3,0xDA,0xAF,0xA7,0x6C,0x44,0x9F,0x0A,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0xFF,0x16,0x58,0x5F,0xD7,0x6C,0x64,0x20,0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2C,0x73,
0x70,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x22,0x03,0x01,0xC3,0x6C,0x91,0x0D,0x00,0x69,0xF8,
0x8E,0xD6,0xE3,0xF7,0xC3,0xC6,0xD9,0xDF,0xC2,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xBA,0x10,0x2A,0x6B,0x6C,0x64,0x20,0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2C,0x3C,
0x69,0x78,0x2C,0x69,0x79,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x01,0x00,0x00,0x00,0x1C,0x5C,0x46,0x2D,0xB9,0x8E,0x78,
0x60,0xB1,0x74,0x0E,0xB3,0x46,0xD1,0xCC,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xDE,0x39,0x19,0x69,0x6C,0x64,0x20,0x3C,0x62,0x63,0x2C,0x64,0x65,0x2C,0x68,
0x6C,0x2C,0x73,0x70,0x3E,0x2C,0x6E,0x6E,0x6E,0x6E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x21,0x00,0x00,0xE8,0x87,0x06,0x20,0x12,0xBD,0x9B,
0xB6,0x53,0x72,0xE5,0xA1,0x51,0x13,0xBD,0xF1,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x22,0x7D,0xD5,0x25,0x6C,0x64,0x20,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,0x2C,
0x6E,0x6E,0x6E,0x6E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x0A,0x00,0x00,0x00,0xA8,0xB3,0x2A,0x1D,0x8E,0x7F,0xAC,
0x42,0x03,0x01,0x03,0x01,0xC6,0xB1,0x8E,0xEF,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xFF,0x00,
0x00,0xB0,0x81,0x89,0x35,0x6C,0x64,0x20,0x61,0x2C,0x3C,0x28,0x62,0x63,0x29,0x2C,
0x28,0x64,0x65,0x29,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x06,0x00,0x00,0x00,0x07,0xC4,0x9D,0xF4,0x3D,0xD1,0x39,
0x03,0x89,0xDE,0x55,0x74,0x53,0xC0,0x09,0x55,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0xF1,0xDA,0xB5,0x56,0x6C,0x64,0x20,0x3C,0x62,0x2C,0x63,0x2C,0x64,0x2C,0x65,
0x2C,0x68,0x2C,0x6C,0x2C,0x28,0x68,0x6C,0x29,0x2C,0x61,0x3E,0x2C,0x6E,0x6E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x36,0x01,0x00,0x45,0x1B,0x02,0x01,0x02,0x01,0xC1,
0xD5,0xC7,0x61,0xC4,0xBD,0xC0,0x85,0x16,0xCD,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0x26,0xDB,0x47,0x7E,0x6C,0x64,0x20,0x28,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,
0x2B,0x31,0x29,0x2C,0x6E,0x6E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x46,0x01,0x00,0x16,0xD0,0x02,0x01,0x02,0x01,0x60,
0x42,0x39,0x7F,0x04,0x04,0x97,0x4A,0x85,0xD0,0x20,0x18,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xCC,0x11,0x06,0xA8,0x6C,0x64,0x20,0x3C,0x62,0x2C,0x63,0x2C,0x64,0x2C,0x65,
0x3E,0x2C,0x28,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x66,0x01,0x00,0xE0,0x84,0x02,0x01,0x02,0x01,0x52,
0x9C,0x99,0xA7,0xB6,0x49,0x93,0x00,0xAD,0xEE,0x20,0x08,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFA,0x2A,0x4D,0x03,0x6C,0x64,0x20,0x3C,0x68,0x2C,0x6C,0x3E,0x2C,0x28,0x3C,
0x69,0x78,0x2C,0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x7E,0x01,0x00,0xB6,0xD8,0x02,0x01,0x02,0x01,0x12,
0xC6,0x07,0xDF,0xD0,0x9C,0x43,0xA6,0xE5,0xA0,0x20,0x00,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xA5,0xE9,0xAC,0x64,0x6C,0x64,0x20,0x61,0x2C,0x28,0x3C,0x69,0x78,0x2C,0x69,
0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x26,0x00,0x00,0x53,0x3C,0x40,0x46,0x79,0xE1,0x11,
0x77,0x07,0xC1,0xFA,0x1A,0x81,0xAD,0x9B,0x5D,0x20,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0x24,0xE8,0x82,0x8B,0x6C,0x64,0x20,0x3C,0x69,0x78,0x68,0x2C,0x69,0x78,0x6C,
0x2C,0x69,0x79,0x68,0x2C,0x69,0x79,0x6C,0x3E,0x2C,0x6E,0x6E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x40,0x00,0x00,0x00,0xA4,0x72,0x24,0xA0,0xAC,0x61,0x03,
0x01,0xC7,0x82,0x8F,0x71,0x97,0x8F,0x8E,0xEF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0xFF,0x00,
0x00,0x74,0x4B,0x01,0x18,0x6C,0x64,0x20,0x3C,0x62,0x63,0x64,0x65,0x68,0x6C,0x61,
0x3E,0x2C,0x3C,0x62,0x63,0x64,0x65,0x68,0x6C,0x61,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x40,0x00,0x00,0xC5,0xBC,0x03,0x01,0x03,0x01,0x03,
0x01,0xC2,0x2F,0xC0,0x98,0x83,0x1F,0xCD,0x3B,0x20,0x3F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0xFF,0x00,
0x00,0x47,0x8B,0xA3,0x6B,0x6C,0x64,0x20,0x3C,0x62,0x63,0x64,0x65,0x78,0x79,0x61,
0x3E,0x2C,0x3C,0x62,0x63,0x64,0x65,0x78,0x79,0x61,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x32,0x03,0x01,0x00,0x68,0xFD,0xEC,0xF4,0xA0,0x44,0x43,
0xB5,0x53,0x06,0xBA,0xCD,0xD2,0x4F,0xD8,0x1F,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xFF,0x00,
0x00,0xC9,0x26,0x2D,0xE5,0x6C,0x64,0x20,0x61,0x2C,0x28,0x6E,0x6E,0x6E,0x6E,0x29,
0x20,0x2F,0x20,0x6C,0x64,0x20,0x28,0x6E,0x6E,0x6E,0x6E,0x29,0x2C,0x61,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0xA8,0x00,0x00,0x52,0x98,0xFA,0x68,0xA1,0x66,0x06,
0x01,0x04,0x01,0x01,0x00,0xC1,0x68,0xB7,0x20,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x94,0xF4,0x27,0x69,0x6C,0x64,0x64,0x3C,0x72,0x3E,0x20,0x28,0x31,0x29,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0xA8,0x00,0x00,0x2E,0xF1,0x2A,0xEB,0xBA,0xD5,0x06,
0x01,0x04,0x01,0x02,0x00,0x47,0xFF,0xE4,0xFB,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x39,0xDD,0x3D,0xE1,0x6C,0x64,0x64,0x3C,0x72,0x3E,0x20,0x28,0x32,0x29,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0xA0,0x00,0x00,0x30,0xFE,0xCD,0x03,0x58,0x60,0x05,
0x01,0x03,0x01,0x01,0x00,0x04,0x60,0x88,0x26,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xF7,0x82,0xB0,0xD1,0x6C,0x64,0x69,0x3C,0x72,0x3E,0x20,0x28,0x31,0x29,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0xA0,0x00,0x00,0xCE,0x4A,0x6E,0xC2,0x88,0xB1,0x05,
0x01,0x03,0x01,0x02,0x00,0x14,0x2D,0x9F,0xA3,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xE9,0xEA,0xD0,0xAE,0x6C,0x64,0x69,0x3C,0x72,0x3E,0x20,0x28,0x32,0x29,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0x44,0x00,0x00,0xA2,0x38,0x6B,0x5F,0x34,0xD9,0xE4,
0x57,0xD6,0xD2,0x42,0x46,0x43,0x5A,0xCC,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xD6,0x38,0xDD,0x6A,0x6E,0x65,0x67,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xED,0x67,0x00,0x00,0xCB,0x91,0x8B,0xC4,0x62,0xFA,0x03,
0x01,0x20,0xE7,0x79,0xB4,0x40,0x06,0xE2,0x8A,0x00,0x08,0x00,0x00,0xFF,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xFF,0x00,
0x00,0xFF,0x82,0x3E,0x77,0x3C,0x72,0x72,0x64,0x2C,0x72,0x6C,0x64,0x3E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x07,0x00,0x00,0x00,0x92,0xCB,0x43,0x6D,0x90,0x0A,0x84,
0xC2,0x53,0x0C,0x0E,0xF5,0x91,0xEB,0xFC,0x40,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0x9B,0xA3,0x80,0x7C,0x3C,0x72,0x6C,0x63,0x61,0x2C,0x72,0x72,0x63,0x61,0x2C,
0x72,0x6C,0x61,0x2C,0x72,0x72,0x61,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0xCB,0x01,0x06,0xAF,0xDD,0x02,0x01,0x02,0x01,0x3C,
0xFF,0xF6,0xDB,0xF4,0x94,0x82,0x80,0xD9,0x61,0x20,0x00,0x00,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x57,0x00,0x00,
0x00,0x71,0x00,0x34,0xCB,0x73,0x68,0x66,0x2F,0x72,0x6F,0x74,0x20,0x28,0x3C,0x69,
0x78,0x2C,0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xCB,0x00,0x00,0x00,0xEB,0xCC,0x4A,0x5D,0x07,0xE0,0x03,
0x01,0x95,0x13,0xEE,0x30,0x43,0x78,0xAD,0x3D,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x57,0xFF,0x00,
0x00,0xA4,0x25,0x58,0x33,0x73,0x68,0x66,0x2F,0x72,0x6F,0x74,0x20,0x3C,0x62,0x2C,
0x63,0x2C,0x64,0x2C,0x65,0x2C,0x68,0x2C,0x6C,0x2C,0x28,0x68,0x6C,0x29,0x2C,0x61,
0x3E,0x2E,0x2E,0x24,0xFF,0xCB,0x80,0x00,0x00,0xD5,0x2C,0xAB,0x97,0xFF,0x39,0x03,
0x01,0x4B,0xD1,0xB2,0x6A,0x53,0x27,0x38,0xB5,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xD7,0xFF,0x00,
0x00,0x8B,0x57,0xF0,0x08,0x3C,0x73,0x65,0x74,0x2C,0x72,0x65,0x73,0x3E,0x20,0x6E,
0x2C,0x3C,0x62,0x63,0x64,0x65,0x68,0x6C,0x28,0x68,0x6C,0x29,0x61,0x3E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0xCB,0x01,0x86,0x44,0xFB,0x02,0x01,0x02,0x01,0x09,
0xBA,0xBE,0x68,0xD8,0x32,0x10,0x5E,0x67,0xA8,0x20,0x00,0x00,0x78,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0x00,
0x00,0xCC,0x63,0xF9,0x8A,0x3C,0x73,0x65,0x74,0x2C,0x72,0x65,0x73,0x3E,0x20,0x6E,
0x2C,0x28,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,0x2B,0x31,0x29,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x70,0x01,0x00,0x0D,0x27,0x02,0x01,0x02,0x01,0x3A,
0xB7,0x7B,0x88,0xEE,0x99,0x86,0x70,0x07,0xCA,0x20,0x03,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,
0x00,0x04,0x62,0x6A,0xBF,0x6C,0x64,0x20,0x28,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,
0x2B,0x31,0x29,0x2C,0x3C,0x62,0x2C,0x63,0x2C,0x64,0x2C,0x65,0x3E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x74,0x01,0x00,0x64,0xB6,0x02,0x01,0x02,0x01,0xAC,
0xE8,0xF5,0xB5,0xFE,0xAA,0x12,0x10,0x66,0x95,0x20,0x01,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x6A,0x1A,0x88,0x31,0x6C,0x64,0x20,0x28,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,
0x2B,0x31,0x29,0x2C,0x3C,0x68,0x2C,0x6C,0x3E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0xDD,0x77,0x01,0x00,0xAF,0x67,0x02,0x01,0x02,0x01,0x13,
0x4F,0x44,0x06,0xD7,0xBC,0x50,0xAC,0xAF,0x5F,0x20,0x00,0x00,0x00,0x00,0x00,0x01,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0xCC,0xBE,0x5A,0x96,0x6C,0x64,0x20,0x28,0x3C,0x69,0x78,0x2C,0x69,0x79,0x3E,
0x2B,0x31,0x29,0x2C,0x61,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xFF,0x02,0x00,0x00,0x00,0x3B,0x0C,0x92,0xB5,0xFF,0x6C,0x9E,
0x95,0x03,0x01,0x04,0x01,0xC1,0x21,0xE7,0xBD,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0x7A,0x4C,0x11,0x4F,0x6C,0x64,0x20,0x28,0x3C,0x62,0x63,0x2C,0x64,0x65,0x3E,
0x29,0x2C,0x61,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,
0x2E,0x2E,0x2E,0x24,0xE5,0x7E,0x23,0x66,0x6F,0x7E,0x32,0x67,0x1D,0x23,0xE5,0x11,
0x14,0x00,0x19,0x11,0xDC,0x1C,0xCD,0x4B,0x1C,0xE1,0xE5,0x11,0x28,0x00,0x19,0x11,
0x04,0x1D,0xCD,0x4B,0x1C,0x21,0x04,0x1D,0x36,0x01,0xE1,0xE5,0x11,0x44,0x1D,0x01,
0x04,0x00,0xED,0xB0,0x11,0x03,0x01,0x01,0x10,0x00,0xED,0xB0,0x11,0x2C,0x00,0x19,
0xEB,0x0E,0x09,0xCD,0xD0,0x1D,0xCD,0x76,0x1E,0x3A,0x44,0x1D,0xFE,0x76,0xCA,0x40,
0x1B,0xE6,0xDF,0xFE,0xDD,0xC2,0x3D,0x1B,0x3A,0x45,0x1D,0xFE,0x76,0xC4,0x2C,0x1D,
0xCD,0x8B,0x1C,0xC4,0xAF,0x1C,0xE1,0xCA,0x7C,0x1B,0x11,0x3C,0x00,0x19,0xCD,0x37,
0x1E,0x11,0x0A,0x1E,0xCA,0x73,0x1B,0x11,0x11,0x1E,0x0E,0x09,0xCD,0xD0,0x1D,0xCD,
0x9B,0x1D,0x11,0x2C,0x1E,0x0E,0x09,0xCD,0xD0,0x1D,0x21,0x8A,0x1E,0xCD,0x9B,0x1D,
0x11,0x34,0x1E,0x0E,0x09,0xCD,0xD0,0x1D,0xE1,0x23,0x23,0xC9,0xE5,0x3E,0x01,0x32,
0xF2,0x1B,0x32,0x16,0x1C,0x21,0xDC,0x1C,0x22,0xF3,0x1B,0x21,0x04,0x1D,0x22,0x17,
0x1C,0x06,0x04,0xE1,0xE5,0x11,0x44,0x1D,0xCD,0xA6,0x1B,0x06,0x10,0x11,0x03,0x01,
0xCD,0xA6,0x1B,0xC3,0x29,0x1B,0xCD,0xAF,0x1B,0x23,0x05,0xC2,0xA6,0x1B,0xC9,0xC5,
0xD5,0xE5,0x4E,0x11,0x14,0x00,0x19,0x7E,0xFE,0x00,0xCA,0xD0,0x1B,0x06,0x08,0x0F,
0xF5,0x3E,0x00,0xDC,0xF5,0x1B,0xA9,0x0F,0x4F,0xF1,0x05,0xC2,0xBF,0x1B,0x06,0x08,
0x11,0x14,0x00,0x19,0x7E,0xFE,0x00,0xCA,0xEB,0x1B,0x06,0x08,0x0F,0xF5,0x3E,0x00,
0xDC,0x19,0x1C,0xA9,0x0F,0x4F,0xF1,0x05,0xC2,0xDC,0x1B,0xE1,0xD1,0x79,0x12,0x13,
0xC1,0xC9,0x00,0x00,0x00,0xC5,0xE5,0x2A,0xF3,0x1B,0x46,0x21,0xF2,0x1B,0x7E,0x4F,
0x07,0x77,0xFE,0x01,0xC2,0x0E,0x1C,0x2A,0xF3,0x1B,0x23,0x22,0xF3,0x1B,0x78,0xA1,
0xE1,0xC1,0xC8,0x3E,0x01,0xC9,0x00,0x00,0x00,0xC5,0xE5,0x2A,0x17,0x1C,0x46,0x21,
0x16,0x1C,0x7E,0x4F,0x07,0x77,0xFE,0x01,0xC2,0x32,0x1C,0x2A,0x17,0x1C,0x23,0x22,
0x17,0x1C,0x78,0xA1,0xE1,0xC1,0xC8,0x3E,0x01,0xC9,0xF5,0xC5,0xD5,0xE5,0x36,0x00,
0x54,0x5D,0x13,0x0B,0xED,0xB0,0xE1,0xD1,0xC1,0xF1,0xC9,0xD5,0xEB,0x01,0x28,0x00,
0xCD,0x3A,0x1C,0xEB,0x06,0x14,0x0E,0x01,0x16,0x00,0x5E,0x7B,0xA1,0xCA,0x61,0x1C,
0x14,0x79,0x07,0x4F,0xFE,0x01,0xC2,0x5B,0x1C,0x23,0x05,0xC2,0x5A,0x1C,0x7A,0xE6,
0xF8,0x0F,0x0F,0x0F,0x6F,0x26,0x00,0x7A,0xE6,0x07,0x3C,0x47,0x3E,0x80,0x07,0x05,
0xC2,0x7E,0x1C,0xD1,0x19,0x11,0x14,0x00,0x19,0x77,0xC9,0xC5,0xD5,0xE5,0x21,0xDC,
0x1C,0x11,0x14,0x00,0xEB,0x19,0xEB,0x34,0x7E,0xFE,0x00,0xCA,0xAA,0x1C,0x47,0x1A,
0xA0,0xCA,0xA6,0x1C,0x36,0x00,0xC1,0xD1,0xE1,0xC9,0x23,0x13,0xC3,0x97,0x1C,0xC5,
0xD5,0xE5,0x21,0x04,0x1D,0x11,0x14,0x00,0xEB,0x19,0xEB,0x7E,0xB7,0xCA,0xD7,0x1C,
0x47,0x1A,0xA0,0xC2,0xD3,0x1C,0x78,0x07,0xFE,0x01,0xC2,0xD1,0x1C,0x36,0x00,0x23,
0x13,0x77,0xAF,0xE1,0xD1,0xC1,0xC9,0x23,0x13,0xC3,0xBB,0x1C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF5,0xC5,0xD5,0xE5,
0xF3,0xED,0x73,0x8F,0x1D,0x31,0x05,0x01,0xFD,0xE1,0xDD,0xE1,0xE1,0xD1,0xC1,0xF1,
0xED,0x7B,0x11,0x01,0x00,0x00,0x00,0x00,0xED,0x73,0x8D,0x1D,0x31,0x8D,0x1D,0xF5,
0xC5,0xD5,0xE5,0xDD,0xE5,0xFD,0xE5,0xED,0x7B,0x8F,0x1D,0xFB,0x2A,0x03,0x01,0x22,
0x7F,0x1D,0x21,0x8B,0x1D,0x7E,0xE6,0xD7,0x77,0x06,0x10,0x11,0x7F,0x1D,0x21,0x8A,
0x1E,0x1A,0x13,0xCD,0x4E,0x1E,0x05,0xC2,0x71,0x1D,0xE1,0xD1,0xC1,0xF1,0xC9,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7E,0xCD,0xAD,0x1D,0x23,0x05,0xC2,0x91,0x1D,0xC9,0xF5,0xC5,0xE5,0x06,0x04,
0x7E,0xCD,0xAD,0x1D,0x23,0x05,0xC2,0xA0,0x1D,0xE1,0xC1,0xF1,0xC9,0xF5,0x0F,0x0F,
0x0F,0x0F,0xCD,0xB6,0x1D,0xF1,0xF5,0xC5,0xD5,0xE5,0xE6,0x0F,0xFE,0x0A,0xDA,0xC3,
0x1D,0xC6,0x27,0xC6,0x30,0x5F,0x0E,0x02,0xCD,0xD0,0x1D,0xE1,0xD1,0xC1,0xF1,0xC9,
0xF5,0xC5,0xD5,0xE5,0xCD,0x05,0x00,0xE1,0xD1,0xC1,0xF1,0xC9,0x5A,0x38,0x30,0x61,
0x6C,0x6C,0x20,0x69,0x6E,0x73,0x74,0x72,0x75,0x63,0x74,0x69,0x6F,0x6E,0x20,0x65,
0x78,0x65,0x72,0x63,0x69,0x73,0x65,0x72,0x0A,0x0D,0x24,0x54,0x65,0x73,0x74,0x73,
0x20,0x63,0x6F,0x6D,0x70,0x6C,0x65,0x74,0x65,0x24,0x20,0x20,0x4F,0x4B,0x0A,0x0D,
0x24,0x20,0x20,0x45,0x52,0x52,0x4F,0x52,0x20,0x2A,0x2A,0x2A,0x2A,0x20,0x63,0x72,
0x63,0x20,0x65,0x78,0x70,0x65,0x63,0x74,0x65,0x64,0x3A,0x24,0x20,0x66,0x6F,0x75,
0x6E,0x64,0x3A,0x24,0x0A,0x0D,0x24,0xC5,0xD5,0xE5,0x11,0x8A,0x1E,0x06,0x04,0x1A,
0xBE,0xC2,0x4A,0x1E,0x23,0x13,0x05,0xC2,0x3F,0x1E,0xE1,0xD1,0xC1,0xC9,0xF5,0xC5,
0xD5,0xE5,0xE5,0x11,0x03,0x00,0x19,0xAE,0x6F,0x26,0x00,0x29,0x29,0xEB,0x21,0x8E,
0x1E,0x19,0xEB,0xE1,0x01,0x04,0x00,0x1A,0xA8,0x46,0x77,0x13,0x23,0x0D,0xC2,0x67,
0x1E,0xE1,0xD1,0xC1,0xF1,0xC9,0xF5,0xC5,0xE5,0x21,0x8A,0x1E,0x3E,0xFF,0x06,0x04,
0x77,0x23,0x05,0xC2,0x80,0x1E,0xE1,0xC1,0xF1,0xC9,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x77,0x07,0x30,0x96,0xEE,0x0E,0x61,0x2C,0x99,0x09,0x51,0xBA,0x07,0x6D,
0xC4,0x19,0x70,0x6A,0xF4,0x8F,0xE9,0x63,0xA5,0x35,0x9E,0x64,0x95,0xA3,0x0E,0xDB,
0x88,0x32,0x79,0xDC,0xB8,0xA4,0xE0,0xD5,0xE9,0x1E,0x97,0xD2,0xD9,0x88,0x09,0xB6,
0x4C,0x2B,0x7E,0xB1,0x7C,0xBD,0xE7,0xB8,0x2D,0x07,0x90,0xBF,0x1D,0x91,0x1D,0xB7,
0x10,0x64,0x6A,0xB0,0x20,0xF2,0xF3,0xB9,0x71,0x48,0x84,0xBE,0x41,0xDE,0x1A,0xDA,
0xD4,0x7D,0x6D,0xDD,0xE4,0xEB,0xF4,0xD4,0xB5,0x51,0x83,0xD3,0x85,0xC7,0x13,0x6C,
0x98,0x56,0x64,0x6B,0xA8,0xC0,0xFD,0x62,0xF9,0x7A,0x8A,0x65,0xC9,0xEC,0x14,0x01,
0x5C,0x4F,0x63,0x06,0x6C,0xD9,0xFA,0x0F,0x3D,0x63,0x8D,0x08,0x0D,0xF5,0x3B,0x6E,
0x20,0xC8,0x4C,0x69,0x10,0x5E,0xD5,0x60,0x41,0xE4,0xA2,0x67,0x71,0x72,0x3C,0x03,
0xE4,0xD1,0x4B,0x04,0xD4,0x47,0xD2,0x0D,0x85,0xFD,0xA5,0x0A,0xB5,0x6B,0x35,0xB5,
0xA8,0xFA,0x42,0xB2,0x98,0x6C,0xDB,0xBB,0xC9,0xD6,0xAC,0xBC,0xF9,0x40,0x32,0xD8,
0x6C,0xE3,0x45,0xDF,0x5C,0x75,0xDC,0xD6,0x0D,0xCF,0xAB,0xD1,0x3D,0x59,0x26,0xD9,
0x30,0xAC,0x51,0xDE,0x00,0x3A,0xC8,0xD7,0x51,0x80,0xBF,0xD0,0x61,0x16,0x21,0xB4,
0xF4,0xB5,0x56,0xB3,0xC4,0x23,0xCF,0xBA,0x95,0x99,0xB8,0xBD,0xA5,0x0F,0x28,0x02,
0xB8,0x9E,0x5F,0x05,0x88,0x08,0xC6,0x0C,0xD9,0xB2,0xB1,0x0B,0xE9,0x24,0x2F,0x6F,
0x7C,0x87,0x58,0x68,0x4C,0x11,0xC1,0x61,0x1D,0xAB,0xB6,0x66,0x2D,0x3D,0x76,0xDC,
0x41,0x90,0x01,0xDB,0x71,0x06,0x98,0xD2,0x20,0xBC,0xEF,0xD5,0x10,0x2A,0x71,0xB1,
0x85,0x89,0x06,0xB6,0xB5,0x1F,0x9F,0xBF,0xE4,0xA5,0xE8,0xB8,0xD4,0x33,0x78,0x07,
0xC9,0xA2,0x0F,0x00,0xF9,0x34,0x96,0x09,0xA8,0x8E,0xE1,0x0E,0x98,0x18,0x7F,0x6A,
0x0D,0xBB,0x08,0x6D,0x3D,0x2D,0x91,0x64,0x6C,0x97,0xE6,0x63,0x5C,0x01,0x6B,0x6B,
0x51,0xF4,0x1C,0x6C,0x61,0x62,0x85,0x65,0x30,0xD8,0xF2,0x62,0x00,0x4E,0x6C,0x06,
0x95,0xED,0x1B,0x01,0xA5,0x7B,0x82,0x08,0xF4,0xC1,0xF5,0x0F,0xC4,0x57,0x65,0xB0,
0xD9,0xC6,0x12,0xB7,0xE9,0x50,0x8B,0xBE,0xB8,0xEA,0xFC,0xB9,0x88,0x7C,0x62,0xDD,
0x1D,0xDF,0x15,0xDA,0x2D,0x49,0x8C,0xD3,0x7C,0xF3,0xFB,0xD4,0x4C,0x65,0x4D,0xB2,
0x61,0x58,0x3A,0xB5,0x51,0xCE,0xA3,0xBC,0x00,0x74,0xD4,0xBB,0x30,0xE2,0x4A,0xDF,
0xA5,0x41,0x3D,0xD8,0x95,0xD7,0xA4,0xD1,0xC4,0x6D,0xD3,0xD6,0xF4,0xFB,0x43,0x69,
0xE9,0x6A,0x34,0x6E,0xD9,0xFC,0xAD,0x67,0x88,0x46,0xDA,0x60,0xB8,0xD0,0x44,0x04,
0x2D,0x73,0x33,0x03,0x1D,0xE5,0xAA,0x0A,0x4C,0x5F,0xDD,0x0D,0x7C,0xC9,0x50,0x05,
0x71,0x3C,0x27,0x02,0x41,0xAA,0xBE,0x0B,0x10,0x10,0xC9,0x0C,0x20,0x86,0x57,0x68,
0xB5,0x25,0x20,0x6F,0x85,0xB3,0xB9,0x66,0xD4,0x09,0xCE,0x61,0xE4,0x9F,0x5E,0xDE,
0xF9,0x0E,0x29,0xD9,0xC9,0x98,0xB0,0xD0,0x98,0x22,0xC7,0xD7,0xA8,0xB4,0x59,0xB3,
0x3D,0x17,0x2E,0xB4,0x0D,0x81,0xB7,0xBD,0x5C,0x3B,0xC0,0xBA,0x6C,0xAD,0xED,0xB8,
0x83,0x20,0x9A,0xBF,0xB3,0xB6,0x03,0xB6,0xE2,0x0C,0x74,0xB1,0xD2,0x9A,0xEA,0xD5,
0x47,0x39,0x9D,0xD2,0x77,0xAF,0x04,0xDB,0x26,0x15,0x73,0xDC,0x16,0x83,0xE3,0x63,
0x0B,0x12,0x94,0x64,0x3B,0x84,0x0D,0x6D,0x6A,0x3E,0x7A,0x6A,0x5A,0xA8,0xE4,0x0E,
0xCF,0x0B,0x93,0x09,0xFF,0x9D,0x0A,0x00,0xAE,0x27,0x7D,0x07,0x9E,0xB1,0xF0,0x0F,
0x93,0x44,0x87,0x08,0xA3,0xD2,0x1E,0x01,0xF2,0x68,0x69,0x06,0xC2,0xFE,0xF7,0x62,
0x57,0x5D,0x80,0x65,0x67,0xCB,0x19,0x6C,0x36,0x71,0x6E,0x6B,0x06,0xE7,0xFE,0xD4,
0x1B,0x76,0x89,0xD3,0x2B,0xE0,0x10,0xDA,0x7A,0x5A,0x67,0xDD,0x4A,0xCC,0xF9,0xB9,
0xDF,0x6F,0x8E,0xBE,0xEF,0xF9,0x17,0xB7,0xBE,0x43,0x60,0xB0,0x8E,0xD5,0xD6,0xD6,
0xA3,0xE8,0xA1,0xD1,0x93,0x7E,0x38,0xD8,0xC2,0xC4,0x4F,0xDF,0xF2,0x52,0xD1,0xBB,
0x67,0xF1,0xA6,0xBC,0x57,0x67,0x3F,0xB5,0x06,0xDD,0x48,0xB2,0x36,0x4B,0xD8,0x0D,
0x2B,0xDA,0xAF,0x0A,0x1B,0x4C,0x36,0x03,0x4A,0xF6,0x41,0x04,0x7A,0x60,0xDF,0x60,
0xEF,0xC3,0xA8,0x67,0xDF,0x55,0x31,0x6E,0x8E,0xEF,0x46,0x69,0xBE,0x79,0xCB,0x61,
0xB3,0x8C,0xBC,0x66,0x83,0x1A,0x25,0x6F,0xD2,0xA0,0x52,0x68,0xE2,0x36,0xCC,0x0C,
0x77,0x95,0xBB,0x0B,0x47,0x03,0x22,0x02,0x16,0xB9,0x55,0x05,0x26,0x2F,0xC5,0xBA,
0x3B,0xBE,0xB2,0xBD,0x0B,0x28,0x2B,0xB4,0x5A,0x92,0x5C,0xB3,0x6A,0x04,0xC2,0xD7,
0xFF,0xA7,0xB5,0xD0,0xCF,0x31,0x2C,0xD9,0x9E,0x8B,0x5B,0xDE,0xAE,0x1D,0x9B,0x64,
0xC2,0xB0,0xEC,0x63,0xF2,0x26,0x75,0x6A,0xA3,0x9C,0x02,0x6D,0x93,0x0A,0x9C,0x09,
0x06,0xA9,0xEB,0x0E,0x36,0x3F,0x72,0x07,0x67,0x85,0x05,0x00,0x57,0x13,0x95,0xBF,
0x4A,0x82,0xE2,0xB8,0x7A,0x14,0x7B,0xB1,0x2B,0xAE,0x0C,0xB6,0x1B,0x38,0x92,0xD2,
0x8E,0x9B,0xE5,0xD5,0xBE,0x0D,0x7C,0xDC,0xEF,0xB7,0x0B,0xDB,0xDF,0x21,0x86,0xD3,
0xD2,0xD4,0xF1,0xD4,0xE2,0x42,0x68,0xDD,0xB3,0xF8,0x1F,0xDA,0x83,0x6E,0x81,0xBE,
0x16,0xCD,0xF6,0xB9,0x26,0x5B,0x6F,0xB0,0x77,0xE1,0x18,0xB7,0x47,0x77,0x88,0x08,
0x5A,0xE6,0xFF,0x0F,0x6A,0x70,0x66,0x06,0x3B,0xCA,0x11,0x01,0x0B,0x5C,0x8F,0x65,
0x9E,0xFF,0xF8,0x62,0xAE,0x69,0x61,0x6B,0xFF,0xD3,0x16,0x6C,0xCF,0x45,0xA0,0x0A,
0xE2,0x78,0xD7,0x0D,0xD2,0xEE,0x4E,0x04,0x83,0x54,0x39,0x03,0xB3,0xC2,0xA7,0x67,
0x26,0x61,0xD0,0x60,0x16,0xF7,0x49,0x69,0x47,0x4D,0x3E,0x6E,0x77,0xDB,0xAE,0xD1,
0x6A,0x4A,0xD9,0xD6,0x5A,0xDC,0x40,0xDF,0x0B,0x66,0x37,0xD8,0x3B,0xF0,0xA9,0xBC,
0xAE,0x53,0xDE,0xBB,0x9E,0xC5,0x47,0xB2,0xCF,0x7F,0x30,0xB5,0xFF,0xE9,0xBD,0xBD,
0xF2,0x1C,0xCA,0xBA,0xC2,0x8A,0x53,0xB3,0x93,0x30,0x24,0xB4,0xA3,0xA6,0xBA,0xD0,
0x36,0x05,0xCD,0xD7,0x06,0x93,0x54,0xDE,0x57,0x29,0x23,0xD9,0x67,0xBF,0xB3,0x66,
0x7A,0x2E,0xC4,0x61,0x4A,0xB8,0x5D,0x68,0x1B,0x02,0x2A,0x6F,0x2B,0x94,0xB4,0x0B,
0xBE,0x37,0xC3,0x0C,0x8E,0xA1,0x5A,0x05,0xDF,0x1B,0x2D,0x02,0xEF,0x8D
};

//ZXALLBIN_H END








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
#ifdef cfg_use_test_fps_48k
 unsigned char fetchOpcode(unsigned short int address)
 {
  tstates += 4;
  return z80Ram[address];
 }
#else
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
#endif

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

 
 #ifdef cfg_use_test_fps_48k
  unsigned int cur_fps=0;
  unsigned int time_end;
  unsigned int gb_min_frame;
  unsigned int gb_max_frame;
  unsigned int gb_cur_frame;  
  unsigned int aux_time_frame_ini;
  unsigned int ini_time_one_second= clock();
   
  while ((clock()-ini_time_one_second)<1000)
  {  
   gb_min_frame=10000;
   gb_max_frame=0;
   gb_cur_frame=0;
   aux_time_frame_ini;
   tstates = 0;
   time_end= tstates + 69887;
   aux_time_frame_ini=clock();
   while (tstates <= time_end)
   {
    execute();
   }   
   gb_cur_frame= (clock()- aux_time_frame_ini);
   if (gb_cur_frame < gb_min_frame)
    gb_min_frame= gb_cur_frame;
   if (gb_cur_frame > gb_max_frame)   
    gb_max_frame= gb_cur_frame;
   cur_fps++; 
  }
  printf("fps(%d) - ms cur(%d) min(%d) max(%d)\n",cur_fps,gb_cur_frame,gb_min_frame,gb_max_frame);
 #else
  while (!finish)
  {
   execute();
  } 
 #endif
}


//********
//* MAIN *
//********
int main(int argc, char *argv[])
{
 #ifdef cfg_use_test_fps_48k
  printf("CLOCKS_PER_SEC %d\n",CLOCKS_PER_SEC);
  while (!finish)
  {
   runTest();        
  }    
 #else     
  #if defined(cfg_use_time_show) && !defined(cfg_use_time_per_line)
   ShowTime();
   runTest();
   ShowTime();
  #else
   runTest();   
  #endif
 #endif 
 return 0;
}