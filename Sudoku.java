import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Sudoku {
	 private int[][] sudoku; 
	 public Sudoku(int[][] sudoku) {
	  this.sudoku = sudoku;
	 }
	  
	 public static void main(String args[]) throws IOException {
		 if (args.length == 0)                              //接收参数
	        {
	            System.out.println("无参数！");
	        }
			else
			{
				
				int n=Integer.parseInt(args[1]);
				int m=Integer.parseInt(args[3]);
		        String i=args[5];
		        String o=args[7]; 
		    	RFile(n,m,i,o);    
	         }
		
	 }

	 public static  void RFile(int n,int m,String i,String o) throws IOException {
		 int k=0,k1,k2;
		 int [][] sudoku1= {{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0}};
			BufferedReader br = new BufferedReader(new FileReader(i));
	        String temp;//定义字符串,用于保存每行读取到的
	        int count=0;
	        while ((temp = br.readLine()) != null) {
	              int[] ary=intchange(temp);//通过函数ba字符串数组解析成整数数组
	            	 sudoku1[k]=ary;
	              if(count==n) {
	            	int[][] sudoku=null;
	      	        for(k1=0;k1<n;k1++) {
	      	        	for(k2=0;k2<n;k2++) {
	      	        		sudoku[k1][k2]=sudoku1[k1][k2];
	      	        	}
	      	        }
	      	        Sudoku s=new Sudoku(sudoku);
	      	        s.Resolve(0, 0, n,o);
	              }
	        
	       
	       }
	 }
	 
	 static int[] intchange(String temp) {// 字符串数组解析成int数组
		  String[] ss = temp.trim().split("\\s+");// .trim()可以去掉首尾多余的空格
		            // .split("\\s+")
		            // 表示用正则表达式去匹配切割,\\s+表示匹配一个或者以上的空白符
		  int[] sudoku = new int[ss.length];
		  for (int i = 0; i < sudoku.length; i++) {
		   sudoku[i] = Integer.parseInt(ss[i]);// 解析数组的每一个元素
		  }
		  return sudoku;// 返回一个int数组
		 }
	 
	  public void WFile(String o,int n) throws IOException {  
		  File file = new File(o);  //存放数组数据的文件 
			FileWriter out = new FileWriter(file); //文件写入流 
			   
		  //将数组中的数据写入到文件中。每行各数据之间TAB间隔 
		  for(int i=0;i<n;i++){ 
		   for(int j=0;j<n;j++){ 
		    out.write(sudoku[i][j]+" ");
		    System.out.print(sudoku[i][j]);
		   } 
		   out.write(""); 
		  } 
		  out.close(); 
		}
	  
	 /**
	  * 数独算法
	  *
	  * @param i 行号
	  * @param j 列号
	 * @throws IOException 
	  */
	 public void Resolve(int i, int j,int n,String o) throws IOException {
	  if (i == n-1 && j == n) {
	   //已经成功了，打印数组即可
	   WFile(o,n);
	  }
	  //已经到了列末尾了，还没到行尾，就换行
	  if (j == n) {
	   i++;
	   j = 0;
	  }
	  
	  //如果i行j列是空格，那么才进入给空格填值的逻辑
	  if (sudoku[i][j] == 0) {
	   for (int k = 1; k <= n; k++) {
	    //判断给i行j列放1-n中的任意一个数是否能满足规则
	    if (check(i, j, k,n)) {
	     //将该值赋给该空格，然后进入下一个空格
	     sudoku[i][j] = k;
	     Resolve(i, j + 1,n,o);
	     //初始化该空格
	     sudoku[i][j] = 0;
	    }
	   }
	  } else {
	   //如果该位置已经有值了，就进入下一个空格进行计算
	   Resolve(i, j + 1,n,o);
	  }
	  
	 }
	  
	 /**
	  * 判断给某行某列赋值是否符合规则
	  *
	  * @param row 被赋值的行号
	  * @param line 被赋值的列号
	  * @param number 赋的值
	  */
	 private boolean check(int row, int line, int number,int n) {
	  //判断该行该列是否有重复数字
	  for (int i = 0; i < n; i++) {
	   if (sudoku[row][i] == number || sudoku[i][line] == number) {
	    return false;
	   }
	  }
	  return true;
	 }
	  
}
