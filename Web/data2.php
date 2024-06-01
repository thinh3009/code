<?php
    if (isset($_POST['id'])) {
        $id = $_POST['id'];
    } else {
        $id = '';
    }

    if (isset($_POST['name'])) {
        $name = $_POST['name'];
    } else {
        $name = '';
    }

    if (isset($_POST['passw'])) {
        $passw = $_POST['passw'];
    } else {
        $passw = '';
    }

    if (isset($_POST['email'])) {
        $email = $_POST['email'];
    } else {
        $email = '';
    }

    if (isset($_POST['gt'])) {
        $gt = $_POST['gt'];
    } else {
        $gt = '';
    }

    if (isset($_POST['sothich'])) {
        $sothich = $_POST['sothich'];
    } else {
        $sothich = '';
    }

    if (isset($_POST['nation'])) {
        $nation = $_POST['nation'];
    } else {
        $nation = '';
    }

    if (isset($_POST['note'])) {
        $note = $_POST['note'];
    } else {
        $note = '';
    }

    //data base connect
    $conn= new mysqli('localhost','root','','web');
    if ($conn->connect_error){
        echo "$conn->connect_error";
        die('Connect error!! '.$conn->connect_error);
    }
    else{
        $stmt = $conn->prepare("insert into dangky(id, name, passw, email, gt, sothich, nation, note) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        $stmt->bind_param("sssssssi", $id, $name, $passw, $email, $gt, $sothich, $nation, $note);
        $stmt->execute();                
        echo 'Đăng ký thành công...........';
        $stmt->close();
        $conn->close();
    }
?> 