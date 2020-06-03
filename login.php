<?php

require_once 'config.php';
$redirect_uri = 'https://' . $_SERVER['HTTP_HOST'] . '/oauth2callback.php';
header('Location: ' . filter_var($redirect_uri, FILTER_SANITIZE_URL));

?>