<? // Last accessed: 2020-04-23 - AJ P.

$xref = $site; set_xref($xref); ma_site_config();
$head->title = "Members Area";
$t4cache = $GLOBALS['debug'] ? time() : floor(time()/60);
$head->css = "css/shared/stylesheet.css?v=$t4cache" ;
$head->more .= "
	<meta name='viewport' content='width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0, viewport-fit=cover' />
	<link rel='stylesheet' type='text/css' href='css/shared/glyphs/styles.min.css'>
    <link rel='stylesheet' type='text/css' href='css/mempremium/style.css?v=$t4cache'>\n".
    ( $index['site_config']['dark_theme'] ? "<link rel='stylesheet' type='text/css' href='css/mempremium/dark.css?v=$t4cache'>" : '' )."\n"."
    <link rel='stylesheet' type='text/css' href='css/$xref/theme.css?v=$t4cache'>
	<script src='/js/flocdates/mempremium.js?v=$t4cache'></script>
";

// Adding genre specific ID to body tag if genre is not Adult
if($index['site_config']['genre']!='Adult') {
	$pos = strpos($head->body, 'body') + 4;
	$genre = strtolower($index['site_config']['genre']);
	$head->body = substr_replace($head->body, " id='$genre-site'", $pos, 0);
}

// Only add Chrome extension script to allowed IPs and using Chrome browser
if (strstr(' 209.151.233.21 ', $_SERVER['REMOTE_ADDR']) && strstr($_SERVER['HTTP_USER_AGENT'], 'Chrome')) {
	$head->more .= "
		<script>
		chrome.runtime.sendMessage( 'obccoeelbicfeeeknhipehljmohgjmmo', { debug: ".$GLOBALS['debug']." });
		</script>
	";
}

