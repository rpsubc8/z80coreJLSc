# Core Z80 in C
I have made a quick conversion of Jose Luis Sanchez's Z80 core to C (not POSIX) in STD(C89) standard.
The original C++ project is by Jose Luis Sanchez. I have only made a conversion to C, to serve as a template for other platforms and compilers with smaller resources.
 Serve as a template for other platforms and compilers with smaller resources.<br>
This modified version only allows the use of a single Z80 core, instead of multiple ones, a feature that the original project had.

<br><br>
<h1>Original project</h1>
<a href='https://github.com/jsanchezv/z80cpp'>z80cpp</a></li>


<br><br>
<h1>Files</h1>
Everything can be left simplified in 2 files (z80.c and z80.h), but for simulations, the following structure has been left:
<ul>
 <li>z80.h</li>
 <li>z80.c</li>
 <li>sim.c (for simulation)</li>
 <li>zxallbin.h (the zxall test binary)</li>
 <li>gbGlobal (Z80 global and simulation variables)</li>
</ul>


<br><br>
<h1>Environment</h1>
It is prepared for Windows mingw32 (devcpp), but gcc can be used with Linux as well as embedded systems.

<br><br>
<h1>Template</h1>
We only have to define the behavior of:
<pre>
unsigned char fetchOpcode(unsigned short int address)
{
}

unsigned char peek8(unsigned short int address)
{
}

void poke8(unsigned short int address, unsigned char value)
{
}

unsigned short int peek16(unsigned short int address)
{   
}

void poke16(unsigned short int address, RegisterPair word)
{
}

void addressOnBus(unsigned short int address, int wstates)
{
}

unsigned char inPort(unsigned short int port)
{    
}

void outPort(unsigned short int port, unsigned char value)
{    
}

void interruptHandlingTime(int wstates)
{
}

unsigned char isActiveINT(void)
{
}
</pre>
We must take into account the <b>Start simulator</b> section of the <b>gbGlobal.h</b> file, because that is where we define the Z80 resources to emulate, i.e. RAM and ports.


<br><br>
<h1>Test</h1>
If we launch the simulation that simulates the CPM console output, we will get the execution times of the zxall test:
<center><img src='https://raw.githubusercontent.com/rpsubc8/z80coreJLSc/main/preview/previewzxall1.gif'></center>
When finished, if all goes well, it will look something like the following:
<center><img src='https://raw.githubusercontent.com/rpsubc8/z80coreJLSc/main/preview/previewzxall2.gif'></center>

<br><br>
<h1>Options</h1>
Several setting options are allowed in the gbConfig.h file:
<ul>
 <li><b>cfg_use_big_endian</b>: Big endian support</li>
 <li><b>WITH_BREAKPOINT_SUPPORT</b>: Allows debugging</li> 
 <li><b>cfg_use_time_show</b>: Displays the times</li>
 <li><b>cfg_use_time_per_line</b>: Displays the time in each execution line.</li>
 <li><b>cfg_use_tstates_64bits</b>: Declares the 64-bit timing variable.</li>
 <li><b>cfg_use_direct_RegA</b>: Quick access mode to a Z80 register.</li>
 <li>--</li>
 <li><b>cfg_use_direct_PendingEI</b>: Quick access mode to PendingEI.</li>
 <li><b>cfg_use_finish_fast</b>: Execution variable declared in fast mode (ESP32).</li>
 <li><b>cfg_use_z80RAM_fast</b>: The RAM array in fast mode (ESP32)</li>
 <li><b>cfg_use_z80Ports_fast</b>: The port array in fast mode (ESP32)</li>
 <li><b>cfg_use_time_fast</b>: Access to the timer in fast mode (ESP32)</li>
</ul>


