<?php

// Start session
if(!session_id()) session_start();
$_SESSION['logged_in'] = 0;

require_once __DIR__.'/vendor/autoload.php';

$client = new Google_Client();
$client->setAuthConfig('client_secret.json');
$client->addScope('email');
$client->addScope('profile');
$client->addScope(Google_Service_Drive::DRIVE_APPDATA);
$client->addScope(Google_Service_Drive::DRIVE_FILE);
$client->setAccessType("offline");

