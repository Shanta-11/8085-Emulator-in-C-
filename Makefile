IDIR = ./header
CC = g++
CFLAGS=-I$(IDIR)

ODIR=object
LDIR=./src

LIBS=-lm

_DEPS = MASTER.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  validityAddress.o LDA.o complement.o decimalToHex.o hexToDecimal.o hexAdd.o hexAdd16bit.o hexSub.o hexSub16bit.o increaseAddress.o operationSize.o registerNumber.o validityFile.o LHLD.o LXI.o MOV.o MVI.o SET.o SHLD.o STA.o STAX.o XCHG.o CMA.o CMP.o JC.o JMP.o JNC.o JNZ.o JZ.o ADD.o ADI.o DAD.o DCR.o DCX.o INR.o INX.o SUB.o SUI.o ANA.o ANI.o CALL.o CC.o CM.o CMC.o CNC.o CNZ.o CP.o CPE.o CPI.o CPO.o CZ.o JM.o JP.o JPE.o JPO.o ORA.o ORI.o POP.o PUSH.o RET.o RC.o RNC.o RZ.o RNZ.o RP.o RM.o RPE.o RPO.o STC.o XRA.o XRI.o execution.o updatedAddress.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
	
emulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