<br><br>
<h1>ESP32</h1>
I have left a project for ESP32 (sourceESP32), for a quick test.<br>
The port memory has been left at 8192 bytes, which is good for testing purposes.<br>
The output is through the serial port, through which we can monitor.
<pre>
15:50:13.123 -> BEGIN Test
15:50:13.123 ->  (00:00:00) Z80all instruction exerciser
15:50:13.123 -> <adc,sbc> hl,<bc,de,hl,sp>....  OK
15:54:23.087 -> add hl,<bc,de,hl,sp>..........  OK
15:56:27.501 -> add ix,<bc,de,ix,sp>..........  OK
15:58:31.963 -> add iy,<bc,de,iy,sp>..........  OK
16:00:36.416 -> aluop a,nn....................  OK
16:01:39.342 -> aluop a,<b,c,d,e,h,l,(hl),a>..  OK
16:38:21.948 -> aluop a,<ixh,ixl,iyh,iyl>.....  OK
16:57:04.702 -> aluop a,(<ix,iy>+1)...........  OK
17:06:31.325 -> bit n,(<ix,iy>+1).............  OK
17:06:35.739 -> bit n,<b,c,d,e,h,l,(hl),a>....  OK
17:08:57.614 -> cpd<r>........................  OK
17:09:25.270 -> cpi<r>........................  OK
17:09:52.965 -> <daa,cpl,scf,ccf>.............  OK
17:11:54.128 -> <inc,dec> a...................  OK
17:12:00.667 -> <inc,dec> b...................  OK
17:12:07.207 -> <inc,dec> bc..................  OK
17:12:10.582 -> <inc,dec> c...................  OK
17:12:17.121 -> <inc,dec> d...................  OK
17:12:23.682 -> <inc,dec> de..................  OK
17:12:27.041 -> <inc,dec> e...................  OK
17:12:33.574 -> <inc,dec> h...................  OK
17:12:40.136 -> <inc,dec> hl..................  OK
17:12:43.496 -> <inc,dec> ix..................  OK
17:12:46.894 -> <inc,dec> iy..................  OK
17:12:50.253 -> <inc,dec> l...................  OK
17:12:56.777 -> <inc,dec> (hl)................  OK
17:13:03.339 -> <inc,dec> sp..................  OK
17:13:06.699 -> <inc,dec> (<ix,iy>+1).........  OK
17:13:20.410 -> <inc,dec> ixh.................  OK
17:13:26.972 -> <inc,dec> ixl.................  OK
17:13:33.496 -> <inc,dec> iyh.................  OK
17:13:40.058 -> <inc,dec> iyl.................  OK
17:13:46.621 -> ld <bc,de>,(nnnn).............  OK
17:13:46.660 -> ld hl,(nnnn)..................  OK
17:13:46.699 -> ld sp,(nnnn)..................  OK
17:13:46.738 -> ld <ix,iy>,(nnnn).............  OK
17:13:46.816 -> ld (nnnn),<bc,de>.............  OK
17:13:46.933 -> ld (nnnn),hl..................  OK
17:13:46.972 -> ld (nnnn),sp..................  OK
17:13:47.011 -> ld (nnnn),<ix,iy>.............  OK
17:13:47.167 -> ld <bc,de,hl,sp>,nnnn.........  OK
17:13:47.285 -> ld <ix,iy>,nnnn...............  OK
17:13:47.363 -> ld a,<(bc),(de)>..............  OK
17:13:47.441 -> ld <b,c,d,e,h,l,(hl),a>,nn....  OK
17:13:47.558 -> ld (<ix,iy>+1),nn.............  OK
17:13:47.636 -> ld <b,c,d,e>,(<ix,iy>+1)......  OK
17:13:48.808 -> ld <h,l>,(<ix,iy>+1)..........  OK
17:13:49.394 -> ld a,(<ix,iy>+1)..............  OK
17:13:49.667 -> ld <ixh,ixl,iyh,iyl>,nn.......  OK
17:13:49.707 -> ld <bcdehla>,<bcdehla>........  OK
17:13:59.707 -> ld <bcdexya>,<bcdexya>........  OK
17:14:20.292 -> ld a,(nnnn) / ld (nnnn),a.....  OK
17:14:20.371 -> ldd<r> (1)....................  OK
17:14:20.488 -> ldd<r> (2)....................  OK
17:14:20.566 -> ldi<r> (1)....................  OK
17:14:20.683 -> ldi<r> (2)....................  OK
17:14:20.761 -> neg...........................  OK
17:14:49.316 -> <rrd,rld>.....................  OK
17:15:04.824 -> <rlca,rrca,rla,rra>...........  OK
17:15:17.988 -> shf/rot (<ix,iy>+1)...........  OK
17:15:18.886 -> shf/rot <b,c,d,e,h,l,(hl),a>..  OK
17:15:39.121 -> <set,res> n,<bcdehl(hl)a>.....  OK
17:15:59.277 -> <set,res> n,(<ix,iy>+1).......  OK
17:16:00.214 -> ld (<ix,iy>+1),<b,c,d,e>......  OK
17:16:02.871 -> ld (<ix,iy>+1),<h,l>..........  OK
17:16:03.457 -> ld (<ix,iy>+1),a..............  OK
17:16:03.574 -> ld (<bc,de>),a................  OK
17:16:03.808 -> Tests completeZ80 reset after 3785304271 t-states
17:16:03.808 ->  (01:25:46) END Test
</pre>
You can see the speed in an ESP32, 1 hour and 15 minutes of execution.