function ma_site_config() {

	global $site,$index,$head;
	$mode = $GLOBALS['mode'];
	$page = (isset($_GET['page'])?htmlentities($_GET['page']):'');

	if(isset($index['site_config'])) return;
	
	$paid = (isset($GLOBALS['dat']['unlimited'])?$GLOBALS['dat']['unlimited']:0);

	// Get the xref
	$xref = $site; set_xref($xref);

	//-----------------------------------------------------------------------------------------//
	//------------------------- CONFIGURATION SETTINGS BASED ON XREF --------------------------//
	//-----------------------------------------------------------------------------------------//
	
	// Adult Game Passes

	if($xref=='adultgame') {

		$genre = "games";

	// BBC Bunnies

	} elseif($xref=='bbcbunnies') {

		$genre = "black";
		$dark_theme = 1;

	// CamSexHookup

	} elseif ($xref=='camsexhookup') {

		$sliders = [
			325 => "4K Porn",
			31 	=> "Teen",
			22 	=> "MILF",
			20 	=> "Rough",
			326 => "Gamer Girls"
		];
		$ls_heading = 'Live on Cam Now';
		$ls_rows = 6;

	// Cutie GFs

	} elseif ($xref=='cutiegfs') {

		$sliders = [
			31 	=> "Destroyed Teens",
			41 	=> "Asian Tiny Teens",
			265 => "Lesbian Teens",
			284	=> "Ebony Teens"
		];
		$messages = [
			'See these cute <strong>Ex-Girlfriends Fucked</strong> in their first videos!',
			'Enter our massive archive of <strong>tight pussy</strong> porn collection!',
			'See these <strong>Social Media Sluts</strong> exposed on video!',
			'Click here to see more <strong>Cutie Ex-Girlfriends</strong>!'
		];

	// Nude Gamer

	} elseif ($xref=='nudegamer') {

		$originals_title = 'Gamer Girls';
		$sliders = [
			324 => "Gamer Girls",
			325	=> "4K Porn"
		];
		$ls_rows = 6;

	// Trans D

	} elseif ($xref=='transd') {
		
		$genre = "trans";

	}

	//-----------------------------------------------------------------------------------------//
	//------------------------- CONFIGURATION SETTINGS BASED ON GENRE -------------------------//
	//-----------------------------------------------------------------------------------------//

	if(!empty($genre)) {

		if(empty($content_type)) $content_type = 'genre';

		// Games

		if($genre=='games') {

			if(empty($nav_menu)) $nav_menu = [
				'Home' 				=> [ 'home', 'home' ],
				'Search Games'		=> [ 'games', 'gamepad-alt' ],
				'Categories' 		=> [ 'categories', 'list' ],
				'Adult Videos' 		=> [ 'videos', 'film' ],
				'Live Adult Cams'	=> [ 'cams', 'video' ],
				'My Lists' 			=> [ 'my-lists', 'star' ]
			];
		
			if(empty($search_menu)) $search_menu = [
				'Games' 			=> [ 'games', 'gamepad-alt', '?page=games' ],
				'Adult Videos' 		=> [ 'videos', 'play-circle', '?page=videos' ],
				'Pornstars' 		=> [ 'pornstars', 'star', '?page=pornstars' ],
				'Bonus Movies' 		=> [ 'film', 'film', '?page=bonus-movies' ],
				'Photos' 			=> [ 'photos', 'images', '?page=photos' ],
				'Cam Models' 		=> [ 'cams', 'video', '?page=cams' ],
				'Members' 			=> [ 'members', 'profile-female', '?page=search-members' ]
			];

			if(empty($messages)) $messages = 0;
			if(empty($originals_title)) $originals_title = 'Premium Games';
			if(empty($originals_type)) $originals_type = 'Premium';

		// Trans

		} elseif ($genre=='trans') {

			// Nav Menu Items => [0]=page, [1]=icon
			if(empty($nav_menu)) $nav_menu = [
				'Home'          => [ 'home', 'home' ],
				'Search Videos' => [ 'videos', 'search' ],
				'Pornstars'     => [ 'pornstars', 'star' ],
				'Bonus Movies'  => [ 'bonus-movies', 'film' ],
				'Photos'        => [ 'photos', 'images' ],
				'Live Cams'     => [ 'cams', 'video' ],
				'My Lists'      => [ 'my-lists', 'star' ]
			];

			if(empty($sliders)) $sliders = [
				307 => "Pretty Lady Boys",
				308 => "Shemale Latin Lovers",
				309 => "BBW Shemales",
				310 => "Trantastic Threesomes",
				311 => "Tattooed TS Girls",
				312 => "SheMilf Seduction",
				313 => "Fetish Gender Benders",
				314 => "Blonde T-Girl Babes",
				315 => "Shemale On Shemale",
				316 => "Shemale's In Charge",
				317 => "Brunette Babes With Boners",
				319 => "Bare Back Babes With Balls",
				320 => "TS Thai Twigs",
				321 => "Dream Wiener"
			];

			if(empty($header_ctas)) $header_ctas = [
				[ "PETITE HOT SHEMALES", "<i>See innocent cuties</i> in hardcore videos" ],
				[ "TIGHT NEW HOT SHEMALES", "Access <i>our massive videos archive</i> now!" ],
				[ "<b>SHEMALES</b> EXPOSED", "<i>Petite whores</i> fucking on video" ],
				[ "CLICK HERE FOR", "FREE ACCESS" ]
			];

			if(empty($messages)) {
				$messages = [
					'Watch these <strong>sexy shemales</strong> take throbbing cocks!',
					'See our <strong>naughty trannies</strong> bathe in cum!',
					'Our tgirls <strong>love getting pounded</strong> in their gaping holes!',
					'These <strong>shemales</strong> know just what you need!'
				];
			}

			if(empty($footer_cta)) $footer_cta = [
				'see more cute shemales now!',
				'CLICK HERE FOR',
				'FREE ACCESS'
			];
		}
	}

	//-----------------------------------------------------------------------------------------//
	//---------------------------------------- DEFAULTS ---------------------------------------//
	//-----------------------------------------------------------------------------------------//

	// Used to control the type of content to display on certain pages throughout the site
	// Example: Step lander on free accounts, video background on subscribe page
	if(empty($content_type)) $content_type = 'default';

	// Nav Menu Items => [0]=page, [1]=icon
	if(empty($nav_menu)) $nav_menu = [
		'Home'          => [ 'home', 'home' ],
		'Search Videos' => [ 'videos', 'search' ],
		'Categories'    => [ 'categories', 'list' ],
		'Pornstars'     => [ 'pornstars', 'star' ],
		'Bonus Movies'  => [ 'bonus-movies', 'film' ],
		'Photos'        => [ 'photos', 'images' ],
		'Live Cams'     => [ 'cams', 'video' ],
		'My Lists'      => [ 'my-lists', 'star' ]
	];

	// Search Menu Items => [0]=data-type, [1]=icon, [2]=link
	if(empty($search_menu)) $search_menu = [
		'Videos'        => [ 'videos', 'play-circle' ],
		'Pornstars'     => [ 'pornstars', 'star' ],
		'Bonus Movies'  => [ 'movies', 'film' ],
		'Photos'        => [ 'photos', 'images' ],
		'Cam Models'    => [ 'cams', 'video' ],
		'Members'       => [ 'members', 'profile-female', '?page=search-members&searching=1' ]
	];

	// Site Settings
	if(empty($genre)) $genre = $index['site'][$site]['genre'];
	if(empty($dark_theme)) $dark_theme = 0;

	// Featured Live Stars
	if(empty($ls_heading)) $ls_heading = 'Live Stars of the Hour';
	if(empty($ls_rows)) $ls_rows = 1;

	// Sliders
	if(empty($originals_title)) $originals_title = 'Originals';
	if(empty($originals_type)) $originals_type = 'Original';
	if(empty($sliders)) $sliders = [
		325 => "4K Porn",
		31 	=> "Teen",
		22 	=> "MILF",
		20 	=> "Rough"
	];

	// Free Home Page - Header CTAs => [0]=top, [1]=bottom, <i>=highlight, <b>=black font color
	if(empty($header_ctas)) $header_ctas = [
		[ "PETITE HOT GIRLS", "<i>See innocent cuties</i> in hardcore videos" ],
		[ "TIGHT NEW HOT GIRLS", "Access <i>our massive videos archive</i> now!" ],
		[ "<b>HOT GIRLS</b> EXPOSED", "<i>Petite whores</i> fucking on video" ],
		[ "CLICK HERE FOR", "FREE ACCESS" ]
	];

	// Free Home Page - Messages displayed between each set of thumbnails
	if(!isset($messages)) $messages = [
		'See these cute <strong>girls getting fucked</strong> in their first videos!',
		'Enter our massive archive of <strong>tight pussy</strong> porn collection!',
		'See these <strong>Social Media Sluts</strong> exposed on video!',
		'Click here to see more <strong>cute girls</strong>!'
	];

	// Free Home Page - Footer CTA
	if(empty($footer_cta)) $footer_cta = [
		'see more cute girls now!',
		'CLICK HERE FOR',
		'FREE ACCESS'
	];

	// Hiding "Pornstars" page from free accounts
	if(!$paid) {
		unset($nav_menu['Pornstars']);
		unset($search_menu['Pornstars']);
	}

	//-----------------------------------------------------------------------------------------//
	//-------------------------------------- ADD TO INDEX -------------------------------------//
	//-----------------------------------------------------------------------------------------//	

	// Global Settings
	$index['site_config']['nav_menu'] 					= $nav_menu;
	$index['site_config']['search_menu'] 				= $search_menu;
	$index['site_config']['genre'] 						= $genre;
	$index['site_config']['dark_theme']					= $dark_theme;
	$index['site_config']['content_type'] 				= $content_type;

	// Home Page

	if($mode=='home' || stristr($page,'members')) {

		if($paid) {
			$index['site_config']['ls_heading'] 		= $ls_heading;
			$index['site_config']['ls_rows'] 			= $ls_rows;
			$index['site_config']['originals_title']	= $originals_title;
			$index['site_config']['originals_type']		= $originals_type;
			$index['site_config']['sliders'] 			= $sliders;
		} else {
			$index['site_config']['header_ctas'] 		= $header_ctas;
			$index['site_config']['messages'] 			= $messages;
			$index['site_config']['footer_cta'] 		= $footer_cta;
		}
		
	}
	elseif ($mode=='gifts') $head->body ='<body class="gifts">';
	elseif ($mode=='join/upd_card') $head->body ='<body class="upd_card">';
	elseif ($mode=='join/upd_card3') $head->body ='<body class="upd_card3">';
	elseif ($mode=='join/upgd_action') $head->body ='<body class="upgd_action">';
}

