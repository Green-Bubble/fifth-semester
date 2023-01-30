<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;
use Illuminate\Support\Str;

return new class extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('day_marks', function (Blueprint $table) {
            $table->id();
            $table->foreignId('habit_id')->references('id')->on('habits')->cascadeOnDelete();
            $table->date('mark_date');
            $table->enum('state',['done','failed','skipped','value']);
            $table->integer('value',false,true)->nullable();
            $table->timestamps();
        });
    }
    
    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('day_marks');
    }
};
