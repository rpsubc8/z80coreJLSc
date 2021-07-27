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
Se puede ver la velocidad en un ESP32, de 1 hora y 25 minutos de ejecución con las opciones por defecto.<br>
Si se seleccionan varias opciones de optimización, nos queda en (01:24:58).<br>


<br><br>
<h1>ESP32 fps</h1>
Si activamos el pragma <b>cfg_use_test_fps_48k</b> en el <b>gbConfig.h</b> podremos medir los fps (cuadros por segundo), así como el tiempo en milisegundos cur (actual), min (mínimo) y max (máximo) para completar un frame en el ZX Spectrum 48K (69887 t-states).

<pre>
16:35:48.682 -> fps(135) - ms cur(7) min(7) max(7)
16:35:49.698 -> fps(135) - ms cur(7) min(7) max(7)
16:35:50.713 -> fps(135) - ms cur(7) min(7) max(7)
16:35:51.690 -> fps(135) - ms cur(8) min(8) max(8)
16:35:52.706 -> fps(135) - ms cur(8) min(8) max(8)
16:35:53.721 -> fps(135) - ms cur(8) min(8) max(8)
16:35:54.698 -> fps(135) - ms cur(8) min(8) max(8)
16:35:55.713 -> fps(135) - ms cur(7) min(7) max(7)
</pre>
