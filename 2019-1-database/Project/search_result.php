<!DOCTYPE html>
<html>
    <head>
    <title> Content </title>
    
    <link rel ="stylesheet" href="css/bootstrap.css">
    <script type="text/javascript" src ="js/bootstrap.js"></script>
    <link href="css/style.css" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1> webtoon search </h1>
        
            <FORM method="post" action = "search_result.php">          
                <label>webtoon name : </label>
            <input type="text" class="form-control" name="webtoon_name">
            <br>
            <button type="submit" class="btn btn-primary">Search</button>
            </FORM>
            
    
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
    
    $webtoon_name = $_POST['webtoon_name'];
    $search_key = '%'.$webtoon_name.'%';
    
    try{
        $sql = "SELECT * FROM webtoon WHERE wname LIKE :webtoon_name";
        $stmh = $pdo->prepare($sql);
        $stmh->bindValue(':webtoon_name', $search_key, PDO::PARAM_STR);
        $stmh->execute();
        $count = $stmh->rowCount();
        
        if($count<1){
            print "<center><BR> no webtoons are selected <BR><BR><center>";
        }
        else{
            print "<center><BR> ".$count." webtoons are found <BR><BR><center>";
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
                <th class="text-center"> 관심 웹툰 추가 </th>
            </tr>
            
            <?php
                while($row = $stmh->fetch(PDO::FETCH_ASSOC)){
            ?>
            
            <tr>
                <td align = 'center' style="word-break: break-all">
                    <form method="POST" action="content_check.php">
                    <?php
                    $wid = htmlspecialchars($row['wid']);
                    $wrid = htmlspecialchars($row['wrid']);
                    $wname = htmlspecialchars($row['wname']);
                    $is_adult = htmlspecialchars($row['is_adult']);
                    $weekday = htmlspecialchars($row['weekday']);
                    
                    if($is_adult == 1)
                        $adult= 'Yes';
                    else
                        $adult= 'No';
                    
                    echo "<button type='submit' class='btn btn-light' name='wid' value='".$wid."'>".$wname."</button>";
                    echo "</form>"
                    ?>  
                </td>
                <td align = 'center' style='word-break: break-all'><?=$wrid?></td>
                <td align = 'center'><?=$weekday?></td>
                <td align = 'center'><?=$adult?></td>
                <td align = 'center'>
                    <form method="POST" action="add_favorite.php">
                    <?php                   
                    echo "<button type='submit' class='btn btn-warning' name='wid' value='".$wid."'> add favorite </button>";
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