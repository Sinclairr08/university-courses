<!DOCTYPE html>
<html>
    <head>
    <title> Content </title>    
    
    <link rel ="stylesheet" href="css/bootstrap.css">
    <script type="text/javascript" src ="js/bootstrap.js"></script>
    <link href="css/style.css" rel="stylesheet" type="text/css">
    </head>

    <body>
        <h1> Information </h1>

    <?php
        session_start();
        $uname = $_SESSION['ses_name'];
        $cookie = $_SESSION['cookies'];
        $uage = $_SESSION['ses_age'];   
    ?>
    
    <table class='table'>
        <tbody>
            <tr>
                <th class="text-center"> 이름 </th>
                <td align="center"><?=$uname?></td>
            </tr>
            
            <tr>
                <th class="text-center"> 나이 </th>
                <td align="center"><?=$uage?></td>
            </tr>
            
            <tr>
                <th class="text-center"> 쿠키 수 </th>
                <td align="center"><?=$cookie?></td>
            </tr>
        </tbody>   
    </table>
    
    <br>
    <a href = "main.html"><button class="btn btn-link"> Go to home </button></a>
    
    </body>
</html>