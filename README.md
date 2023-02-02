# Habit Tracker University
## Starting the project as development server
### Backend
> **Please note** that all commands and files path are relative to `backend/` folder
1. Steps for cloned project
    1. Run `composer install`
    2. Copy `.env.example` file into `.env` file and fill it with setup for your configuration
    3. Run `php artisan key:generate`
    4. Run `php artisan migrate`
2. Steps for copied project
    1. Project is configured for SQLite and database is already here, in file `database/database.sqlite`
    2. Credentials for user with existing habits: `admin@mail.com` & `adminhaslo!`
    3. For database inspection run `sqlite database/database.sqlite`. This command will start sqlite interpreter where database can be edited and viewed with SQL. `.headers ON` makes `SELECT` more readable
3. Run `php artisan serve`
4. Website can be accessed on http://localhost:8000/
### Frontend
> **Please note** that all commands and files path are relative to `frontend/` folder
1. Steps for cloned project
    1. Run `npm i`
    2. Copy `.env.example` file into `.env` file and fill link to backend
2. Run `npm run dev`
3. Website can be accessed on http://localhost:4000/

## Features
- DEVELOPMENT

---
### Used technologies
[<img align="left" alt="PHP" width="26px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/php/php-original.svg" style="padding-right:10px;" />][php]
[<img align="left" alt="Laravel" width="26px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/laravel/laravel-plain.svg" style="padding-right:10px;" />][laravel]
[<img align="left" alt="Sqlite" width="26px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/sqlite/sqlite-original.svg" style="padding-right:10px;" />][sqlite]
[<img align="left" alt="JS" width="26px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/javascript/javascript-original.svg" style="padding-right:10px;" />][js]
[<img align="left" alt="React" width="26px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/react/react-original.svg" style="padding-right:10px;" />][react]
[<img align="left" alt="CSS" width="26px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/css3/css3-original.svg" style="padding-right:10px;"/>][css]
[<img align="left" alt="Vite" width="26px" src="https://raw.githubusercontent.com/MarcinSkic/marcinskic/main/icons/vite.svg" style="padding-right:10px;"/>][vite]

[js]: https://en.wikipedia.org/wiki/JavaScript
[react]: https://pl.reactjs.org
[vite]: https://vitejs.dev
[php]: https://www.php.net
[laravel]: https://laravel.com
[sqlite]: https://www.sqlite.org/index.html
[js]: https://en.wikipedia.org/wiki/JavaScript
[react]: https://pl.reactjs.org
[css]: https://en.wikipedia.org/wiki/CSS
[vite]: https://vitejs.dev