function csv_to_json($csv) {
    if(file_exists($csv)) {
		$thumbs = array_map('str_getcsv', file($csv));
		$thumbs[0] = preg_replace('/[\x00-\x1F\x80-\xFF]/', '', $thumbs[0]);
        array_walk($thumbs, function(&$a) use ($thumbs) {
            $a = array_combine($thumbs[0], $a);
        });
		array_shift($thumbs);
		$ids=[];
		for ($i = 0; $i < count($thumbs); $i++) {
			if (!empty($thumbs[$i]['id']) || $i < intval($thumbs[$i]['id'])) $ids[] = intval($thumbs[$i]['id']);
			else $ids[] = $i;
		}
		$thumbs = array_combine($ids,$thumbs);
        return $thumbs;
    } else return [];
}

// CTA that displays at the top of some free pages
function cta($free=-1,$place='mid') {
    if ($free) { ?>
        <div class="<?= ($place=='top'?'cta-wrapper top':'cta-wrapper') ?>">
            <button href="?page=subscribe&ref=play_video" class="cta-button btn-lander-trigger">
                Click here for
                <span class="access primary-color">free unlimited access</span>
                <div class="drop-shadow secondary-bg-color"></div>
                <div class="brand-icon"></div>
            </button>
        </div>
    <? }
}

function data_from_csv($a=[]) {

	$data = $a['data'];
	$csv = $a['csv'];

	if(file_exists($csv)) {

		$data = str_replace('["', '', $data);
		$data = str_replace('"]', '', $data);
		$data = explode('","', $data);

		$array = [];
		$array_keys = ['vid','title','thumbnail','views','length','up_down','jpg','desc'];

		foreach ($data as $key => $value) {
			$b = explode('|', $value);
			foreach ($b as $k => $i) {
				$array[$b[0]][$array_keys[$k]] = $i;
			}
		}
		unset($key); unset($value);

		// Sorting the data by order in CSV

		$array_ids=[];
		if($f=fopen($csv,'r')) {
			while($r=fgets($f,1024)) if ($r>0) $array_ids[]=intval(trim($r));
			fclose($f);
		}

		$result = [];
		foreach ($array_ids as $key => $value) {
			$result[$value] = $array[$value];
		}
		unset($key); unset($value);

	} else {
		$result = 0;
		echo "<p style='background-color:#c00;color:#FFF;text-align:center;font-weight:bold;padding:20px;'>The CSV Does Not Exist</p>";
	}

	return $result;
}

function find_existing_file($filename) {
	global $site, $index;

	// Get the xref
	$xref = $site; set_xref($xref);

	$path = INC_PATH."/inc/$site/helpers/files";

	// 1. This function will look for a custom file in a folder named by xref
	$file_check = $path . "/$xref/" . $filename;
	if(file_exists($file_check)) return [ 'url' => $file_check, 'type'	=> 'xref' ];

	// 2. If a file does not exist, it will search in a folder named by genre
	$file_check = $path . "/".strtolower($index['site_config']['genre'])."/" . $filename;
	if(file_exists($file_check)) return [ 'url' => $file_check, 'type'	=> 'genre' ];

	// 3. If a file does not exist, it will search the /default/ folder
	$file_check = $path . "/default/" . $filename;
	if(file_exists($file_check)) return [ 'url' => $file_check, 'type'	=> 'default' ];

	// 4. If no files exist, return 0
	return 0;
}

function svg_profile_photo($image,$alt="Photo",$string=0) {
    $no_photo = strstr($image, 'no_photo');
    if($string) {
        $svg = "<svg id='no-photo' class='svg-no-photo' viewBox='0 0 260 260'><title>no-photo</title><path d='M82.5,199.8c-1.5,3-1.6,3.5-2.2,4.2c-0.5,0.7-27.1,11.5-65.5,30.5C7.7,238.2,3.3,240.2,0,242v18h260v-18 c-3.3-1.8-7.7-3.9-14.9-7.4c-38.3-19-64.9-29.8-65.5-30.5c-0.5-0.7-0.7-1.2-2.2-4.2s-3.4-7.1-3.7-9.4c-0.6-4.3,0.2-5-0.5-6.8 c-0.5-1.4-5.8-1.6-6.3-2.4c-0.2-0.4-2.6-19.6-2.4-20.9c0.2-1.3,9.7-14.6,12-30.6c0,0,2.4,0.8,3.6-0.9s5.5-10,6.6-20.3 c1.1-9.6,1-14.3-4.6-13.2c0,0,3.1-4.9,5.1-13.9c2-9,2.8-19.8,1.1-26.7c-2.3-9-7.6-13.5-12.9-21.3c-5.7-8.4-9.6-11.9-12.1-13.6 c-5.8-3.9-14.4-7.7-30.1-7.7c-15.7,0-23.2,4.4-26.8,6.7c-5.4,3.4-11,9.6-14.3,13c-3.3,3.3-8.1,5.3-10.9,5.9 c-2.8,0.5-7.6-0.6-8.5-0.5S71.3,47.9,71,55.1c-0.4,7.1,0.9,17.5,2.9,26.4c2,9,3.9,13.9,3.9,13.9c-5.6-1.1-5.7,3.6-4.6,13.2 c1.1,10.3,5.5,18.6,6.6,20.3c1.1,1.7,3.6,0.9,3.6,0.9c2.3,16,11.8,29.3,12,30.6c0.2,1.3-2.2,20.5-2.4,20.9c-0.5,0.8-5.8,1-6.3,2.4 c-0.6,1.8,0.1,2.4-0.5,6.8C85.9,192.7,84,196.8,82.5,199.8z'/></svg>";
        return "<div class='photo-wrap new-photo-wrap circle".($no_photo?' no-profile-photo':'')."'><div class='content'>".( $no_photo ? $svg : "<div class='profile-photo' style='background-image:url($image);' alt='$alt'></div>" )."</div></div>";
    } else {
        ?>
            <div class="photo-wrap new-photo-wrap circle<?= $no_photo ? ' no-profile-photo' : '' ?>">
                <div class="content">
                    <? if ($no_photo) { ?>
                        <svg id='no-photo' class='svg-no-photo' viewBox='0 0 260 260'><title>no-photo</title><path d='M82.5,199.8c-1.5,3-1.6,3.5-2.2,4.2c-0.5,0.7-27.1,11.5-65.5,30.5C7.7,238.2,3.3,240.2,0,242v18h260v-18 c-3.3-1.8-7.7-3.9-14.9-7.4c-38.3-19-64.9-29.8-65.5-30.5c-0.5-0.7-0.7-1.2-2.2-4.2s-3.4-7.1-3.7-9.4c-0.6-4.3,0.2-5-0.5-6.8 c-0.5-1.4-5.8-1.6-6.3-2.4c-0.2-0.4-2.6-19.6-2.4-20.9c0.2-1.3,9.7-14.6,12-30.6c0,0,2.4,0.8,3.6-0.9s5.5-10,6.6-20.3 c1.1-9.6,1-14.3-4.6-13.2c0,0,3.1-4.9,5.1-13.9c2-9,2.8-19.8,1.1-26.7c-2.3-9-7.6-13.5-12.9-21.3c-5.7-8.4-9.6-11.9-12.1-13.6 c-5.8-3.9-14.4-7.7-30.1-7.7c-15.7,0-23.2,4.4-26.8,6.7c-5.4,3.4-11,9.6-14.3,13c-3.3,3.3-8.1,5.3-10.9,5.9 c-2.8,0.5-7.6-0.6-8.5-0.5S71.3,47.9,71,55.1c-0.4,7.1,0.9,17.5,2.9,26.4c2,9,3.9,13.9,3.9,13.9c-5.6-1.1-5.7,3.6-4.6,13.2 c1.1,10.3,5.5,18.6,6.6,20.3c1.1,1.7,3.6,0.9,3.6,0.9c2.3,16,11.8,29.3,12,30.6c0.2,1.3-2.2,20.5-2.4,20.9c-0.5,0.8-5.8,1-6.3,2.4 c-0.6,1.8,0.1,2.4-0.5,6.8C85.9,192.7,84,196.8,82.5,199.8z'/></svg>
                    <? } else { ?>
                        <div class='profile-photo' style='background-image:url(<?=$image?>);' alt='<?= $alt ?>'></div>
                    <? } ?>
                </div>
            </div>
        <?
    }
}

