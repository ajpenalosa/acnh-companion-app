<?php

$link = '?';

$filter='all';
if (!empty($_GET['filter'])) $filter = htmlentities($_GET['filter']);

$sort='';
if (!empty($_GET['sort'])) $sort = htmlentities($_GET['sort']);

function csv_to_json($csv) {
    if(file_exists($csv)) {
		$thumbs = array_map('str_getcsv', file($csv));
		$thumbs[0] = preg_replace('/[\x00-\x1F\x80-\xFF]/', '', $thumbs[0]);
        array_walk($thumbs, function(&$a) use ($thumbs) {
            $a = array_combine($thumbs[0], $a);
        });
        $ids=[];
        $table_headers=$thumbs[0];
		array_shift($thumbs);
		for ($i = 0; $i < count($thumbs); $i++) {
			if (!empty($thumbs[$i]['id']) || $i < intval($thumbs[$i]['id'])) $ids[] = intval($thumbs[$i]['id']);
			else $ids[] = $i;
		}
		$thumbs = array_combine($ids,$thumbs);
        return [$table_headers,$thumbs];
    } else return [];
}

$diy_data = csv_to_json('./assets/csv/data.csv');

foreach ($diy_data[1] as $key => $value) {
    $diy_data[1][$key]['Sell Price'] = intval($value['Sell Price']);
}

if($filter=='aj') {
    $aj_data = [];
    foreach ($diy_data[1] as $key => $value) {
        if($value['AJ']==1) $aj_data[]=$value;
    };
    unset($key);
    unset($value);
    $diy_data[1] = $aj_data;
    $link.='filter='.$filter;
}

if($sort=='bells') {

    function sortByBells($a,$b) {
      return ($a['Sell Price'] <= $b['Sell Price']) ? 1 : -1;
    }
    usort($diy_data[1], 'sortByBells');

} elseif ($sort=='recipe') {

    function sortByRecipe($a,$b) {
      return ($a['Recipe'] <= $b['Recipe']) ? -1 : 1;
    }
    usort($diy_data[1], 'sortByRecipe');

}
?>
<div class="filter-buttons">
    <a href="?filter=all">All</a>
    <a href="?filter=aj">A.J.</a>
    <a href="?filter=faye">Faye</a>
</div>
<div class="data-table">
    <div class="table-header">
        <a class="th-name tc-recipe" href="<?=$link?>&sort=recipe">Recipe</a>
        <a class="th-name tc-sell-price" href="<?=$link?>&sort=bells">Sell Price</a>
    </div>
    <?/*
    <div class="search">
        <form>
            <input />
            <buttton type="submit"></button>
        </form>
    </div>
    */?>
    <div class="tabs-diy">
        <ul>
            <li><button class="btn-tab btn-tab-favorite active"><svg class="icon icon-star"><use xlink:href="#star"></use></svg></button></li>
            <li><button class="btn-tab btn-tab-hot-item"><svg class="icon icon-fire"><use xlink:href="#fire"></use></svg></button></li>
            <li><button class="btn-tab btn-tab-have"><svg class="icon icon-diy-card"><use xlink:href="#diy-card"></use></svg></button></li>
            <li><button class="btn-tab btn-tab-everything"><svg class="icon icon-everything"><use xlink:href="#everything"></use></svg></button></li>
        </ul>
    </div>
    <div class="table-content">
        <? foreach($diy_data[1] as $key => $value): ?>
                <? foreach($value as $content_key => $content_value):
                
                        if ($content_key == 'Verified') { // Verified

                        if ($content_value) $verified = 'Yes';
                        else $verified = 'No';

                    } elseif ($content_key == 'Category') { // Sell Price

                        $category = "<img src='./assets/images/icon-$content_value-white.png' class='icon-category' />";
                        
                    } elseif ($content_key == 'Image') { // Images

                        if($content_value !== 'undefined') $image = "<img src='$content_value' class='img-recipe' />";

                    } elseif ($content_key == 'Recipe') { // Recipe
                        
                        $recipe = $content_value;

                    } elseif ($content_key == 'Required Materials') { // Required Materials

                        $materials = explode('|',$content_value);

                        $required_materials = "";

                        foreach ($materials as $key => $value) {
                            $item = explode(':',$value);

                            if($item[0] == 'N/A') {
                                $required_materials = $item[0];
                            } else {
                                $filename = str_replace(" ","-",strtolower($item[0]));
                                $required_materials .= "<div class='material-item'><span><img src='./assets/images/materials/$filename.png' class='img-material' /></span> <span>$item[1] x $item[0]</span></div>";
                            } 
                        }

                    } elseif ($content_key == 'Sell Price') { // Sell Price

                        $sell_price = number_format($content_value);

                    }
                endforeach; ?>

            <div class="diy-item">
                <div class="item-header">
                    <div class="recipe">
                        <span class="diy-image-wrapper"><?=$image?></span> <?=$recipe?>
                    </div>
                    <div class="sell-price">
                        <span class="verified <?=strtolower($verified)?>"><svg class="svg-verified"><use xlink:href="#check"></use></svg></span>
                        <img src='./assets/images/materials/bells.png' class='img-sell-price' />
                        <?=$sell_price?>
                    </div>
                </div>
                <div class="item-center">
                    <div class="required-materials"><?=$required_materials?></div>
                    <div class="category">
                        <span class="info-image"><?=$category?></span>
                        <span class="info-text">Category</span>
                    </div>
                </div> 
                <div class="item-info">
                    <button class="btn btn-update-diy btn-favorite" data-name="diy" data-type="favorites" data-recipe="<?=$recipe?>">
                        <svg class="icon icon-star"><use xlink:href="#star"></use></svg>
                    </button>
                    <button class="btn btn-update-diy btn-hot-item" data-name="diy" data-type="hot-item" data-recipe="<?=$recipe?>">
                        <svg class="icon icon-fire"><use xlink:href="#fire"></use></svg>
                    </button>
                    <button class="btn btn-update-diy btn-have" data-name="diy" data-type="have" data-recipe="<?=$recipe?>">
                        <svg class="icon icon-diy-card"><use xlink:href="#diy-card"></use></svg>
                    </button>
                </div>
            </div>

        <? endforeach; ?>
    </div>
</div>
<script>
var url = 'https://www.acnh.pixelmotives.com/appdata.php?method=get&name=diy';
</script>