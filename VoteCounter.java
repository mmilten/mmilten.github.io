/** VoteCounter.java
 *  This servlet processes the ballot form, returning a
 *  document asking for a new vote if no vote was made on the
 *  ballot. For legitimate ballots, the vote is added to
 *  the current totals, and those totals are presented to
 *  the user in a return document.
 *  A cookie is returned to the voter, recording the fact
 *  that a vote was received. The servlet examines all votes
 *  for cookies to ensure that there is no multiple voting.
 *  The voting data file, votesdat.ser, is stored on the Web
 *  server.
 */

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class VoteCounter extends HttpServlet {

    protected void processRequest(HttpServletRequest request, 
                                  HttpServletResponse response)
            throws ServletException, IOException {
        Cookie cookies[] = null;
        int index;
        Cookie newCookie;
        int votes[] = null;
        int sumCatVotes;
        int sumDogVotes;
        String vote1;
        String vote2;
        File votesdat = new File("votesdat.ser");
        String dogCandidates[] = {"Daren Dogman", "Timmy Taildragger",
            "Don Dogpile"};
        String catCandidates [] = {"Kitty Catland", "Al El Gato", 
            "Kitten Katnip", "Tommie Cat", "Fred Feline"};
        
        // Set content type for response and get a writer
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
 
        // Get cookies from the request
        cookies = request.getCookies();

        // Check to see if there was a vote on the form
        vote1 = request.getParameter("vote1");
        vote2 = request.getParameter("vote2");
        if (vote1 == null || vote2 == null) {  //** There was no vote
            // Create the return document
            makeHeader(response, out);
            out.println(
                    "You submitted a ballot with no vote marked <br />");
            out.println(
                    "Please mark the ballot and resubmit");
        } //** end of if (vote == null) ...
        else {  //** There was a vote

            // Check to see if this client voted before
            if (!votedBefore(cookies)) {

                // No previous vote, so get the contents of the file
                //  (if the file already exists)

                // Synchronize block for file input-output
                synchronized (this) {
                    if (votesdat.exists()) {
                        ObjectInputStream indat = 
                        new ObjectInputStream(new FileInputStream(votesdat));

                        // We need the try-catch here because
                        // readObject can throw ClassNotFoundException
                        try {
                            votes = (int[]) indat.readObject();
                        } catch (ClassNotFoundException problem) {
                            problem.printStackTrace();
                        }
                    } //** end of if(votesdat.exists() ...
                    
                    // If the file does not exist (this is the first
                    //  vote), create the votes array
                    else {
                        votes = new int[8];                    
                    }    
                    // Add the new vote to the votes array
                    if (vote1.equals("Dogman")) {
                            votes[0]++;
                    } else if (vote1.equals("Taildragger")) {
                            votes[1]++;
                    } else {
                            votes[2]++;
                    }   //** end of if (vote.equals("Dogman"))  

                    if (vote2.equals("Catland")) {
                            votes[3]++;
                    } else if (vote2.equals("El Gato")) {
                            votes[4]++;
                    } else if (vote2.equals("Katnip")) {
                            votes[5]++;
                    } else if (vote2.equals("Cat")) {
                            votes[6]++;
                    } else {
                            votes[7]++;
                    }   //** end of if (vote.equals("Catland"))
                                       
                    // Write updated votes array to disk
                    ObjectOutputStream outdat = new ObjectOutputStream(
                            new FileOutputStream(votesdat));
                    outdat.writeObject(votes);
                    outdat.flush();
                    outdat.close();
                }  //** end of synchronized block

                // Attach a cookie to the response
                newCookie = new Cookie("iVoted", "true");
                newCookie.setMaxAge(5);   //** Set to 5 for testing
                response.addCookie(newCookie);

                // Write a response message
                makeHeader(response, out);
                out.println("Your vote has been received");
                out.println(
                    "<br /><br /> Current Voting Percentages: <br />");

                // Compute the total dog and cat votes
                sumCatVotes = 0;
                sumDogVotes = 0;
                for (index = 0; index < 3; index++)
                    sumDogVotes += votes[index];
                for (index = 3; index < 8; index++)
                    sumCatVotes += votes[index];

                // Create the dog votes percentages
                out.println("<h3> For Dogcatcher </h3>");
                for (index = 0; index < 3; index++) {
                    out.print(dogCandidates[index]);
                    out.print(": ");
                    if (sumDogVotes > 0)
                        out.println(
                         ((100 * votes[index]) / sumDogVotes) +
                          "% <br />");
                    else
                        out.println(0 + "% <br />");
                }
                
                // Create the cat votes percentages
                out.println("<br /> <br /> <h3> For Catcatcher </h3>");
                for (index = 3; index < 8; index++) {
                    out.print(catCandidates[index - 3]);
                    out.print(": ");
                    if (sumCatVotes > 0)
                        out.println(((100 * votes[index]) /
                                     sumCatVotes) + "% <br />");
                    else
                        out.println(0 + "% <br />");
                }
            } //** end of if (!votedBefore(cookies) ...
            else {  // The client voted before

                // Write a response message
                makeHeader(response, out);
                out.println(
                    "Your vote is illegal - you have already voted!");
            }  // end of else clause - client voted before
        }  // end of else (there was a vote)

        // Finish response document and close the stream
        out.println("</body> </html>");
        out.close();

    }  //** end of ProcessRequest

    //-----------------------------------------------------------------
    // Method votedBefore - return true if the client voted before;
    //  false otherwise
    private boolean votedBefore(Cookie [] cookies) {
        if (cookies == null || cookies.length == 0) {
            return false;
        } else {

            // Check the cookies to see if this user voted before
            for (Cookie cookie: cookies) {
                if (cookies.getName().equals("iVoted")) {
                    return true;
                }
            }  // end of for (index = 0; ...
            return false;
        }  //** end of if (cookies == null ...
    }  //** end of votedBefore

    //-----------------------------------------------------------------
    // Method makeHeader - get the writer and produce the
    //  response header
    private void makeHeader(HttpServletResponse response,
                            PrintWriter out)
            throws IOException {

        // Write the response document head and the message
        out.println("<html><head>");
        out.println(
                "<title> Return message </title></head><body>");
    }  //** end of makeHeader

    // Method doPost - just calls processRequest
    protected void doPost(HttpServletRequest request,
            HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}  //** end of VoteCounter2
