import java.io.* ;
import java.util.* ;
import java.math.* ;
import java.text.* ;
import static java.lang.Math.min ;
import static java.lang.Math.max ;
public class Main{
	public static void main(String args[]) throws IOException{
		Solver s = new Solver() ;
		s.init() ;
		s.Solve() ;
		s.Finish() ;
	}
}
class pair implements Comparable<pair>{
	long x,y ;
	pair(long x,long y){
		this.x = x ; this.y=y ;
	}
	public int compareTo(pair p){
		return (this.x<p.x ? -1 : (this.x>p.x ? 1 : (this.y<p.y ? -1 : (this.y>p.y ? 1 : 0)))) ;
	}
}
class Solver{
	void Solve() throws IOException{
		
	}	
	void init(){
		op = new PrintWriter(System.out) ;
		ip = new Reader(System.in) ;		
	}
	void Finish(){
		op.flush() ;
		op.close() ;
	}
	void p(Object o){
		op.print(o) ;
	}
	void pln(Object o){
		op.println(o) ;
	}
	PrintWriter op ;
	Reader ip ;		
}
class Reader {
	BufferedReader reader;
	StringTokenizer tokenizer;
	Reader(InputStream input) {
		reader = new BufferedReader(
					new InputStreamReader(input) );
		tokenizer = new StringTokenizer("") ;
	}
	String s() throws IOException {
		while (!tokenizer.hasMoreTokens()){
			tokenizer = new StringTokenizer(
			reader.readLine()) ;
		}
		return tokenizer.nextToken();
	}
	int i() throws IOException {
		return Integer.parseInt(s()) ;
	}
	long l() throws IOException{
		return Long.parseLong(s()) ;
	}
	double d() throws IOException {
		return Double.parseDouble(s()) ;
	}
}

