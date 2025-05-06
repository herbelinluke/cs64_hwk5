#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          Level 1 difficulty: assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti
//          c) has only registers $t0 thru $t7 or $s0 thru $s7 in the instruction
//

string registers( int r ) {
	if (r >= 16) {
		if (r == 16) { return "$s0, "; }
		else if (r == 17) { return "$s1, "; }
		else if (r == 18) { return "$s2, "; }
		else if (r == 19) { return "$s3, "; }
		else if (r == 20) { return "$s4, "; }
		else if (r == 21) { return "$s5, "; }
		else if (r == 22) { return "$s6, "; }
		else if (r == 23) { return "$s7, "; }
	} else if (r == 8) { return "$t0, "; }
   	else if (r == 9) {return  "$t1, "; }
	else if (r == 10) { return  "$t2, "; }
	else if (r == 11) { return  "$t3, "; }
	else if (r == 12) { return  "$t4, "; }
	else if (r == 13) { return  "$t5, "; }
	else if (r == 14) { return  "$t6, "; }
	else if (r == 15) { return  "$t7, "; }
	return "null, ";
		
}


string disassemble( string hex ) {

    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the different parts of the hex instruction!
    //
    // YOUR CODE GOES HERE!!
	string result;
    if (hex[0] == '2') {
		if (stoi(string(1, hex[1]), nullptr, 16) < 4) { 
			result = "addi ";
		} else if (stoi(string(1, hex[1]) + "\0", nullptr, 16) >= 8) { 
			result = "slti ";
		} else { 
			result = "addiu ";
		}
	} else {
		if (stoi(string(1, hex[1]) + "\0", nullptr, 16) >= 4) { 
			result = "ori ";
		} else { 
			result = "andi ";
		}
	}

	int rs = stoi(string(1, hex[1]) + string(1, hex[2]), nullptr, 16);
	rs = rs >> 1;
	rs = rs & 31;	
	int rt = stoi(string(1, hex[2]) + string(1, hex[3]), nullptr, 16);
	rt = rt & 31;	
	result += registers(rt);
	result += registers(rs);
		
	int16_t immediate = static_cast<int16_t>(stoi(hex.substr(4), nullptr, 16));
	result += to_string(immediate);
    return result;  // remove stub and replace it with correct variable
}

int main() {
// Don't change any code in main() function!!

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
