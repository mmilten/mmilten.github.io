<%--
    Document: index (for the VoteCounter project)
    Creation: May 7, 2011, 3:01:19PM
    Author: bob2
    Purpose: The markup document for the vote counter project
             Presents a ballot to the user and calls the VoteCounter
             servlet for handling the form
    --%>
<%@page contentType = "text/html" pageEncoding = "UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <title>Ballot</title>
        <meta http-equiv="Content-Type" content="text/html;
            charset=UTF-8">
    </head>
    <body>
        <form action="VoteCounter" method="POST">
            <h3> Please choose one candidate for dogcatcher </h3>
            <p>
                <input type="radio" name="vote1" value="Dogman" />
                Daren Dogman <br />
                <input type="radio" name="vote1" value="Taildragger" />
                Timmy Taildragger <br />
                <input type="radio" name="vote1" value="Dogpile" />
                Don Dogpile <br />
            </p>
            <h3> Please choose one candidate for catcatcher </h3>
            <p>
                <input type="radio" name="vote2" value="Catland" />
                Kitty Catland <br />
                <input type="radio" name="vote2" value="El Gato" />
                Al El Gato <br />
                <input type="radio" name="vote2" value="Katnip" />
                Kitten Katnip <br />
                <input type="radio" name="vote2" value="Cat" />
                Tommie Cat <br />
                <input type="radio" name="vote2" value="Feline" />
                Fred Feline <br />
            </p><p>
                <input type = "submit" value = "Submit ballot" />
            </p>
        </form>
    </body>
</html>