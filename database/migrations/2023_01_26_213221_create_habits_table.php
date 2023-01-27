<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('habits', function (Blueprint $table) {
            $table->id();
            $table->foreignId('user_id')->references('id')->on('users')->cascadeOnDelete();
            $table->enum('type',['positiveYN','negativeYN','positiveNumerical','negativeNumerical']);
            $table->string('color');
            $table->string('title');
            $table->string('description');
            $table->enum('frequency',['everyday','times-a-week','every-each-day']);
            $table->time('startHour');
            $table->time('endHour');

        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('habits');
    }
};
