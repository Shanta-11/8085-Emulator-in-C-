SET 2010,05
LXI H,2010
MOV B,M
MVI A,00
MOV D,B
DCR B
JZ 101B
MOV E,B
ADD D
DCR E
JNZ 100F
MOV D,A
MVI A,00
DCR B
JMP 100B
MOV A,D
STA 2011
HLT