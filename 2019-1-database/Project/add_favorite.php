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

	$wid = $_POST['wid'];
        session_start();
        $uid = $_SESSION['ses_id'];

        $table_name = 'favorite';
        $sql = "INSERT INTO $table_name (uid, wid) VALUES ('$uid', '$wid')";
                
        if ($conn->query($sql) === TRUE) {
            echo "<script>alert(\"Successly added to your favorite\");"
            . "window.location = 'search.html';</script>";
        } else {
            
            echo "<script>alert(\"Alreay in your favorite!\");"
            . "window.location = 'search.html';</script>";
        }
 
        $conn->close();
?>
