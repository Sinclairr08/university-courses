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
    $wid_cname = $_POST['wid_cname'];
    $pieces = explode("@", $wid_cname);     # For parsing
    $wid = $pieces[0];
    $cname = $pieces[1];
    $r_cookie = $pieces[2];
    
    try{
        $pdo=new PDO($dsn, $db_user, $db_pass);
    }
    catch (PDOException $Exception) {
        die('Error: '.$Exception->getMessage());
    }

    $age = $_SESSION['ses_age'];
    $table_name = 'webtoon';
        
    $sql = "select * from $table_name where wid = :id";
    $stmh = $pdo->prepare($sql);
    $stmh->bindvalue(':id', $wid, PDO::PARAM_STR);
    $stmh->execute();
        
    $row = $stmh->fetch(PDO::FETCH_ASSOC);
    $is_adult = $row['is_adult'];
    
    # Adult webtoon is accessed by kids
    if($is_adult == 1 && $age < 19){
        echo "<script>alert(\"Not for kids!\");"
        . "window.location = 'main.html';</script>";
    }
    
    # Not enough cookie
    else if ($u_cookies < $r_cookie){
        echo "<script>alert(\"Not enough cookie! please charge your cookie\");"
        . "window.location = 'charge.html';</script>";
    }
        
    else{
        $table_name = "bought";
        $sql = "INSERT INTO $table_name (uid, wid, cname) VALUES"
                . "('$uid', '$wid', '$cname')";
        
        if ($conn->query($sql) === TRUE) {
            $u_cookies = $u_cookies - $r_cookie;
                
            $table_name_2 = 'user';
            $sql_update = "UPDATE $table_name_2 SET cookies = $u_cookies WHERE uid = '$uid'";
                
            if($conn->query($sql_update) == TRUE){
                $_SESSION['cookies'] = $u_cookies;
                echo "<script>alert(\"Thank you for your purchase\");"
                . "window.location = 'purchase.php';</script>";
            }
                
            else {

            echo "<script>alert(\"somthing wrong happened! please try again\");"
                . "window.location = 'purchase.php';</script>";
            }
                
        } else {
            echo "<script>alert(\"you can't buy this! maybe you already bought this one\");"
            . "window.location = 'purchase.php';</script>";
        }
    }
?>