import java.lang.*;
import java.net.*;
import java.io.*;
import java.util.*;

class Tserver 
{

public static void main(String args[]) throws Exception
{

	ServerSocket ss = new ServerSocket(8002);
	
	Socket s = ss.accept();

	PrintStream dobj = new PrintStream(s.getOutputStream());

	BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));

	BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

	
	
while(true)
{
String str1,str2;
	while((str1 = br.readLine())!=null)
	{
	
	System.out.println(str1);
	str2 = sc.readLine();	
	dobj.println(str2);
	} 
			dobj.close();
			ss.close();
			s.close();
			br.close();
}




}
}
