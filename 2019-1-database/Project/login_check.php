<?php
    $db_user="root";
    $db_pass="1234";
    $db_type="mysql";
    $db_host="localhost";
    $db_name="webtoon";
    $dsn = "$db_type:host=$db_host; dbname=$db_name; charset=utf8";

    try{
        $pdo=new PDO($dsn, $db_user, $db_pass);
    }
    catch (PDOException $Exception) {
        die('Error: '.$Exception->getMessage());
    }
    
    $id = $_POST['user_id'];
    $pw = $_POST['user_pw'];
        
    $table_name = 'user';       
    $sql = "select * from $table_name where uid = :id and upw = :pw";
                
    $stmh = $pdo->prepare($sql);
    $stmh->bindvalue(':id', $id, PDO::PARAM_STR);
    $stmh->bindvalue(':pw', $pw, PDO::PARAM_STR);
    $stmh->execute();
        
    $count = $stmh->rowCount();
        
    if($count<1){
        echo "<script>alert(\"No id or Wrong password!\");"
        . "window.location = 'login.html';</script>";
    }
    else{
        $row = $stmh->fetch(PDO::FETCH_ASSOC);
        $name = $row['uname'];
        $age = $row['uage'];
        $cookies = $row['cookies'];
            
        session_start();
        $_SESSION['ses_id'] = $id;
        $_SESSION['ses_pw'] = $pw;
        $_SESSION['ses_name'] = $name;
        $_SESSION['ses_age'] = $age;
        $_SESSION['cookies'] = $cookies;
            
        echo "<script>window.location = 'main.html';</script>";
    }
?>
