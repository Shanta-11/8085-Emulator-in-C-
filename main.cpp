#include "MASTER.h"
#include <fstream>
#include "tools.h"

class simulator8085
{
private:
     map<string,string> Memory;
     vector<string>sequence;
     string startAddress;
     string pc;
     string sp;
     bool flag[8];
     string registers[7];
     bool memdump;
public :
	simulator8085(){
		
		for(int i = 0;i<7;i++)
			registers[i] = "NULL";
		
		for(int i=0;i<8;i++)
			flag[i] = false;
		
		startAddress = "";
		pc = "";
        sp = "FFFF";
        memdump = false;
	}
    void getStartAddress()
    {
        cout<<"\nEnter the starting address:\n";
        cin>>startAddress;
        pc = startAddress;
        if(!validityAddress(startAddress)){
			
			cout<<"Invalid Starting address, please enter a hex address";
			exit(1);
		}
        sequence.push_back(startAddress);
    }
    void programFileMemDump(char* filename){
        memdump = true;
        onlyProgramFile(filename);
    }

    void onlyProgramFile(char* filename)
    {
        ifstream input;
        input.open(filename);
        if(input.fail() == true){
			
			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
			exit(0);
		}
        string line;
        while(getline(input,line))
        {
            if(isValidCommand(line))
            {
                Memory[pc]=line;
                pc=updatedAddress(pc,Memory);
                
                sequence.push_back(pc);
			}else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
        }

        pc = startAddress;

        while(Memory[pc] != "HLT")
        {
            
            pc=execution(Memory[pc],registers,flag,Memory,pc, sp);
            // cout<<"executed "<<Memory[pc]<<endl;
        }
        if(memdump){
            cout<<"Memory Dump Starts"<<endl<<endl;
            cout<<"ADDR Instruction"<<endl;
            cout<<"-------------------------"<<endl;
            for(auto it = Memory.begin(); it != Memory.end(); it++){
                cout<<it -> first<<" "<<it -> second<<"\n";
            }
        }
    }
};

int main(int argc,char* argv[])
{
    simulator8085 instance;
    instance.getStartAddress();
    if(argc == 3){
        if(strcmp(argv[2], "-m")==0){
            instance.programFileMemDump(argv[1]);
        }
        else{
            cout<<"invalid argument, use '-m' for memory dump...\n exitting..."<<endl;
            exit(1);
        }
    }
    if(argc==2)
    {
		instance.onlyProgramFile(argv[1]);
    }
    else if(argc==1)
    {
        cout<<"No File provided, exitting..."<<endl;
		exit(1);
    }
    
}
