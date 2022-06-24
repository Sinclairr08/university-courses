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

	$id = $_POST['new_id'];
        $pw = $_POST['new_pw'];
        $age = $_POST['new_age'];
        $name = $_POST['new_name'];
        $cookies = '0';
        
        $table_name = 'user';
        
        $sql = "INSERT INTO $table_name (uid, upw, uname, uage, cookies) VALUES"
                . "('$id', '$pw', '$name', $age, $cookies)";
 
        if ($conn->query($sql) === TRUE) {
            echo "<script>alert(\"Sign in correctly\");"
            . "window.location = 'login.html';</script>";
        }
        # Error : if there is a field that is not filled
        else if(mysqli_errno($conn) == 1064) {                    
            echo "<script>alert(\"Fill the blank!\");"
            . "window.location = 'sign_up.html';</script>";
        }
        # Error : if the id is duplicate
        else if(mysqli_errno($conn) == 1062){
            echo "<script>alert(\"Those id exist. please use other id!\");"
            . "window.location = 'sign_up.html';</script>";
        }
        # Error : Other errors
        else{
            echo "<script>alert(\"unexpected error! Try again!!\");"
            . "window.location = 'sign_up.html';</script>";
        }
 
        $conn->close();

?>
