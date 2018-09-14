import java.lang.*;
import java.net.*;
import java.io.*;
import java.util.*;

class Tclient
{
public static void main(String args[]) throws Exception
{

	Socket s = new Socket("127.0.0.1",8002);

	BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));

	DataOutputStream dobj = new DataOutputStream(s.getOutputStream());

	String str1,str2;

	BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));


	while(!((str1=sc.readLine()).equals("exit")))
	{
		dobj.writeBytes(str1+"\n");
		
		str2 = br.readLine();

		System.out.println(str2);
	}


	dobj.close();
	br.close();

}
}
