<!DOCTYPE html>
<html>
    <head>
    <title> Content </title>
    
    <link rel ="stylesheet" href="css/bootstrap.css">
    <script type="text/javascript" src ="js/bootstrap.js"></script>
    <link href="css/style.css" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1> Available list </h1>

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
    
        session_start();
        $id = $_SESSION['ses_id'];
        $table_name_1 = 'webtoon_content';
        $table_name_2 = 'bought';
        
    try{
        $sql = "SELECT * FROM  $table_name_1 t1 where NOT EXISTS (SELECT * FROM $table_name_2 t2 where t1.wid = t2.wid and t1.cname = t2.cname and uid = :id)";
        $stmh = $pdo->prepare($sql);
        $stmh->bindValue(':id', $id, PDO::PARAM_STR);
        $stmh->execute();
        $count = $stmh->rowCount();
        
        if($count<1){
            print "<center><BR> You purchased all the webtoons! <BR><BR><center>";
        }
        else{
            print "<center><BR> ".$count." webtoons that you can purchase <BR><BR><center>";
        }
        
        
    }catch (PDOException $Exception) {
            die('Error: '.$Exception->getMessage());
        }
    
    ?>
    
    <table class='table'>
        <tbody>
            <tr>
                <th class="text-center"> 웹툰 이름 </th>
                <th class="text-center"> 웹툰 화 </th>
                <th class="text-center"> 평점 </th>
                <th class="text-center"> 요구 쿠키 수 </th>
                <th class="text-center"> 구매 </th>
            </tr>
            
            <?php
                while($row = $stmh->fetch(PDO::FETCH_ASSOC)){
                    $wid = htmlspecialchars($row['wid']);
                    $cname = htmlspecialchars($row['cname']);
                    $r_cookie = htmlspecialchars($row['r_cookie']);
                    $ratio = htmlspecialchars($row['ratio']);
                    
                    $table_webtoon = 'webtoon';
                    $sql_content = "SELECT * FROM $table_webtoon WHERE wid = :wid";
                    $stmt = $pdo->prepare($sql_content);
                    $stmt->bindvalue(':wid', $wid, PDO::PARAM_STR);
                    $stmt->execute();
                    $row_webtoon =  $stmt->fetch(PDO::FETCH_ASSOC);
                    $wname = $row_webtoon['wname'];
            ?>
            
            <tr>
                <td align = 'center' style="word-break: break-all"><?=$wname?></td>
                
                <td align = 'center' style="word-break: break-all">
                    <button class='btn btn-light'><?=$cname?> </button>
                </td>
                <td align = 'center' style='word-break: break-all'><?=$ratio?>  </td>
                <td align = 'center' style='word-break: break-all'><?=$r_cookie ?>  </td>
                <td align = 'center'>
                    <form method="POST" action="purchase_check.php">
                    <?php
                    echo "<button type='submit' class='btn btn-success' name='wid_cname' value='".$wid."@".$cname."@".$r_cookie."'> purchase </button>";
                    echo "</form>"
                    ?>
                </td>
            </tr>
  
            <?php
            }
            ?>
           
            </tbody>
        </table>
    
    <br>
    <a href = "main.html"><button class="btn btn-link"> Go to home </button></a>
    
    </body>
</html>