<?php
        $db_user="root";
        $db_pass="1234";
        $db_type="mysql";
        $db_host="localhost";
        $db_name="webtoon";
        $dsn = "$db_type:host=$db_host; dbname=$db_name; charset=utf8";
        
        $conn = new mysqli($db_host, $db_user, $db_pass, $db_name);
        if ($conn -> connect_error)
            { die("Connection failed: " . $conn->connect_error); } 

        session_start();
        $uid = $_SESSION['ses_id'];
        $u_cookies = $_SESSION['cookies'];
	$money = $_POST['money'];
        $n_cookies = intdiv($money, 100);
        $table_name = 'user';
        
        $u_cookies = $u_cookies + $n_cookies;
        $sql = "UPDATE $table_name SET cookies = $u_cookies WHERE uid = '$uid'";
 
        if ($conn->query($sql) === TRUE) {
            $_SESSION['cookies'] = $u_cookies;
            echo "<script>alert(\"Charged correctly!\");"
            . "window.location = 'main.html';</script>";
        }
        # Error: update failure
        else {
            echo "<script>alert(\"Someting wrong happened!\");"
            . "window.location = 'charge.html';</script>";
        }
        $conn->close();
?>