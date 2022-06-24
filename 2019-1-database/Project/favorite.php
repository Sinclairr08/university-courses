<!DOCTYPE html>
<html>
    <head>
    <title> Content </title>    
    
    <link rel ="stylesheet" href="css/bootstrap.css">
    <script type="text/javascript" src ="js/bootstrap.js"></script>
    <link href="css/style.css" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1> Favorite webtoon list </h1>
                       
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
        $table_name_1 = 'favorite';
        $table_name_2 = 'webtoon';
        
    try{
        $sql = "SELECT * FROM $table_name_1 NATURAL JOIN $table_name_2 WHERE uid = :id";
        $stmh = $pdo->prepare($sql);
        $stmh->bindValue(':id', $id, PDO::PARAM_STR);
        $stmh->execute();
        $count = $stmh->rowCount();
        
        if($count<1){
            print "<center><BR> no webtoons are in the list. Try to make your favorite! <BR><BR><center>";
        }
        else{
            print "<center><BR> ".$count." webtoons that you like <BR><BR><center>";
        }
        
    }catch (PDOException $Exception) {
        die('Error: '.$Exception->getMessage());
    }
    
    ?>
    
    <table class='table'>
        <tbody>
            <tr>
                <th class="text-center"> 웹툰 이름 </th>
                <th class="text-center"> 작가 이름 </th>
                <th class="text-center"> 요일 </th>
                <th class="text-center"> 성인 웹툰 여부 </th>
            </tr>
            
            <?php
                while($row = $stmh->fetch(PDO::FETCH_ASSOC)){
                    $wid = htmlspecialchars($row['wid']);
                    $wname = htmlspecialchars($row['wname']);
                    $is_adult = htmlspecialchars($row['is_adult']);
                    $wrid = htmlspecialchars($row['wrid']);
                    $weekday = htmlspecialchars($row['weekday']);
                    
                    if($is_adult == 1)
                        $adult= 'Yes';
                    else
                        $adult= 'No';
            ?>
            
            <tr>
                <td align = 'center' style="word-break: break-all">
                    <form method="POST" action="content_check.php">
                    <?php
                    echo "<button type='submit' class='btn btn-light' name='wid' value='".$wid."'>".$wname."</button>";                   
                    echo "</form>"
                    ?>    
                </td>
                <td align = 'center' style='word-break: break-all'><?=$weekday?></td>
                <td align = 'center'><?=$wrid?></td>
                <td align = 'center'><?=$adult?></td>
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