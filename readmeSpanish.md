# Core Z80 en C 
He realizado una conversión rápida del core del Z80 de Jose Luis Sánchez a C (no POSIX).
El proyecto original en C++ es de Jose Luis Sánchez. Yo tan sólo he realizado una conversión a C, para que
 sirva de plantilla en otras plataformas y compiladores de recursos más reducidos.

<h1>Proyecto original</h1>
<a href='https://github.com/jsanchezv/z80cpp'>z80cpp</a></li>

<br><br>
<h1>Archivos</h1>
Todo se puede dejar simplificado en 2 archivos (z80.c y z80.h), pero para realizar simulaciones, se ha dejado la siguiente estructura:
<ul>
 <li>z80.h</li>
 <li>z80.c</li>
 <li>sim.c (para simulación)</li>
 <li>zxallbin.h (el binario de test zxall)</li>
 <li>gbGlobal (variables globales de Z80 y de simulación)</li>
</ul>

<br><br>
<h1>Entorno</h1>
Está preparado para mingw32 (devcpp) de Windows, pero puede usarse gcc y Linux.


<br><br>
<h1>Plantilla</h1>
Tan sólo tenemos que definir el comportamiento de:

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



<br><br>
<h1>Test</h1>
Si lanzamos la simulación que simula la salida de consola de CPM, nos saldrá los tiempos de ejecución del test zxall:



