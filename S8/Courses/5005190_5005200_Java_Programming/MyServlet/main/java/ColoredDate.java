import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/ColoredDate")
public class ColoredDate extends HttpServlet {
  String[] youbi = {
      "日", "月", "火", "水", "木", "金", "土"};

  @Override
  protected void doGet(HttpServletRequest request, 
                     HttpServletResponse response) 
               throws ServletException, IOException {
    response.setContentType(
      "text/html; charset=UTF-8");
    PrintWriter out = response.getWriter();
    Calendar cal = Calendar.getInstance();

    out.println("<html><head></head><body>");

    // initialize thisSec
    int thisSec = cal.get(Calendar.SECOND);

    if (thisSec >= 0 && thisSec <= 19) {
      out.println("<span style=\"color: black\">");
    }

    else if (thisSec >= 20 && thisSec <= 39) {
      out.println("<span style=\"color: blue\">");
    }

    else if (thisSec >= 40 && thisSec <= 59) {
      out.println("<span style=\"color: red\">");
    }
    
    out.printf("%d年%d月%d日%s曜日%d時%d分%d秒\n", 
      cal.get(Calendar.YEAR), 
      cal.get(Calendar.MONTH) + 1, 
      cal.get(Calendar.DAY_OF_MONTH), 
      youbi[cal.get(Calendar.DAY_OF_WEEK) - 1],
      cal.get(Calendar.HOUR_OF_DAY), 
      cal.get(Calendar.MINUTE), 
      cal.get(Calendar.SECOND));  

    out.println("</span></body></html>");
    out.close();
  }
}