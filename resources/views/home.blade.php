<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Habit Tracker - Uni Project</title>

    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@500;700&display=swap" rel="stylesheet">

    <link rel="stylesheet" href="{{ URL::asset('css/normalize.css'); }}">
    <link rel="stylesheet" href="{{ URL::asset('css/main.css'); }}">
    <link rel="icon" type="image/x-icon" href="{{ URL::asset('favicon.ico'); }}">
</head>
<body>
    <header class="top-bar">
        <h1 id="logo">Habit Forge</h1>
        <nav>
            <a href="{{ url('/features') }}">Features</a>
            <a href="{{ url('/about') }}">About</a>
        </nav>
        <aside>
            <a href="{{ url('/login') }}" class="a-button">
                LOG IN
            </a>
            <a href="{{ url('/signup') }}" class="a-button">
                SIGN UP
            </a>
        </aside>
    </header>
</body>
</html>