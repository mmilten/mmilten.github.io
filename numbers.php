<!DOCTYPE html>
<!-- numbers.php is the 
     php for exercise 9.5
      -->
<html lang = "en">
    <head>
        <title> numbers.php </title>
        <meta charset = "utf-8" />
    </head>
    <body>
        <?php
            /** Get the first four-digit number in a string
             *  Parameter: a string that contains numbers seperated by spaces
             *  Returns: The first-four digit number in the string, returns 0
             *  if there is no numbers found
            */
            function string_number($str)
            {
                $numbers = preg_split("/ +/", $str);
                foreach ($numbers as $numb)
                    if (strlen($numb) == 4)
                        return $numb;
                return false;
            }

            $number_str = "5 12 456 1223 128840 88499 2354 33";
            $result = string_number($number_str);

            if ($result !=0)
                print("The first four-digit number is: $result <br />");
            else
                print("There are no four-digit number in the string <br />");
        ?>
    </body>
</html>
