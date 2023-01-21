<?php
class Website {
    protected $content;
    protected $title = "Modułowy serwis PHP";
    protected $tags = "narzędzia internetowe, php, formularz, galeria";
    protected $buttons = [
        "Kontakt" => "?strona=index",
        "Galeria" => "?strona=galeria",
        "Formularz" => "?strona=formularz",
        "O nas"=>"?strona=onas"
    ];

    public function set_content($content){
        $this->content = $content;
    }

    function set_title($title){
        $this->title = $title;
    }

    public function set_tags($tags){
        $this->tags = $tags;
    }
    
    public function set_buttons($buttons)
    {
        $this->buttons = $buttons;
    }

    public function set_style($url){
        var_dump($url);
        echo `<link rel="stylesheet" href="$url" type="text/css" />`;
    }

    public function show(){
        $this->show_header();
        $this->show_content();
        $this->show_footer();
    }
    public function show_title(){
        echo `<title>$this->title</title>`;
    }

    public function show_tags(){
        echo `<meta name="keyword" contents="$this->tags">`;
    }

    public function show_menu() {
        echo "<div id='nav'>";
        foreach($this->buttons as $nazwa => $url){
            echo `<a href="$url">$nazwa</a>`;
        }
        echo "</div>";
    }

    public function show_header(){
        ?>
        <!DOCTYPE html>
        <html>
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initialscale=1.0">
                <link rel="stylesheet" href="css/style.css" type="text/css" />
        <?php
        var_dump("Ha");
        $this->set_style('css/style.css');
        echo  `<title>$this->title</title></head><body>`;
    }
    
    public function show_content(){
        echo "<div id='tresc'>";
        echo "<div id='nag'>";
        echo "<img src='zdjecia/foto.jpg' alt='foto' /></div>";
        echo "<div id='menu'>";
        $this->show_menu();
        echo "</div></div>";
        echo "</div></div>";
        echo "<div id='main'>";
        echo "<h1>".$this->title."</h1>";
        echo $this->content . "</div>";
    }

    public function show_footer() {
        echo '<div id="stopka"> &copy; BP </div>';
        echo '</body></html>';
    }
}
?>