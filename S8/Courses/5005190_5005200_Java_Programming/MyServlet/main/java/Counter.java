package main.java;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/Counter")
public class Counter extends HttpServlet {
  @Override
  protected void doGet(HttpServletRequest request, 
                     HttpServletResponse response) 
            throws ServletException, IOException {
    response.setContentType(
      "text/html; charset=UTF-8");
    PrintWriter out = response.getWriter();
    out.println("<html><head></head><body>");
    int i; 
    File tmpDir = new File(
      System.getProperty("java.io.tmpdir"));
    File f = new File(tmpDir, "counter.txt");
    BufferedReader fin = null;
    try {
      fin = new BufferedReader(new FileReader(f));
      i =  Integer.parseInt(fin.readLine());
    } catch (FileNotFoundException // ファイルがなければ 
           | NullPointerException  // ファイルが空なら 
           | NumberFormatException e) { // 数でないなら
      i = 0;  // 0 に
    } finally {
      if (fin != null) {
        fin.close();  // closeを忘れない
      }
    }

    PrintWriter fout
        = new PrintWriter(new FileWriter(f));
    fout.println(++i);
    fout.close();  // closeを忘れない

    out.printf("あなたは %d番目の来訪者です。%n", i);
    out.println("</body></html>");
    out.close();   // closeを忘れない
  }
}