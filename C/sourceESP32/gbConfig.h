#ifndef _GB_GBCONFIG_H
 #define _GB_GBCONFIG_H

//Timer options
#define cfg_use_time_show
//#define cfg_use_time_per_line
//64 bits (slow) vs 32 bits (fast)
//#define cfg_use_tstates_64bits

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

//Options simulator
#define cfg_use_finish_fast
#define cfg_use_z80RAM_fast
#define cfg_use_z80Ports_fast
#define cfg_use_time_fast
//#define cfg_use_test_fps_48k

#endif
