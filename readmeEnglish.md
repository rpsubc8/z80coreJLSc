# Core Z80 in C
I have made a quick conversion of Jose Luis Sanchez's Z80 core to C (not POSIX).
The original C++ project is by Jose Luis Sanchez. I have only made a conversion to C, to serve as a template for other platforms and compilers with smaller resources.
 Serve as a template for other platforms and compilers with smaller resources.

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
