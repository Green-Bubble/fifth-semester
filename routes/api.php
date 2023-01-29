<?php

use App\Http\Controllers\Api\AuthController;
use App\Http\Controllers\Api\DayMarkController;
use App\Http\Controllers\Api\HabitController;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::middleware('auth:sanctum')->group(function() {
        Route::get('/user', function (Request $request) {
            return $request->user();
        });

        Route::post('/logout',[AuthController::class,'logout']);

        Route::post('/habits',[HabitController::class,'index']);

        Route::prefix('/habit')->group(function (){
            Route::post('/store',[HabitController::class,'store']);
            Route::put('/{id}',[HabitController::class,'update']);
            Route::delete('/{id}',[HabitController::class,'destroy']);
        });

        Route::post('/daymarks',[DayMarkController::class,'index']);
        Route::prefix('/daymark')->group(function (){
            Route::post('/store',[DayMarkController::class,'store']);
            Route::put('/{id}',[DayMarkController::class,'update']);
        });
    }
);

Route::post('/signup',[AuthController::class,'signup']);
Route::post('/login',[AuthController::class,'login']);
