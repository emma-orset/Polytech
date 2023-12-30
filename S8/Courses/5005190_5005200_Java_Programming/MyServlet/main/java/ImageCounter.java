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

@WebServlet("/ImageCounter")
public class ImageCounter extends HttpServlet {
  @Override
  protected void doGet(HttpServletRequest request, 
                     HttpServletResponse response) 
            throws ServletException, IOException {
    response.setContentType(
      "text/html; charset=UTF-8");
    PrintWriter out = response.getWriter();
    out.println("<html><head></head><body>");
    
    int count; 
    File tmpDir = new File(
      System.getProperty("java.io.tmpdir"));
    File f = new File(tmpDir, "counter.txt");
    BufferedReader fin = null;
    try {
      fin = new BufferedReader(new FileReader(f));
      count = Integer.parseInt(fin.readLine());
    } catch (FileNotFoundException | NullPointerException | NumberFormatException e) {
      count = 0;
    } finally {
      if (fin != null) {
        fin.close();
      }
    }

    count++;
    PrintWriter fout = new PrintWriter(new FileWriter(f));
    fout.println(count);
    fout.close();

    out.print("あなたは ");
    
    String countString = String.valueOf(count);
    for (int i = 0; i < countString.length(); i++) {
      char digit = countString.charAt(i);
      String imageName = "images/" + digit + ".png";
      out.printf("<img src=\"%s\" alt=\"%s\">", imageName, digit);
    }
    
    out.println("番目の来訪者です。");
    out.println("</body></html>");
    out.close();
  }
}
