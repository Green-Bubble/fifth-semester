<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Habit Keeper - Uni Project</title>
</head>
<body>
    <header>
        <h1 id="logo">Habit Keeper</h1>
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