// Title Area - START
function convert_columns($arr){
	$ret=[];
	foreach($arr as $k) {
		$ex=explode(':',$k);
		$ret[]=['id'=>$ex[0],'name'=>$ex[1]];
	}
	return $ret;
}
function titleArea($page_title) {
	global $site;
	$search=$filter = '';
	$categories	 = [];
	$top_categories = [];
	$paid=$GLOBALS['dat']['unlimited'];
	$ref='play_video';
	inc('vids/XXXvid_common.inc');
	if(isset($_GET['page']))	$page = htmlentities($_GET['page']);
	if(isset($_GET['search']))  $search = str_replace('+', ' ', htmlentities($_GET['search']));
	if(isset($_GET['name'])) 	$search = str_replace('+', ' ', htmlentities($_GET['name']));
	if(isset($_GET['tag']))     $search = str_replace('+', ' ', htmlentities($_GET['tag']));
	if(isset($_GET['filter']))  $filter = htmlentities($_GET['filter']);
	elseif(isset($_GET['cat'])) $filter = htmlentities($_GET['cat']);

	$toggle_filter_disabled_pages = ' my-lists cams ';
	$toggle_filter_enabled = strstr($toggle_filter_disabled_pages, $page) ? 0 : 1;

	$button_filter_disabled_pages = ' cams search-members ';
	$button_filter_enabled = strstr($button_filter_disabled_pages, $page) ? 0 : 1;

	if($search || $filter) $dropdown = "true";
	else $dropdown = "false";

	if( $page === 'my-lists') $list = array( "Watchlist", "History", "Liked");
	else {
		$list = array("Featured","Newest","Top Rated","Most Viewed");
		$categories[] = array(
			"id" => "mvid",
			"name" => "Members Videos"
		);
		if(@$_GET['page']=='photos'){
			$ref='photos';
			$top_categories=convert_columns(explode(',',
				"23:Cum Shots,13:Blow Jobs,89:Reality,69:Masturbation,16:Big Ass,24:Curvy,86:Pornstars,61:Latin,115:Voyeur,135:Blonde,34:Fantasies,117:Gonzo-POV,93:Small Breasts,".
				"14:Big Breasts,31:Exhibition,139:Panties,104:Teen,136:Brunette,1:Amateur,71:Natural Breasts,147:Solo,140:Petite,142:ExGirlFriend,20:College Coeds"));
			$categories=convert_columns(explode(',',
				"73:Nurse,62:Leather,141:Editors Picks,144:3D Toon,132:Dildos,153:Massage,".
				"157:Emo,96:Spanking,114:Virgins,94:Smoking,143:Ladyboy,91:Sex Toys,152:Office,8:BDSM,21:Creampie,22:CrossDressing,37:Feet,58:Interracial,131:Uniform,126:No nudity,".
				"3:Anime - Hentai,63:Legs,38:Fetish,156:Yoga,154:Gym,7:BBW,29:European,64:Lesbian,105:Threesomes,76:Orgies,45:Games - Sports,99:Spring Break,".
				"133:Bareback,4:Asian,11:Black,50:Hairy,70:Mature,33:Facials,90:Red Heads,2:Anal,56:MILF,124:Big Cock,138:Handjob,101:Hardcore,88:Pussy,92:Shaving,".
				"23:Cum Shots,13:Blow Jobs,89:Reality,69:Masturbation,16:Big Ass,24:Curvy,86:Pornstars,61:Latin,115:Voyeur,135:Blonde,34:Fantasies,117:Gonzo-POV,93:Small Breasts,".
				"14:Big Breasts,31:Exhibition,139:Panties,104:Teen,136:Brunette,1:Amateur,71:Natural Breasts,147:Solo,140:Petite,142:ExGirlFriend,20:College Coeds"));
		} elseif(@$_GET['page']=='bonus-movies'){
			$top_categories=convert_columns(explode(',',
				'136:Brunette,71:Natural Breasts,101:Hardcore,140:Petite,14:Big Breasts,20:College Coeds,135:Blonde,13:Blow Jobs,23:Cum Shots,24:Curvy,33:Facials,'.
				'69:Masturbation,124:Big Cock,138:Handjob,93:Small Breasts,34:Fantasies,86:Pornstars,56:MILF,88:Pussy,2:Anal,31:Exhibition,16:Big Ass,115:Voyeur,104:Teen'));
			$categories=convert_columns(explode(',',
				'136:Brunette,71:Natural Breasts,101:Hardcore,140:Petite,14:Big Breasts,20:College Coeds,135:Blonde,13:Blow Jobs,23:Cum Shots,24:Curvy,33:Facials,69:Masturbation,'.
				'124:Big Cock,138:Handjob,93:Small Breasts,34:Fantasies,86:Pornstars,56:MILF,88:Pussy,2:Anal,31:Exhibition,16:Big Ass,115:Voyeur,104:Teen,1:Amateur,139:Panties,'.
				'61:Latin,91:Sex Toys,105:Threesomes,29:European,90:Red Heads,64:Lesbian,132:Dildos,58:Interracial,117:Gonzo-POV,89:Reality,11:Black,4:Asian,142:ExGirlFriend,'.
				'38:Fetish,96:Spanking,50:Hairy,21:Creampie,99:Spring Break,147:Solo,25:Double Penetration,70:Mature,131:Uniform,8:BDSM,7:BBW,152:Office,109:Tranny-Shemale,'.
				'76:Orgies,62:Leather,37:Feet,119:Squirting,47:Gay,134:Strap-On,137:Cum Swap,149:The Punishment Zone,133:Bareback,46:Gangbang,63:Legs,153:Massage,45:Games - Sports,'.
				'143:Ladyboy,156:Yoga,154:Gym,130:Twink,73:Nurse,157:Emo,79:Peeing,19:Cheerleaders,94:Smoking,146:Fat,125:Instructional,129:Bear,10:BI-Sexual,123:Interactive,'.
				'114:Virgins,92:Shaving,113:Vintage Porn,126:No nudity'));
		} elseif(@$_GET['page']=='games'){
			$categories=$top_categories=convert_columns(explode(',',
				'3:Action Games,4:Action Junkies,33:Adult Games,5:Arcade,6:Arcade Games,28:Awesome Games,26:Battle Babes,7:Board and Puzzle,8:Bouncing Ball,9:Card and Strategy,'.
				'10:Card Games,37:Casual Adult Games,11:Casual Games,12:Connect and Match,13:Educational,29:Forge of Empires Bonus Games,31:Gay Fuck Super Heroes,32:Hentai Games,'.
				'14:HTML5 Games,15:Maths and Science,16:Multiplayer,17:Multiplayer Games,18:Puzzle Games,19:Shoot or Throw,'.
				'20:Sport and Hobby,21:Sports Games,22:Strategy Games,30:Super Fuck Heroes,23:Virtual Reality,27:War Games,24:Whack and Smack,25:Word Games'));
		} elseif(@$_GET['page']=='pornstars'){
			$top_categories=[
				['id'=>"age.20's",					'name'=>'<b>Age</b> 20\'s' ],				['id'=>"age.mature",		'name'=>'<b>Age</b> Mature' ],
				['id'=>"age.MILF",					'name'=>'<b>Age</b> MILF' ],				['id'=>"age.teen",			'name'=>'<b>Age</b> Teen' ],
				['id'=>"bodyType.athletic",			'name'=>'<b>Body Type</b> Athletic' ],		['id'=>"bodyType.BBW",		'name'=>'<b>Body Type</b> BBW' ],
				['id'=>"bodyType.curvy",			'name'=>'<b>Body Type</b> Curvy' ],			['id'=>"bodyType.petite",	'name'=>'<b>Body Type</b> Petite' ],
				['id'=>"breastSize.A cup",			'name'=>'<b>Breast Size</b> A cup' ],		['id'=>"breastSize.B cup",	'name'=>'<b>Breast Size</b> B cup' ],
				['id'=>"breastSize.C cup",			'name'=>'<b>Breast Size</b> C cup' ],		['id'=>"breastSize.D cup",	'name'=>'<b>Breast Size</b> D cup' ],
				['id'=>"breastSize.DD+ cup",		'name'=>'<b>Breast Size</b> DD+ cup' ],		['id'=>"breastType.enhanced",'name'=>'<b>Breast Type</b> Enhanced' ],
				['id'=>"breastType.natural",		'name'=>'<b>Breast Type</b> Natural' ],		['id'=>"ethnicity.asian",	'name'=>'<b>Ethnicity</b> Asian' ],
				['id'=>"ethnicity.black",			'name'=>'<b>Ethnicity</b> Black' ],			['id'=>"ethnicity.european",'name'=>'<b>Ethnicity</b> European' ],
				['id'=>"ethnicity.exotic",			'name'=>'<b>Ethnicity</b> Exotic' ],		['id'=>"ethnicity.latin",	'name'=>'<b>Ethnicity</b> Latin' ],
				['id'=>"ethnicity.middle eastern",	'name'=>'<b>Ethnicity</b> Middle Eastern'],	['id'=>"ethnicity.white",	'name'=>'<b>Ethnicity</b> White' ],
				['id'=>"eyeColor.blue",				'name'=>'<b>Eye Color</b> Blue' ],			['id'=>"eyeColor.brown",	'name'=>'<b>Eye Color</b> Brown' ],
				['id'=>"eyeColor.dark brown",		'name'=>'<b>Eye Color</b> Dark Brown' ],	['id'=>"eyeColor.green",	'name'=>'<b>Eye Color</b> Green' ],
				['id'=>"eyeColor.hazel",			'name'=>'<b>Eye Color</b> Hazel' ],			['id'=>"gender.female",		'name'=>'<b>Gender</b> Female' ],
				['id'=>"gender.male",				'name'=>'<b>Gender</b> Male' ],				['id'=>"gender.TV / TG",	'name'=>'<b>Gender</b> TV / TG' ],
				['id'=>"hairColor.black",			'name'=>'<b>Hair Color</b> Black' ],		['id'=>"hairColor.blonde",	'name'=>'<b>Hair Color</b> Blonde' ],
				['id'=>"hairColor.brunette",		'name'=>'<b>Hair Color</b> Brunette' ],		['id'=>"hairColor.red",		'name'=>'<b>Hair Color</b> Red' ],
				['id'=>"hairColor.shaved",			'name'=>'<b>Hair Color</b> Shaved' ],		['id'=>"pussyType.groomed",	'name'=>'<b>Pussy Type</b> Groomed' ],
				['id'=>"pussyType.hairy",			'name'=>'<b>Pussy Type</b> Hairy' ],		['id'=>"pussyType.shaved",	'name'=>'<b>Pussy Type</b> Shaved' ],
				['id'=>"modelType.amateur",			'name'=>'<b>Model Type</b> Amateur' ],		['id'=>"modelType.newbie",	'name'=>'<b>Model Type</b> Newbie' ],
				['id'=>"modelType.pornstar",		'name'=>'<b>Model Type</b> Pornstar' ]
			];
		} else {
			$xref = $site;
			if(isset($GLOBALS['dat']['xref']) && $p=strpos($GLOBALS['dat']['xref'],'|'))
				if($p>4) $xref=substr($GLOBALS['dat']['xref'],0,$p);
			$q = "select n.record_num, n.name
				from niches n join nicheCategories_niches nc_n on nc_n.nicheID = n.record_num
				join nicheCategories nc on nc_n.nicheCatID = nc.nicheCatID
				where (categoryID is null or categoryID in ".(strstr($xref,'transd')?'(4)':'(1,3,9)').
				") and enabled>0 and totalVideos > 5 order by n.name";
			$selected_categories = [2, 4, 8, 124, 14, 11, 13, 20, 21, 141, 142, 33, 38, 46, 101, 61, 64, 56, 71, 76, 140, 104, 131, 114 ];
			if(strstr($xref,'transd')) $selected_categories = [ 2, 4, 109, 124, 14, 11, 13, 20, 21, 141, 142, 33, 38, 46, 101, 61, 64, 56, 71, 76, 140, 104, 131, 114 ];

			if ($res = myq($q)) {
				while($r = m_fetch_assoc($res)) {
					$categories[] = array(
						"id" => $r['record_num'],
						"name" => $r['name']
					);

					if (in_array($r['record_num'], $selected_categories)) { // $top_categories[$r['record_num']]= $r['name']
						$top_categories[] = array(
							"id" => $r['record_num'],
							"name" => $r['name']
						);
					}
				}
			}
		}
	}
	$cln_top_cat=[];
	foreach($top_categories as $arr) $cln_top_cat[$arr['id']]=$arr['name'];
	$cln_top_cat=json_encode($cln_top_cat);
	?>
	<div class="container">
		<div class="row-v7 c1-across margin-top-40 margin-bottom-20 search-header btablet">
			<div class="column">
				<h2 class="header-text">
				<? if ( $page === "my-lists" ) { ?>
					<span class="tab-name">&nbsp;</span>
				<? } else {
					if($search) {
						echo $search;
						?>
						<div class="results-wrapper">
							<span class="results">No results</span>
							<a class="clear-results" href="?page=<?=$page?>">
								<svg class="icon-times-circle primary-fill">
									<use xlink:href="#times-circle"></use>
								</svg>
							</a>
						</div>
					<? } else {
						echo $page_title;
						if ($toggle_filter_enabled) {
						?>
							<a href="#" class="btn-filter-toggle">
								<i class="fas fa-filter">
									<svg class="icon-filter primary-fill">
										<use xlink:href="#filter"></use>
									</svg>
								</i>
							</a>
						<? }
					}
				} ?>
				</h2>
			</div>
		</div>
	</div>
	<? if ($toggle_filter_enabled) {
		if( $page!='search-members' ) { ?>
			<div class="container filters-container">
				<div class="row-v7 margins-bottom portions-70-30">
					<div class="column">
						<h3 class="search-by-text"><?= $filter || strpos(' pornstars games',$page)? 'Categories': 'Top Categories'?>:</h3>
					</div>
					<div class="column text-right">
						<a href="#" class="filter-clear secondary-color">Clear Filters</a>
					</div>
				</div>
				<div class="tags-container active opacity">
					<div class="tags-list row-v7 margins-bottom c6-across"></div>
				</div>
				<div class="row-v7 c1-across">
					<div class="column text-right">
						<? if(!strpos(' games pornstars',$page)) { ?>
						<a href="#" class="btn-see-all primary-color active">See All</a>
						<? } ?>
						<div class="tags-chosen text-left"></div>
					</div>
				</div>
				<div class="filter-controls">
					<div class="row-v7 c1-across">
						<div class="column">
							<div class="filter-apply-cancel">
								<a href="#" class="btn-control filter-apply primary-bg-color">Apply</a>
								<a href="#" class="btn-control filter-cancel primary-bg-color">Cancel</a>
							</div>
						</div>
					</div>
				</div>
			</div>
		<? }
	}
	if($button_filter_enabled) { ?>
		<div class="container filter-sort-wrapper">
			<div class="row-v7 margin-top-20 margin-bottom-20 c1-tablet portions-60-40">
				<div class="column">
					<ul class="filter-buttons active">
						<?  foreach( $list as $key => $value ) { ?>
							<li><button class="btn-filter primary-bg-color primary-border-color btn-<?=strtolower(str_replace(" ", "-", $value)) ?><?= $key == 0 ? ' active' : '' ?>"><?=$value?></button></li>
						<? } ?>
					</ul>
				</div>
				<div class="column text-right">
					<div class="sort">
						<div class="filter">
							<a href="#" class="btn-filter-dropdown primary-bg-hover"><span class="filter-text">Newest</span> <i><svg><use xlink:href="#angle-down"></use></svg></i></a></a>
							<ul class="sort-list">
								<li><a href="#" class="filter-option primary-bg-hover">Newest</a></li>
								<li><a href="#" class="filter-option primary-bg-hover">Top Rated</a></li>
								<li><a href="#" class="filter-option primary-bg-hover">Most Viewed</a></li>
							</ul>
						</div>
					</div>
				</div>
			</div>
		</div>
	<? }
	if( $page != 'search-members' ) { ?>
		<script>
		$(function() {
			const   filterText = $(".filter-text"),
					sortList = $(".sort-list");
			var	 filterBy = filterText.text(),
					sortTimeout;
			var filter =<?=$filter?'true':'false'; ?>;
			function listVisibility() {
				if(sortList.hasClass("opacity")) {
					clearTimeout(sortTimeout);
					sortList.removeClass("opacity").removeClass("display");
					document.body.removeEventListener("click", listVisibility);
				}  else {
					sortList.addClass("display");
					sortTimeout = setTimeout(function() {
						sortList.addClass("opacity");
					}, 10);
				}
			};
			$(".btn-filter-dropdown").on("click", function(e) {
				e.preventDefault();
				document.body.addEventListener("click", listVisibility);
			});
			$(".filter-option").on("click", function(e) {
				e.preventDefault();
				var text = $(this).text().toLowerCase().replace(" ", "-");
				filterText.text($(this).text());
				filterBy = $(this).text();
				$(".filter-option").removeClass("active");
				$(this).addClass("active");
			});
			$(".btn-filter").on("mouseenter", function() {
				if(!$(this).hasClass("active")) $(this).addClass("hover");
			}).on("mouseleave",function(){
				if($(this).hasClass("hover")) $(this).removeClass("hover");
			}).on("click", function(e) {
				e.preventDefault();
				<? if($paid) { ?>
					if($(this).hasClass("hover")) $(this).removeClass("hover");
					$(".btn-filter").removeClass("active");
					$(this).addClass("active");
				<? } else { ?>
					self.location='?page=subscribe&ref=<?=$ref?>';
				<? } ?>
			});
			var categoriesAll = <?= json_encode(array_combine(array_column($categories, 'id'), array_column($categories, 'name'))); ?>,
				categoriesTop = <?= $cln_top_cat?>,
				<? if ($page == 'pornstars') echo "categoriesAll = categoriesTop,\n"; ?>
				filterIn = "<?= $filter ?>",
				filterOut = "top",
				filterType = '',
				tagsChosen = {},
				chosen,
				timeoutFiltersContainer,
				toggleActive = false,
				hasAdd = false,
				dropdown = <?=$dropdown?>,
				btnAddMore = $("<a href='#' class='btn-control filter-add-more primary-bg-hover'><svg class='primary-fill'><use xlink:href='#plus'></use></svg></a>"),
				page = "<?= $page ?>";
			function displayOptions(dropdown) {
				if(dropdown) {
					if($(".filter-buttons").hasClass("active")) $(".filter-buttons").removeClass("active");
					$(".sort").addClass("active");
				} else {
					if($(".sort").hasClass("active")) $(".sort").removeClass("active");
					$(".filter-buttons").addClass("active");
				}
			}
			displayOptions(dropdown);
			function initializeChosen(filterIn) {
				filterIn = filterIn.split(",");
				toggleActive = true;
				hasAdd = true;
				$(".tags-container").removeClass("active opacity");
				$(".btn-see-all").removeClass("active");
				$(".filters-container, .filter-clear").addClass("active");
				$(".btn-filter-toggle").hide();
				setTimeout(function(){
					$(".filters-container").addClass("opacity");
				},10);
				filterType = filterIn[0];
				for (var i = 1; i < filterIn.length; i++) {
					id = filterIn[i];
					tagsChosen[id] = categoriesAll[id];
				}
				addTags(tagsChosen);
				createTags(filterType === 'top' ? categoriesTop : categoriesAll);
				$(".btn-see-all").text(filterType === 'top' ? "See All" : "Show Less");
				$(".tags-chosen").addClass("active").append(btnAddMore);
			}
			if(filterIn) initializeChosen(filterIn);
			else createTags(categoriesTop);
			function createTags(tags) {
				let o=[];
				$(".tags-list").empty();
				for (let i in tags) {
					o.push('<div rel="'+tags[i]+'" class="column"><a href=# class="add-tag' + ( tagsChosen.hasOwnProperty(i) ? " added": "" ) + ' secondary-color primary-hover" data-cat-id="' + i + '">' + tags[i] + '</a></div>');
				}
				o.sort(function(a,b){
					a=a.substr(10,20).toLowerCase();
					b=b.substr(10,20).toLowerCase();
					if(a>b) return 1; else if(b>a) return -1;
					return 0;
				});
				$(".tags-list").html(o.join(''));
			}
			function addTags(chosenTags) {
				$(".tags-chosen").empty();
				for (let i in chosenTags) {
					let tag = $('<a href="#" class="chosen-tag remove-tag secondary-bg-color" data-cat-id="' + i + '"><span class="vertical-align">' + chosenTags[i] + '</span><i class="fas fa-times-circle"><svg class="icon-times-circle"><use xlink:href="#times-circle"></use></svg></i></a>');
					$(".tags-chosen").append(tag);
				}
				if(hasAdd) $(".tags-chosen").append(btnAddMore);
			}
			$("body").on("click", ".btn-filter-toggle", function(e) {
				// Toggle filters
				e.preventDefault();
				clearTimeout(timeoutFiltersContainer);
				if(!toggleActive) {
					$(".filters-container").addClass("active");
					setTimeout(function(){
						$(".filters-container").addClass("opacity");
					},10);
					toggleActive = true;
				} else {
					$(".filters-container").removeClass("opacity");
					timeoutFiltersContainer = setTimeout(function(){
						$(".filters-container").removeClass("active");
					},400);
					toggleActive = false;
					displayOptions(dropdown);
				}
			}).on("click", ".add-tag", function(e) {
				// Choose tag
				e.preventDefault();
				if (!Object.keys(tagsChosen).length) {
					$(".filter-clear, .tags-chosen, .filter-controls, .filter-apply-cancel").addClass("active");
				}
				$(this).addClass("added");
				let id = $(this).data("cat-id");
				tagsChosen[id] = categoriesAll[id];
				addTags(tagsChosen);
			}).on("click", ".remove-tag", function(e) {
				let go_on=1;
				// Remove tag
				e.preventDefault();
				let id = $(this).data("cat-id");
				$('.add-tag[data-cat-id="' + id + '"]').removeClass("added");
				delete tagsChosen[id];
				if (!Object.keys(tagsChosen).length) {
					$(".tags-chosen, .filter-controls").removeClass("active");
					if(filter) {
						go_on=0;
						self.location='?page=<?=$page?>';
					} else {
						$(".tags-container").addClass("active");
						setTimeout(function(){
							$(".tags-container").addClass("opacity");
						},10);
						$(".btn-see-all").addClass("active");
						hasAdd = false;
						dropdown = false;
					}
				}
				if(go_on){
					$(this).addClass("opacity-hidden");
					setTimeout(function() {
						$('.chosen-tag[data-cat-id="' + id + '"]').remove();
						$(".filter-clear, .tags-chosen, .filter-controls, .filter-apply-cancel").addClass("active");
					},800);
				} else $('.chosen-tag[data-cat-id="' + id + '"]').remove();
			}).on("click", ".filter-clear", function(e) {
				// Clear tags
				e.preventDefault();
				$(this).removeClass("active");
				if(filter) {
					self.location='?page=<?=$page?>';
				} else {
					$(".tags-chosen").empty();
					tagsChosen = {};
					$(".tags-container, .btn-see-all").addClass("active");
					$(".tags-chosen, .filter-controls").removeClass("active");
					setTimeout(function(){
						$(".tags-container").addClass("opacity");
					},10);
					$(".add-tag").removeClass("added");
					hasAdd = false;
					dropdown = false;
				}
			}).on("click", ".filter-apply", function(e) {
				// Apply Filters
				e.preventDefault();
				<? if ($paid) { ?>
					if (Object.keys(tagsChosen).length) {
						for (let i in tagsChosen) {
							filterOut += ',' + encodeURIComponent(i);
						}
						self.location='?page=<?=$page?>&filter=' + filterOut;
					}
				<? } else { ?>
					self.location='?page=subscribe&ref=<?=$ref?>';
				<? } ?>
			}).on("click", ".filter-cancel", function(e) {
				// Cancel
				e.preventDefault();
				if(filter) {
					self.location='?page=<?=$page?>';
				} else {
					tagsChosen = {};
					$(".add-tag").removeClass("added");
					$(".filters-container").removeClass("opacity");
					setTimeout(function(){
						$(".filter-controls, .filters-container, .tags-chosen, .filter-controls").removeClass("active");
						$(".tags-chosen").empty();
					},400);
					toggleActive = false;
					if($(".btn-see-all").hasClass("active")) $(".btn-see-all").removeClass("active");
					hasAdd = false;
					dropdown = false;
					displayOptions(dropdown);
				}
			}).on("click", ".filter-add-more", function(e) {
				// Add more
				e.preventDefault();
				$(this).remove();
				$(".filter-controls, .tags-container, .filter-apply-cancel").addClass("active");
				setTimeout(function(){
					$(".tags-container").addClass("opacity");
				},10);
				if(!$(".btn-see-all").hasClass("active")) $(".btn-see-all").addClass("active");
				if(filterIn) {
					filterIn = filterIn.split(",");
					if( filterIn[0] === "top") {
						$(".search-by-text").text("Top Categories:");
					} else {
						$(".search-by-text").text("All Categories:");
					}
				}
			}).on("click", ".btn-see-all", function(e) {
				e.preventDefault();
				$(".filter-controls").removeClass("active");
				var text = $(this).text();
				$(".tags-chosen").empty();
				tagsChosen = {};
				if( text === "See All") {
					filterOut = "all";
					$(this).text("Show Less");
					$(".tags-container").addClass("show-all");
					$(".search-by-text").text("All Categories:");
					createTags(categoriesAll);
				} else {
					filterOut = "top";
					$(this).text("See All");
					$(".tags-container").removeClass("show-all");
					$(".search-by-text").text("Top Categories:");
					createTags(categoriesTop);
				}
			}).on("click",".btn-letter",function(e){
				e.preventDefault();

				if(toggleActive) {
					$(".filters-container").removeClass("opacity");
					timeoutFiltersContainer = setTimeout(function(){
						$(".filters-container").removeClass("active");
					},400);
					toggleActive = false;
					$(".tags-chosen").empty();
					tagsChosen = {};
					$(".tags-container, .btn-see-all").addClass("active");
					$(".tags-chosen, .filter-controls").removeClass("active");
					setTimeout(function(){
						$(".tags-container").addClass("opacity");
					},10);
					$(".add-tag").removeClass("added");
					hasAdd = false;
				}
				dropdown = false;
				displayOptions(dropdown);
			});
		});
		</script>
	<? }
}
// Title Area - END

if($GLOBALS['index']['site'][$site]['genre'] == 'Games'){
	function getGamesThumb($r){	// where $r is a join of content and games_meta tables
		$u  = 'https://mygamervault.com/';
		$fn = $r['file_name'];
		$fp = $r['feedProviderID'];
		$ar = ['13'=>"$u$fn", '10'=>"$u/games/thumbs/$fn.jpg", '11'=>"$u/games/images-165games/$fn.jpg"];
		if(isset($ar[$fp])) return $ar[$fp];
		if($fp==9){
			if (($r['gameCatID']==31 || $r['cat_id']==26) && is_numeric($fn) && intval($fn)<=28)
				return "$u/games/images-gay/small/$fn.jpg";
			return "$u/games/images-tiles/$fn.jpg";
		}
		return (strstr($r['feedThumb'],'http')?$r['feedThumb']:"$u{$r['feedThumb']}");
	}
	function filter_game($q,$cat){
		$a=[];
		$b=[];
		$len=count($cat);
		$min=1;
		if($len>=6) $min=5; elseif($len==5) $min=4;	elseif($len==4) $min=3;
		elseif($len>1) $min=2; // try to get us at least 2 or 3 or 4 depend on the selection
		if ($res = myq($q))	while($r = m_fetch_assoc($res)) {
			$ok=0;
			$c=",{$r['G']},";
			foreach($cat as $i) if(strstr($c,",$i,")) $ok++;
			if($ok>=$min) $a[]=(1000-$ok)."|{$r['record_num']}|{$r['title']}|{$r['views']}|".getGamesThumb($r);
			if($min>1 && $ok>=$min-1) $b[]=(1000-$ok)."|{$r['record_num']}|{$r['title']}|{$r['views']}|".getGamesThumb($r)."|$ok>=$min";
		}
		if(!$a) $a=$b;
		sort($a);
		$ret=[];
		foreach($a as $i) {
			$ex=explode('|',$i); array_shift($ex); $ret[]=implode('|',$ex);
		}
		return json_encode($ret);
	}
}
?>