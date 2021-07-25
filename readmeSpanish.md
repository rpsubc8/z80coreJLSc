# Core Z80 en C 
He realizado una conversión rápida del core del Z80 de José Luis Sánchez a C (no POSIX) en normativa STD(C89).
El proyecto original en C++ es de Jose Luis Sánchez. Yo tan sólo he realizado una conversión a C, para que
 sirva de plantilla en otras plataformas y compiladores de recursos más reducidos.<br>
Esta versión modificada sólo permite usar un único core de Z80, en lugar de múltiples, característica que si tenía el proyecto original.

<br><br>
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
Está preparado para mingw32 (devcpp) de Windows, pero puede usarse gcc con Linux, así como sistemas embebidos.


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
Debemos tener en cuenta la sección de <b>Inicio simulador</b> del fichero <b>gbGlobal.h</b>, porque ahi es donde definimos los recursos del Z80 a emular, es decir, RAM y puertos.



<br><br>
<h1>Test</h1>
Si lanzamos la simulación que simula la salida de consola de CPM, nos saldrá los tiempos de ejecución del test zxall:
<center><img src='https://raw.githubusercontent.com/rpsubc8/z80coreJLSc/main/preview/previewzxall1.gif'></center>
Cuando termine, si todo va bien, saldrá algo como lo siguiente:
<center><img src='https://raw.githubusercontent.com/rpsubc8/z80coreJLSc/main/preview/previewzxall2.gif'></center>


<br><br>
<h1>Opciones</h1>
Se permiten varias opciones de ajustes en el fichero gbConfig.h:
<ul>
 <li><b>cfg_use_big_endian</b>: Soporte de Big endian</li>
 <li><b>WITH_BREAKPOINT_SUPPORT</b>: Permite depuración</li>
 <li><b>cfg_use_time_show</b>: Muestra los tiempos</li>
 <li><b>cfg_use_time_per_line</b>: Muestra el tiempo en cada linea de ejecución.</li>
 <li><b>cfg_use_tstates_64bits</b>: Declara la variable de temporización de 64 bits.</li>
 <li><b>cfg_use_direct_RegA</b>: Modo de acceso rápido a un registro del Z80.</li>
 <li>--</li>
 <li><b>cfg_use_direct_PendingEI</b>: Modo de acceso rápido a PendingEI.</li>
 <li><b>cfg_use_finish_fast</b>: Variable de ejecución declarada en modo rápido (ESP32).</li>
 <li><b>cfg_use_z80RAM_fast</b>: El array de RAM en modo rápido (ESP32)</li>
 <li><b>cfg_use_z80Ports_fast</b>: El array de puertos en modo rápido (ESP32)</li>
 <li><b>cfg_use_time_fast</b>: El acceso al timer en modo rápido (ESP32)</li>
</ul>



<br><br>
<h1>ESP32</h1>
He dejado un proyecto para ESP32 (sourceESP32), para realizar un test rápido.<br>
La memoria de puertos se ha dejado en 8192 bytes, que nos vale para los tests.<br>
La salida se realiza por el puerto serie, por donde podemos monitorizar.
