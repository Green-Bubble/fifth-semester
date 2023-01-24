<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/
$frontLink = 'http://localhost:4000';

Route::get('/example', function () {
    return view('welcome');
});

Route::get('/', function (){
    return view('home');
});

Route::redirect('/login',"$frontLink/login");
Route::redirect('/signup',"$frontLink/signup");
