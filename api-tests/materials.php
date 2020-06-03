<?php
/*
    parse.php

    MediaWiki API Demos
    Demo of `Parse` module: Parse content of a page

    MIT License
*/

$endPoint = "https://nookipedia.com/w/api.php";

$params = [
    "action"    => "parse",
    "page"      => "DIY",
    "section"      => 3,
    "format"    => "json"
];

$url = $endPoint . "?" . http_build_query( $params );

$ch = curl_init( $url );
curl_setopt( $ch, CURLOPT_RETURNTRANSFER, true );
$output = curl_exec( $ch );
curl_close( $ch );

$result = json_decode( $output, true );

echo( $result["parse"]["text"]["*"] );

?>


<!-- HTML4 and (x)HTML -->
<script type="text/javascript" src="./assets/js/jquery-3.5.1.min.js"></script>