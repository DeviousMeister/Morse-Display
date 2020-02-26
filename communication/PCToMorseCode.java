package communication;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import jssc.SerialPortException;

public class PCToMorseCode {
	public static void main(String[] args) throws SerialPortException, IOException {		
		// TODO:  Fix this: 
		//           a) Uncomment to create a SerialComm object
		//           b) Update the "the port" to refer to the serial port you're using
		//              (The port listed in the Arduino IDE Tools>Port menu.		
		//           c) Deal with the unresolved issue
		SerialComm port = new SerialComm("COM3");
		
		// TODO: Complete section 6 of the Studio gather sanitized user input
		//       and send it to the Arduino) ??????????
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while(true){
			int n = in.read();
			port.writeByte((byte)n);
		}
		
	}

}
