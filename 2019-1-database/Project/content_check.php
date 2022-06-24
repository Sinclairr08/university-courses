<!DOCTYPE html>
<html>
    <head>
    <title> main page </title>
    
    <link rel ="stylesheet" href="css/bootstrap.css">
    <script type="text/javascript" src ="js/bootstrap.js"></script>
    <link href="css/style.css" rel="stylesheet" type="text/css">
    </head>    
    
    <body>

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

	$wid = $_POST['wid'];
        $table_name = 'webtoon';
        $sql = "select * from $table_name where wid = :wid";
                
        $stmh = $pdo->prepare($sql);
        $stmh->bindvalue(':wid', $wid, PDO::PARAM_STR);
        $stmh->execute();
        
        $count = $stmh->rowCount();
        $row = $stmh->fetch(PDO::FETCH_ASSOC);
        $is_adult = $row['is_adult'];
        
        session_start();
        $user_age = $_SESSION['ses_age'];
            
        if($is_adult == 1 && $user_age < 19){
            echo "<script>alert(\"Not available for kids!\");"
            . "window.location = 'main.html';</script>";
        }
           
        $wname = $row['wname'];
        $table_content = 'webtoon_content';
        ?>
        
        <h2> <?=htmlspecialchars($wname)?>  </h2>
        
        <?php
        $sql_content = "SELECT * FROM $table_content WHERE wid = :wid";
        $stmt = $pdo->prepare($sql_content);
        $stmt->bindvalue(':wid', $wid, PDO::PARAM_STR);
        $stmt->execute();            
        $count = $stmt->rowCount();
        
        if($count<1){
            print "<center><BR> Webtoon have no contents<BR><BR><center>";
        }
        
        else{
            print "<center><BR> ".$count." webtoon stories are exist <BR><BR><center>";
        }
        ?>

    <table class='table'>
        <tbody>
            <tr>
                <th class="text-center"> 웹툰 화 </th>
                <th class="text-center"> 평점 </th>
                <th class="text-center"> 요구 쿠키 수 </th>
                <th class="text-center"> 구매 </th>
            </tr>
            
            <?php
                while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
                    $cname = htmlspecialchars($row['cname']);
                    $r_cookie = htmlspecialchars($row['r_cookie']);
                    $ratio = htmlspecialchars($row['ratio']);
            ?>
            
            <tr>
                <td align = 'center' style="word-break: break-all">
                    <button class='btn btn-light'><?=$cname?> </button>
                </td>
                <td align = 'center' style='word-break: break-all'><?=$ratio?></td>
                <td align = 'center' style='word-break: break-all'><?=$r_cookie ?>  </td>
                <td align = 'center'>
                    <form method="POST" action="purchase_check.php">
                    <?php
                    echo "<button type='submit' class='btn btn-success' name='wid_cname' value='".$wid."@".$cname."@".$r_cookie."'> purchase </button>";   
                    echo "</form>"
                    ?>
            </tr>
            <?php
            }
            ?>
           
        </tbody>        
    </table>

    </body>
</html>